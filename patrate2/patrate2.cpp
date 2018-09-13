#include <fstream>
using namespace std;

ifstream is ("patrate2.in");
ofstream os ("patrate2.out");

int n;
short v[500400];

void MUL(int b);

int main()
{
    is >> n;
    v[0] = 1, v[1] = 1;
    for (int i = 2; i <= n; ++i)
        MUL(i);
    int k = n*n;
    while (k >= 20)
    {
        MUL(1024 * 1024);
        k -= 20;
    }
    for (int i = 1; i <= k; ++i)
        MUL(2);
    for (int i = v[0]; i >= 1; --i)
        os << v[i];
    is.close();
    os.close();
    return 0;
}

void MUL(int b)
{
    int i, t = 0;
    for (i = 1; i <= v[0] || t; ++i, t /= 10)
        v[i] = (t += v[i] * b) % 10;
    v[0] = i-1;
};
