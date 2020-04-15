/* ############################################ */
/* ###| By: Melnik Atrhur <molluk@mail.ru> |### */
/* ###|   Created: 2020-04-10 13:55:33     |### */
/* ############################################ */

#include <iostream>
#include <cstdlib>  //random
#include <ctime>    //time for random

using namespace std;

struct  Date
{
    int day;
    int month;
    int year;
};

Date*   create_array(int array_size);       //create array and allocate memory for it
void    print_array(const Date *array, int array_size);        //print array
void    push_item_back(Date **array, int &array_size, Date new_element);       //add item back
Date*   del_item_back(Date **array, int &array_size);        //delele last add item
void    delete_array(Date *array);

int     main()
{
    int dates_count;

    //create start array
    cout << "Enter dates: ";
    cin >> dates_count;

    Date *dates = create_array(dates_count);   

    srand(time(NULL));
    for(int i = 0; i < dates_count; i++)
    {
        dates[i].day = 1 + rand() % 30;
        dates[i].month = 1 + rand() % 12;
        dates[i].year = 1939 + rand() % 2022;
    }

    print_array(dates, dates_count);    


    return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
Date*     create_array(int dates_count)
{
    int *dates = new int [dates_count];   //memory allocation
}

///////////////////////////////////////////////////////////////////////////////////////////////////
void    print_array(int *dates, int dates_count)
{
    for(int i = 0; i < dates_count; i++)
        cout << "dates[" << i << "]" << " = " << dates[i] << endl;
}
///////////////////////////////////////////////////////////////////////////////////////////////////