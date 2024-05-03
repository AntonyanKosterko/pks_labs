#ifndef PLANET_H
#define PLANET_H

#include <bits/stdc++.h>

namespace planet {
    class Planet {
    public:
        char* name;
        int diameter;
        bool haveLife;
        int satellites;

        bool operator>(const Planet& other) const;
        bool operator<(const Planet& other) const;
        bool operator==(const Planet& other) const;
        Planet& operator=(const Planet& other);
    };

    std::ostream& operator<<(std::ostream& out, const Planet& planet);
    std::istream& operator>>(std::istream& in, Planet& planet);
}

#endif // PLANET_H

