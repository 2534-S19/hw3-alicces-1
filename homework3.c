#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include "homework3.h"
#include "myGPIO.h"
#include "myTimer.h"

int main(void)
{
    // Count variables to control the LEDs.
    unsigned int count0 = 0;
    unsigned int count1 = 0;

    // TODO: Declare the variables that main uses to interact with your state machine.
    unsigned int buttonHistory;
    bool pressed;

    // Stops the Watchdog timer.
    initBoard();

    // Initialize the GPIO.
    // YOU MUST WRITE THIS FUNCTION IN myGPIO.c
    initGPIO();

    // Initialize Timer0 to provide a one second count interval for updating LED2.
    // YOU MUST WRITE THIS FUNCTION IN myTimer.c
    initTimer(TIMER32_0_BASE, TIMER0_PRESCALER, TIMER0_COUNT);
    // Initialize Timer1 to provide a one millisecond count interval for updating the button history.
    // YOU MUST WRITE THIS FUNCTION IN myTimer.c
    initTimer(TIMER32_1_BASE, TIMER1_PRESCALER, TIMER1_COUNT);
    turnOffAllLeds();
    while(1)
    {
        // Update the color of LED2 using count0 as the index.
        // YOU MUST WRITE THIS FUNCTION BELOW.
        changeLaunchpadLED2(count0);

        // Update the color of the Boosterpack LED using count1 as the index.
        // YOU MUST WRITE THIS FUNCTION BELOW.
        changeBoosterpackLED(count1);

        // TODO:(done) If Timer0 has expired, increment count0.
        // YOU MUST WRITE timer0expired IN myTimer.c
        if(timer0Expired())
        {
            count0++;
        }
        // TODO:(done) If Timer1 has expired, update the button history from the pushbutton value.
        // YOU MUST WRITE timer1expired IN myTimer.c

        if(timer1Expired())
        {

            if(check_Status_Of_Boosterpack_Button1() == 1)
            {
                buttonHistory = buttonHistory << 1;
                buttonHistory |= 0x00000001;

            }
            else if (check_Status_Of_Boosterpack_Button1() == 0)
            {
                buttonHistory = buttonHistory << 1;

            }

        }



        // TODO:(done) Call the button state machine function to check for a completed, debounced button press.
        // YOU MUST WRITE THIS FUNCTION BELOW.

        pressed = fsmBoosterpackButtonS1(buttonHistory);




        // TODO:(done) If a completed, debounced button press has occurred, increment count1.

        if (pressed)
        {
            count1++;
        }


    }
}

void initBoard()
{
    WDT_A_hold(WDT_A_BASE);
}

// TODO: Map the value of a count variable to a color for LED2.
// Since count is an unsigned integer, you can mask the value in some way.
void changeLaunchpadLED2(unsigned int count)
{
    enum Color {BLACK, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE};

    switch(count % 8)
    {
        case BLACK:
            // Turn all the lights off on launchpad
            turnOffAllLedsOnLaunchpad();
            break;
        case RED:
            // Turn on red on launchpad
            turnOffAllLedsOnLaunchpad();
            turnOn_Launchpad_Led2_Red();
            break;
        case GREEN:
            // Turn on yellow on launchpad
            turnOffAllLedsOnLaunchpad();
            turnOn_Launchpad_Led2_Green();
            break;
        case YELLOW:
            // Turn on green on launchpad
            turnOffAllLedsOnLaunchpad();
            turnOn_Launchpad_Led2_Yellow();
            break;
        case BLUE:
            // Turn on blue on launchpad
            turnOffAllLedsOnLaunchpad();
            turnOn_Launchpad_Led2_Blue();
            break;
        case MAGENTA:
            // Turn on magenta on launchpad
            turnOffAllLedsOnLaunchpad();
            turnOn_Launchpad_Led2_Magenta();
            break;
        case CYAN:
            // Turn on cyan on launchpad
            turnOffAllLedsOnLaunchpad();
            turnOn_Launchpad_Led2_Cyan();
            break;
        case WHITE:
            // Turn on white on launchpad
            turnOffAllLedsOnLaunchpad();
            turnOn_Launchpad_Led2_White();
            break;
    }

}

// TODO: Maybe the value of a count variable to a color for the Boosterpack LED
// This is essentially a copy of the previous function, using a different LED
void changeBoosterpackLED(unsigned int count)
{
    enum Color {BLACK, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE};

        switch(count % 8)
        {
            case BLACK:
                // Turn all the lights off on launchpad
                turnOffAllLedsOnBoosterpack();
                break;
            case RED:
                // Turn on red on launchpad
                turnOffAllLedsOnBoosterpack();
                turnOn_Boosterpack_Led_Red();
                break;
            case GREEN:
                // Turn on yellow on launchpad
                turnOffAllLedsOnBoosterpack();
                turnOn_Boosterpack_Led_Green();
                break;
            case YELLOW:
                // Turn on green on launchpad
                turnOffAllLedsOnBoosterpack();
                turnOn_Boosterpack_Led_Yellow();
                break;
            case BLUE:
                // Turn on blue on launchpad
                turnOffAllLedsOnBoosterpack();
                turnOn_Boosterpack_Led_Blue();
                break;
            case MAGENTA:
                // Turn on magenta on launchpad
                turnOffAllLedsOnBoosterpack();
                turnOn_Boosterpack_Led_Magenta();
                break;
            case CYAN:
                // Turn on cyan on launchpad
                turnOffAllLedsOnBoosterpack();
                turnOn_Boosterpack_Led_Cyan();
                break;
            case WHITE:
                // Turn on white on launchpad
                turnOffAllLedsOnBoosterpack();
                turnOn_Boosterpack_Led_White();
                break;
        }

}

// TODO: Create a button state machine.
// The button state machine should return true or false to indicate a completed, debounced button press.
bool fsmBoosterpackButtonS1(unsigned int buttonhistory)
{
    bool pressed = false;
    typedef enum {UP, DOWN} State;
    static State previousState = UP;
    switch(previousState)
    {
        case UP:
            if (buttonhistory & BIT0)
            {
                previousState = DOWN;
                pressed = true;
            }
            else
            {
                previousState = UP;
                pressed = false;
            }


            break;

        case DOWN:
            if (buttonhistory & BIT0)
            {
                previousState = DOWN;
                pressed = false;
            }
            else
            {
                previousState = UP;
                pressed = false;
            }
            break;
    }

    return pressed;
}
