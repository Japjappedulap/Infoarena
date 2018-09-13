#include <fstream>
using namespace std;

ifstream is ("spirala.in");
ofstream os ("spirala.out");

const int Di[] = {-1, 0, 1, 0}, Dj[] = {0, 1, 0, -1};

int n, m, PROG;
int A[102][102];
bool B[102][102];

void Read();
void Solve();
bool Ok(int i, int j);

int main()
{
    Read();
    Solve();
    is.close();
    os.close();
    return 0;
}

void Read()
{
    is >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            is >> A[i][j], B[i][j] = 1;
    PROG = A[1][2] - A[1][1];
};

void Solve()
{
    int i, j, iv, jv, Dir = 1;
    i = 1, j = 1;
    while (B[i][j] == 1)
    {
        B[i][j] = 0;
        iv = i + Di[Dir];
        jv = j + Dj[Dir];
        if (B[iv][jv] != 1)
        {
            ++Dir;
            if (Dir > 3) Dir -= 4;
        }
        iv = i + Di[Dir];
        jv = j + Dj[Dir];
        if (A[iv][jv] != A[i][j] + PROG && B[iv][jv] == 1)
        {
            os << "NU\n" << A[i][j] << ' ' << A[iv][jv];
            return;
        }
        if (B[iv][jv] == 1) i = iv, j = jv;
    }
    os << "DA\n" << A[i][j];
};

bool Ok(int i, int j)
{
    if (i < 1 || j < 1 || i > n || j > m) return false;
    return true;
};











