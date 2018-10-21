EXE:=game

CXX= g++
AR= ar

CXXFLAGS+= -std=c++98 -Wall -Wformat

MAIN_SRC+= ./src/main.cpp \
./src/card.cpp
MAIN_OBJS= $(MAIN_SRC:.cpp=.o)

all: $(EXE)

clean:
	@rm -f $(EXE) $(MAIN_OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $^

$(EXE): $(MAIN_OBJS)
	@echo $^
	$(CXX) $(CXXFLAGS) -o $@ $^
