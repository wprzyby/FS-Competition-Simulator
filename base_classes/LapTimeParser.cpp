#include <iostream>
#include <fstream>

#include "LapTimeParser.h"
#include "../json.hpp"
#include "../constants.h"

LapTimeParser::LapTimeParser(LaptimeMode mode)
{
    load_json_data(DEF_PENALTY_DATA_FILE_PATH);
    m_mode = mode;
    m_enum_conversion_map = DYNAMIC_EVENT_ENUN_TO_STR;
}


LapTimeParser::LapTimeParser(std::string config_path, LaptimeMode mode)
{
    load_json_data(config_path);
    m_mode = mode;
    m_enum_conversion_map = DYNAMIC_EVENT_ENUN_TO_STR;
}


void LapTimeParser::load_json_data(std::string file_path)
{
    std::ifstream json_file(file_path, std::ifstream::binary);
    json_file >> m_penalties_data;
}


double LapTimeParser::parse_time(EventType event_mode, unsigned minutes, unsigned seconds,
                                 unsigned miliseconds, unsigned doo_cnt, unsigned oc_cnt,
                                 unsigned uss_cnt) const
{
    std::string event = m_enum_conversion_map.at(event_mode);
    json doo_penalty_data = m_penalties_data[event]["DOO"];
    json oc_penalty_data = m_penalties_data[event]["OC"];
    json uss_penalty_data = m_penalties_data[event]["USS"];
    unsigned laptime = 0;

    // check for DNF written as 0s laptime
    if(minutes == seconds == miliseconds == 0)
    {
        return 0;
    }

    // add base time to laptime
    laptime += minutes * 60 * 1000;
    laptime += seconds * 1000;
    laptime += miliseconds;

    // check for DNF penalty - if DNF, laptime is set to 0
    if(doo_penalty_data["dnf"].get<bool>() == true && doo_cnt > 0 ||
       oc_penalty_data["dnf"].get<bool>() == true && oc_cnt > 0 ||
       uss_penalty_data["dnf"].get<bool>() == true && uss_cnt > 0)
    {
        return 0;
    }

    // add necessary penalties to laptime
    laptime += doo_penalty_data["penalty"].get<int>() * doo_cnt;
    laptime += oc_penalty_data["penalty"].get<int>() * oc_cnt;
    laptime += uss_penalty_data["penalty"].get<int>() * uss_cnt;

    return format_time(laptime);

}


double LapTimeParser::format_time(unsigned time) const
{
    double ret_val;
    switch (m_mode)
    {
        case m:
            ret_val = double(time) / (60 * 1000);
            break;
        case s:
            ret_val = double(time) / 1000;
            break;
        case ms:
            ret_val = time;
            break;
    }
    return ret_val;
}

void LapTimeParser::set_mode(LaptimeMode mode)
{
    m_mode = mode;
}