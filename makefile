CXXFLAGS = -std=c++14 -Wall

SimpleGradebook : Gradebook.o StudentLinkedList.o
	$(CXX) $(CXXFLAGS) ./obj/Gradebook.o ./obj/StudentLinkedList.o -o ./bin/SimpleGradebook

Gradebook.o : ./src/Gradebook.cpp ./src/HashMap.hpp ./src/StudentLinkedList.hpp
	$(CXX) $(CXXFLAGS) -c ./src/Gradebook.cpp -o ./obj/Gradebook.o

StudentLinkedList.o : ./src/StudentLinkedList.cpp ./src/StudentLinkedList.hpp
	$(CXX) $(CXXFLAGS) -c ./src/StudentLinkedList.cpp -o ./obj/StudentLinkedList.o

clean :
	rm ./obj/*.o
	rm ./bin/SimpleGradebook
