TARGET = ESS.exe

CPP_SRCS = \
../src/Grid.cpp \
../src/File.cpp \
../src/Simulation.cpp \
../src/Control.cpp

all: $(TARGET)

$(TARGET): $(CPP_SRCS)
	g++ -Wall -g -o $@ $(CPP_SRCS)

clean:
	rm -f $(TARGET)
