/* ############################################ */
/* ###| By: Melnik Atrhur <molluk@mail.ru> |### */
/* ###|   Created: 2020-04-07 22:22:09     |### */
/* ############################################ */

#include <iostream>;
#include <vector>;

using namespace std;

int     isMatrixSymmetric(int *matrix, int size);

int     main()
{
    int size = 100;
    int strok_stolb[size][size];

    cout << "Paste size massiv: ";
    cin >> size;

    for(int i = 1; i <= size; i++)
        if(i > 100) return 0;

    isMatrixSymmetric(*strok_stolb, size);

    return 0;
}

int     isMatrixSymmetric(int *matrix)
{

    for(int x = 0; x < matrix[x]; x++)
    {
        for(int y = 0; y < &matrix[x][y]; y++)
            cin >> matrix[x][y];
    }

    return 0;
}