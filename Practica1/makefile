CXX = g++
CXXFLAGS = -O2 -Wall -Wextra

SRCS = $(wildcard *.cpp)
OUTS = $(SRCS:.cpp=.out)

all: $(OUTS)

%.out: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@
	@echo "compilado $@"

clean:
	@if ls *.out 1> /dev/null 2>&1; then \
		rm *.out; \
		echo "borrados .out"; \
	fi
	@if ls *.csv 1> /dev/null 2>&1; then \
		rm *.csv; \
		echo "borrados .csv"; \
	fi

.PHONY: all clean
