#include <iostream>
#include <vector>
#include <map>
#include <cmath>

#include <compsim_classes/event_base.h>
#include <compsim_enums/enums.h>

#include "EnduranceEvent.h"
#include "constants.h"

void EnduranceEvent::init_event_config() {
    m_event_type = endurance;
    m_name = "Endurance Event";
    m_event_categories = CATEGORY_LISTS.at(endurance);
    m_base_points = 25;
    m_time_threshold_coefficient = 1.333;
}


std::map<Team, double> EnduranceEvent::find_teams_best_times() {
    std::map<Team, double> teams_and_corr_times;
    for(auto& team: m_teams) {
        teams_and_corr_times[team] = team.result_of_category(end_corrected_time);
    }
    return teams_and_corr_times;
}


void EnduranceEvent::additional_points_filling()
{
    if (!m_run_efficiency) {return;}

    std::map<Team, double> teams_and_uncorr_times;
    std::map<Team, double> teams_and_eff_factors;

    for(auto& team: m_teams) {
        teams_and_uncorr_times[team] = team.result_of_category(end_uncorrected_time);
        teams_and_eff_factors[team] = (team.result_of_category(energy_used) - team.result_of_category(energy_produced) * 0.9)
                                           * std::pow(team.result_of_category(end_uncorrected_time), 2);
    }

    double best_uncorr_time = find_best_time_overall(teams_and_uncorr_times);
    double best_eff_factor = find_best_time_overall(teams_and_eff_factors);

    // calculating points for each team in the efficiency part of the event
    // and adding them to the points that are already in classicifation
    for(auto& [team, team_uncorr_time]: teams_and_uncorr_times) {
        double team_efficiency_score;

        if(m_teams_and_points.at(team) == 0 || team_uncorr_time > 1.333*best_uncorr_time || team_uncorr_time == 0)
        {
            team_efficiency_score = 0;
        }
        else
        {
            team_efficiency_score = get_efficiency_points(best_eff_factor, teams_and_eff_factors.at(team));
        }

        m_teams_and_points.at(team) += rd_to_n_places(team_efficiency_score, 1);
    }

}


double EnduranceEvent::get_additional_points(double best_time_overall, double team_best_time) const
{
    double points = 225 * ( ( (best_time_overall*1.333 / team_best_time) - 1 ) / 0.333 );

    if (points < 0)
    {
        throw NegativeAdditionalPointsError();
    }

    return points;
}


double EnduranceEvent::get_efficiency_points(double best_eff_factor, double team_eff_factor) const
{
    double eff_max = best_eff_factor * 1.5;
    double points = 75 * ((eff_max - team_eff_factor) / (eff_max - best_eff_factor));

    if (points < 0)
    {
        points = 0; //TODO: negative points are theoretically possible, need to ask about this
    }

    return points;
}
