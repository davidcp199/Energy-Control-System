#ifndef INVERTER_HPP
#define INVERTER_HPP

#include "Storage.hpp"

class Inverter {
public:

    // Constructor with mode as an argument. 
    //Initializes storage with the mode and grid frequency, grid voltage, and battery current to 0.0.
    Inverter(int mode) : storage_(mode), GridFrequency_(0.0), GridVoltage_(0.0), batteryCurrent_(0.0){}
    
    // Constructor with mode and number of battery modules as arguments. 
    //Initializes storage, grid frequency, grid voltage, and battery current.
    Inverter(int mode, int numBatteries) : storage_(mode, numBatteries), GridFrequency_(0.0), GridVoltage_(0.0), batteryCurrent_(0.0){}

    // Controls the energy flow to/from the storage
    //Returns the remaining energy that could not be stored or extracted.
    double energyFlowBatteryModules(double power);

    /* Sets values for the selected battery module in storage
    *  If Voltage is modified, it will be changed in all battery modules
    *
    *   - int indexBatMod: Index of battery module values will be set
    *   - double temperature: New temperature value to set in the battery module
    *   - double voltage: New voltage value to set in all battery modules
    *   - double maxPower: New Maximun Power value to set in the battery module
    */
    void setBatteryModuleValues(int indexBatMod, double temperature, double voltage, double maxPower);

    // Gets a reference to the storage object.
    const Storage& getStorage() const;

    // Returns the energy charge of the system
    double getStoredPower();

    // Returns the free energy storage capacity of the system
    double getfreeStoragePower() ;

    // Sets the grid frequency to the specified value.
    void setGridFrequency(double gridFrequency);

    // Sets the grid voltage to the specified value.
    void setGridVoltage(double gridVoltage);

    // Gets the current grid frequency.
    double getGridFrequency() const;

    // Gets the current grid voltage.
    double getGridVoltage() const;

    // Returns true if the stored power is 0, and False otherwise.
    bool isEmptyStoredPower() const;

    // Gets the flowing battery current in amperes.
    double getBatteryCurrent() const;

    // Gets the battery voltage in volts.
    double getBatteryVoltage() const;

    // Gets the number of battery modules in the system.
    double getNumBatteryModules() const;

private:
    Storage storage_;

    double GridFrequency_;      // Current grid frequency
    double GridVoltage_;        // Current grid voltage
    double maxChargePower_;     // Maximun power system can charge
    double maxDischargePower_;  // Maximun power system can discharge
    double batteryCurrent_;     // Number of battery modules in the system.

    // Returns free power capacity
    double getFreePowerCapacity(){
        return storage_.getfreeStoredPower();
    }
};

#endif