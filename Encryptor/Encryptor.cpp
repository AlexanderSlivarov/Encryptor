#include <iostream>
#include <fstream>
#include <string>
#include <locale> 

using namespace std;

void encrypt(const string& text, const string& outputFile, int shift) {
    ofstream outFile(outputFile);

    if (!outFile.is_open()) {
        cout << "������ ��� ���������� �� �������� ����!" << endl;
        return;
    }

    for (char ch : text) {
        if (isalpha(ch)) {
            char offset = islower(ch) ? 'a' : 'A';
            ch = (ch - offset + shift) % 26 + offset;
        }
        outFile << ch;
    }

    outFile.close();
    cout << "������� � ��������� ������� � ������� � " << outputFile << "!" << endl;
}


void decrypt(const string& inputFile, const string& outputFile, int shift) {
    ifstream inFile(inputFile);
    ofstream outFile(outputFile);

    if (!inFile.is_open() || !outFile.is_open()) {
        cout << "������ ��� ���������� �� ���������!" << endl;
        return;
    }

    char ch;
    while (inFile.get(ch)) {
        if (isalpha(ch)) {
            char offset = islower(ch) ? 'a' : 'A';
            ch = (ch - offset + (26 - (shift % 26))) % 26 + offset; 
        }
        outFile << ch;
    }

    inFile.close();
    outFile.close();
    cout << "������ � ����������� ������� � ������� � " << outputFile << "!" << endl;
}


void displayMenu() {
    cout << "���������� �� ����������/������������ �� �����" << endl;
    cout << "1. ���������� �� �����" << endl;
    cout << "2. ������������ �� ����" << endl;
    cout << "3. �����" << endl;
}

int main() {
    setlocale(LC_ALL, ""); 
    int choice;
    string inputText, inputFile, outputFile; 
    int shift;

    while (true) {
        displayMenu();
        cout << "�������� ����� �����: ";
        cin >> choice;
        cin.ignore(); 

        switch (choice) {
        case 1: 
            cout << "�������� ������ �� ����������: ";
            getline(cin, inputText); 
            cout << "�������� ����� �� �������� ����: ";
            getline(cin, outputFile);
            cout << "�������� �������� �� ������������ (1-25): ";
            cin >> shift;
            encrypt(inputText, outputFile, shift);
            break;

        case 2: 
            cout << "�������� ����� �� ������� ����: ";
            getline(cin, inputFile); 
            cout << "�������� ����� �� �������� ����: ";
            getline(cin, outputFile);
            cout << "�������� �������� �� ������������ (1-25): ";
            cin >> shift;
            decrypt(inputFile, outputFile, shift); 
            break;

        case 3: 
            cout << "�����..." << endl;
            return 0;

        default:
            cout << "��������� �����! �������� ������." << endl;
        }

        cout << endl; 
    }
    return 0;
}
