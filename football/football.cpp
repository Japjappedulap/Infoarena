#include <fstream>
using namespace std;

ifstream is ("football.in");
ofstream os ("football.out");

int N, Tests;
const int PRE[] = {1, 2, 4, 7, 13, 25, 46, 86, 161, 300, 560, 1046, 1952, 3644, 6803, 12699, 23706, 44254, 82611, 154215, 287883, 537408, 1003212, 1872757, 3495988};

int main()
{
    is >> Tests;
    for (int T = 1; T <= Tests; ++T)
        is >> N ,os << "Case " << T << ": " << PRE[N-1] << '\n';
    is.close();
    os.close();
}
