#include <iostream>
#include <string>

using namespace std; // Use the std namespace

int main()
{
    // Create the connect4 board, it has 7 columns represented by the size of the inner vectors, and 6 columns represented by the number of inner vectors
    array<array<string, 7>, 6> board = {{{"", "", "", "", "", "", ""},
                                         {"", "", "", "", "", "", ""},
                                         {"", "", "", "", "", "", ""},
                                         {"", "", "", "", "", "", ""},
                                         {"", "", "", "", "", "", ""},
                                         {"", "", "", "", "", "", ""}}};

    // The first player will be represented by an X, the second by a Y
    const char FIRST_PLAYER = 'X', SECOND_PLAYER = 'Y';

    string verdict = "";

    // Keep track of turns, first player always starts.
    char turn = FIRST_PLAYER;

    // The rest should be contained in a while loop until a verdict is produced
    while (verdict.empty())
    {

        // Take from the user the desired column
        int move;

        cout << "Please enter your desired column" << endl;

        // Input validation loop
        while (!(std::cin >> move) || std::cin.peek() != '\n' || move > 6 || move < 0)
        {
            std::cin.clear();                                                   // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            std::cout << "Invalid input. Please enter an integer between 0 and 6: ";
        }

        cout << move << endl;

        // We need to fill the bottom-most empty space of the selected column
        for (int i = 5; i >= 0; i--)
        {
            if (board[i][move].empty())
            { // Fill bottom-most available spot
                board[i][move] = turn;

                // Switch players after making the first move
                if (turn = FIRST_PLAYER)
                {
                    turn = SECOND_PLAYER;
                }
                else
                {
                    turn = FIRST_PLAYER;
                }

                // Exit loop
                break;
            }
        }

        // TODO Check for a winner
    }
    return 0;
}
