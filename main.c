#include <msp430.h> 
#define arraySize = 5
enum RunningStates {
    Running,
    Paused,
    Lose
}States = Paused;


void main(void)
{
    unsigned char currKey=0, dispSz = 3;
    unsigned char dispThree[3];
    int colorArray[arraySize];
    int readInput[arraySize];
    unsigned int somethingFun = 0x2121;
    int rounds = 1, i = 0, max_number = 4, minimum_number = 1;
    initLeds();
    configDisplay();
    configKeypad();
    GrClearDisplay(&g_sContext); // Clear the display

    while (1)    // Forever loop
    {
    currKey = getKey();
    switch (currKey)
    {
    case('*'):
                        GrStringDrawCentered(&g_sContext, "Paused", AUTO_STRING_LENGTH, 48, 15, TRANSPARENT_TEXT);
                        States = Paused;
    break;
    case('#'):
                        GrStringDrawCentered(&g_sContext, "Running", AUTO_STRING_LENGTH, 48, 15, TRANSPARENT_TEXT);
                        States = Running;
    break;
    }
    switch (States)
    {
    case(Paused):
                            delay(10000);
    break;
    case(Running):
     for(i = rounds-1;i<rounds;i++)
         {
             colorArray[i] = rand() % (max_number + 1 - minimum_number) + minimum_number;
          }
    for(i = 0;i<rounds;i++)
    {
        setLeds(colorArray[i] - 0x30);
    }
    delay(3000);
    GrStringDrawCentered(&g_sContext, "Enter keys now", AUTO_STRING_LENGTH, 48, 15, TRANSPARENT_TEXT);
    for(i =0;i<rounds;i++)
    {
        readInput[i] = getKey();
        delay(300);
        if (readInput[i] !=colorArray[i])
        {
            States = Lose;
            break;
        }
    }

    break;
    case(Lose):
        setLeds(1);
        setLeds(2);
        setLeds(3);
        setLeds(4);
        setLeds(1);
        setLeds(2);
        setLeds(3);
        setLeds(4);
        BuzzerOn();
        delay(1000);
        BuzzerOff();
        States = Paused;
    }
    }

}



void delay(int time)
{
 int i = 0;
    while(i<time)
    {
        i++;
    }
}
#include "peripherals.h"

