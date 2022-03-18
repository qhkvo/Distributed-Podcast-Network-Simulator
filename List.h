#ifndef LIST_H
#define LIST_H

#include "Product.h"

class List{
    public:
        List();
        ~List();

      
        void add(Product* prod);
        void get(const string& name, Product** prod) const;
        void remove(const string& name, Product** goner);
        void print() const;  

        bool isEmpty();
        void findProduct(const string& name, Product** prod);


    protected:
        class Node {
            public:
                Product* data;
                Node*    next;
        };

        Node* head;
        

};


#endif

