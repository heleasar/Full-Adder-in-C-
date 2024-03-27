#include <iostream>
#include <vector>

// Function to implement Full Adder
std::vector<bool> Full_Adder(const std::vector<bool>& a, const std::vector<bool>& b) {
    std::vector<bool> sum;
    bool carry = false;

    // Perform addition bit by bit
    for (int i = 0; i < a.size() || i < b.size(); ++i) {
        bool bitA = (i < a.size()) ? a[i] : false;
        bool bitB = (i < b.size()) ? b[i] : false;

        bool bitSum = bitA ^ bitB ^ carry;
        carry = (bitA && bitB) || (carry && (bitA || bitB));

        sum.push_back(bitSum);
    }

    // If there is a remaining carry, add it as the most significant bit
    if (carry) {
        sum.push_back(true);
    }

    return sum;
}

// Function to print a vector of bool as a binary number
void PrintBinary(const std::vector<bool>& binary) {
    for (int i = binary.size() - 1; i >= 0; --i) {
        std::cout << binary[i];
    }
}

int main() {
    // Test cases
    std::vector<bool> a = {true, true, false};    // Binary number: 011
    std::vector<bool> b = {true, false, true};    // Binary number: 101

    std::vector<bool> sum = Full_Adder(a, b);

    // Print the inputs and sum
    std::cout << "Input a: ";
    PrintBinary(a);
    std::cout << std::endl;

    std::cout << "Input b: ";
    PrintBinary(b);
    std::cout << std::endl;

    std::cout << "Sum: ";
    PrintBinary(sum);
    std::cout << std::endl;

    return 0;
}
