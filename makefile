CPPUNI_PATH=/opt/cppunit
TEST_CLASS_PATH=./src/test
CLASS_PATH=./src/main

runner: runner.o TestList.o TestQueue.o TestMinPriorityQueue.o TestGraph.o TestStack.o Graph.o
	g++ -o runner runner.o TestList.o TestQueue.o TestMinPriorityQueue.o TestGraph.o TestStack.o Graph.o   -L${CPPUNIT_PATH}/lib -lstdc++ -lcppunit -ldl

TestList.o:  ${TEST_CLASS_PATH}/data_structures/TestList.cc
	g++ -c ${TEST_CLASS_PATH}/data_structures/TestList.cc -I${CPPUNIT_PATH}/include

TestQueue.o:  ${TEST_CLASS_PATH}/data_structures/TestQueue.cc
	g++ -c ${TEST_CLASS_PATH}/data_structures/TestQueue.cc -I${CPPUNIT_PATH}/include

TestMinPriorityQueue.o:  ${TEST_CLASS_PATH}/data_structures/TestMinPriorityQueue.cc
	g++ -c ${TEST_CLASS_PATH}/data_structures/TestMinPriorityQueue.cc -I${CPPUNIT_PATH}/include


TestGraph.o:  ${TEST_CLASS_PATH}/data_structures/TestGraph.cc
	g++ -c ${TEST_CLASS_PATH}/data_structures/TestGraph.cc -I${CPPUNIT_PATH}/include


TestStack.o:  ${TEST_CLASS_PATH}/data_structures/TestStack.cc
	g++ -c ${TEST_CLASS_PATH}/data_structures/TestStack.cc -I${CPPUNIT_PATH}/include

Graph.o:  ${CLASS_PATH}/data_structures/Graph.cc ${CLASS_PATH}/data_structures/Graph.h 
	g++ -c ${CLASS_PATH}/data_structures/Graph.cc


runner.o: ${TEST_CLASS_PATH}/runner.cpp
	g++ -c ${TEST_CLASS_PATH}/runner.cpp -I${CPPUNIT_PATH}/include



clean:
	rm -f *.o runner



