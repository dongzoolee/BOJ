#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main(void) {
    long testcase, xaxis, yaxis;
    cin >> testcase;

    long* save = new long[testcase];

    for (int i = 0; i < testcase; i++) {
        cin >> xaxis >> yaxis;
        save[i] = yaxis - xaxis - 2;
    }

    for (int f = 0; f < testcase; f++) {
        long long i = 2, add = 2;
        while (add < save[f]) {
            i++;
            add += i;
        }
        save[f] = i + 1;
    }

    for (int i = 0; i < testcase; i++) {
        cout << save[i];
        if (i != testcase - 1)
            cout << "\n";
    }
    delete[]save;
}