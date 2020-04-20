#ifndef DYNARRAY_H
#define DYNARRAY_H

    int*    create_array(int array_size);       //create array and allocate memory for it
    void    array_filled_with_random_values(int *array, int array_size, int pos);       //fill the array with random values
    void    print_array(int *array, int array_size);        //print array
    void    push_item_back(int *array, int *array_size, int new_element);       //add item back
    void    add_item_to_specific_location(int **array, int &array_size, int new_value, int pos_hum);        //add item to specific location
    void    remove_item_to_specific_location(int **array, int &array_size, int pos_hum);        //remove item to specific location
    void    sort_array(int *array, int array_size);     //array sorting
    int     search_item(const int *array, int array_size, int new_element);        //search for an element in an array by its value
    int     del_item_back(int *array, int *array_size, int new_element);        //delele last add item

#endif