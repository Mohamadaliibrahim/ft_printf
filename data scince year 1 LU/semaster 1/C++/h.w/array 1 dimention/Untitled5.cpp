#include <iostream>
using namespace std;
main() {
    const int maxSize = 50;
    int N;

    cout << "Enter the dimension N of the array (maximum 50): ";
    cin >> N;

   
    if (N <= 0 || N > maxSize) {
        std::cerr << "Invalid array dimension. Please enter a value between 1 and 50." << std::endl;
        return 1; 
    }

    
    int A[maxSize];

    
    cout << "Enter " << N << " integers for the array:" << std::endl;
    for (int i = 0; i < N; ++i) {
        std::cout << "Enter value for A[" << i << "]: ";
        std::cin >> A[i];
    }

    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N - i - 1; ++j) {
            if (A[j] > A[j + 1]) {
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }

  
    cout << "Array after sorting in ascending order:" << std::endl;
    for (int i = 0; i < N; ++i) {
        std::cout << A[i] << " ";
    }
    cout << std::endl;

  
    int VAL;
    cout << "Enter a new value (VAL) to insert into the sorted array: ";
    cin >> VAL;

   
    int insertIndex = 0;
    while (insertIndex < N && VAL > A[insertIndex]) {
        insertIndex++;
    }

   
    for (int i = N; i > insertIndex; --i) {
        A[i] = A[i - 1];
    }

  
    A[insertIndex] = VAL;

   
    cout << "Array after inserting " << VAL << " in ascending order:" << std::endl;
    for (int i = 0; i <= N; ++i) {
        std::cout << A[i] << " ";
    }
  cout << std::endl;

   
}
