/**
Implement the main here to match input and output. 
**/

#include "matrix_search.h"

int main()
{
    // Declaration
    int times, arrCount = 0;
    cin >> times;
    string *words = new string[times];
    int **answersArr = new int *[times];
    for (int i = 0; i < times; i++)
    {
        answersArr[i] = new int[4];
    }

    for (int i = 0; i < times; i++)
    {
        int sol[] = {-1, -1, -1, -1};
        int rows, cols;

        cin >> rows >> cols;

        char **mat = build_matrix(rows, cols);
        fill_matrix(rows, cols, mat);

        cin >> words[arrCount];
        matrix_search(sol, words[arrCount], rows, cols, mat);
        delete_matrix(rows, mat);

        for (int j = 0; j < 4; j++)
        {
            answersArr[arrCount][j] = sol[j];
        }

        arrCount++;
    }

    for (int i = 0; i < times; i++)
    {
        cout << "Searching for \"" << words[i] << "\" in matrix " << i << " yields:" << endl;

        if (answersArr[i][0] == -1)
        {
            cout << "The pattern was not found." << endl;
        }
        else
        {
            cout << "Start pos:(" << answersArr[i][0] << ", " << answersArr[i][1] << ") to End pos:(" << answersArr[i][2] << ", " << answersArr[i][3] << ")" << endl;
        }

        cout << endl;
    }

    for (int i = 0; i < times; i++)
    {
        delete[] answersArr[i];
    }
    delete[] answersArr;

    delete[] words;

    return 0;
}
