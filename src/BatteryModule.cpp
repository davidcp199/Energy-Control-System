#include "BatteryModule.hpp"

double BatteryModule::getTemperature() const {
    return temperature_;
}

double BatteryModule::getVoltage() const {
    return voltage_;
}

double BatteryModule::getMaxPower() const {
    return maxPower_;
}

void BatteryModule::setTemperature(double temperature) {
    if (temperature < MIN_BATTERY_TEMPERATURE || temperature > MAX_BATTERY_TEMPERATURE) {
        throw std::invalid_argument("Temperature is out of the allowed range.");
    }
    
    temperature_ = temperature;
}

void BatteryModule::setVoltage(double voltage) {
    if (voltage < 0.0 || voltage > MAX_BATTERY_VOLTAGE) {
        throw std::invalid_argument("Voltage is out of the allowed range.");
    }

    voltage_ = voltage;
}

void BatteryModule::setMaxPower(double maxPower) {
    if (maxPower < 0.0 || maxPower > MAX_BATTERY_POWER) {
        throw std::invalid_argument("Maximum power is out of the allowed range.");
    }

    maxPower_ = maxPower;
}
