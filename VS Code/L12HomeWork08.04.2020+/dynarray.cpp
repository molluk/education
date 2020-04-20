#include <iostream>
#include <cstdlib>  //random
#include <ctime>    //time for random
using namespace std;
///////////////////////////////////////////////////////////////////////////////////////////////////
int*     create_array(int array_size)
{
    int *array = new int [array_size];   //memory allocation
    return array;
}
///////////////////////////////////////////////////////////////////////////////////////////////////
void    array_filled_with_random_values(int *array, int array_size, int pos)
{
    srand(time(NULL));
    int min = 0, max = 100;     //range of random digits from min to max
    
    cout << pos << " " << array_size << endl;
    if(pos == 0)
        for(int i = pos; i < array_size; i++)
            array[i] = min + rand() % max;
    else
        for(int i = (array_size - 1 - pos); i < (array_size + pos); i++)
            array[i] = min + rand() % max;
}
///////////////////////////////////////////////////////////////////////////////////////////////////
void    print_array(int *array, int array_size)
{
    for(int i = 0; i < array_size; i++)
        cout << "array[" << i << "]" << " = " << array[i] << endl;
}
///////////////////////////////////////////////////////////////////////////////////////////////////
void    push_item_back(int *array, int *array_size, int new_element)
{
    array = new int [*array_size + new_element]; 
    *array_size = *array_size + new_element;    
}
///////////////////////////////////////////////////////////////////////////////////////////////////
void    add_item_to_specific_location(int **array, int &array_size, int new_value, int pos_hum)
{
    array_size += 1;
    int *newarray = new int [array_size];
    
    for(int i = 0; i < array_size; i++)
        *(newarray + i) = *(*array + i);
    
    for(int i = array_size - 1; i >= pos_hum; i--)
    {
        if(i > pos_hum)
            *(newarray + i) = *(*array + (i - 1));
        else if(i > 0 && i == pos_hum)
            *(newarray + i) = new_value;       
        else
            *(newarray + i) = new_value;
    }
    delete[] *array;
    *array = newarray;
}
///////////////////////////////////////////////////////////////////////////////////////////////////
void    remove_item_to_specific_location(int **array, int &array_size, int pos_hum)
{
    int *newarray = new int [array_size];
    
    for(int i = 0; i < array_size; i++)
        *(newarray + i) = *(*array + i);
    
    for(int i = pos_hum; i < array_size; i++)
        *(newarray + i) = *(*array + (i + 1));

    delete[] *array;
    *array = newarray;
    array_size -= 1;
}
///////////////////////////////////////////////////////////////////////////////////////////////////
void    sort_array(int *array, int array_size)
{
    int sort, save;
    cout << "Sort an array by: \n\t\t1)Descending; \n\t\t2)Ascending" << endl;
    cin >> sort;
    switch (sort)
    {
        case 1: for(int x = 0; x < array_size; x++)
                {
                    for (int y = 0; y < array_size; y++)
                    {
                        if(array[x] < array[y])
                        {
                            save = array[y];
                            array[y] = array[x];
                            array[x] = save;
                        }
                    }
                }
                break;

        case 2: for(int x = 0; x < array_size; x++)
                {
                    for (int y = 0; y < array_size; y++)
                    {
                        if(array[x] > array[y])
                        {
                            save = array[y];
                            array[y] = array[x];
                            array[x] = save;
                        }
                    }
                }
                break;
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////////
int     search_item(const int *array, int array_size, int new_element)
{
    for(int i = 0; i < array_size; i++)
    {
        if(array[i] == new_element)
        {
            cout << "The entered value: " << new_element << " ,is in the array element: ";
            cout << "array[" << i << "] = " << new_element << endl;
            return 1;
        }
    }
    return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////
int     del_item_back(int *array, int *array_size, int new_element)
{
    array = new int [*array_size - new_element]; 
    *array_size = *array_size - new_element;
    return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////
void    delete_array(int *array)
{
    delete [] array;
    array = nullptr;
}