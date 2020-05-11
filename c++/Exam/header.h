/* ########################################## */
/* ###|By: Melnik Arthur <molluk@mail.ru>|### */
/* ###|                                  |### */
/* ###|   Created: 2020-05-11 21:54:24   |### */
/* ########################################## */

#pragma once

#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <unistd.h> //delete this
#include <iostream>

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
    int enemy_field[10][9];
};

using namespace std;

void    create_table();
int     create_random_table(Player *player);
void    create_enemy_print_table(Player *player);
int     reading_table(Player *player);
int     check_table(Player *player);
int     shoot(Player *shoot_pl, Player *def_pl, Ship *sh_player1, int pb, int x1, int y1, int start);   //pb - human || bot
void    print_table(Player *player, int table);    //0 - print player_field, 1 - print enemy_field

