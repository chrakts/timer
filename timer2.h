#ifndef TIMER2_H_INCLUDED
#define TIMER2_H_INCLUDED

#include <avr/io.h>
#include <stdbool.h>
#include <avr/interrupt.h>
#include <errno.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

enum{TM_START,TM_RESET,TM_STOP,TM_RUN};
enum{RESTART_YES,RESTART_NO};

struct Timer2
{
	uint8_t		state;
	uint8_t		restart;
	uint16_t	value;
	uint16_t	actual;
	void  (*OnReady)  (uint16_t parameter);
	uint16_t parameter;
};

typedef struct Timer2 TIMER2;

void init_mytimer(void);


#endif // TIMER2_H_INCLUDED
