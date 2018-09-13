#include <fstream>
using namespace std;

ifstream is ("jocul.in");
ofstream os ("jocul.out");

int n, v[1001], s, sol;
bool D[50001];

void Read();
void Solve();

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
    is >> n;
    for (int i = 1; i <= n; ++i)
    {
        is >> v[i];
        s += v[i];
    }
};

void Solve()
{
    D[0] = true;
    for (int i = 1; i <= n; ++i)
        for (int j = (s/2)-v[i]; j >= 0; --j)
            if (D[j] == true)
                D[j+v[i]] = true;
    for (int i = (s/2); i >= 0; --i)
        if (D[i] == true)
        {
            sol = i;
            break;
        }
    if (sol <= s-sol)
        os << sol << ' ' << s-sol;
    else
        os << s-sol << ' ' << sol;
};











