#include <cstdio>
using namespace std;

int nr, vmax=0, v[6000], nc=0;
int a[120][120];
int x, y;
FILE *f;

void Fill();
int Suma(int i, int j);

int main()
{
    int i, j, n, m;
    char ch;
    f = fopen("vila.in", "r");
    fscanf (f, "%d %d\n", &n, &m);
    for (i = 0; i <= n+1; i++)
        for (j = 0; j <= m+1; j++)
            a[i][j] = 0;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            fscanf (f, "%c", &ch);
            if (ch == '1')
                a[i][j] = 0;
            else
                a[i][j] = -1;
        }
        fscanf(f,"\n");}
    fclose(f);
    v[0] = 0;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            if (a[i][j] == -1)
            {
                nc++;
                nr = 0;
                x = i;
                y = j;
                Fill();
                if (nr > vmax)
                    vmax = nr;
                v[nc] = nr;
            }
    f = fopen("vila.out", "w");
    fprintf (f , "%d\n", nc);
    fprintf (f , "%d\n", vmax);
    vmax = 0;
    int sx, sy;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            if (a[i][j] == 0)
                if (Suma(i, j) > vmax)
                {
                    vmax = Suma(i, j);
                    sx = i;
                    sy = j;
                }
    fprintf(f, "%d %d %d\n", sx, sy, vmax);
    fclose(f);
}

void Fill()
{
    if (a[x][y] != -1)
        return;
    nr++;
    a[x][y]=nc;
    x++;Fill();x--;
    x--;Fill();x++;
    y++;Fill();y--;
    y--;Fill();y++;
};

int Suma(int i, int j)
{
    int s = 0;
    s += v[a[i-1][j]];
    if (a[i+1][j] != a[i-1][j])
        s += v[a[i+1][j]];
    if ( (a[i][j-1] != a[i-1][j]) && (a[i][j-1] != a[i+1][j]) )
        s += v[a[i][j-1]];
    if ( (a[i][j+1] != a[i-1][j]) && (a[i][j+1] != a[i+1][j]) && (a[i][j+1] != a[i][j-1]) )
        s += v[a[i][j+1]];
    s++;
    return s;
};
