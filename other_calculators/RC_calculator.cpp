#include <iostream>
#include <cmath>
#include <map>
#include "tools.h"


float energy_dissipated(float initial_voltage, float end_voltage, float capacitance, int sigfigs);


std::map<std::string, float> calculate_initial_voltage(float end_voltage, float capacitance, float resistance, float time, int sigfigs)
{
    float initial_voltage = end_voltage/(exp(-time/(resistance*capacitance)));
    float energy = energy_dissipated(initial_voltage, end_voltage, capacitance, sigfigs);

    std::map<std::string, float> results;
    results.insert({"initial_voltage", rdsigfigs(initial_voltage, sigfigs)});
    results.insert({"energy", rdsigfigs(energy, sigfigs)});

    return results;
}


std::map<std::string, float> calculate_end_voltage(float initial_voltage, float capacitance, float resistance, float time, int sigfigs)
{
    float end_voltage = initial_voltage*(exp(-time/(resistance*capacitance)));
    float energy = energy_dissipated(initial_voltage, end_voltage, capacitance, sigfigs);

    std::map<std::string, float> results;
    results.insert({"end_voltage", rdsigfigs(end_voltage, sigfigs)});
    results.insert({"energy", rdsigfigs(energy, sigfigs)});

    return results;
}


std::map<std::string, float> calculate_capacitance(float initial_voltage, float end_voltage, float resistance, float time, int sigfigs)
{
    float capacitance = (-time/(resistance*log(end_voltage/initial_voltage)));
    float energy = energy_dissipated(initial_voltage, end_voltage, capacitance, sigfigs);

    std::map<std::string, float> results;
    results.insert({"capacitance", rdsigfigs(capacitance, sigfigs)});
    results.insert({"energy", rdsigfigs(energy, sigfigs)});

    return results;
}


std::map<std::string, float> calculate_resistance(float initial_voltage, float capacitance, float end_voltage, float time, int sigfigs)
{
    float resistance = (-time/(capacitance*log(end_voltage/initial_voltage)));
    float energy = energy_dissipated(initial_voltage, end_voltage, capacitance, sigfigs);

    std::map<std::string, float> results;
    results.insert({"resistance", rdsigfigs(resistance, sigfigs)});
    results.insert({"energy", rdsigfigs(energy, sigfigs)});

    return results;
}


std::map<std::string, float> calculate_time(float initial_voltage, float capacitance, float resistance, float end_voltage, int sigfigs)
{
    float time = resistance*capacitance*log(initial_voltage/end_voltage);
    float energy = energy_dissipated(initial_voltage, end_voltage, capacitance, sigfigs);

    std::map<std::string, float> results;
    results.insert({"time", rdsigfigs(time, sigfigs)});
    results.insert({"energy", rdsigfigs(energy, sigfigs)});

    return results;
}


std::map<std::string, float> calculate_initial_voltage_DC(float end_voltage, float capacitance, float current, float time, int sigfigs)
{
    float initial_voltage = (current*time)/capacitance + end_voltage;
    initial_voltage = absolute<float>(initial_voltage);
    float energy = energy_dissipated(initial_voltage, end_voltage, capacitance, sigfigs);

    std::map<std::string, float> results;
    results.insert({"initial_voltage", rdsigfigs(initial_voltage, sigfigs)});
    results.insert({"energy", rdsigfigs(energy, sigfigs)});

    return results;
}


std::map<std::string, float> calculate_end_voltage_DC(float initial_voltage, float capacitance, float current, float time, int sigfigs)
{
    float end_voltage = -(current*time)/capacitance + initial_voltage;
    end_voltage = absolute<float>(end_voltage);
    float energy = energy_dissipated(initial_voltage, end_voltage, capacitance, sigfigs);

    std::map<std::string, float> results;
    results.insert({"end_voltage", rdsigfigs(end_voltage, sigfigs)});
    results.insert({"energy", rdsigfigs(energy, sigfigs)});

    return results;
}


std::map<std::string, float> calculate_capacitance_DC(float initial_voltage, float end_voltage, float current, float time, int sigfigs)
{
    float capacitance = (current*time)/(initial_voltage - end_voltage);
    capacitance = absolute<float>(capacitance);
    float energy = energy_dissipated(initial_voltage, end_voltage, capacitance, sigfigs);

    std::map<std::string, float> results;
    results.insert({"capacitance", rdsigfigs(capacitance, sigfigs)});
    results.insert({"energy", rdsigfigs(energy, sigfigs)});

    return results;
}


std::map<std::string, float> calculate_current_DC(float initial_voltage, float capacitance, float end_voltage, float time, int sigfigs)
{
    float current = capacitance*(-end_voltage + initial_voltage)/time;
    current = absolute<float>(current);
    float energy = energy_dissipated(initial_voltage, end_voltage, capacitance, sigfigs);

    std::map<std::string, float> results;
    results.insert({"current", rdsigfigs(current, sigfigs)});
    results.insert({"energy", rdsigfigs(energy, sigfigs)});

    return results;
}


std::map<std::string, float> calculate_time_DC(float initial_voltage, float capacitance, float current, float end_voltage, int sigfigs)
{
    float time = capacitance*(-end_voltage + initial_voltage)/current;
    time = absolute<float>(time);
    float energy = energy_dissipated(initial_voltage, end_voltage, capacitance, sigfigs);

    std::map<std::string, float> results;
    results.insert({"time", rdsigfigs(time, sigfigs)});
    results.insert({"energy", rdsigfigs(energy, sigfigs)});

    return results;
}


float energy_dissipated(float initial_voltage, float end_voltage, float capacitance, int sigfigs)
{
    float Ep = 0.5*capacitance*initial_voltage*initial_voltage;
    float Ek = 0.5*capacitance*end_voltage*end_voltage;
    float result = 0;
    if (Ek > Ep)
    {
        result = rdsigfigs(Ek - Ep, sigfigs);
    }
    else
    {
        result = rdsigfigs(Ep - Ek, sigfigs);
    }
    return result;
}