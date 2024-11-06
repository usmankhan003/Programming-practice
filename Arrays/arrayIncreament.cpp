#include <iostream>
using namespace std;

int main() {
    int* oldArray = new int[6]{ 20, 35, 50, 40, 60, 30 };

    cout << "Old Array Elements:" << endl << endl;
    for (int i = 0; i < 6; i++) {
        cout << oldArray[i] << endl;
    }

    int newSize = 5;  
    int* newArray = new int[newSize];

    for (int i = 0, j = 0; i < 6; i++) {
        if (i == 2) continue;  // Skip the element at index 2
        newArray[j++] = oldArray[i];
    }

    // Delete the old array
    delete[] oldArray;

    cout << "\nNew Array Elements (excluding 50):" << endl << endl;
    for (int i = 0; i < newSize; ++i) {
        cout << newArray[i] << endl;
    }

    return 0;
}
