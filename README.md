# Formula Student Competition Simulator

## Introduction
This app's goal is to allow for fast calculation of points received by teams in a Formula Student competition, based on their times and scores in various events and taking into account any penalties received. This quick and automatic calculation can then be used to solve points-related questions during Formula Student Quizzes quickly and efficiently without prior knowledge or looking into competition rules.

## Project structure
The project is divided into _lib_ and _src_ sections, the former containing the app's business logic and the latter containing the GUI code, allowing for user interaction. The project also features automatic tests for the logic.

## Building and running
The project is built with CMake and requires Qt to be installed on the system. To build it, run the following commands:

```bash
cmake -S . -B ./build
cmake --build ./build
```

and then locate and execute the _compsim_gui_ executable file. If you come across the issue of not locating the required Qt package, try running the command with an additional argument pointing towards your Qt installation path (i.e. _{home_directory}/Qt/6.6.1/gcc_64/lib/cmake_):
```bash
cmake -S . -B ./build -DCMAKE_PREFIX_PATH="<qt installation path>"
```
You can also run tets by locating the _run_tests_ executable in the _build/test_ directory.

To complete points calculation, you first need to choose the type of competition, i.e. FS Germany / FS Netherlands, and then enter the teams and select FS competition events to run. After finishing the setup, you can input all necessary times and penalties for each event in separate screens. Inputs can be changed later on and values of for example seconds exceeding 60 or milliseconds exceeding 1000 are allowed.

## Adjusting configuration

You can change the penalties given for different offenses mentioned in the Formula Student rules by editing the _dynamic_events_penalties.json_ file. Formulas for points for different FS competitions can be found in appropriately named files in the _lib_ directory (_dynamic/static_formulas\_<competition_type>_). The current configuration is consistent with version 1.1 of the FS Rules 2024.

## Responsible

### Contributors
- Wojciech Przybylski @wprzyby (wojciech.protondynamic@gmail.com)
- Adam Sieruga (adamsie.protondynamic@gmail.com)

### Currently maintaining
- Wojciech Przybylski @wprzyby (wojciech.protondynamic@gmail.com)
