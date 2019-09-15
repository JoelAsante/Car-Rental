# test:ArrayList.h ArrayList.cpp Car.h Car.cpp main.cpp carsdata.txt
# 	g++ -Wall -o test ArrayList.h ArrayList.cpp Car.h Car.cpp main.cpp carsdata.txt

test: ArrayList.h ArrayList.cpp Car.h Car.cpp main.cpp carsdata.txt
	g++ -Wall -o test ArrayList.cpp Car.cpp main.cpp 