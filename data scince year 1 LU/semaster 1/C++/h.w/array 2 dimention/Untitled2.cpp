#include <iostream>

 main() {
    int N, M;

  
    std::cout << "Enter the number of rows (N) for the matrix A: ";
    std::cin >> N;

    std::cout << "Enter the number of columns (M) for the matrix A: ";
    std::cin >> M;

   
    if (N <= 0 || M <= 0) {
        std::cerr << "Invalid dimensions. Please enter positive values for rows and columns." << std::endl;
        return 1; 
    }

   
    int** A = new int*[N];
    for (int i = 0; i < N; ++i) {
        A[i] = new int[M];
    }

  
    std::cout << "Enter the elements for the matrix A (" << N << " rows, " << M << " columns):" << std::endl;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            std::cout << "Enter value for A[" << i << "][" << j << "]: ";
            std::cin >> A[i][j];
        }
    }


    int** B = new int*[M];
    for (int i = 0; i < M; ++i) {
        B[i] = new int[N];
    }

   
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            B[j][i] = A[i][j];
        }
    }

    
    std::cout << "Original matrix A:" << std::endl;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            std::cout << A[i][j] << " ";
        }
        std::cout << std::endl;
    }

    
    std::cout << "Transposed matrix B:" << std::endl;
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cout << B[i][j] << " ";
        }
        std::cout << std::endl;
    }

 
    for (int i = 0; i < N; ++i) {
        delete[] A[i];
    }
    delete[] A;

    for (int i = 0; i < M; ++i) {
        delete[] B[i];
    }
    delete[] B;

}
