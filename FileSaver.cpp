#include <iostream>
#include <fstream>
#include "FileSaver.h"


FileSaver::FileSaver(const Competition& competition, std::string filepath)
: m_competition(competition), m_filepath(filepath) {}


void FileSaver::save_competition_classification() const
{
    std::fstream file;
    try
    {
        file.open(m_filepath, std::ios::out|std::ios::app);
        file << "\n";
        file << "\n| COMPETITION CLASSIFICATION | \n";
        int counter = 1;
        for(auto& [team, score]: m_competition.get_final_classification())
        {
            file << counter << "." << team << " | " << score << "\n";
            counter++;
        }
        file << "\n";
        file << "--------------------------------------------------------------------------------------------------------------------------------------------------------------";
        file.close();
    }
    catch (const std::ifstream::failure& e)  // TODO: Sprawdzić, czy to zadziała
    {
        std::cout << "File not found: Couldn`t find provided file directory" << std::endl;
    }
}


void FileSaver::save_events_classifications() const
{
    std::fstream file;
    try
    {
        file.open(m_filepath, std::ios::out);
        file << "\n";
        file << "--------------------------------------------------------------------------------------------------------------------------------------------------------------";
        for(auto& [event_type, results]: m_competition.get_events_points())  // Iterating through every event
        {
            file << "\n| " << INFO_EVENT_NAMES.at(event_type) << " |\n";  // Printing event`s name
            int counter = 1;
            for(auto& [team, score]: results)
            {
                file << counter << "." << team << " | " << score << "\n";  // Printing teams` scores
                counter++;
            }
            file << "\n";
        }
        file.close();
    }
    catch (const std::ifstream::failure& e)
    {
        std::cout << "File not found: Couldn`t find provided file directory" << std::endl;
    }
}


void FileSaver::save_info() const
{
    // Saving info to files in propper order.
    save_events_classifications();
    save_competition_classification();
    //
}
