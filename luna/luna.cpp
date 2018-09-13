#include <fstream>
#include <vector>
using namespace std;

ifstream is ("luna.in");
ofstream os ("luna.out");

#define x first
#define y second

int N, M, K, A[51][51], mx;
int Sl[51][51];
bool B[5004];
pair <int, int> D;
vector <pair <int, int> > Q[5004];

bool FindSize(int p, int a, int b);

int main()
{
    is >> N >> M;
    for (int i = 1; i <= N ; ++i)
        for (int j = 1; j <= M; ++j)
            is >> A[i][j], B[A[i][j]] = 1;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            if (A[i][j] == A[i][j-1]) Sl[i][j] = Sl[i][j-1]+1;
            else Sl[i][j] = 1;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
        {
            D.x = 0;
            D.y = Sl[i][j];
            for (int k = i; k > 0 && A[i][j] == A[k][j]; --k)
            {
                ++D.x;
                D.y = min(D.y, Sl[k][j]);
                Q[A[i][j]].push_back(D);
            }
        }

    int P, X, Y;
    for (is >> K; K; --K)
    {
        is >> P >> X >> Y;
        if (B[P] == 0) os << "Tara de provenienta nu are parcele pe Luna!\n";
        else
            if (FindSize(P, X, Y) == 1) os << "Cererea poate fi satisfacuta!\n";
            else os << "Cererea nu poate fi satisfacuta!\n";
    }
    is.close();
    os.close();
};

bool FindSize(int p, int a, int b)
{
    for (size_t i = 0; i < Q[p].size(); ++i)
        if ((Q[p][i].x >= a && Q[p][i].y >= b) || (Q[p][i].x >= b && Q[p][i].y >= a))
            return true;
    return 0;
};
