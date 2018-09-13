#include <fstream>
using namespace std;

ifstream is ("fractii.in");
ofstream os ("fractii.out");


int Prim[1000004];  //Prim[i] = cate numere strict mai mici decat i si care au GCD = 1;

long long Solve(int k);

int main()
{
    int T;
    is >> T;
    os << Solve(T);
}

long long Solve(int N)
{
    for (int i = 1; i <= N; ++i)
        Prim[i] = i-1;
    long long sol = 0;
    for (int i = 2; i <= N; sol += Prim[i], ++i)
        for (int j = i+i; j <= N; j += i)
            Prim[j] -= Prim[i];
    return sol * 2 + 1;
};
