#ifndef EVENT_H
#define EVENT_H
#include <map>
#include <iostream>
#include <vector>
#include "Team.h"


class Event  // Abstract class
{
    protected:
    // Attributes:
    std::vector<Team> teams_participating;  // Vector of the Teams that are participating in the event (required to be provided externally).
    std::map<Team, std::map<std::string, double>> teams_and_results;  // Map with teams and second map of attributes created from Teams vector by a method.
    std::map<Team, const double> classification;  // Array with teams and total points scored in the Event [Team, TotalPoints].

    // Methods:
    virtual void create_teams_and_results_map()=0;  // Function to create teams_and_results map.
    void set_teams_results(std::map<Team,std::vector<double>> &results);  // Function to set results from provided vector in the event for every team participating.
    virtual void calculate_teams_points()=0;  // Function that calculates points for teams (based on the map: teams_and_results).
    void make_final_classification();  // Function that sorts teams by their total score (not cirtual, as it only sorts the map by the amount of points that teams scored - same for every competition).

    public:
    // Constructor:
    Event(std::vector<Team> teams);  // Constructor
    // Getters:
    std::map<Team, std::map<std::string, double>> get_teams_and_results() const;
    std::map<Team, const unsigned int> get_classification() const;
    virtual std::string get_file_info_name()=0;  // Opens the file with information about the Event.
};

#endif
