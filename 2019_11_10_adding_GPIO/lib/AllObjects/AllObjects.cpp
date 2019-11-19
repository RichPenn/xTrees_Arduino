#include <Arduino.h>
#include <Wire.h>
#include "OneObject.h"
#include "AllObjects.h"

using namespace std;

AllObjects::AllObjects( bool t_I2C_Active, int t_I2C_Address)   // TESTED
{                                  
    I2C_Active = t_I2C_Active;
    I2C_Address = t_I2C_Address;
}

int AllObjects::objectCount()                                   // TESTED
{
    return(sizeof(eightObjects)/sizeof(eightObjects[0]));
}

void AllObjects::set_objStatus(int t_idx,                       // TESTED
                                bool t_tf, 
                                int t_pos, 
                                int t_gpioPin,
                                unsigned long t_timeOn, 
                                unsigned long t_timeOff) 
{
    eightObjects[t_idx].set_m_active_Status(t_tf, t_pos, t_gpioPin, t_timeOn, t_timeOff);
}

void AllObjects::set_allON(int t_speed) 
{                                                              // TESTED
    for (int idx = 0; idx < objectCount(); idx++) {
        if (eightObjects[idx].get_m_active_Status()) {
            eightObjects[idx].set_m_wLED_Status(true);
        }
    }
    write_All(I2C_Active);
    delay(t_speed);
};

void AllObjects::set_allOFF(int t_speed) 
{                                                               // TESTED
    for (int idx = 0; idx < objectCount(); idx++) {
        if (eightObjects[idx].get_m_active_Status()) {
            eightObjects[idx].set_m_wLED_Status(false);
        }
    }
    write_All(I2C_Active);
    delay(t_speed);
};

void AllObjects::set_L2HON(unsigned int t_speed) 
{                                                               // TESTED
    for (int idx = 0; idx < objectCount(); idx++) {
        if (eightObjects[idx].get_m_active_Status()) {
            eightObjects[idx].set_m_wLED_Status(true);
            write_All(I2C_Active);
            delay(t_speed);
        }
    }
};

void AllObjects::set_H2LON(unsigned int t_speed) 
{                                                               // TESTED
    for (int idx = objectCount() -1; idx >= 0; idx--) {
        if (eightObjects[idx].get_m_active_Status()) {
            eightObjects[idx].set_m_wLED_Status(true);
            write_All(I2C_Active);
            delay(t_speed);
        }
    }
};

void AllObjects::set_L2HOFF(unsigned int t_speed) 
{                                                               // TESTED
    for (int idx = 0; idx < objectCount(); idx++) {
        if (eightObjects[idx].get_m_active_Status()) {
            eightObjects[idx].set_m_wLED_Status(false);
            write_All(I2C_Active);
            delay(t_speed);
        }
    }
};

void AllObjects::set_H2LOFF(unsigned int t_speed) 
{                                                               // TESTED
    for (int idx = objectCount() -1; idx >= 0; idx--) {
        if (eightObjects[idx].get_m_active_Status()) {
            eightObjects[idx].set_m_wLED_Status(false);
            write_All(I2C_Active);
            delay(t_speed);
        }
    }
};

void AllObjects::set_1_L2HON(unsigned int t_speed)              // TESTED
{
    for (int idx = 0; idx < objectCount(); idx++)
    {
        if (eightObjects[idx].get_m_active_Status())
        {
            set_allOFF(0);
            eightObjects[idx].set_m_wLED_Status(true);
        }
        write_All(I2C_Active);
        delay(t_speed);
    }
};

void AllObjects::set_1_H2LON(unsigned int t_speed)              // TESTED
{ 
    for (int idx = objectCount() - 1; idx >= 0; idx--)
    {
        if (eightObjects[idx].get_m_active_Status())
        {
            set_allOFF(0);
            eightObjects[idx].set_m_wLED_Status(true);
        }
        write_All(I2C_Active);
        delay(t_speed);
    }
};

void AllObjects::set_1_L2HOFF(unsigned int t_speed)             // TESTED
{ 
    for (int idx = 0; idx < objectCount(); idx++)
    {
        if (eightObjects[idx].get_m_active_Status())
        {
            set_allON(0);
            eightObjects[idx].set_m_wLED_Status(false);
        }
        write_All(I2C_Active);
        delay(t_speed);
    }
};

void AllObjects::set_1_H2LOFF(unsigned int t_speed)             // TESTED
{ 
    for (int idx = (objectCount() - 1); idx >= 0; idx--)
    {
        if (eightObjects[idx].get_m_active_Status())
        {
            set_allON(0);
            eightObjects[idx].set_m_wLED_Status(false);
        }
        write_All(I2C_Active);
        delay(t_speed);
    }
};

void AllObjects::set_2_L2HON(unsigned int t_speed)              // TESTED
{
    int max_Array = objectCount() -1;
    int min_Array = 0;

    for (int idx = min_Array; idx <= max_Array; idx++)
    {
        set_allOFF(0);

        if (eightObjects[idx].get_m_active_Status())
        {
            eightObjects[idx].set_m_wLED_Status(true);
        }
        if ((idx > min_Array) && (idx <= max_Array +1))
        {
            if (eightObjects[idx -1].get_m_active_Status())
            {
                eightObjects[idx -1].set_m_wLED_Status(true);
            }
        }   
        write_All(I2C_Active);
        delay(t_speed);   
    }
    if (eightObjects[max_Array].get_m_active_Status())  // the last light in run
    {
        set_allOFF(0);
        eightObjects[max_Array].set_m_wLED_Status(true);
        write_All(I2C_Active);
        delay(t_speed);
        set_allOFF(0);
        delay(t_speed);
    }
};

void AllObjects::set_2_H2LON(unsigned int t_speed)              // TESTED
{ 
    int max_Array = objectCount() -1;
    int min_Array = 0;

    for (int idx = max_Array; idx >= min_Array; idx--)
    {
        set_allOFF(0);

        if (eightObjects[idx].get_m_active_Status())
        {
            eightObjects[idx].set_m_wLED_Status(true);
        }
        if ((idx < max_Array) && (idx >= min_Array -1))
        {
            if (eightObjects[idx +1].get_m_active_Status())
            {
                eightObjects[idx +1].set_m_wLED_Status(true);
            }
        }   
        write_All(I2C_Active);
        delay(t_speed);   
    }
    if (eightObjects[min_Array].get_m_active_Status())  // the last light in run
    {
        set_allOFF(0);
        eightObjects[min_Array].set_m_wLED_Status(true);
        write_All(I2C_Active);
        delay(t_speed);
        set_allOFF(0);
        delay(t_speed);
    }
};

void AllObjects::set_Flicker(unsigned int t_duration, int t_speed)  // TESTED
{                                                                 // count elements of array
    unsigned long later = eightObjects[0].now() + t_duration;    // later = sys time + t_duration

    for (unsigned long now = eightObjects[0].now(); now <= later; 
                    now = eightObjects[0].now())                 // loop until sys time >= later 
        {
        for (int idx = 0; idx < objectCount(); idx++) {          // using object method to control 
            if (eightObjects[idx].get_m_active_Status()) {       // on/off status and change interval
                eightObjects[idx].checkTime();
            }
            write_All(I2C_Active);                               // write pins at end of each loop
        }
        delay(t_speed);                                          // pause at end of pattern...
    }
};

void AllObjects::set_OddAndEven(unsigned int t_duration, int t_speed)  // TESTED
{    
    bool evenON = true;                                           // even or odd lights on
    unsigned long later = eightObjects[0].now() + t_duration;     // length of OddAndEven cycle

    for (unsigned long now = eightObjects[0].now(); now <= later; // loop until sys time >= later
                    now = eightObjects[0].now())
        {
        for (int idx = 0; idx < objectCount(); idx++) {
            if ( idx%2){
                eightObjects[idx].set_m_wLED_Status(evenON);
            }
            else {
                eightObjects[idx].set_m_wLED_Status(!evenON);
            }
            write_All(I2C_Active);
        }
        delay(t_speed);
        evenON = !evenON;
    }
};

void AllObjects::set_2_fromCenter(unsigned int t_duration, int t_speed)  // TESTED
{
    unsigned long later = eightObjects[0].now() + t_duration;    // later = sys time + t_duration

    set_allOFF(0);
    delay(t_speed);
    
    for (unsigned long now = eightObjects[0].now(); now <= later; now = eightObjects[0].now())
    {
        eightObjects[3].set_m_wLED_Status(true);
        eightObjects[4].set_m_wLED_Status(true);
        write_All(I2C_Active);
        delay(t_speed);
        
        eightObjects[2].set_m_wLED_Status(true);
        eightObjects[5].set_m_wLED_Status(true);
        write_All(I2C_Active);
        delay(t_speed);    
        
        eightObjects[1].set_m_wLED_Status(true);
        eightObjects[6].set_m_wLED_Status(true);
        eightObjects[3].set_m_wLED_Status(false);
        eightObjects[4].set_m_wLED_Status(false);
        write_All(I2C_Active);
        delay(t_speed);
        
        eightObjects[0].set_m_wLED_Status(true);
        eightObjects[7].set_m_wLED_Status(true);
        eightObjects[2].set_m_wLED_Status(false);
        eightObjects[5].set_m_wLED_Status(false);
        write_All(I2C_Active);
        delay(t_speed);

        eightObjects[1].set_m_wLED_Status(false);
        eightObjects[6].set_m_wLED_Status(false);
        write_All(I2C_Active);
        delay(t_speed);

        eightObjects[0].set_m_wLED_Status(false);
        eightObjects[7].set_m_wLED_Status(false);        
        write_All(I2C_Active);
        delay(t_speed);
    }

}

void AllObjects::write_All(bool t_I2C)                          // TESTED for I2C
{                                                               // TESTED for GPIO Pins
    //
    // future development -- add digitalWrite for pins
    //

    int flags = 0b00000000;

    if (eightObjects[0].get_m_wLED_Status()) { flags = flags | 0b00000001; }
    if (eightObjects[1].get_m_wLED_Status()) { flags = flags | 0b00000010; }
    if (eightObjects[2].get_m_wLED_Status()) { flags = flags | 0b00000100; }
    if (eightObjects[3].get_m_wLED_Status()) { flags = flags | 0b00001000; }
    if (eightObjects[4].get_m_wLED_Status()) { flags = flags | 0b00010000; }
    if (eightObjects[5].get_m_wLED_Status()) { flags = flags | 0b00100000; }
    if (eightObjects[6].get_m_wLED_Status()) { flags = flags | 0b01000000; }
    if (eightObjects[7].get_m_wLED_Status()) { flags = flags | 0b10000000; }

    if (t_I2C)      // using I2C bus
    {
        Wire.beginTransmission(I2C_Address); 
        Wire.write(flags);
        Wire.endTransmission();
    }
    else            // using gpio pins
    {
        for (int idx = 0; idx < objectCount(); idx++) 
        {
            int a_gpioPin = eightObjects[idx].get_m_gpioPin();

            if (bitRead(flags,idx)== 1)
            {
                digitalWrite(a_gpioPin, HIGH);
            }
            else
            {
                digitalWrite(a_gpioPin, LOW);
            }
            
        }
    }

};
