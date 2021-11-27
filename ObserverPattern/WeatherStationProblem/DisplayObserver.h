#ifndef __Display_H_
#define __Display_H_
#include <iostream>
#include "Observer_Interface.h"
#include "Subject_Interface.h"
#include "WeatherSubject.h"

class Display: public Observer{
public:
    Display() = default;
    Display(Subject *wd) : WeatherData(wd){
        wd->register_observer(this);
    };
    void update(double t, double p, double h) override;
    void display_changes();

private:
    Subject *WeatherData;
    int number_of_readings = 0;
    double temp = 0.0f;
    double pressure = 0.0f;
    double humidity = 0.0f;
};

// Implementation


inline void Display::update(double t, double p, double h) {
    this->temp = t;
    this->pressure = p;
    this->humidity = h;
    display_changes();
}

inline void Display::display_changes() {
    std::cout << "Temperature = " << t << std::endl;
    std::cout << "Pressure = " << p << std::endl;
    std::cout << "Humidity = " << h << std::endl;
}
#endif