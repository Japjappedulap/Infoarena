#include <fstream>
#include <stack>
using namespace std;

#define x first
#define y second
#define BF 1<<20
char Pars[BF], *p;
int GET();
void Check();

ifstream is ("bile.in");
ofstream os ("bile.out");

const int Di[] = {-1, 0, 1, 0};
const int Dj[] = {0, 1, 0, -1};

int N, T[63805], S[63805], R[63805], CloseRoots[4], ind;
bool B[276][276];
int Root(int k){int r;for (r = k;T[r] != r; r = T[r]);for (; T[k] != k; k = T[k]){T[k] = r;}return r;}
pair<int,int> IN[63805];
stack <int> Stk;

bool Exists(int val, int k);
void ReInit();
void Unite(int A, int B);

int main()
{
    p = Pars;
    N = GET();
    for (int i = 1; i <= N*N; ++i)
    {
        IN[i].x = GET(), IN[i].y = GET();
        T[i] = i;
        S[i] = 0;
        R[i] = 1;
    }
    for (int k = N*N, i, j, res = 0, pp; k >= 1; --k)
    {
        for (int d = 0; d < 4; ++d)
        {
            i = IN[k].x + Di[d];
            j = IN[k].y + Dj[d];
            pp = (i-1)*N+j;
            pp = Root(pp);
            if (Exists(pp, d) == 0 && B[i][j] == 1)
                CloseRoots[d] = pp;
        }
        ind = (IN[k].x-1)*N + IN[k].y;
        for (int d = 0; d < 4; ++d)
            if (CloseRoots[d])
                Unite(Root(ind), Root(CloseRoots[d]));
        B[IN[k].x][IN[k].y] = 1;
        S[ind]++;
        res = max(res, S[ind]);
        Stk.push(res);
        ReInit();
    }
    for (Stk.pop(); !Stk.empty(); Stk.pop())
        os << Stk.top() << '\n';
    os << 0;
    is.close();
    os.close();
}

void Unite(int A, int B)
{
    if (R[A] > R[B])
    {
        T[B] = A;
        S[A] += S[B];
        ind = A;
    }
    else
    {
        T[A] = B;
        S[B] += S[A];
        ind = B;
    }
    if (R[A] == R[B])
        R[B]++;
};

bool Exists(int val, int k)
{
    for (int d = 0; d < k; ++d)
        if (CloseRoots[d] == val) return 1;
    return 0;
};

void ReInit()
{
    for (int d = 0; d < 4; ++d)CloseRoots[d] = 0;
};

int GET()
{
    int X = 0;
    while (*p < '0' || *p > '9')++p, Check();
    while (*p >= '0' && *p <= '9') X = X*10 + (*p - '0'), ++p, Check();
    return X;
};

void Check()
{
    if (*p == '\0') is.get(Pars, BF, '\0'), p = Pars;
};
