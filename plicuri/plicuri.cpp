#include <algorithm>
#include <fstream>
using namespace std;

ifstream is ("plicuri.in");
ofstream os ("plicuri.out");

#define x second

int N;
int P[100002], CMX;
pair <int, int> v[100002];

inline int CMP(pair<int,int> A, pair<int,int> B);

int BS(int val);

int main()
{
    is >> N;
    for (int i = 1; i <= N; ++i)
    {
        is >> v[i].first >> v[i].x;
        if (v[i].first > v[i].x) swap(v[i].first, v[i].x);
    }
    sort(v+1, v+N+1, CMP);
    CMX = 1;
    P[1] = v[1].x;
    for (int i = 2, pos; i <= N; ++i)
    {
        pos = BS(v[i].x);
        P[pos+1] = v[i].x;
    }
    os << CMX;
    is.close();
    os.close();
}

int BS(int val)
{
    int L = 0, M, R = CMX;
    while(L <= R)
    {
        M = (L+R) / 2;
        if (P[M] < val && P[M+1] >= val) return M;
        if (P[M] < val) L = M+1;
        else R = M-1;
    }
    ++CMX;
    return CMX-1;
};

inline int CMP(pair<int,int> A, pair<int,int> B)
{
    if (A.first == B.first)
        return A.x>B.x;
    return A<B;
};
