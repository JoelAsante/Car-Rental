//Joel Asante
//K753A978
//CS400
//Homework 2 - main.cpp

//includes
#include"ArrayList.h"
#include<fstream>
using namespace std;


void menu();
int main()
{
   ifstream infile("carsdata.txt");
  
   if (!infile)// || !outfile)
   {
       cout << "ERROR!!! .... File not found....Existing" << endl;
       //pause
       system("pause");
       return 1;
   }
   //Create Array List of Car
  // ArrayList<Car> cars = new ArrayList<Car>();

   //add upto 15 cars
   int id;
   string make, model, color;
   ArrayList array;

   while (infile >> id >> make >> model >> color)
   {
      
       Car car(id, make, model, color);
       array.push_back(car);
        //array.add(car);
       //cars->add(car);
   }
  
  
   int menuChoice;
   do
   {
       menu();
      
       cin >> menuChoice;
       bool found = false;
    switch (menuChoice)
        {
       case 1:
           cout << "Please Enter Car ID: ";
           cin >> id;
          
           for (int i = 0; i < array.size(); i++)
           {
               if (id == array.get(i).getID())      //one gets the object and the other objects attribute
               {
                   found = true;
                   cout << "Found Car ID " << id << "\n";
                   //cout << array.get(i).getID();

                    cout<< "Other Info of this ID is: " << endl;
                
                    cout << "Make of Car: " <<array.get(i).getMake()<<endl;
                    cout << "Model of Car: " <<array.get(i).getModel()<<endl;
                    cout << "Color of Car: " <<array.get(i).getColor()<< "\n" <<endl;
                   break;
               }
              
           }

           if (!found)
           {
               cout << " Car ID Not found..." <<"\n"<< endl;
           }
           
           break;

       case 2:
           cout << "Please Enter Car Make: ";
           cin >> make;

           for (int i = 0; i < array.size(); i++)
           {
               if (make ==  array.get(i).getMake())
               {
                cout<< "\nCar Make Found: " << array.get(i).getMake() << "\n";
                cout<< "Other Info of this make is: " << endl;
                
                cout << "ID of Car: " <<array.get(i).getID()<<endl;
                cout << "Model of Car: " <<array.get(i).getModel()<<endl;
                cout << "Color of Car: " <<array.get(i).getColor()<< "\n" <<endl;
                found = true;
                break;
               }
              
           }
           if (!found)
           {
               cout << "Not found..." << "\n"<<endl;
           }
           break;

       case 3:
           cout << "Please Enter Car Model: ";
           cin >> model;

           for (int i = 0; i < array.size(); i++)
           {
               if (model == array.get(i).getModel())
               {
                cout <<"\nCar Model Found: " << array.get(i).getModel() << "\n";
                cout<< "Other Info of this Model is: " << endl;
                
                cout << "ID of Car: " <<array.get(i).getID()<<endl;
                cout << "Make of Car: " <<array.get(i).getMake()<<endl;
                cout << "Color of Car: " <<array.get(i).getColor()<< "\n" <<endl;
                found = true;
               }
              
           }
           if (!found)
           {
               cout << "Not found..." << "\n"<<endl;
           }
           break;

       case 4:
           cout << "Please Enter Car Color: ";
           cin >> color;

           for (int i = 0; i < array.size(); i++)
           {
               if (color == array.get(i).getColor())
               {
                    cout << "\nCar Color Found: " << array.get(i).getColor() << "\n";
                    cout<< "Other Info of this Color is: " << endl;
                    
                    cout << "ID of Car: " <<array.get(i).getID()<<endl;
                    cout << "Make of Car: " <<array.get(i).getMake()<<endl;
                    cout << "Model of Car: " <<array.get(i).getModel()<< "\n" <<endl;
                   found = true;
               }
              
           }
           if (!found)
           {
               cout << "Not found..." <<"\n"<< endl;
           }
           break;

       case 5:
           cout << "Enter Id: ";
           cin >> id;
           for (int i =0; i< array.size(); i++)
           {
               if (id == array.get(i).getID())
                   found = true;
           }
           if (found)
           {
               cout << "Duplicate Car ID Found ... Try again.." << "\n"<<endl;
               break;
           }
           else
           {
               ofstream outfile("carsdata.txt", ios::app);
               cout << "Enter Car Model: ";
               cin >> model;
               cout << "Enter Car Make: ";
               cin >> make;
               cout << "Enter Car Color: ";
               cin >> color;
               Car car(id, make, model, color);

               //add to arraylist
               array.push_back(car);

               //add to file
               outfile << car;
               outfile.close();
               cout << "\nCAR ADDED SUCCESSFULLY...." <<"\n"<< endl;
           }
           break;

       case 6:
           cout << "Enter Id: ";
           cin >> id;
           for (int i = 0; i < array.size(); i++)
           {
               if (id == array.get(i).getID())
               {
                   array.del(i);
                   cout << "Delete successfully..." << endl;
                   found = true;
               }
           }
           if (!found)
           {
               cout << "Car not found ...." << endl;
           }
           break;

       case 7:
           cout << "Cars Record: " << endl;
           for (int i = 0; i < array.size(); i++)
           {
               cout << array.get(i).getID() << endl;
               cout << array.get(i).getMake() << endl;
                cout << array.get(i).getModel() << endl;
                 cout << array.get(i).getColor() << endl;
           }

            break;
        case 8:
            cout << "Thanks for Using Application...\n" << endl;
            system("pause");
            break;
       default:
           cout << "WRONG CHOICE ...TRY AGAIN!!\n\n";
           break;
        }
      
   }while (menuChoice != 8);
}
//Function definitions
void menu()
{
    cout << "WELCOME TO THE CARS.COM";
    cout << "\n(1) Search by Car Id\n(2) Search by Car Make\n(3) Search by Car Model\n(4) Search by Car Color\n(5) Add New Car\n(6) Delete an Existing Car\n(7) List All Cars\n(8) Exit the Program.\n\nPlease Enter your choice: ";
} 