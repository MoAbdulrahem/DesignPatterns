#ifndef _WeatherData_H_
#define _WeatherData_H_
#include <list>
#include "Subject_Interface.h"
#include "Observer_Interface.h"

class WeatherData : public Subject(){
public:
    WeatherData() = default;
    void register_observer(Observer *) override;
    void remove_observer(Observer *) override;
    void notify() override;
    void set_measurements(const double &t, const double &p, const double &h);
    void measurements_changed() { notify(); };

private:
    std::list(Observer *) observers = {};
    double temperature = 0.0f;
    double humidity = 0.0f;
    double pressure = 0.0f;
};

inline void WeatherData::register_observer(Observer *o) {
    observers.push_back(o);
}

inline void WeatherData::remove_observer(Observer *o) {
    std::erase(observersl, o);
}

inline void WeatherData::notify(){
    for(auto o : observers){
        o->update(temprature, pressure, humidity);
    }
}

inline void WeatherData::set_measurements(const double &t, const double &p, const double &h) {
    this.temprature = t;
    this.pressure = p;
    this.humidity = h;
    measurements_changed()
}
#endif
