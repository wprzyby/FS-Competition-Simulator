#ifndef FILE_SAVER_H
#define FILE_SAVER_H

#include <iostream>
#include "../base_classes/Competition.h"
#include "../base_classes/Event.h"

class FileSaver
{
    private:
        std::string m_filepath;
        Competition m_competition;
        void save_competition_classification() const;
        void save_events_classifications() const;

    public:
        FileSaver(const Competition& competition, std::string filepath="./text_files/simulations.txt");
        void save_info() const;
        ~FileSaver(){}
};

#endif
