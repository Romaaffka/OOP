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
//��������
void Square::Vvod() {
    cout << endl << "������� ����� �����������: " << endl;
    cout << "������: "; cin >> str;
    cout << "�����: "; cin >> gor;
    cout << "�����: "; cin >> ul;
    cout << endl;
}
//�����
void Square::Vivod() {
    cout << endl << "������ �����: ";
    cout << "\n������: " << str << "\n�����: " << gor << "\n�����: " << ul;
    cout << endl << endl;
}
//��������� ������
void Square::Strana()
{
    cout << "������� ������ ";
    cout << endl;
    cout << "������: "; cin >> str;
}
//��������� ������
void Square::Gorod()
{
    cout << "������� ����� ";
    cout << endl;
    cout << "�����: "; cin >> gor;
}
void Square::Ulica()
{
    cout << "������� ����� ";
    cout << endl;
    cout << "�����: "; cin >> ul;
}

int main() {
    setlocale(LC_ALL, "Russian");
    Square a;
    int adress;
    for (;;) {
        cout << "����: " << endl;
        cout << "1. C������ �����" << endl;
        cout << "2. �������� ������" << endl;
        cout << "3. �������� �����" << endl;
        cout << "4. �������� �����" << endl;
        cout << "5. ����� ������" << endl;
        cout << "6. �����" << endl;

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
            cout << "�������� ����� �� 1 �� 6" << endl;
            break;
        }

    }
    system("PAUSE");
    return 0;
}