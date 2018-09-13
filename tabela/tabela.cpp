#include <fstream>
using namespace std;

ifstream is ("tabela.in");
ofstream os ("tabela.out");

int L, C;

int main()
{
    is >> L >> C;
    os << ((L-1)^(C-1));
}
