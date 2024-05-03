#include "planet.h"

using namespace std;

namespace planet {
    bool Planet::operator> (const Planet& other) const {
        return diameter > other.diameter;
    }

    bool Planet::operator< (const Planet& other) const {
        return diameter < other.diameter;
    }

    bool Planet::operator== (const Planet& other) const {
        return diameter == other.diameter;
    }

    Planet& Planet::operator= (const Planet& other) {
        if (&other != this) {
            name = other.name;
            diameter = other.diameter;
            haveLife = other.haveLife;
            satellites = other.satellites;
        }
        return *this;
    }

    ostream& operator<< (ostream& out, const Planet& planet) {
        out << planet.name << " " << planet.diameter << " " << planet.haveLife << " " << planet.satellites;
        return out;
    }

    istream& operator>> (istream& in, Planet& planet) {
        in >> planet.name;
        in >> planet.diameter;
        in >> planet.haveLife;
        in >> planet.satellites;
        return in;
    }
}