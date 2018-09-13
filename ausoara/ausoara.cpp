#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int main() {
    ifstream cin("ausoara.in");
    ofstream cout("ausoara.out");

    int N; cin >> N;
    vector<int> intersect;
    for (int i = 0; i < N; ++i) {
        int K; cin >> K;
        vector<int> V(K);
        for (int j = 0; j < K; ++j)
            cin >> V[j];

        if (i == 0) {
            intersect = V;
            continue;
        }

        vector<int> aux(K);
        aux.erase(set_intersection(intersect.begin(), intersect.end(), V.begin(), V.end(), aux.begin()), aux.end());
        swap(intersect, aux);
    }

    cout << intersect.size() << " ";
    for (int i = 0; i < int(intersect.size()); ++i)
        cout << intersect[i] << " ";

}
