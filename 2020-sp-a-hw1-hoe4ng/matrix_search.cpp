/**
Here in the .cpp you should define and implement the functions that are declared in the .h file.
It is not recommended to add extra functions on this assignment.
**/

#include "matrix_search.h"

// We're giving you this one the first time, and you should copy it into all future assignments.
// Change the information to your own email handle (S&T username)
void get_identity(string &my_id)
{
  my_id = "hoe4ng";
}

char **build_matrix(int rows, int cols)
{
  char **matrix = new char *[rows];
  for (int i = 0; i < rows; i++)
  {
    matrix[i] = new char[cols];
  }
  return matrix;
}

void fill_matrix(int rows, int cols, char **matrix)
{
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      cin >> matrix[i][j];
    }
  }
}

void print_matrix(int rows, int cols, char **matrix)
{
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
}

void delete_matrix(int rows, char **matrix)
{
  for (int i = 0; i < rows; i++)
  {
    delete matrix[i];
  }
  delete matrix;
}

void matrix_search(int sol[], string word, int rows, int cols, char **matrix)
{
  int wordLen = word.length() - 1;
  bool found = false;

  if (!(wordLen + 1 > rows && wordLen + 1 > cols))
  {
    for (int i = 0; i < rows; i++)
    {
      for (int j = 0; j < cols; j++)
      {
        if (word[0] == matrix[i][j])
        {
          string temp = "";

          // Up
          if (i - wordLen >= 0 && matrix[i - wordLen][j] == word[wordLen])
          {
            for (int k = i; k > i - wordLen - 1; k--)
            {
              temp += matrix[k][j];
            }

            if (!temp.compare(0, wordLen + 1, word))
            {
              found = true;
              sol[0] = i;
              sol[1] = j;
              sol[2] = i - wordLen;
              sol[3] = j;
            }
          }

          // Down
          if (i + wordLen < rows && matrix[i + wordLen][j] == word[wordLen])
          {
            temp = "";

            for (int k = i; k <= i + wordLen; k++)
            {
              temp += matrix[k][j];
            }

            if (!temp.compare(0, wordLen + 1, word))
            {
              found = true;
              sol[0] = i;
              sol[1] = j;
              sol[2] = i + wordLen;
              sol[3] = j;
            }
          }

          // Right
          if (j + wordLen < cols && matrix[i][j + wordLen] == word[wordLen])
          {
            temp = "";

            for (int k = j; k <= j + wordLen; k++)
            {
              temp += matrix[i][k];
            }

            if (!temp.compare(0, wordLen + 1, word))
            {
              found = true;
              sol[0] = i;
              sol[1] = j;
              sol[2] = i;
              sol[3] = j + wordLen;
            }
          }

          // Left
          if (j - wordLen >= 0 && matrix[i][j - wordLen] == word[wordLen])
          {
            temp = "";

            for (int k = j; k >= j - wordLen; k--)
            {
              temp += matrix[i][k];
            }

            if (!temp.compare(0, wordLen + 1, word))
            {
              found = true;
              sol[0] = i;
              sol[1] = j;
              sol[2] = i;
              sol[3] = j - wordLen;
            }
          }

          // Top Right
          if ((i - wordLen >= 0 && matrix[i - wordLen][j + wordLen] == word[wordLen]) && (j + wordLen < cols && matrix[i - wordLen][j + wordLen] == word[wordLen]))
          {
            temp = "";

            int tempCount = j;
            for (int k = i; k > i - wordLen - 1; k--)
            {
              temp += matrix[k][tempCount++];
            }

            if (!temp.compare(0, wordLen + 1, word))
            {
              found = true;
              sol[0] = i;
              sol[1] = j;
              sol[2] = i - wordLen;
              sol[3] = j + wordLen;
            }
          }

          // Bottom Right
          if ((i + wordLen < rows && matrix[i + wordLen][j + wordLen] == word[wordLen]) && (j + wordLen < cols && matrix[i + wordLen][j + wordLen] == word[wordLen]))
          {
            temp = "";

            int tempCount = j;
            for (int k = i; k <= rows - wordLen; k++)
            {
              temp += matrix[k][tempCount++];
            }

            if (!temp.compare(0, wordLen + 1, word))
            {
              found = true;
              sol[0] = i;
              sol[1] = j;
              sol[2] = i + wordLen;
              sol[3] = j + wordLen;
            }
          }

          // Top Left
          if ((i - wordLen >= 0 && matrix[i - wordLen][j - wordLen] == word[wordLen]) && (j - wordLen >= 0 && matrix[i - wordLen][j - wordLen] == word[wordLen]))
          {
            temp = "";

            int tempCount = j;
            for (int k = i; k >= 0; k--)
            {
              temp += matrix[k][tempCount--];
            }

            if (!temp.compare(0, wordLen + 1, word))
            {
              found = true;
              sol[0] = i;
              sol[1] = j;
              sol[2] = i - wordLen;
              sol[3] = j - wordLen;
            }
          }

          // Bottom Left
          if ((i + wordLen < rows && matrix[i + wordLen][j - wordLen] == word[wordLen]) && (j - wordLen >= 0 && matrix[i + wordLen][j - wordLen] == word[wordLen]))
          {
            temp = "";

            int tempCount = j;
            for (int k = i; k < rows - wordLen; k++)
            {
              temp += matrix[k][tempCount--];
            }
            cout << "Temp: " << temp << endl;
            if (!temp.compare(0, wordLen + 1, word))
            {
              found = true;
              sol[0] = i;
              sol[1] = j;
              sol[2] = i + wordLen;
              sol[3] = j - wordLen;
            }
          }

          if (found)
          {
            break;
          }
        }
      }
      if (found)
      {
        break;
      }
    }
  }
}