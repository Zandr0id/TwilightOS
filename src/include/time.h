/*
timer.h
This will hold time based structs and related functions
*/

#ifndef TIMER_H_
#define TIMER_H_

#define BASE_FREQUENCY 1193180

enum PIT_Ports
{
    PIT_CHANNEL_0 = 0x40,
    PIT_CHANNEL_1 = 0x41,
    PIT_CHANNEL_2 = 0x42,
    PIT_CMD = 0x43
};

typedef struct time_data
{
    int clock_divisor; //fed to timer to 
    unsigned int millisecs_since_poweron; //a huge spot to count all system ticks
    unsigned int seconds_since_poweron; //seconds 
    unsigned int minutes_since_poweron; //minutes
    
    /*TODO: This not working for some reason
    time_data()
    {
        clock_divisor = 1;
        millisecs_since_poweron = 0;
        seconds_since_poweron = 0;
        minutes_since_poweron = 0;
    }

    void increment_time()
    {
        minutes_since_poweron++;
        seconds_since_poweron = millisecs_since_poweron % 100; //100 millisecs in a second
        minutes_since_poweron = seconds_since_poweron % 60; //60 seconds in a minute
    }
    */

}time_data;

//returns the diff in millisecs of two times
unsigned int time_diff(time_data future, time_data past)
{
    return (future.millisecs_since_poweron - past.millisecs_since_poweron);
}

//TODO: Move into struct above
void increment_time(time_data* time)
{
    time->millisecs_since_poweron++;
    time->seconds_since_poweron = time->millisecs_since_poweron / 1000; //1000 millisecs in a second
    time->minutes_since_poweron = time->seconds_since_poweron / 60; //60 seconds in a minute
}

#endif