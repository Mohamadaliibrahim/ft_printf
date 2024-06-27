#include <iostream>
#include <cmath> // for pow()

int main() {
    int n;

    // Read the degree of the polynomial
    std::cout << "Enter the degree of the polynomial (n): ";
    std::cin >> n;

    // Validate the input for n
    if (n < 0) {
        std::cerr << "Invalid degree. Please enter a non-negative value." << std::endl;
        return 1; // Exit with an error code
    }

    // Declare an array for coefficients
    float A[n + 1];

    // Read coefficients from the user
    std::cout << "Enter the coefficients of the polynomial from highest degree to lowest:" << std::endl;
    for (int i = n; i >= 0; --i) {
        std::cout << "Enter A[" << i << "]: ";
        std::cin >> A[i];
    }

    // Read the value of X
    float X;
    std::cout << "Enter the value of X: ";
    std::cin >> X;

    // Calculate P(X) using pow() function
    float result_pow = 0;
    for (int i = n; i >= 0; --i) {
        result_pow += A[i] * std::pow(X, i);
    }

    // Calculate P(X) using Horner scheme
    float result_horner = A[0];
    for (int i = 1; i <= n; ++i) {
        result_horner = result_horner * X + A[i];
    }

    // Display the results
    std::cout << "Result using pow() function: P(" << X << ") = " << result_pow << std::endl;
    std::cout << "Result using Horner scheme: P(" << X << ") = " << result_horner << std::endl;

    return 0; // Exit successfully
}
