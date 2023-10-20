#include "PhotovoltaicPanel.hpp"
#include <stdexcept>

double PhotovoltaicPanel::getPowerProduced() const {
    return powerProduced_;
}

double PhotovoltaicPanel::getVoltage() const {
    return voltage_;
}

double PhotovoltaicPanel::getCurrent() const {
    return current_;
}

void PhotovoltaicPanel::setVoltageCurrent(double Voltage, double Current){
    if (Voltage < 0 || Voltage > 230){
        throw std::invalid_argument("Voltage produced by solar panel cannot be Negative or exceed 230 V");
    }

    if (Current < 0 || Current > 400){
        throw std::invalid_argument("Current produced by solar panel cannot be Negative or exceed 400 A");
    }

    voltage_ = Voltage;
    current_ = Current;
    updatePowerProduced();
}