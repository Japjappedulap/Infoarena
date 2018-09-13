#include <fstream>
#include <vector>
using namespace std;

ifstream is ("minim.in");
ofstream os ("minim.out");

int N, S[1004], sum, I, J, aux, x;
vector <int> v, pos;

int main()
{
    is >> N;
    for (int i = 0, x; i < N; ++i)
        is >> x, v.push_back(-x), pos.push_back(i);
    while (!v.empty())
    {
        sum = -2e8;
        I = J = aux = x = 0;
        S[0] = v[0];
        for (int i = 1; i < v.size(); ++i)
            S[i] = S[i-1]+v[i];
        for (int i = 0; i < v.size(); ++i)
        {
            if (sum < S[i] - x) sum = S[i] - x, I = aux, J = i;
            if (x > S[i]) x = S[i], aux = i+1;
        }
        os << -sum << ' ' << pos[I]+1 << ' ' << pos[J]+1 << '\n';
        v.erase(v.begin()+I, v.begin()+J+1);
        pos.erase(pos.begin()+I, pos.begin()+J+1);
    }
    is.close();
    os.close();
}
