#include <iostream>
using namespace std;
class Square {
    string str;
    string gor;
    string ul;
public:
    void Vvod();
    void Strana();
    void Gorod();
    void Ulica();
    void Vivod();
};
//создание
void Square::Vvod() {
    cout << endl << "Введите адрес организации: " << endl;
    cout << "Страна: "; cin >> str;
    cout << "Город: "; cin >> gor;
    cout << "Улица: "; cin >> ul;
    cout << endl;
}
//вывод
void Square::Vivod() {
    cout << endl << "Полный адрес: ";
    cout << "\nСтрана: " << str << "\nГород: " << gor << "\nУлица: " << ul;
    cout << endl << endl;
}
//изминение страны
void Square::Strana()
{
    cout << "Введите страну ";
    cout << endl;
    cout << "Страна: "; cin >> str;
}
//изменение города
void Square::Gorod()
{
    cout << "Введите город ";
    cout << endl;
    cout << "Город: "; cin >> gor;
}
void Square::Ulica()
{
    cout << "Введите улицу ";
    cout << endl;
    cout << "Улица: "; cin >> ul;
}

int main() {
    setlocale(LC_ALL, "Russian");
    Square a;
    int adress;
    for (;;) {
        cout << "Меню: " << endl;
        cout << "1. Cоздать адрес" << endl;
        cout << "2. Изменить страну" << endl;
        cout << "3. Изменить город" << endl;
        cout << "4. Изменить улицу" << endl;
        cout << "5. Вывод адреса" << endl;
        cout << "6. Выход" << endl;

        cin >> adress;
        cout << endl;

        switch (adress) {
        case 1: {system("cls");
            a.Vvod();
        };
              break;
        case 2: {system("cls");
            a.Strana();
        };
              break;
        case 3: {system("cls");
            a.Gorod();
        };
              break;
        case 4: {system("cls");
            a.Ulica();
        };
              break;
        case 5: {system("cls");
            a.Vivod();
        };
              break;
        case 6: { system("cls");
            exit(0);
        };
              break;
        default: system("cls");
            cout << "Выберите числа от 1 до 6" << endl;
            break;
        }

    }
    system("PAUSE");
    return 0;
}