#include <iostream>
#include <string>
#include <iomanip>
#include "Queue.h"

using namespace std;

Queue::Queue(): head(NULL), tail(NULL){}

Queue::~Queue(){
    Node* currNode = head;
    Node* nextNode; 

    //1 2 3 4
    while(currNode!=NULL){
        nextNode = currNode->next;  //save 2
        delete currNode;        //delete 1
        currNode = nextNode;    //set 2 to head
    }
    

}

bool Queue::isEmpty(){
    if(head == NULL){return true;}
    return false;
}

void Queue::peekFirst(WHLocation** loc){
    //see the first element in the queue
    if(this->isEmpty()){
        *loc=NULL;
    }else{
        *loc=head->data;
    }

}
void Queue::popFirst(WHLocation** loc){
    //see and take out the first element in the queue -> delete head Node if exist

    if(this->isEmpty()){
        *loc=NULL;
    }else{
        *loc=head->data;

        Node* deleteNode = head;
        head = head->next; 
        delete deleteNode;
    }
}
void Queue::addLast(WHLocation* loc){
    //Add loc to the end of the Queue
    Node* newNode = new Node();
    newNode->data = loc;
    newNode->next = NULL; //last node -> points to NULL

    if(this->isEmpty()){
        //then only newNode in Queue -> is both head and tail
        head = newNode;
        tail = newNode;
    }else{
        tail->next = newNode;  //link the newNode to the Queue
        tail = newNode;        //set the newNode to tail
    }
}

void Queue::print(){}