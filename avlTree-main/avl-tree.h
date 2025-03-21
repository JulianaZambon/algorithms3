#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int chave;
    int altura;
    struct nodo *pai;
    struct nodo *filhoEsq;
    struct nodo *filhoDir;
} nodo;

typedef struct arvore {
    nodo *raiz;
} arvore;

/*Inicializa uma árvore vazia.*/
arvore *inicializaArvore();

/*Inicializa um nodo vazio.*/
nodo *inicializaNodo(int valor);

/*Calcula o máximo de dois números*/
int calculaMaximo(int a, int b);

/*É chamada pela função verificaBalancoArvore caso a árvore AVL esteja 
desbalanceada e precise de rotações à esquerda para ser balanceada*/  
nodo *rotacionaArvoreEsquerda(nodo *aux);

/*É chamada pela função verificaBalancoArvore caso a árvore AVL esteja 
desbalanceada e precise de rotações à direita para ser balanceada*/  
nodo *rotacionaArvoreDireita(nodo *aux);

/*Verifica se a árvore está balanceada e chama a função rotacionaArvore
caso seja necessário rotacioná-la para balanço*/
nodo *verificaBalancoArvore(nodo *raiz);

/*Insere um nodo específico na árvore*/
arvore *insereNodo(arvore *avl, nodo *novo);

/*Calcula a altura de um nó e a retorna.*/
int alturaNodo(nodo *nodo);

/*Verifica se um nodo está, ou não, presente em 
uma árvore. Caso esteja, o remove.*/
arvore *removeNodo(arvore *avl, int chave);

/*Verifica se um nodo está, ou não, presente na árvore. Caso 
esteja, retorna 1, caso não esteja retorna 0*/
int buscaNodo(nodo *raiz, int chave);

/*Imprime recursivamente a estrutura de uma árvore.*/
void imprimeArvore(nodo *avl);

/*Libera a memória alocada para uma árvore.*/
void destroiArvore(nodo *avl);