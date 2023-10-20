#include "Grid.hpp"
#include <stdexcept>

double Grid::getEnergySold() const {
    return energySold_;
}

double Grid::getEnergyBought() const {
    return energyBought_;
}

double Grid::getVoltage() const {
    return voltage_;
}

double Grid::getFrequency() const {
    return frequency_;
}

void Grid::setEnergySold(double EnergySold) {
    if (EnergySold < 0) {
        throw std::invalid_argument("Energy Sold to Grid cannot be negative");
    }
    energySold_ = EnergySold;
}

void Grid::setEnergyBought(double EnergyBought) {
    if (EnergyBought < 0) {
        throw std::invalid_argument("Energy Bought to Grid cannot be negative");
    }
    energyBought_ = EnergyBought;
}

void Grid::setVoltage(double voltage) {
    if (voltage < 0 || voltage > 230) {
        throw std::invalid_argument("Grid Voltage cannot be negative or higher than 230 V");
    }
    voltage_ = voltage;
}

void Grid::setFrequency(double frequency) {
    if (frequency < 0 || frequency > 60) {
        throw std::invalid_argument("Grid Frecuency cannot be negative or higher than 60 Hz");
    }
    frequency_ = frequency;
}