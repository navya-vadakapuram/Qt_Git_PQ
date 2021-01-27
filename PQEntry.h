
#ifndef _pqentry_h
#define _pqentry_h

#include <string>
#include <iostream>
using namespace std;

struct PQEntry {
public:
    string value;
    int priority;

    PQEntry(string value = "", int priority = 0);
};

bool operator <(const PQEntry& pqe1, const PQEntry& pqe2);
bool operator <=(const PQEntry& pqe1, const PQEntry& pqe2);
bool operator ==(const PQEntry& pqe1, const PQEntry& pqe2);
bool operator !=(const PQEntry& pqe1, const PQEntry& pqe2);
bool operator >(const PQEntry& pqe1, const PQEntry& pqe2);
bool operator >=(const PQEntry& pqe1, const PQEntry& pqe2);
ostream& operator <<(ostream& out, const PQEntry& pqe);

#endif
