#include <fstream>
using namespace std;

ifstream is ("divk.in");
ofstream os ("divk.out");

#define BUFFER 1<<17
char Pars[BUFFER], *p;

int GET();
void Check();

int N, A, B, K;
int v[500003], r[100003];
long long S;

int main()
{
    p = Pars;
    N = GET();
    K = GET();
    A = GET();
    B = GET();
    for (int i = 1, x; i <= N; ++i)
        x = GET(), v[i] = (v[i-1] + x) % K;
    for (int i = 0; i <= N; ++i)
    {
        if (i >= A)
            r[v[i-A]]++;
        if (i-1 >= B)
            r[v[i-B-1]]--;
        S += r[v[i]];
    }
    os << S;
    is.close();
    os.close();
}

int GET()
{
    int X = 0;
    while (*p <= '0' || *p > '9') ++p, Check();
    while (*p >= '0' && *p <= '9') X = X * 10 + (*p - '0'), ++p, Check();
    return X;
};

void Check()
{
    if (*p == '\0') is.get(Pars, BUFFER, '\0'), p = Pars;
};
