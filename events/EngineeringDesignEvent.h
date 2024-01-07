#pragma once

#include "compsim_classes/StaticEvent.h"
#include "compsim_enums/enums.h"
#include <map>
#include <vector>
#include <iostream>

#include <compsim_classes/event_base.h>


class EngineeringDesignEvent : public StaticEvent {
    private:
      void init_event_config(unsigned int finalists=0, std::map<Team, double> points_to_set={}) override;
      double get_points(double, double) const override {return 0;};

    public:
      EngineeringDesignEvent() {init_event_config();}
      EngineeringDesignEvent(std::vector<Team> &teams)
                            : StaticEvent(teams) {init_event_config();}
};

class DCEngineeringDesignEvent: public StaticEvent {
    private:
      void init_event_config(unsigned int finalists=0, std::map<Team, double> points_to_set={}) override;
      double get_points(double, double) const override {return 0;};

    public:
      DCEngineeringDesignEvent() {init_event_config();}
      DCEngineeringDesignEvent(std::vector<Team> &teams)
                            : StaticEvent(teams) {init_event_config();}
};
