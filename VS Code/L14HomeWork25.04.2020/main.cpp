/* ########################################## */
/* ###|By: Melnik Arthur <molluk@mail.ru>|### */
/* ###|                                  |### */
/* ###|   Created: 2020-04-27 16:54:03   |### */
/* ########################################## */

#include <iostream>
#include <vector>

using namespace std;

int     plus(int x, int y){return x+y;};
int     minus(int x, int y){return x-y;};
int     myltiply(int x, int y){return x*y;};
int     divide(int x, int y){return x/y;};

int     calc(char **argv, int y);

int     main(int argc, char *argv[])
{

    cout << "pered calc" << argv[1] << endl;

    calc(argv, 0);

    return 0;
}

int     calc(char **argv, int start)
{
    int stop = 0;
    int sum;
    char x1, y1;
    int x = 0, y = 0;
    vector <int> bracket;

    cout << "CALC: " << argv[1] << endl;

    for(int i = start; (i != '(' || i != '\0'); i++)
        if(*argv[i] == '(') calc(argv, i);

    for(int i = start; *argv[i] != ')'; i++)    
    {
        for(int i = start; *argv[i] >= 0 && *argv[i] <= 9; i++) x *= 10 + (int)*argv[i];     //??????????????
        if(*argv[i] == ('*', '/', '\\', '+', '-'))
    }
    
   return 0;
}