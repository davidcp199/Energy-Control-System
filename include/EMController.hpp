#ifndef EMController_H
#define EMController_H

#include "PhotovoltaicPanel.hpp"
#include "Grid.hpp"
#include "House.hpp"
#include "Inverter.hpp"

class EMController {
public:

    // Constructor with no arguments. Initializes all variable components to 0.0.
    EMController(): currentFromStorage_(0.0), voltageFromStorage_(0.0), frequencyFromGrid_(0.0), voltageFromGrid_(0.0), voltageFromPanel_(0.0), currentFromPanel_(0.0){}

    // Manages energy flow between components: inverter, solar panel, house, and grid.
    void manageEnergy(Inverter& inverter,PhotovoltaicPanel& solarpanel ,House& house, Grid& grid);

    // Gets the current from the energy storage system in Amps.
    double getCurrentFromStorage() const;

    // Gets the voltage from the energy storage system in Volts.
    double getVoltageFromStorage() const;

    // Gets the frequency from the grid in Hertz.
    double getFreqFromGrid() const;

    // Gets the voltage from the grid in Volts.
    double getVoltageFromGrid() const;

    // Gets the voltage from the solar panel in Volts.
    double getVoltageFromPanel() const;

    // Gets the current from the solar panel in Amps.
    double getCurrentFromPanel() const;

private:

    double currentFromStorage_; // Current from the energy storage system in Amps.
    double voltageFromStorage_; // Voltage from the energy storage system in Volts.

    double frequencyFromGrid_;  // Frequency from the grid in Hertz.
    double voltageFromGrid_;    // Voltage from the grid in Volts.

    double voltageFromPanel_;   // Voltage from the solar panel in Volts.
    double currentFromPanel_;   // Current from the solar panel in Amps.

    void setHouseValues(House& house, double current, double voltage, double freq){
        house.setCurrent(current);
        house.setVoltage(voltage);
        house.setFrequency(freq);
    }

    void initializeValues(Grid& grid, House& house){
        currentFromStorage_ = 0;
        voltageFromStorage_ = 0;
        frequencyFromGrid_ = 0;
        voltageFromGrid_ = 0;
        voltageFromPanel_ = 0;
        currentFromPanel_ = 0;

        grid.setEnergyBought(0.0);
        grid.setEnergySold(0.0);

        house.setCurrent(0.0);
        house.setFrequency(0.0);
        house.setVoltage(0.0);
    }

    // Updates current and voltage from the energy storage system based on the inverter's values.
    void updateVoltageCurrentStorage(Inverter inverter){
        currentFromStorage_ = inverter.getBatteryCurrent();
        voltageFromStorage_ = inverter.getBatteryVoltage();
    }

    // Updates current and voltage from the solar panel.
    void updateVoltageCurrentSolarpanel(PhotovoltaicPanel solarpanel){
        voltageFromPanel_ = solarpanel.getVoltage();
        currentFromPanel_ = solarpanel.getCurrent();

    }
    
    // Updates voltage and frequency from the grid based on the grid's values.
    void updateVoltageFreqGrid(Grid grid){
        voltageFromGrid_ = grid.getVoltage();
        frequencyFromGrid_ = grid.getFrequency();
    }


};
#endif