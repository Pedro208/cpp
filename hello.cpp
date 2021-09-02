#include <iostream>
#include <list>

using namespace std;

struct treenode
{
    int info;
    treenode *esq;
    treenode *dir;
};
typedef treenode *treenodeptr;

void tInsere(treenodeptr &p, int x)
{
    if (p == NULL) // insere na raiz
    {
        p = new treenode;
        p->info = x;
        p->esq = NULL;
        p->dir = NULL;
    }
    else if (x < p->info) // insere na subarvore esquerda
        tInsere(p->esq, x);
    else // insere na subarvore direita
        tInsere(p->dir, x);
}

void multiplos3(treenodeptr arvore)
{
    if (arvore != NULL)
    {
        if(arvore->info%3 == 0 )
            cout<<arvore->info;
        multiplos3(arvore->esq);
        multiplos3(arvore->dir);}
}

void tDestruir(treenodeptr arvore)
{
    if (arvore != NULL)
    {
        tDestruir(arvore->esq);
        tDestruir(arvore->dir);
        delete arvore;
    }
    arvore = NULL;
}

int main()
{

    treenodeptr arvore = NULL; // ponteiro para a árvore
    float n = 0,i=0;

    cin >> n;
    do
    {
        i++;
        tInsere(arvore, n);
        cin >> n;

    } while (n != -1);

    multiplos3(arvore);
    
    tDestruir(arvore);

    return 0;
}