#ifndef STORE_H
#define STORE_H

#include <iostream>
#include <string>
#include <iomanip>

#include "Product.h"
#include "List.h"
#include "WHLocation.h"
#include "StoreLocation.h"
#include "defs.h"


using namespace std;

class Store {
		
	public:
		//constructor
		Store(const string& name);
		
		//destructor
		~Store();

		//other
		void findAvailableSLoc(StoreLocation** sloc);
		void findAvailableWHLoc(WHLocation** wloc);

		void printStoreStock();
		void printWareHouseStock();
		void printProducts();

		//these are done for you
		void findProduct(const string& name, Product** prod); 
		void receiveProduct(const string& pname, int quantity);
		void fillOrder(const string& product, int &quantity);
		void print();
	
	private:
		string name;
		StoreLocation slocs[SLOCS];
		WHLocation whlocs[WHLOCS];
		List* products;
};
#endif