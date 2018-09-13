#include <fstream>
#include <vector>
#include <deque>
using namespace std;

ifstream is ("summax.in");
ofstream os ("summax.out");

const int LIM = 2000000000;

int N, L, R;
vector <vector <int> > D, S;
deque <int> DFq;

void Solve(int S, int D, int i, int j);

int main()
{
    int Task;
    is >> Task >> N >> L >> R;
    D = S = vector<vector<int> > (N+1, vector<int>());
    for (int i = 1; i <= N; ++i)
        D[i] = S[i] = vector <int>(i+1);
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= i; ++j)
            is >> D[i][j];


    for (int j = 1; j <= N; ++j)
        S[N][j] = 1;

    for (int i = N-1; i >= 1; --i)
        for (int j = 1; j <= i; ++j)
        {
            if (D[i+1][j] > D[i+1][j+1])
                D[i][j] += D[i+1][j], S[i][j] = S[i+1][j];

            else
                D[i][j] += D[i+1][j+1], S[i][j] = S[i+1][j+1];

            if (D[i+1][j] == D[i+1][j+1])
                S[i][j] = min(1LL*LIM+1, 1LL*S[i+1][j]+S[i+1][j+1]);
        }

    if (Task == 1)
        os << S[1][1];
    else
    {
        DFq.push_back(1);
        Solve(1, S[1][1], 1, 1);
    }

    is.close();
    os.close();
}


void Solve(int St, int Dr, int i, int j)
{
    if (i == N)
    {
        deque <int> p = DFq;

        while (!p.empty())
        {
            os << p.front() << ' ';
            p.pop_front();
        }
        os << '\n';
        return;
    }
    if (D[i+1][j] > D[i+1][j+1])    //going left son
    {
        DFq.push_back(j);
        Solve(St, St+S[i+1][j]-1, i+1, j);
        DFq.pop_back();
    }
    if (D[i+1][j] < D[i+1][j+1])    //going right son
    {
        DFq.push_back(j+1);
        Solve(Dr-S[i+1][j+1]+1, Dr, i+1, j+1);
        DFq.pop_back();
    }
    if (D[i+1][j] == D[i+1][j+1])   //going both sons
    {
        int M = St + S[i+1][j] - 1;
        if (L <= M)
        {
            DFq.push_back(j);
            Solve(St, M, i+1, j);
            DFq.pop_back();
        }
        if (M < R)
        {
            DFq.push_back(j+1);
            Solve(M+1, Dr, i+1, j+1);
            DFq.pop_back();
        }
    }
};
