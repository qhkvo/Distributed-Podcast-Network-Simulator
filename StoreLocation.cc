#include "StoreLocation.h"

const int StoreLocation::capacity = SLOC_CAPACITY ;
const char StoreLocation::code = 'A';
int StoreLocation::nextId = 0;

StoreLocation::StoreLocation():Location(code, ++nextId){}


void StoreLocation::setProduct(string productName){
    product = productName;
}


int StoreLocation::getFreeSpace(){
    return (capacity - quantity);
}


int StoreLocation::getCapacity() {return capacity;}

//Return false if the location has a different product, or if it cannot fit all the product.
bool StoreLocation::add(string addProduct, int amount) {


    //if product empty, set this location to new product, add amount
    if(this->isAvailable() && amount <= capacity){
        product= addProduct;
        quantity = amount;
        return true;
    }

    //if not empty, compare the name, if the same->add
    if(this->product == addProduct && amount + quantity <= capacity){
        quantity = amount + quantity;
        return true;
    }

    return false;

}
bool StoreLocation::remove(int amount){

    if(amount <= quantity){
        quantity= quantity - amount;
        return true;
    }
    return false;
}
