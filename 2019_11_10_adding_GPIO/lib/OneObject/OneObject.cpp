#include <Arduino.h>
#include "OneObject.h"

using namespace std;

OneObject::OneObject() {                                // TESTED
    // cout << "Default constructor for OneObject here\n";
}

bool OneObject::get_m_active_Status() {                 // TESTED
    return m_active;
};

void OneObject::set_m_active_Status                     // TESTED
    ( bool t_m_active, 
      int t_m_position, 
      int t_m_gpioPin, 
      unsigned long t_m_timeOn, 
      unsigned long t_m_timeOff) 
{
    this->m_active = t_m_active;
    this->m_position = t_m_position;
    this->m_gpioPin = t_m_gpioPin;
    this->m_timeOn = t_m_timeOn;
    this->m_timeOff = t_m_timeOff;
};

int OneObject::get_m_postiion() {                       //TESTED
    return m_position;
};

int OneObject::get_m_gpioPin() {
    return m_gpioPin;
}

bool OneObject::get_m_rLED_Status() {                   // TESTED   
    return m_rLED;
};

void OneObject::set_m_rLED_Status(bool f_OnOff) {       // TESTED
    this->m_rLED = f_OnOff;
};

bool OneObject::get_m_gLED_Status() {                   // TESTED
    return m_gLED;
};
void OneObject::set_m_gLED_Status(bool f_OnOff) {       // TESTED
    this->m_gLED = f_OnOff;
};

bool OneObject::get_m_bLED_Status() {                   // TESTED
    return m_bLED;
};

void OneObject::set_m_bLED_Status(bool f_OnOff) {       // TESTED
    this->m_bLED = f_OnOff;
};

bool OneObject::get_m_wLED_Status() {                   // TESTED
    return m_wLED;
};

void OneObject::set_m_wLED_Status(bool f_OnOff) {       // TESTED
    this->m_wLED = f_OnOff;
};

unsigned long OneObject::get_m_timeOn() {               // TESTED
    return m_timeOn;
};

void OneObject::set_m_timeOn(unsigned long	t_time) {   // TESTED
    this->m_timeOn = t_time;
};

unsigned long OneObject::get_m_timeOff() {              // TESTED
    return m_timeOff;
};

void OneObject::set_m_timeOff(unsigned long	t_time) {   // TESTED
    this->m_timeOff = t_time;
};

unsigned long OneObject::get_m_timeChange() {
    return m_timeChange;
};

void OneObject::set_m_timeChange(unsigned long	t_time) {
    this->m_timeChange = t_time;
};

unsigned long OneObject::now() {
    return millis();   // time since current program start in mills
    //
    // -- C equivelent of millis() for windows development / testing
    //
    // return std::chrono::duration_cast<std::chrono::
    //      milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    //
};

void OneObject::print_m_all(bool t_Serial) {
    if (t_Serial) {

    } else {
/*         cout
                << "\n Status       -> " << get_m_active_Status()
                << "\n Position     -> " << get_m_postiion()
                << "\n rLED status  -> " << get_m_rLED_Status()
                << "\n gLED status  -> " << get_m_gLED_Status()
                << "\n bLED status  -> " << get_m_bLED_Status()
                << "\n wLED status  -> " << get_m_wLED_Status()
                << "\n m_timeOn     -> " << get_m_timeOn()
                << "\n m_timeOff    -> " << get_m_timeOff()
                << "\n m_timeChange -> " << get_m_timeChange()
                << endl;
*/
    }
}

bool OneObject::checkTime() {
    if ( get_m_timeChange() < now()) {
        if (get_m_wLED_Status() == true) {
            m_wLED = false;
            m_timeChange = now() + m_timeOff;
        } else {
            m_wLED = true;
            m_timeChange = now() + m_timeOn;
        }
        stateChange = true;
    } else {
        stateChange = false;
    }
    return stateChange;
};
