#include <iostream>
#include <fstream>

#include <compsim_classes/Competition.h>

#include "FileSaver.h"


FileSaver::FileSaver(Competition competition, std::string filepath)
{
    m_competition = std::move(competition);
    m_filepath = filepath;
}


void FileSaver::save_competition_classification() const
{
    std::fstream file;
    try
    {
        file.open(m_filepath, std::ios::out|std::ios::app);
        file << "\n| COMPETITION CLASSIFICATION | \n";
        int counter = 1;
        for(auto& [team, score]: m_competition.get_final_classification())
        {
            file << "   " << counter << ". " << team << ": " << score << "\n";
            counter++;
        }
        file << "\n";
        file << "--------------------------------------------------------------------------------------------------------------------------------------------------------------";

    }
    catch (const std::ifstream::failure& e)
    {
        std::cout << "File not found: Couldn`t find provided file directory" << std::endl;
    }
    file.close();
}


void FileSaver::save_events_classifications() const
{
    std::fstream file;
    try
    {
        file.open(m_filepath, std::ios::out);
        file << "--------------------------------------------------------------------------------------------------------------------------------------------------------------";
        file << "\n";
        for(auto& [event_type, results]: m_competition.get_events_classification())  // Iterating through every event
        {
            file << "\n| " << INFO_EVENT_NAMES.at(event_type) << " |\n";  // Printing event`s name
            int counter = 1;
            for(auto& [team, score]: results)
            {
                file << "   " << counter << ". " << team << ": " << score << "\n";  // Printing teams` scores
                counter++;
            }
            file << "\n";
        }

    }
    catch (const std::ifstream::failure& e)
    {
        std::cout << "File not found: Couldn`t find provided file directory" << std::endl;
    }
    file.close();
}


void FileSaver::save_info() const
{
    // Saving info to files in propper order.
    save_events_classifications();
    save_competition_classification();
    //
}
