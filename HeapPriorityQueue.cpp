
#include "HeapPriorityQueue.h"
#include "strlib.h"

static const int INITIAL_CAPACITY = 10;

HeapPriorityQueue::HeapPriorityQueue() {
    myCapacity = INITIAL_CAPACITY;
    mySize = 1;
    myElements = new PQEntry[myCapacity];

}

HeapPriorityQueue::~HeapPriorityQueue() {
    delete [] myElements;

}

void HeapPriorityQueue::changePriority(string value, int newPriority) {
    for (int i=1;i<=mySize;i++) {
        if(myElements[i].value==value){
            PQEntry entry= myElements[i];
            for(int j=i;j<mySize-1;j++){
                myElements[j]=myElements[j+1];
            }
            mySize--;
            enqueue(entry.value,newPriority);
            break;
        }
    }

}

void HeapPriorityQueue::clear() {
    delete [] myElements;
    myElements=new PQEntry[10];
    mySize=0;

}
void HeapPriorityQueue:: checkChildren(int i){
    if(myElements[i]>myElements[2*i]){

        swap(i,2*i);
    }
    if(myElements[i]>myElements[2*i+1]){

        swap(i,2*i+1);
    }
}

string HeapPriorityQueue::dequeue() {
    if(mySize==1){
        return "";
    }
    string s=myElements[1].value;
    PQEntry* newA= new PQEntry[myCapacity];
    newA[1]=myElements[mySize-1];
    for (int i = 2; i <=mySize-1; i++) {                     //
        newA[i] = myElements[i];
    }
    delete []myElements;
    myElements=newA;

    mySize--;

    int i=1,j=1;
    if(mySize>1){
        checkChildren(i);
        while(!((2*i)>mySize)){
            checkChildren(2*i);
            i=2*i;
        }
        while(!((2*j+1)>mySize)){
            checkChildren(2*j+1);
            j=2*j+1;
        }

    }

    return s;
}

void HeapPriorityQueue::enqueue(string value, int priority) {
    checkResize();


    PQEntry *pq=new PQEntry(value,priority);
    myElements[mySize]=*pq;
    int i=mySize;

    while(!isEmpty()){
        if((myElements[i/2])>(myElements[i])){
            swap(i/2,i);

            i=i/2;
        }else{
            break;
        }
    }
    mySize++;


}

bool HeapPriorityQueue::isEmpty() const {
    return mySize==1;
}

string HeapPriorityQueue::peek() const {
    if(isEmpty()){
        return "";
    }else{
        return myElements[1].value;
    }
}

int HeapPriorityQueue::peekPriority() const {
    if(isEmpty()){
        throw "empty queue";
    }else{
        return myElements[1].priority;
    }

}

int HeapPriorityQueue::size() const {

    return mySize;
}

void HeapPriorityQueue:: swap(int i,int j){


    if(i!=j && (i<=mySize && j<=mySize)){

        PQEntry temp=myElements[i];
        myElements[i]=myElements[j];
        myElements[j]=temp;


    }




}
void HeapPriorityQueue::checkResize() {
    if (mySize == myCapacity) {
        // copy all elements into a bigger array
        PQEntry* bigger=new PQEntry[2 * myCapacity];
        for (int i = 1; i < mySize; i++) {
            bigger[i] = myElements[i];
        }

        // swap in the new bigger array for the old one
        delete[] myElements;
        myElements = bigger;
        myCapacity *= 2;
    }
}
string HeapPriorityQueue::toString() const {
        string s;
        s+="{";
        for (int i=1;i<mySize;i++) {
            s+=myElements[i].value+" : "+(integerToString(myElements[i].priority));
            if(i!=mySize-1){
                s+=" ,";
            }
        }
        s+="}";
        return s;
}

ostream& operator<<(ostream& out, const HeapPriorityQueue& queue) {
    string s=queue.toString();
    return out<<s;
}
