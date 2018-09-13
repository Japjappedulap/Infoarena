#include <fstream>
#include <cstring>
#include <vector>
using namespace std;

ofstream os ("abc2.out");

char Main[10000031];
char Word[22];
int L;
unsigned int P[23] = {1};

const int MOD = 99991;
vector <unsigned int> Hash[MOD];

void Input();
void Insert(unsigned int );
bool Existence(unsigned int );

int main()
{
    for (int i = 1; i <= 22; ++i)
        P[i] = P[i-1] * 3;

    Input();
    unsigned int x = 0, sol = 0;

    char *i = Main;
    for (int k = 0; k < L; ++k, ++i)
        x += P[k] * (*i-'a');
    sol += Existence(x);

    for ( ;*i != '\0' ; ++i)
    {
        x /= 3;
        x += (*i - 'a') * P[L-1];
        sol += Existence(x);
    }

    os << sol;
    os.close();
}

void Input()
{
    ifstream is ("abc2.in");
    is >> Main;

    for (unsigned int x = 0, k = 0; is >> Word; Insert(x), x = 0, k = 0)
        for (char *p = Word; *p != '\0'; ++p, ++k)
            x += P[k] * (*p-'a');

    L = strlen(Word);
    is.close();
};

void Insert(unsigned int X)
{
    if (Existence(X)) return;
    Hash[X % MOD].push_back(X);
};

bool Existence(unsigned int X)
{
    for (const unsigned int& i : Hash[X % MOD])
        if (i == X)
            return true;
    return false;
};






