#include <fstream>
#include <vector>
using namespace std;

const int Mmax = 2048;
const int Nmax = 1000010;
typedef long long LL;

ifstream is ("ksecv4.in");
ofstream os ("ksecv4.out");

int N, K, M;
LL A[Mmax], B[Mmax];
LL V[Nmax];

bool Check(long long S);

int main()
{
    is >> N >> K >> M;
    for (int i = 0; i < M; ++i)
        is >> A[i];
    for (int i = 0; i < M; ++i)
        is >> B[i];
    for (int i = 0; i < N; ++i)
        V[i] = A[i%M] ^ B[i/M];

    LL result;
    LL bit = 1LL<<60;
    for (result = 0; bit > 0; bit >>= 1)
        if (Check(result + bit) == 0)
            result += bit;

    os << result+1;
}

bool Check(long long S)
{
    int Sol = 0;
    S <<= 1;
    LL Mx(V[0]), Mn(V[0]);
    for (int i = 0; i < N; ++i)
    {
        if (Mn > V[i])
        {
            Mn = V[i];
            if (Mx-Mn > S)
            {
                Mx = V[i];
                ++Sol;
                if (Sol == K)
                    return 0;
            }
        }

        if (Mx < V[i])
        {
            Mx = V[i];
            if (Mx-Mn > S)
            {
                Mn = V[i];
                ++Sol;
                if (Sol == K)
                    return 0;
            }
        }
    }
    return 1;
};







