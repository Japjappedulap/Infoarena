#include <fstream>
#include <cstring>

#define INF 0x3f3f3f3f
#define INPUT   "scara3.in"
#define OUTPUT  "scara3.out"

std::ifstream is (INPUT);
std::ofstream os (OUTPUT);

int N;
int A[1208], E[1208];
int DP[2][1208];
int LP = 0, LC = 1;
std::pair <int, int> sol;

void Read();
std::pair <int, int> Solve();

int main()
{
    Read();
    sol = Solve();
    os << sol.first << ' ' << sol.second;
    is.close();
    os.close();
}

void Read()
{
    is >> N;
    int aux, t, v;
    is >> aux;
    for (size_t i = 1; i <= aux; ++i)
        is >> t >> v, A[t] = v;
    is >> aux;
    for (size_t i = 1; i <= aux; ++i)
        is >> t >> v, E[t] = v;
};

std::pair <int, int> Solve()
{
    memset(DP, INF, sizeof(DP));
    DP[0][0] = 0;
    for (size_t i = 0; i < N; ++i, std::swap(LC, LP))
    {
        for (size_t j = i; j <= N; ++j)
        {
            for (int k = 1; k <= A[j] && k <= N; ++k)
                if (DP[LC][j+k] > DP[LP][j])
                    DP[LC][j+k] = DP[LP][j];
            for (int k = 1; k <= 2*E[j] && k <= N; ++k)
                if (DP[LC][j+k] > DP[LP][j]+(k+1)/2)
                    DP[LC][j+k] = DP[LP][j]+(k+1)/2;
            DP[LC][j+1] = std::min(DP[LC][j+1], DP[LP][j]);
        }
        if (DP[LP][N] < INF)
        {
            std::pair <int, int> aux;
            aux.first = i;
            aux.second = DP[LP][N];
            return aux;
        }
    }
};
