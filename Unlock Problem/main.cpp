#include <iostream>
#include <chrono>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;
using namespace std::chrono;

long long backtrack(string tester) {
    auto start_time = high_resolution_clock::now();
    int count = 0;
    string number = "";
    for (int ret = 0; ret < tester.length(); ret++) {
        for (int i = 0; i < 10; i++) {
            cout << "Digit ke-" << ret << " = " << i;
            if (to_string(i) == string(1, tester[ret])) {
                cout << " (accepted)" << endl << endl;
                number += to_string(i);
                count++;
                break;
            }
            else {
                cout << " (declined)" << endl;
                count++;
            }
        }

    }
    cout << "your PIN   : " << number << " (PIN guessed)" << endl;
    cout << "count      : " << count << endl;
    auto end_time = high_resolution_clock::now();
    auto time_lapsed = duration_cast<milliseconds>(end_time - start_time);
    cout << "time taken : " << time_lapsed.count() << " ms" << endl;
    return time_lapsed.count();
}

void bruteforce(int passw) {
    auto start_time = high_resolution_clock::now();
    int guess = 0;
    cout << "current test PIN = " << guess << endl;
    while (true) {
        guess++;
        cout << "current test PIN = " << guess << endl;
        if (guess == passw) {
            cout << endl;
            cout << "your PIN   : " << guess << " (PIN guessed)" << endl;
            break;
        }
    }
    auto end_time = high_resolution_clock::now();
    auto time_lapsed = duration_cast<milliseconds>(end_time - start_time);
    cout << "time taken : " << time_lapsed.count() << " ms" << endl;
}


int generateRandomNumber() {
    // Generate a random number between 100 and 999
    int randomNumber = rand() % 900 + 100;
    return randomNumber;
}

void clearScreen() {
    system("cls");
}

int selectMenu() {
    cout << "======MENU=======" << endl;
    cout << "01. Generate New PIN" << endl;
    cout << "02. Brute Force" << endl;
    cout << "03. Backtracking" << endl;
    cout << "04. Show PIN" << endl;
    cout << "05. Exit" << endl;
    cout << "Masukkan menu: ";

    int input = 5;
    cin >> input;
    cout << "=================" << endl;

    cout << "Tekan ENTER untuk melanjutkan...";
    cin.ignore();  // Mengabaikan karakter newline yang tersisa setelah membaca masukan
    cin.get();  // Menunggu pengguna menekan ENTER

    clearScreen();  // Menghapus layar setelah pengguna menekan ENTER


    return input;
}


int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed the random number generator

    int passw = generateRandomNumber();
    int pilih = selectMenu();

    while (pilih != 5) {
        switch (pilih) {
        case 1:
            passw = generateRandomNumber();
            cout << "Your PIN is = ***" << endl << endl;
            break;
        case 2:
            cout << "\n========== Brute Force ==========" << endl;
            bruteforce(passw);
            cout << endl << endl;
            break;
        case 3:
            cout << "\n========== Backtracking ==========" << endl;
            backtrack(to_string(passw));
            cout << endl << endl;
            break;
        case 4:
            cout << "Your PIN is: " << passw << endl << endl;
            break;
        default:
            cout << "Invalid menu selection." << endl << endl;
            break;

        }
        pilih = selectMenu();
    }

    return 0;
}

