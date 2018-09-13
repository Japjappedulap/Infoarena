#include <fstream>
#include <cstdio>
using namespace std;

FILE * is = fopen("custi.in", "r");
FILE * os = fopen("custi.out", "w");

bool a[1001][1001];
int n, v[1004], x;
int dp[1001][1001];

void Solve();

int main()
{
    Solve();
    for (int i = n; i > 0; i--)
        v[i] += v[i+1];
    for (int it = 1; it <= n; ++it)
        fprintf(os, "%i \n", v[it]);
    fclose(is);
    fclose(os);
    return 0;
}

void Solve()
{
    fscanf(is,"%i", &n);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
        {
            fscanf(is, "%i", &a[i][j]);
            if (i == 1 && a[i][j] == 1) dp[i][j] = 1, v[1]++;
            if (j == 1 && a[i][j] == 1) dp[i][j] = 1, v[1]++;
            if (i >= 2 && j >= 2 && a[i][j] == 1)
            {
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]);
                if (a[i-dp[i][j]][j-dp[i][j]] == 1)
                    dp[i][j]++;
                v[dp[i][j]]++;
            }
        }
    if (a[1][1] == 1) v[1]--;
};
