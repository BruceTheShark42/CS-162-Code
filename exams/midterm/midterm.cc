/*
 *  Bruce Cosgrove
 *  NOTE:
 *  I didn't change the code to my own style
 *  simply because it would take more time.
 */
#include <iostream>
#include <cstring>

using namespace std;

// multiply returns the product of num1 and num2 (e.g., num1 * num2).
// num1 and num2 are always positive
// Do not use the * operator, the only operators you
// can use are +, ++, and =
// 50% credit if using other operators
int multiply(int num1, int num2) {
    int product = 0;
    while (num1-- > 0)
        product = product + num2;
    return product;
}

// This function prints out the array parameter in this form:
// [1, 2, 3, 4]
// It does not require a line break.
// Printing out the elements only: 20% (e.g., 1234)
// Printing out the elements with braces: 50% (e.g., [1234])
// Printing out the elements with an extra comma: 80% (e.g., [1, 2, 3, 4, ])
// Printing out correctly: 100% (e.g., [1, 2, 3, 4])
void printArrayElements(int array[], int size) {
    cout << '[';
    for (int i = 0; i < size; ++i) {
        cout << array[i];
        if (i < size - 1)
            cout << ", ";
    }
    cout << ']';
}

// This function decrements the elements at positions
// divisible by 3 in the given array (e.g., 
// elements 0, 3, 6, 9 ...).
// For instance, if the input is {1, 2, 3, 4, 5, 6, 7}
// array would be changed to {2, 2, 3, 5, 5, 6, 8} after
// the function has finished.
// Partial credit subjective
void incrementEveryThirdElement(int array[], int size) {
    for (int i = 0; i < size; i += 3)
        ++array[i];
}

class Averager {
    private:
        double min;
        double max;
    public:
        // Constructor to set min to n, max to x
        Averager(double n, double x) : min(n), max(x) {}
        // Returns the arithmetic mean of min and max
        // (e.g., the sum of min and max divided by two)
        double getMean() {
            return (min + max) / 2.0;
        }
};

// This function prints out the number of vowels (a,e,i,o,u)
// int the given c-style string str. cstring library has
// been imported so you can use strlen() to check the length
// of the string. Do not count y.
// The output should be formatted like this for str "aeei":
// a: 1, e: 2, i:1, o: 0, u:0
// You do not need a line break.
// 50% credit if you print the count only
void printVowelCount(const char str[]) {
    int vowels[5] {0};
    int len = strlen(str);
    for (int i = 0; i < len; ++i) {
        switch (str[i]) {
            case 'A':
            case 'a':
                ++vowels[0];
                break;
            case 'E':
            case 'e':
                ++vowels[1];
                break;
            case 'I':
            case 'i':
                ++vowels[2];
                break;
            case 'O':
            case 'o':
                ++vowels[3];
                break;
            case 'U':
            case 'u':
                ++vowels[4];
                break;
        }
    }
    cout << "a: " << vowels[0] << ", e: " << vowels[1]
         << ", i: " << vowels[2] << ", o: " << vowels[3]
         << ", u: " << vowels[4] << '\n';
}

/*
 * Do NOT modify main!
 */
int main() {
    cout << "*******************\nTesting multiply\n";
    cout << "multiplying 0 * 4\n";
    int actual = multiply(0, 4);
    cout << "Expected 0 and got: " << actual << endl;
    cout << "multiplying 5 * 4\n";
    actual = multiply(5, 4);
    cout << "Expected 20 and got: " << actual << endl;
    cout << "multiplying 25 * 14\n";
    actual = multiply(25, 14);
    cout << "Expected 350 and got: " << actual << endl;

    cout << "\n*******************\nTesting decrementOddElements and printArrayElements\n";
    int array[] = {1,2,3,4};
    cout << "Expected 1 2 3 4 and got: ";
    printArrayElements(array, 4);
    cout << endl;
    int a[] = {5, 2, 7, 12, 15, 19, 34};
    incrementEveryThirdElement(a, 7);
    cout << "Expected [6, 2, 7, 13, 15, 19, 35] and got: ";
    printArrayElements(a, 7);
    cout << endl;
    int b[] = {-4, 64, -4, 0, 0, 300040, 12523, 23426, 7654, 9543};
    incrementEveryThirdElement(b, 10);
    cout << "Expected [-3, 64, -4, 1, 0, 300040, 12524, 23426, 7654, 9544] and got: ";
    printArrayElements(b, 10);
    cout << endl;
    
    /*** Test creating Averager class and getMean function ***/
    cout << "\n*******************\nTesting Averager class and getMean\n";
    Averager m = Averager(112.43, 6.32);
    cout << "Expected 59.375 and got: " << m.getMean() << endl;
    m = Averager(465.89, 9033.67);
    cout << "Expected 4749.78 and got: " << m.getMean() << endl;

    /*** Test printVowelCount ***/
    cout << "\n*******************\nTesting printVowelCount\n";
    cout << "input string: aaeeeiuuuu\n";
    cout << "Expected a: 2, e: 3, i: 1, o: 0, u: 4 and got: ";
    printVowelCount("aaeeeiuuuu");
    cout << endl;
    cout << "input string: eoouaii\n";
    cout << "Expected a: 1, e: 1, i: 2, o: 2, u: 1 and got: ";
    printVowelCount("eoouaii");
    cout << endl;
    cout << "input string: ahoy, when will you and i be done with midterms?\n";
    cout << "Expected a: 2, e: 4, i: 4, o: 3, u: 1 and got: ";
    printVowelCount("ahoy, when will you and i be done with midterms?");
    cout << endl;
    return 0;
}
