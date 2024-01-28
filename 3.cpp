#include <bits/stdc++.h>
#include <iostream>
#include <istream>
#include <ostream>

class AEROFLOT {
    std::string m_destination; 
    int m_id;
    std::string m_type;    
public: 
    AEROFLOT()
    : m_destination("")
    , m_id(0)
    , m_type("") {
    }
    AEROFLOT(std::string destination, int id, std::string type)
    : m_destination(destination)
    , m_id(id)
    , m_type(type) {
    }
    ~AEROFLOT() {}
    AEROFLOT(const AEROFLOT &A1)
    : m_destination(A1.destination())
    , m_id(A1.id())
    , m_type(A1.type()) {
    }
    AEROFLOT& operator= (const AEROFLOT &A1) {
        m_destination = A1.destination();
        m_id = A1.id();
        m_type = A1.type();
        return *this;
    }

    std::string destination() const {
        return m_destination;
    }

    int id() const {
        return m_id;
    }

    std::string type() const {
        return m_type;
    }

    void set_destination(std::string destination) {
        m_destination = destination;
    }

    void set_id(int id) {
        m_id = id;
    }

    void set_type(std::string type) {
        m_type = type;
    }

    friend std::ostream& operator<<(std::ostream& os, const AEROFLOT& A);
    friend std::istream& operator>>(std::istream& is, AEROFLOT& A);
};

std::ostream& operator<<(std::ostream& out, const AEROFLOT& A) {
    out << A.destination() <<  " " << A.id() << " " << A.type();
    return out;
}

std::istream& operator>>(std::istream& is, AEROFLOT& A) {
	std::string destination, type;
	int id;
    is >> destination >> id >> type;
    A = AEROFLOT(destination, id, type);
    return is;
}

int main() { 
    AEROFLOT A[7];
    AEROFLOT T;
    std::cout << "Enter data: " << std::endl;
    for (int i=0; i<7; i++)
        std::cin >> A[i];
    for (int i=0; i<7; i++) {
        for (int j=i; j<7; j++) {
            if (A[j].id() < A[i].id()) {
                T = A[i];
                A[i] = A[j];
                A[j] = T;
            }
        }
    }
    int ch, p = 0;
    std::string s;
    std::cout << "If you`d like to quit - enter symbol '#' " << std::endl;
    std::cout << "Enter estimated destination:" << std::endl;
    getline(std::cin, s);
    getline(std::cin, s);
    if (s == "#") {
        ch = 1;
    } else {
        for (int i=0; i<7; i++) {
            if (A[i].destination() == s) {
                p = 1;
                std::cout << A[i].id() << " " << A[i].type() << std::endl;
            }
        }
        if (p == 0)
            std::cout << "There are no flight to entered destination!" << std::endl;
    }
    while (ch!=1) {
        p = 0;
        std::cout << "If you`d like to quit - enter symbol '#' " << std::endl;
        std::cout << "Enter estimated destination:" << std::endl;
        getline(std::cin, s);
        if (s == "#") {
            ch = 1;
        } else {
            for (int i=0; i<7; i++) {
                if (A[i].destination() == s) {
                    p = 1;
                    std::cout << A[i].id() << " " << A[i].type() << std::endl;
                }
            }
            if (p == 0)
                std::cout << "There are no flight to entered destination!" << std::endl;
        }
            
    }
}