//Joel Asante

#include<iostream>
#include<string>
using namespace std;

class Car
{
    private:
        int id;
        string make;
        string model;
        string color;
        
    public:
        //default Constructor
        Car();
        //Overload Constructor
        Car(int id, string make, string model, string color);

        //getters
        int getID();
        string getModel();
        string getMake();
        string getColor();

        //setters
        void setID(int id);
        void setModel(string model);
        void setMake(string make);
        void setColor(string color);

        //overload operator for input and outpur
        friend ostream& operator << (ostream& out, const Car& c);
        friend istream& operator >> (istream& in, Car& c);

};
