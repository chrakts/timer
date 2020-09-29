#ifndef TIMER_H_INCLUDED
#define TIMER_H_INCLUDED

#include <avr/io.h>
#include <stdbool.h>
#include <avr/interrupt.h>
#include <errno.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

enum{TM_START,TM_RESET,TM_STOP,TM_RUN};
enum{RESTART_YES,RESTART_NO};

struct Timer
{
	uint8_t		state;
	uint8_t		restart;
	uint16_t	value;
	uint16_t	actual;
	void  (*OnReady)  (uint8_t test);
};

typedef struct Timer TIMER;

void init_mytimer(void);


#endif // TIMER_H_INCLUDED
