#include <fstream>
using namespace std;

ifstream is ("fructe.in");
ofstream os ("fructe.out");

int T, a, b;

int main()
{
	is >> T;
	for (int t = 0; t < T; ++t)
	{
		is >> a >> b;
		if (b % 2 == 1) os << 1 << '\n';
		else			os << 0 << '\n';
	}
	is.close();
	os.close();
}