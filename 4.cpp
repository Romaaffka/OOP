#include <bits/stdc++.h>
#include <iostream>
#include <fstream> 
using namespace std;

bool ch_vow (char a) {
    char vow[12] = {'A', 'E', 'I', 'O', 'U', 'Y', 'a', 'e', 'i', 'o', 'u', 'y'};
    bool chk = false;
    for (int i=0; i<12; i++) {
        if (a == vow[i])
            chk = true;
    }
    return chk;
}

bool ch_sign (char a) {
    char sign[6] = {'.', ',', '?', '!', ';', ':'};
    bool chk = false;
    for (int i=0; i<6; i++) {
        if (a == sign[i])
            chk = true;
    }
    return chk;
}

bool check (char a) {
    bool chk = false;
    int n = (int) a;
    if ((n >= 65 && n <= 90) || (n >= 97 && n <= 122))
        chk = true;
    return chk;
}

int main() {
    ifstream in("C:/text.txt"); //Здесь нужно прописать путь к файлу с текстом
    char c;
    string wrd = "";
    bool ch1, ch2, wd = false;
    while(!in.eof()) {
        in.get(c);
        if (ch1 == false) {
            if (ch_vow(c)) {
                if (wd) {
                    ch1 = true;
                    wrd += c;
                    continue;
                }
            } else 
                wd = false;
        } else {
            if (check(c)) {
                if (ch2) {
                    wd = false;
                    continue;
                }
                wrd += c;
                continue;
            } else {
                if (ch_sign(c)) {
                    ch2 = true;
                    continue;
                } else {
                    if (c == ' ' || c == 9 || c == '\n') {
                        if (wd) {
                            cout << wrd << ' ';
                            ch2 = false;
                            ch1 = false;
                            wrd = "";
                            continue; 
                        }
                        wd = true;
                        continue;
                    }
                    wd = false;
                    continue; 
                }
            }
        }
        if (c == ' ' || c == 9 || c == '\n') 
            wd = true;
    }
    in.close();
}