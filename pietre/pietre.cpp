#include <fstream>
using namespace std;

ifstream is ("pietre.in");
ofstream os ("pietre.out");

int T, A, B;
int V[2000001], dif = 1;
bool ex[2000001];


int main()
{
    for (int i = 1; i + dif <= 2000000; ++i)
    {
        if (ex[i] == 1) continue;
        V[i] = i+dif;
        ex[i] = ex[i+dif] = 1;
        ++dif;
    }
    for (is >> T; T; --T)
    {
        is >> A >> B;
        if (V[min(A, B)] == max(A, B))
            os << "2\n";
        else
            os << "1\n";
    }


    is.close();
    os.close();
}
