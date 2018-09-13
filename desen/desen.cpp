#include <fstream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;

#define Point pair<int,int>
#define x first
#define y second

ifstream is ("desen.in");
ofstream os ("desen.out");

int N, step, Nr, Acur(1), Aprev;
vector <Point> Ps;
vector <pair<double, Point> > APM[2], Aux;
vector <pair<double, Point> > :: iterator it;

double APMcost;
int T[1001], R[1001];

void APMInsertPoint(Point p);
int Root(int k);
void Unite(int a, int b);
double Dist(Point A, Point B);

int main()
{
    is >> N;
    Ps.resize(N+1);
    os << fixed;
    for (int i = 1; i <= N; ++i)
    {
        is >> Ps[i].x >> Ps[i].y;
        APMInsertPoint(Ps[i]);
        Nr++;
    }
    is.close();
    os.close();
}

void APMInsertPoint(Point p)
{
    APM[Acur].clear();
    ++step;
        APMcost = 0;
        for (int i = 1; i <= Nr+1; ++i) T[i] = i, R[i] = 1;
    Aux = APM[Aprev];
    for (int i = 1; i <= Nr; ++i)
        Aux.push_back(make_pair(Dist(Ps[i], Ps[Nr+1]) , make_pair(i, Nr+1)));
    sort(Aux.begin(), Aux.end());
    int Rx, Ry;
    pair<double, Point> m;
    for (it = Aux.begin(); it != Aux.end(); ++it)
    {
        m = *it;
        Rx = Root(m.y.x);
        Ry = Root(m.y.y);
        if (Ry != Rx)
        {
            Unite(Ry, Rx);
            APMcost += m.x;
            APM[Acur].push_back(m);
        }
    }
    os << APMcost << '\n';
    swap(Acur, Aprev);
};

double Dist(Point A, Point B)
{
    return sqrt( double((B.x-A.x)*(B.x-A.x) + (B.y-A.y)*(B.y-A.y)) );
};

int Root(int k)
{
    int r = k;
    for (; T[r] != r; r = T[r]);
    for (int s; T[k] != k; s = T[k], T[k] = r, k = s);
    return r;
};

void Unite(int a, int b)
{
    if (R[a] > R[b])
        T[b] = a;
    else
    {
        T[a] = b;
        if (R[a] == R[b])
            R[b]++;
    }
};















