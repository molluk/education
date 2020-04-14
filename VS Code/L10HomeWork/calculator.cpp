/* ############################################ */
/* ###| By: Melnik Atrhur <molluk@mail.ru> |### */
/* ###|   Created: 2020-04-05 15:52:59     |### */
/* ############################################ */

#include <unistd>

#include <iostream>

using namespace std;

int mul(int x, int y){return x*y;}
int add(int x, int y){return x+y;}
int sub(int x, int y){return x-y;}
int del(int x, int y){return x/y;}

using Mathfunc = int(*)(int, int);

int     main() 
{
    Mathfunc oper[] {mul, add, sub, del};
    int x, y, i = 0;
    char sim;
    char mth[4] = {'*', '+', '-', '/'};

    cout << "Insert equation: " << endl;
    cin >> x >> sim >> y;

    cout << x << sim << y << "=";
    while(sim != mth[i])
        i++;
    cout << oper[i](x, y) << endl;
}
////////////////////////////////////////////////////////////////////
/*
    while(sim == '+')
    {
        cout << add(x, y, sim) << endl;
        break;
    }
    while(sim == '-')
    {
        cout << sub(x, y, sim) << endl;
        break;
    }
        while(sim == '*')
    {
        cout << mul(x, y, sim) << endl;
        break;
    }
    while(sim == '/')
    {
        cout << del(x, y, sim) << endl;
        break;
    }
    */