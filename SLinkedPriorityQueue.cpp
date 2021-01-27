
#include "SLinkedPriorityQueue.h"
#include "ListNode.h"
#include "strlib.h"
#include "simpio.h"
#include <iostream>

using namespace std;

SLinkedPriorityQueue::SLinkedPriorityQueue() {
    front=NULL;
}

void SLinkedPriorityQueue::deallocate(ListNode *node){
    if(node!=NULL){
        deallocate(node->next);                             //using recursion
        delete node;
    }
}

SLinkedPriorityQueue::~SLinkedPriorityQueue() {
    deallocate(front);
}

void SLinkedPriorityQueue::changePriority(string value, int newPriority) {
    ListNode *cur=front;
    ListNode *prev=NULL;
    ListNode *next=NULL;
    if(cur==NULL){
        throw"empty priority queue";
    }else{
        while(true){
            if(cur->value==value){
                next=cur->next;
                break;
            }
            prev=cur;
            cur=cur->next;
        }
    }
    if(prev==NULL && next==NULL){         //if only 1 node
        cur->priority=newPriority;
    }else if(prev==NULL){
        front=front->next;               //when 1st node's priority is to be updated
        enqueue(cur->value,newPriority);
    }else if(next==NULL){
        prev->next=NULL;                //when last node's priority is to be updated
        enqueue(cur->value,newPriority);
    }else{//if (prex!=NULL && next!=NULL)
        prev->next=next;
        enqueue(cur->value,newPriority); //when middle node's priority is to be updated
    }
}

void SLinkedPriorityQueue::clear() {
    deallocate(front);
    front=NULL;
}

string SLinkedPriorityQueue::dequeue() {
    if(front==NULL){
        throw "attempting to dequeue an empty PQ";
    }else{
        ListNode *n=front;
        front=front->next;
        string s=n->value;
        delete n;
        return s;
    }
}

void SLinkedPriorityQueue::enqueue(string value, int priority) {
    if(isEmpty()){
        front=new ListNode(value,priority);
    }else{
        ListNode *newNode=new ListNode(value,priority);

        if((*front)>(*newNode)){
            newNode->next=front;               //add at front
            front=newNode;
        }else{
            ListNode *current=front;
            while(current->next!=NULL && ((*(current->next)))<(*newNode)){
                current=current->next;
            }
            newNode->next=current->next;     //LAST
            current->next=newNode;

        }
    }

}

bool SLinkedPriorityQueue::isEmpty() const {
    return front==NULL;
}

string SLinkedPriorityQueue::peek() const {
    if(!isEmpty()){
        string s=front->value;
        return s;
    }else{
        throw "empty PQ";
    }
}

int SLinkedPriorityQueue::peekPriority() const {
    if(!isEmpty()){
        int n=front->priority;
        return n;
    }else{
        return 0;
    }
}

int SLinkedPriorityQueue::size() const {
    int count = 0;
    ListNode* current = front;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}
string SLinkedPriorityQueue::toString() const {
    if(isEmpty()){
        return "{}";
    }else{
        string s;
        s+="{";
        ListNode* f=front;
        while(f->next!=NULL){
            s+=f->value+" : "+(integerToString(f->priority));
            f=f->next;
            s+=" ,";
        }

        s+=f->value+ " : " +integerToString(f->priority) +"}";
        return s;
    }
}

ostream& operator<<(ostream& out, const SLinkedPriorityQueue& queue){
    string s=queue.toString();
    return out<<s;
}
