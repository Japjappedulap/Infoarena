#include <fstream>
#define Gm 76000
using namespace std;

ifstream is ("ghiozdan.in");
ofstream os ("ghiozdan.out");

int n, G, x;
int DP[Gm];
int V[201], T[Gm];

int main()
{
    is >> n >> G;
    for (int i = 1; i <= n; ++i)
        is >> x, V[x]++;
    DP[0] = 1;
    for (int w = 200; w >= 1; --w)
        if (V[w])
        for (int i = G-w; i >= 0; --i)
            if (DP[i])
            for (int j = 1; j <= V[w] && i + j*w <= G && !DP[i+j*w]; ++j){
                DP[i+j*w] = DP[i]+j;
                T[i+j*w] = w;
            }
    for (int i = G; i >= 1; --i)
        if (DP[i]){
            os << i << ' ' << DP[i]-1 << '\n';
            while (i)
            {
                os << T[i] << '\n';
                i -= T[i];
            }
            break;
        }
    is.close();
    os.close();
    return 0;
}
