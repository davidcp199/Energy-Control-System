#ifndef PARAMETERS_HPP
#define PARAMETERS_HPP

enum BatteryParameters {
    STANDARD_BATTERY_TEMPERATURE = 15, // Standard temperature for battery operation in Celsius degrees
    STANDARD_BATTERY_VOLTAGE = 24, // Standard voltage for battery operation in Volts
    STANDARD_BATTERY_POWER = 200, // Standard maximum charge/discharge power for the battery module in Watts
    MIN_BATTERY_TEMPERATURE = -20, // Minimum safe temperature for battery operation in Celsius degrees
    MAX_BATTERY_TEMPERATURE = 50, // Maximum safe temperature for battery operation in Celsius degrees
    MAX_BATTERY_VOLTAGE = 230, // Maximum voltage supported by the battery module in Volts
    MAX_BATTERY_POWER = 6000 // Maximum power storage capacity of the battery module in Watts
};

enum GridParameters {
    STANDARD_GRID_FREQUENCY = 60, // Standard frequency of the electrical grid in Hertz
    STANDARD_GRID_VOLTAGE = 220, // Standard voltage of the electrical grid in Volts
    MAX_GRID_FREQUENCY = 60, // Maximum frequency of the electrical grid in Hertz
    MAX_GRID_VOLTAGE = 220 // Maximum voltage of the electrical grid in Volts
};

#endif

