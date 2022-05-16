#ifndef SKIDPAD_EVENT_H
#define SKIDPAD_EVENT_H
#include <map>
#include <vector>
#include <iostream>
#include "../base_classes/Team.h"
#include "../base_classes/Event.h"


class SkidpadEvent : public Event  // SkidpadEvent class that inherits from the abstract class Event
{
    protected:
        // Methods:
        virtual void calculate_teams_points();  // Function that calculates points for teams (based on the map: teams_and_results).

    public:
        SkidpadEvent();
        SkidpadEvent(std::vector<Team> &teams);
        // Destructor:
        ~SkidpadEvent();
        // Methods
        virtual std::string get_file_info_name();
};

#endif

// DONE
