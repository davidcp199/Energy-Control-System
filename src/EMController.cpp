#include "EMController.hpp"

void EMController::manageEnergy(Inverter& inverter, PhotovoltaicPanel& solarpanel, House& house, Grid& grid) {
    
    initializeValues(grid, house);

    double rest = (solarpanel.getPowerProduced() - house.getPowerIn());
    double aux = rest;

    updateVoltageCurrentSolarpanel(solarpanel);
    inverter.setGridVoltage(grid.getVoltage());
    inverter.setGridFrequency(grid.getFrequency());
    
    setHouseValues(house, solarpanel.getCurrent(), solarpanel.getVoltage(), 0.0);

    if(rest > 0){
        rest = inverter.energyFlowBatteryModules(aux);
        updateVoltageCurrentStorage(inverter);
        setHouseValues(house, inverter.getBatteryCurrent(), inverter.getBatteryVoltage(), 0);

        if (rest > 0){
            grid.setEnergySold(rest);
        }

    }else if (rest < 0){
        aux = rest;

        if (!inverter.isEmptyStoredPower()){
            rest = inverter.energyFlowBatteryModules(aux);

            updateVoltageCurrentStorage(inverter);
            setHouseValues(house, abs(currentFromStorage_), voltageFromStorage_, 0);            
        }

        grid.setEnergyBought(abs(rest));

        updateVoltageFreqGrid(grid);
        setHouseValues(house, 0, voltageFromGrid_, frequencyFromGrid_);

    }else{

    }
}

double EMController::getCurrentFromStorage() const{
    return currentFromStorage_;
}

double EMController::getVoltageFromStorage() const{
    return voltageFromStorage_;
}

double EMController::getFreqFromGrid() const{
    return frequencyFromGrid_;
}

double EMController::getVoltageFromGrid() const{
    return voltageFromGrid_;
}

double EMController::getVoltageFromPanel() const{
    return voltageFromPanel_;
}

double EMController::getCurrentFromPanel() const{
    return currentFromPanel_;
}