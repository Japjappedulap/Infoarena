#include <fstream>
using namespace std;

ifstream is ("minusk.in");
ofstream os ("minusk.out");

int N, K;
long long P[1000001], M[1000001];

int main()
{
    is >> N >> K;
    P[0] = 1;
    for (int i = 1; i <= N; ++i)
    {
        P[i] = (P[i-1] + M[i-1]) % 2011;
        if (i >= K) M[i] = (P[i-1] + M[i-1] - P[i-K]) % 2011;
        else M[i] = (P[i-1] + M[i-1]) % 2011;
        while (M[i] < 0) M[i] += 2011;
    }
    os << (P[N] + M[N]) % 2011;
    is.close();
    os.close();
}
