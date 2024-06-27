#include <iostream>
using namespace std;
unsigned long long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

unsigned long long binomialCoefficient(int p, int q) {
    return factorial(p) / (factorial(q) * factorial(p - q));
}

void displayPascalsTriangle(int rows) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j <= i; ++j) {
           cout << binomialCoefficient(i, j) << " ";
        }
      cout << endl;
    }
}

 main() {
    int numRows;

  
    cout << "Enter the number of rows for Pascal's triangle: ";
  cin >> numRows;

    
    cout << "Pascal's triangle:" << std::endl;
    displayPascalsTriangle(numRows);

   
}
