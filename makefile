CPPUNI_PATH=/opt/cppunit
TEST_CLASS_PATH=./src/test

runner: runner.o TestList.o
	g++ -o runner runner.o TestList.o -L${CPPUNIT_PATH}/lib -lstdc++ -lcppunit -ldl

TestList.o:  ${TEST_CLASS_PATH}/data_structures/TestList.cc
	g++ -c ${TEST_CLASS_PATH}/data_structures/TestList.cc -I${CPPUNIT_PATH}/include

runner.o: ${TEST_CLASS_PATH}/runner.cpp
	g++ -c ${TEST_CLASS_PATH}/runner.cpp -I${CPPUNIT_PATH}/include

clean:
	rm -f *.o runner



