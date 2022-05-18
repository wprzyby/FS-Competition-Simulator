#ifndef LAP_TIME_PARSER_H
#define LAP_TIME_PARSER_H

#include <iostream>
#include <fstream>
#include <jsoncpp/json/json.h>
#include <jsoncpp/json/value.h>

#include "../constants.h"

class LapTimeParser
{
    private:
        Json::Value m_penalties_data;
        LaptimeMode m_mode;
        std::map<EventType, std::string> m_enum_conversion_map;
        void load_json_data(std::string file_path);
        double format_time(unsigned time_in_ms) const;
    public:
        LapTimeParser(LaptimeMode mode=ms);
        LapTimeParser(std::string config_path, LaptimeMode=ms);
        double parse_time(EventType event_mode, unsigned minutes, unsigned seconds, unsigned miliseconds, unsigned doo, unsigned oc, unsigned uss) const;
};


#endif