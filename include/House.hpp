#ifndef HOUSE_HPP
#define HOUSE_HPP

class House {
public:

    // Gets the amount of power entering the house in Watts.
    double getPowerIn() const;

    // Gets the voltage entering to the house in Volts.
    double getVoltage() const;

    // Gets the frequency entering to the house in Hertz.
    double getFrequency() const;

    // Gets the current entering to the house in Amps.
    double getCurrent() const;

    // Sets the amount of power entering the house in Watts.
    void setPowerIn(double power);

    // Sets the voltage entering to the house in Volts.
    void setVoltage(double voltage);

    // Sets the frequency entering to the house in Hertz.
    void setFrequency(double frequency);

    // Sets the current entering to the house in Amps.
    void setCurrent(double current);

private:
    double powerIn_ = 0.0;     // Amount of energy entering the house in Watts
    double voltage_ = 0.0;     // Voltage entering to the house in Volts.
    double frequency_ = 0.0;   // Frequency entering to the house in Hertz.
    double current_ = 0.0;     // Current entering to the house in Amps.
};

#endif
