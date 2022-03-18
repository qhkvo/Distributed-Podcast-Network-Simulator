#ifndef QUEUE_H
#define QUEUE_H

#include "WHLocation.h"

class Queue{

    //private nested class
    class Node{
        public:
            WHLocation* data;
            Node*    next;
        
    };

    public:
        Queue();
        ~Queue();

        bool isEmpty();
        void peekFirst(WHLocation** loc);
        void popFirst(WHLocation** loc);
        void addLast(WHLocation* loc);
        void print();


    private:
        Node* head;
        Node* tail;
        

    
};

#endif