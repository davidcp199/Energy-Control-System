#ifndef PARAMETERS_HPP
#define PARAMETERS_HPP

/*
    Default values for battery parameters
*/
const double STANDARD_BATTERY_TEMPERATURE = 15.0; // Standard temperature for battery operation in Celsius degrees
const double STANDARD_BATTERY_VOLTAGE = 24.0; // Standard voltage for battery operation in Volts
const double STANDARD_BATTERY_POWER = 200.0; // Standard maximum charge/discharge power for the battery module in Watts

const double MIN_BATTERY_TEMPERATURE = -20; // Minimum safe temperature for battery operation in Celsius degrees
const double MAX_BATTERY_TEMPERATURE = 50; // Maximum safe temperature for battery operation in Celsius degrees

const double MAX_BATTERY_VOLTAGE = 230; // Maximum voltage supported by the battery module in Volts
const double MAX_BATTERY_POWER = 1000; // Maximum power storage capacity of the battery module in Watts

/*
    Default values for GRID parameters
*/
const double STANDARD_GRID_FREQUENCY = 60.0; // Standard frequency of the electrical grid in Hertz
const double STANDARD_GRID_VOLTAGE = 220.0; // Standard voltage of the electrical grid in Volts

const double MAX_GRID_FREQUENCY = 60.0; // Maximun frequency of the electrical grid in Hertz
const double MAX_GRID_VOLTAGE = 220.0; // Maximun voltage of the electrical grid in Volts

#endif
