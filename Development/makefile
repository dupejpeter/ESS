TARGET = ESS.exe

CPP_SRCS = \
../src/Control.cpp \
../src/Grid.cpp \
../src/Simulation.cpp \
../src/File.cpp

all: $(TARGET) test

$(TARGET): $(CPP_SRCS)
	g++ -Wall -g -o $@ $(CPP_SRCS)

TEST = test.exe

TEST_SRCS = \
../src/Grid.cpp \
../src/Simulation.cpp \
../src/File.cpp \
../src/Simulation_test.cpp

test: $(TEST)

$(TEST): $(TEST_SRCS)
	g++ -Wall -g -o $@ $^

clean:
	rm -f $(TARGET) $(TEST)

clean_test:
	rm -f $(TEST)
