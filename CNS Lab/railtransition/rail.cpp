#include <iostream>
#include <string>

using namespace std;

string encryptRailFence(string plaintext, int rails) {
    string ciphertext;
    string railMatrix[rails];
    int row = 0;
    bool directionDown = false;

    for (char c : plaintext) {
        railMatrix[row] += c;

        if (row == 0 || row == rails - 1) {
            directionDown = !directionDown;
        }

        if (directionDown) {
            row++;
        } else {
            row--;
        }
    }

    for (int i = 0; i < rails; i++) {
        ciphertext += railMatrix[i];
    }

    return ciphertext;
}

string decryptRailFence(string ciphertext, int rails) {
    string plaintext;
    string railMatrix[rails];
    int row = 0;
    bool directionDown = false;

    for (int i = 0; i < ciphertext.length(); i++) {
        railMatrix[row] += 'X'; // Fill the railMatrix with placeholders

        if (row == 0 || row == rails - 1) {
            directionDown = !directionDown;
        }

        if (directionDown) {
            row++;
        } else {
            row--;
        }
    }

    int index = 0;
    for (int i = 0; i < rails; i++) {
        for (int j = 0; j < railMatrix[i].length(); j++) {
            railMatrix[i][j] = ciphertext[index++];
        }
    }

    row = 0;
    directionDown = false;

    for (int i = 0; i < ciphertext.length(); i++) {
        plaintext += railMatrix[row][0];
        railMatrix[row].erase(0, 1);

        if (row == 0 || row == rails - 1) {
            directionDown = !directionDown;
        }

        if (directionDown) {
            row++;
        } else {
            row--;
        }
    }

    return plaintext;
}

int main() {
    string plaintext, ciphertext, decryptedText;
    int rails;

    cout << "Enter the plaintext: ";
    getline(cin, plaintext);

    cout << "Enter the number of rails: ";
    cin >> rails;

    ciphertext = encryptRailFence(plaintext, rails);
    cout << "Encrypted ciphertext: " << ciphertext << endl;

    decryptedText = decryptRailFence(ciphertext, rails);
    cout << "Decrypted plaintext: " << decryptedText << endl;

    return 0;
}

