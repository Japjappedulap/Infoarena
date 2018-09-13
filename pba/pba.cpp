#include <fstream>
using namespace std;

ifstream is ("pba.in");
ofstream os ("pba.out");

long long N, v[50002], s1, s2, s3;

int main()
{
    is >> N;
    for (int i = 1; i <= N; ++i)
        is >> v[i];
    for (int i = 1; i <= N; ++i)
        s1 = max(v[i], s1);
    for (int i = 1; i <= N; ++i)
        if (v[i] == s1)
    {
        v[i] = 0;
        break;
    }
    for (int i = 1; i <= N; ++i)
        s2 = max(v[i],s2);
    for (int i = 1; i <= N; ++i)
        if (v[i] == s2)
        {
            v[i] = 0;
            break;
        }
    for (int i = 1; i <= N; ++i)
        s3 = max(v[i],s3);
    for (int i = 1; i <= N; ++i)
        if (v[i] == s3)
        {
            v[i] = 0;
            break;
        }
    s1 *= s2;
    s1 %= 1000000007;
    s1 *= s3;
    s1 %= 1000000007;
    os << s1;
    is.close();
    os.close();
}
