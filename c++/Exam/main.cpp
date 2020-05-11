/* ########################################## */
/* ###|By: Melnik Arthur <molluk@mail.ru>|### */
/* ###|                                  |### */
/* ###|   Created: 2020-04-29 21:00:31   |### */
/* ########################################## */

//ПЕЧАТЬ ТАБЛИЦЫ ВЫСТРЕЛОВ 

using namespace std;


#include "header.h"

struct  Ship;
struct Player;

int     main()
{
    Player  player1; 
    Player enemy_field1;
    Player  player2;
    Player enemy_field2;
    Ship    sh_player1;
    Ship    sh_player2;
    int choice;

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
                create_random_table(&player2); //CREATE RANDOM TABLE PLAYER(AI) №2
                create_enemy_print_table(&player1);
                while(sh_player1.all_sell != 0 || sh_player2.all_sell != 0)     //SHOOT
                {
                    system("clear");
                    cout << "YOU TABLE: " << endl;
                    print_table(&player1, 0); 
                    cout << "ENEMY TABLE: " << endl;
                    print_table(&player1, 1);
                    shoot(&player1, &player2, &sh_player2, 0, 0, 0, 0);     //human
                    shoot(&player1, &player2, &sh_player1, 1, 0, 0, 0);     //bot
                }
                break;
            
    }
    


    cout << "TABLE PLAYER 1: " << endl;
    print_table(&player1, 0);

    cout << "RANDOM TABLE PLAYER №: 2" << endl;
    create_random_table(&player2);
    print_table(&player2, 0);


}

