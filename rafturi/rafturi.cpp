#include <fstream>
using namespace std;

ifstream input ("rafturi.in");
ofstream output ("rafturi.out");

int n, C, A[10001], DP[10001];

const int MAXV = 999999999;

void Read();
void DynamicProgramming();

int main()
{
    Read();
    DynamicProgramming();
    output << DP[C];
    input.close();
    output.close();
    return 0;
};

void DynamicProgramming()
{
    DP[0] = A[0];
    int V1, V2, V3;
    for (int i = 1; i <= C; ++i)
    {
        V1 = DP[i-1] + A[i];
        V2 = DP[i-2] + max(A[i], A[i-1]);
        V3 = DP[i-3] + max(A[i], max(A[i-1], A[i-2]));
        DP[i] = min(V1, min(V2, V3));
        if (A[i] == 0)
            DP[i] = min(DP[i], DP[i-1]);
    }
};

void Read()
{
    int x, y;
    input >> C >> n;
    for (int i = 0; i < n; ++i)
    {
        input >> x >> y;
        A[x] = max(y, A[x]);
    }
};
