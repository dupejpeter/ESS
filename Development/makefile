TARGET = ESS.exe

CPP_SRCS = \
../src/Control.cpp \
../src/Grid.cpp

all: $(TARGET) test

$(TARGET): $(CPP_SRCS)
	g++ -Wall -g -o $@ $(CPP_SRCS)

TEST = test.exe

TEST_SRCS = \
../src/Grid.cpp \
../src/File.cpp \
../src/File_test.cpp

test: $(TEST)

$(TEST): $(TEST_SRCS)
	g++ -Wall -g -o $@ $^

clean:
	rm -f $(TARGET) $(TEST)
