#ifndef LAP_TIME_PARSER_H
#define LAP_TIME_PARSER_H

#include <iostream>
#include <fstream>

#include "../json.hpp"
#include "../constants.h"

using json = nlohmann::json;

class LapTimeParser
{
    private:
        json m_penalties_data;
        LaptimeMode m_mode;
        std::map<EventType, std::string> m_enum_conversion_map;
        void load_json_data(std::string file_path);
        double format_time(unsigned time_in_ms) const;
    public:
        LapTimeParser(LaptimeMode mode=ms);
        LapTimeParser(std::string config_path, LaptimeMode=ms);
        double parse_time(EventType event_mode, unsigned minutes, unsigned seconds, unsigned miliseconds, unsigned doo=0, unsigned oc=0, unsigned uss=0) const;
        void set_mode(LaptimeMode mode);
};


#endif