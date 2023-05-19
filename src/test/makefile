CPPUNI_PATH=/opt/cppunit

main: main.o testlist.o
	g++ -o test main.o testlist.o -L${CPPUNIT_PATH}/lib -lstdc++ -lcppunit -ldl

testlist.o: testlist.cc
	g++ -c testlist.cc -I${CPPUNIT_PATH}/include

main.o: main.cpp
	g++ -c main.cpp -I${CPPUNIT_PATH}/include

clean:
	rm -f *.o main



