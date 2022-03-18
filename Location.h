#ifndef LOCATION_H
#define LOCATION_H

#include <iostream>
#include <string>
#include <sstream>
using namespace std;


class Location{
    public:
        Location(char code, int num);  //-> id: code+num

        //getters
        string getID();
        string getProduct();
        int getQuantity();

        //setters
        void setID();
        void setProduct();
        void setQuantity();

        bool isEmpty();
        bool isAvailable();
        void print();

        //Virtual member functions
        virtual int getCapacity() = 0;   //pure virtual function
        virtual bool add(string product, int quantity) = 0;
        virtual bool remove(int quantity) = 0;


    protected:
        string id;       //the label of this location
        string product;  //the name of the product stored at this location
        int quantity;   //the quantity of product stored at this location
        static const string NONE;   //class variable


};





#endif