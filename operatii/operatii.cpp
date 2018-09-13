#include <fstream>
using namespace std;
#define BUFFER 1 << 20
ifstream is ("operatii.in");
ofstream os ("operatii.out");

int n, x;
long long sol;
char Pars[BUFFER], *p;

void Check();
int Get();

int main()
{
    p = Pars;
    n = Get();
    for (int i = 0,x = Get(), V; i < n; ++i, V = x, x = Get())
    {

        if (x > V) sol += (x-V);
    }
    os << sol;
    is.close();
    os.close();
    return 0;
}

void Check()
{
    if (*p == '\0') is.get(Pars, BUFFER, '\0'), p = Pars;
};

int Get()
{
    while (*p < '0' || *p > '9') ++p, Check();
    int X = 0;
    while (*p >= '0' && *p <= '9') X = X*10 + *p-'0', ++p, Check();
    return X;
};
