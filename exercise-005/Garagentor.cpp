#include <fmt/chrono.h>
#include <fmt/format.h>

#include "CLI/CLI.hpp"

#include <thread>

extern int getInput(void);

typedef enum{
    DB_STATE_OFF = 0, // Garagentor aus --> Start Bedingung
    DB_STATE_S1 = 1,  // Garagentor unten
    DB_STATE_S2 = 2,  // Garagentor oben
    DB_STATE_ON = 3,  // Garagentor unterwegs
    DB_STATE_MAX
} DebounceState_t;

DebounceState_t state = DB_STATE_OFF;

void stateMachine()
{
    switch(state)
    {
        case DB_STATE_OFF:
            if(1 == getInput())
            {
                state = DB_STATE_S1;
            }
        break;
        case DB_STATE_S1:
            if (1 == getInput())
            {
                state = DB_STATE_S2;
            }
            else
            {
                state = DB_STATE_OFF;
            }
        break;
        case DB_STATE_S2:
            if (1 == getInput())
            {
                state = DB_STATE_ON;
            }
            else
            {
                state = DB_STATE_OFF;
            }
        break;
        case DB_STATE_ON:
            if (1 == getInput())
            {
                state = DB_STATE_ON;
            }
            else
            {
                state = DB_STATE_OFF;
            }
        break;
        default:
            state = DB_STATE_OFF;
        break;         
    }
}


void sleep_ms(int milliseconds)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}
