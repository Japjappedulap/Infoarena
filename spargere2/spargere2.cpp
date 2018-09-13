#include <fstream>

#define I "spargere2.in"
#define O "spargere2.out"
#define DIM 200010
#define INI -0x3f3f3f3f
#define BUFFER 1<<17

std::ifstream is (I);
std::ofstream os (O);

int N, K;
int V[DIM];
long long D[DIM];
char Pars[BUFFER], *p;
int Get();
void Check();

int main()
{
    p = Pars;
    N = Get();
    K = Get();
    for (int i = 1; i <= N; ++i)
        V[i] = Get();
    for (int i = N; i >= 1; --i)
        D[i] = std::max(D[i+K]+V[i], D[i+1]);
    if (D[1] < 0) D[1] = 0;
    os << D[1];
    is.close();
    os.close();
}

int Get()
{
    int sgn = 1, X = 0;
    while (*p < '0' || *p > '9')
    {
        if (*p == '-') break;
        ++p, Check();
    }
    if (*p == '-') sgn = -1, ++p, Check();
    while (*p >= '0' && *p <= '9') X = X*10+ *p-'0', ++p, Check();
    X = X * sgn;
    return X;
};

void Check()
{
    if (*p == '\0') is.get(Pars, BUFFER, '\0'), p = Pars;
};
