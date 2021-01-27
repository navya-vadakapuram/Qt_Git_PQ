
#ifndef _listnode_h
#define _listnode_h

#include <iostream>
#include <string>
#include "PQEntry.h"
using namespace std;

struct ListNode {
    public:
        string value;
        int priority;
        ListNode* next;

        ListNode(string value = "", int priority = 0, ListNode* next = NULL);
        /*friend bool operator <(const ListNode& node1, const ListNode& node2);
        friend bool operator <=(const ListNode& node1, const ListNode& node2);
        friend bool operator ==(const ListNode& node1, const ListNode& node2);
        friend bool operator !=(const ListNode& node1, const ListNode& node2);
        friend bool operator >(const ListNode node1, const ListNode node2);
        friend bool operator >=(const ListNode& node1, const ListNode& node2);*/


};
bool operator <(const ListNode& node1, const ListNode& node2);
bool operator <=(const ListNode& node1, const ListNode& node2);
bool operator ==(const ListNode& node1, const ListNode& node2);
bool operator !=(const ListNode& node1, const ListNode& node2);
bool operator >(const ListNode& node1, const ListNode& node2);
bool operator >=(const ListNode& node1, const ListNode& node2);
ostream& operator <<(ostream& out, const ListNode& node);

#endif
