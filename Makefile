CC := g++
CFLAGS := -g -std=c++20
test: catch_config.o test_acceleration.o Event.o Team.o AccelerationEvent.o exceptions.o Event_tools.o
	$(CC) $(CFLAGS) $^ -o $@

test_acceleration.o: ./tests/test_acceleration.cpp ./events/AccelerationEvent.h ./base_classes/Team.h ./events/AccelerationEvent.h constants.h exceptions.h
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

clean:
	rm -f *.gch
	rm -f *.o
	rm -f main
	rm -f ./tests/test