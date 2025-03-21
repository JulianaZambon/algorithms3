#include <stdio.h>
#include <stdlib.h>
#include "avl-tree.h"

int main() {

    //Cria uma árvore AVL vazia.
    arvore *avl = inicializaArvore();
    char comando;
    int chave;

    while (scanf(" %c %d", &comando, &chave) != EOF) {
        printf("%c %d\n", comando, chave);
        
        if (comando == 'i') {
            //Insere nó na árvore.
            nodo *novo = inicializaNodo(chave);
            avl = insereNodo(avl, novo);
            imprimeArvore(avl->raiz);
            printf("\n");
        
        } else if (comando == 'r') {
            //Remove nó da árvore.
            avl = removeNodo(avl, chave);
            imprimeArvore(avl->raiz);
            printf("\n");
        
        } else if (comando == 'b') {
            //Se árvore é vazia, indica erro.
            if (avl->raiz != NULL) {

                //Imprime os nós consultados na busca.
                nodo *nodoEncontrado = avl->raiz;
                printf("%d", nodoEncontrado->chave);

                while (nodoEncontrado != NULL && nodoEncontrado->chave != chave) {
                    if (nodoEncontrado->chave < chave)
                        nodoEncontrado = nodoEncontrado->filhoDir;

                    else if (nodoEncontrado->chave > chave)
                        nodoEncontrado = nodoEncontrado->filhoEsq;

                    if (nodoEncontrado != NULL)
                        printf(",%d", nodoEncontrado->chave);
                }
                printf("\n");
            }
        }
    }

    //Libera a memória da árvore.
    destroiArvore(avl->raiz);
    free(avl);

    return 0;
}