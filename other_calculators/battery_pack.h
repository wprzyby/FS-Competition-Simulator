#ifndef BATTERY_PACK_H
#define BATTERY_PACK_H

#include<iostream>
#include <map>


std::map<std::string, float> calculate_power(float current, int cells, float cell_voltage, float stack_resistance, int stacks_number, int sigfigs);
std::map<std::string, float> calculate_current(float power, int cells, float cell_voltage, float stack_resistance, int stacks_number, int sigfigs);
std::map<std::string, float> calculate_energy_density(float cell_voltage, float nominal_capacity, float total_mass, int cells_in_stack, int numer_of_stacks, int sigfigs);
std::map<std::string, float> calculate_cell_voltage(float energy_density, float nominal_capacity, float total_mass, int cells_in_stack, int number_of_stacks, int sigfigs);
std::map<std::string, float> calculate_nominal_capacity(float energy_density, float cell_voltage, float total_mass, int cells_in_stack, int number_of_stacks, int sigfigs);
std::map<std::string, float> calculate_total_mass(float energy_density, float cell_voltage, float nominal_capacity, int cells_in_stack, int number_of_stacks, int sigfigs);
std::map<std::string, float> calculate_cells_in_stack(float energy_density, float cell_voltage, float nominal_capacity, float total_mass, int number_of_stacks, int sigfigs);
std::map<std::string, float> calculate_number_of_stacks(float energy_density, float cell_voltage, float nominal_capacity, float total_mass, int cells_in_stack, int sigfigs);


#endif