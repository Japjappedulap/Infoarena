#include <fstream>
using namespace std;

ifstream is ("avarcolaci.in");
ofstream os ("avarcolaci.out");

#define BF 1<<18
char Pars[BF], *p;
int GET();
void Check();

int N, T, El[20], Ap[20], x, App[20];

int main()
{
    p = Pars;
    T = GET();
    for (int t = 1; t <= T; ++t)
    {
        N = GET();
        x = GET();
        El[t] = x;
        Ap[t] = 1;
        for (int i = 2; i <= 2*N; ++i)
        {
            x = GET();
            if (El[t] == x)
                ++Ap[t];
            else
            {
                if (Ap[t] > 1)
                    Ap[t]--;
                if (Ap[t] <= 1)
                    Ap[t] = 1, El[t] = x;
            }
        }
    }
    is.close();
    is.clear();
    is.open("avarcolaci.in");
    T = GET();
    for (int t = 1; t <= T; ++t)
    {
        N = GET();
        for (int i = 1; i <= 2*N; ++i)
        {
            x = GET();
            if (El[t] == x)
                App[t]++;
        }
        if (App[t] > N)
            os << El[t] << '\n';
        else
            os << "Mozart\n";
    }
    os.close();
}


int GET()
{
    while (*p < '0' || *p > '9') ++p, Check();
    int X = 0;
    while (*p >= '0' && *p <= '9') X = 10*X + (*p-'0'), ++p, Check();
    return X;
};

void Check()
{
    if (*p == '\0') is.get(Pars, BF, '\0'), p = Pars;
};
