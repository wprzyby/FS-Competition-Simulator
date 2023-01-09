#pragma once

#include "Event.h"

class StaticEvent : public Event {
    protected:
      unsigned int m_number_of_finalists=0;
      std::map<Team, double> m_points_to_set={};

      virtual void init_event_config(unsigned int number_of_finalists, std::map<Team, double> points_to_set)=0;
      virtual double get_points(double, double) const =0;
      virtual void no_finals_points_filling();
      virtual void finals_points_filling();
      void fill_teams_points() override;

    public:
      StaticEvent(): Event() {m_is_dynamic=false;}
      StaticEvent(std::vector<Team>& teams_participating) : Event(teams_participating) {}
};