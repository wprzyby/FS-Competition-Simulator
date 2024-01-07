#pragma once
#include "compsim_enums/enums.h"
#include <map>
#include <vector>
#include <iostream>

#include <compsim_classes/event_base.h>
#include "constants.h"


class BusinessPlanEvent : public StaticEvent  // BusinessEvent class that inherits from the abstract class Event
{
    private:
      void init_event_config(unsigned int finalists, std::map<Team, double> points_to_set) override;
      double get_points(double team_total_result, double max_points) const override;
      void no_finals_points_filling() override;

    public:
      BusinessPlanEvent(unsigned int finalists=0, std::map<Team, double> points_to_set={})
                                :StaticEvent() {init_event_config(finalists, points_to_set);}
      BusinessPlanEvent(std::vector<Team> &teams, unsigned int finalists=0, std::map<Team, double> points_to_set={})
                                :StaticEvent(teams) {init_event_config(finalists, points_to_set);}
};
