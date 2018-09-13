#include <fstream>
#include <vector>
using namespace std;

ifstream is ("reguli.in");
ofstream os ("reguli.out");

const int Nmax = 500004;

int N;
long long S[Nmax];
int KMP[Nmax];


int main()
{
    is >> N;
    long long x, y;
    is >> x;
    for (int i = 1; i < N; ++i)
    {
        is >> y;
        S[i] = y-x;
        x = y;
    }


    for (int i = 2, k = 0; i < N; ++i)
    {
        while (k > 0 && S[k+1] != S[i])
            k = KMP[k];
        if (S[k+1] == S[i])
            ++k;
        KMP[i] = k;
    }

    os << N-KMP[N-1]-1 << '\n';
    for (int i = 1; i < N-KMP[N-1]; ++i)
        os << S[i] << '\n';

    is.close();
    os.close();
}














