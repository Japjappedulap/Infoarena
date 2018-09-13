#include <cstring>
#include <fstream>
#include <string>
using namespace std;

ifstream is ("map.in");
ofstream os ("map.out");

const int Nmax = 2001;


char Txt[Nmax];
int D[Nmax];
int Ex[Nmax];

int N, M;


int main()
{
    is >> N >> M;

    for (int k = 0; k < N; ++k)
    {
        memset(Txt, 0, sizeof(Txt));
        is >> Txt;
        memset(D, 0, sizeof(D));
        for (int i = 1, j = 0; i < M; ++i)
        {
            while (Txt[i] != Txt[j] && j != 0)
                j = D[j-1];
            if (Txt[i] == Txt[j])
                ++j;
            D[i] = j;
        }
        Ex[M]++;
        for (int i = M-1; i > M/2 && D[i] > M/2; i = D[i-1])
            Ex[D[i]]++;
    }

    for (int k = (M/2)+1; k <= M; ++k)
        if (Ex[k] == N)
        {
            os << k;
            break;
        }


}
