#include <algorithm>
#include <fstream>
#include <vector>
#include <cstring>
using namespace std;

const int Nmax = 101;
const double INF = 100000000.0;

ifstream is ("elicoptere.in");
ofstream os ("elicoptere.out");

int Task, N, K;
vector <pair<int, double> > Graph[Nmax];
vector <pair<double, pair<int,int> > > Edges;
double W[Nmax][Nmax];

int A, B, C;
inline void COEF(int Xa, int Ya, int Xb, int Yb);
inline double Oriz(int, int, int, int);
inline double Vert(int, int, int, int);

int T[Nmax], S[Nmax];

int Root(int x) { while (x != T[x])x = T[x]; return x; }
void Unite(int a, int b)
{
    if (S[a] > S[b]) T[b] = a;
    else             T[a] = b;
    if (S[a] == S[b])  ++S[b];
}

void Read();

void DFS(int x);
void DFSAPM(int x);
bool Viz[Nmax];
int Size;

int main()
{
    Read();
    if (Task == 1)
    {
        int sol1 = 0;
        for (int i = 1; i <= N; ++i)
            if (Viz[i] == 0)
            {
                Size = 0;
                DFS(i);
                sol1 += (Size-1);
            }
        os << sol1;
    }
    if (Task == 2)
    {
        int sol2 = 0;
        for (int i = 1; i <= N; ++i)
            if (Viz[i] == 0)
            {
                Size = 0;
                DFS(i);
                sol2 += ((Size * (Size-1)) / 2);
            }
        os << sol2;
    }
    if (Task == 3)
    {
        double sol3 = 0;
        for (int i = 1; i <= N; ++i)
            T[i] = i, S[i] = 1;
        for (int i = 1; i <= N; ++i)
            if (Viz[i] == 0)
            {
                Edges.clear();
                DFSAPM(i);

                double APM_cost = 0;
                sort(Edges.begin(), Edges.end());
                int Ra, Rb;
                for (const auto& e : Edges)
                {
                    Ra = Root(e.second.first);
                    Rb = Root(e.second.second);
                    if (Ra != Rb)
                    {
                        Unite(Ra, Rb);
                        APM_cost += e.first;
                    }
                }
                sol3 += APM_cost;
            }
        os << fixed;
        os << sol3;
    }

}

void DFSAPM(int x)
{
    Viz[x] = 1;
    for (const auto& y : Graph[x])
        if (Viz[y.first] == 0)
            Edges.push_back({y.second, {x, y.first}});
    for (const auto& y : Graph[x])
        if (Viz[y.first] == 0)
            DFSAPM(y.first);
};

void DFS(int x)
{
    Viz[x] = 1;
    Size++;
    for (const auto& y : Graph[x])
        if (Viz[y.first] == 0)
            DFS(y.first);
};

void Read()
{
    is >> Task >> N >> K;

    int X[3][Nmax], Y[3][Nmax];

    for (int i = 1; i <= N; ++i)
        is >> X[0][i] >> Y[0][i] >> X[1][i] >> Y[1][i] >> X[2][i] >> Y[2][i];

    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            W[i][j] = INF;

    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            if (i != j)
            {
                for (int k = 0; k < 3; ++k)
                {

                    COEF(X[0][j], Y[0][j], X[1][j], Y[1][j]);//X[0][j], Y[0][j] -> X[1][j], Y[1][j]
                    if (X[0][j] <= X[k][i] && X[k][i] <= X[1][j] && W[i][j] > Vert(X[k][i], Y[k][i], Y[0][j], Y[1][j]))
                        W[i][j] = Vert(X[k][i], Y[k][i], Y[0][j], Y[1][j]);
                    if (X[1][j] <= X[k][i] && X[k][i] <= X[0][j] && W[i][j] > Vert(X[k][i], Y[k][i], Y[1][j], Y[0][j]))
                        W[i][j] = Vert(X[k][i], Y[k][i], Y[1][j], Y[0][j]);

                    if (Y[0][j] <= Y[k][i] && Y[k][i] <= Y[1][j] && W[i][j] > Oriz(X[k][i], Y[k][i], X[0][j], X[1][j]))
                        W[i][j] = Oriz(X[k][i], Y[k][i], X[0][j], X[1][j]);
                    if (Y[1][j] <= Y[k][i] && Y[k][i] <= Y[0][j] && W[i][j] > Oriz(X[k][i], Y[k][i], X[1][j], X[0][j]))
                        W[i][j] = Oriz(X[k][i], Y[k][i], X[1][j], X[0][j]);


                    COEF(X[1][j], Y[1][j], X[2][j], Y[2][j]);//X[1][j], Y[1][j] -> X[2][j], Y[2][j]
                    if (X[1][j] <= X[k][i] && X[k][i] <= X[2][j] && W[i][j] > Vert(X[k][i], Y[k][i], Y[1][j], Y[2][j]))
                        W[i][j] = Vert(X[k][i], Y[k][i], Y[1][j], Y[2][j]);
                    if (X[2][j] <= X[k][i] && X[k][i] <= X[1][j] && W[i][j] > Vert(X[k][i], Y[k][i], Y[2][j], Y[1][j]))
                        W[i][j] = Vert(X[k][i], Y[k][i], Y[2][j], Y[1][j]);
                    if (Y[1][j] <= Y[k][i] && Y[k][i] <= Y[2][j] && W[i][j] > Oriz(X[k][i], Y[k][i], X[1][j], X[2][j]))
                        W[i][j] = Oriz(X[k][i], Y[k][i], X[1][j], X[2][j]);
                    if (Y[2][j] <= Y[k][i] && Y[k][i] <= Y[1][j] && W[i][j] > Oriz(X[k][i], Y[k][i], X[2][j], X[1][j]))
                        W[i][j] = Oriz(X[k][i], Y[k][i], X[2][j], X[1][j]);


                    COEF(X[2][j], Y[2][j], X[0][j], Y[0][j]);//X[2][j], Y[2][j] -> X[0][j], Y[0][j]
                    if (X[2][j] <= X[k][i] && X[k][i] <= X[0][j] && W[i][j] > Vert(X[k][i], Y[k][i], Y[2][j], Y[0][j]))
                        W[i][j] = Vert(X[k][i], Y[k][i], Y[2][j], Y[0][j]);
                    if (X[0][j] <= X[k][i] && X[k][i] <= X[2][j] && W[i][j] > Vert(X[k][i], Y[k][i], Y[0][j], Y[2][j]))
                        W[i][j] = Vert(X[k][i], Y[k][i], Y[0][j], Y[2][j]);
                    if (Y[2][j] <= Y[k][i] && Y[k][i] <= Y[0][j] && W[i][j] > Oriz(X[k][i], Y[k][i], X[2][j], X[0][j]))
                        W[i][j] = Oriz(X[k][i], Y[k][i], X[2][j], X[0][j]);
                    if (Y[0][j] <= Y[k][i] && Y[k][i] <= Y[2][j] && W[i][j] > Oriz(X[k][i], Y[k][i], X[0][j], X[2][j]))
                        W[i][j] = Oriz(X[k][i], Y[k][i], X[0][j], X[2][j]);
                }

            }
    for (int i = 1; i <= N; ++i)
        for (int j = i+1; j <= N; ++j)
            if (W[i][j] < K || W[j][i] < K)
                Graph[i].push_back({j, min(W[i][j], W[j][i])}),
                Graph[j].push_back({i, min(W[i][j], W[j][i])});
};

inline void COEF(int Xa, int Ya, int Xb, int Yb)
{
    A = Yb - Ya;
    B = Xa - Xb;
    C = Xb*Ya - Xa*Yb;
};

inline double Oriz(int X, int Y, int Xa, int Xb)
{
    if (A == 0)
        return min(fabs(X-Xa), fabs(X-Xb));
    return fabs(((double(-B)*Y - C) / A) - X);
};

inline double Vert(int X, int Y, int Ya, int Yb)
{
    if (B == 0)
        return min(fabs(Y-Ya), fabs(Y-Yb));
    return fabs(((double(-A)*X - C) / B) - Y);
};
