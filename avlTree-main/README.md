# Algoritmos e Estrutura de Dados III

## Trabalho Prático 1: Implementação de Árvore AVL
Este trabalho prático foi desenvolvido para a disciplina CI1057 - Algoritmos e Estruturas de Dados 3 do Departamento de Informática da UFPR. <br>
O objetivo é implementar as rotinas de manipulação de uma árvore AVL.

Equipe: 
- Juliana Zambon (jz22), GRR20224168 <br>
- Millena Suiani Costa (msc22), GRR20221243 <br>

### Estruturas de Dados da Árvore AVL
A implementação da árvore AVL utilizou as seguintes estruturas definidas na biblioteca avl-tree.h :<br>

#### Struct Árvore AVL
  
  Contém um ponteiro para a raiz da árvore.
  
```c
typedef struct arvore {
    nodo *raiz;
} arvore;
```

#### Struct Nodos da Árvore
  
  Contém três ponteiros para nós, sendo eles o pai, o filho esquerdo e o filho direito. Além de
uma chave e a altura.
  
```c
typedef struct nodo {
    int chave;
    int altura;
    struct nodo *pai;
    struct nodo *filhoEsq;
    struct nodo *filhoDir;
} nodo;
```

### Bibliotecas desenvolvidas no Projeto
A biblioteca desenvolvida para o trabalho foi a avl-tree.h, que define as structs mencionadas anteriormente.
Também estão definidas as seguintes funções:
<br>
- `arvore *inicializaArvore();`
  - Inicializa uma árvore vazia.
   
- `nodo *inicializaNodo(int valor);`
  - Inicializa um nodo vazio.

- `int calculaMaximo(int a, int b);`
  - Calcula o máximo de dois números.
  
- `nodo *rotacionaArvoreEsquerda(arvore *avl);`
  - É chamada pela função verificaBalancoArvore caso a árvore AVL esteja 
desbalanceada e precise de rotações à esquerda para ser balanceada.

- `nodo *rotacionaArvoreDireita(arvore *avl);`
  - É chamada pela função verificaBalancoArvore caso a árvore AVL esteja
desbalanceada e precise de rotações à direita para ser balanceada.

- `nodo *verificaBalancoArvore(arvore *avl);` 
  - Verifica se a árvore está balanceada e chama a função rotacionaArvore
caso seja necessário rotacioná-la para balanço.

- `arvore *insereNodo(arvore *avl, nodo *novo);`
  - Insere um nodo específico na árvore.
  
- `int alturaNodo(nodo *nodo);`
  - Calcula a altura de um nó e a retorna.

- `arvore *removeNodo(arvore *avl, int chave);`
  - Verifica se um nodo está, ou não, presente em 
uma árvore. Caso esteja, o remove.

- `int buscaNodo(arvore *avl, int chave);`
  - Verifica se um nodo está, ou não, presente na árvore. Caso esteja,
retorna 1, caso não esteja retorna 0.

- `void imprimeArvore(arvore *avl);` 
  - Imprime recursivamente a estrutura de uma árvore.
 
- `void destroiArvore(arvore *avl);`
  - Libera a memória alocada para uma árvore.
