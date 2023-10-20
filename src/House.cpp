#include "House.hpp"
#include <stdexcept>

double House::getPowerIn() const {
    return powerIn_;
}

double House::getVoltage() const {
    return voltage_;
}

double House::getFrequency() const {
    return frequency_;
}

double House::getCurrent() const {
    return current_;
}

void House::setPowerIn(double power) {
    if (power < 0.0) {
        throw std::invalid_argument("Power cannot be negative.");
    }
    powerIn_ = power;
}

void House::setVoltage(double voltage) {
    if (voltage < 0.0) {
        throw std::invalid_argument("Voltage cannot be negative.");
    }
    voltage_ = voltage;
}

void House::setFrequency(double frequency) {
    if (frequency < 0.0) {
        throw std::invalid_argument("Frequency cannot be negative.");
    }
    frequency_ = frequency;
}

void House::setCurrent(double current) {
    if (current < 0.0) {
        throw std::invalid_argument("Current cannot be negative.");
    }
    current_ = current;
}