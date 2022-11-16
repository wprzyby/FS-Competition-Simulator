#include <iostream>
#include <vector>
#include <map>

#include <compsim_classes/event_base.h>
#include <compsim_enums/enums.h>

#include "AutocrossEvent.h"
#include "constants.h"

void AutocrossEvent::calculate_teams_points()
{
    double base_points = BASE_COMPLETION_POINTS.at(autocross);
    double time_threshold_coefficient = 1.25;
    std::map<Team, double> teams_and_best_times = find_teams_best_times();

    fill_points_std_dynamic(base_points, time_threshold_coefficient,
                            teams_and_best_times, &get_additional_points);
}


double AutocrossEvent::get_additional_points(double best_time_overall, double team_best_time)
{
    double points = 95.5 * ( ( ( (best_time_overall * 1.25) / team_best_time) - 1 ) / 0.25 );

    if (points < 0)
    {
        throw NegativeAdditionalPointsError();
    }

    return points;

}
