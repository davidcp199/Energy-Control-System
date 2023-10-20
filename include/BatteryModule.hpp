#ifndef BATTERYMODULE_HPP
#define BATTERYMODULE_HPP

#include <stdexcept>

class BatteryModule {
public:

    // Constructor with default values 
    //  - Temperature_  = 15.0 ºC
    //  - voltage = 24.0 V
    //  - Maximun charge/discharge Power = 200.0 W
    BatteryModule(): temperature_(15.0), voltage_(24.0), maxPower_(200.0) {}

    // Returns Temperature of the Battery Module
    double getTemperature() const;

    // Returns Voltage of the Battery Module
    double getVoltage() const;

    // Returns Maximun Power that the Battery Module can charge/discharge
    double getMaxPower() const;

    // Sets Temperature of the Battery Module
    void setTemperature(double temperature);

    // Sets Voltage of the Battery Module
    void setVoltage(double voltage);

    // Sets Maximun Power that the Battery Module can storage
    void setMaxPower(double maxPower);

private:
    double temperature_;    // Temperature of the Battery Module in Celsius degrees
    double voltage_;       // Voltage of the module in Volts
    double maxPower_;      // Maximum charge/discharge power of the module in Watts
};

#endif
