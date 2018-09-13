#include <algorithm>
#include <fstream>
using namespace std;

ifstream is ("calcule.in");
ofstream os ("calcule.out");

const int Nmax = 100001;
const int MOD = 20011;

int N, K;
int V[Nmax];
int P[Nmax] = {Nmax}, Psize; // P descrescator
int R[Nmax], sol;

int BS(int x);

void debug()
{
    for (int i = 1; i <= Psize; ++i)
        os << P[i] << ' ';
    os << '\n';
};

int main()
{
    is >> N >> K;
    for (int i = 1; i <= N; ++i)
        is >> V[i];
    Psize = 1;
    P[1] = V[1];
    for (int i = 2, pos; i <= N; ++i)
        if (V[i] <= P[Psize])
        {
            Psize++;
            P[Psize] = V[i];
        }
        else
        {
            pos = BS(V[i]);
            P[pos] = V[i];
        }
    os << Psize << '\n';
    R[0] = 1;
    for (int i = 1; i <= N; ++i)
        V[i] = (V[i] + V[i-1]) % K;

    for (int i = 1; i <= N; ++i)
    {
        sol += R[V[i]];
        R[V[i]]++;
        if (sol >= MOD)
            sol -= MOD;
    }

    os << sol;
    is.close();
    os.close();
}

int BS(int x)   // pozitia celui mai mare numar strict mai mic decat x
{
    int bit, i;
    for (bit = 0; (1<<bit) < Psize; ++bit);
    for (i = 0; bit >= 0; bit--)
        if (i + (1<<bit) <= Psize && P[i + (1<<bit) - 1] >= x)
            i += (1<<bit);
    return i;
};













