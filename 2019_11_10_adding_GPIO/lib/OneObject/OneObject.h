#ifndef ONEOBJECT_H
#define ONEOBJECT_H

class OneObject {
  public:
    OneObject();    // default constructor

    bool get_m_active_Status();
    void set_m_active_Status(    // sete active and position
        bool t_m_active,
        int t_m_position,
        int t_m_gpioPin,
        unsigned long t_m_timeOn,
        unsigned long t_m_timeOff );

    int  get_m_postiion();
    int  get_m_gpioPin();

    bool get_m_rLED_Status();
    void set_m_rLED_Status(bool f_OnOff);

    bool get_m_gLED_Status();
    void set_m_gLED_Status(bool f_OnOff);

    bool get_m_bLED_Status();
    void set_m_bLED_Status(bool f_OnOff);

    bool get_m_wLED_Status();
    void set_m_wLED_Status(bool f_OnOff);

    unsigned long get_m_timeOn();
    void set_m_timeOn(unsigned long	t_time);

    unsigned long get_m_timeOff();
    void set_m_timeOff(unsigned long t_time);

    unsigned long get_m_timeChange();
    void set_m_timeChange(unsigned long t_time);

    void print_m_all(bool t_Serial);

    unsigned long now();

    bool checkTime();

  private:
    bool m_active{0};  // in use
    int m_position{0}; // order in pattern 
    int m_gpioPin{0};  // gpio pin used (ignored with I2C)

    bool m_rLED{0};		// red LED
    bool m_gLED{0};		// green LED
    bool m_bLED{0};		// blue LED
    bool m_wLED{0};		// white LED

    unsigned long m_timeOn{0};     // these used for
    unsigned long m_timeOff{0};    // non-blocking
    unsigned long m_timeChange{0}; // delay (twinkle)

    bool stateChange;
};

#endif // ONEOBJECT_H
