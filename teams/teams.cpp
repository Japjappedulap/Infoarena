#include <fstream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAX 10000000
ifstream is ("teams.in");
ofstream os ("teams.out");

int n, a, b, x, SOL;
char c[MAX];
vector <int> v;

int BinarySearch1(int L, int R, int Key);
int BinarySearch2(int L, int R, int Key);

int main()
{
    is >> n >> a >> b;
    for (int i = 0; i < n; ++i)
    {
        is >> x;
        v.push_back(x);
    }
    sort (v.begin(), v.end());
    for (int it = 0, I, J; it < n-1; ++it, I = 0, J = 0)
    {
        I = BinarySearch1(it, n, a-v[it]);
        J = BinarySearch2(it, n, b-v[it]);
        if (I < J)
        {
            if (I <= it && J > it)
                SOL += J-it;
            else
                if (I > it && J > it)
                    SOL += J - I+1;
        }
        //os << J << ' ' << I << '\n';
    }
    os << SOL;
    is.close();
    os.close();
    return 0;
}

void Parsing()
{
    is >> n >> a >> b;
    v.resize(n-1);
    is.getline(c, MAX-1, '\n');
    memset(c, 0, sizeof(c));
    is.getline(c, MAX-1, '\n');
    n = 0;
    for (int i = 0; c[i] != '\n'; i++)
        if (c[i] == ' ')
            v[n] = x, x = 0, ++n;
        else
            x = x*10 + c[i];
};

int BinarySearch1(int L, int R, int Key)
{
    int M;
    while (L <= R)
    {
        M = (L+R) / 2;
        if (v[M] < Key)
            L = M+1;
        else
            R = M-1;
    }
    return L;
};

int BinarySearch2(int L, int R, int Key)
{
    int M;
    while (L <= R)
    {
        M = (L+R) / 2;
        if (v[M] <= Key)
            L = M+1;
        else
            R = M-1;
    }
    return R;
};
