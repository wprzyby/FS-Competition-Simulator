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
    void make_event_classification();  // Function that sorts teams by their total score (not cirtual, as it only sorts the map by the amount of points that teams scored - same for every competition).
    virtual void calculate_teams_points()=0;

    public:
    // Methods:
    virtual void set_results(std::map<Team, std::map<std::string, double>> &results)=0;  // Function to create teams_and_results map.
    void simulate();  // Simulating the event

    // Constructor:
    Event();
    Event(std::vector<Team> p_teams_participating);

    // Getters:
    std::map<Team, const double> get_classification() const;
    virtual std::string get_file_info_name()=0;  // Opens the file with information about the Event.
};

// Order of calling out the methods:
// event.set_results(results);
// event.simulate();
// event.get_classification();

#endif
