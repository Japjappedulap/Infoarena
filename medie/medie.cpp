#include <fstream>
using namespace std;

ifstream is ("medie.in");
ofstream os ("medie.out");

int n, V[9001], D[14001], sol;

int main()
{
    is >> n;
    for (int i = 1; i <= n; ++i)
        is >> V[i], D[2*V[i]]++;
    for (int i = 1; i <= n; ++i)
        for (int j = i+1; j <= n; ++j)
        {
            sol += D[V[i]+V[j]];
            if (V[i] == V[j]) sol -= 2;
        }
    os << sol;
    is.close();
    os.close();
    return 0;
}
