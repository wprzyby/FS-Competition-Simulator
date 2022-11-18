#pragma once
#include <map>
#include <vector>
#include <iostream>

#include <compsim_classes/event_base.h>


class BusinessPlanEvent : public Event  // BusinessEvent class that inherits from the abstract class Event
{
    private:
      unsigned int m_finalists;
      std::map<Team, double> m_points_to_set;

    protected:
      void fill_teams_points() override;  // Function that calculates points for teams (based on the map: teams_and_results).

    public:
      BusinessPlanEvent(int finalists=0, std::map<Team, double> points_to_set={})
                        : m_finalists(finalists), m_points_to_set(points_to_set) {init_event_type(businessplan);}
      BusinessPlanEvent(std::vector<Team> &teams, int finalists=0, std::map<Team, double> points_to_set={})
                        : Event(teams), m_finalists(finalists), m_points_to_set(points_to_set) {init_event_type(businessplan);}

    private:
      double get_points(double team_total_result, double max_points) const;
};
