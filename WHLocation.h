#ifndef WHLOCATION_H
#define WHLOCATION_H

#include <iostream>
#include <string>
#include "Location.h"
#include "defs.h"
using namespace std;

class WHLocation:public Location{
    public:
        WHLocation();

        //virtual functions
        virtual int getCapacity();
        virtual bool add(string addProduct, int amount);
        virtual bool remove(int amount);

    private:
        //class variables
        static const char code;
        static const int capacity;
        static int nextId;


};



#endif