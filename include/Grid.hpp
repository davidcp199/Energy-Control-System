#ifndef GRID_HPP
#define GRID_HPP

#include "params.hpp"

class Grid {
public:

    // Constructor with specified voltage and frequency. Initializes energy sold and bought to 0.
    Grid(double Voltage, double Freq): energySold_(0.0), energyBought_(0.0), voltage_(Voltage), frequency_(Freq){}

    // Gets the amount of energy sold to grid in Watts.
    double getEnergySold() const;

    // Gets the amount of energy bought to grid in Watts.
    double getEnergyBought() const;

    // Gets the grid voltage in Volts.
    double getVoltage() const;

    // Gets the grid frequency in Hertz.
    double getFrequency() const;

    // Sets the amount of energy sold in Watts.
    void setEnergySold(double EnergySold);

    // Sets the amount of energy bought in Watts.
    void setEnergyBought(double EnergyBought);

    // Sets the grid voltage in Volts.
    void setVoltage(double voltage);

    // Sets the grid frequency in Hertz.
    void setFrequency(double frequency);

private:
    double energySold_ = 0.0;    // Amount of energy sold to the grid in Watts
    double energyBought_ = 0.0;  // Amount of energy bought from the grid in Watts
    double voltage_ = STANDARD_GRID_VOLTAGE;       // Grid voltage in Volts
    double frequency_ = STANDARD_GRID_FREQUENCY;     // Grid frequency in Hertz
};

#endif