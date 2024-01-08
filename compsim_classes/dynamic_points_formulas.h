#include <map>
#include <string>

double m_acceleration_points(std::map<std::string, double> event_data, std::string team_name);
double dc_acceleration_points(std::map<std::string, double> event_data, std::string team_name);
double dv_acceleration_points(std::map<std::string, double> event_data, std::string team_name);

double m_autocross_points(std::map<std::string, double> event_data, std::string team_name);
double dc_autocross_points(std::map<std::string, double> event_data, std::string team_name);

double endurance_points(std::map<std::string, double> event_data, std::string team_name);
double efficiency_points(std::map<std::string, double> event_data, std::string team_name);

double m_skidpad_points(std::map<std::string, double> event_data, std::string team_name);
double dc_skidpad_points(std::map<std::string, double> event_data, std::string team_name);
double dv_skidpad_points(std::map<std::string, double> event_data, std::string team_name);



