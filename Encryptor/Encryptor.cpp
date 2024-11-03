#include <iostream>
#include <fstream>
#include <string>
#include <locale> 

using namespace std;

void encrypt(const string& text, const string& outputFile, int shift) {
    ofstream outFile(outputFile);

    if (!outFile.is_open()) {
        cout << "Грешка при отварянето на изходния файл!" << endl;
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
    cout << "Текстът е криптиран успешно и записан в " << outputFile << "!" << endl;
}


void decrypt(const string& inputFile, const string& outputFile, int shift) {
    ifstream inFile(inputFile);
    ofstream outFile(outputFile);

    if (!inFile.is_open() || !outFile.is_open()) {
        cout << "Грешка при отварянето на файловете!" << endl;
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
    cout << "Файлът е декриптиран успешно и записан в " << outputFile << "!" << endl;
}


void displayMenu() {
    cout << "Инструмент за криптиране/декриптиране на текст" << endl;
    cout << "1. Криптиране на текст" << endl;
    cout << "2. Декриптиране на файл" << endl;
    cout << "3. Изход" << endl;
}

int main() {
    setlocale(LC_ALL, ""); 
    int choice;
    string inputText, inputFile, outputFile; 
    int shift;

    while (true) {
        displayMenu();
        cout << "Въведете вашия избор: ";
        cin >> choice;
        cin.ignore(); 

        switch (choice) {
        case 1: 
            cout << "Въведете текста за криптиране: ";
            getline(cin, inputText); 
            cout << "Въведете името на изходния файл: ";
            getline(cin, outputFile);
            cout << "Въведете стойност на изместването (1-25): ";
            cin >> shift;
            encrypt(inputText, outputFile, shift);
            break;

        case 2: 
            cout << "Въведете името на входния файл: ";
            getline(cin, inputFile); 
            cout << "Въведете името на изходния файл: ";
            getline(cin, outputFile);
            cout << "Въведете стойност на изместването (1-25): ";
            cin >> shift;
            decrypt(inputFile, outputFile, shift); 
            break;

        case 3: 
            cout << "Изход..." << endl;
            return 0;

        default:
            cout << "Невалиден избор! Опитайте отново." << endl;
        }

        cout << endl; 
    }
    return 0;
}
