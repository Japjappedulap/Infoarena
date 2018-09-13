#include <fstream>
using namespace std;

ifstream is ("schi.in");
ofstream os ("schi.out");

int N;
int v[30003], f[30003];
int AIB[30003];

void Update(int pos, int val);
int Q(int pos);
int BS(int val);

int main()
{
    is >> N;
    for (int i = 1; i <= N; ++i)
        is >> v[i], Update(i, 1);
    for (int i = N, pos; i > 0; --i)
    {
        pos = BS(v[i]);
        Update(pos, -1);
        f[pos] = i;
    }
    for (int i = 1; i <= N; ++i)
        os << f[i] << '\n';
    is.close();
    os.close();
}

int BS(int val)
{
    int p, d = 0;
    for (p = (1<<19); p; p >>= 1)
        if (d + p <= N && Q(d+p) < val)
            d += p;
    return d+1;
};

int Q(int pos)
{
    int sum = 0;
    for (int i = pos; i > 0; i -= (i &-i))
        sum += AIB[i];
    return sum;
};

void Update(int pos, int val)
{
    for (int i = pos; i <= N; i += (i &-i))
        AIB[i] += val;
};















