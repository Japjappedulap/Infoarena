#include <fstream>
#include <algorithm>
using namespace std;

#define MOD 1000000007

ifstream is ("galagie.in");
ofstream os ("galagie.out");

#define BUFFER 1<<17
char Pars[BUFFER], *p;

int GET();
void Check();

int N;
long long V[100004], S[100004], R, X;

int main()
{
    p = Pars;
    N = GET();
    for (int i = 1; i <= N ; ++i)
        V[i] = GET();
    sort(V+1, V+N+1);
    for (int i = 1; i <= N ; ++i)
        S[i] = S[i-1] + V[i];
    R = V[1] * (N-1) - (S[N]-S[1]);
    R = -R;
    for (int i = 2; i < N ; ++i)
    {
        X = V[i]* (i-1) - S[i-1];
        R += X;
        R %= MOD;
        X = V[i]* (N-i) - (S[N] - S[i]);
        X = -X;
        R += X;
        R %= MOD;
    }
    X = V[N]* (N-1) - S[N-1];
    R += X;
    R %= MOD;
    os << R;
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
