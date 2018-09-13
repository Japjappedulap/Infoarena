#include <fstream>
using namespace std;

ifstream is ("datorii.in");
ofstream os ("datorii.out");

int N, M;
int arb[60006], SUM;

void Update(int N, int L, int R, int pos, int val);
void Sum(int N, int L, int R, int x, int y);

int main()
{
    is >> N >> M;
    for (int i = 1, x; i <= N; ++i)
    {
        is >> x;
        Update(1, 1, N, i, x);
    }
    for (int i = 1, x, y, OP; i <= M; ++i)
    {
        is >> OP >> x >> y;
        if (OP == 0)
            Update(1, 1, N, x, -y);
        else
        {
            SUM = 0;
            Sum(1, 1, N, x, y);
            os << SUM << '\n';
        }
    }
    is.close();
    os.close();
}

void Update(int N, int L, int R, int pos, int val)
{
    if (L == R)
    {
        arb[N] += val;
        return;
    }
    int M = (L+R)/2;
    if (pos <= M) Update(N*2, L, M, pos, val);
    else Update(2*N+1, M+1, R, pos, val);
    arb[N] = arb[2*N]+arb[2*N+1];
};

void Sum(int N, int L, int R, int x, int y)
{
    if (x <= L && R <= y)
    {
        SUM += arb[N];
        return;
    }
    int M = (L+R)/2;
    if (x <= M) Sum(2*N, L, M, x, y);
    if (M < y) Sum(2*N+1, M+1, R, x, y);
};




















