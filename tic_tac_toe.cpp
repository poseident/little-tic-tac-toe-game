#include <string>
#include <iostream>

void print_board();
void play_game();
int win_check(int turn);
void player_turn(int turn);

enum space_filler
{
    blank = 0,
    X = 1,
    O = 2,
};

space_filler center = blank;
space_filler Upper_center = blank;
space_filler Bottom_center = blank;
space_filler Left_center = blank;
space_filler Right_center = blank;
space_filler Upper_Left_Corner = blank;
space_filler Upper_Right_Corner = blank;
space_filler Bottom_left_corner = blank;
space_filler Bottom_right_corner = blank;

int main(void)
{
    std::cout << "TIC-TAC-TOE:" << std::endl << std::endl;
    std::cout << "Player 1 is O!" << std::endl;
    std::cout << "Player 2 is X!" << std::endl;
    std::cout << std::endl << "Instructions: Press the number of the space that you wish to put your O/X." << std::endl;
    std::cout << "Objective: Get 3 in a row of O/X to win! That's it!" << std::endl << std::endl;

    play_game();
}

int taken(std::string input)
{
    int i = stoi(input);
    switch(i)
    {
        case 1:
        {
            if (center != blank)
                return (1);
            break;
        }
        case 2:
        {
            if (Upper_center != blank)
                return (1);
            break;
        }
        case 3:
        {
            if (Bottom_center != blank)
                return (1);
            break;
        }
        case 4:
        {
            if (Left_center != blank)
                return (1);
            break;
        }
        case 5:
        {
            if (Right_center != blank)
                return (1);
            break;
        }
        case 6:
        {
            if (Upper_Left_Corner != blank)
                return (1);
            break;
        }
        case 7:
        {
            if (Upper_Right_Corner != blank)
                return (1);
            break;
        }
        case 8:
        {
            if (Bottom_left_corner != blank)
                return (1);
            break;
        }
        case 9:
        {
            if (Bottom_right_corner != blank)
                return (1);
            break;
        }
    }
    return (0);
}

void put_piece(std::string input, int turn)
{
    int i = stoi(input);
    space_filler piece;

    if (turn % 2 == 0)
        piece = O;
    else
        piece = X;
    switch(i)
    {
        case 1: center = piece; break;
        case 2: Upper_center = piece; break;
        case 3: Bottom_center = piece; break;
        case 4: Left_center = piece; break;
        case 5: Right_center = piece;  break;
        case 6: Upper_Left_Corner = piece; break;
        case 7: Upper_Right_Corner = piece; break;
        case 8: Bottom_left_corner = piece; break;
        case 9: Bottom_right_corner = piece; break;
    }
}

int in_the_board(std::string input)
{
    int i = stoi(input);

    if (i > 9 || i < 1)
        return (0);
    else
        return (1);
}

void player_turn(int turn)
{
    std::string input;

    do
    {
        print_board();
        if (turn % 2 == 0)
            std::cout << "Player 1 turn" << std::endl;
        else
            std::cout << "Player 2 turn" << std::endl;
        std::cout << "choose number on the board to put your pieces, wich isnt already taken" << std::endl;
        std::cin >> input;
        if (taken(input))
            std::cout << "this piece is already taken" << std::endl;
        if (!in_the_board(input))
            std::cout << stoi(input) << " is not available on the board" << std::endl;
    } while (taken(input) || !in_the_board(input));
    put_piece(input, turn);
}

void print_board()
{
    switch(center)
    {
        case 0: std::cout << "1. __     "; break;
        case 1: std::cout << "1. X      "; break;
        case 2: std::cout << "1. O      "; break;
    }
    switch(Upper_center)
    {
        case 0: std::cout << "2. __     "; break;
        case 1: std::cout << "2. X      "; break;
        case 2: std::cout << "2. O      "; break;
    }
    switch (Bottom_center)
    {
        case 0: std::cout << "3. __     " << std::endl << std::endl; break;
        case 1: std::cout << "3. X      " << std::endl << std::endl; break;
        case 2: std::cout << "3. O      " << std::endl << std::endl; break;
    }
    switch(Left_center)
    {
        case 0: std::cout << "4. __     "; break;
        case 1: std::cout << "4. X      "; break;
        case 2: std::cout << "4. O      "; break;
    }
    switch(Right_center)
    {
        case 0: std::cout << "5. __     "; break;
        case 1: std::cout << "5. X      "; break;
        case 2: std::cout << "5. O      "; break;
    }
    switch(Upper_Left_Corner)
    {
        case 0: std::cout << "6. __     " << std::endl << std::endl; break;
        case 1: std::cout << "6. X      " << std::endl << std::endl; break;
        case 2: std::cout << "6. O      " << std::endl << std::endl; break;
    }
    switch(Upper_Right_Corner)
    {
        case 0: std::cout << "7. __     "; break;
        case 1: std::cout << "7. X      "; break;
        case 2: std::cout << "7. O      "; break;
    }
    switch(Bottom_left_corner)
    {
        case 0: std::cout << "8. __     "; break;
        case 1: std::cout << "8. X      "; break;
        case 2: std::cout << "8. O      "; break;
    }
    switch(Bottom_right_corner)
    {
        case 0: std::cout << "9. __     " << std::endl << std::endl; break;
        case 1: std::cout << "9. X      " << std::endl << std::endl; break;
        case 2: std::cout << "9. O      " << std::endl << std::endl; break;
    }
}

void play_game(void)
{
    int piece_on_board = 0;
    int turn = 0;
    std::string input;
    bool win = false;

    std::cout << "choose a number between 1 and 9 to put your piece in the board" << std::endl;
    while (!win && piece_on_board < 9)
    {
        player_turn(turn);
        win = win_check(turn);
        turn++;
        piece_on_board++;
    }
    if (piece_on_board == 9 && !win)
        std::cout << "its a draw gg !" << std::endl;
    return ;
}

int win_check(int turn)
{
    space_filler checker;
    space_filler checker2;
    space_filler checker3;
    int player;

    if (turn % 2 == 0)
        player = 1;
    else
        player = 2;
    if (center != blank)
    {
        checker = center;
        if(Left_center == checker && Upper_Right_Corner == checker)
        {
            std::cout << "Player " << player << " wins!" << std::endl;
            return (1);
        }
        else if(Upper_center == checker && Bottom_center == checker)
        {
            std::cout << "Player " << player << " wins!" << std::endl;
            return (1);
        }
    }
    if (Right_center != blank)
    {
        checker2 = Right_center;
        if(center == checker2 && Bottom_right_corner == checker2)
        {
            std::cout << "Player " << player << " wins!" << std::endl;
            return (1);
        }
        else if(Left_center == checker2 && Upper_Left_Corner == checker2)
        {
            std::cout << "Player " << player << " wins!" << std::endl;
            return (1);
        }
        else if(Upper_center == checker2 && Bottom_left_corner == checker2)
        {
            std::cout << "Player " << player << " wins!" << std::endl;
            return (1);
        }
        else if(Upper_Right_Corner == checker2 && Bottom_center == checker2)
        {

            std::cout << "Player " << player << " wins!" << std::endl;
            return (1);
        }
    }
    if (Bottom_right_corner != blank)
    {
        checker3 = Bottom_right_corner;
        if(Bottom_center == checker3 && Upper_Left_Corner == checker3)
        {
            std::cout << "Player " << player << " wins!" << std::endl;
            return (1);
        }
        else if(Upper_Right_Corner == checker3 && Bottom_left_corner == checker3)
        {
            std::cout << "Player " << player << " wins!" << std::endl;
            return (1);
        }
    }
    return (0);
}