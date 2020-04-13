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
void    add_item_to_specific_location(int **array, int &array_size, int new_value, int pos_hum);
int     del_item_back(int *array, int *array_size, int new_element);
void    delete_array(int *array);

int     main()
{
    int array_size, new_element; 
    int pos_hum, new_value;

    //create start array
    cout << "Enter array size: ";
    cin >> array_size;
    int *array = create_array(array_size);   //create array and allocate memory for it
    array_filled_with_random_values(array, array_size, 0);  //fill the array with random values
    print_array(array, array_size);    //print array

    //add new elements
    cout << "How many elements to add: ";
    cin >> new_element;
    push_item_back(array, &array_size, new_element);     //add item back
    array_filled_with_random_values(array, array_size, new_element);
    print_array(array, array_size);

    //add item to specific location
    cout << "What position do you want to insert the element: ";
    cin >> pos_hum;
    cout << "Enter a value: ";
    cin >> new_value;
    if (pos_hum <= array_size && pos_hum >= 0)
        add_item_to_specific_location(&array, array_size, new_value, pos_hum);
    else
        cout << "Error" << endl;
    cout << "new array_size: " << array_size << endl;
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
//????????????????????????????????????????????????????????????????????????????????????????????????
void    add_item_to_specific_location(int **array, int &array_size, int new_value, int pos_hum)
{
    *array = new int [array_size + 1];
    array_size = array_size + 1;

    for(int i = array_size - 1; i >= pos_hum; i--)
    {
        cout << "6ilo -> array["<< i << "]" << array[i] << endl;
        if(i > pos_hum) 
            array[i] = array[i - 1];
        else 
        {
            array[i] = array[i - 1];
            array[i - 1] = new_value;       //???????????/
            cout << "Stalo -> array["<< i << "- 1] = &new_value: " << array[i - 1] << endl;
        }
        cout << "Stalo -> array["<< i << "]" << array[i] << endl;
    }
    //cout << "**array: " << **array << endl;     //показывает содержимое 0 элемента по адресу

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