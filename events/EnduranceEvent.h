#ifndef ENDURANCE_EVENT_H
#define ENDURANCE_EVENT_H
#include <map>
#include <vector>
#include <iostream>
#include "../base_classes/Team.h"
#include "../base_classes/Event.h"


class EnduranceEvent : public Event  // EnduranceEvent class that inherits from the abstract class Event
{
    protected:
        // Methods:
        virtual void calculate_teams_points();  // Function that calculates points for teams (based on the map: teams_and_results).

    public:
        // Constructors:
        EnduranceEvent();
        EnduranceEvent(std::vector<Team> &teams);
        // Destructor:
        ~EnduranceEvent();
        // Methods
        virtual std::string get_file_info_name();
};

#endif

// DONE
