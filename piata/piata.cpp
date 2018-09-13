#include <fstream>
using namespace std;

ifstream fin ("piata.in");
ofstream fout ("piata.out");

int n, is, js, ip, jp, S, sol;

int SetValue(int i, int j);

int main()
{
    fin >> n >> is >> js >> ip >> jp;
    for (int j = js; j <= jp; ++j)
        S += SetValue(is, j);
    sol += S;
    for (int i = is+1; i <= ip; ++i, sol += S)
        S -= SetValue(i-1, jp), S += SetValue(i, js);
    fout << sol;
    fin.close();
    fout.close();
    return 0;
}

int SetValue(int i, int j)
{
    int x, sum = 0;
    if (i <= j) x = j-i+1;
    else x = n+j-i+1;
    while (x != 0) sum += x % 10, x /= 10;
    return sum;
};
