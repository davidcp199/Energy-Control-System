#ifndef PHOTOVOLTAICPANEL_HPP
#define PHOTOVOLTAICPANEL_HPP

class PhotovoltaicPanel {
public:
    
    // Constructor with no arguments. Initializes voltage, current, and power produced to 0.0.
    PhotovoltaicPanel(){};

    // Constructor with specified voltage and current. Initializes voltage, current, and calculates power produced.
    PhotovoltaicPanel(double Voltage, double Current): voltage_(Voltage), current_(Current), powerProduced_(Voltage * Current){};

    // Gets the amount of power produced in Watts.
    double getPowerProduced() const;

    // Gets the voltage produced in Volts.
    double getVoltage() const;

    // Gets the current produced in Amps.
    double getCurrent() const;

    // Sets the voltage and current values.
    void setVoltageCurrent(double Voltage, double Current);

private:
    double voltage_ = 0.0;        // Produced voltage in Volts
    double current_ = 0.0;        // Produced current in Amps
    double powerProduced_ = 0.0;  // Amount of energy produced in Watts

    void updatePowerProduced() {
        powerProduced_ = voltage_ * current_;
    }
};

#endif