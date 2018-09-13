#include <algorithm>
#include <fstream>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

ifstream cin ("dictree.in");
ofstream cout ("dictree.out");

const int Nmax = 25001;

int N, sol;
string S[Nmax+1];

int Prefix(string a, string b);

int main()
{
    string xax;

    cin >> N;
    for (int i = 1; i <= N; ++i)
        cin >> S[i];

    sort(S+1, S+N+1);

    S[0] = "";

    for (int i = 1; i <= N; ++i)
    {
        sol += (S[i].length() - Prefix(S[i], S[i-1]));
    }


    cout << sol+1;

    cin.close();
    cout.close();
}

int Prefix(string a, string b)
{
    int Sz = min(a.length(), b.length());
    int i;
    for (i = 0; i < Sz; ++i)
        if(a[i] != b[i])
            break;
    return i;
};
