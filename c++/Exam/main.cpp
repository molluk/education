/* ########################################## */
/* ###|By: Melnik Arthur <molluk@mail.ru>|### */
/* ###|                                  |### */
/* ###|   Created: 2020-04-29 21:00:31   |### */
/* ########################################## */

using namespace std;


#include "header.h"

struct  Ship;
struct Player;

int     main()
{
    Player  player1; 
    Player  enemy_field1;
    Player  player2;
    Player  enemy_field2;
    Ship    sh_player1;
    Ship    sh_player2;
    int choice;
    /*
    player1.player_field = (int**)malloc(10 * sizeof(int*));
    player1.enemy_field = (int**)malloc(10 * sizeof(int*));
    player2.player_field = (int**)malloc(10 * sizeof(int*));
    player2.enemy_field = (int**)malloc(10 * sizeof(int*));
    
    for(int i = 0; i < 10; i++) {player1.player_field[i] =  (int*)malloc(10 * sizeof(int));}
    for(int i = 0; i < 10; i++) {player1.enemy_field[i] =  (int*)malloc(10 * sizeof(int));}
    for(int i = 0; i < 10; i++) {player2.player_field[i] =  (int*)malloc(10 * sizeof(int));}
    for(int i = 0; i < 10; i++) {player2.enemy_field[i] =  (int*)malloc(10 * sizeof(int));}
    */
    cout << "Game mode:\n1)Player vs AI;\n2)Player vs Player;\n3)AI vs. AI;\nYou choice :";
    cin >> choice;

    switch(choice)
    {
        case 1: 
                cout << "Generate a table: \n1)Yes; \n2)No;\nYou choice: ";
                cin >> choice;
                if(choice == 1)
                    create_random_table(&player1);
                else 
                {
                    create_table();
                    cout << "Press ENTER when fill the table in the file: \"field_war.txt\"" << endl;
                    getchar();
                    getchar();  
                    if(reading_table(&player1) == 0) return 0;
                    if(check_table(&player1) == 0) return 0;
                }
                cout << "Press ENTER" << endl;
                getchar();
                getchar();
                create_random_table(&player2); //CREATE RANDOM TABLE PLAYER(AI) №2
                create_enemy_print_table(&player2);

                while(sh_player1.all_sell != 0 || sh_player2.all_sell != 0)     //SHOOT
                {
                    system("clear");
                    shoot(&player1, &player2, &sh_player2, 0, 0, 0, 0);     //human atack
                    shoot(&player2, &player1, &sh_player1, 1, 0, 0, 0);     //bot atack
                }
                break;

        case 2: 
                cout << "Generate a table: \n1)Yes; \n2)No;\nYou choice: ";
                cin >> choice;
                if(choice == 1)
                {
                    create_random_table(&player1);
                    create_random_table(&player2);
                }
                else 
                {
                    create_table();
                    cout << "Player 1 press ENTER when fill the table in the file: \"field_war.txt\"" << endl;
                    getchar();
                    getchar();
                    if(reading_table(&player1) == 0) return 0;
                    if(check_table(&player1) == 0) return 0;

                    create_table();
                    cout << "Player 2 press ENTER when fill the table in the file: \"field_war.txt\"" << endl;
                    getchar();
                    getchar();  
                    if(reading_table(&player2) == 0) return 0;
                    if(check_table(&player2) == 0) return 0;
                }
                    while(sh_player1.all_sell != 0 || sh_player2.all_sell != 0)     //SHOOT
                    {
                        system("clear");
                        cout << "PLAYER 1: " << endl;
                        print_table(&player1); 
                        shoot(&player1, &player2, &sh_player2, 0, 0, 0, 0);     //player1 atack
                        system("clear");
                        cout << "PLAYER 2 " << endl;
                        print_table(&player2); 
                        shoot(&player2, &player1, &sh_player1, 0, 0, 0, 0);     //player2 atack
                    }
                    break;
        case 3:
                create_random_table(&player1); //CREATE RANDOM TABLE PLAYER(AI) №1
                create_random_table(&player2);
                create_enemy_print_table(&player1);
                create_enemy_print_table(&player2);
                while(sh_player1.all_sell != 0 || sh_player2.all_sell != 0)     //SHOOT
                {
                    shoot(&player1, &player2, &sh_player2, 1, 0, 0, 0);     //human atack
                    shoot(&player2, &player1, &sh_player1, 1, 0, 0, 0);     //bot atack
                }
                if(sh_player1.all_sell > 0) cout << "WIN BOT №1" << endl;
                else if(sh_player2.all_sell > 0) cout << "WIN BOT №2" << endl;
                break;
            
    }

}

