#include <iostream>

const int MAX_DEGREE = 13;

 main() {
    int N;


    std::cout << "Enter the degree of Pascal's triangle (up to 13): ";
    std::cin >> N;

  
    if (N < 0 || N > MAX_DEGREE) {
        std::cerr << "Invalid degree. Please enter a non-negative value up to 13." << std::endl;
        return 1; 
    }

   
    int P[MAX_DEGREE + 1][MAX_DEGREE + 1] = {0};

    
    for (int i = 0; i <= N; ++i) {
        P[i][0] = 1; 
        P[i][i] = 1; 

       
        for (int j = 1; j < i; ++j) {
            P[i][j] = P[i - 1][j] + P[i - 1][j - 1];
        }
    }

  
    std::cout << "Pascal's triangle of degree " << N << ":" << std::endl;
    for (int i = 0; i <= N; ++i) {
        for (int j = 0; j <= i; ++j) {
            std::cout << P[i][j] << " ";
        }
        std::cout << std::endl;
    }

    
}
