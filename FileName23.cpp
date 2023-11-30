#include <iostream>
#include <cstdlib>  // For rand and srand
#include <ctime>    // For time

class DiagonalArray {
public:
    void input_data() {
        // Initialize random seed
        srand(static_cast<unsigned>(time(0)));

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (i == j) {
                    // Place a random number from 0 to 9 on the diagonal
                    array[i][j] = rand() % 10;
                }
                else {
                    // Place 0 outside the diagonal
                    array[i][j] = 0;
                }
            }
        }
    }

    void process_data() {
        diagonalSum = 0;

        for (int i = 0; i < 10; i++) {
            diagonalSum += array[i][i];
        }
    }

    void display_result() {
        std::cout << "Diagonal Array:" << std::endl;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                std::cout << array[i][j] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << "Sum of diagonal elements: " << diagonalSum << std::endl;
    }

private:
    int array[10][10];
    int diagonalSum;
};

int main() {
    DiagonalArray arr;

    arr.input_data();
    arr.process_data();
    arr.display_result();

    return 0;
}
