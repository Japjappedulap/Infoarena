#include <fstream>
#include <deque>
using namespace std;

const int Nmax  = 1000 + 2;
const int INF = 0x3f3f3f3f;

ifstream cin ("padure.in");
ofstream cout ("padure.out");

const int Di[] = {-1, 0, 1, 0}, Dj[] = {0, 1, 0, -1};

int N, M, A[Nmax][Nmax], DP[Nmax][Nmax];
int SourceI, SourceJ;
int DestI, DestJ;
bool B[Nmax][Nmax];

deque < pair <int, int> > DQ;

void Read();
void BF();
bool Ok(int i, int j);

int main()
{
    Read();
    BF();
    cout << DP[DestI][DestJ] << '\n';
  //  for (int i = 1; i <= N; ++i, cout << '\n')
   //     for (int j = 1; j <= M; ++j)
    //        cout << DP[i][j] << ' ';
}

void Read()
{
    cin >> N >> M;
    cin >> SourceI >> SourceJ;
    cin >> DestI >> DestJ;

    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            cin >> A[i][j], DP[i][j] = INF;
}

void BF()
{
    DP[SourceI][SourceJ] = 0;
    DQ.push_front({SourceI, SourceJ});

    for (int i, j; !DQ.empty(); )
    {
        i = DQ.front().first;
        j = DQ.front().second;
        DQ.pop_front();
        B[i][j] = 1;
        for (int dir = 0, iv, jv; dir < 4; ++dir)
        {
            iv = i + Di[dir];
            jv = j + Dj[dir];
            if (Ok(iv, jv) && B[iv][jv] == 0)
                if (A[iv][jv] != A[i][j] && DP[iv][jv] > DP[i][j] + 1)
                {
                    DP[iv][jv] = DP[i][j] + 1;
                    DQ.push_back({iv, jv});
                }
                if (A[iv][jv] == A[i][j] && DP[iv][jv] > DP[i][j])
                {
                    DP[iv][jv] = DP[i][j];
                    DQ.push_front({iv, jv});
                }

        }
    }

}

bool Ok(int i, int j)
{
    return 1 <= i && i <= N && 1 <= j && j <= M;
};
