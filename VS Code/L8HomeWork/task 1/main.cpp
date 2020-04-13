/* ########################################## */
/* ###|By: Melnik Atrhur <molluk@mail.ru>|### */
/* ###|                                  |### */
/* ###|   Created: 2020-03-03 13:22:53   |### */
/* ########################################## */

#include <iostream>
#include <stdio.h>
#include <unistd.h> 
#include <cstdlib>
#include <string>

using namespace std;

int     character_check(string num);
int     conversion(int num, int syst);

int     main()
{
    Number:
    int num, syst;
    string  number, num_system;

    cout << "Paste you number: ";
    cin >> number;
    if (character_check(number) == 0)
    {
        sleep(1);
        goto Number; 
    }

    Num_system:
    cout << "Indicate the required number system it is 2 to 36: ";
    cin >> num_system;
    if (character_check(num_system) == 0 || stoi(num_system) <= 1 || stoi(num_system) >= 37)
    {
        cout << "Error" << endl;
        system("clear");
        goto Num_system; 
    }
    cout << "Your value : " << number << ", in the number system: " << num_system << ", will look like this: ";
    num = stoi(number);     //convert string in int
    syst = stoi(num_system);    //convert string in int
    conversion(num, syst);
    
    return 0;
}

int     character_check(string num)
{
    int i;

    i = 0;
    while(num[i] != '\0')
    {
        if(num[i] >= '0' && num[i] <= '9')
            i++;
        else 
        {
            cout << "Error, you inserted an invalid character: " << num[i] << "\n";
            return 0;
        }
    }
    return 1;
}

int         conversion(int num, int syst)
{
    int     i;
    int     sum[i];
    char    sim[i];

    i = 1;
    while(num != 0)
    {
        sum[i] = num - ((num / syst) * syst);
        if(sum[i] >= 10 && syst >= 16)
            sim[i] = (sum[i] - 10) + 65;
        num = num / syst;
        i++;
    }
    i--;
    while(i != 0)
    {
        if(sum[i] >= 0 && sum[i] <= 9)
            cout << sum[i--];
        else
            cout << sim[i--];
    }
    cout << "\n";
    return 0;
}