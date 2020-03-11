/* Here in the .cpp you should define and implement everything declared in the .h file.
 */

#include "maze.h"

void get_identity(string &my_id)
{
    my_id = "hoe4ng";
}

string *build_matrix(int rows)
{
    string *matrix = new string[rows];
    return matrix;
}

void fill_matrix(string *matrix, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        getline(cin, matrix[i]);
    }
}

void print_matrix(string *matrix, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        cout << matrix[i] << endl;
    }
}

void delete_matrix(string *&matrix)
{
    delete[] matrix;
    matrix = nullptr;
}

void find_start(string *matrix, int rows, int &row, int &col)
{
    for (int i = 0; i < rows; i++)
    {
        int len = matrix[i].length();
        for (int j = 0; j < len; j++)
        {
            if (matrix[i][j] == 'N')
            {
                row = i;
                col = j;
                break;
            }
        }
    }
}

bool find_exit(string *matrix, int row, int col)
{
    if (at_end(matrix, row, col))
    {
        return true;
    }

    if (matrix[row][col] == ' ')
    {
        matrix[row][col] = '@';
    }

    // NORTH
    if (valid_move(matrix, row, col, "NORTH"))
    {
        if (find_exit(matrix, row - 1, col))
        {
            return true;
        }
    }

    // East
    if (valid_move(matrix, row, col, "EAST"))
    {
        if (find_exit(matrix, row, col + 1))
        {
            return true;
        }
    }

    // SOUTH
    if (valid_move(matrix, row, col, "SOUTH"))
    {
        if (find_exit(matrix, row + 1, col))
        {
            return true;
        }
    }

    // WEST
    if (valid_move(matrix, row, col, "WEST"))
    {
        if (find_exit(matrix, row, col - 1))
        {
            return true;
        }
    }

    if (matrix[row][col] == '@')
    {
        matrix[row][col] = ' ';
    }

    return false;
}

bool at_end(string *matrix, int row, int col)
{
    return matrix[row][col] == 'E';
}

bool valid_move(string *matrix, int row, int col, string direction)
{
    if (direction.compare("NORTH") == 0)
    {
        if (matrix[row - 1][col] == ' ' || matrix[row - 1][col] == 'E')
        {
            return true;
        }
    }

    else if (direction.compare("SOUTH") == 0)
    {
        if (matrix[row + 1][col] == ' ' || matrix[row + 1][col] == 'E')
        {
            return true;
        }
    }

    else if (direction.compare("EAST") == 0)
    {
        if (matrix[row][col + 1] == ' ' || matrix[row][col + 1] == 'E')
        {
            return true;
        }
    }

    else if (direction.compare("WEST") == 0)
    {
        if (matrix[row][col - 1] == ' ' || matrix[row][col - 1] == 'E')
        {
            return true;
        }
    }

    return false;
}
