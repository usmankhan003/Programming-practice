#include <iostream>
// no changes added
using namespace std;

int main() {
    int* array = new int[1]; // Create an array with one element
    int size = 1;
    int sum = 0;
    int product = 1;

    cout << "Please enter any integer: ";
    cin >> array[0];
//    sum = + array[0];
//    product *= array[0];

    char choice;
    while (true) {
        cout << "Do you want to add another number (Y/N)? ";
        cin >> choice;

        if (choice == 'N' || choice == 'n') {
            break;
        } 
		else if (choice == 'Y' || choice == 'y') {
            // Resize the array
            // function for resizing the array
            int* newArray = new int[size + 1];
            for (int i = 0; i < size; i++) {
                newArray[i] = array[i];
            }
             array = newArray;
           int input;
           
            // Add new element to the array
            cout << "Please enter any integer: ";
            cin >> input;//array[size];
            //funciton call  array = abc(array,input)
//            sum += array[size];
//            product *= array[size];
            size++;
        } 
		else {
            cout << "Invalid choice. Please enter Y or N." << endl;
        }
    }

    // Display the sum and product
//    cout << "Addition of numbers: " << sum << endl;
//    cout << "Multiplication of numbers: " << product << endl;

//    delete[] array;
    
    return 0;
}
