#include <iostream>
#include <vector>
#include <cstdint>

using std::vector;

const int_fast64_t MOD = 1000000007;

vector<vector<int_fast64_t>> matrixMultiplication(const vector<vector<int_fast64_t>> &matrixA, const vector<vector<int_fast64_t>> &matrixB)
{
    vector<vector<int_fast64_t>> result(2, vector<int_fast64_t>(2, 0));
    result[0][0] = (matrixA[0][0] * matrixB[0][0] + matrixA[0][1] * matrixB[1][0]) % MOD;
    result[0][1] = (matrixA[0][0] * matrixB[0][1] + matrixA[0][1] * matrixB[1][1]) % MOD;
    result[1][0] = (matrixA[1][0] * matrixB[0][0] + matrixA[1][1] * matrixB[1][0]) % MOD;
    result[1][1] = (matrixA[1][0] * matrixB[0][1] + matrixA[1][1] * matrixB[1][1]) % MOD;

    return result;
}

int_fast64_t fibonacci(uint_fast64_t n)
{
    vector<vector<int_fast64_t>> result = {{1, 0}, {0, 1}};
    vector<vector<int_fast64_t>> matrix = {{0, 1}, {1, 1}};

    while(n > 0)
    {
        if(n % 2 == 1)
        {
            result = matrixMultiplication(result, matrix);
        }
        matrix = matrixMultiplication(matrix, matrix);
        n /= 2;
    }

    return result[1][0];
}

int main()
{
    uint_fast64_t n;
    std::cin >> n;

    int_fast64_t fibonacciNumber = fibonacci(n);
    int_fast64_t result = fibonacciNumber % MOD;

    std::cout << result << std::endl;

    return EXIT_SUCCESS;
}