#include <fstream>
#include <cstring>
using namespace std;

ifstream is ("fsb.in");
ofstream os ("fsb.out");

#define DOS 200002

int N,  Ap[2*DOS], sol;
char V[DOS];

int main()
{
    is >> N;
    is >> V;
    Ap[DOS+0] = 1;
    for (int i = 0, x = 0; i < N; ++i)
    {
        if (V[i] == '1') ++x;
        else --x;
        sol += Ap[DOS+x];
        ++Ap[DOS+x];
    }
    os << sol;
    is.close();
    os.close();
}
