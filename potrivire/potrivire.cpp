#include <fstream>
#include <vector>
#include <cstring>
#include <cstdlib>
using namespace std;

ifstream is ("potrivire.in");
ofstream os ("potrivire.out");

const int Nmax = 10005;

int N, M;
char T[Nmax], B[Nmax];
char Pattern[31][Nmax];
int KMP[31][Nmax];
int K, S = 1, F = 1;

void Decompose();
void Prefix(int x);

int main()
{
    is >> N >> M;
    is >> T+1 >> B;
    Decompose();
    for (int i = 1; i <= K; ++i)
        Prefix(i);
    bool matchfound = 0;
    for (int i = 1, j = 0, SZ; i <= K; ++i, matchfound = 0)
    {
        SZ = strlen(Pattern[i]+1);
        if (SZ == 0)
            continue;
        ++j;
        for (int k = 0; j <= N; ++j)
        {
            while (k > 0 && Pattern[i][k+1] != T[j])
                k = KMP[i][k];
            if (Pattern[i][k+1] == T[j])
                k++;
            if (j == N && i < K)
            {
                os << -1;
                exit(0);
            }
            if (k == SZ)
            {
                if (i == 1)
                    S = j-SZ+1;
                if (i == K)
                    F = j;
                matchfound = 1;
                break;
            }
        }
        if (matchfound == 0)
        {
            os << -1;
            exit(0);
        }
    }
    if (B[1] == '*')
        S = 1;
    os << S << ' ' << F;
    is.close();
    os.close();
}

void Decompose()
{
    for (int i = 0, j; i < M;)
    {
        while (B[i] == '*' && B[i] != '\0' && i < M) ++i;

        if (i >= M) break;
        for (++K, j = i;B[i] != '*' && B[i] != '\0' && i < M; ++i)
        {
            Pattern[K][i-j+1] = B[i];
        }
    }
};

void Prefix(int x)
{
    int SZ = strlen(Pattern[x]+1);
    for (int i = 2, k = 0; i <= SZ; ++i)
    {
        while (k > 0 && Pattern[x][k+1] != Pattern[x][i])
            k = KMP[x][k];
        if (Pattern[x][k+1] == Pattern[x][i])
            ++k;
        KMP[x][i] = k;
    }
};
