#pragma once

#include "compsim_enums/enums.h"
#include <map>
#include <vector>
#include <iostream>

#include <compsim_classes/event_base.h>


class EngineeringDesignEvent : public Event {
    protected:
      void fill_teams_points() override;  // Function that calculates points for teams (based on the map: teams_and_results).

    public:
      EngineeringDesignEvent() {init_event_type(engineering_design);}
      EngineeringDesignEvent(std::vector<Team> &teams)
                            : Event(teams) {init_event_type(engineering_design);}
};

class DCEngineeringDesignEvent: public EngineeringDesignEvent {
    public:
      DCEngineeringDesignEvent() {init_event_type(engineering_design_DC);}
      DCEngineeringDesignEvent(std::vector<Team> &teams)
                            : EngineeringDesignEvent(teams) {init_event_type(engineering_design);}
};
