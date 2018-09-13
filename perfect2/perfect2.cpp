#include <fstream>
#include <algorithm>
#include <cstring>

#define IN "perfect2.in"
#define OU "perfect2.out"
#define DIM 200005
#define x first
#define y second
#define BF 1<<17

std::ifstream is (IN);
std::ofstream os (OU);

typedef std::pair<int,int> Point;

int Task;
int N;
Point V[DIM], RP[DIM];

char Pars[BF], *p;
void Check();
int Get();

int GCD(int A, int B);
void Solve1();
void Solve2();

int main()
{
    p = Pars;
    Check();
    Task = Get();
    switch (Task)
    {
        case 1:
            Solve1(); break;
        case 2:
            Solve2(); break;
    }
    is.close();
    os.close();
}

void Check()
{
    if (*p == '\0') is.get(Pars, BF, '\0'), p = Pars;
};

int Get()
{
    while (*p <= '0' || *p > '9') ++p, Check();
    int X = 0;
    while (*p >= '0' && *p <= '9') X = X * 10 + *p - '0', ++p, Check();
    return X;
};

int GCD(int A, int B)
{
    if (!B) return A;
    return GCD(B, A%B);
};

void Solve1()
{
    N = Get();
    Point DL(1<<23, 1<<23), UR;
    for (int i = 1; i <= N; ++i)
    {
        V[i].x = Get(), V[i].y = Get();
        if (DL.x > V[i].x) DL.x = V[i].x;
        if (DL.y > V[i].y) DL.y = V[i].y;
        if (UR.x < V[i].x) UR.x = V[i].x;
        if (UR.y < V[i].y) UR.y = V[i].y;
    }
    os << DL.x << ' ' << DL.y << ' ' << UR.x << ' ' << UR.y;
};

void Solve2()
{
    N = Get();
    int sol = 0;
    V[1].x = Get(), V[1].y = Get();
    for (int i = 2; i <= N; ++i)
    {
        V[i].x = Get(), V[i].y = Get();
        if ( GCD(abs(V[i].x-V[1].x), abs(V[i].y-V[1].y)) == 1 )
            sol++;
    }
    os << sol;
};

