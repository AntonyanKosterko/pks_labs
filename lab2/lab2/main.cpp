#include <bits/stdc++.h>
#include "planet/planet.h"
#include "party/party.h"

using namespace std;

vector<party::Party> parties;

void read_parties(){
    ifstream in("input.txt");
    party::Party p;
    if (in.is_open()){
        while (in >> p){
            parties.push_back(p);
        }
    }
    in.close();    
}

void write_parties(){
    ofstream out("output.txt");
    for(auto p : parties){
        out << p << '\n';
    }
    out.close();  
}

void sort_parties(){
    sort(parties.begin(), parties.end());
}

void add_party(){
    cout << "Enter title, leader, amount participants, governance\n";
    party::Party p;
    cin >> p.title >> p.leader >> p.participants >> p.governance;
    parties.push_back(p);
}

void erase_party(){
    cout << "enter number 0 - " << parties.size() - 1 << '\n';
    int number;
    cin >> number;
    parties.erase(parties.begin() + number);
}

void print_parties(){
    for(auto p : parties){
        cout << p << '\n';
    }
}

void interactive(){
    
    string message = "0 - reading from database\n1 - write into database\n2 - sorting database\n3 - add new file in database\n4 - delete from database\n 5 - write all database\n";
    int n;
    
    while(true){
        cout << message;
        cin >> n;
        switch (n){
        case 0:
            read_parties();
            break;
        case 1:
            write_parties();
            break;
        case 2:
            sort_parties();
            break;
        case 3:
            add_party();
            break;
        case 4:
            erase_party();
            break;
        case 5:
            print_parties();
            break;
        default:
            cout << message;
        }
    }
}

void demo(){
    vector<planet::Planet> f;
    ifstream in("planets_input.txt");
    planet::Planet p;
    if (in.is_open()){
        while (in >> p){
            f.push_back(p);
        }
    }
    in.close();
    p.name = "earth";
    p.diameter = 100000;
    p.haveLife = 0;
    p.satellites = 2;
    f.push_back(p);
    bool st = f[0] < f[1];
    cout << st << '\n';
    //f.erase(f.begin() + 4);
    sort(f.begin(), f.end());
    ofstream out("planets_output.txt");
    for(int i = 0; i < f.size(); ++i){
        cout << f[i] << '\n';
        out << f[i] << '\n';
    }
    out.close();  
}

int main() {
    setlocale(LC_ALL, "Russian");
    int status;
    string message = "0 - Planet\n1 - Party\n";
    cout << message;
    while(true){
        cin >> status;
        switch (status){
            case 0:
                demo();
                break;
            case 1:
                interactive();
                break;
            default:
                cout << message;
        }
    }
    return 0;
}