#include <fstream>
#include <cstring>
using namespace std;

ifstream is ("sub.in");
ofstream os ("sub.out");

struct Node{
    int Ap;
    bool Banned;
    Node *Son[26];
    Node() : Ap(1), Banned(0){
        memset(Son, 0, sizeof(Son));
    }
};

Node *Root = new Node;
int Na, Nb, Count;
char C[301];

void BuildTrie();
void Add(char*, Node *);
void Add(char*, Node *, int);
void BanSecvs();
void Denie(char*, Node*);

int main()
{
    BuildTrie();
    BanSecvs();
    os << Count;
    is.close();
    os.close();
}

void BuildTrie()
{
    is >> Na;
    is >> C;
    for (char *p = C; *p; ++p)
        Add(p, Root);
    for (int i = 2; i <= Na; ++i)
    {
        is >> C;
        for (char *p = C; *p; ++p)
            Add(p, Root, i);
    }
};

void Add(char *w, Node *X)
{
    if (*w == 0)
        return;
    if (X->Son[*w - 'a'] == 0)
    {
        X->Son[*w - 'a'] = new Node;
        if (Na == 1)
            Count++;
    }
    Add(w+1, X->Son[*w - 'a']);
};

void Add(char *w, Node *X, int k)
{
    if (*w == 0)
        return;

    if ( X->Son[*w - 'a'] && X->Son[*w - 'a']->Ap >= k-1)
    {
        if (k == Na && X->Son[*w - 'a']->Ap != k)
            Count++;
        X->Son[*w - 'a']->Ap = k;
        Add(w+1, X->Son[*w - 'a'], k);
    }
};

void BanSecvs()
{
    is >> Nb;
    for (int i = 1; i <= Nb; ++i)
    {
        is >> C;
        for (char *p = C; *p; ++p)
            Denie(p, Root);
    }
};

void Denie(char *w, Node *X)
{
    if (*w == 0) return;
    if (X->Son[*w - 'a'] && X->Son[*w - 'a']->Ap == Na)
    {
        if (X->Son[*w - 'a']->Banned == 0)
            Count--;
        X->Son[*w - 'a']->Banned = 1;
        Denie(w+1, X->Son[*w - 'a']);
    }
};
