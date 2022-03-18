#include "Location.h"


const string Location::NONE = "Empty";

Location::Location(char code, int num){
    this->quantity = 0;
    this->product = NONE;

    //chang all to str
    stringstream ss;
    ss << code << num;
    this->id = ss.str();
}

bool Location::isEmpty(){
    if(quantity==0){return true;}
    return false;
}

bool Location::isAvailable(){
    if(product == NONE){return true;}
    return false;
}

string Location::getID(){return id;}
string Location::getProduct(){return product;}
int Location::getQuantity(){return quantity;}

void Location::print(){
    cout<<"Location: " <<id<<endl;
    cout<<"Product: "<<product<<endl;
    cout<<"Quantity: "<<quantity<<endl<<endl;
}
