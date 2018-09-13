#include <fstream>
#include <vector>
using namespace std;

ifstream is ("iepuri.in");
ofstream os ("iepuri.out");

const int MOD = 666013;


class Matrix{
private:
    vector<vector<int> > values;
public:
    Matrix(int X)
    {
        values = vector<vector<int>> (X, vector<int>(X));
    }
    void Set(int i, int j, int k)
    {
        values[i][j] = k;
    }
    int Get(int i, int j)
    {
        return values[i][j];
    }
    Matrix operator * (const Matrix& F)
    {
        size_t i, j, k;
        Matrix aux(values.size());
        for (i = 0; i < values.size(); ++i)
            for (j = 0; j < values.size(); ++j)
                for (k = 0; k < values.size(); ++k)
            aux.Set(i, j, (aux.Get(i, j) + 1LL * values[i][k] * F.values[k][j]) % MOD);
        return aux;
    }
    void Print()
    {
        size_t i, j;
        for (i = 0; i < values.size(); ++i, os << '\n')
            for (j = 0; j < values.size(); ++j)
                os << values[i][j] << ' ';
        os << '\n';
    }
    Matrix Lpow(Matrix A, int B)
    {
        if (B == 1) return A;
        if (B % 2 == 0) return Lpow(A * A, B/2);
        if (B % 2 == 1) return A * Lpow(A * A, B/2);
    }
};

int Tests;
int A, B, C, X, Y, Z;

void Solve();

int main()
{
    for (is >> Tests; Tests; --Tests)
        Solve();
    is.close();
    os.close();
    return 0;
}

void Solve()
{
    int N, Sol;
    is >> A >> B >> C >> X >> Y >> Z >> N;

    Matrix M(3), U(3);
    M.Set(1, 0, 1);
    M.Set(2, 1, 1);
    M.Set(0, 2, Z);
    M.Set(1, 2, Y);
    M.Set(2, 2, X);
    U = M;
    Sol = 0;

    M = M.Lpow(M, N-2);

    Sol = (1LL * A * M.Get(0, 2)) % MOD;
    Sol = (Sol + 1LL * B * M.Get(1, 2)) % MOD;
    Sol = (Sol + 1LL * C * M.Get(2, 2)) % MOD;

    os << Sol << '\n';
};
