#include <fstream>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

FILE * is = fopen("dreptunghiuri2.in", "r");
ofstream os ("dreptunghiuri2.out");

struct Cel{int i, j;};
queue <Cel> Q;

vector <pair <Cel, Cel> > v;
vector <int> DP;

const int di[] = {0, 1};
const int dj[] = {1, 0};

int a[1001][1001], n, m, Minc, MincCnt;
bool b[1001][1001];

void Read();
void Fill();
Cel Lee(int i1, int j1);
void debug();

int main()
{
    Read();
    Fill();
    DP.resize(v.size());
    for (int i = 0; i < v.size(); i++)
    {
        DP[i] = 1;
        for (int j = i-1; j >= 0; --j)
            if (v[i].first.i > v[j].first.i && v[i].first.j > v[j].first.j)
                if (v[i].second.i < v[j].second.i && v[i].second.j < v[j].second.j)
                    DP[i] = max(DP[j]+1, DP[i]);
        if (DP[i] > Minc)
            Minc = DP[i], MincCnt = 0;
        if (DP[i] == Minc)
            MincCnt++;
    }
    os << DP.size() << ' ' << Minc << ' ' << MincCnt;
    fclose(is);
    os.close();
    return 0;
}

void Fill()
{
    Cel UL, DR;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (b[i][j] == 1)
            {
                UL.i = i, UL.j = j;
                DR = Lee(i, j);
                v.push_back(make_pair(UL, DR));
            }
        }
    }
};

Cel Lee(int i1, int j1)
{
    int i, j, iv, jv;
    Cel ret, Ac;
    if (b[i1+1][j1] == 0 && b[i1][j1+1] == 0)
    {
        a[i1][j1] = 1;
        b[i1][j1] = 0;
        ret.i = i1, ret.j = j1;
        return ret;
    }
    if (b[i1+1][j1] == 1 && b[i1][j1+1] == 0)
    {
        a[i1][j1] = 1;
        Ac.i = i1, Ac.j = j1;
        Q.push(Ac);
        while(!Q.empty())
        {
            Ac = Q.front(); Q.pop();
            i = Ac.i, j = Ac.j;
            b[i][j] = 0;
            for (int dir = 1; dir < 2; dir++)
            {
                iv = i + di[dir], jv = j + dj[dir];
                if (b[iv][jv] == 1 && a[iv][jv] == 0)
                {
                    a[iv][jv] = a[i][j]+1;
                    Ac.i = iv, Ac.j = jv;
                    ret = Ac;
                    Q.push(Ac);
                }
            }
        }
        return ret;
    }
    if (b[i1+1][j1] == 0 && b[i1][j1+1] == 1)
    {
        a[i1][j1] = 1;
        Ac.i = i1, Ac.j = j1;
        Q.push(Ac);
        while(!Q.empty())
        {
            Ac = Q.front(); Q.pop();
            i = Ac.i, j = Ac.j;
            b[i][j] = 0;
            for (int dir = 0; dir < 1; dir++)
            {
                iv = i + di[dir], jv = j + dj[dir];
                if (b[iv][jv] == 1 && a[iv][jv] == 0)
                {
                    a[iv][jv] = a[i][j]+1;
                    Ac.i = iv, Ac.j = jv;
                    ret = Ac;
                    Q.push(Ac);
                }
            }
        }
        return ret;
    }
    if (b[i1+1][j1] == 1 && b[i1][j1+1] == 1)
    {
        a[i1][j1] = 1;
        Ac.i = i1, Ac.j = j1;
        Q.push(Ac);
        while(!Q.empty())
        {
            Ac = Q.front(); Q.pop();
            i = Ac.i, j = Ac.j;
            b[i][j] = 0;
            for (int dir = 0; dir < 2; dir++)
            {
                iv = i + di[dir], jv = j + dj[dir];
                if (b[iv][jv] == 1 && a[iv][jv] == 0)
                {
                    a[iv][jv] = a[i][j]+1;
                    Ac.i = iv, Ac.j = jv;
                    ret = Ac;
                    Q.push(Ac);
                }
            }
        }
        return ret;
    }

};

void Read()
{
    int ax;
    fscanf(is, "%i %i", &n, &m);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            fscanf(is, "%i", &ax);
            if (ax == 1) b[i][j] = 1;
            else         b[i][j] = 0;
        }
};
