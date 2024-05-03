#include "party.h"

using namespace std;

namespace party {
    bool Party::operator> (const Party& other) const {
        return participants > other.participants;
    }

    bool Party::operator< (const Party& other) const {
        return participants < other.participants;
    }

    bool Party::operator== (const Party& other) const {
        return participants == other.participants;
    }

    Party& Party::operator= (const Party& other) {
        if (&other != this) {
            title = other.title;
            participants = other.participants;
            governance = other.governance;
            leader = other.leader;
        }
        return *this;
    }

    ostream& operator<< (ostream& out, const Party& party) {
        out << party.title << " " << party.leader << " " << party.participants << " " << party.governance;
        return out;
    }

    istream& operator>> (istream& in, Party& party) {
        in >> party.title;
        in >> party.leader;
        in >> party.participants;
        in >> party.governance;
        return in;
    }
}