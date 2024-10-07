
# Compiler flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall

# Object files
ofiles = TestingMain.o \
         SmartDevice.o LegacyThermostat.o \
         Command.o \
         Sensor.o 

# Target for the executable
main: $(ofiles)
	$(CXX) $(CXXFLAGS) $(ofiles) -o main
	chmod +x main  # Add execute permission

# Rules for generating object files
TestingMain.o: TestingMain.cpp SmartDevice.h LegacyThermostat.h \
               Command.h \
               Sensor.h
	$(CXX) $(CXXFLAGS) -c TestingMain.cpp -o TestingMain.o

SmartDevice.o: SmartDevice.cpp SmartDevice.h
	$(CXX) $(CXXFLAGS) -c SmartDevice.cpp -o SmartDevice.o

LegacyThermostat.o: LegacyThermostat.cpp LegacyThermostat.h
	$(CXX) $(CXXFLAGS) -c LegacyThermostat.cpp -o LegacyThermostat.o

Command.o: Command.cpp Command.h
	$(CXX) $(CXXFLAGS) -c Command.cpp -o Command.o

Sensor.o: Sensor.cpp Sensor.h
	$(CXX) $(CXXFLAGS) -c Sensor.cpp -o Sensor.o

# Run the program
run: main
	./main

# Run the program with Valgrind
valgrind: main
	valgrind --leak-check=full --track-origins=yes ./main

# Clean up
clean:
	rm -f *.o main
