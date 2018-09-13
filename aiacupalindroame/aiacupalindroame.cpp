#include <fstream>
#include <vector>
#include <cstring>
#include <string>
using namespace std;
ifstream fin ("aiacupalindroame.in");
ofstream fout ("aiacupalindroame.out");

const int Nmax = 200001;
const int Qmax = 500001;

struct Trie_node{
    Trie_node* next[26];
    int id;
    Trie_node(){
        memset(next, 0, sizeof(next));
        id = 0;} };
Trie_node *Root_trie;
int id_cnt = 2;
int Id_solve[Nmax+1];
void DF_solve(int x, Trie_node* cur_trie);
bool Query(int x, int y);

int N, Q;
int T[Nmax+1];
string edges;
vector <pair<int, char> > Tree[Nmax];

void Input();
bool Query(int x, int y);
string get_chain(int node);

int main()
{
    Input();
    Root_trie = new Trie_node();
    Root_trie->id = 1;
    DF_solve(1, Root_trie);
    for (int x, y; Q; --Q)
    {
        fin >> x >> y;
        fout << Query(x, y) << '\n';
    }
    return 0;
};

void Input()
{
    fin >> N >> Q;
    for (int i = 2, x; i <= N; ++i)
        fin >> T[i];
    fin >> edges;
    for (int i = 2; i <= N; ++i)
    {
        Tree[T[i]].push_back({i, edges[i-2]});
    }
};

bool Query(int x, int y)
{
    if (Id_solve[x] == Id_solve[y])
        return true;
    return false;
};
void DF_solve(int x, Trie_node* cur_trie)
{
    Id_solve[x] = cur_trie->id;
    for (const auto& nxt : Tree[x])
    {
        if (cur_trie->next[nxt.second - 'a'] == 0)
        {
            cur_trie->next[nxt.second - 'a'] = new Trie_node();
            cur_trie->next[nxt.second - 'a']->id = id_cnt;
            id_cnt++;
        }
        DF_solve(nxt.first, cur_trie->next[nxt.second - 'a']);
    }
};
