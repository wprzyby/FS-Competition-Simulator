#ifndef COST_AND_MANUFACTURING_EVENT_H
#define COST_AND_MANUFACTURING_EVENT_H
#include <map>
#include <vector>
#include <iostream>
#include "../base_classes/Team.h"
#include "../base_classes/Event.h"


class CostAndManufacturingEvent : public Event  // CostAndManufacturingEvent class that inherits from the abstract class Event
{
    private:
        // Additional atributes
        std::map<Team, double> m_points_to_set;
        unsigned int m_finalists;
        // Methods:
        double get_points(double team_total_result, double max_points) const;


    protected:
        // Methods:
        virtual void calculate_teams_points();  // Function that calculates points for teams (based on the map: teams_and_results).


    public:
        // Constructors:
        CostAndManufacturingEvent();
        CostAndManufacturingEvent(std::vector<Team> &teams, unsigned int finalists, std::map<Team, double> points_to_set={});
        // Destructor:
        ~CostAndManufacturingEvent();
        // Methods
        virtual std::string get_info_file_name();
};

#endif

// DONE
