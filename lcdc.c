

#include <stdlib.h>

#include "defs.h"
#include "hw.h"
#include "lcd.h"
#include "regs.h"


struct lcdc lcdc;

#define C (lcdc.cycles)


/*
 * stat_trigger updates the STAT interrupt line to reflect whether any
 * of the conditions set to be tested (by bits 3-6 of R_STAT) are met.
 * This function should be called whenever any of the following occur:
 * 1) LY or LYC changes.
 * 2) A state transition affects the low 2 bits of R_STAT (see below).
 * 3) The program writes to the upper bits of R_STAT.
 * stat_trigger also updates bit 2 of R_STAT to reflect whether LY=LYC.
 */

void stat_trigger()
{
	static const int condbits[4] = { 0x08, 0x30, 0x20, 0x00 };
	int flag = 0;

	//if (!(R_LCDC & 0x80)) return;
	
	if (R_LY == R_LYC)
	{
		R_STAT |= 0x04;
		if (R_STAT & 0x40) flag = IF_STAT;
	}
	else R_STAT &= ~0x04;

	if (R_STAT & condbits[R_STAT&3]) flag = IF_STAT;
	
	hw_interrupt(flag, IF_STAT);
}


/*
 * stat_change is called when a transition in the state table results
 * in a change to the LCD STAT condition (the low 2 bits of R_STAT).
 * It raises or lowers the VBLANK interrupt line appropriately and
 * calls stat_trigger to update the STAT interrupt line.
 */

static void stat_change(int stat)
{
	int iraise;
	
	stat &= 3;
	R_STAT = (R_STAT & 0x7C) | stat;

	//if (!(R_LCDC & 0x80)) return;

	hw_interrupt((stat == 1) ? IF_VBLANK : 0, IF_VBLANK);
	stat_trigger();
}


void lcdc_change(byte b)
{
	if ((R_LCDC ^ b) & 0x80) /* lcd on/off change */
	{
		R_LY = 0;
		stat_change(2);
		C = 40;
		if (R_LCDC & 0x80)
		{
			lcd_begin();
		}
	}
	R_LCDC = b;
}


void lcdc_trans()
{
	if (!(R_LCDC & 0x80))
	{
		switch ((byte)(R_STAT & 3))
		{
		case 0:
		case 1:
			stat_change(2);
			C += 40;
			break;
		case 2:
			stat_change(3);
			C += 86;
			break;
		case 3:
			stat_change(0);
			C += 102;
			break;
		}
		return;
	}

	switch ((byte)(R_STAT & 3))
	{
	case 1:
		if (R_LY == 0)
		{
			lcd_begin();
			lcd_refreshline();
			stat_change(2);
			C += 40;
			break;
		}
		else if (R_LY < 152)
			C += 228;
		else if (R_LY == 152)
			C += 28;
		else
		{
			R_LY = -1;
			C += 200;
		}
		R_LY++;
		stat_trigger();
		break;
	case 2:
		stat_change(3);
		C += 86;
		break;
	case 3:
		if (hw.hdma)
		{
			stat_change(0);
			hw_hdma();
			stat_change(2);
			C += 40;
			break;
		}
		stat_change(0);
		C += 102;
		break;
	case 0:
		lcd_refreshline();
		if (++R_LY >= 144)
		{
			stat_change(1);
			C += 228;
			break;
		}
		stat_change(2);
		C += 40;
		break;
	}
}


void lcdc_advance(int cnt)
{
	C -= cnt;
	while (C <= 0) lcdc_trans();
}

void lcdc_step()
{
	lcdc_advance(cpu_emulate(C));
}

void lcdc_reset()
{
	C = 40;
}




