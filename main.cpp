#include <iostream>
#include <string>
#include <ctime>


using namespace std;
class Position;
class Piece
{
    char player;
    int column, row;
    bool isKing;


public:
    static int move_choice;
    static bool inJump;
    Piece() {}
    Piece(char player, int row, int column, bool isKing = false)
    {
        this->player = player;
        this->column = column;
        this->row = row;
        this->isKing = isKing;
    }
    void setrow(int x)
    {
        row = x;
    }
    void setcolumn(int y)
    {
        column = y;
    }
    int getrow()
    {
        return row;
    }
    int getcolumn()
    {
        return column;
    }

    void setIsKing()
    {
        isKing = true;
    }
    bool getIsKing()
    {
        return isKing;
    }

    void validateMoves(Position board[8][8]);
    void makeMove(int row, int col)
    {
        if ((row < 8 && row >= 0) && (col < 8 && col >= 0))
        {
            this->row = row;
            this->column = col;
        }

        if (row == 0 && player == 'W')
            isKing = true;
        else if (row == 7 && player == 'R')
            isKing = true;
    }


};

class Position
{
    bool isDark, isKingMaker;
    char containingValue;

public:
    Position() {}
    Position(bool isDark, int row)
    {
        this->isDark = isDark;
        containingValue = ' ';

        if (row == 0 || row == 7)
            isKingMaker = true;
        else
            isKingMaker = false;
    }

    void setContainingValue(char x)
    {
        this->containingValue = x;
    }

    char getContainingValue()
    {
        return containingValue;
    }

    bool getIsKingMaker()
    {
        return isKingMaker;
    }

    bool getIsDark()
    {
        return isDark;
    }


    void afterMoveCleaner()
    {
        if (containingValue != 'R' && containingValue != 'W')
            containingValue = ' ';
    }


};

void Piece::validateMoves(Position board[8][8])
{
    cout << "Row: " << row << '\t' << "Column: " << column << endl;
    cout << "Status: " << (isKing ? "King" : "Not a King") << endl;
    cout << "Possible Moves: ";


    if (player == 'R') // PLAYER IS RED
    {
        if (!isKing)
        {
            if (board[row + 1][column + 1].getContainingValue() == 'W' && (column + 1 < 8) && (row + 1 < 8))
            {
                if ((board[row + 2][column + 2].getContainingValue() == ' ' || (board[row + 2][column + 2].getContainingValue() != 'W' && board[row + 2][column + 2].getContainingValue() != player)) && (column + 2 < 8) && (row + 2 < 8))
                {
                    move_choice++;
                    board[row + 2][column + 2].setContainingValue(move_choice);
                    cout << (char)move_choice << ", ";
                    inJump = true;
                }
            }
            if ((board[row + 1][column - 1].getContainingValue() == 'W') && (column - 1 >= 0) && (row + 1 < 8))
            {
                if ((board[row + 2][column - 2].getContainingValue() == ' ' || (board[row + 2][column - 2].getContainingValue() != 'W' && board[row + 2][column - 2].getContainingValue() != player)) && (column - 2 >= 0) && (row + 2 < 8))
                {
                    move_choice++;
                    board[row + 2][column - 2].setContainingValue(move_choice);
                    cout << (char)move_choice << ", ";
                    inJump = true;
                }
            }
            if (!inJump)
            {
                if ((board[row + 1][column + 1].getContainingValue() == ' ') && (column + 1 < 8) && (row + 1 < 8))
                {
                    move_choice++;
                    board[row + 1][column + 1].setContainingValue(move_choice);
                    cout << (char)move_choice << ", ";
                }
                if (board[row + 1][column - 1].getContainingValue() == ' ' && (column - 1 >= 0) && (row + 1 < 8))
                {
                    move_choice++;
                    board[row + 1][column - 1].setContainingValue(move_choice);
                    cout << (char)move_choice << ", ";
                }
            }




        }

        else // RED KING
        {
            if (board[row + 1][column + 1].getContainingValue() == 'W' && (column + 1 < 8) && (row + 1 < 8))
            {
                if ((board[row + 2][column + 2].getContainingValue() == ' ' || (board[row + 2][column + 2].getContainingValue() != 'W' && board[row + 2][column + 2].getContainingValue() != player)) && (column + 2 < 8) && (row + 2 < 8))
                {
                    move_choice++;
                    board[row + 2][column + 2].setContainingValue(move_choice);
                    cout << (char)move_choice << ", ";
                    inJump = true;
                }
            }
            if ((board[row + 1][column].getContainingValue() == 'W') && (row + 1 < 8))
            {
                if ((board[row + 2][column].getContainingValue() == ' ' || (board[row + 2][column].getContainingValue() != 'W' && board[row + 2][column].getContainingValue() != player)) && (row + 2 < 8))
                {
                    move_choice++;
                    board[row + 2][column].setContainingValue(move_choice);
                    cout << (char)move_choice << ", ";
                    inJump = true;
                }

            }

            if ((board[row + 1][column - 1].getContainingValue() == 'W') && (column - 1 >= 0) && (row + 1 < 8))
            {
                if ((board[row + 2][column - 2].getContainingValue() == ' ' || (board[row + 2][column - 2].getContainingValue() != 'W' && board[row + 2][column - 2].getContainingValue() != player)) && (column - 2 >= 0) && (row + 2 < 8))
                {
                    move_choice++;
                    board[row + 2][column - 2].setContainingValue(move_choice);
                    cout << (char)move_choice << ", ";
                    inJump = true;
                }
            }
            if (board[row - 1][column + 1].getContainingValue() == 'W' && (column + 1 < 8) && (row - 1 >= 0))
            {
                if ((board[row - 2][column + 2].getContainingValue() == ' ' || (board[row - 2][column + 2].getContainingValue() != 'W' && board[row - 2][column + 2].getContainingValue() != player)) && (column + 2 < 8) && (row - 2 >= 0))
                {
                    move_choice++;
                    board[row - 2][column + 2].setContainingValue(move_choice);
                    cout << (char)move_choice << ", ";
                    inJump = true;
                }
            }
            if ((board[row - 1][column].getContainingValue() == 'W') && (row - 1 >= 0))
            {
                if ((board[row - 2][column].getContainingValue() == ' ' || (board[row - 2][column].getContainingValue() != 'W' && board[row - 2][column].getContainingValue() != player)) && (row - 2 >= 0))
                {
                    move_choice++;
                    board[row - 2][column].setContainingValue(move_choice);
                    cout << (char)move_choice << ", ";
                    inJump = true;
                }

            }

            if ((board[row - 1][column - 1].getContainingValue() == 'W') && (column - 1 >= 0) && (row - 1 >= 0))
            {
                if ((board[row - 2][column - 2].getContainingValue() == ' ' || (board[row - 2][column - 2].getContainingValue() != 'W' && board[row - 2][column - 2].getContainingValue() != player)) && (column - 2 >= 0) && (row - 2 >= 0))
                {
                    move_choice++;
                    board[row - 2][column - 2].setContainingValue(move_choice);
                    cout << (char)move_choice << ", ";
                    inJump = true;
                }
            }


            if (!inJump)
            {
                if (board[row + 1][column - 1].getContainingValue() == ' ' && (column - 1 >= 0) && (row + 1 < 8))
                {
                    move_choice++;
                    board[row + 1][column - 1].setContainingValue(move_choice);
                    cout << (char)move_choice << ", ";
                }
                if (board[row + 1][column].getContainingValue() == ' ' && (row + 1 < 8))
                {
                    move_choice++;
                    board[row + 1][column].setContainingValue(move_choice);
                    cout << (char)move_choice << ", ";
                }
                if ((board[row + 1][column + 1].getContainingValue() == ' ') && (column + 1 < 8) && (row + 1 < 8))
                {
                    move_choice++;
                    board[row + 1][column + 1].setContainingValue(move_choice);
                    cout << (char)move_choice << ", ";
                }
                if ((board[row - 1][column + 1].getContainingValue() == ' ') && (column + 1 < 8) && (row - 1 >= 0))
                {
                    move_choice++;
                    board[row - 1][column + 1].setContainingValue(move_choice);
                    cout << (char)move_choice << ", ";
                }
                if (board[row - 1][column].getContainingValue() == ' ' && (row - 1 >= 0))
                {
                    move_choice++;
                    board[row - 1][column].setContainingValue(move_choice);
                    cout << (char)move_choice << ", ";
                }
                if ((board[row - 1][column - 1].getContainingValue() == ' ') && (column - 1 >= 0) && (row - 1 >= 0))
                {
                    move_choice++;
                    board[row - 1][column - 1].setContainingValue(move_choice);
                    cout << (char)move_choice << ", ";
                }
            }
        }
    }
    else // PLAYER IS WHITE
    {
        if (!isKing)
        {
            if (board[row - 1][column + 1].getContainingValue() == 'R' && (column + 1 < 8) && (row - 1 >= 0))
            {
                if ((board[row - 2][column + 2].getContainingValue() == ' ' || (board[row - 2][column + 2].getContainingValue() != 'R' && board[row - 2][column + 2].getContainingValue() != player)) && (column + 2 < 8) && (row - 2 >= 0))
                {
                    move_choice++;
                    board[row - 2][column + 2].setContainingValue(move_choice);
                    cout << (char)move_choice << ", ";
                    inJump = true;
                }
            }
            if ((board[row - 1][column - 1].getContainingValue() == 'R') && (column - 1 >= 0) && (row - 1 >= 0))
            {
                if ((board[row - 2][column - 2].getContainingValue() == ' ' || (board[row - 2][column - 2].getContainingValue() != 'R' && board[row - 2][column - 2].getContainingValue() != player)) && (column - 2 >= 0) && (row - 2 >= 0))
                {
                    move_choice++;
                    board[row - 2][column - 2].setContainingValue(move_choice);
                    cout << (char)move_choice << ", ";
                    inJump = true;
                }
            }
            if (!inJump)
            {
                if ((board[row - 1][column + 1].getContainingValue() == ' ') && (column + 1 < 8) && (row - 1 >= 0))
                {
                    move_choice++;
                    board[row - 1][column + 1].setContainingValue(move_choice);
                    cout << (char)move_choice << ", ";
                }
                if (board[row - 1][column - 1].getContainingValue() == ' ' && (column - 1 >= 0) && (row - 1 >= 0))
                {
                    move_choice++;
                    board[row - 1][column - 1].setContainingValue(move_choice);
                    cout << (char)move_choice << ", ";
                }
            }

        }

        else // WHITE KING
        {
            if (board[row + 1][column + 1].getContainingValue() == 'R' && (column + 1 < 8) && (row + 1 < 8))
            {
                if ((board[row + 2][column + 2].getContainingValue() == ' ' || (board[row + 2][column + 2].getContainingValue() != 'R' && board[row + 2][column + 2].getContainingValue() != player)) && (column + 2 < 8) && (row + 2 < 8))
                {
                    move_choice++;
                    board[row + 2][column + 2].setContainingValue(move_choice);
                    cout << (char)move_choice << ", ";
                    inJump = true;
                }
            }
            if ((board[row + 1][column].getContainingValue() == 'R') && (row + 1 < 8))
            {
                if ((board[row + 2][column].getContainingValue() == ' ' || (board[row + 2][column].getContainingValue() != 'R' && board[row + 2][column].getContainingValue() != player)) && (row + 2 < 8))
                {
                    move_choice++;
                    board[row + 2][column].setContainingValue(move_choice);
                    cout << (char)move_choice << ", ";
                    inJump = true;
                }

            }

            if ((board[row + 1][column - 1].getContainingValue() == 'R') && (column - 1 >= 0) && (row + 1 < 8))
            {
                if ((board[row + 2][column - 2].getContainingValue() == ' ' || (board[row + 2][column - 2].getContainingValue() != 'R' && board[row + 2][column - 2].getContainingValue() != player)) && (column - 2 >= 0) && (row + 2 < 8))
                {
                    move_choice++;
                    board[row + 2][column - 2].setContainingValue(move_choice);
                    cout << (char)move_choice << ", ";
                    inJump = true;
                }
            }
            if (board[row - 1][column + 1].getContainingValue() == 'R' && (column + 1 < 8) && (row - 1 >= 0))
            {
                if ((board[row - 2][column + 2].getContainingValue() == ' ' || (board[row - 2][column + 2].getContainingValue() != 'R' && board[row - 2][column + 2].getContainingValue() != player)) && (column + 2 < 8) && (row - 2 >= 0))
                {
                    move_choice++;
                    board[row - 2][column + 2].setContainingValue(move_choice);
                    cout << (char)move_choice << ", ";
                    inJump = true;
                }
            }
            if ((board[row - 1][column].getContainingValue() == 'R') && (row - 1 >= 0))
            {
                if ((board[row - 2][column].getContainingValue() == ' ' || (board[row - 2][column].getContainingValue() != 'R' && board[row - 2][column].getContainingValue() != player)) && (row - 2 >= 0))
                {
                    move_choice++;
                    board[row - 2][column].setContainingValue(move_choice);
                    cout << (char)move_choice << ", ";
                    inJump = true;
                }

            }

            if ((board[row - 1][column - 1].getContainingValue() == 'R') && (column - 1 >= 0) && (row - 1 >= 0))
            {
                if ((board[row - 2][column - 2].getContainingValue() == ' ' || (board[row - 2][column - 2].getContainingValue() != 'R' && board[row - 2][column - 2].getContainingValue() != player)) && (column - 2 >= 0) && (row - 2 >= 0))
                {
                    move_choice++;
                    board[row - 2][column - 2].setContainingValue(move_choice);
                    cout << (char)move_choice << ", ";
                    inJump = true;
                }
            }


            if (!inJump)
            {
                if (board[row + 1][column - 1].getContainingValue() == ' ' && (column - 1 >= 0) && (row + 1 < 8))
                {
                    move_choice++;
                    board[row + 1][column - 1].setContainingValue(move_choice);
                    cout << (char)move_choice << ", ";
                }
                if (board[row + 1][column].getContainingValue() == ' ' && (row + 1 < 8))
                {
                    move_choice++;
                    board[row + 1][column].setContainingValue(move_choice);
                    cout << (char)move_choice << ", ";
                }
                if ((board[row + 1][column + 1].getContainingValue() == ' ') && (column + 1 < 8) && (row + 1 < 8))
                {
                    move_choice++;
                    board[row + 1][column + 1].setContainingValue(move_choice);
                    cout << (char)move_choice << ", ";
                }
                if ((board[row - 1][column + 1].getContainingValue() == ' ') && (column + 1 < 8) && (row - 1 >= 0))
                {
                    move_choice++;
                    board[row - 1][column + 1].setContainingValue(move_choice);
                    cout << (char)move_choice << ", ";
                }
                if (board[row - 1][column].getContainingValue() == ' ' && (row - 1 >= 0))
                {
                    move_choice++;
                    board[row - 1][column].setContainingValue(move_choice);
                    cout << (char)move_choice << ", ";
                }
                if ((board[row - 1][column - 1].getContainingValue() == ' ') && (column - 1 >= 0) && (row - 1 >= 0))
                {
                    move_choice++;
                    board[row - 1][column - 1].setContainingValue(move_choice);
                    cout << (char)move_choice << ", ";
                }
            }

        }
    }

}



int Piece::move_choice = 96;
bool Piece::inJump = false;
int numOfReds = 12, numOfWhites = 12;

void game_init(char board[8][8]);
void board_init(Position board[8][8]);
void player_init(Piece[], Position board[8][8], char);
void renderBoard(Position board[8][8]);
void theGame();
void makeMove(Piece*&, Piece*&, Position board[8][8], char);
void multipleJump(Piece*&, Piece*&, Position board[8][8], char, int);
int indexFinder(Piece*&, char, int, int);
void positionUpdater(Piece*&, Position board[8][8], char, int, int, int, int, int);
void makeJump(Piece*&, Piece*&, Position board[8][8], char, int, int, int, int, int);
void afterMoveCleaner(Position board[8][8]);
void modifyPieces(Piece*&, int, char);
char winner;
int main()
{
    string p1, p2;
    int choice;
    char toss;
    char toss_winner;
    bool games = true;
    char x;
    int score_p1 = 0;
    int score_p2 = 0;

    cout << "\nEnter name of player 1: ";
    getline(cin, p1);
    cout << "\nEnter name of player 2: ";
    getline(cin, p2);



    cout << endl << "----------COIN TOSS--------";
    cout << endl << endl << p1 << " press h/H for heads and t/T fot tails: ";
    cin >> toss;
    while (toss != 'h' && toss != 'H' && toss != 't' && toss != 'T')
    {
        cout << endl << " press h/H for heads and t/T fot tails:  ";
        cin >> toss;
    }
    srand(time(NULL));
    choice = rand();
    if ((choice % 2 == 1 && toss == 'h') || choice % 2 == 1 && toss == 'H')
    {
        cout << endl << p1 << " has won the toss and will be red in first game." << endl;
        toss_winner = '1';
    }
    else
    {
        cout << endl << p2 << " has won the toss and will be red in first game." << endl;
        toss_winner = '2';
    }

    cout << endl << endl << "If you will enter a wrong move your turn will be skipped.";
    cout << endl << "Making a jump is Compulsory! " << endl << endl;
    cout << p1 << " " << score_p1 << " : " << score_p2 << " " << p2 << endl;
    if (toss_winner == '1')
        cout << endl << p1 << " is red" << endl << endl;

    else
        cout << endl << p2 << " is red" << endl << endl;
    system("pause");
    theGame();
    if (toss_winner == '1')
    {

        if (winner == 'D')
        {
            score_p1 = score_p1;
            score_p2 = score_p2;
        }
        else if (winner == 'R')
            score_p1++;
        else
            score_p2++;
    }

    else
    {
        if (winner == 'D')
        {
            score_p1 = score_p1;
            score_p2 = score_p2;
        }
        else if (winner == 'R')
            score_p2++;
        else
            score_p1++;

    }
    cout << p1 << " " << score_p1 << " : " << score_p2 << " " << p2 << endl;


    if (score_p1 > score_p2)
        cout << endl << p1 << " wins! ";
    else if (score_p2 > score_p1)
        cout << endl << p2 << " wins! ";
    else
        cout << endl << " Match is drawn";
    return 0;
}

void afterMoveCleaner(Position board[8][8])
{
    char x;
    for (int row = 0; row < 8; row++)
    {
        for (int col = 0; col < 8; col++)
        {
            x = board[row][col].getContainingValue();
            if ((x != Piece::move_choice) && (x != 'R') && (x != 'W'))
            {
                board[row][col].setContainingValue(' ');
            }
        }
    }
}
void board_init(Position board[8][8])
{
    bool isLastDark = false;
    for (int row = 0; row < 8; row++)
    {
        for (int col = 0; col < 8; col++)
        {
            if (!isLastDark)
            {
                board[row][col] = Position(true, row);
                if (col != 7)
                    isLastDark = true;
            }
            else
            {
                board[row][col] = Position(false, row);
                if (col != 7)
                    isLastDark = false;
            }

        }
    }
}

void player_init(Piece pieces[], Position board[8][8], char player)
{
    int piece_index = 0, max_row, row;

    if (player == 'R')
    {
        row = 0;
        max_row = 3;
    }

    else
    {
        row = 5;
        max_row = 8;
    }

    for (; row < max_row; row++)
    {
        for (int col = 0; col < 8; col++)
        {
            if (board[row][col].getIsDark())
            {
                pieces[piece_index] = Piece(player, row, col);
                board[row][col].setContainingValue(player);
                piece_index++;
            }
        }
    }
}

void theGame()
{

    Position board[8][8];
    bool gameCompelete = false, isPlayerOne = true, jumpChecked = false;
    Piece* red_pieces = new Piece[numOfReds];
    Piece* white_pieces = new Piece[numOfWhites];
    char choice;

    board_init(board);
    player_init(red_pieces, board, 'R');
    player_init(white_pieces, board, 'W');
    renderBoard(board);
 
    while (!gameCompelete)
    {
        if (isPlayerOne) // RED TURN
        {

            cout << endl << "RED: " << numOfReds << endl;
            for (int i = 0; i < numOfReds; i++)
            {

                red_pieces[i].validateMoves(board);
                cout << endl << endl;
                if (Piece::inJump && !jumpChecked)
                {
                    afterMoveCleaner(board);
                    jumpChecked = true;

                }

            }

            if (numOfReds < 5 && numOfWhites > numOfReds)
            {
                cout << "Would you like to resign? Enter y/Y for YES or any character for NO: ";
                cin >> choice, cout << endl;

                if (choice == 'Y' || choice == 'y')
                {
                    gameCompelete = true;
                    cout << "PLAYER WHITE WON THE GAME, YOU LOST!\n";
                    winner = 'W';
                    break;
                }
                else
                    cout << "CONTINUE WITH THE GAME\n";
            }


            else if (numOfReds < 5 && numOfReds == numOfWhites)
            {
                cout << "Would you like to agree for a draw? Enter y/Y for YES or any character for NO: ";
                cin >> choice, cout << endl;

                if (choice == 'Y' || choice == 'y')
                {
                    cout << "Player RED wants to agree for a draw, would like to agree?: Enter y/Y for YES or any character for NO: ";
                    cin >> choice, cout << endl;
                    if (choice == 'Y' || choice == 'y')
                    {
                        gameCompelete = true;
                        cout << "RED AND WHITE HAVE AGREED FOR A DRAW!\n";
                        winner = 'D';
                        break;
                    }
                    else
                        cout << "PLAYER WHITE DOES NOT AGREE FOR A DRAW, CONTINUE WITH THE GAME\n";
                }
                else
                    cout << "CONTINUE WITH THE GAME\n";
            }
            else if (Piece::move_choice == 96 || numOfReds == 0)
            {
                cout << "PLAYER WHITE WON THE GAME, YOU LOST!\n";
                winner = 'W';
                gameCompelete = true;
                break;
            }

            Piece::move_choice = 96;
            renderBoard(board);
            cout << endl << "RED: " << numOfReds << endl << endl;
            makeMove(red_pieces, white_pieces, board, 'R');
            jumpChecked = false;
            isPlayerOne = false;

        }

        else // WHITE TURN
        {
            cout << endl << "WHITE: " << numOfWhites << endl;
            for (int i = 0; i < numOfWhites; i++)
            {
                white_pieces[i].validateMoves(board);
                cout << endl << endl;
                if (Piece::inJump && !jumpChecked)
                {
                    afterMoveCleaner(board);
                    jumpChecked = true;
                }
            }

            if (numOfWhites < 5 && numOfReds > numOfWhites)
            {
                cout << "Would you like to resign? Enter y/Y for YES or any character for NO: ";
                cin >> choice, cout << endl;

                if (choice == 'Y' || choice == 'y')
                {
                    gameCompelete = true;
                    cout << "PLAYER RED WON THE GAME, YOU LOST!\n";
                    winner = 'R';
                    break;
                }
                else
                    cout << "CONTINUE WITH THE GAME\n";
            }


            else if (numOfWhites < 5 && numOfReds == numOfWhites)
            {
                cout << "Would you like to agree for a draw? Enter y/Y for YES or any character for NO: ";
                cin >> choice, cout << endl;

                if (choice == 'Y' || choice == 'y')
                {
                    cout << "Player WHITE wants to agree for a draw, would like to agree?: Enter y/Y for YES or any character for NO: ";
                    cin >> choice, cout << endl;
                    if (choice == 'Y' || choice == 'y')
                    {
                        gameCompelete = true;
                        cout << "RED AND WHITE HAVE AGREED FOR A DRAW!\n";
                        winner = 'D';
                        break;
                    }
                    else
                        cout << "PLAYER RED DOES NOT AGREE FOR A DRAW, CONTINUE WITH THE GAME\n";
                }
                else
                    cout << "CONTINUE WITH THE GAME\n";
            }
            else if (Piece::move_choice == 96 || numOfWhites == 0)
            {
                cout << "PLAYER RED WON THE GAME, YOU LOST!\n";
                winner = 'R';
                gameCompelete = true;
                break;
            }

            Piece::move_choice = 96;
            renderBoard(board);
            cout << endl << "WHITE: " << numOfWhites << endl << endl;
            makeMove(red_pieces, white_pieces, board, 'W');
            isPlayerOne = true;
            jumpChecked = false;
        }
    }

}

void renderBoard(Position board[8][8])
{
    for (int i = 0;i < 8;i++)
    {
        cout << "   " << i;
    }
    cout << endl;
    cout << " ";
    for (int i = 0; i < 11; i++)
        cout << "---";

    cout << endl;

    for (int row = 0; row < 8; row++)
    {
        cout << row;
        for (int col = 0; col < 8; col++)
        {
            if (col == 0)
            {
                cout << "| " << board[row][col].getContainingValue() << " | ";
            }
            else
            {
                cout << board[row][col].getContainingValue() << " | ";
            }
        }

        cout << endl;
        cout << " ";
        for (int i = 0; i < 11; i++)
            cout << "---";
        cout << endl;
    }
}

void makeMove(Piece*& red_pieces, Piece*& white_pieces, Position board[8][8], char player)
{
    int row_choice, col_choice, index;
    char move_choice;
    bool correctPiece = false;

    while (!correctPiece)
    {
        cout << "Please kindly enter the row of the piece you want to move: ", cin >> row_choice, cout << endl;
        cout << "Please kindly enter the column of the piece you want to move: ", cin >> col_choice, cout << endl;
        if (board[row_choice][col_choice].getContainingValue() == player)
            correctPiece = true;
        else
            cout << "Your piece does not exist at this position, try again!\n";
    }
    cout << "Please kindly enter move you want to make: ", cin >> move_choice, cout << endl;

    for (int row = 0; row < 8; row++)
    {
        for (int col = 0; col < 8; col++)
        {
            if (board[row][col].getContainingValue() == move_choice)
            {
                if (!Piece::inJump)
                {
                    if (player == 'R')
                    {
                        index = indexFinder(red_pieces, player, row_choice, col_choice);
                        positionUpdater(red_pieces, board, player, index, row_choice, col_choice, row, col);
                    }
                    else
                    {
                        index = indexFinder(white_pieces, player, row_choice, col_choice);
                        positionUpdater(white_pieces, board, player, index, row_choice, col_choice, row, col);
                    }
                    continue;
                }
                else
                {
                    if (player == 'R')
                        index = indexFinder(red_pieces, player, row_choice, col_choice);
                    else
                        index = indexFinder(white_pieces, player, row_choice, col_choice);

                    makeJump(red_pieces, white_pieces, board, player, index, row_choice, col_choice, row, col);
                    continue;
                }

            }
            else if (row == 7 && col == 7)
            {
                Piece::inJump = false;
                board[row][col].afterMoveCleaner();
            }
            else
            {
                board[row][col].afterMoveCleaner();
            }

        }
    }

}

int indexFinder(Piece*& pieces, char player, int row, int col)
{
    int size;
    if (player == 'R')
        size = numOfReds;
    else
        size = numOfWhites;

    for (int i = 0; i < size; i++)
    {
        if (pieces[i].getrow() == row && pieces[i].getcolumn() == col)
            return i;
    }

}

void positionUpdater(Piece*& pieces, Position board[8][8], char player, int index, int old_row, int old_col, int new_row, int new_col)
{
    if (!pieces[index].getIsKing())
    {
        if (player == 'R') // RED PLAYER
        {
            if (old_row + 1 == new_row)
            {
                if (old_col + 1 == new_col)
                {
                    pieces[index].makeMove(new_row, new_col);
                    board[old_row][old_col].setContainingValue(' ');
                    board[new_row][new_col].setContainingValue(player);
                }
                else if (old_col - 1 == new_col)
                {
                    pieces[index].makeMove(new_row, new_col);
                    board[old_row][old_col].setContainingValue(' ');
                    board[new_row][new_col].setContainingValue(player);
                }
                else
                {
                    board[new_row][new_col].setContainingValue(' ');
                    cout << "Invalid Move!\n";
                }
            }
            else
            {
                board[new_row][new_col].setContainingValue(' ');
                cout << "Invalid Move!\n";
            }
        }
        else // WHITE PLAYER
        {
            if (old_row - 1 == new_row)
            {
                if (old_col + 1 == new_col)
                {
                    pieces[index].makeMove(new_row, new_col);
                    board[old_row][old_col].setContainingValue(' ');
                    board[new_row][new_col].setContainingValue(player);
                }
                else if (old_col - 1 == new_col)
                {
                    pieces[index].makeMove(new_row, new_col);
                    board[old_row][old_col].setContainingValue(' ');
                    board[new_row][new_col].setContainingValue(player);
                }
                else
                {
                    board[new_row][new_col].setContainingValue(' ');
                    cout << "Invalid Move!\n";
                }
            }
            else
            {
                board[new_row][new_col].setContainingValue(' ');
                cout << "Invalid Move!\n";
            }
        }

    }

    else
    {
        if (old_row + 1 == new_row)
        {
            if (old_col + 1 == new_col)
            {
                pieces[index].makeMove(new_row, new_col);
                board[old_row][old_col].setContainingValue(' ');
                board[new_row][new_col].setContainingValue(player);
            }
            else if (old_col - 1 == new_col)
            {
                pieces[index].makeMove(new_row, new_col);
                board[old_row][old_col].setContainingValue(' ');
                board[new_row][new_col].setContainingValue(player);
            }
            else if (old_col == new_col)
            {
                pieces[index].makeMove(new_row, new_col);
                board[old_row][old_col].setContainingValue(' ');
                board[new_row][new_col].setContainingValue(player);
            }
            else
            {
                board[new_row][new_col].setContainingValue(' ');
                cout << "Invalid Move!\n";
            }
        }
        else if (old_row - 1 == new_row)
        {
            if (old_col + 1 == new_col)
            {
                pieces[index].makeMove(new_row, new_col);
                board[old_row][old_col].setContainingValue(' ');
                board[new_row][new_col].setContainingValue(player);
            }
            else if (old_col - 1 == new_col)
            {
                pieces[index].makeMove(new_row, new_col);
                board[old_row][old_col].setContainingValue(' ');
                board[new_row][new_col].setContainingValue(player);
            }
            else if (old_col == new_col)
            {
                pieces[index].makeMove(new_row, new_col);
                board[old_row][old_col].setContainingValue(' ');
                board[new_row][new_col].setContainingValue(player);
            }
            else
            {
                board[new_row][new_col].setContainingValue(' ');
                cout << "Invalid Move!\n";
            }
        }
        else
        {
            board[new_row][new_col].setContainingValue(' ');
            cout << "Invalid Move!\n";
        }
    }
}

void makeJump(Piece*& red_pieces, Piece*& white_pieces, Position board[8][8], char player, int this_index, int old_row, int old_col, int new_row, int new_col)
{
    int other_index;
    if (player == 'R') // RED PLAYER
    {
        if (!red_pieces[this_index].getIsKing())
        {
            if (old_row + 2 == new_row)
            {
                if (old_col + 2 == new_col && board[old_row + 1][old_col + 1].getContainingValue() == 'W')
                {
                    red_pieces[this_index].makeMove(new_row, new_col);
                    other_index = indexFinder(white_pieces, 'W', old_row + 1, old_col + 1);
                    modifyPieces(white_pieces, other_index, 'W');
                    board[old_row][old_col].setContainingValue(' ');
                    board[old_row + 1][old_col + 1].setContainingValue(' ');
                    board[new_row][new_col].setContainingValue(player);
                    multipleJump(red_pieces, white_pieces, board, player, this_index);
                }
                else if (old_col - 2 == new_col && board[old_row + 1][old_col - 1].getContainingValue() == 'W')
                {
                    red_pieces[this_index].makeMove(new_row, new_col);
                    other_index = indexFinder(white_pieces, 'W', old_row + 1, old_col - 1);
                    modifyPieces(white_pieces, other_index, 'W');
                    board[old_row][old_col].setContainingValue(' ');
                    board[old_row + 1][old_col - 1].setContainingValue(' ');
                    board[new_row][new_col].setContainingValue(player);
                    multipleJump(red_pieces, white_pieces, board, player, this_index);
                }
                else
                {
                    Piece::inJump = false;
                    board[new_row][new_col].setContainingValue(' ');
                    cout << "Invalid Move! You Must Jump!\n";
                }
            }
            else
            {
                Piece::inJump = false;
                board[new_row][new_col].setContainingValue(' ');
                cout << "Invalid Move! You Must Jump!\n";
            }
        }
        else // RED KING
        {
            if (old_row + 2 == new_row)
            {
                if (old_col + 2 == new_col && board[old_row + 1][old_col + 1].getContainingValue() == 'W')
                {
                    red_pieces[this_index].makeMove(new_row, new_col);
                    other_index = indexFinder(white_pieces, 'W', old_row + 1, old_col + 1);
                    modifyPieces(white_pieces, other_index, 'W');
                    board[old_row][old_col].setContainingValue(' ');
                    board[old_row + 1][old_col + 1].setContainingValue(' ');
                    board[new_row][new_col].setContainingValue(player);
                    multipleJump(red_pieces, white_pieces, board, player, this_index);
                }
                else if (old_col - 2 == new_col && board[old_row + 1][old_col - 1].getContainingValue() == 'W')
                {
                    red_pieces[this_index].makeMove(new_row, new_col);
                    other_index = indexFinder(white_pieces, 'W', old_row + 1, old_col - 1);
                    modifyPieces(white_pieces, other_index, 'W');
                    board[old_row][old_col].setContainingValue(' ');
                    board[old_row + 1][old_col - 1].setContainingValue(' ');
                    board[new_row][new_col].setContainingValue(player);
                    multipleJump(red_pieces, white_pieces, board, player, this_index);
                }
                else if (old_col == new_col && board[old_row + 1][old_col].getContainingValue() == 'W')
                {
                    red_pieces[this_index].makeMove(new_row, new_col);
                    other_index = indexFinder(white_pieces, 'W', old_row + 1, old_col);
                    modifyPieces(white_pieces, other_index, 'W');
                    board[old_row][old_col].setContainingValue(' ');
                    board[old_row + 1][old_col].setContainingValue(' ');
                    board[new_row][new_col].setContainingValue(player);
                    multipleJump(red_pieces, white_pieces, board, player, this_index);
                }

                else
                {
                    Piece::inJump = false;
                    board[new_row][new_col].setContainingValue(' ');
                    cout << "Invalid Move! You Must Jump!\n";
                }
            }

            else if (old_row - 2 == new_row)
            {
                if (old_col + 2 == new_col && board[old_row - 1][old_col + 1].getContainingValue() == 'W')
                {
                    red_pieces[this_index].makeMove(new_row, new_col);
                    other_index = indexFinder(white_pieces, 'W', old_row - 1, old_col + 1);
                    modifyPieces(white_pieces, other_index, 'W');
                    board[old_row][old_col].setContainingValue(' ');
                    board[old_row - 1][old_col + 1].setContainingValue(' ');
                    board[new_row][new_col].setContainingValue(player);
                    multipleJump(red_pieces, white_pieces, board, player, this_index);
                }
                else if (old_col - 2 == new_col && board[old_row - 1][old_col - 1].getContainingValue() == 'W')
                {
                    red_pieces[this_index].makeMove(new_row, new_col);
                    other_index = indexFinder(white_pieces, 'W', old_row - 1, old_col - 1);
                    modifyPieces(white_pieces, other_index, 'W');
                    board[old_row][old_col].setContainingValue(' ');
                    board[old_row - 1][old_col - 1].setContainingValue(' ');
                    board[new_row][new_col].setContainingValue(player);
                    multipleJump(red_pieces, white_pieces, board, player, this_index);
                }
                else if (old_col == new_col && board[old_row - 1][old_col].getContainingValue() == 'W')
                {
                    red_pieces[this_index].makeMove(new_row, new_col);
                    other_index = indexFinder(white_pieces, 'W', old_row - 1, old_col);
                    modifyPieces(white_pieces, other_index, 'W');
                    board[old_row][old_col].setContainingValue(' ');
                    board[old_row - 1][old_col].setContainingValue(' ');
                    board[new_row][new_col].setContainingValue(player);
                    multipleJump(red_pieces, white_pieces, board, player, this_index);
                }

                else
                {
                    Piece::inJump = false;
                    board[new_row][new_col].setContainingValue(' ');
                    cout << "Invalid Move! You Must Jump!\n";
                }
            }

            else
            {
                Piece::inJump = false;
                board[new_row][new_col].setContainingValue(' ');
                cout << "Invalid Move! You Must Jump!\n";
            }
        }

    }

    else // WHITE PLAYER
    {
        if (!white_pieces[this_index].getIsKing())
        {
            if (old_row - 2 == new_row)
            {
                if (old_col + 2 == new_col && board[old_row - 1][old_col + 1].getContainingValue() == 'R')
                {
                    white_pieces[this_index].makeMove(new_row, new_col);
                    other_index = indexFinder(red_pieces, 'R', old_row - 1, old_col + 1);
                    modifyPieces(red_pieces, other_index, 'R');
                    board[old_row][old_col].setContainingValue(' ');
                    board[old_row - 1][old_col + 1].setContainingValue(' ');
                    board[new_row][new_col].setContainingValue(player);
                    multipleJump(red_pieces, white_pieces, board, player, this_index);
                }
                else if (old_col - 2 == new_col && board[old_row - 1][old_col - 1].getContainingValue() == 'R')
                {
                    white_pieces[this_index].makeMove(new_row, new_col);
                    other_index = indexFinder(red_pieces, 'R', old_row - 1, old_col - 1);
                    modifyPieces(red_pieces, other_index, 'R');
                    board[old_row][old_col].setContainingValue(' ');
                    board[old_row - 1][old_col - 1].setContainingValue(' ');
                    board[new_row][new_col].setContainingValue(player);
                    multipleJump(red_pieces, white_pieces, board, player, this_index);
                }
                else
                {
                    Piece::inJump = false;
                    board[new_row][new_col].setContainingValue(' ');
                    cout << "Invalid Move! You Must Jump!\n";
                }
            }
            else
            {
                Piece::inJump = false;
                board[new_row][new_col].setContainingValue(' ');
                cout << "Invalid Move! You Must Jump!\n";
            }
        }
        else // WHITE KING
        {
            if (old_row + 2 == new_row)
            {
                if (old_col + 2 == new_col && board[old_row + 1][old_col + 1].getContainingValue() == 'R')
                {
                    white_pieces[this_index].makeMove(new_row, new_col);
                    other_index = indexFinder(red_pieces, 'R', old_row + 1, old_col + 1);
                    modifyPieces(red_pieces, other_index, 'R');
                    board[old_row][old_col].setContainingValue(' ');
                    board[old_row + 1][old_col + 1].setContainingValue(' ');
                    board[new_row][new_col].setContainingValue(player);
                    multipleJump(red_pieces, white_pieces, board, player, this_index);
                }
                else if (old_col - 2 == new_col && board[old_row + 1][old_col - 1].getContainingValue() == 'R')
                {
                    white_pieces[this_index].makeMove(new_row, new_col);
                    other_index = indexFinder(red_pieces, 'R', old_row + 1, old_col - 1);
                    modifyPieces(red_pieces, other_index, 'R');
                    board[old_row][old_col].setContainingValue(' ');
                    board[old_row + 1][old_col - 1].setContainingValue(' ');
                    board[new_row][new_col].setContainingValue(player);
                    multipleJump(red_pieces, white_pieces, board, player, this_index);
                }
                else if (old_col == new_col && board[old_row + 1][old_col].getContainingValue() == 'R')
                {
                    white_pieces[this_index].makeMove(new_row, new_col);
                    other_index = indexFinder(red_pieces, 'R', old_row + 1, old_col);
                    modifyPieces(red_pieces, other_index, 'R');
                    board[old_row][old_col].setContainingValue(' ');
                    board[old_row + 1][old_col].setContainingValue(' ');
                    board[new_row][new_col].setContainingValue(player);
                    multipleJump(red_pieces, white_pieces, board, player, this_index);
                }

                else
                {
                    Piece::inJump = false;
                    board[new_row][new_col].setContainingValue(' ');
                    cout << "Invalid Move! You Must Jump!\n";
                }
            }

            else if (old_row - 2 == new_row)
            {
                if (old_col + 2 == new_col && board[old_row - 1][old_col + 1].getContainingValue() == 'R')
                {
                    white_pieces[this_index].makeMove(new_row, new_col);
                    other_index = indexFinder(red_pieces, 'R', old_row - 1, old_col + 1);
                    modifyPieces(red_pieces, other_index, 'R');
                    board[old_row][old_col].setContainingValue(' ');
                    board[old_row - 1][old_col + 1].setContainingValue(' ');
                    board[new_row][new_col].setContainingValue(player);
                    multipleJump(red_pieces, white_pieces, board, player, this_index);
                }
                else if (old_col - 2 == new_col && board[old_row - 1][old_col - 1].getContainingValue() == 'R')
                {
                    white_pieces[this_index].makeMove(new_row, new_col);
                    other_index = indexFinder(red_pieces, 'R', old_row - 1, old_col - 1);
                    modifyPieces(red_pieces, other_index, 'R');
                    board[old_row][old_col].setContainingValue(' ');
                    board[old_row - 1][old_col - 1].setContainingValue(' ');
                    board[new_row][new_col].setContainingValue(player);
                    multipleJump(red_pieces, white_pieces, board, player, this_index);
                }
                else if (old_col == new_col && board[old_row - 1][old_col].getContainingValue() == 'R')
                {
                    white_pieces[this_index].makeMove(new_row, new_col);
                    other_index = indexFinder(red_pieces, 'R', old_row - 1, old_col);
                    modifyPieces(red_pieces, other_index, 'R');
                    board[old_row][old_col].setContainingValue(' ');
                    board[old_row - 1][old_col].setContainingValue(' ');
                    board[new_row][new_col].setContainingValue(player);
                    multipleJump(red_pieces, white_pieces, board, player, this_index);
                }

                else
                {
                    Piece::inJump = false;
                    board[new_row][new_col].setContainingValue(' ');
                    cout << "Invalid Move! You Must Jump!\n";
                }
            }

            else
            {
                Piece::inJump = false;
                board[new_row][new_col].setContainingValue(' ');
                cout << "Invalid Move! You Must Jump!\n";
            }
        }

    }

}

void multipleJump(Piece*& red_pieces, Piece*& white_pieces, Position board[8][8], char player, int index)
{
    Piece::inJump = false;
    if (player == 'R')
    {
        Piece::move_choice = 96;
        red_pieces[index].validateMoves(board);
        cout << endl;

        if (Piece::inJump)
        {
            renderBoard(board);
            cout << endl << "RED: " << numOfReds << endl << endl;
            makeMove(red_pieces, white_pieces, board, player);
        }
        else
        {
            for (int row = 0; row < 8; row++)
            {
                for (int col = 0; col < 8; col++)
                {
                    board[row][col].afterMoveCleaner();
                }
            }
        }

    }

    else
    {
        Piece::move_choice = 96;
        white_pieces[index].validateMoves(board);
        cout << endl;
        if (Piece::inJump)
        {
            renderBoard(board);
            cout << endl << "WHITE: " << numOfWhites << endl << endl;
            makeMove(red_pieces, white_pieces, board, player);
        }
        else
        {
            for (int row = 0; row < 8; row++)
            {
                for (int col = 0; col < 8; col++)
                {
                    board[row][col].afterMoveCleaner();
                }
            }
        }
    }

}

void modifyPieces(Piece*& pieces, int ignorePiece, char player)
{
    int numOfPieces;
    if (player == 'R')
        numOfPieces = --numOfReds;
    else
        numOfPieces = --numOfWhites;

    Piece* temp = new Piece[numOfPieces];

    for (int i = 0, j = 0; j < numOfPieces + 1; i++, j++)
    {
        if (j == ignorePiece)
        {
            i--;
            continue;
        }
        else
        {
            temp[i] = pieces[j];
        }
    }

    pieces = NULL;
    delete[] pieces;
    pieces = temp;

}
