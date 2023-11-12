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
    const string FIRST_PLAYER = "X", SECOND_PLAYER = "Y";
    const array<string, 4> winningComination1 = {"X", "X", "X", "X"}, winningComination2 = {"Y", "Y", "Y", "Y"};

    string verdict = "";

    // Keep track of turns, first player always starts.
    string turn = FIRST_PLAYER;

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

        // We need to fill the bottom-most empty space of the selected column
        for (int i = 5; i >= 0; i--)
        {
            if (board[i][move].empty())
            { // Fill bottom-most available spot
                board[i][move] = turn;

                // Switch players after making the first move
                if (turn == FIRST_PLAYER)
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

        // Let's test what we have so far

        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 7; j++)
            {
                if (board[i][j].empty())
                {
                    cout << "E";
                }
                else
                {
                    cout << board[i][j];
                }
            }
            cout << '\n';
        }

        // TODO Check for a winner

        // Horizontal check, starting with the bottom and climbing up
        for (int i = 5; i >= 0; i--)
        {
            for (int j = 0; j < 4; j++)
            {
                if (board[i][j] == "E")
                {
                    continue;
                }
                // collect array of 4 consecutive elements
                array<string, 4> sub;
                for (int x = 0; x < 4; x++)
                {
                    sub[x] = board[i][j + x];
                }

                // Compare the 4 consecutive elements beginning from index j with the winning combinations
                if (equal(sub.begin(), sub.end(), begin(winningComination1)))
                {
                    verdict = "Player 1 Wins!";
                    break;
                }
                else if (equal(sub.begin(), sub.end(), begin(winningComination2)))
                {
                    verdict = "Player 2 Wins!";
                    break;
                }
            }
        }

        // Vertical check, top loop represents index
        for (int i = 0; i < 7; i++)
        {
            for (int x = 5; x >= 3; x--)
            {
                if (board[x][i] == "E")
                {
                    continue;
                }
                // collect array of 4 consecutive elements
                array<string, 4> sub;
                for (int j = 0; j < 4; j++)
                {
                    sub[j] = board[x - j][i];
                }

                // Compare the 4 consecutive elements beginning from index j with the winning combinations
                if (equal(sub.begin(), sub.end(), begin(winningComination1)))
                {
                    verdict = "Player 1 Wins!";
                    break;
                }
                else if (equal(sub.begin(), sub.end(), begin(winningComination2)))
                {
                    verdict = "Player 2 Wins!";
                    break;
                }
            }
        }

        // Diagonal check
    }
    cout << verdict << endl;
    return 0;
}
