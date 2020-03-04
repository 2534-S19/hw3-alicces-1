/*
 * GPIO.c
 *
 *  Created on:
 *      Author:
 */

// For the code you place here, you may use your code that uses register references.
// However, I encourage you to start using the Driver Library as soon as possible.

#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include "myGPIO.h"


#define BUFFER_SIZE             5
#define LAUNCHPAD_LED1          BIT0    // P1.0
#define LAUNCHPAD_LED2_RED      BIT0    // P2.0
#define LAUNCHPAD_LED2_BLUE     BIT2    // P2.1
#define LAUNCHPAD_LED2_GREEN    BIT1    // P2.2
#define LAUNCHPAD_BUTTON1       BIT1    // P1.1
#define LAUNCHPAD_BUTTON2       BIT4    // P1.4
#define BOOSTERPACK_LED_RED     BIT6    // P2.6
#define BOOSTERPACK_LED_GREEN   BIT4    // P2.4
#define BOOSTERPACK_LED_BLUE    BIT6    // P5.6
#define BOOSTERPACK_BUTTON1     BIT1    // P5.1
#define BOOSTERPACK_BUTTON2     BIT5    // P3.5
#define PRESSED                 0
#define CHECKPOINT0             0
#define CHECKPOINT1             10
#define CHECKPOINT2             20
#define CHECKPOINT3             30
#define CHECKPOINT4             40

// TODO: Create a function to initialize the GPIO.
// Even though this assignment does not use all of the pushbuttons, you should write one function that does a complete GPIO init.
void initGPIO()
{
    // Sets launchpad led1 for output
        P1DIR |= LAUNCHPAD_LED1;

        // Sets launchpad led2 red for output
        P2DIR |= LAUNCHPAD_LED2_RED;
        // Sets launchpad led2 green for output
        P2DIR |= LAUNCHPAD_LED2_GREEN;
        // Sets launchpad led2 blue for output
        P2DIR |= LAUNCHPAD_LED2_BLUE;

        // Sets launchpad button 1 for input with pull up resistor
        P1DIR &= ~LAUNCHPAD_BUTTON1;
        P1REN |= LAUNCHPAD_BUTTON1;
        P1OUT |= LAUNCHPAD_BUTTON1;

        // Sets launchpad button 2 for input with pull up resistor
        P1DIR &= ~LAUNCHPAD_BUTTON2;
        P1REN |= LAUNCHPAD_BUTTON2;
        P1OUT |= LAUNCHPAD_BUTTON2;

        // Sets boosterpack led red for output
        P2DIR |= BOOSTERPACK_LED_RED;
        // Sets boosterpack led green for output
        P2DIR |= BOOSTERPACK_LED_GREEN;
        // Sets boosterpack led blue for output
        P5DIR |= BOOSTERPACK_LED_BLUE;

        // Sets boosterpack button 1 for input with pull up resistor
        P5DIR &= ~BOOSTERPACK_BUTTON1;
        P5REN |= BOOSTERPACK_BUTTON1;
        P5OUT |= BOOSTERPACK_BUTTON1;

        // Sets boosterpack button 2 for input with pull up resistor
        P3DIR &= ~BOOSTERPACK_BUTTON2;
        P3REN |= BOOSTERPACK_BUTTON2;
        P3OUT |= BOOSTERPACK_BUTTON2;
}

// Launchpad LED1



// This funtion turns on led1 on launchpad
void turnOn_Launchpad_Led1()
{
    P1OUT |= LAUNCHPAD_LED1;
}

// This funtion turns off led1 on launchpad
void turnOff_Launchpad_Led1()
{
    P1OUT &= ~LAUNCHPAD_LED1;
}

// Launchpad LED2


// This function turns on led2 red on launchpad
void turnOn_Launchpad_Led2_Red()
{
    P2OUT |= LAUNCHPAD_LED2_RED;
}

// This function turns on led2 green on launchpad
void turnOn_Launchpad_Led2_Green()
{
    P2OUT |= LAUNCHPAD_LED2_GREEN;
}

// This function turns on led2 blue on launchpad
void turnOn_Launchpad_Led2_Blue()
{
    P2OUT |= LAUNCHPAD_LED2_BLUE;
}

// This function turns off led2 red on launchpad
void turnOff_Launchpad_Led2_Red()
{
    P2OUT &= ~LAUNCHPAD_LED2_RED;
}

// This function turns off led2 green on launchpad
void turnOff_Launchpad_Led2_Green()
{
    P2OUT &= ~LAUNCHPAD_LED2_GREEN;
}

// This function turns off led2 blue on launchpad
void turnOff_Launchpad_Led2_Blue()
{
    P2OUT &= ~LAUNCHPAD_LED2_BLUE;
}

//  Boosterpack leds turn on and off functions

// This function turns on led red on boosterpack
void turnOn_Boosterpack_Led_Red()
{
    P2OUT |= BOOSTERPACK_LED_RED;
}

// This function turns on led green on boosterpack
void turnOn_Boosterpack_Led_Green()
{
    P2OUT |= BOOSTERPACK_LED_GREEN;
}

// This function turns on led blue on boosterpack
void turnOn_Boosterpack_Led_Blue()
{
    P5OUT |= BOOSTERPACK_LED_BLUE;
}

// This function turns off led red on boosterpack
void turnOff_Boosterpack_Led_Red()
{
    P2OUT &= ~BOOSTERPACK_LED_RED;
}

// This function turns off led green on boosterpack
void turnOff_Boosterpack_Led_Green()
{
    P2OUT &= ~BOOSTERPACK_LED_GREEN;
}

// This function turns off led blue on boosterpack
void turnOff_Boosterpack_Led_Blue()
{
    P5OUT &= ~BOOSTERPACK_LED_BLUE;
}

//  Launchpad buttons status check

//  This function checks if button1 on launchpad is pushed or not.
unsigned char check_Status_Of_Launchpad_Button1()
{
    return ((P1IN & LAUNCHPAD_BUTTON1) == PRESSED);
}

//  This function checks if button2 on launchpad is pushed or not.
unsigned char check_Status_Of_Launchpad_Button2()
{
    return ((P1IN & LAUNCHPAD_BUTTON2) == PRESSED);
}

// Boosterpack buttons status check

//  This function checks if button1 on boosterpack is pushed or not.
unsigned char check_Status_Of_Boosterpack_Button1()
{
    return ((P5IN & BOOSTERPACK_BUTTON1) == PRESSED);
}

//  This function checks if button2 on boosterpack is pushed or not.
unsigned char check_Status_Of_Boosterpack_Button2()
{
    return ((P3IN & BOOSTERPACK_BUTTON2) == PRESSED);
}


// this function turns of all the LEDs
void turnOffAllLeds()
{
    turnOff_Launchpad_Led1();

    turnOff_Launchpad_Led2_Red();
    turnOff_Launchpad_Led2_Green();
    turnOff_Launchpad_Led2_Blue();

    turnOff_Boosterpack_Led_Red();
    turnOff_Boosterpack_Led_Green();
    turnOff_Boosterpack_Led_Blue();
}

void turnOffAllLedsOnLaunchpad()
{
    turnOff_Launchpad_Led2_Red();
    turnOff_Launchpad_Led2_Green();
    turnOff_Launchpad_Led2_Blue();
}

void turnOffAllLedsOnBoosterpack()
{
    turnOff_Boosterpack_Led_Red();
    turnOff_Boosterpack_Led_Green();
    turnOff_Boosterpack_Led_Blue();
}

void turnOn_Boosterpack_Led_Yellow()
{

    turnOn_Boosterpack_Led_Red();
    turnOn_Boosterpack_Led_Green();
}
void turnOn_Boosterpack_Led_Cyan()
{

    turnOn_Boosterpack_Led_Green();
    turnOn_Boosterpack_Led_Blue();
}
void turnOn_Boosterpack_Led_Magenta()
{

    turnOn_Boosterpack_Led_Red();
    turnOn_Boosterpack_Led_Blue();
}
void turnOn_Boosterpack_Led_White()
{

    turnOn_Boosterpack_Led_Red();
    turnOn_Boosterpack_Led_Green();
    turnOn_Boosterpack_Led_Blue();
}

void turnOn_Launchpad_Led2_Yellow()
{
    turnOn_Launchpad_Led2_Red();
    turnOn_Launchpad_Led2_Green();
}
void turnOn_Launchpad_Led2_Cyan()
{
    turnOn_Launchpad_Led2_Blue();
    turnOn_Launchpad_Led2_Green();
}
void turnOn_Launchpad_Led2_Magenta()
{
    turnOn_Launchpad_Led2_Red();
    turnOn_Launchpad_Led2_Blue();
}
void turnOn_Launchpad_Led2_White()
{
    turnOn_Launchpad_Led2_Red();
    turnOn_Launchpad_Led2_Green();
    turnOn_Launchpad_Led2_Blue();
}
