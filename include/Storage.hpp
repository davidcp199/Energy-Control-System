#ifndef STORAGE_HPP
#define STORAGE_HPP

#include "BatteryModule.hpp"
#include <vector>
#include <stdexcept>

class Storage {
public:
    // Modes of the System
    static const int Basic = 1;
    static const int Standard = 2;
    static const int PRO = 3;

    // Maximun number of battery modules for each Mode
    static const int MaxBatteriesBasic = 2;
    static const int MaxBatteriesStandard = 3;
    static const int MaxBatteriesPRO = 5;

    /*
    * Constructor with Mode as argument
    *
    * System will have the maximun number of battery modules for each mode
    * Mode 1: 2 Battery Modules
    * Mode 2: 3 Battery Modules
    * Mode 3: 5 Battery Modules
    */
    Storage(int mode);

    /* 
    * Constructor with Mode and Number of Battery Modules as argument
    * 
    * The system will have the battery modules selected in numBatteries
    * - Mode 1: max = 2 Battery Modules
    * - Mode 2: max = 3 Battery Modules
    * - Mode 3: max = 5 Battery Modules
     */
    Storage(int mode, int numBatteries);

    // Charges / Discharges Battery modules and returns current flowing from/to them
    double manageBatteryModulesPower(double power);

    /* Sets values for the selected battery module
    *  If Voltage is modified, it will be changed in all battery modules
    *
    *   - int indexBatMod: Index of battery module values will be set
    *   - double temperature: New temperature value to set in the battery module
    *   - double voltage: New voltage value to set in all battery modules
    *   - double maxPower: New Maximun Power value to set in the battery module
    */
    void setBatteryModuleValues(int indexBatMod, double temperature, double voltage, double maxPower);
    
    // Returns the system Mode (1 -> Basic, 2 -> Standard, 3 -> PRO)
    int getMode() const;

    // Returns the number of Battery Modules in the system
    int getNumBatteryModules() const;

    // Returns Maximun Power that can be charged/discharged
    double getTotalPower() const;

    // Gets the current voltage in the Battery Modules.
    double getBMVoltage() const;

    // Sets the power Stored in all the battery modules
    void setStoredPower(int power);

    // Returns the power Stored in the battery modules
    double getStoredPower() const;

    // Returns the free power storage in the system / rest power charge capacity
    double getfreeStoredPower() const;

    // Returns true if the stored power is 0, and False otherwise.
    bool isEmptyStoredPower() const;

    // Returns a vector with all the Battery Modules in the system wich cannot be modified
    const std::vector<BatteryModule>& getBatteryModules() const;

    // Returns Battery module selected with index
    BatteryModule getBatteryModule(int indexBatMod) const;


private:
    int mode_;                                      // Contracted mode rate
    std::vector<BatteryModule> batteryModules_;     // Vector with all battery modules
    int numBatteryModules_;                         // Number of Batteries in the system

    double TotalMaxPower_;                          // Max PW that can be Stored
    double BMVoltage_;                              // Voltage of the Battery Modules
    double StoredPower_;                            // Power that can be discharged from storage
    double FreeStoragePower_;                       // Power that can be charged in storage


    // Updates Maximun power that can be stored, Voltage of the Modules and charge capacity
    void updateCapacityVaules() {
        TotalMaxPower_ = 0.0;

        for (const BatteryModule& batteryModule : batteryModules_){
            TotalMaxPower_ += batteryModule.getMaxPower();
        }

        FreeStoragePower_ = TotalMaxPower_ - StoredPower_;
        setBMVoltage(batteryModules_[1].getVoltage());
    }

    // Set BMVoltage to voltage value
    void setBMVoltage(double voltage){
        BMVoltage_ = voltage;
    }
};

#endif