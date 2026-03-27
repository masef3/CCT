CXX = g++
CXXFLAGS = -Wall -Wextra -g -std=c++20 -O3 -flto
SRCS = sources
OBJCTS = objects
BIN = cct

SOURCES = $(wildcard $(SRCS)/*.cpp)

OBJECTS = $(SOURCES:$(SRCS)/%.cpp=$(OBJCTS)/%.o)

$(BIN): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(BIN)

$(OBJCTS)/%.o: $(SRCS)/%.cpp | $(OBJCTS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJCTS):
		mkdir -p $(OBJCTS)

.PHONY: clean rebuild tests install

clean:
	rm -f $(BIN) $(OBJECTS) *.folded *.perf-folded

rebuild:
	make clean
	make

install: $(BIN)
	make
	sudo cp $(BIN) /usr/local/bin


