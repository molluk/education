/* ########################################## */
/* ###|By: Melnik Arthur <molluk@mail.ru>|### */
/* ###|                                  |### */
/* ###|   Created: 2020-04-29 21:00:31   |### */
/* ########################################## */

#include <iostream>
#include <fstream>
#include <ctime>

#define error_message cout <<" error in coordinat: \n"<<char(x+'a')<<":"<<char(y+'a')<<":"<<char(y1+'a')<<"\n"<<char(x1+'a')<<":"<<char(y+'a')<<":"<<char(y1+'a')<< endl; return 0;

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
int     create_random_table(Player *player);
int     reading_table(Player *player);
int     check_table(Player *player);
void    print_table(Player *player);

int     main()
{
    Player player1;
    Player player2;

    create_table();
    cout << "Press ENTER when fill the table in the file: \"field_war.txt\"" << endl;
    getchar();
    if(reading_table(&player1) == 0) return 0;
    if(check_table(&player1) == 0) return 0;

    cout << "TABLE PLAYER 1: " << endl;
    print_table(&player1);

    cout << "RANDOM TABLE PLAYER №: 2" << endl;
    create_random_table(&player2);
    print_table(&player2);

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

int    reading_table(Player *player)
{
    int x = 0, y = 0, num = 1;
    Ship ships;
    char buff;
    ifstream tab("field_war.txt");

    //reading table
    while(buff != '*' || num <= 100)
    {
        tab >> buff;
        if(buff >= '0' && buff <= '4' && buff != '\0')
        {
            player->player_field[x][y] = buff - '0';  
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

int     check_table(Player *player)
{
    int num10, num11, num20, num21;
    int x = 0, x1 = 1;  //line      x:|y|y1|    
    int y = 0, y1 = 1;  //column   x1:|y|y1|

    while(x1 < 10)
    {
        num10 = player->player_field[x][y];
        num11 = player->player_field[x][y1];
        num20 = player->player_field[x1][y];
        num21 = player->player_field[x1][y1];

        //check obliquely
        if((num10 != 0 && num21 != 0) || ( num20 != 0 && num11 != 0))
                {
                    cout << "Check obliquely" << endl;
                    error_message;
                }
        //check horizontally and vertically
        else if((num10 > 0 && num20 > 0 && num10 != num20) || (num10 > 0 && num11 > 0 && num10 != num11) ||
                    (num11 > 0 && num10 > 0 && num11 != num10) || (num11 > 0 && num21 > 0 && num11 != num21) || 
                    (num20 > 0 && num10 > 0 && num20 != num10) || (num20 > 0 && num21 > 0 && num20 != num21) ||
                    (num21 > 0 && num20 > 0 && num21 != num20) || (num21 > 0 && num11 > 0 && num21 != num11) )
                {
                    cout << "Check horizontally and vertically" << endl;
                    error_message;
                }
        if ((x1 && y1) == 9) return 1;
        else if(y1 < 9){y++; y1++;}
        else if(y1 == 9){x++; x1++; y = 0; y1 = 1;} 
    }
    return 1;
}

void    print_table(Player *player)
{
    for(int x = 0; x < 9; x++)
    {
        for(int y = 0; y < 9; y++)
            cout << "|" << player->player_field[x][y];
        if(x <= 9) cout << "|" << endl;
    }
}

int    create_random_table(Player *player)
{
    Ship ships;
    srand(time(0));
    int check;

    for(int x = 0; x < 9; x++)
        for(int y = 0; y < 9; y++)
            player->player_field[x][y] = 0;


    while(ships.all_sell > 1)
    {
        if(ships.four_d == 4)
        {
            check = 0;
            while(check < 1)
            {
                int x = 0 + rand() % 5;
                int y = 0 + rand() % 5;
                int xy = 1 + rand() % 2;    //horizontal or vertical
                //horizontal
                if(xy == 0) 
                {
                    player->player_field[x][y] = 4;
                    player->player_field[x][y+1] = 4;
                    player->player_field[x][y+2] = 4;
                    player->player_field[x][y+3] = 4;
                }
                //vetrical
                else
                {
                    player->player_field[x][y] = 4;
                    player->player_field[x+1][y] = 4;
                    player->player_field[x+2][y] = 4;
                    player->player_field[x+3][y] = 4;
                }
                ships.four_d -= 4;
                check++;
            }
            ships.all_sell -= 4;
        }
        else if(ships.three_d == 6)
        {
            check = 0;
            while(check < 2)
            {
                int x = 0 + rand() % 6;
                int y = 0 + rand() % 6;
                int xy = 1 + rand() % 2;    //horizontal or vertical
                //horizontal
                if(xy == 1) 
                {
                    if(player->player_field[x-1][y-1] == 0 && player->player_field[x-1][y] == 0 && player->player_field[x-1][y+1] == 0 && player->player_field[x-1][y+2] == 0 && player->player_field[x-1][y+3] == 0 && 
                        player->player_field[x][y-1] == 0 && player->player_field[x][y] == 0 && player->player_field[x][y+1] == 0 && player->player_field[x][y+2] == 0 && player->player_field[x][y+3] == 0 &&
                        player->player_field[x+1][y-1] == 0 && player->player_field[x+1][y] == 0 && player->player_field[x+1][y+1] == 0 && player->player_field[x+1][y+2] == 0 && player->player_field[x+1][y+3] == 0)
                        {
                            player->player_field[x][y] = 3;
                            player->player_field[x][y+1] = 3;
                            player->player_field[x][y+2] = 3;
                            ships.three_d -= 3;
                            check++;
                            ships.all_sell -= 3;
                        }
                }
                //vetrical
                else
                {
                    if(player->player_field[x-1][y-1] == 0 && player->player_field[x-1][y] == 0 && player->player_field[x-1][y+1] == 0 && 
                        player->player_field[x][y-1] == 0 && player->player_field[x][y+1] == 0 && player->player_field[x+1][y-1] == 0 && player->player_field[x+1][y+1] == 0 && player->player_field[x+2][y-1] == 0 && 
                        player->player_field[x+2][y+1] == 0 && player->player_field[x+3][y-1] == 0 && player->player_field[x+3][y] == 0 && player->player_field[x+3][y+1] == 0)
                        {
                            player->player_field[x][y] = 3;
                            player->player_field[x+1][y] = 3;
                            player->player_field[x+2][y] = 3;
                            ships.three_d -= 3;
                            check++;
                            ships.all_sell -= 3;
                        }
                }
            }
        }
        else if(ships.two_d == 6)
        {
            check = 0;
            while(check < 3)
            {
                int x = 0 + rand() % 7;
                int y = 0 + rand() % 7;
                int xy = 1 + rand() % 2;    //horizontal or vertical
                //horizontal
                if(xy == 1) 
                {
                    if(player->player_field[x-1][y-1] == 0 & player->player_field[x-1][y] == 0 & player->player_field[x-1][y+1] == 0 & player->player_field[x-1][y+2] == 0 & 
                        player->player_field[x][y-1] == 0 & player->player_field[x][y] == 0 & player->player_field[x][y+1] == 0 & player->player_field[x][y+2] == 0 &
                        player->player_field[x+1][y-1] == 0 & player->player_field[x+1][y] == 0 & player->player_field[x+1][y+1] == 0 & player->player_field[x+1][y+2] == 0)
                        {
                            player->player_field[x][y] = 2;
                            player->player_field[x][y+1] = 2;
                            ships.two_d -= 2;
                            check++;
                            ships.all_sell -= 2;
                        }
                }
                //vetrical
                else
                {
                    if(player->player_field[x-1][y-1] == 0 && player->player_field[x-1][y] == 0 && player->player_field[x-1][y+1] == 0 && 
                        player->player_field[x][y-1] == 0 && player->player_field[x][y] == 0 && player->player_field[x][y+1] == 0 && player->player_field[x+1][y-1] == 0 && player->player_field[x+1][y] == 0 && 
                        player->player_field[x+1][y+1]== 0 && player->player_field[x+2][y-1] == 0 && player->player_field[x+2][y] == 0 && player->player_field[x+2][y+1] == 0)
                        {
                            player->player_field[x][y] = 2;
                            player->player_field[x+1][y] = 2;
                            ships.two_d -= 2;
                            check++;
                            ships.all_sell -= 2;
                        }
                }
            }
        }
        else if(ships.single_d == 4)
        {
            check = 0;
            while(check < 3)
            {
                int x = 0 + rand() % 8;
                int y = 0 + rand() % 8;
                int xy = 1 + rand() % 2;    //horizontal or vertical
                //horizontal
                if(xy == 1) 
                {
                    if(player->player_field[x-1][y-1] == 0 && player->player_field[x-1][y] == 0 && player->player_field[x-1][y+1] == 0 && 
                        player->player_field[x][y-1] == 0 && player->player_field[x][y] == 0 && player->player_field[x][y+1] == 0 &&
                        player->player_field[x+1][y-1] == 0 && player->player_field[x+1][y] == 0 && player->player_field[x+1][y+1] == 0)
                        {
                            player->player_field[x][y] = 1;
                            ships.single_d -= 1;
                            check++;
                            ships.all_sell -= 1;
                        }
                }
                //vetrical
                else
                {
                    if(player->player_field[x-1][y-1] == 0 && player->player_field[x-1][y] == 0 && player->player_field[x-1][y+1] == 0 && 
                        player->player_field[x][y-1] == 0 && player->player_field[x][y] == 0 && player->player_field[x][y+1] == 0 && player->player_field[x+1][y-1] == 0 && player->player_field[x+1][y] == 0 && 
                        player->player_field[x+1][y+1] == 0 && player->player_field[x+2][y-1] == 0 && player->player_field[x+2][y] == 0 && player->player_field[x+2][y+1] == 0)
                        {
                            player->player_field[x][y] = 1;
                            ships.single_d -= 1;
                            check++;
                            ships.all_sell -= 1;
                        }
                }
            }
        }
    }
    return 0;
}