#include <stdio.h>
#include <stdlib.h>
#include "avl-tree.h"

/*Inicializa uma árvore vazia.*/
arvore *inicializaArvore() {
    arvore *AVL = (arvore *)malloc(sizeof(arvore));
    AVL->raiz = NULL;
    return AVL;
}

/*Inicializa um nodo vazio.*/
nodo *inicializaNodo(int valor) {
    nodo *novo = malloc(sizeof(nodo));
    novo->chave = valor;
    novo->altura = 1;
    novo->filhoEsq = NULL;
    novo->filhoDir = NULL;
    novo->pai = NULL;
    return novo;
}

/*Calcula o máximo de dois números.*/
int calculaMaximo(int a, int b) {
    if (a > b)
        return a;
    return b;
}

/*É chamada pela função verificaBalancoArvore caso a árvore AVL esteja 
desbalanceada e precise de rotações à direita para ser balanceada.*/  
nodo *rotacionaArvoreDireita(nodo *raiz) {
    nodo *aux = raiz->filhoEsq;
    
    //Realiza a rotação.   
    raiz->filhoEsq = aux->filhoDir;
    aux->filhoDir = raiz;
    
    //Atualiza as alturas após a rotação. 
    raiz->altura = calculaMaximo(alturaNodo(raiz->filhoEsq), alturaNodo(raiz->filhoDir)) + 1;
    aux->altura = calculaMaximo(alturaNodo(aux->filhoEsq), alturaNodo(aux->filhoDir)) + 1;
    
    return aux;
}

/*É chamada pela função verificaBalancoArvore caso a árvore AVL esteja 
desbalanceada e precise de rotações à esquerda para ser balanceada.*/  
nodo *rotacionaArvoreEsquerda(nodo *raiz) {
    nodo *aux = raiz->filhoDir;
    
    //Realiza a rotação.
    raiz->filhoDir = aux->filhoEsq;
    aux->filhoEsq = raiz;
    
    //Atualiza as alturas após a rotação.
    raiz->altura = calculaMaximo(alturaNodo(raiz->filhoEsq), alturaNodo(raiz->filhoDir)) + 1;
    aux->altura = calculaMaximo(alturaNodo(aux->filhoEsq), alturaNodo(aux->filhoDir)) + 1;
    
    return aux;
}

/*Verifica se a árvore está balanceada e chama as funções de 
rotação caso seja necessário rotacioná-la para balanço.*/
nodo *verificaBalancoArvore(nodo *raiz) {
    int balanco = alturaNodo(raiz->filhoEsq) - alturaNodo(raiz->filhoDir);

    if (balanco > 1) {
        if (alturaNodo(raiz->filhoEsq->filhoEsq) >= alturaNodo(raiz->filhoEsq->filhoDir))
            raiz = rotacionaArvoreDireita(raiz);
        else {
            raiz->filhoEsq = rotacionaArvoreEsquerda(raiz->filhoEsq);
            raiz = rotacionaArvoreDireita(raiz);
        }
    
    } else if (balanco < -1) {
        if (alturaNodo(raiz->filhoDir->filhoDir) >= alturaNodo(raiz->filhoDir->filhoEsq))
            raiz = rotacionaArvoreEsquerda(raiz);
        else {
            raiz->filhoDir = rotacionaArvoreDireita(raiz->filhoDir);
            raiz = rotacionaArvoreEsquerda(raiz);
        }
    }

    return raiz;
}

/*Insere um nodo específico na árvore.*/
arvore *insereNodo(arvore *avl, nodo *novo) {
    
    //Se a árvore for vazia, a raiz recebe o nodo.
    if (avl->raiz == NULL) {
        avl->raiz = novo;
        return avl;
    }

    //Verifica a posição correta para se colocar o nó.
    nodo *raiz = avl->raiz;
    nodo *pai = NULL;
    while (raiz != NULL) {
        pai = raiz;

        if (novo->chave < raiz->chave)
            raiz = raiz->filhoEsq;
        else
            raiz = raiz->filhoDir;
    }

    //Insere o nó e atualiza o número de nós da árvore.
    if (novo->chave < pai->chave)
        pai->filhoEsq = novo;
    else
        pai->filhoDir = novo;
    novo->pai = pai;

    //Atualiza as alturas da árvore.
    nodo *aux = novo->pai;
    while (aux != NULL) {
        aux->altura = calculaMaximo(alturaNodo(aux->filhoEsq), alturaNodo(aux->filhoDir)) + 1;
        aux = aux->pai;
    }

    avl->raiz = verificaBalancoArvore(avl->raiz);
    return avl;
}

/*Calcula a altura de um nó e a retorna.*/
int alturaNodo(nodo *nodo) {
    if (nodo == NULL)
        return 0;
    return nodo->altura;
}

/*Verifica se um nodo está, ou não, presente em 
uma árvore. Caso esteja, o remove.*/
arvore *removeNodo(arvore *avl, int chave) {
    
    //Se a árvore é vazia, a retorna.
    if (avl->raiz == NULL)
        return avl;

    //Verifica a posição do nó a ser removido.
    nodo *raizAux = avl->raiz;
    nodo *pai = NULL;
    while (raizAux != NULL && raizAux->chave != chave) {
        pai = raizAux;

        if (chave < raizAux->chave)
            raizAux = raizAux->filhoEsq;
        else
            raizAux = raizAux->filhoDir;
    }
    
    //Se a árvore é vazia, a retorna.
    if (raizAux == NULL)
        return avl;

    //Remove o nó e atribui os valores necessários para cada ponteiro.
    if (raizAux->filhoEsq == NULL || raizAux->filhoDir == NULL) {
        nodo *filho = raizAux->filhoEsq ? raizAux->filhoEsq : raizAux->filhoDir;

        if (filho == NULL) {
            if (pai == NULL)
                avl->raiz = NULL;
            else {
                if (raizAux == pai->filhoEsq)
                    pai->filhoEsq = NULL;
                else
                    pai->filhoDir = NULL;
            }
        } else {
            if (pai == NULL)
                avl->raiz = filho;
            
            else {
                if (raizAux == pai->filhoEsq)
                    pai->filhoEsq = filho;
                else
                    pai->filhoDir = filho;
            }
            filho->pai = pai;
        }
        free(raizAux);
    
    } else {
        nodo *sucessor = raizAux->filhoDir;
        
        while (sucessor->filhoEsq != NULL)
            sucessor = sucessor->filhoEsq;

        raizAux->chave = sucessor->chave;
        avl = removeNodo(avl, sucessor->chave);
    }

    //Se a árvore é vazia, a retorna.
    if (avl->raiz == NULL)
        return avl;

    //Atualiza as alturas da árvore.
    nodo *aux = avl->raiz;
    while (aux != NULL) {
        aux->altura = calculaMaximo(alturaNodo(aux->filhoEsq), alturaNodo(aux->filhoDir)) + 1;
        aux = aux->pai;
    }

    avl->raiz = verificaBalancoArvore(avl->raiz);
    return avl;
}

/*Verifica se um nodo está, ou não, presente na árvore. Caso
esteja, retorna 1, caso não esteja retorna 0.*/
int buscaNodo(nodo *raiz, int chave) {
    if (raiz == NULL)
        return 0;

    /*Se a árvore não for vazia, verifica 
    se o nó em questão é encontrado.*/
    if (raiz->chave == chave)
        return 1;

    if (raiz->chave > chave)
        return buscaNodo(raiz->filhoEsq, chave);

    return buscaNodo(raiz->filhoDir, chave);
}

/*Imprime recursivamente a estrutura de uma árvore.*/
void imprimeArvore(nodo *avl) {

    if (avl != NULL) {
        printf("(%d,", avl->chave);
        imprimeArvore(avl->filhoEsq);
        printf(",");
        imprimeArvore(avl->filhoDir);
        printf(")");
    
    } else
        printf("()");
}

/*Libera a memória alocada para uma árvore.*/
void destroiArvore(nodo *avl) {
    if (avl != NULL) {
        destroiArvore(avl->filhoEsq);
        destroiArvore(avl->filhoDir);
        free(avl);
    }
}