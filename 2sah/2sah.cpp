#include <fstream>
#include <vector>
using namespace std;

ifstream is ("2sah.in");
ofstream os ("2sah.out");

const int MOD = 100003;

class Matrix{
private:
    vector<vector<int> > values;
public:
    Matrix (){}
    Matrix (int SIZE){
        values = vector<vector<int> > (SIZE, vector<int> (SIZE));
    }
    void Set (int x, int y, int val){
        values[x-1][y-1] = val;
    }
    int Get(int i, int j){
        return this->values[i][j];
    }
    Matrix operator*(const Matrix& B){
        size_t i, j, k;
        Matrix aux(B.values.size());
        for (i = 0; i < B.values.size(); ++i)
            for (j = 0; j < B.values.size(); ++j)
                for (k = 0; k < B.values.size(); ++k)
                    aux.Set(i+1, j+1, (( 1LL * aux.Get(i, j) + 1LL * this->values[i][k] * B.values[k][j] ) % MOD));
        return aux;
    }
};

int N, K, Task;
Matrix Z;

int Lpow(int A, int B);
Matrix MatrixLpow(Matrix A, int B);

int main()
{
    is >> Task >> N >> K;
    --K;
    if (Task == 1)
        os << Lpow(3, K) << '\n';
    else
    {
        Matrix M(3);
        M.Set(1, 3, 1);
        M.Set(2, 1, 1);
        M.Set(2, 3, 1);
        M.Set(3, 2, 1);
        M.Set(3, 3, 1);
        Z = M;
        M = MatrixLpow(Z, N-K+2);
        os << M.Get(2, 0) << '\n';
    }
    is.close();
    os.close();
}

int Lpow(int A, int B)
{
    if (B == 0) return 1;
    if (B == 1) return A;
    if (B % 2 == 0) return Lpow((1LL * A * A) % MOD, B/2) % MOD;
    if (B % 2 == 1) return (1LL * A * Lpow((1LL * A * A) % MOD, B/2)) % MOD;
};

Matrix MatrixLpow(Matrix A, int B)
{
    if (B == 0) return Z;
    if (B == 1) return A;
    if (B % 2 == 0) return MatrixLpow(A * A, B/2);
    if (B % 2 == 1) return (A * MatrixLpow(A * A, B/2));
};
