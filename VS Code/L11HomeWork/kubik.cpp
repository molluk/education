/* ############################################ */
/* ###| By: Melnik Atrhur <molluk@mail.ru> |### */
/* ###|   Created: 2020-04-04 18:51:33     |### */
/* ############################################ */

#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

struct  Player
{
    int id;        //player number
    vector <int> drop;      //throw number
    int score = 0;          //total points
};

void    player_number(int num, int drop);
void    output(Player *pl, int num, int drop);

int     main()
{
    int drop, num;

    cout << "Enter the number of players: ";
    cin >> num;

    cout << "Enter the number of throws: ";
    cin >> drop;

    player_number(num, drop);

    return 0;
}

void    player_number(int num, int drop)
{
    Player pl[num];
    int save;

    for(int i = 0; i < num; i++)
    {
        pl[i].id = i;
        for(int d = 0; d < drop; d++)
        {
            pl[i].drop.push_back(rand() % (6 - 1) + 1);
            pl[i].score += pl[i].drop[d];
        }
    }
    //Sort Ascending
    for(int i = 0; i < num; i++)
    {
        for(int x = 0; x < num; x++)
        {
            if(pl[i].score < pl[x].score)
            {
                save = pl[i].id;
                pl[i].id = pl[x].id;
                pl[x].id = save;

                save = pl[i].score;
                pl[i].score = pl[x].score;
                pl[x].score = save;

                for(int d = 0; d < drop; d++)
                {
                    save = pl[i].drop[d];
                    pl[i].drop[d] = pl[x].drop[d];
                    pl[x].drop[d] = save;
                }
            }
        }
    }
    output(pl, num, drop);
}

void    output(Player *pl, int num, int drop)
{
    int out;

    cout << "\nDisplay of data: "<< endl;
    cout << "\t\t1)About the winner;\n\t\t2)Data on all players" << endl;
    cin >> out;
    
    switch(out)
    {
        case 1: cout << "Player № " << pl[num-1].id << " WINNER!" << endl;
                cout << "Score: " << pl[num-1].score << endl;
                break;
        case 2: for(int i = num - 1; i >= 0; i--)
                {
                    if(i == num - 1)
                        cout << "Player № " << pl[num-1].id << " winner!" << endl;
                    else 
                        cout << "Player № " << pl[i].id << endl;
                    cout << "Score: ";
                    for(int d = 0; d < drop; d++)
                        cout << pl[i].drop[d] << " | ";
                    cout << "Total: " << pl[i].score << endl;
                }   
    }
}
