/* ########################################## */
/* ###|By: Melnik Atrhur <molluk@mail.ru>|### */
/* ###|                                  |### */
/* ###|   Created: 2020-03-15 15:21:04   |### */
/* ########################################## */

#include <iostream>
#include <stdlib.h>     //system("cls")

using namespace std;

int    insert_values(int mass_size);
int     check(int num);

int     main()
{
    int mass_size; 

    cout << "Specify the size of the array: ";
    cin >> mass_size;

    if(check(mass_size) == 0)
        return 0;
    insert_values(mass_size);     
    return 0;
}

int     check(int num)
{
    char x;
    while (num != 0)
    {
        x = num % 10;
        if (x < 0 || x > 9)
            return 0;
        num /= 10;
    }
    return 1;
}

int     insert_values(int mass_size)
{
    int mass[mass_size];
    int sort, save;
    for(int i = 0; i < mass_size; i++)
    {
        cout << "Enter the values you want to sort: ";
        cin >> mass[i];
        check(mass[i]);
        system("clear");
    }
    cout << "Sorting options: \n\t1) in descending order; \n\t2)  ascending;" << endl;
    cout << "Sort array by option №: ";
    cin >> sort;
    if(sort < 1 || sort > 2 || check(sort) == 0)
        return 0;
    switch(sort)
    {
        case 1: for(int j = 0; j < mass_size; j++)
                {
                    while(mass[j] < mass[++j])
                    {
                        save = mass[++j];
                        mass[++j] = mass[j];
                        mass[j] = save;
                    }
                }
        case 2: for(int j = 0; j < mass_size; j++)
                {

                }
    }
    for(int i = 0; i < mass_size; i++)
        cout << mass[i] << " ";
    cout << endl;
    return 0;
}

