#include <iostream>
using namespace std;

int sum_dividers(int n) {
    int sum = 1; 

    for (int i = 2; i <= n / 2; ++i) {
        if (n % i == 0) {
            sum += i;
        }
    }

    return sum;
}

int is_abundant(int n) {
    return sum_dividers(n) > 2 * n;
}

void display_abundant_numbers(int a, int b) {
    std::cout << "Abundant numbers in the interval [" << a << ", " << b << "]:" << std::endl;

    for (int i = a; i <= b; ++i) {
        if (is_abundant(i)) {
            std::cout << i << " ";
        }
    }

  cout << std::endl;
}
main() {
    int a, b;

    
    cout << "Enter the values of a and b (separated by a space): ";
    cin >> a >> b;

    
    if (a > b) {
      cerr << "Invalid interval. Please ensure that a is less than or equal to b." << std::endl;
        return 1;
    }

    
    display_abundant_numbers(a, b);

  
}
