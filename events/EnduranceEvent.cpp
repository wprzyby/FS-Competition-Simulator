#include <iostream>
#include <vector>
#include <map>
#include <cmath>

#include <compsim_classes/event_base.h>
#include <compsim_enums/enums.h>

#include "EnduranceEvent.h"
#include "constants.h"


void EnduranceEvent::calculate_teams_points()
{
    std::map<Team, double> teams_and_corr_times;
    std::map<Team, double> teams_and_uncorr_times;
    std::map<Team, double> teams_and_eff_factors;

    for(auto& [team, team_results]: m_teams_and_results)
    {
        teams_and_corr_times[team] = team_results.at(end_corrected_time);
        if (m_run_efficiency)
        {
            teams_and_uncorr_times[team] = team_results.at(end_uncorrected_time);
            teams_and_eff_factors[team] = (team_results.at(energy_used) - team_results.at(energy_produced) * 0.9)
                                           * std::pow(team_results.at(end_uncorrected_time), 2);
        }
    }

    double base_points = BASE_COMPLETION_POINTS.at(endurance);
    double time_threshold_coefficient = 1.333;

    fill_points_std_dynamic(base_points, time_threshold_coefficient, teams_and_corr_times, &get_endurance_points);
    if (!m_run_efficiency) {return;}

    double best_uncorr_time = find_best_time_overall(teams_and_uncorr_times);
    double best_eff_factor = find_best_time_overall(teams_and_eff_factors);

    // calculating points for each team in the efficiency part of the event
    // and adding them to the points that are already in classicifation
    for(auto& [team, team_uncorr_time]: teams_and_uncorr_times)
    {
        double team_efficiency_score;

        if(m_classification.at(team) == 0 || team_uncorr_time > 1.333*best_uncorr_time || team_uncorr_time == 0)
        {
            team_efficiency_score = 0;
        }
        else
        {
            team_efficiency_score = get_efficiency_points(best_eff_factor, teams_and_eff_factors.at(team));
        }

        m_classification.at(team) += rd_to_n_places(team_efficiency_score, 1);
    }

}


double EnduranceEvent::get_endurance_points(double best_time_overall, double team_best_time)
{
    double points = 300 * ( ( (best_time_overall*1.333 / team_best_time) - 1 ) / 0.333 );

    if (points < 0)
    {
        throw NegativeAdditionalPointsError();
    }

    return points;
}


double EnduranceEvent::get_efficiency_points(double best_eff_factor, double team_eff_factor)
{
    double points = 75 * ( 2 - (team_eff_factor / best_eff_factor) );

    if (points < 0)
    {
        throw NegativeAdditionalPointsError();
    }

    return points;
}
