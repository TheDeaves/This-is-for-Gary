CXX = g++ #Using g++ compiler 
CXXFLAGS = -std=c++11 -Wall -ftest-coverage -fprofile-arcs 

OBJECTS = Combat.o Character.o Dialogue.o   # Others as needed

main: Driver.o $(OBJECTS) #Driver class go here
	$(CXX) $(CXXFLAGS) -o $@ $^


clean:
	$(RM) *.o *.gc* *.dSYM test/test core Driver

testBuild: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -Itest/catch/catch.hpp -o test/test $(OBJECTS) test/test.cpp

test: testBuild
	test/test --success