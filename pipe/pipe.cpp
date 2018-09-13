#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

ifstream is ("pipe.in");
ofstream os ("pipe.out");

int DP[97000];
#define DP (DP + 37000)
bool B[97000];
#define B (B + 37000)

int DP2[97000];
#define DP2 (DP2 + 37000)
bool B2[97000];
#define B2 (B2 + 37000)

int n, X1, Y1, X2, Y2, val, s, as, rs;
char ch;

vector <int> A, R;

int main()
{
    is >> n;
    is >> X1 >> Y1 >> X2 >> Y2;
    if (X1 > X2) swap(X1, X2), swap(Y1, Y2);
    for (int i = 1, val; i <= n; ++i)
    {
        is >> ch >> val;
        if (ch == 'R')  R.push_back(val), rs += val;
        else            A.push_back(val), as += val;
    }
    sort(R.begin(), R.end());
    for (int i  = Y1-rs; i <= Y1+rs; ++i) DP[i] = 1 << 24;
    for (int i  = X1-rs; i <= X1+rs; ++i) DP2[i] = 1 << 24;
    sort(A.begin(), A.end());
    DP[Y1] = 0; B[Y1] = 1; s = 0;
    for (int k = 0; k < R.size(); ++k, s += R[k])
        for (int i = Y1-s; i <= Y1+s; ++i)
            if (B[i] == 1)
            {
                if (DP[i] + R[k] < DP[i+R[k]]) DP[i+R[k]] = DP[i] + R[k], B[i+R[k]] = 1;
                if (DP[i] + R[k] < DP[i-R[k]]) DP[i-R[k]] = DP[i] + R[k], B[i-R[k]] = 1;
            }
    DP2[X1] = 0; B2[X1] = 1; s = 0;
    for (int k = 0; k < A.size(); ++k, s += A[k])
        for (int i = X1-s; i <= X1+s; ++i)
            if (B2[i] == 1)
            {
                if (DP2[i] + A[k] < DP2[i+A[k]]) DP2[i+A[k]] = DP2[i] + A[k], B2[i+A[k]] = 1;
                if (DP2[i] + A[k] < DP2[i-A[k]]) DP2[i-A[k]] = DP2[i] + A[k], B2[i-A[k]] = 1;
            }
    if (B2[X2] == 0 || B[Y2] == 0) os << "imposibil";
    else os << DP[Y2]+DP2[X2];
    is.close();
    os.close();
    return 0;
}
