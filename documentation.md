# FORMULA STUDENT COMPETITION SIMULATOR
## General information
The purpose of the programme is to allow for quick simulation of the results of a Formula Student competition and its events by inputting teams' results. It allows calculation of teams' points awarded in desired events and saving a report of the whole competition to a text file. It may be utilised to solve Formula Student Quizzes questions and to allow competition judges and/or contestants to quickly determine final competition scores.

## Tackling of the problem
The working principles of the programme are simple: the user is required to provide information about the teams participating in the competition, select events to simulate and type points scored by teams in given categories in static events or times and penalties in dynamic events. Points are calculated according to competition rules that can be found on [this page](https://www.formulastudent.de/fileadmin/user_upload/all/2022/rules/FS-Rules_2022_v1.0.pdf). Afterwards the classification of selected events and the full competition is displayed on the screen and can be saved into a text file. To achieve this, a class hierarchy constructed to utilise polymorphism is used as described in the _Project structure_ section below.

## Project structure

### Base classes
1. Team - class representing a team participating in the competition, containing attributes like _name_, _university_ and _number_.
2. Event - a virtual class that is the basis for all the events present in Formula Student competitions. Its attributes are teams, categories present in the event, a map with the teams' results and a vector with a sorted final classification. It contains a virtual method for points calculation in every event. Its basic functionality is to calculate points for teams and provide a sorted classification.
3. Competition - a class that contains events and teams. Its basic functionality is running simulations for each event that it contains and making a final sorted classification with total points each team scored across all the events.
4. LapTimeParser - a class used to conveniently convert times provided by user to times later used in calculation of points. It handles penalties received by teams by parsing a _.json_ file containing information about time penalties for each possible infringement in the dynamic events.

### Events
A group of 7 classes inheriting from the virtual Event class. Each one contains its own event category vectors and methods used to calculate points according to the rules of the given event.

### General utilities
A set of files containing all additional auxiliary functions and variables used by base classes.
1. event_tools - defines functions helping with operations needed to calculate points, such as finding best times, comparing teams' times and rounding points with given precision.
2. exceptions - a set of classes defining custom exceptions that can occur during the use of the programme.
3. constants - a set of all global constant variables, enum vectors and maps utilised by base classes.
4. dynamic_event_penalties - a file containing information about penalties given for certain infringements that occur during the dynamic events. Defined with accordance with current rules.
5. enums - a folder containing the definitions of enums used across the project, representing event categories and event types.

### Interface
1. main - function used for communication with the user
2. ui_tools - a set of tools utilised to fetch user input
3. FileSaver - a class used to save a report about the events results and the whole competition classification to a human-readable text file.

### Used libraries
1. CATCH2 - a unit test framework that is utilised to test the project. [link](https://github.com/catchorg/Catch2)
2. JSON - a modern C++ library for simple usage of json files (used by LapTimeParser). [link](https://github.com/nlohmann/json)


## Unusual techniques used

### Enum to string conversion by using a stream operator
The conversion is achieved by defining enums within _.def_ files and including the definitions in a _.cpp_ file. By further utilising preprocessor definitions, a table of const* char[], indexed by the number corresponding to the enum, is created and used by the definition of _operator >>_ function to display the name of the enum.

### LapTimeParser
An unconventional way of convenient conversion of times from minutes, seconds and miliseconds to a desired format. Using a class to achieve this functionality allows for an easy config file interaction and necessary inclusion of penalties converted to times according to rules.


## Testing
Each class and utility within the programme logic is covered by unit tests performed using the CATCH2 unit test framework. To create sets of data for testing, random reasonable results were selected for teams in each event and pen-and-paper calculations were made with accordance to Formula Student rules to determine the correct points to be awarded. The same data was provided to the event classes in order to compare the results. Additionaly, every general utility was tested with data unrelated to a Formula Student competition (for example rounding points and finding maximum value).

## Possible improvements
- Implementation of a graphical user interface with extended exception handling instead of a console one for ease and speed of use.
- Addition of methods opening files contatining useful information about the respective events.
- Saving the state of the whole programme to a file to enable real-time simulation during real-life competitions.
- Overall optimisation (variable types, const vs non-const values, algorithms' efficiency).

# How to use

## Compilation
The project utilises compilation through CMake. To compile, download CMake. For apt-based Linux distributions, install through:
```
sudo apt install cmake
```
For Windows, click [here](https://cmake.org/download/).

With CMake, to compile the main programme, run the following commands in top-level project directory:
```
cmake .
make main
```

## Running tests
If using Visual Studio Code, tests can be run by running the _Build and run tests_ task defined in tasks.json. If not, tests can be run by executing the following commands:
```
cmake .
make tests
./run_tests
```

## Running the main programme
After compiling the main programme as described in the _Compilation_ section, run the _main_executable_.

The programme will ask for the information about teams. Be sure to enter numbers where numbers are to be provided (for example, team number). After entering all the teams, select that you don't want to add any more teams.

Then, you will be asked to choose the events to be simulated from a list. Afterwards, the simulation process will begin. You will need to enter points for categories in static events and times and infringement occurances in dynamic events for every team entered.

After providing all the necessary data, the final classification of the whole competition will be shown on the screen with an option to save it alongside the final classification for every simulated event to a text file that can be found in _/output_files_ directory.

# Contact
Adam Sieruga - @a.sieruga (at Gitlab), adamsie.protondynamic@gmail.com

Wojciech Przybylski - @wprzyby (at Gitlab), wojciech.protondynamic@gmail.com
