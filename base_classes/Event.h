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
        EventType m_event_type;

        // Vector of the Teams that are participating in the event (required to be provided externally).
        std::vector<Team> m_teams_participating;

        // Map with teams and second map of categories in desired Event.
        std::map<Team, std::map<EventsCategories, double>> m_teams_and_results;

        // Array with teams and total points scored in the Event [Team, TotalPoints].
        std::map<Team, double> m_classification;

        // Vector with enum categories in the Event
        std::vector<EventsCategories> m_event_categories;

        // Vector of tuples with teams and points (tuples sorted by points)
        std::vector<std::pair<Team, double>> m_sorted_classification;

        // Function that sorts teams by their total score (not cirtual, as it only sorts the map by the amount of points that teams scored - same for every competition).
        void make_event_classification();

        // Calculating points for each event according to the rules.
        virtual void calculate_teams_points()=0;


    public:
        // Setting results to the attribute:
        void set_results(std::map<Team, std::map<EventsCategories, double>> &results);

        // Simulating the event.
        void simulate();

        void set_teams(std::vector<Team> &teams);

        // Default Constructor:
        Event();

        // Constructor:
        Event(std::vector<Team> teams_participating);  // FIXME: Shouldn`t we use initialization lists in all constructors?

        // Destructor:
        virtual ~Event();

        // Getter of map with final event unsorted classification:
        std::map<Team, double> get_classification() const;

        // Getter of vector with final event sorted classification:
        std::vector<std::pair<Team, double>> get_sorted_classification() const {return m_sorted_classification;}

        // Getter of the name of file with information about the event.
        virtual std::string get_info_file_name()=0;

        // Getter of the type of event as an enum
        EventType get_event_type() const {return m_event_type;}
};

// Order of calling out the methods:
// event.set_results(results);
// event.simulate();
// event.get_classification();

#endif
