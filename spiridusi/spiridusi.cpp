#include <fstream>
#include <vector>
using namespace std;

#define cint const int

ifstream is ("spiridusi.in");
ofstream os ("spiridusi.out");

cint Nmax = 100001;
cint INF = 1000000000;

int N, C, Sp[Nmax], Pr[Nmax]; vector<int> Tree[Nmax];

int Sum[Nmax]; //Suma Sp de la nodu 1 la nodu curent
int PSum[Nmax]; //suma Pr de la nodu 1 la nodu curent

int Solution;

class SegmentTree{
    int Sz;
    vector <int> T;
public:

    SegmentTree(int sz)
    {
        for (Sz = 1; Sz < sz; Sz<<=1);
        sz = Sz;
        T = vector<int> (2*Sz, -INF);
    }
    inline void update(int where, int val)
    {
        where += Sz;
        T[where] = val;
        for (where >>= 1; where > 0; where >>= 1)
            T[where] = max(T[2*where], T[2*where+1]);
    }
    inline int query(int L, int R)
    {
        int res = -INF;
        L += Sz, R += Sz;
        while (L <= R)
        {
            res = max(res, max(T[L], T[R]));
            L = (L + 1) / 2;
            R = (R - 1) / 2;
        }
        return res;
    }
} ST(0);


inline int GetBestAncestor(int L, int R, int Val);

bool Visited[Nmax];
void DFS(int x);

void Input();

int main()
{
    Input();
    DFS(1);
    os << Solution;
    is.close();
    os.close();
}

int Depth = 0;

void DFS(int x)
{
    Depth++;
    Visited[x] = 1;
    Sum[Depth] = Sum[Depth-1] + Sp[x];
    PSum[Depth] = PSum[Depth-1] + Pr[x];

    ST.update(Depth, PSum[Depth]);

    int Fx = GetBestAncestor(0, Depth, Sum[Depth]);

    Solution = max(Solution, ST.query(Fx, x)-PSum[Fx-1]);

    for (const int& y : Tree[x])
        if (Visited[y] == 0)
            DFS(y);


    Sum[Depth] = PSum[Depth] = 0;
    ST.update(Depth, -INF);
    Depth--;
};

inline int GetBestAncestor(int L, int R, int Val)
{
    if (Val - Sum[L] <= C) return L+1;
    Val -= C;
    int bit, best;    //C + S[best] < Val
    for (bit = 1; bit < R ; bit <<= 1);
    for (best = 0; bit ; bit >>= 1)
        if (best + bit <= R && Sum[best + bit] < Val)
            best += bit;
    return min (R, best+2);
};


void Input()
{
    is >> N >> C;
    ST = SegmentTree(N+1);
    for (int i = 1; i <= N; ++i)
        is >> Sp[i];
    for (int i = 1; i <= N; ++i)
        is >> Pr[i];
    for (int x, y, i = 1; i < N; ++i)
    {
        is >> x >> y;
        Tree[x].push_back(y);
        Tree[y].push_back(x);
    }
};
