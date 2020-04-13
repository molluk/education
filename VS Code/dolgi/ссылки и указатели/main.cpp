/* ############################################ */
/* ###| By: Melnik Atrhur <molluk@mail.ru> |### */
/* ###|   Created: 2020-04-10 13:55:33     |### */
/* ############################################ */

#include <iostream>
#include <cstdlib>  //random
#include <ctime>    //time for random

using namespace std;

int*    create_array(int array_size);
void    array_filled_with_random_values(int *array, int array_size, int pos);
void    print_array(int *array, int array_size);
void    push_item_back(int *array, int *array_size, int new_element);
int     del_item_back(int *array, int *array_size, int new_element);
void    delete_array(int *array);

int     main()
{
    int array_size;
    int new_element; 

    cout << "Enter array size: ";
    cin >> array_size;

    int *array = create_array(array_size);   //create array and allocate memory for it
    array_filled_with_random_values(array, array_size, 0);  //fill the array with random values
    print_array(array, array_size);    //print array
    
    cout << "How many elements to add: ";
    cin >> new_element;

    push_item_back(array, &array_size, new_element);     //add item back
    array_filled_with_random_values(array, array_size, array_size);
    print_array(array, array_size);
    del_item_back(array, &array_size, new_element);  //delete back item

    cout << "Elements left after removal: " << endl;

    print_array(array, array_size);
    delete_array(array);   //delete array

    return 0;
}

int*     create_array(int array_size)
{
    int *array = new int [array_size];   //memory allocation
    return array;
}

void    array_filled_with_random_values(int *array, int array_size, int pos)
{
    srand(static_cast <unsigned int> (time(0)));

    int min = 0, max = 100;     //range of random digits from min to max

    if(pos == 0)
        for(int i = pos; i < array_size; i++)
            array[i] = rand()%(max - min) + min;
    else
        for(int i = pos; i <= array_size; i++)
            array[i] = rand()%(max - min) + min;
}

void    print_array(int *array, int array_size)
{
    for(int i = 0; i < array_size; i++)
        cout << "array[" << i << "]" << " = " << array[i] << endl;
}

void    push_item_back(int *array, int *array_size, int new_element)
{
    array = new int [*array_size + new_element]; 
    *array_size = *array_size + new_element;    
}

int     del_item_back(int *array, int *array_size, int new_element)
{
    array = new int [*array_size - new_element]; 
    *array_size = *array_size - new_element;
}

void    delete_array(int *array)
{
    delete [] array;
    array = nullptr;
}

