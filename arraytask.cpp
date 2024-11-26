#include <iostream>
using namespace std;

// Function to resize the array
int* resizeArray(int* array, int& size, int newValue) {
    int* newArray = new int[size + 1];
    for (int i = 0; i < size; i++) {
        newArray[i] = array[i];
    }
    newArray[size] = newValue;
    delete[] array; // Free the old array
    size++;
    return newArray;
}

// Function to calculate the sum of array values
int calculateSum(int* array, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    return sum;
}

// Function to calculate the product of array values
int calculateProduct(int* array, int size) {
    int product = 1;
    for (int i = 0; i < size; i++) {
        product *= array[i];
    }
    return product;
}

// Function to display array values
void displayArray(int* array, int size) {
    cout << "Array values: ";
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main() {
    int* array = new int[1];
    int size = 1;
    int input;

    cout << "Enter the first value: ";
    cin >> array[0];

    while (true) {
        cout << "Do you want to add another value? (yes/no): ";
        string response;
        cin >> response;

        if (response == "yes") {
            cout << "Enter the next value: ";
            cin >> input;
            array = resizeArray(array, size, input);
        } else if (response == "no") {
            if (size == 1) {
                cout << "The only value in the array is: " << array[0] << endl;
            } else {
                while (true) {
                    cout << "Do you want to (A) add, (M) multiply, or (D) display the array values? ";
                    char choice;
                    cin >> choice;

                    if (choice == 'A' || choice == 'a') {
                        cout << "Sum of array values: " << calculateSum(array, size) << endl;
                        break;
                    } else if (choice == 'M' || choice == 'm') {
                        cout << "Product of array values: " << calculateProduct(array, size) << endl;
                        break;
                    } else if (choice == 'D' || choice == 'd') {
                        displayArray(array, size);
                        break;
                    } else {
                        cout << "Invalid choice. Please choose again." << endl;
                    }
                }
            }
            break;
        } else {
            cout << "Invalid input. Please answer 'yes' or 'no'." << endl;
        }
    }

    delete[] array; // Free the memory
    return 0;
}
