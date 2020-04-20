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
    string name;
    string author;
    string publishing_house;
    string genre;
};

#include "funct.h"
#include "the_functions.cpp"

int     main()
{
    setlocale(LC_ALL, "Russian");
    int num;
    srand(time(NULL));

    cout << "Enter the number of books: ";
    cin >> num;

    Book book_list[num];

    for(int i = 0; i < num; i++)
    {
        book_list[i].name = random_book_name((0 + rand() % 49));
        book_list[i].author = random_author((0 + rand() % 24), (1 + rand() % 2));
        book_list[i].publishing_house = random_publishing_house((0 + rand() % 30));
        book_list[i].genre = random_genre((0 + rand() % 22));
        cout << i << ") ";
        cout << "Book name: " << book_list[i].name << "; ";
        cout << "Author: " << book_list[i].author << "; ";
        cout << "Publishing_house: " << book_list[i].publishing_house << "; ";
        cout << "Genre: " << book_list[i].genre << ";" << endl;
    }


    return 0;
}
