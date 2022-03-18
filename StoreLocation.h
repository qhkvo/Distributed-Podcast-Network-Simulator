#ifndef STORELOCATION_H
#define STORELOCATION_H

#include <iostream>
#include <string>
#include "defs.h"
#include "Location.h"

using namespace std;

//public Location to be base class
class StoreLocation:public Location{
    
    public:
        StoreLocation();
        void setProduct(string productName);
        int getFreeSpace();  
        

        //virtual functions
        virtual int getCapacity();
        virtual bool add(string addProduct, int amount);
        virtual bool remove(int amount);

    private:
        //class variables
        static const char code;
        static const int capacity;
        //produce the next id number that is passed into the Location constructor
        static int nextId; 

};

#endif