#include <iostream>
#include <map>
#include <cmath>
#include "tools.h"


// class NegativeDeltaError(Exception):
//     def __init__(self, line):
//         super().__init__(colored("""Delta of the square polynominal is negative. Provided parameters are incorrect.""", "red"))
//         self.line = line


// def line():
//     return inspect.currentframe().f_back.f_lineno


double rdsigfigs(double N, double n);


std::map<std::string, float> calculate_distance_and_acceleration(float initial_speed, float end_speed, float time, int sigfigs)  // FIXME: Maybe enum instead of string?
{
    float acceleration = (end_speed - initial_speed)/time;
    float distance = ((end_speed + initial_speed)*time)/2;

    std::map<std::string, float> results;
    results.insert({"acceleration", rdsigfigs(acceleration, sigfigs)});
    results.insert({"distance", rdsigfigs(distance, sigfigs)});

    return results;
}


std::map<std::string, float> calculate_distance_and_time(int sigfigs, float end_speed, float initial_speed, float acceleration)
{
    float time = (end_speed - initial_speed)/acceleration;
    float distance = (end_speed*end_speed - initial_speed*initial_speed)/(2*acceleration);

    std::map<std::string, float> results;
    results.insert({"time", rdsigfigs(time, sigfigs)});
    results.insert({"distance", rdsigfigs(distance, sigfigs)});

    return results;
}


std::map<std::string, float> calculate_distance_and_initial_speed(int sigfigs, float end_speed, float time, float acceleration)
{
    float distance = end_speed*time - (acceleration*time*time)/2;
    float initial_speed = end_speed - acceleration*time;

    std::map<std::string, float> results;
    results.insert({"initial_speed", rdsigfigs(initial_speed, sigfigs)});
    results.insert({"distance", rdsigfigs(distance, sigfigs)});

    return results;
}


std::map<std::string, float> calculate_distance_and_end_speed(int sigfigs, float initial_speed, float time, float acceleration)
{
    float distance = (acceleration*time*time)/2 + initial_speed*time;
    float end_speed = acceleration*time + initial_speed;

    if (end_speed < 0.001) {end_speed = 0;}

    std::map<std::string, float> results;
    results.insert({"end_speed", rdsigfigs(end_speed, sigfigs)});
    results.insert({"distance", rdsigfigs(distance, sigfigs)});

    return results;
}


std::map<std::string, float> calculate_acceleration_and_time(int sigfigs, float initial_speed, float end_speed, float distance)
{
    float acceleration = (end_speed*end_speed - initial_speed*initial_speed)/(2*distance);
    float time = 2*distance/(end_speed + initial_speed);

    std::map<std::string, float> results;
    results.insert({"time", rdsigfigs(time, sigfigs)});
    results.insert({"acceleration", rdsigfigs(acceleration, sigfigs)});

    return results;
}


std::map<std::string, float> calculate_acceleration_and_initial_speed(int sigfigs, float time, float distance, float end_speed)
{
    float initial_speed = (2*distance - end_speed*time)/time;
    float acceleration = (end_speed - initial_speed)/time;

    std::map<std::string, float> results;
    results.insert({"time", rdsigfigs(time, sigfigs)});
    results.insert({"initial_speed", rdsigfigs(initial_speed, sigfigs)});

    return results;
}


std::map<std::string, float> calculate_acceleration_and_end_speed(int sigfigs, float time, float distance, float initial_speed)
{
    float acceleration = (2*(distance - initial_speed*time))/(time*time);
    float end_speed = (2*(distance - time*initial_speed))/time + initial_speed;

    if (end_speed < 0.001) {end_speed = 0;}

    std::map<std::string, float> results;
    results.insert({"acceleration", rdsigfigs(acceleration, sigfigs)});
    results.insert({"end_speed", rdsigfigs(end_speed, sigfigs)});

    return results;
}


std::map<std::string, float> calculate_time_and_initial_speed(int sigfigs, float acceleration, float distance, float end_speed)
{
    float initial_speed = sqrt(end_speed*end_speed - 2*acceleration*distance);
    float time = (end_speed - initial_speed)/acceleration;

    std::map<std::string, float> results;
    results.insert({"time", rdsigfigs(time, sigfigs)});
    results.insert({"initial_speed", rdsigfigs(initial_speed, sigfigs)});

    return results;
}


std::map<std::string, float> calculate_time_and_end_speed(int sigfigs, float acceleration, float distance, float initial_speed)
{
    float delta_sq = sqrt(4*initial_speed*initial_speed + 8*acceleration*distance);  //TODO: Exception (negative delta handling)
    float time_1 = (-2*initial_speed + delta_sq)/(2*acceleration);
    float time_2 = (-2*initial_speed - delta_sq)/(2*acceleration);

    float time;
    if (time_1 > time_2) {time = time_1;}
    else {time = time_2;}

    float end_speed = acceleration*time + initial_speed;

    if (end_speed < 0.001) {end_speed = 0;}

    std::map<std::string, float> results;
    results.insert({"time", rdsigfigs(time, sigfigs)});
    results.insert({"end_speed", rdsigfigs(end_speed, sigfigs)});

    return results;
}


std::map<std::string, float> calculate_initial_speed_and_end_speed(int sigfigs, float acceleration, float distance, float time)
{
    float initial_speed = (2*distance - acceleration*time*time)/(2*time);
    float end_speed = acceleration*time + initial_speed;

    if (end_speed < 0.001) {end_speed = 0;}

    std::map<std::string, float> results;
    results.insert({"initial_speed", rdsigfigs(initial_speed, sigfigs)});
    results.insert({"end_speed", rdsigfigs(end_speed, sigfigs)});

    return results;
}
