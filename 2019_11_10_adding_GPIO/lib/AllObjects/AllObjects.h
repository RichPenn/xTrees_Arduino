#ifndef ALLOBJECTS_H
#define ALLOBJECTS_H


class AllObjects : public OneObject {
  public:
    AllObjects(bool t_I2C_Active, int t_I2C_Address);  // default constructor

    int objectCount(); // number of object in eightObjects[] array
    
    void set_objStatus(int t_idx, bool t_tf, 
                       int t_pos, int t_gpioPin,
                       unsigned long t_timeOn,
                       unsigned long t_timeOff);

    void set_allON(int t_speed);
    void set_allOFF(int t_speed);

    void set_L2HON(unsigned int t_speed);
    void set_H2LON(unsigned int t_speed);

    void set_H2LOFF(unsigned int t_speed);
    void set_L2HOFF(unsigned int t_speed);

    void set_1_L2HON(unsigned int t_speed);
    void set_1_H2LON(unsigned int t_speed);

    void set_1_H2LOFF(unsigned int t_speed);
    void set_1_L2HOFF(unsigned int t_speed);

    void set_2_L2HON(unsigned int t_speed);   
    void set_2_H2LON(unsigned int t_speed);   

    void set_Flicker(unsigned int t_duration, int t_speed);

    void set_OddAndEven(unsigned int t_duration, int t_speed);

    void set_2_fromCenter(unsigned int t_duration, int t_speed);  // TO-DO

    void write_All(bool t_I2C);   // I2C or digital

   private:
    OneObject eightObjects[8];
    bool I2C_Active;
    int I2C_Address;
};

#endif // ALLOBJECTS_H
