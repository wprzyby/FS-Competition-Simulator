#include <iostream>
#include <map>
#include <cmath>
#include "tools.h"


// Function get_line() is not needed as c++ has variable __LINE__


std::map<std::string, float> calculate_power(float current, int cells, float cell_voltage, float stack_resistance, int stacks_number, int sigfigs)
{
    float voltage = cells*cell_voltage;
    float resistance = stack_resistance/stacks_number;
    float power = voltage*current - current*current*resistance;
    float voltage_drop = voltage - current*resistance;

    std::map<std::string, float> results;
    results.insert({"voltage", rdsigfigs(voltage, sigfigs)});
    results.insert({"resistance", rdsigfigs(resistance, sigfigs)});
    results.insert({"power", rdsigfigs(power, sigfigs)});
    results.insert({"voltage_drop", rdsigfigs(voltage_drop, sigfigs)});

    return results;
}


std::map<std::string, float> calculate_current(float power, int cells, float cell_voltage, float stack_resistance, int stacks_number, int sigfigs)
{
    float voltage = cells*cell_voltage;
    float resistance = stack_resistance/stacks_number;
    float delta_sqrt = sqrt(voltage*voltage - 4*power*resistance);
    // TODO: Exception Handling: Negative delta
    float current = (voltage - delta_sqrt)/(2*resistance);
    float voltage_drop = voltage - current*resistance;

    std::map<std::string, float> results;
    results.insert({"voltage", rdsigfigs(voltage, sigfigs)});
    results.insert({"resistance", rdsigfigs(resistance, sigfigs)});
    results.insert({"current", rdsigfigs(current, sigfigs)});
    results.insert({"voltage_drop", rdsigfigs(voltage_drop, sigfigs)});

    return results;
}


std::map<std::string, float> calculate_energy_density(float cell_voltage, float nominal_capacity, float total_mass, int cells_in_stack, int numer_of_stacks, int sigfigs)
{
    float energy_density = (nominal_capacity*cells_in_stack*numer_of_stacks*cell_voltage)/(total_mass);

    std::map<std::string, float> results;
    results.insert({"energy_density", rdsigfigs(energy_density, sigfigs)});

    return results;
}


std::map<std::string, float> calculate_cell_voltage(float energy_density, float nominal_capacity, float total_mass, int cells_in_stack, int number_of_stacks, int sigfigs)
{
    float cell_voltage = (total_mass*energy_density)/(number_of_stacks*cells_in_stack*nominal_capacity);

    std::map<std::string, float> results;
    results.insert({"cell_voltage", rdsigfigs(cell_voltage, sigfigs)});

    return results;
}


std::map<std::string, float> calculate_nominal_capacity(float energy_density, float cell_voltage, float total_mass, int cells_in_stack, int number_of_stacks, int sigfigs)
{
    float nominal_capacity = (total_mass*energy_density)/(number_of_stacks*cells_in_stack*cell_voltage);

    std::map<std::string, float> results;
    results.insert({"nominal_capacity", rdsigfigs(nominal_capacity, sigfigs)});

    return results;
}


std::map<std::string, float> calculate_total_mass(float energy_density, float cell_voltage, float nominal_capacity, int cells_in_stack, int number_of_stacks, int sigfigs)
{
    float total_mass = (nominal_capacity*number_of_stacks*cells_in_stack*cell_voltage)/energy_density;

    std::map<std::string, float> results;
    results.insert({"total_mass", rdsigfigs(total_mass, sigfigs)});

    return results;
}


std::map<std::string, float> calculate_cells_in_stack(float energy_density, float cell_voltage, float nominal_capacity, float total_mass, int number_of_stacks, int sigfigs)
{
    float cells_in_stack = (total_mass*energy_density)/(number_of_stacks*cell_voltage*nominal_capacity);

    std::map<std::string, float> results;
    results.insert({"cells_in_stack", rdsigfigs(cells_in_stack, sigfigs)});

    return results;
}


std::map<std::string, float> calculate_number_of_stacks(float energy_density, float cell_voltage, float nominal_capacity, float total_mass, int cells_in_stack, int sigfigs)
{
    float number_of_stacks = (total_mass*energy_density)/(cells_in_stack*cell_voltage*nominal_capacity);

    std::map<std::string, float> results;
    results.insert({"number_of_stacks", rdsigfigs(number_of_stacks, sigfigs)});

    return results;
}
