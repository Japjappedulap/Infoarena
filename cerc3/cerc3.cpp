#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int N, M = 1, Q, P;
int cnt[2003];
using Circle = pair< pair<int,int>, int> ;
#define x first.first
#define y first.second
#define R second

vector <Circle> C;

inline int CMP(Circle A, Circle B)
{ return A.x * B.y < B.x * A.y || (A.x * B.y == B.x * A.y && A.x + A.y < B.x + B.y); };
double Dist(Circle A, Circle B) { return sqrt( abs((A.x-B.x) * (A.x-B.x)) + abs((A.y-B.y) * (A.y-B.y)));};

int main()
{
    freopen("cerc3.in", "r", stdin);
    freopen("cerc3.out", "w", stdout);
    scanf("%i", &N);
    C.resize(N);
    for (int i = 0, G; i < N; ++i)
        scanf("%i%i%i", &C[i].x, &C[i].y, &C[i].R);
    sort(C.begin(), C.end(), CMP);
    for (int i = 0; i < N-1; ++i)
        if (C[i].x * C[i+1].y != C[i+1].x * C[i].y)
            M++;
    for (int t = 0, k = 0, mx = 0; t < N; t = k+1, ++k, mx = 0)
    {
        while (C[k].x * C[k+1].y == C[k+1].x * C[k].y)
            ++k;
        for (int i = t; i <= k; ++i)
        {
            cnt[i] = 1;
            for (int j = i-1; j >= t; --j)
                if (Dist(C[i], C[j]) > C[i].R + C[j].R && cnt[i] < cnt[j]+1)
                    cnt[i] = cnt[j]+1;
        }
        for (int i = t; i <= k; ++i)
            if (cnt[i] > mx)
                mx = cnt[i];
        if (mx > Q)
            Q = mx, P = 0;
        if (mx == Q)
            P++;
    }
    printf("%i %i %i", M, Q, P);
}
