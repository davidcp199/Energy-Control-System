#include "Storage.hpp"

Storage:: Storage(int mode) : mode_(mode){
    if (mode == Basic) {
        batteryModules_.resize(2, BatteryModule());
        numBatteryModules_ = 2;

    } else if (mode == Standard) {
        batteryModules_.resize(3, BatteryModule());
        numBatteryModules_ = 3;

    } else if (mode == PRO) {
        batteryModules_.resize(5, BatteryModule());
        numBatteryModules_ = 5;

    } else {
        throw std::invalid_argument("Invalid Mode. Must be Basic, Standard o PRO.");
    }

    StoredPower_ = 0;
    Storage::updateCapacityVaules(); 
}

Storage::Storage(int mode, int numBatteries) : mode_(mode), numBatteryModules_(numBatteries){
    int maxBatteries;

    if (mode == Basic) {
        maxBatteries = MaxBatteriesBasic;
    } else if (mode == Standard) {
        maxBatteries = MaxBatteriesStandard;
    } else if (mode == PRO) {
        maxBatteries = MaxBatteriesPRO;
    } else {
        throw std::invalid_argument("Invalid Mode. Must be Basic, Standard o PRO.");
    }
    
    if (numBatteries > maxBatteries) {
        throw std::invalid_argument("The number of batteries exceeds the maximum allowed for the selected mode.");
    }
    
    batteryModules_.resize(numBatteries, BatteryModule());
    StoredPower_ = 0;
    Storage::updateCapacityVaules();
}

double Storage::manageBatteryModulesPower(double power){
    if (power > 0 && TotalMaxPower_ < (StoredPower_ + power)){
        throw std::invalid_argument("Not enough capacity power to chargue"); 

    }else if (power < 0 && power > StoredPower_){
        throw std::invalid_argument("Not enough power to dischargue"); 

    }else{
        StoredPower_ += power;
        FreeStoragePower_ = TotalMaxPower_ - StoredPower_;
    }

    return power / BMVoltage_;
}

void Storage::setBatteryModuleValues(int indexBatMod, double temperature, double voltage, double maxPower) {
    int aux = indexBatMod - 1;

    if (aux >= 0 && aux < numBatteryModules_) {
        batteryModules_[aux].setTemperature(temperature);
        batteryModules_[aux].setMaxPower(maxPower);
        
        for (int cont = 0; cont < numBatteryModules_; cont++){
            batteryModules_[cont].setVoltage(voltage);
        }

        Storage::updateCapacityVaules();

    } else {
        throw std::invalid_argument("Index exceeds number of battery modules.");
    }
}

int Storage::getMode() const{
    return mode_;
}

int Storage::getNumBatteryModules() const{
    return numBatteryModules_;
}

double Storage::getTotalPower() const{
    return TotalMaxPower_;
}

double Storage::getBMVoltage() const{
    return BMVoltage_;
}

void Storage::setStoredPower(int power){
    StoredPower_ = power;
}

double Storage::getStoredPower() const{
    return StoredPower_;
}

double Storage::getfreeStoredPower() const{
    return FreeStoragePower_;
}

bool Storage::isEmptyStoredPower() const{
    return StoredPower_ == 0;
}

const std::vector<BatteryModule>& Storage::getBatteryModules() const{
    return batteryModules_;
}

BatteryModule Storage::getBatteryModule(int indexBatMod) const{
    int aux = indexBatMod - 1;

    if (indexBatMod < 0 || aux > numBatteryModules_) {
        throw std::invalid_argument("Index exceeds number of battery modules.");
    }

    return batteryModules_[aux];
}
