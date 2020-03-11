/* Declare any non-required functions above main.
 * The duty of main here is to interact with the user, take in input, and manage wrapping output and runtime.
 * Remember, if you are considering putting something in main or a function, double check the specifications.
 * Each function should only do what it is specified to do, and no more.
 */

#include "maze.h"

int main()
{
    string dummy;
    int rows = 1, mapNum = 0;
    while (rows != 0)
    {
        int row, col;
        cin >> rows;
        if (rows == 0)
        {
            break;
        }

        getline(cin, dummy);

        string *mat = build_matrix(rows);
        fill_matrix(mat, rows);
        find_start(mat, rows, row, col);

        if (find_exit(mat, row, col))
        {
            cout << "Map " << mapNum << " -- Solution found:" << endl;
        }
        else
        {
            cout << "Map " << mapNum << " -- No solution found:" << endl;
        }

        mapNum++;
        print_matrix(mat, rows);
        cout << endl;
        delete_matrix(mat);
    }

    return 0;
}
