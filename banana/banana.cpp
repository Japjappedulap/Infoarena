#include <fstream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

#define fir first.first
#define sec first.second
#define ban second
#define TEMP pair <pair <int,int>, bool>

ifstream is ("banana.in");
ofstream os ("banana.out");

int nr, k, x, y, area, sol;

const int di[] = {-1, 0, 1,  0}, dj[] = { 0, 1, 0, -1};

vector <TEMP> v;
vector <int> zone;
queue <TEMP> q;

void BFS();
vector <TEMP> :: iterator BinarySearch(TEMP val);

int main()
{
    is >> nr >> k;
    for (int i = 0; i < nr; ++i)
    {
        is >> x >> y;
        v.push_back(make_pair(make_pair(x, y), false));
    }
    sort(v.begin(), v.end());
    BFS();
    sort(zone.begin(), zone.end());
    for (vector <int> :: reverse_iterator rit = zone.rbegin(); rit != zone.rend() && k > 0; ++rit, --k)
        sol += *rit;
    os << sol;
    is.close();
    os.close();
    return 0;
}

vector <TEMP> :: iterator BinarySearch(TEMP val)
{
    if (binary_search(v.begin(), v.end(), val))
    {
        vector <TEMP> :: iterator it = lower_bound(v.begin(), v.end(), val);
        return it;
    }
    return v.end();
};

void BFS()
{
    int i, j;
    TEMP next, ac;
    vector <TEMP> :: iterator it = v.begin();
    vector <TEMP> :: iterator iter;
    for( ; it != v.end(); ++it)
        if ((*it).ban == false)
        {
            q.push(*it);
            (*it).ban = true;
            area = 0;
            while (!q.empty())
            {
                area++;
                ac = q.front(), q.pop();
                i = ac.fir;
                j = ac.sec;
                for (int dir = 0; dir < 4; dir++)
                {
                    next.fir = i + di[dir];
                    next.sec = j + dj[dir];
                    iter = BinarySearch(next);
                    if (iter != v.end())
                        if ((*iter).ban == false)
                        {
                            ac.fir = (*iter).fir, ac.sec = (*iter).sec;
                            (*iter).ban = true;
                            q.push(ac);
                        }
                }
            }
            zone.push_back(area);
        }
};
