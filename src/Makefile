CXX = g++ #Using g++ compiler 
CXXFLAGS = -std=c++11 -Wall -ftest-coverage -fprofile-arcs 

OBJECTS = Combat/Combat.o Character/Character.o Dialogue/Dialogue.o Item/Item.o Shop/Shop.o DataStructs/Node.o DataStructs/Tree.o DataStructs/DLL.o # Others as needed

main: Driver.o $(OBJECTS) #Driver class go here
	$(CXX) $(CXXFLAGS) -o $@ $^


clean:
		rm -rf main.dSYM
	$(RM) ../*.o ../*.gc* test/*.o test/*.gc* *.dSYM test/test core mainma

testBuild: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -Itest/catch/catch.hpp -o test/test $(OBJECTS) test/test.cpp

test: testBuild
	test/test --success