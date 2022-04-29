#ifndef EVENT_H
#define EVENT_H
#include <map>
#include <vector>
#include "Team.h"


class Event  // Abstract class
{
    protected:
    // Attributes:
    std::vector<Team> teams_participating;  // Vector of the Teams that are participating in the event (required to be provided externally).
    std::map<Team, std::map<std::string, double>> teams_and_results;  // Map with teams and second map of attributes created from Teams vector by a method.
    std::map<Team, int> classification;  // Array with teams and total points scored in the Event [Team, TotalPoints].

    // Methods:
    virtual void create_teams_and_results_map()=0;  // Function to create teams_and_results map.
    virtual void set_teams_results()=0;  // Function to set results in the event for every team participating.
    virtual void calculate_teams_points()=0;  // Function that calculates points for teams (based on the map: teams_and_results).
    virtual void make_final_classification()=0;  // Function that sorts teams by their total score.
    virtual void open_info_file()=0;  // Opens the file with information about the Event.

    public:
    // Getters:
    std::map<Team, std::map<std::string, double>> get_teams_and_results();
    std::map<Team, int> get_classification();
};

#endif
