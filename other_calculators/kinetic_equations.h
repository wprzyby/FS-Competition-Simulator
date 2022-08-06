#ifndef KINETIC_EQUATIONS_H
#define KINETIC_EQUATIONS_H

#include <iostream>
#include <map>


std::map<std::string, float> calculate_distance_and_acceleration(float initial_speed, float end_speed, float time, int sigfigs);
std::map<std::string, float> calculate_distance_and_time(int sigfigs, float end_speed, float initial_speed, float acceleration);
std::map<std::string, float> calculate_distance_and_initial_speed(int sigfigs, float end_speed, float time, float acceleration);
std::map<std::string, float> calculate_distance_and_end_speed(int sigfigs, float initial_speed, float time, float acceleration);
std::map<std::string, float> calculate_acceleration_and_time(int sigfigs, float initial_speed, float end_speed, float distance);
std::map<std::string, float> calculate_acceleration_and_initial_speed(int sigfigs, float time, float distance, float end_speed);
std::map<std::string, float> calculate_acceleration_and_end_speed(int sigfigs, float time, float distance, float initial_speed);
std::map<std::string, float> calculate_time_and_initial_speed(int sigfigs, float acceleration, float distance, float end_speed);
std::map<std::string, float> calculate_time_and_end_speed(int sigfigs, float acceleration, float distance, float initial_speed);
std::map<std::string, float> calculate_initial_speed_and_end_speed(int sigfigs, float acceleration, float distance, float time);


#endif