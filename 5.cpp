#include <bits/stdc++.h>
#include <stdio.h>
#include <iostream>
#include <fstream> 
using namespace std;

typedef struct bus {
    int number; 
    string driver; 
    int route_nmb; 
} bus;

void bus_key(list<bus> &depot) {
    cout << "Enter number of buses you`d like to add: ";
    int num;
    cin >> num;
    bus b;
    for (int i=0; i<num; i++) {
        cout << "Enter unique bus number: ";
        cin >> b.number;
        cout << "Enter bus driver: ";
        getline(cin, b.driver);
        getline(cin, b.driver);
        cout << "Enter bus route number: ";
        cin >> b.route_nmb;
        depot.push_back(b);
    }
}

void bus_file(list<bus> &depot) {
    cout << "Please, be sure, that in file all info about buses is written in one line\n and different properties are divided by straight line ( like this: '|' )!"<< endl;
    cout << endl;
    cout << "Enter the exact address of file, where info is located: ";
    string path, line;
    cin >> path;
    ifstream file(path);
    bool ch1 = false;
    bool ch2 = false;
    int k1, k2 = 0;
    bus b;
    while(!file.eof())
    {
        getline(file, line);
        for (int i=0; i<line.size(); i++) {
            if (!ch2) {
                if (!ch1) {
                    if (line[i] == '|') {
                        k1 = i;
                        ch1 = true;
                        path = line.substr(0, i-1);
                        path.erase(remove(path.begin(),path.end(),' '),path.end());
                        b.number = stoi(path);
                        continue;
                    }
                } else {
                    if (line[i] == '|') {
                        k2 = i;
                        ch2 = true;
                        b.driver = line.substr(k1+1, i-k1-1);
                        continue;
                    }
                }
            } else {
                path = line.substr(k2+1);
                path.erase(remove(path.begin(),path.end(),' '),path.end());
                b.route_nmb = stoi(path);
                ch1 = false;
                ch2 = false;
                break;
            }
        }
        depot.push_back(b);
    }
}

void leave(list<bus> &depot, list<bus> &route) {
    list<bus>::iterator dep;
    if(depot.empty()) {
        cout << "There are no buses in the depot! First send some ..." << endl;
        return;
    }
    int num;
    cout << "Enter the number of bus going to route: ";
    cin >> num;
    bus b;
    for (dep = depot.begin(); dep != depot.end(); dep++) {
        if ((*dep).number == num) {
            b = *dep;
            depot.erase(dep);
            route.push_back(b);
            cout << "Bus number " << num << " went to route" <<endl;
            return;
        }
    }
    cout << "There is no bus number " << num << " in the depot" <<endl;
}

void returne(list<bus> &depot, list<bus> &route) {
    list<bus>::iterator rt;
    if(route.empty()) {
        cout << "There are no buses in the route! First send some ..." << endl;
        return;
    }
    int num;
    cout << "Enter the number of bus going to depot: ";
    cin >> num;
    bus b;
    for (rt = route.begin(); rt != route.end(); rt++) {
        if ((*rt).number == num) {
            b = *rt;
            route.erase(rt);
            depot.push_back(b);
            cout << "Bus number " << num << " went to depot" <<endl;
            return;
        }
    }
    cout << "There is no bus number " << num << " in the route" <<endl;
}

void info(list<bus> &depot, list<bus> &route) {
    list<bus>::iterator it;
    int t, k = 0;
    cout << "+---------------+--------------------------+------------+" << endl;
    cout << "|                         Depot                         |" << endl;
    cout << "+---------------+--------------------------+------------+" << endl;
    if (depot.empty()) {
        cout << "|            There are no buses in the depot            |" << endl;
        cout << "+---------------+--------------------------+------------+" << endl;
    } else {
        cout << "|   bus number  |          Driver          |    route   |" << endl;
        cout << "+---------------+--------------------------+------------+" << endl;
        for (it = depot.begin(); it != depot.end(); it++) {
            t = (*it).number;
            k = 0;
            while(t > 0) {
                t = t/10;
                k++;
            }
            cout << '|';
            for (int i=0; i<14-k; i++)
                cout << ' ';
            cout << (*it).number << " |";
            for (int i=0; i<25-(*it).driver.size(); i++)
                cout << ' ';
            cout << (*it).driver << " |";
            t = (*it).route_nmb;
            k = 0;
            while(t > 0) {
                t = t/10;
                k++;
            }
            for (int i=0; i<11-k; i++)
                cout << ' ';
            cout << (*it).route_nmb << " |" << endl;
            cout << "+---------------+--------------------------+------------+" << endl;
        }
    }
    cout << "|                         Route                         |" << endl;
    cout << "+---------------+--------------------------+------------+" << endl;
    if (route.empty()) {
        cout << "|            There are no buses in the route            |" << endl;
        cout << "+---------------+--------------------------+------------+" << endl;
    } else {
        cout << "|   bus number  |          Driver          |    route   |" << endl;
        cout << "+---------------+--------------------------+------------+" << endl;
        for (it = route.begin(); it != route.end(); it++) {
            t = (*it).number;
            k = 0;
            while(t > 0) {
                t = t/10;
                k++;
            }
            cout << '|';
            for (int i=0; i<14-k; i++)
                cout << ' ';
            cout << (*it).number << " |";
            for (int i=0; i<25-(*it).driver.size(); i++)
                cout << ' ';
            cout << (*it).driver << " |";
            t = (*it).route_nmb;
            k = 0;
            while(t > 0) {
                t = t/10;
                k++;
            }
            for (int i=0; i<11-k; i++)
                cout << ' ';
            cout << (*it).route_nmb << " |" << endl;
            cout << "+---------------+--------------------------+------------+" << endl;
        }
    }
}

void print_menu() {
    system("cls");
    cout << "+------------------------------------+" << endl;
    cout << "| Enter the number of action below:  |" << endl;
    cout << "|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|" << endl;
    cout << "| 1. Add bus info through keyboard   |" << endl;
    cout << "| 2. Add bus info from file          |" << endl;
    cout << "| 3. Leave the bus to route          |" << endl;
    cout << "| 4. Return the bus to depot         |" << endl;
    cout << "| 5. Route and depot info            |" << endl;
    cout << "| 6. Exit                            |" << endl;
    cout << "+------------------------------------+" << endl;
    cout << ">>";
}

int get_variant () {
    int var;
    cin >> var;
    while (var < 1 || var > 6) {
        cout << "Incorrect input. Try again:\n";
        cout << ">>";
        cin >> var;
    }
    return var;
}

int main() {
    int variant;
    list<bus> depot;
    list<bus> route;
    do {
        print_menu(); 
        variant = get_variant();
        switch (variant) {
            case 1:
                bus_key(depot);
                break;

            case 2:
                bus_file(depot);
                break;

            case 3:
                leave(depot, route);
                break;

            case 4:
                returne(depot, route);
                break;

            case 5:
                info(depot, route);
                break;
        }

        if (variant != 6)
            system("pause");

    } while (variant != 6);
    return 0;
}