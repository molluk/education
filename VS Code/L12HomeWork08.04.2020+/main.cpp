/* ############################################ */
/* ###| By: Melnik Atrhur <molluk@mail.ru> |### */
/* ###|   Created: 2020-04-10 13:55:33     |### */
/* ############################################ */

#include <iostream>
#include <cstdlib>  //random
#include <ctime>    //time for random
#include "dynarray.h"

using namespace std;

void    delete_array(int *array);

int     main()
{
    int array_size, new_element; 
    int pos_hum, new_value;

    //create start array
    cout << "Enter array size: ";
    cin >> array_size;
    int *array = create_array(array_size);   
    array_filled_with_random_values(array, array_size, 0);  
    print_array(array, array_size);    

    //add new elements
    cout << "How many elements to add: ";
    cin >> new_element;
    push_item_back(array, &array_size, new_element);     
    array_filled_with_random_values(array, array_size, new_element);    
    print_array(array, array_size);

    //del last add item
    cout << "Del last add item: " << endl;
    del_item_back(array, &array_size, new_element);
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
    print_array(array, array_size);

    //remove item to specific location
    cout << "The item under which number you want to delete: ";
    cin >> pos_hum;
    remove_item_to_specific_location(&array, array_size, pos_hum);
    print_array(array, array_size);

    //array sorting
    cout << "ARRAY SORT :" << endl;
    sort_array(array, array_size);
    print_array(array, array_size);

    //search for an element in an array by its value
    cout << "Enter a value to find an array element: " << endl;
    cin >> new_element;
    if(search_item(array, array_size, new_element) == 0) 
        cout << "The value you entered: " << new_element << ", is not in the array" << endl;

    cout << "Elements left after removal: " << endl;
    print_array(array, array_size);
    delete_array(array);   //delete array

    return 0;
}
