#include <fstream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

ifstream is("poligon6.in");
ofstream os("poligon6.out");

int n,x[1001],Sol;
vector<pair<int,int> > V;
vector<int>  V2;

struct Criteria {
    bool operator()(const std::pair<int,int> &left, const std::pair<int,int> &right) {
        return left.first*right.second > left.second*right.first;
    }
};

int main()
{
    is >> n;
    int k;
    for ( int i = 1; i <= n; ++i )
    {
        is >> x[i];
        for ( int j = 1; j < sqrt((x[i]*x[i])/2); ++j )
        {
            k = sqrt(double(x[i]*x[i]-j*j));
            if ( k*k+j*j== x[i]*x[i] )
                V.push_back(make_pair(k,j));
        }
    }
    os << V.size()*2 << '\n';
    int aux(1);
    sort(V.begin(),V.end(),Criteria());
    for ( int i = 0; i < V.size()-1; ++i )
    {
        if ( V[i].first * V[i+1].second == V[i].second * V[i+1].first  )
        {
            aux++;
        }
        else
        {
            Sol++;
            V2.push_back(aux);
            aux=1;
        }
    }
    Sol++;
    os << Sol*2<< '\n';
    for ( int i = 0; i < V2.size(); ++i )
        os << V2[i] << " ";
    os << aux << " " << aux << " ";
    for ( int i = V2.size()-1; i >= 0; --i )
        os << V2[i] << " ";
    return 0;
}
