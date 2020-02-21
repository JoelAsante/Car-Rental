//Joel Asante


#include"Car.h"
//default Constructor
Car::Car()
{
   id = 0;
   make = "";
   model = "";
   color = "";
}

//Overload Constructor
Car::Car(int id, string make, string model, string color)
{
   this->id = id;
   this->make = make;
   this->model = model;
   this->color = color;
}

//getters
int Car::getID()
{
   return id;
}
string Car::getModel()
{
   return model;
}
string Car::getMake()
{
   return make;
}
string Car::getColor()
{
   return color;
}

//setters
void Car::setID(int id)
{
   this->id = id;
}
void Car::setModel(string model)
{
   this->model = model;
}
void Car::setMake(string make)
{
   this->make = make;
}
void Car::setColor(string color)
{
   this->color = color;
}

//overload operator for input and outpur
ostream& operator << (ostream& out, const Car& c)
{
   out << c.id << " " << c.make << " " << c.model << " " << c.color << endl;
   return out;
}
istream& operator >> (istream& in, Car& c)
{
   cout << "Enter Id: ";
   in >> c.id;
   cout << "Enter Make: ";
   in >> c.make;
   cout << "Enter Model: ";
   in >> c.model;
   cout << "Enter color: ";
   in >> c.color;
   return in;
}
