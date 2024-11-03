#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function to encrypt the text using a simple Caesar cipher
void encrypt(const string& inputFile, const string& outputFile, int shift) {
    ifstream inFile(inputFile);
    ofstream outFile(outputFile);

    if (!inFile.is_open() || !outFile.is_open()) {
        cout << "Error opening files!" << endl;
        return;
    }

    char ch;
    while (inFile.get(ch)) {
        if (isalpha(ch)) {
            char offset = islower(ch) ? 'a' : 'A';
            ch = (ch - offset + shift) % 26 + offset;
        }
        outFile << ch;
    }

    inFile.close();
    outFile.close();
    cout << "File encrypted successfully!" << endl;
}

// Function to decrypt the text using a simple Caesar cipher
void decrypt(const string& inputFile, const string& outputFile, int shift) {
    // Decrypting is just encrypting with the negative shift
    encrypt(inputFile, outputFile, 26 - (shift % 26)); // Decrypting is shifting backwards
    cout << "File decrypted successfully!" << endl;
}

// Function to display the menu and get user choice
void displayMenu() {
    cout << "File Encryption/Decryption Tool" << endl;
    cout << "1. Encrypt a file" << endl;
    cout << "2. Decrypt a file" << endl;
    cout << "3. Exit" << endl;
}

int main() {
    int choice;
    string inputFile, outputFile;
    int shift;

    while (true) {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: // Encrypt
            cout << "Enter the input file name: ";
            cin >> inputFile;
            cout << "Enter the output file name: ";
            cin >> outputFile;
            cout << "Enter shift value (1-25): ";
            cin >> shift;
            encrypt(inputFile, outputFile, shift);
            break;

        case 2: // Decrypt
            cout << "Enter the input file name: ";
            cin >> inputFile;
            cout << "Enter the output file name: ";
            cin >> outputFile;
            cout << "Enter shift value (1-25): ";
            cin >> shift;
            decrypt(inputFile, outputFile, shift);
            break;

        case 3: // Exit
            cout << "Exiting..." << endl;
            return 0;

        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    }
    return 0;
}
