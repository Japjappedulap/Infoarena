#include <fstream>
using namespace std;

ifstream is ("noname.in");

int N, x;
short P1[1005], P2[1005];
short p1[1005], p2[1005];
char M[1005][1005];

int main()
{
    is >> N;
    for (int i = 1; i <= N; ++i)
        is >> P1[i], p1[P1[i]] = i;
    for (int i = 1; i <= N; ++i)
        is >> P2[i], p2[P2[i]] = i;
    for (int i = 1, j = N, k = 1; k <= N; ++k)
        if (k % 2 == 1)
            P1[k] = p1[j--];
        else
            P1[k] = p1[i++];
    for (int i = 1, j = N, k = 1; k <= N; ++k)
        if (k % 2 == 1)
            P2[k] = p2[j--];
        else
            P2[k] = p2[i++];
    for (int i = 1; i <= N; ++i)
        if (i % 2 == 1)
        {
            for (int j = 1; j <= N; ++j)
                if (M[P1[i]][j] == 0) M[P1[i]][j] = '2';
            for (int j = 1; j <= N; ++j)
                if (M[j][P2[i]] == 0) M[j][P2[i]] = '2';
        }
        else
        {
            for (int j = 1; j <= N; ++j)
                if (M[P1[i]][j] == 0) M[P1[i]][j] = '1';
            for (int j = 1; j <= N; ++j)
                if (M[j][P2[i]] == 0) M[j][P2[i]] = '1';
        }
    freopen("noname.out","w",stdout);
    printf("1\n");
    for ( int i = 1; i <= N; ++i )
    {
        for ( int j = 1; j <= N; ++j )
            printf("%c ", char(M[i][j]-1));
        printf("\n");
    }
    is.close();
}
