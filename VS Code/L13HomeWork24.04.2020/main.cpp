/* ########################################## */
/* ###|By: Melnik Atrhur <molluk@mail.ru>|### */
/* ###|                                  |### */
/* ###|   Created: 2020-04-18 15:13:14   |### */
/* ########################################## */

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

struct  Book
{
    int name;
    int author;
    int publishing_house;
    int genre;
};

#include "funct.h"
#include "book_params.cpp"
#include "the_functions.cpp"

int     main()
{
    int num;
    srand(time(NULL));
    
    cout << "Enter the number of books: ";
    cin >> num;

    Book book_list[num];
 
    for(int i = 0; i < num; i++)
    {
        book_list[i].name = random_name(0 + rand() % 49);
        book_list[i].author = random_author(0 + rand() % 49);
        book_list[i].publishing_house = random_publishing_house(0 + rand() % 49);
        book_list[i].genre = random_genre(0 + rand() % 49);
    }
    
}