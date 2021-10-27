# makefile
#
# Author: aKuad
#
# Published with CC0 license
#

# Source info
TARGET = sqlite_make
HEDS =
SRCS = sqlite_make.cpp
OBJS = $(SRCS:.cpp=.o)
# Build config
CXX = g++
CXXFLAGS = -Wall -O2
LDFLAGS = -lsqlite3
RM = -rm

# Target - Build main
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) $(LDFLAGS) -o $(TARGET)

# Target - Build object files
%.o: %.cpp $(HEDS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Target - Remove build files
clean:
	$(RM) $(TARGET)
	$(RM) *.o

.PHONY: clean
