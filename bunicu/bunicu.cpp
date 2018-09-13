#include <fstream>
#include <cstring>
using namespace std;

ifstream is ("bunicu.in");
ofstream os ("bunicu.out");

int N, T;
bool b[1003];
char c[1003];
void Solve();

int main()
{
    for (is >> T; T; --T)
        Solve();
    is.close();
    os.close();
}

void Solve()
{
    is >> N;
    for (int i = 1, cnt; i <= N; ++i)
    {
        is >> c;
        cnt = 0;
        for (int j = 0; j < N; ++j)
            if (c[j] == '1')
                cnt++;
        b[cnt] = 1;
    }
    for (int i = 0; i <= N; ++i)
        if (b[i] == 0)
        {
            for (int j = 1; j <= i; ++j)
                os << 1;
            for (int j = i+1; j <= N; ++j)
                os << 0;
            break;
        }
    os << '\n';
    memset(b, 0, sizeof(b));
};
