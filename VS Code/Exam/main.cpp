/* ########################################## */
/* ###|By: Melnik Arthur <molluk@mail.ru>|### */
/* ###|                                  |### */
/* ###|   Created: 2020-04-29 21:00:31   |### */
/* ########################################## */

#include <iostream>
#include <fstream>

struct  Ship
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

struct Player
{
    int player_field[10][9];
};

using namespace std;

void    create_table();
int     reading_table(Player *player1);
int     check_table(Player *player1, Player *player2);
void    print_table(Player *player1, Player *player2);

int     main()
{
    Player player1;
    Player player2;
    create_table();
    cout << "Press ENTER when fill the table in the file: \"field_war.txt\"" << endl;
    getchar();
    if(reading_table(&player1) == 0) return 0;
    if(check_table(&player1, &player2) == 0) return 0;
    print_table(&player1, &player2);

    return 0;
}

void    create_table()
{
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

int    reading_table(Player *player1)
{
    int x = 0, y = 0, num = 0;
    Ship ships;
    char buff;
    ifstream tab("field_war.txt");

    //reading table
    while(buff != '*' || num <= 99)
    {
        tab >> buff;
        if(buff >= '0' && buff <= '4' && buff != '\0')
        {
            player1->player_field[x][y] = buff - '0';  //int?
            y++;
            num++;
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
    return 1;
}

int     check_table(Player *player1, Player *player2)
{
    int num;

    for(int x = 0; x < 10; x++)
    {
        for(int y = 0; y < 9; y++)
        {
            if(player1->player_field[x][y] >= 1 && player1->player_field[x][y] <= 4)
            {
                num = player1->player_field[x][y];
                if(num == 1)
                {
                    if(0 < (player1->player_field[x][y--] || player1->player_field[x][y++] //1string
                        || player1->player_field[x--][y] || player1->player_field[x][y--] || player1->player_field[x][y++] //2string
                        || player1->player_field[x++][y] || player1->player_field[x][y--] || player1->player_field[x][y++])) //3trsing
                        {
                            cout << "Error cheking table in:" << player1->player_field[x][y] << "(X:Y) = (" << x << y << ")" << endl;
                            return 0;
                        }
                }
                else if(num == 2)
                {
                    if()
                    {

                    }
                    else if((player1->player_field[x][y--] || player1->player_field[x][y++ || 
                        player1->player_field[x--][y]] || player1->player_field[x++][y]) != 2)
                        {
                            cout << "Error cheking table in:" << player1->player_field[x][y] << "(X:Y) = (" << x << y << ")" << endl;
                            return 0;
                        }
                    
                }
            }
        }
    }
    return 1;
}
void    print_table(Player *player1, Player *player2)
{
    for(int x = 0; x < 10; x++)
    {
        for(int y = 0; y < 9; y++)
            cout << "|" << player1->player_field[x][y];
        if(x <= 9) cout << "|" << endl;
    }
}    