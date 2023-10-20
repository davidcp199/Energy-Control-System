#include <iostream>
#include <cassert>

#include "EMController.hpp"

// Unit test for PhotovoltaicPanel.
void TestPhotovoltaicPanel();

// Unit test for Grid.
void TestGrid();

// Unit test for BatteryModule.
void TestBatteryModule();

// Unit test for House.
void TestHouse();

// Unit test for Storage.
void TestStorage();

// Unit test for Inverter.
void TestInverter();

// Unit test for EMController.
void TestEMController();

// Displays a list of items and returns the chosen option.
int showList();

// Executes the main program logic.
void run();

int main() {

    TestPhotovoltaicPanel();
    TestGrid();
    TestBatteryModule();
    TestHouse();
    TestStorage();
    TestInverter();
    TestEMController();

    run();




    return 0;
}

void TestPhotovoltaicPanel() {
    PhotovoltaicPanel panel;

    assert(panel.getPowerProduced() == 0.0);
    assert(panel.getVoltage() == 0.0);
    assert(panel.getCurrent() == 0.0);
    std::cout<<"\nTest constructor PhotovoltaicPanel -> OK\n";

    panel.setVoltageCurrent(2.0, 3.0);

    assert(panel.getPowerProduced() == 6.0);
    assert(panel.getVoltage() == 2.0);
    assert(panel.getCurrent() == 3.0);
    std::cout<<"Test set values PhotovoltaicPanel -> OK\n";
    std::cout<<"Complete PhotovoltaicPanel -> OK\n\n";
}

void TestGrid() {
    Grid grid;

    assert(grid.getEnergyBought()==0.0);
    assert(grid.getEnergySold()==0.0);
    assert(grid.getFrequency()==60.0);
    assert(grid.getVoltage()==220.0);
    std::cout<<"Test constructor Grid -> OK\n";

    Grid grid2(5.0, 40.0);

    assert(grid2.getEnergyBought()==0.0);
    assert(grid2.getEnergySold()==0.0);
    assert(grid2.getFrequency()==40.0);
    assert(grid2.getVoltage()==5.0);
    std::cout<<"Test constructor Grid with arguments -> OK\n";

    grid.setEnergyBought(1.0);
    grid.setEnergySold(2.0);
    grid.setFrequency(15.0);
    grid.setVoltage(4.0);

    assert(grid.getEnergyBought()==1.0);
    assert(grid.getEnergySold()==2.0);
    assert(grid.getFrequency()==15.0);
    assert(grid.getVoltage()==4.0);
    std::cout<<"Test set values Grid -> OK\n";
    std::cout<<"Complete Grid -> OK\n\n";
}

void TestBatteryModule() {
    BatteryModule battery;

    assert(battery.getTemperature() == 15.0);
    assert(battery.getVoltage() == 24.0);
    assert(battery.getMaxPower() == 200.0);
    std::cout << "Test empty constructor Battery -> OK\n";

    battery.setTemperature(25.0);
    battery.setVoltage(48.0);
    battery.setMaxPower(5000.0);

    assert(battery.getTemperature() == 25.0);
    assert(battery.getVoltage() == 48.0);
    assert(battery.getMaxPower() == 5000.0);
    std::cout << "Test set values Battery -> OK\n";
    std::cout << "Complete Battery -> OK\n\n";
}

void TestHouse() {
    House house;

    assert(house.getPowerIn() == 0.0);
    assert(house.getVoltage() == 0.0);
    assert(house.getFrequency() == 0.0);
    assert(house.getCurrent() == 0.0);
    std::cout << "Test constructor House -> OK\n";

    house.setPowerIn(1000.0);
    house.setVoltage(220.0);
    house.setFrequency(60.0);
    house.setCurrent(5.0);

    assert(house.getPowerIn() == 1000.0);
    assert(house.getVoltage() == 220.0);
    assert(house.getFrequency() == 60.0);
    assert(house.getCurrent() == 5.0);
    std::cout << "Test set values House -> OK\n";
    std::cout << "Complete House -> OK\n\n";
}

void TestStorage() {
    Storage storage(2);

    assert(storage.getMode() == Storage::Standard);

    assert(storage.getNumBatteryModules() == 3);

    double expectedTotalPower = 0.0;
    for (const BatteryModule& batteryModule : storage.getBatteryModules()) {
        expectedTotalPower += batteryModule.getMaxPower();
    }

    assert(storage.getTotalPower() == expectedTotalPower);

    std::cout << "Test storage mode 2 (Standard) and 3 Battery Modules with all values == 0.0 -> OK\n";

    storage.setBatteryModuleValues(1,15,22,30);
    storage.setBatteryModuleValues(2,10,18,100);
    storage.setBatteryModuleValues(3,7,5,70);
    assert(storage.getTotalPower() == 200);
    std::cout << "Test storage mode 2 (Standard) and 3 Battery Modules changing values -> OK\n";

    assert(storage.getBatteryModule(3).getTemperature() == 7);

    assert(storage.getStoredPower() == 0);
    assert(storage.getfreeStoredPower() == 200 && storage.getTotalPower() == 200);

    storage.manageBatteryModulesPower(20.0);

    assert(storage.getStoredPower() == 20);
    assert(storage.getfreeStoredPower() == 180 && storage.getTotalPower() == 200);
    std::cout << "Charge Battery Modules -> OK\n";

    storage.manageBatteryModulesPower(-10.0);

    assert(storage.getStoredPower() == 10);
    assert(storage.getfreeStoredPower() == 190 && storage.getTotalPower() == 200);
    std::cout << "Discharge Battery Modules -> OK\n";
}

void TestInverter() {
    Inverter inverter(Storage::PRO, 3);

    inverter.setBatteryModuleValues(1, 25.0, 12.0, 100.0);
    inverter.setBatteryModuleValues(2, 26.0, 12.0, 110.0);
    inverter.setBatteryModuleValues(3, 27.0, 12.0, 120.0);

    inverter.getStorage().getBatteryModules();
    assert(inverter.getStorage().getBatteryModule(1).getTemperature() == 25.0);
    assert(inverter.getStorage().getBatteryModule(1).getVoltage() == 12.0);
    assert(inverter.getStorage().getBatteryModule(1).getMaxPower() == 100.0);
    
    assert(inverter.getStorage().getBatteryModule(2).getTemperature() == 26.0);
    assert(inverter.getStorage().getBatteryModule(2).getVoltage() == 12.0);
    assert(inverter.getStorage().getBatteryModule(2).getMaxPower() == 110.0);
    
    assert(inverter.getStorage().getBatteryModule(3).getTemperature() == 27.0);
    assert(inverter.getStorage().getBatteryModule(3).getVoltage() == 12.0);
    assert(inverter.getStorage().getBatteryModule(3).getMaxPower() == 120.0);

    std::cout<<"\nSet Battery Modules Inverter -> OK\n";
    
    double restCharge = inverter.energyFlowBatteryModules(60.0);
    assert(restCharge == 0.0);
    assert(inverter.getBatteryCurrent() == 5);
    double restDischarge = inverter.energyFlowBatteryModules(-24.0);
    assert(restDischarge == 0.0);
    assert(inverter.getBatteryCurrent() == -2);
    
    assert(inverter.getStoredPower() == 36.0);
    assert(inverter.getfreeStoragePower() == 294.0);

    std::cout<<"Flow energy from/to Battery Modules Inverter -> OK\n";
    
    inverter.setGridFrequency(60.0);
    inverter.setGridVoltage(220.0);
    
    assert(inverter.getGridFrequency() == 60.0);
    assert(inverter.getGridVoltage() == 220.0);

    std::cout<<"Test Inverter -> OK\n";
}

void TestEMController() {
    Inverter inverter(2);
    PhotovoltaicPanel solarpanel;
    House house;
    Grid grid;
    EMController emController;

    solarpanel.setVoltageCurrent(12.0, 5.0);
    house.setPowerIn(500.0);
    inverter.energyFlowBatteryModules(10);

    emController.manageEnergy(inverter, solarpanel, house, grid);

    assert(emController.getVoltageFromGrid() == house.getVoltage());
    assert(emController.getVoltageFromPanel() == 12.0);
    assert(emController.getFreqFromGrid() == 60.0);

    assert(inverter.getStoredPower() == 0.0);
    assert(grid.getEnergyBought() == 430.0);
    assert(grid.getEnergySold() == 0.0);

    std::cout<<"\nTest EMController: Solar Panel Power + Stored Power not enough to provide house -> OK\n";

    solarpanel.setVoltageCurrent(120.0, 15.0);
    house.setPowerIn(500.0);

    emController.manageEnergy(inverter, solarpanel, house, grid);

    assert(emController.getCurrentFromStorage() == house.getCurrent());    
    assert(house.getVoltage() == 24.0);
    assert(emController.getVoltageFromPanel() == 120.0);
    assert(inverter.getStoredPower() == 600.0);
    assert(grid.getEnergySold() == 700.0);
    assert(grid.getEnergyBought() == 0.0);

    std::cout<<"Test EMController: Solar Panel Power > House Power Consumption: Storage + Sell Rest -> OK\n\n";
    
}

int showList() {
    int op;

    std::cout<<"\nChoose an option:\n"
    <<"\t1. Change House Consume \n"
    <<"\t2. Change Photovoltaic panel Values\n"
    <<"\t3. Change Battery Module Values\n"
    <<"\t4. Change Grid Values \n"
    <<"\t5. Show Storage Status \n"
    <<"\t6. -> Energy Flow <-\n"
    <<"\t7. Exit \n"
    <<"Option: ";

    std::cin>>op;
    return op;

}

void run() {
    PhotovoltaicPanel panel;
    House house;
    Grid grid;
    EMController e;
    int mode;
    int option = 1;
    int consume, voltage, current, indexBM, temperature, maxPower;

    std::cout<<"Choose the mode you want to contract. Mode 1 comes with two built-in battery modules, Mode 2 with three, and Mode 3 with five.\n";
    std::cin>>mode;

    while(mode <= 0 || mode > 3){
        std::cout<<"Choose a valid mode. Mode 1 comes with two built-in battery modules, Mode 2 with three, and Mode 3 with five.\n";
        std::cin>>mode;        
    }
    Inverter inverter(mode);
    

    while (option != 7){
        option = showList(); 

        switch (option) {
            case 1:
                std::cout<<"Select the House Consume: ";
                std::cin>>consume;
                while(consume < 0){
                    std::cout<<"House consume cannot be negative\n";
                    std::cin>>consume;
                }

                house.setPowerIn(consume);
                break;

            case 2:
                std::cout<<"Select the PV voltage: ";
                std::cin>>voltage;
                while(voltage < 0 || voltage > 230){
                    std::cout<<"Select a correct voltage. Available values are 0 to 230 V\n";
                    std::cin>>voltage;
                }

                std::cout<<"Select the PV current: ";
                std::cin>>current;
                while(current < 0 || current > 400){
                    std::cout<<"Select a correct current. Available values are 0 to 400 A\n";
                    std::cin>>current;
                }

                panel.setVoltageCurrent(voltage,current);
                break;

            case 3:
                std::cout<<"Select the battery module in which you want to make changes: ";
                std::cin>>indexBM;
                while(indexBM > inverter.getNumBatteryModules()){
                    std::cout<<"Select a correct Battery module. Available values are 1 to "<<inverter.getNumBatteryModules()<<std::endl;
                    std::cin>>indexBM;
                }

                std::cout<<"Select the temperature: ";
                std::cin>>temperature;
                while(temperature > 50 || temperature < -20){
                    std::cout<<"Select a correct temperature. Available values are -20 to 50\n";
                    std::cin>>temperature;
                }

                std::cout<<"Select the voltage: ";
                std::cin>>voltage;
                while(voltage > 230 || voltage < 0.0){
                    std::cout<<"Select a correct voltage. Available values are 0 to 230\n";
                    std::cin>>voltage;
                }

                std::cout<<"Select the Maximun Storage Power: ";
                std::cin>>maxPower;
                while(maxPower < 0){
                    std::cout<<"Select a Maximun Power bigger than 0.0: \n";
                    std::cin>>maxPower;
                }

                inverter.setBatteryModuleValues(indexBM,temperature,voltage,maxPower);
                break;

            case 4:
                int voltage, freq;

                std::cout<<"Select the Grid voltage: ";
                std::cin>>voltage;
                while(voltage < 0 || voltage > 230){
                    std::cout<<"Select a correct voltage. Available values are 0 to 230 V\n";
                    std::cin>>voltage;
                }
                grid.setVoltage(voltage);

                std::cout<<"Select the Grid Frequency: ";
                std::cin>>freq;
                while(freq < 0 || freq > 60){
                    std::cout<<"Select a correct frequency. Available values are 0 to 60 A\n";
                    std::cin>>freq;
                }
                grid.setFrequency(freq);
                break;

            case 5:
                    std::cout<<"----------------------------------------------------------------------------------";
                    std::cout<<"\nMaximun Store Capacity: "<<inverter.getStoredPower()+inverter.getfreeStoragePower()<<" W"<<std::endl;
                    std::cout<<"\nStored power in storage: "<<inverter.getStoredPower()<<" W"<<std::endl;
                    std::cout<<"Free power capacity in storage: "<<inverter.getfreeStoragePower()<<" W"<<std::endl;
                    std::cout<<"----------------------------------------------------------------------------------";
                break;

            case 6:
                    e.manageEnergy(inverter,panel,house,grid);
                    std::cout<<"----------------------------------------------------------------------------------";
                    std::cout<<"\nVoltage provided by Solarpanel: "<<e.getVoltageFromPanel()<<" V"<<std::endl;
                    std::cout<<"Current provided by Solarpanel: "<<e.getCurrentFromPanel()<<" A"<<std::endl;
                    std::cout<<"Power provided by Solarpanel: "<<e.getCurrentFromPanel() * e.getVoltageFromPanel()<<" W"<<std::endl;

                    if (e.getCurrentFromStorage() < 0){
                        std::cout<<"\nCurrent Battery provided to House: "<<abs(e.getCurrentFromStorage())<<" A"<<std::endl;
                        std::cout<<"Voltage Battery provided to House: "<<e.getVoltageFromStorage()<<" V"<<std::endl;
                        std::cout<<"Power Battery provided to House: "<<abs(e.getCurrentFromStorage()) * e.getVoltageFromStorage()<<" W"<<std::endl;
                    }

                    std::cout<<"\nPower Sold to Grid: "<<grid.getEnergySold()<<" W"<<std::endl;
                    std::cout<<"Power Bought to Grid: "<<grid.getEnergyBought()<<" W"<<std::endl;
                    std::cout<<"Frequency Grid "<<inverter.getGridFrequency()<<" Hz"<<std::endl;
                    std::cout<<"Voltage Grid "<<inverter.getGridVoltage()<<" V"<<std::endl<<std::endl;
                    std::cout<<"----------------------------------------------------------------------------------";
                break;
            case 7:
                break;
            default:
                std::cout << "Invalid option. Please choose an option from 1 to 7." << std::endl;
                break;
        }
    }
}