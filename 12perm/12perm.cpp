#include <fstream>
#include <cstdlib>
using namespace std;
#define MOD (1<<20)

ifstream is ("12perm.in");
ofstream os ("12perm.out");

int N, A, B, C, D;

int main()
{
    is >> N;
    D = 1;C = 2;B = 6;A = 12;
    for (int i = 5; i <= N; ++i)
    {
        D = C;C = B;B = A;
        A = B + D + 2*(i-2);
        A = A & (MOD-1);
    }
    os << A;
    is.close();
    os.close();
}
