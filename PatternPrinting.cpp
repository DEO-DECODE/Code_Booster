#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int numCol = (n + 2) + n / 2 + 1;
    vector<vector<string>> patterns(n, vector<string>(numCol, " "));
    for (int row = 0; row < n; ++row)
    {
        patterns[row][0] = "*";
    }
    for (int col = 0; col < n + 2; ++col)
    {
        patterns[n / 2][col] = "*";
    }
    int startColumn = n + 2, startRow = n / 2;
    int tempCol = startColumn, tempRow = startRow;
    while (tempCol < numCol && tempRow >= 0)
    {
        /* code */
        for (int col = tempCol; col < numCol; ++col)
        {
            patterns[tempRow][col] = "@";
        }
        tempCol++;
        tempRow--;
    }
    tempCol = startColumn, tempRow = startRow;
    while (tempCol < numCol && tempRow < n)
    {
        /* code */
        for (int col = tempCol; col < numCol; ++col)
        {
            patterns[tempRow][col] = "@";
        }
        tempCol++;
        tempRow++;
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < numCol; ++j)
        {
            cout << patterns[i][j] << " ";
        }
        cout << endl;
    }
}
