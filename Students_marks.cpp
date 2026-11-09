#include <iostream>
#include <limits>
using namespace std;

const int MAX_STUDENTS = 100;
const double PASS_MARK = 40.0;   


void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}


int readStudentCount() {
    int n;
    cout << "How many students (1-" << MAX_STUDENTS << ")? ";
    cin >> n;
    while (cin.fail() || n < 1 || n > MAX_STUDENTS) {
        clearInput();
        cout << "Invalid count. Enter a number between 1 and " << MAX_STUDENTS << ": ";
        cin >> n;
    }
    return n;
}


void readMarks(double marks[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Enter mark for student " << i + 1 << ": ";
        cin >> marks[i];
        while (cin.fail() || marks[i] < 0 || marks[i] > 100) {
            clearInput();
            cout << "Invalid mark. Enter a value between 0 and 100: ";
            cin >> marks[i];
        }
    }
}

double calculateTotal(const double marks[], int n) {
    double total = 0;
    for (int i = 0; i < n; i++)
        total += marks[i];
    return total;
}

double calculateAverage(const double marks[], int n) {
    return calculateTotal(marks, n) / n;
}

double findHighest(const double marks[], int n) {
    double highest = marks[0];
    for (int i = 1; i < n; i++)
        if (marks[i] > highest)
            highest = marks[i];
    return highest;
}

double findLowest(const double marks[], int n) {
    double lowest = marks[0];
    for (int i = 1; i < n; i++)
        if (marks[i] < lowest)
            lowest = marks[i];
    return lowest;
}

int countPassed(const double marks[], int n) {
    int passed = 0;
    for (int i = 0; i < n; i++)
        if (marks[i] >= PASS_MARK)
            passed++;
    return passed;
}

void displayResults(const double marks[], int n) {
    int passed = countPassed(marks, n);
    cout << "\n----- RESULTS -----\n";
    cout << "Total   : " << calculateTotal(marks, n) << endl;
    cout << "Average : " << calculateAverage(marks, n) << endl;
    cout << "Highest : " << findHighest(marks, n) << endl;
    cout << "Lowest  : " << findLowest(marks, n) << endl;
    cout << "Passed  : " << passed << endl;
    cout << "Failed  : " << n - passed << endl;
    cout << "-------------------\n";
}

int main() {
    char again;
    do {
        int n = readStudentCount();
        double marks[MAX_STUDENTS];

        readMarks(marks, n);
        displayResults(marks, n);

        cout << "\nRun the analysis again? (y/n): ";
        cin >> again;
    } while (again == 'y' || again == 'Y');

    cout << "Goodbye!\n";
    return 0;
}