#include <iostream>
#include <vector>

using namespace std;

vector<char> square = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

bool check_win() 
{
    // Check rows
    if (square[1] == square[2] && square[2] == square[3])
    {
        return true;
    }
    if (square[4] == square[5] && square[5] == square[6])
    {
        return true;
    }
    if (square[7] == square[8] && square[8] == square[9])
    {
        return true;
    }
    // Check columns
    if (square[1] == square[4] && square[4] == square[7])
    {
        return true;
    }
    if (square[2] == square[5] && square[5] == square[8])
    {
        return true;
    }
    if (square[3] == square[6] && square[6] == square[9])
    {
        return true;
    }
    // Check diagonals
    if (square[3] == square[5] && square[5] == square[7])
    {
        return true;
    }
    if (square[1] == square[5] && square[5] == square[9])
    {
        return true;
    }

    // Check for draw
    for (int i = 1; i <= 9; i++) 
    {
        if (square[i] != 'X' && square[i] != 'O') 
        {
            return false; // Game is still ongoing
        }
    }
    
    return false; // Draw
}

void board() 
{
    // Clear the screen (for cross-platform compatibility, avoid system calls)
    system("cls");

    cout << "Tic Tac Toe Game" << endl;
    cout << "Player_1 [X] Player_2 [O]" << endl << endl;

    cout << "     |     |     " << endl;
    cout << "  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << "  " << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << "  " << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << "  " << endl;
    cout << "     |     |     " << endl;
}

void resetBoard() 
{
    for (int i = 1; i <= 9; i++) 
    {
        square[i] = '0' + i;
    }
}
int main() {

    char play_again;

    do{
        int player = 1, choice;
        char mark;
        bool game_over = false;
        resetBoard();

        while (!game_over) {
            board();
            player = (player % 2) ? 1 : 2;
            cout << "Player " << player << " enter the number (1-9): ";
            cin >> choice;
    
            mark = (player == 1) ? 'X' : 'O';
    
            if (choice >= 1 && choice <= 9 && square[choice] != 'X' && square[choice] != 'O') 
            {
                square[choice] = mark;
            } 
            else 
            {
                cout << "Invalid Move! Try again." << endl;
                cin.ignore();
                cin.get();
                continue; // Skip the rest of the loop and prompt the player again
            }
    
            if (check_win()) 
            {
                game_over = true;
                board();
                cout << "CONGRATULATIONS! PLAYER " << player << " WINS" << endl;
            } 
            else 
            {
                bool draw = true;
                for (int i = 1; i <= 9; i++) 
                {
                    if (square[i] != 'X' && square[i] != 'O') 
                    {
                        draw = false;
                        break;
                    }
                }
    
                if (draw) 
                {
                    game_over = true;
                    board();
                    cout << "GAME DRAW" << endl;
                }
            }
    
            player++; // Move to the next player
        }
      cout << "Do you want to play again? (Y/N): ";
      cin >> play_again;

    }while(play_again =='Y' || play_again == 'y');

    cin.ignore();
    cin.get();

    return 0;
}
