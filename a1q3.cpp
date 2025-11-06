#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    double start, end, step;
    char ch;
    cout << "Enter the starting angle in degrees : ";
    cin >> start;
    cout << "Enter the ending angle in degrees   : ";
    cin >> end;
    cout << "Enter the step length               : ";
    cin >> step;
    cout << "Enter the fill character            : ";
    cin >> ch;

    int mid = 40;
    cout << "\nPlot of cosine:\n";
    for (double t = start; t <= end; t += step) {
        double rad = t * 3.14159265 / 180.0;
        double val = cos(rad);
        int len = static_cast<int>(val * mid);
        cout << setw(6) << t << "° ";
        if (len < 0) {
            for (int i = 0; i < mid + len; i++) cout << ' ';
            for (int i = 0; i < -len; i++) cout << ch;
            cout << '|';
        } else {
            for (int i = 0; i < mid; i++) cout << ' ';
            cout << '|';
            for (int i = 0; i < len; i++) cout << ch;
        }
        cout << endl;
    }

    cout << "\nPlot of sine:\n";
    for (double t = start; t <= end; t += step) {
        double rad = t * 3.14159265 / 180.0;
        double val = sin(rad);
        int len = static_cast<int>(val * mid);
        cout << setw(6) << t << "° ";
        if (len < 0) {
            for (int i = 0; i < mid + len; i++) cout << ' ';
            for (int i = 0; i < -len; i++) cout << ch;
            cout << '|';
        } else {
            for (int i = 0; i < mid; i++) cout << ' ';
            cout << '|';
            for (int i = 0; i < len; i++) cout << ch;
        }
        cout << endl;
    }

    cout << "\nPlot of exponential:\n";
    for (double t = start; t <= end; t += step) {
        double val = exp(t * 3.14159265 / 180.0);
        int len = static_cast<int>(log10(val + 1) * mid / 2);
        cout << setw(6) << t << "° ";
        for (int i = 0; i < mid; i++) cout << ' ';
        cout << '|';
        for (int i = 0; i < len; i++) cout << ch;
        cout << endl;
    }

    return 0;
}
