#include <iostream>
#include <string>

using namespace std;

void addOneHour();
void addOneMinute();
void addOneSecond();

int getHour();
int getMinute();
int getSecond();

void setHour(int h);
void setMinute(int m);
void setSecond(int s);

void displayClocks(unsigned int h, unsigned int m, unsigned int s);

int clockHour = 0;
int clockMinute = 0;
int clockSecond = 0;

int getHour() {
    return clockHour;
}

int getMinute() {
    return clockMinute;
}

int getSecond() {
    return clockSecond;
}

void setHour(int h) {
    clockHour = h;
}

void setMinute(int m) {
    clockMinute = m;
}

void setSecond(int s) {
    clockSecond = s;
}

string twoDigitString(unsigned int n) {
    if (n < 10) {
        return "0" + string(1, '0' + n);
    }
    else {
        return string(1, '0' + (n / 10)) +
            string(1, '0' + (n % 10));
    }
}
string nCharString(size_t n, char c) {
    string result = "";

    for (size_t i = 0; i < n; ++i) {
        result += c;
    }

    return result;
}
string formatTime24(unsigned int h, unsigned int m, unsigned int s) {
    return twoDigitString(h) + ":" +
        twoDigitString(m) + ":" +
        twoDigitString(s);
}
string formatTime12(unsigned int h, unsigned int m, unsigned int s) {

    if (h == 0) {
        return twoDigitString(12) + ":" +
            twoDigitString(m) + ":" +
            twoDigitString(s) + " A M";
    }
    else if (h < 12) {
        return twoDigitString(h) + ":" +
            twoDigitString(m) + ":" +
            twoDigitString(s) + " A M";
    }
    else if (h == 12) {
        return twoDigitString(h) + ":" +
            twoDigitString(m) + ":" +
            twoDigitString(s) + " P M";
    }
    else {
        return twoDigitString(h - 12) + ":" +
            twoDigitString(m) + ":" +
            twoDigitString(s) + " P M";
    }
}
void printMenu(char* strings[], unsigned int numStrings, unsigned char width) {

    cout << nCharString(width, '*') << endl;

    for (unsigned int i = 0; i < numStrings; ++i) {

        unsigned int spaces = width - string(strings[i]).length() - 7;

        cout << "* " << i + 1 << " - " << strings[i]
            << nCharString(spaces, ' ')
                << "*" << endl;

            if (i < numStrings - 1) {
                cout << endl;
            }
    }

    cout << nCharString(width, '*') << endl;
}
unsigned int getMenuChoice(unsigned int maxChoice) {

    unsigned int choice;

    do {
        cin >> choice;
    } while (choice < 1 || choice > maxChoice);

    return choice;
}
void mainMenu() {

    int choice = 0;

    char menu1[] = "Add One Hour";
    char menu2[] = "Add One Minute";
    char menu3[] = "Add One Second";
    char menu4[] = "Exit";

    char* menuItems[] = { menu1, menu2, menu3, menu4 };

    while (choice != 4) {

        displayClocks(getHour(), getMinute(), getSecond());

        cout << endl;

        printMenu(menuItems, 4, 26);

        choice = getMenuChoice(4);

        if (choice == 1) {
            addOneHour();
        }
        else if (choice == 2) {
            addOneMinute();
        }
        else if (choice == 3) {
            addOneSecond();
        }
    }
}
void displayClocks(unsigned int h, unsigned int m, unsigned int s) {

    cout << nCharString(27, '*') << nCharString(3, ' ')
        << nCharString(27, '*') << endl;

    cout << nCharString(1, '*') << nCharString(6, ' ')
        << "12-HOUR CLOCK"
        << nCharString(6, ' ') << nCharString(1, '*')
        << nCharString(3, ' ');

    cout << nCharString(1, '*') << nCharString(6, ' ')
        << "24-HOUR CLOCK"
        << nCharString(6, ' ') << nCharString(1, '*')
        << endl;

    cout << endl;

    cout << nCharString(1, '*') << nCharString(6, ' ')
        << formatTime12(h, m, s)
        << nCharString(7, ' ') << nCharString(1, '*')
        << nCharString(3, ' ');

    cout << nCharString(1, '*') << nCharString(8, ' ')
        << formatTime24(h, m, s)
        << nCharString(9, ' ') << nCharString(1, '*')
        << endl;

    cout << nCharString(27, '*') << nCharString(3, ' ')
        << nCharString(27, '*') << endl;
}
void addOneSecond() {

    int currentSecond = getSecond();

    if (currentSecond <= 58) {
        setSecond(currentSecond + 1);
    }
    else {
        setSecond(0);
        addOneMinute();
    }
}
void addOneMinute() {

    int currentMinute = getMinute();

    if (currentMinute <= 58) {
        setMinute(currentMinute + 1);
    }
    else {
        setMinute(0);
        addOneHour();
    }
}
void addOneHour() {

    int currentHour = getHour();

    if (currentHour >= 0 && currentHour <= 22) {
        setHour(currentHour + 1);
    }
    else if (currentHour == 23) {
        setHour(0);
    }
}
int main() {

    mainMenu();

    return 0;
}