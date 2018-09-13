#include <fstream>
#include <vector>
using namespace std;

ifstream is ("br.in");
ofstream os ("br.out");

int n, T;
vector <int> V, S;

int BS(int L, int R, int val);

int main()
{
    is >> n >> T;
    V.resize(n+1); S.resize(n+1);
    for (int i = 1; i <= n; ++i)
        is >> V[i], S[i] = S[i-1]+V[i];
    for (int t = 0, i, X, R; t < T; ++t)
    {
        is >> i >> X;
        if (X >= S[n])
            os << n << '\n';
        else
        {
            if (S[n]-S[i-1] > X)
            {
                R = S[i-1]+X;
                os << BS(i, n, R)-i << '\n';
            }
            else
            {
                R = X-(S[n]-S[i-1]);
                os << BS(1, i, R)+(n-i) << '\n';
            }
        }
    }


    is.close();
    os.close();
    return 0;
}

int BS(int L, int R, int val)
{
    int l = L, r = R, m = 0;
    while (l < r)
    {
        m = (l+r)/2;
        if (S[m] <= val)
            l = m+1;
        if (S[m] >= val)
            r = m;
    }
    return l;
};
