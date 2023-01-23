all: walkin

walkin: walkIn.cpp List.o Patient.o
	g++ -Wall -o walkin walkIn.cpp list.o Patient.o

list.o: List.cpp List.h
	g++ -Wall -c List.cpp

Patient.o: Patient.cpp Patient.h
	g++ -Wall -c Patient.cpp

clean:	
	rm -f *.o walkin