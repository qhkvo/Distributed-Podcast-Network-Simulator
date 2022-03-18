#include "WHLocation.h"

//declare class variables
const int WHLocation::capacity = WHLOC_CAPACITY ;
const char WHLocation::code = 'B';
int WHLocation::nextId = 0;

WHLocation::WHLocation():Location(code, ++nextId){};

//virtual functions
int WHLocation::getCapacity(){return capacity;}
bool WHLocation::add(string addProduct, int amount){
    if(this->isAvailable() && amount <= capacity){
        product = addProduct;
        quantity = amount;
        return true;
    }
    return false;
}


bool WHLocation::remove(int amount){
    if(amount <= quantity){
        quantity= quantity - amount;
        if(quantity == 0){
        product = NONE;
        }
        return true;
    }

    return false;

}