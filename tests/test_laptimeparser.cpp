#include "../base_classes/LapTimeParser.h"

#include "catch.hpp"
#include "../enums/enums.h"

/*
PENALTIES USED IN TESTS ARE FROM FORMULA STUDENT RULES 2022
POTENTIALLY SUBJECT TO CHANGE - IF PENALTIES DEFINED IN DEFAULT JSON FILE PENALTY CONFIG
ARE CHANGED TO COMPLY WITH CHANGING FS RULES, THESE TESTS BECOME INVALID
*/

TEST_CASE("Time parsing functionality via LapTimeParser")
{
    LapTimeParser parser;
    unsigned minutes = 0;
    unsigned seconds = 0;
    unsigned miliseconds = 0;
    unsigned number_of_doo = 0;
    unsigned number_of_oc = 0;
    unsigned number_of_uss = 0;
    EventType type = acceleration;

    SECTION("Basic parsing - no penalties")
    {
        type = acceleration;

        minutes = 0;
        seconds = 0;
        miliseconds = 0;
        CHECK(parser.parse_time(type, minutes, seconds, miliseconds) == 0);
        minutes = 0;
        seconds = 0;
        miliseconds = 500;
        CHECK(parser.parse_time(type, minutes, seconds, miliseconds) == 500);
        minutes = 1;
        seconds = 0;
        miliseconds = 0;
        CHECK(parser.parse_time(type, minutes, seconds, miliseconds) == 60000);
        minutes = 1;
        seconds = 0;
        miliseconds = 0;
        CHECK(parser.parse_time(type, minutes, seconds, miliseconds) == 60000);
        minutes = 0;
        seconds = 1;
        miliseconds = 0;
        CHECK(parser.parse_time(type, minutes, seconds, miliseconds) == 1000);
        minutes = 3;
        seconds = 25;
        miliseconds = 530;
        CHECK(parser.parse_time(type, minutes, seconds, miliseconds) == 205530);
        minutes = 3;
        seconds = 100;
        miliseconds = 2000;
        CHECK(parser.parse_time(type, minutes, seconds, miliseconds) == 282000);
    }

    SECTION("Parsing with penalties - acceleration")
    {
        type = acceleration;

        minutes = 0;
        seconds = 0;
        miliseconds = 0;
        number_of_doo = 1;
        number_of_oc = 0;
        number_of_uss = 0;
        CHECK(parser.parse_time(type, minutes, seconds, miliseconds,
                                number_of_doo, number_of_oc, number_of_uss) == 0);
        minutes = 1;
        seconds = 30;
        miliseconds = 500;
        number_of_doo = 3;
        number_of_oc = 0;
        number_of_uss = 0;
        CHECK(parser.parse_time(type, minutes, seconds, miliseconds,
                                number_of_doo, number_of_oc, number_of_uss) == 96500);
        minutes = 1;
        seconds = 30;
        miliseconds = 500;
        number_of_doo = 3;
        number_of_oc = 1;
        number_of_uss = 0;
        CHECK(parser.parse_time(type, minutes, seconds, miliseconds,
                                number_of_doo, number_of_oc, number_of_uss) == 0);
        minutes = 1;
        seconds = 30;
        miliseconds = 500;
        number_of_doo = 3;
        number_of_oc = 0;
        number_of_uss = 1;
        CHECK(parser.parse_time(type, minutes, seconds, miliseconds,
                                number_of_doo, number_of_oc, number_of_uss) == 0);
    }

    SECTION("Parsing with penalties - autocross")
    {
        type = autocross;

        minutes = 0;
        seconds = 0;
        miliseconds = 0;
        number_of_doo = 1;
        number_of_oc = 0;
        number_of_uss = 0;
        CHECK(parser.parse_time(type, minutes, seconds, miliseconds,
                                number_of_doo, number_of_oc, number_of_uss) == 0);
                                minutes = 0;
        minutes = 1;
        seconds = 30;
        miliseconds = 500;
        number_of_doo = 3;
        number_of_oc = 0;
        number_of_uss = 0;
        CHECK(parser.parse_time(type, minutes, seconds, miliseconds,
                                number_of_doo, number_of_oc, number_of_uss) == 96500);
        minutes = 1;
        seconds = 30;
        miliseconds = 500;
        number_of_doo = 3;
        number_of_oc = 1;
        number_of_uss = 0;
        CHECK(parser.parse_time(type, minutes, seconds, miliseconds,
                                number_of_doo, number_of_oc, number_of_uss) == 106500);
        minutes = 1;
        seconds = 30;
        miliseconds = 500;
        number_of_doo = 3;
        number_of_oc = 0;
        number_of_uss = 1;
        CHECK(parser.parse_time(type, minutes, seconds, miliseconds,
                                number_of_doo, number_of_oc, number_of_uss) == 0);
    }

    SECTION("Parsing with penalties - endurance")
    {
        type = endurance;

        minutes = 0;
        seconds = 0;
        miliseconds = 0;
        number_of_doo = 1;
        number_of_oc = 0;
        number_of_uss = 0;
        CHECK(parser.parse_time(type, minutes, seconds, miliseconds,
                                number_of_doo, number_of_oc, number_of_uss) == 0);
                                minutes = 0;
        minutes = 1;
        seconds = 30;
        miliseconds = 500;
        number_of_doo = 3;
        number_of_oc = 0;
        number_of_uss = 0;
        CHECK(parser.parse_time(type, minutes, seconds, miliseconds,
                                number_of_doo, number_of_oc, number_of_uss) == 96500);
        minutes = 1;
        seconds = 30;
        miliseconds = 500;
        number_of_doo = 3;
        number_of_oc = 1;
        number_of_uss = 0;
        CHECK(parser.parse_time(type, minutes, seconds, miliseconds,
                                number_of_doo, number_of_oc, number_of_uss) == 106500);
        minutes = 1;
        seconds = 30;
        miliseconds = 500;
        number_of_doo = 3;
        number_of_oc = 0;
        number_of_uss = 1;
        CHECK(parser.parse_time(type, minutes, seconds, miliseconds,
                                number_of_doo, number_of_oc, number_of_uss) == 96500);
    }

    SECTION("Parsing with penalties - skidpad")
    {
        type = skidpad;

        minutes = 0;
        seconds = 0;
        miliseconds = 0;
        number_of_doo = 1;
        number_of_oc = 0;
        number_of_uss = 0;
        CHECK(parser.parse_time(type, minutes, seconds, miliseconds,
                                number_of_doo, number_of_oc, number_of_uss) == 0);
                                minutes = 0;
        minutes = 1;
        seconds = 30;
        miliseconds = 500;
        number_of_doo = 3;
        number_of_oc = 0;
        number_of_uss = 0;
        CHECK(parser.parse_time(type, minutes, seconds, miliseconds,
                                number_of_doo, number_of_oc, number_of_uss) == 91100);
        minutes = 1;
        seconds = 30;
        miliseconds = 500;
        number_of_doo = 3;
        number_of_oc = 1;
        number_of_uss = 0;
        CHECK(parser.parse_time(type, minutes, seconds, miliseconds,
                                number_of_doo, number_of_oc, number_of_uss) == 0);
        minutes = 1;
        seconds = 30;
        miliseconds = 500;
        number_of_doo = 3;
        number_of_oc = 0;
        number_of_uss = 1;
        CHECK(parser.parse_time(type, minutes, seconds, miliseconds,
                                number_of_doo, number_of_oc, number_of_uss) == 0);
    }
}
