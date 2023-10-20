#include "Inverter.hpp"

double Inverter::energyFlowBatteryModules(double power){
    if (power > 0){
        maxChargePower_ = getFreePowerCapacity();

        if (power <= getFreePowerCapacity()){
            batteryCurrent_ = storage_.manageBatteryModulesPower(power);
            return 0;

        }else{
            batteryCurrent_ =storage_.manageBatteryModulesPower(maxChargePower_);
            return power - maxChargePower_;
        }

    }else{
        maxDischargePower_ = storage_.getStoredPower();

        if (abs(power) <= maxDischargePower_){
            batteryCurrent_ = storage_.manageBatteryModulesPower(power);
            return 0;

        }else{
            batteryCurrent_ = storage_.manageBatteryModulesPower(-maxDischargePower_); 
            return abs(power) - maxDischargePower_;
        }
    }
}

void Inverter::setBatteryModuleValues(int indexBatMod, double temperature, double voltage, double maxPower){
    if (temperature < -20.0 || temperature > 50.0) {
        throw std::invalid_argument("Temperature is out of the allowed range.");

    }else if (voltage < 0.0 || voltage > 230){
        throw std::invalid_argument("Voltage cannot be negative or exceed 230 V.");
    }

    storage_.setBatteryModuleValues(indexBatMod,temperature,voltage,maxPower);
}

const Storage& Inverter::getStorage() const {
    return storage_;
}

double Inverter::getStoredPower() {
    maxDischargePower_ = storage_.getStoredPower();

    return maxDischargePower_;
}

double Inverter::getfreeStoragePower() {
    maxChargePower_ = storage_.getfreeStoredPower();

    return maxChargePower_;
}

void Inverter::setGridFrequency(double gridFrequency){
    GridFrequency_ = gridFrequency;
}

void Inverter::setGridVoltage(double gridVoltage){
    GridVoltage_ = gridVoltage;
}

double Inverter::getGridFrequency() const{
    return GridFrequency_;
}

double Inverter::getGridVoltage() const{
    return GridVoltage_;
}

bool Inverter::isEmptyStoredPower() const{
    return storage_.isEmptyStoredPower();
}

double Inverter::getBatteryCurrent() const{
    return batteryCurrent_;
}

double Inverter::getBatteryVoltage() const{
    return storage_.getBMVoltage();
}

double Inverter::getNumBatteryModules() const{
    return storage_.getNumBatteryModules();
}