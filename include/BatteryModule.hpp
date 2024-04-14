#ifndef BATTERYMODULE_HPP
#define BATTERYMODULE_HPP

#include <stdexcept>
#include "params.hpp"

class BatteryModule {
public:
    BatteryModule(){};
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
    double temperature_ = STANDARD_BATTERY_TEMPERATURE;    // Temperature of the Battery Module in Celsius degrees
    double voltage_ = STANDARD_BATTERY_VOLTAGE;       // Voltage of the module in Volts
    double maxPower_ = STANDARD_BATTERY_POWER;      // Maximum charge/discharge power of the module in Watts
};

#endif
