#pragma once

#include "compsim_classes/StaticEvent.h"
#include "compsim_enums/enums.h"
#include "events/constants.h"
#include <map>
#include <vector>
#include <iostream>

#include <compsim_classes/event_base.h>


class CostAndManufacturingEvent : public StaticEvent  // CostAndManufacturingEvent class that inherits from the abstract class Event
{
    private:
      void init_event_config(unsigned int finalists, std::map<Team, double> points_to_set) override;
      double get_points(double team_total_result, double max_points) const override;

    public:
      CostAndManufacturingEvent(int finalists=0, std::map<Team, double> points_to_set={})
                                :StaticEvent() {init_event_config(finalists, points_to_set);}
      CostAndManufacturingEvent(std::vector<Team> &teams, int finalists=0, std::map<Team, double> points_to_set={})
                                :StaticEvent(teams) {init_event_config(finalists, points_to_set);}



};
