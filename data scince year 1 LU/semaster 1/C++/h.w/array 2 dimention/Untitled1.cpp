#include <iostream>

int main() {
    const int maxRows = 10;
    const int maxCols = 10;

    int R, C;

  
    std::cout << "Enter the number of rows (R) for the 2D array (max 10): ";
    std::cin >> R;

    std::cout << "Enter the number of columns (C) for the 2D array (max 10): ";
    std::cin >> C;

 
    if (R <= 0 || R > maxRows || C <= 0 || C > maxCols) {
        std::cerr << "Invalid dimensions. Please enter values between 1 and 10." << std::endl;
        return 1; // Exit with an error code
    }

  
    int M[maxRows][maxCols];
    int V[maxRows * maxCols];

   
    std::cout << "Enter the elements for the 2D array (" << R << " rows, " << C << " columns):" << std::endl;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            std::cout << "Enter value for M[" << i << "][" << j << "]: ";
            std::cin >> M[i][j];
            V[i * C + j] = M[i][j]; 
        }
    }

    
    std::cout << "Original 2D array M:" << std::endl;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            std::cout << M[i][j] << " ";
        }
        std::cout << std::endl;
    }

  
    std::cout << "Resulting 1D array V:" << std::endl;
    for (int i = 0; i < R * C; ++i) {
        std::cout << V[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
