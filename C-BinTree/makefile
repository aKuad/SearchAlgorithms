# makefile
#
# Author: aKuad
#
# Published with CC0 license
#

# Source info
EXE_NRM = bintree_normal
EXE_HAS = bintree_hash
HEDS = NodeBinTree.h
SRCS = NodeBinTree.cpp
OBJS = $(SRCS:.cpp=.o)
# Build config
CXX = g++
CXXFLAGS = -Wall -O2
RM = -rm -f

# Target - Build all
all: $(EXE_NRM) $(EXE_HAS)

# Target - Build liner_normal
$(EXE_NRM): $(EXE_NRM).o $(OBJS)
	$(CXX) $(CXXFLAGS) $(EXE_NRM).o $(OBJS) -o $(EXE_NRM)

# Target - Build liner_hash
$(EXE_HAS): $(EXE_HAS).o $(OBJS)
	$(CXX) $(CXXFLAGS) $(EXE_HAS).o $(OBJS) -o $(EXE_HAS)

# Target - Build object files
%.o: %.cpp $(HEDS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Target - Remove build files
clean:
	$(RM) $(EXE_NRM)
	$(RM) $(EXE_HAS)
	$(RM) *.o

.PHONY: all clean
