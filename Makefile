CC := g++
CFLAGS := -g -std=c++20 -Wall
test: catch_config.o test_acceleration.o test_autocross.o Event.o Team.o AccelerationEvent.o AutocrossEvent.o exceptions.o Event_tools.o test_businessplan.o BusinessPlanEvent.o test_cost_and_manufacturing.o\
CostAndManufacturingEvent.o test_endurance.o EnduranceEvent.o test_engineering_design.o EngineeringDesignEvent.o test_event_functionalities.o test_skidpad.o SkidpadEvent.o#test_laptimeparser.o LapTimeParser.o
	$(CC) $(CFLAGS) $^ -o $@

test_acceleration.o: ./tests/test_acceleration.cpp ./events/AccelerationEvent.h ./base_classes/Team.h constants.h exceptions.h
	$(CC) $(CFLAGS) $^ -c
Event.o: ./base_classes/Event.cpp ./base_classes/Event.h constants.h ./base_classes/Team.h
	$(CC) $(CFLAGS) $^ -c
Team.o: ./base_classes/Team.h ./base_classes/Team.cpp exceptions.h
	$(CC) $(CFLAGS) $^ -c
AccelerationEvent.o: ./events/AccelerationEvent.cpp ./events/AccelerationEvent.h ./base_classes/Event.h ./base_classes/Team.h constants.h exceptions.h Event_tools.h
	$(CC) $(CFLAGS) $^ -c
catch_config.o: ./tests/catch_config.cpp ./tests/catch.hpp
	$(CC) $(CFLAGS) $^ -c
exceptions.o: exceptions.h exceptions.cpp
	$(CC) $(CFLAGS) $^ -c
Event_tools.o: Event_tools.h Event_tools.cpp ./base_classes/Team.h constants.h
	$(CC) $(CFLAGS) $^ -c
test_autocross.o: ./tests/test_autocross.cpp ./events/AutocrossEvent.h ./base_classes/Team.h ./events/AutocrossEvent.h constants.h exceptions.h
	$(CC) $(CFLAGS) $^ -c
AutocrossEvent.o: ./events/AutocrossEvent.cpp ./events/AutocrossEvent.h ./base_classes/Event.h ./base_classes/Team.h constants.h exceptions.h Event_tools.h
	$(CC) $(CFLAGS) $^ -c
test_businessplan.o: ./tests/test_businessplan.cpp ./events/BusinessPlanEvent.h ./base_classes/Team.h constants.h exceptions.h
	$(CC) $(CFLAGS) $^ -c
BusinessPlanEvent.o: ./events/BusinessPlanEvent.cpp ./events/BusinessPlanEvent.h ./base_classes/Event.h ./base_classes/Team.h constants.h exceptions.h Event_tools.h
	$(CC) $(CFLAGS) $^ -c
# test_competition.o: ./tests/test_competition.cpp ./base_classes/Competition.h ./events/AutocrossEvent.h ./events/EngineeringDesignEvent.h ./base_classes/Team.h constants.h exceptions.h
# 	$(CC) $(CFLAGS) $^ -c
test_cost_and_manufacturing.o: ./tests/test_cost_and_manufacturing.cpp ./events/CostAndManufacturingEvent.h ./base_classes/Team.h constants.h exceptions.h
	$(CC) $(CFLAGS) $^ -c
CostAndManufacturingEvent.o: ./events/CostAndManufacturingEvent.cpp ./events/CostAndManufacturingEvent.h ./base_classes/Event.h ./base_classes/Team.h constants.h exceptions.h Event_tools.h
	$(CC) $(CFLAGS) $^ -c
test_endurance.o: ./tests/test_endurance.cpp ./events/EnduranceEvent.h ./base_classes/Team.h constants.h exceptions.h
	$(CC) $(CFLAGS) $^ -c
EnduranceEvent.o: ./events/EnduranceEvent.cpp ./events/EnduranceEvent.h ./base_classes/Event.h ./base_classes/Team.h constants.h exceptions.h Event_tools.h
	$(CC) $(CFLAGS) $^ -c
test_engineering_design.o: ./tests/test_engineering_design.cpp ./events/EngineeringDesignEvent.h ./base_classes/Team.h constants.h exceptions.h
	$(CC) $(CFLAGS) $^ -c
EngineeringDesignEvent.o: ./events/EngineeringDesignEvent.cpp ./events/EngineeringDesignEvent.h ./base_classes/Event.h ./base_classes/Team.h constants.h exceptions.h Event_tools.h
	$(CC) $(CFLAGS) $^ -c
test_event_functionalities.o: ./tests/test_event_functionalities.cpp Event_tools.h ./events/AccelerationEvent.h ./base_classes/Team.h constants.h exceptions.h
	$(CC) $(CFLAGS) $^ -c
# test_laptimeparser.o: ./tests/test_laptimeparser.cpp ./base_classes/LapTimeParser.h
# 	$(CC) $(CFLAGS) $^ -c
# LapTimeParser.o: ./base_classes/LapTimeParser.h ./base_classes/LapTimeParser.cpp constants.h json.hpp
# 	$(CC) $(CFLAGS) $^ -c
test_skidpad.o: ./tests/test_skidpad.cpp ./events/SkidpadEvent.h ./base_classes/Team.h constants.h exceptions.h
	$(CC) $(CFLAGS) $^ -c
SkidpadEvent.o: ./events/SkidpadEvent.cpp ./events/SkidpadEvent.h ./base_classes/Event.h ./base_classes/Team.h constants.h exceptions.h Event_tools.h
	$(CC) $(CFLAGS) $^ -c
# Competition.o: ./base_classes/Competition.h ./base_classes/Competition.cpp ./base_classes/Team.h ./base_classes/Event.h constants.h
	$(CC) $(CFLAGS) $^ -c

clean:
# LINUX
#	rm -f *.gch
#	rm -f *.o
#	rm -f main
#	rm -f ./tests/test

# WINDOWS
	del -f *.gch
	del -f *.o
	cd tests && del -f *.gch
	cd tests && del -f *.o
	cd events && del -f *.gch
	cd events && del -f *.o
	cd base_classes && del -f *.gch
	cd base_classes && del -f *.o
	del -f main
	del -f test.exe