#include "timer.h"
#include "myTimers.h"



void init_mytimer(void)
{
	CLK.RTCCTRL = CLK_RTCSRC_RCOSC32_gc | CLK_RTCEN_bm;

	do {
		;// Wait until RTC is not busy.
	} while ( RTC.STATUS & RTC_SYNCBUSY_bm );

	RTC.PER = 16;
	RTC.CNT = 0;
	RTC.COMP = 0;
	RTC.CTRL = RTC_PRESCALER_DIV16_gc;
	RTC.INTCTRL	= RTC_OVFINTLVL_MED_gc;
}

ISR ( RTC_OVF_vect )
{
uint8_t i;
	for (i=0;i<MYTIMER_NUM;i++)
	{
		switch(MyTimers[i].state )
		{
			case TM_STOP:
			break;
			case TM_RUN:
				if (MyTimers[i].actual==0)
				{
					if (MyTimers[i].restart == RESTART_YES)
					{
						MyTimers[i].actual = MyTimers[i].value;
						MyTimers[i].state = TM_RUN;
					}
					else
						MyTimers[i].state = TM_STOP;
					if (MyTimers[i].OnReady!=NULL)
						MyTimers[i].OnReady(3);
				}
				MyTimers[i].actual--;
			break;
			case TM_START:
				MyTimers[i].actual = MyTimers[i].value;
				MyTimers[i].state = TM_RUN;
			break;

			case TM_RESET:
				MyTimers[i].state = TM_START;
			break;
		}
	}
}

