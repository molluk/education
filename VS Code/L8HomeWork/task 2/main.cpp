/* ########################################## */
/* ###|By: Melnik Atrhur <molluk@mail.ru>|### */
/* ###|                                  |### */
/* ###|   Created: 2020-03-11 22:56:09   |### */
/* ########################################## */

#include <iostream>
#include <stdlib.h>
#include <unistd.h>       //sleep

using namespace std;

int        drop();

int         main() 
{
    int sum1 = 0;
    int sum2 = 0;
    int s;
    int player_num;

    choose_player:
    cout << "Choose who walks first: \n\t1)Human;\n\t2)Computer;" << endl;
    cin >> player_num;
    if(player_num < 1 || player_num > 2)
    {
        system("clear");
        goto choose_player;
    }
    for(int i = 10; i > 0; i--)
    {
        s = 0;
        if(player_num % 2)
        {
            s = drop() + drop();
            sum1 += s;
            cout << "Throws human: " << s << endl;
        }
        else
        {
            s = drop() + drop();
            sum2 += s;
            cout << "Throws a computer: " << s << endl;
        }
        player_num++;
    }
    if(sum1 > sum2)
        cout << "Human Win: " << sum1 << endl;
    else if (sum1 == sum2)
        cout << "Draw. Human: " << sum1 << "Computer: " << sum2 << endl;
    else
        cout << "Computer Win: " << sum2 << endl;

    cout << "Average score Human: " << (sum1 / 5) << endl;
    cout << "Average score Computer: " << (sum2 / 5) << endl;
    return 0;
}

int        drop()
{
    sleep (1);
    srand(time(0));
    return (1 + rand() % 6);
}
