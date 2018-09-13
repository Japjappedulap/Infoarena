#include <fstream>
using namespace std;

ifstream is ("adunare.in");
ofstream os ("adunare.out");

int main()
{
    int a, b;
    is >> a >> b;
    os << a+b;
    is.close();
    os.close();
}

