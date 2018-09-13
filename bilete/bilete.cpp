#include <cstdio>
#include <cstring>
using namespace std;

FILE * is = fopen("bilete.in", "r");
FILE * os = fopen("bilete.out", "w");

int n, k;

void Solve1();
void Solve2();
void Solve3();

int main()
{
    fscanf(is, "%i%i", &n, &k);
    if (k == 1) Solve1();
    if (k == 2) Solve2();
    if (k == 3) Solve3();
    fclose(os);
    fclose(is);
}

void Solve1()
{
    bool D[10][10];
    memset(D, 0, sizeof(D));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (D[i][j] == 0 && D[i][n-j+1] == 0)
            {
                D[i][j] = D[i][n-j+1] = 1;
                fprintf(os, "%i%i\n", i, j);
            }
};

void Solve2()
{
    bool D[10][10][10][10];
    memset(D, 0, sizeof(D));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            for (int ii = 1; ii <= n; ++ii)
                for (int jj = 1; jj <= n; ++jj)
                {
                    if (ii == i && jj == j);
                    else
                        if (D[i][j][ii][jj] == 0 && D[i][n-j+1][ii][n-jj+1] == 0)
                        {
                            D[i][j][ii][jj] = D[i][n-j+1][ii][n-jj+1] = D[ii][jj][i][j] = 1;
                            fprintf(os, "%i%i%i%i\n", i, j, ii, jj);
                        }

                }
};

void Solve3()
{
    bool D[9][9][9][9][9][9];
    memset(D, 0, sizeof(D));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            for (int ii = 0; ii < n; ++ii)
                for (int jj = 0; jj < n; ++jj)
                    for (int iii = 0; iii < n; ++iii)
                        for (int jjj = 0; jjj < n; ++jjj)
                        {
                            if ((i == ii && jj == j) || (iii == ii && jjj == jj) || (i == iii && j == jjj));
                            else
                            {
                                if (D[i][j][ii][jj][iii][jjj] == 0 &&  D[i][n-j-1][ii][n-jj-1][iii][n-jjj-1] == 0)
                                {
                                    D[i][n-j-1][ii][n-jj-1][iii][n-jjj-1] = 1;
                                    D[i][j][ii][jj][iii][jjj] = 1;
                                    D[i][j][iii][jjj][ii][jj] = 1;
                                    D[ii][jj][i][j][iii][jjj] = 1;
                                    D[iii][jjj][i][j][ii][jj] = 1;
                                    D[iii][jjj][ii][jj][i][j] = 1;
                                    D[ii][jj][iii][jjj][i][j] = 1;
                                    fprintf(os, "%i%i%i%i%i%i\n", i+1, j+1, ii+1, jj+1, iii+1, jjj+1);
                                }
                            }
                        }
};
