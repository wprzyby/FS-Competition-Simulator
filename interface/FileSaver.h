#pragma once

#include <iostream>
#include "constants.h"
#include <compsim_classes/Competition.h>
#include <compsim_classes/Event.h>

class FileSaver
{
    private:
        std::string m_filepath;
        Competition m_competition;
        void save_competition_classification() const;
        void save_events_classifications() const;

    public:
        FileSaver(Competition competition, std::string filepath);
        void save_info() const;
        ~FileSaver(){}
};
