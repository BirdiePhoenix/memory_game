#include "../include/game_input.hpp"
#include "../include/millis.h"
#include "../include/button_driver.hpp"

void initButtons()
{
    buttonList[0] = blue_button(&DDRB, &PORTB, &PINB, PB5);
    buttonList[1] = yellow_button(&DDRB, &PORTB, &PINB, PB4);
    buttonList[2] = red_button(&DDRB, &PORTB, &PINB, PB3);
    buttonList[3] = green_button(&DDRB, &PORTB, &PINB, PB2);
}

buttonList wait_for_input()
{
    millis_init();

    while (1)
    {
        for(int i = 0; i < (sizeof(buttonList) / sizeof(buttonList[0])); i++)
        {
            if(buttonList[i].is_pressed == true)
            {
                return buttonList[i];
            }
        }
    } 
}