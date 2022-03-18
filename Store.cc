#include "Store.h"

Store::Store(const string& name){
    this->name = name;

    products = new List; //initialize the products
}

Store::~Store(){
    //for list pointer
    delete products;
}


void Store::findAvailableSLoc(StoreLocation** sloc){
    for(int i=0; i<SLOCS; i++){
        if(slocs[i].isAvailable()){
            *sloc = &slocs[i];
            return;
        }
    }
    *sloc=NULL;
}


void Store::findAvailableWHLoc(WHLocation** wloc){
    for(int i=0; i<WHLOCS; i++){
        if(whlocs[i].isAvailable()){
            *wloc = &whlocs[i];
            return;
        }
    }
    *wloc=NULL;
}

void Store::receiveProduct(const string& pname, int quantity){
    Product* prod = NULL;
    cout<<"Receiving..."<<endl;
    products->findProduct(pname, &prod);
    if (prod==NULL){
        cout<<"Making new product"<<endl;
        StoreLocation* sloc;
        findAvailableSLoc(&sloc);
        prod = new Product(pname, sloc);
        products->add(prod);

    }

    WHLocation* bloc;
    while(quantity > 0){
        findAvailableWHLoc(&bloc);
        if (quantity > bloc->getCapacity()){
            bloc->add(pname, bloc->getCapacity());
            prod->addWHLocation(bloc);
            quantity -= bloc->getCapacity();
        }else{
            bloc->add(pname, quantity);
            prod->addWHLocation(bloc);
            quantity = 0;
        }
    }

    cout<<"stocking store location..."<<endl;
    prod->stockStoreLocation();

}

void Store::fillOrder(const string& product, int& quantity){
    Product* prod;
    findProduct(product, &prod);
    if (prod == NULL){
        return;
    }
    prod->fillOrder(quantity);
}

void Store::findProduct(const string& name, Product** prod){
    products->findProduct(name, prod);
}

void Store::print(){
    cout<<"Store: "<<name<<endl;
}

void Store::printStoreStock(){
    cout<<"Store Locations: "<<endl;
    for(int i=0; i<SLOCS; i++){
      if(!slocs[i].isAvailable()){
        //cout<< slocs[i].getID() <<endl; //called StoreLocation->Location
        slocs[i].print();
      }

    }
}

//print all WHLoc that are not empty

void Store::printWareHouseStock(){
    cout<<"Warehouse Locations: "<<endl;
    for(int i=0; i<WHLOCS; i++){
        if(!whlocs[i].isAvailable()){
            whlocs[i].print();
        }
    }
}


void Store::printProducts(){
    cout<<"Products: "<<endl;
    products->print();
}
