#include <fstream>
#include <vector>
using namespace std;

ifstream is ("muzica.in");
ofstream os ("muzica.out");

const int MOD = 4993;

int N, M;
int A, B, C, D, mod, Sol;
vector <int> Hash[MOD];
vector <int> :: iterator it;

bool Exists(int value);

int main()
{
    is >> N >> M;
    is >> A >> B >> C >> D >> mod;
    for (int i = 1, X; i <= N; ++i)
    {
        is >> X;
        Hash[X % MOD].push_back(X);
    }
    if (Exists(A))Sol++;

    if (Exists(B))Sol++;

    for (int i = 3, X; i <= M; ++i)
    {
        X = ((long long) ((long long)B * (long long)C) + (long long) ((long long)A * (long long)D)) % (long long)mod;
        if (Exists(X))
            Sol++;
        A = B;
        B = X;
    }

    os << Sol;

    is.close();
    os.close();
}

bool Exists(int value)
{
    int H = value % MOD;
    for (it = Hash[H].begin(); it != Hash[H].end(); ++it)
        if (*it == value)
        {
            Hash[H].erase(it);
            return 1;
        }
    return 0;
};










