/*
 * myGPIO.h
 *
 *  Created on:
 *      Author:
 *
 */

#ifndef MYGPIO_H_
#define MYGPIO_H_

// This function initializes the peripherals used in the program.
void initGPIO();
void turnOn_Launchpad_Led1();
void turnOff_Launchpad_Led1();
void turnOn_Launchpad_Led2_Red();
void turnOn_Launchpad_Led2_Green();
void turnOn_Launchpad_Led2_Blue();
void turnOn_Launchpad_Led2_Yellow();
void turnOn_Launchpad_Led2_Cyan();
void turnOn_Launchpad_Led2_Magenta();
void turnOn_Launchpad_Led2_White();
void turnOff_Launchpad_Led2_Red();
void turnOff_Launchpad_Led2_Green();
void turnOff_Launchpad_Led2_Blue();
void turnOn_Boosterpack_Led_Red();
void turnOn_Boosterpack_Led_Green();
void turnOn_Boosterpack_Led_Blue();
void turnOn_Boosterpack_Led_Yellow();
void turnOn_Boosterpack_Led_Cyan();
void turnOn_Boosterpack_Led_Magenta();
void turnOn_Boosterpack_Led_White();
void turnOff_Boosterpack_Led_Red();
void turnOff_Boosterpack_Led_Green();
void turnOff_Boosterpack_Led_Blue();
unsigned char check_Status_Of_Launchpad_Button1();
unsigned char check_Status_Of_Launchpad_Button2();
unsigned char check_Status_Of_Boosterpack_Button1();
unsigned char check_Status_Of_Boosterpack_Button2();
void turnOffAllLeds();
void turnOffAllLedsOnLaunchpad();
void turnOffAllLedsOnBoosterpack();


// TODO: Define any constants that are local to myGPIO.c using #define


#endif /* MYGPIO_H_ */
