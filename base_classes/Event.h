#ifndef EVENT_H
#define EVENT_H
#include <map>
#include <iostream>
#include <vector>
#include "../constants.h"
#include "Team.h"


class Event  // Abstract class
{
    protected:
        event_type m_event_type;

        // Vector of the Teams that are participating in the event (required to be provided externally).
        std::vector<Team> teams_participating;

        // Map with teams and second map of categories in desired Event.
        std::map<Team, std::map<EventsCategories, double>> teams_and_results;

        // Array with teams and total points scored in the Event [Team, TotalPoints].
        std::map<Team, double> classification;

        // Vector with enum categories in the Event
        std::vector<EventsCategories> event_categories;

        // Function that sorts teams by their total score (not cirtual, as it only sorts the map by the amount of points that teams scored - same for every competition).
        void make_event_classification();

        // Calculating points for each event according to the rules.
        virtual void calculate_teams_points()=0;


    public:
        // Setting results to the attribute:
        void set_results(std::map<Team, std::map<EventsCategories, double>> &results, std::vector<EventsCategories> &categories_in_event);

        // Simulating the event.
        void simulate();

        // Default Constructor:
        Event();

        // Constructor:
        Event(std::vector<Team> p_teams_participating);

        // Destructor:
        virtual ~Event();

        // Getter of final event classification:
        std::map<Team, double> get_classification() const;

        // Getter of the name of file with information about the event.
        virtual std::string get_info_file_name()=0;
};

// Order of calling out the methods:
// event.set_results(results);
// event.simulate();
// event.get_classification();

#endif
