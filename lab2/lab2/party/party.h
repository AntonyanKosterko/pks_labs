#ifndef PARTY_H
#define PARTY_H

#include <iostream>

namespace party {
    class Party {
    public:
        std::string title;
        std::string leader;
        int participants;
        bool governance;

        bool operator> (const Party& other) const;
        bool operator< (const Party& other) const;
        bool operator== (const Party& other) const;

        Party& operator=(const Party& other);
    };

    std::ostream& operator<< (std::ostream& out, const Party& party);
    std::istream& operator>> (std::istream& in, Party& party);
}

#endif // BUS_H

