#include <fstream>
#include <string>
#include <cstring>
using namespace std;

ifstream is ("pufu.in");
ofstream os ("pufu.out");

int n, T;
string X;
int cont[4];

int main()
{
    is >> T;
    for (int t = 0; t < T; t++)
    {
        is >> n;
        for (int i = 0; i < n; ++i)
        {
            is >> X;
            if (X == "ciocolata") cont[1]++;
            if (X == "cascaval")  cont[2]++;
            if (X == "sare")      cont[3]++;
        }
        for (int i = 1; i <= 3; ++i)
            os << cont[i] << ' ';
        os << '\n';
        memset(cont, 0, sizeof(cont));
    }
    is.close();
    os.close();
    return 0;
}
