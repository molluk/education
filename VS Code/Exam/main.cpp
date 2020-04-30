/* ########################################## */
/* ###|By: Melnik Arthur <molluk@mail.ru>|### */
/* ###|                                  |### */
/* ###|   Created: 2020-04-29 21:00:31   |### */
/* ########################################## */

#include <iostream>
#include <fstream>

struct  ship
{
    int four_d = 4;
    int three_d = 6;
    int two_d = 6;
    int single_d = 4;
    int all_sell = 20;
    int all_ships = 10;
    char four_deck = '4';
    char three_deck = '3';
    char two_deck = '2';
    char single_deck = '1';
};

struct player
{
    int player_field[10][9];
};

using namespace std;

void    create_table();
int    reading_table(int matrix_x, int matrix_y);

int     main()
{

    create_table();
    cout << "Press ENTER when fill the table in the file: \"field_war.txt\"" << endl;
    getchar();
    reading_table(0, 0);

    return 0;
}

void    create_table()
{    //create table
    ofstream field_war("field_war.txt");
    for(int i = 1; i <= 10; i++)
    { 
        if(i == 1) field_war << "     a b c d i f g h i j\n" << endl;
        field_war << (char)('a' + i - 1) << "   |0|0|0|0|0|0|0|0|0|0|" << endl;
        if(i == 10)
        {
            for(int i = 0; i < 99; i++) field_war << "*";
            field_war << "\n\t\t\tRULES OF THE GAME" << endl;
            field_war << "\tShips are placed on the field:" << endl;
            field_war << "\t1 ship - a row of 4 cells (“four-deck”; battleship - indicated by the number 4);" << endl;
            field_war << "\t2 ships - a row of 3 cells (“three-deck“; cruisers - indicated by the number 3);" << endl;
            field_war << "\t3 ships - a row of 2 cells (“two-deck“; destroyers - indicated by the number 2);" << endl;
            field_war << "\t4 ships - 1 cell (“single deck“; torpedo boats - indicated by the number 1);" << endl;
            field_war << "\tShips are do not touch each other" << endl;
        }
    }
    field_war.close();
}

int    reading_table(int matrix_x, int matrix_y)
{
    int x = 0, y = 0;
    player player1;
    ship ships;
    char buff;
    ifstream tab("field_war.txt");

    while(buff != '*')
    {
        tab >> buff;
        if(buff >= '0' && buff <= '4' && buff != '\0')
        {
            player1.player_field[x][y] = buff - '0';  //int?
            y++;
            if(buff >= '1' && buff <= '4') ships.all_sell--;
            if(ships.all_sell < 0) 
            {
                cout << "ERROR, you indicated the wrong number of ships" << endl;
                return 0;
            }
        }
        if(y == 10)
        {
            y = 0;
            x++;
        }
    }
    //print table
    for(int x = 0; x < 10; x++)
    {
        for(int y = 0; y < 9; y++)
            cout << "|" << player1.player_field[x][y];
        if(x <= 9) cout << "|" << endl;
    }
    
    return 0;
}