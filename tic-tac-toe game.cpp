#include <iostream>
#include <vector>
#include <string>

void printBoard(const std::vector<std::vector<char>>& board) {
    std::cout << "   0   1   2" << std::endl;
    for (int i = 0; i < 3; ++i) {
        std::cout << i << "  ";
        for (int j = 0; j < 3; ++j) {
            std::cout << board[i][j];
            if (j < 2) {
                std::cout << " | ";
            }
        }
        std::cout << std::endl;
        if (i < 2) {
            std::cout << "  ---|---|---" << std::endl;
        }
    }
    std::cout << std::endl;
}

bool isGameOver(const std::vector<std::vector<char>>& board, char player) {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true;
        }
    }

    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }

    return false;
}

int main() {
    char playAgain;
    do {
        std::vector<std::vector<char>> board(3, std::vector<char>(3, ' ')); 
        char currentPlayer = 'X'; 
        int row, col;
        bool gameInProgress = true;

        std::cout << "Welcome to Tic-Tac-Toe!" << std::endl;

        while (gameInProgress) {
            printBoard(board);

            std::cout << "Player " << currentPlayer << ", enter your move (row and column): ";
            std::cin >> row >> col;

            if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
                std::cout << "Invalid move! Try again." << std::endl;
                continue;
            }

            
            board[row][col] = currentPlayer;

            
            if (isGameOver(board, currentPlayer)) {
                printBoard(board);
                std::cout << "Player " << currentPlayer << " wins!" << std::endl;
                gameInProgress = false; 
            } else {
                
                bool draw = true;
                for (int i = 0; i < 3; ++i) {
                    for (int j = 0; j < 3; ++j) {
                        if (board[i][j] == ' ') {
                            draw = false;
                            break;
                        }
                    }
                    if (!draw) {
                        break;
                    }
                }
                if (draw) {
                    printBoard(board);
                    std::cout << "It's a draw!" << std::endl;
                    gameInProgress = false; 
                } else {
                    
                    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
                }
            }
        }

        std::cout << "Do you want to play again? (y/n): ";
        std::cin >> playAgain;
        std::cin.ignore();
    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}
