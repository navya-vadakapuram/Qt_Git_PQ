
#include "USLinkedPriorityQueue.h"
#include "strlib.h"

USLinkedPriorityQueue::USLinkedPriorityQueue() {
    front=NULL;

}

USLinkedPriorityQueue::~USLinkedPriorityQueue() {
    deallocate(front);

}
void USLinkedPriorityQueue::deallocate(ListNode *node){
    if(node!=NULL){
        deallocate(node->next);                             //using recursion
        delete node;
    }
}



void USLinkedPriorityQueue::changePriority(string value, int newPriority) {
    ListNode *n=front;
    while(n->value!=value){
        n=n->next;
    }
    n->priority=newPriority;

}

void USLinkedPriorityQueue::clear() {
    deallocate(front);
    front=NULL;

}

string USLinkedPriorityQueue::dequeue() {
    string s;
    ListNode* rqdNode=front;
    ListNode* prev=front;
    ListNode* c=front;
    ListNode* current=front->next;
    if(front==NULL){
        throw "cant deque an empty pq";
    }else if(front->next==NULL){
        s=front->value;
    }else{
        while(true){
            if(current->next==NULL){
                if((*current)<(*rqdNode)){
                    prev=c;
                    rqdNode=current;
                    break;
                }
                break;
            }
            if((*current)<(*rqdNode)){
                prev=c;
                rqdNode=current;
            }
            c=current;
            current=current->next;
        }
    }
    if(rqdNode->next==NULL){
        ListNode *temp;
        if((*prev)!=(*rqdNode)){
            s=rqdNode->value;
            temp=prev->next;
            prev->next=NULL;
        }else{
            temp=front;
            front=NULL;
        }
        delete temp;
    }else{
        if((*rqdNode)==(*prev)){
            front=rqdNode->next;
        }else{
            s=rqdNode->value;
            prev->next=rqdNode->next;
        }
        delete rqdNode;
    }
    return s;
}


void USLinkedPriorityQueue::enqueue(string value, int priority) {
    ListNode *newN=new ListNode(value,priority);
    newN->next=front;
    front=newN;

}

bool USLinkedPriorityQueue::isEmpty() const {
    return front==NULL;
}

string USLinkedPriorityQueue::peek() const {
    if(isEmpty()){
        return "";
    }else{
        return front->value;
    }
}

int USLinkedPriorityQueue::peekPriority() const {
    if(isEmpty()){
        return 0;

    }else{
        int rqd=front->priority;
        ListNode *current=front;
        while(true){
            if(current->next==NULL){
                if(current->priority<rqd){
                    rqd=current->priority;
                }
                break;
            }
            if(current->priority<rqd){
                rqd=current->priority;
            }

            current=current->next;
        }
        return rqd;
    }
}

int USLinkedPriorityQueue::size() const {
    int count=0;
    ListNode* f=front;
    while(f!=NULL){
        count++;
        f=f->next;
    }
    return count;
}


string USLinkedPriorityQueue::toString() const {
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


ostream& operator<<(ostream& out, const USLinkedPriorityQueue& queue) {
    string s=queue.toString();
    return out<<s;
}
