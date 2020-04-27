/* ########################################## */
/* ###|By: Melnik Atrhur <molluk@mail.ru>|### */
/* ###|                                  |### */
/* ###|   Created: 2020-04-18 16:25:52   |### */
/* ########################################## */
#pragma once

#include <iostream>

using namespace std;

struct  Book_libr
{
    string name;
    string author;
    string publishing_house;
    string genre;
};

/*
extern string book_name[]; 
extern string book_name_last[];
extern string author_man_name[];
extern string author_man_last_name[];
extern string author_woman_name[];
extern string author_woman_last_name[];
extern string publishing_house[];
extern string genre[];
*/

void    cout_book(int book_list, int num);
