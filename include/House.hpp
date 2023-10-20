#ifndef HOUSE_HPP
#define HOUSE_HPP

class House {
public:

    // House Constructor. 
    // Initializes power consume, voltage, frequency, and current to 0.
    House(): powerIn_(0.0), voltage_(0.0), frequency_(0.0), current_(0.0){}

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
    double powerIn_;     // Amount of energy entering the house in Watts
    double voltage_;     // Voltage entering to the house in Volts.
    double frequency_;   // Frequency entering to the house in Hertz.
    double current_;     // Current entering to the house in Amps.
};

#endif
