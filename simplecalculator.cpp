#include <iostream>

int main() {
    char operation;
    double num1, num2;

    std::cout << "Simple Calculator" << std::endl;
    std::cout << "Enter first number: ";
    std::cin >> num1;
    std::cout << "Enter an operation (+, -, *, /): ";
    std::cin >> operation;
    std::cout << "Enter second number: ";
    std::cin >> num2;

    double result;

    switch (operation) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 == 0) {
                std::cout << "Error! Division by zero is not allowed." << std::endl;
                return 1;
            } else {
                result = num1 / num2;
            }
            break;
        default:
            std::cout << "Invalid operation." << std::endl;
            return 1; 
    }

    std::cout << "Result: " << num1 << " " << operation << " " << num2 << " = " << result << std::endl;

    return 0;
}
