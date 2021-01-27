
#include "PQEntry.h"

PQEntry::PQEntry(string value, int priority) {
    this->value = value;
    this->priority = priority;
}

bool operator <(const PQEntry& pqe1, const PQEntry& pqe2) {
    return pqe1.priority < pqe2.priority ||
            (pqe1.priority == pqe2.priority && pqe1.value < pqe2.value);
}

bool operator ==(const PQEntry& pqe1, const PQEntry& pqe2) {
    return pqe1.priority == pqe2.priority && pqe1.value == pqe2.value;
}

bool operator !=(const PQEntry& pqe1, const PQEntry& pqe2) {
    return !(pqe1 == pqe2);
}

bool operator <=(const PQEntry& pqe1, const PQEntry& pqe2) {
    return pqe1 < pqe2 || pqe1 == pqe2;
}

bool operator >(const PQEntry& pqe1, const PQEntry& pqe2) {
    return !(pqe1 <= pqe2);
}

bool operator >=(const PQEntry& pqe1, const PQEntry& pqe2) {
    return !(pqe1 < pqe2);
}

ostream& operator <<(ostream& out, const PQEntry& pqe) {
    out << "\"" << pqe.value << "\":" << pqe.priority;
    return out;
}
