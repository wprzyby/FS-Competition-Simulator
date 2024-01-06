#pragma once

#include "Event.h"

class DynamicEvent : public Event {
    protected:
      double m_base_points;
      double m_time_threshold_coefficient;
      bool m_use_time_threshold=true;

      virtual void init_event_config()=0;
      virtual double get_additional_points(double, double) const {return 0;}
      virtual double get_additional_points(int, int) const {return 0;}
      virtual std::map<Team, double> find_teams_best_times();
      virtual void basic_points_filling();
      virtual void additional_points_filling() {}
      void fill_teams_points() override;

    public:
      DynamicEvent() : Event() {m_is_dynamic=true;}
      DynamicEvent(std::vector<Team>& teams_participating) : Event(teams_participating) {}

};