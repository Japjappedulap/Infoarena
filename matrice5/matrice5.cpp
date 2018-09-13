#include <fstream>
#include <stack>
using namespace std;

ifstream is ("matrice5.in");
ofstream os ("matrice5.out");

long long T, N, M, K, P, X;
stack <bool> S;

long long Lpow(long long x, long long exp);
long long TOP(long long x, bool y);

int main()
{
    is >> T;
    for (int t = 0; t < T; ++t)
    {
        is >> N >> M >> P >> K;
        os << Lpow(P*K, ((N-1)*(M-1))) * Lpow(P, (N+M-1)) % 10007 << '\n';
    }
    is.close();
    os.close();
    return 0;
}

long long Lpow(long long x, long long exp)
{
    X = 1;
    while (exp){
        S.push(exp % 2);
        exp /= 2;
    }
    while (!S.empty()){
        X = ((X * X) * TOP(x, S.top())) % 10007;
        S.pop();
    }
    return X;
};

long long TOP(long long x, bool y)
{
    if (y == 1) return x;
    return 1;
};
