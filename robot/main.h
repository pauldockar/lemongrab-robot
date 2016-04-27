/*
 * Team:    Lemongrabs
 * Authors: Paul Dockar     - 12059869
 *          Dennis Kim      - 12050466
 *          Kim Izzo        - 11971278
 *          Nick Rabey      - 11988589
 *          Michael Smith   - 11745167
 */

#ifndef MAIN_H
#define	MAIN_H

#include <xc.h>
#pragma config BOREN = OFF, CPD = OFF, WRT = OFF, FOSC = HS, WDTE = OFF, CP = OFF, LVP = OFF, PWRTE = OFF
#include "adc.h"
#include "interrupt.h"
#include "iRobot.h"
#include "lcd.h"
#include "ser.h"
#include "spi.h"
#include "stepper.h"

#define _XTAL_FREQ      20000000        //pic crystal frequency
#define HB_LED          RB0             //set PortB Pin 0 for heartbeat LED
#define PB_START        !RB1            //set PortB Pin 1 for pushbutton start
#define PB_SCAN         !RB2            //set PortB Pin 2 for pushbutton scan closest wall
#define PB_DRIVE_4M     !RB3            //set PortB Pin 3 for pushbutton drive 4m straight line
#define PB_DRVE_SQUARE  !RB4            //set PortB Pin 4 for pushbutton drive 1m square
#define PB_FIND_WALL    !RB5            //set PortB Pin 5 for pushbutton drive along closest wall

volatile bit pb_start_pressed;          //push button flag for PB_START. NOTE THIS IS TEMP TEST CODE
volatile bit pb_scan_pressed;           //push button flag for PB_SCAN
volatile bit pb_drive_4m_pressed;       //push button flag for PB_DRIVE_4M
volatile bit pb_drive_square_pressed;   //push button flag for PB_DRVE_SQUARE
volatile bit pb_find_wall_pressed;      //push button flag for PB_FIND_WALL

void setup (void);                      //calls all other module setup functions
void main (void);                       //main program. starts by calling setup, then loops with pushbutton flag checks and displaying adc distance continuously
void buttonControl (void);              //checks all push button flags. if one is true then call that desired function
void startTest (void);                  //this is temporary driving test code. remove when ready

#endif	/* MAIN_H */
