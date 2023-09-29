#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    int minNumber = 1;
    int maxNumber = 100;

    int randomNumber = std::rand() % (maxNumber - minNumber + 1) + minNumber;

    int guess;
    int attempts = 0;

    std::cout << "Welcome to the Guess the Number Game!" << std::endl;

    while (true) {
        std::cout << "Enter your guess: ";
        std::cin >> guess;
        attempts++;

        if (guess < minNumber || guess > maxNumber) {
            std::cout << "Please enter a guess within the valid range (" << minNumber << " - " << maxNumber << ")." << std::endl;
        } else if (guess < randomNumber) {
            std::cout << "Too low! Try again." << std::endl;
        } else if (guess > randomNumber) {
            std::cout << "Too high! Try again." << std::endl;
        } else {
            std::cout << "Congratulations! You guessed the number (" << randomNumber << ") in " << attempts << " attempts!" << std::endl;
            break;  
        }
    }

    return 0;
}
