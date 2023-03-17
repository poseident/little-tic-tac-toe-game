#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <stdio.h>
#include <iostream>

void print_board();
void play_game();
int win_check();
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

    //print_board();
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

    switch(i)
    {
        case 1:
        {
            if (turn % 2 == 0)
                center = O;
            else
                center = X;
            break;
        }
        case 2:
        {
            if (turn % 2 == 0)
                Upper_center = O;
            else
                Upper_center = X;
            break;
        }
        case 3:
        {
            if (turn % 2 == 0)
                Bottom_center = O;
            else
                Bottom_center = X;
            break;
        }
        case 4:
        {
            if (turn % 2 == 0)
                Left_center = O;
            else
                Left_center = X;
            break;
        }
        case 5:
        {
            if (turn % 2 == 0)
                Right_center = O;
            else
                Right_center = X;
            break;
        }
        case 6:
        {
            if (turn % 2 == 0)
                Upper_Left_Corner = O;
            else
                Upper_Left_Corner = X;
            break;
        }
        case 7:
        {
            if (turn % 2 == 0)
                Upper_Right_Corner = O;
            else
                Upper_Right_Corner = X;
            break;
        }
        case 8:
        {
            if (turn % 2 == 0)
                Bottom_left_corner = O;
            else
                Bottom_left_corner = X;
            break;
        }
        case 9:
        {
            if (turn % 2 == 0)
                Bottom_right_corner = O;
            else
                Bottom_right_corner = X;
            break;
        }
    }
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
    } while (taken(input) && in_the_board(input));
    put_piece(input, turn);
    //print_board();
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

    std::cout << "choose a number between 1 and 9 to put your piece in the board" << std::endl;
    while (!win_check() && piece_on_board < 9)
    {
        player_turn(turn);
        turn++;
        piece_on_board++;
    }
    if (piece_on_board == 9)
        std::cout << "its a draw gg !" << std::endl;
    return ;
}

int win_check(void)
{
    if(center == O && Left_center == O && Upper_Right_Corner == O)
    {
        std::cout << "Player 1 wins!" << std::endl;
        return (1);
    }
    else if(center == O && Upper_center == O && Bottom_center == O)
    {
        std::cout << "Player 1 wins!" << std::endl;
        return (1);
    }
    else if(center == O && Right_center == O && Bottom_right_corner == O)
    {
        std::cout << "Player 1 wins!" << std::endl;
        return (1);
    }
    else if(Upper_center == O && Right_center == O && Bottom_left_corner == O)
    {
        std::cout << "Player 1 wins!" << std::endl;
        return (1);
    }
    else if(Bottom_center == O && Upper_Left_Corner == O && Bottom_right_corner == O)
    {
        std::cout << "Player 1 wins!" << std::endl;
        return (1);
    }
    else if(Left_center == O && Right_center == O && Upper_Left_Corner == O)
    {
        std::cout << "Player 1 wins!" << std::endl;
        return (1);
    }
    else if(Upper_Right_Corner == O && Bottom_left_corner == O && Bottom_right_corner == O)
    {
        std::cout << "Player 1 wins!" << std::endl;
        return (1);
    }
    else if(Upper_Right_Corner == O && Right_center == O && Bottom_center == O)
    {
        std::cout << "Player 1 wins!" << std::endl;
        return (1);
    }
    else if(center == X && Left_center == X && Upper_Right_Corner == X)
    {
        std::cout << "Player 2 wins!" << std::endl;
        return (1);
    }
    else if(center == O && Upper_center == O && Bottom_center == O)
    {
        std::cout << "Player 2 wins!" << std::endl;
        return (1);
    }
    else if(center == X && Right_center == X && Bottom_right_corner == X)
    {
        std::cout << "Player 2 wins!" << std::endl;
        return (1);
    }
    else if(Upper_center == X && Right_center == X && Bottom_left_corner == X)
    {
        std::cout << "Player 2 wins!" << std::endl;
        return (1);
    }
    else if(Bottom_center == X && Upper_Left_Corner == X && Bottom_right_corner == X)
    {
        std::cout << "Player 2 wins!" << std::endl;
        return (1);
    }
    else if(Left_center == X && Right_center == X && Upper_Left_Corner == X)
    {
        std::cout << "Player 2 wins!" << std::endl;
        return (1);
    }
    else if(Upper_Right_Corner == X && Bottom_left_corner == X && Bottom_right_corner == X)
    {
        std::cout << "Player 2 wins!" << std::endl;
        return (1);
    }
    else if(Upper_Right_Corner == X && Right_center == X && Bottom_center == X)
    {
        std::cout << "Player 2 wins!" << std::endl;
        return (1);
    }
    else
        return (0);
}