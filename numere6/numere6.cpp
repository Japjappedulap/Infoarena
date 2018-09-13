#include <algorithm>
#include <cstdio>
#include <vector>
#include <set>
using namespace std;

const int MOD = 9973;

int A, B, sol;
int F[9001];
int D[10];

vector <short> v;
set<vector <short>> pool;

void Add(vector <short> vp);
void BK(vector <short> vp);
int LPow(int A, int B);
int Comb(int N, int K) { return (1LL * F[N] * LPow(F[K], MOD-2) * LPow(F[N-K], MOD-2)) % MOD; };

int main()
{
    freopen("numere6.in", "r", stdin);
    freopen("numere6.out", "w", stdout);
    scanf("%i%i", &A, &B);
    F[0] = 1;
    for (int i = 1; i <= 9000; ++i)
        F[i] = (F[i-1]*i) % MOD;

    int Bx = B;
    for (int K = 2; Bx != 1 && K < 10; ++K)
        while (Bx % K == 0)
            v.push_back(K), Bx /= K;

    if (Bx != 1)
    {
        printf("0");
        return 0;
    }

    BK(v);
    printf("%i", sol);
}

void BK(vector <short> vp)
{
    int prod = 1; sort(vp.begin(), vp.end());
    for (size_t i = 0; i < vp.size(); ++i) prod *= vp[i];
    if (pool.find(vp) == pool.end() && prod == B)
    {
        Add(vp);
        pool.insert(vp);
        vector <short> ax = vp;
        for (size_t i = 0; i < vp.size(); ++i)
            for (size_t j = 0; j < vp.size(); ++j)
            {
                ax = vp;
                if (i != j && vp[i] * vp[j] < 10)
                {
                    ax.push_back(vp[i] * vp[j]);
                    for (auto it = ax.begin(); it != ax.end(); ++it)
                        if (*it == vp[i])
                        {
                            ax.erase(it);
                            break;
                        }
                    for (auto it = ax.begin(); it != ax.end(); ++it)
                        if (*it == vp[j])
                        {
                            ax.erase(it);
                            break;
                        }
                    BK(ax);
                }
            }
    }
};

void Add(vector <short> vp)
{
    int Ax = A, Pv = 1;
    for (const int& x : vp)
        D[x]++;
    for (int i = 2, C; i <= 9; ++i)
        if (D[i])
            C = Comb(Ax, D[i]), Ax -= D[i], Pv = (Pv * C) % MOD, D[i] = 0;
    sol += Pv;
    if (sol >= MOD)
        sol -= MOD;
};

int LPow(int A, int B)
{
    if (B == 0) return 1;
    if (B == 1) return A;
    if (B % 2 == 0) return LPow(A*A % MOD, B/2) % MOD;
    if (B % 2 == 1) return (A * LPow(A*A % MOD, B/2)) % MOD;
};
