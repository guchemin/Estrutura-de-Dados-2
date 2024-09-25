#include <stdio.h>
#include <stdlib.h>

/*Estrutura para um nó em uma lista encadeada: */
typedef struct noA {
   int id;          /*Identificador armazenado no nó. */
   struct noA *next; /* Próximo nó na lista encadeada. */
} NoA;

/*Estrutura de Grafo com lista de adjacências: */
typedef struct grafoA {
   int E; /* Quantidade de arestas. */
   int V; /* Quantidade de vértices. */
   NoA **Adj; /* Lista de adjacências. */
} GrafoA;

/*Estrutura de Grafo com matriz de adjacências: */
typedef struct grafoM {
   int E; /* Quantidade de arestas. */
   int V; /* Quantidade de vértices. */
   int **Mat; /* Matrix de adjacências. */
} GrafoM;

/*Função para criar um grafo com lista de adjacências.*/
GrafoA* criar_grafo_adj (int tamanho) {
   int v;
   GrafoA *G = (GrafoA *)malloc(sizeof(GrafoA));
   G->E = 0;
   G->V = tamanho;
   G->Adj = (NoA **)malloc(tamanho * sizeof(NoA *));
   for (v = 0; v < G->V; v++) {
      G->Adj[v] = NULL;
   }
   return G;
}

/* Função para zerar a matriz */
void criar_mat_nula(GrafoM* G){
    int i, j;
    for(i = 0; i < G->V; i++){
        for(j = 0; j < G->V; j++){
            G->Mat[i][j] = 0;
        }
    }
}

/*Função para criar um grafo com matriz de adjacências.*/
GrafoM* criar_grafo_mat (int tamanho) {
   int v;
   GrafoM *G = (GrafoM *)malloc(sizeof(GrafoM));
   G->E = 0;
   G->V = tamanho;
   G->Mat = (int **)malloc(tamanho * sizeof(int *));
   for (v = 0; v < G->V; v++) {
      G->Mat[v] = (int *)malloc(tamanho * sizeof(int));
   }
   criar_mat_nula(G);
   return G;
}

/* Função para verificar se um vértice já existe no grafo */
int search_aresta_adj(GrafoA* G, int a, int b){
    NoA* temp;
    temp = G->Adj[a];

    while(temp != NULL){
        if(temp->id == b)
            return 1;
        temp = temp->next;
    }

    return 0;
}

/* Função para inserir vértice unidirecional */
void inserir_aresta_adj(GrafoA* G, int a, int b){
    if(search_aresta_adj(G, a, b)){
        printf("Aresta %d-%d ja incluida\n", a, b);
        return;
    }
    else{
        NoA* node;
        node = (NoA*)malloc(sizeof(NoA));
        node->id = b;
        node->next = G->Adj[a];
        G->Adj[a] = node;

        G->E++;
    }
}

/*Função para inserir vértice bidirecional */
void inserir_aresta_adj_bid(GrafoA* G, int a, int b){
    inserir_aresta_adj(G, a, b);
    inserir_aresta_adj(G, b, a);
}

void imprimir_grafo_adj (GrafoA *G) {
    int u;
    printf ("Grafo (lista adjacência):\n");
    for (u = 0; u < G->V; u++) {
        printf ("%2d -> ", u);
        NoA *v;
        for (v = G->Adj[u]; v != NULL; v = v->next) {
            printf ("%2d ", v->id);
        }
        printf ("\n");
    }
    printf ("\n");
}

/* Função para verificar se uma aresta ja existe*/
int search_aresta_mat(GrafoM* G, int a, int b){
    return G->Mat[a][b];
}

/* Função para inserir aresta unidirecional */
void inserir_aresta_mat(GrafoM* G, int a, int b){
    if(search_aresta_mat(G, a, b)){
        printf("Aresta %d-%d ja incluida\n", a, b);
        return;
    }
    else{
        G->Mat[a][b] = 1;
        G->E++;
    }
}

/* Função para inserir arestas bidirecionais */
void inserir_aresta_mat_bid(GrafoM* G, int a, int b){
    inserir_aresta_mat(G, a, b);
    inserir_aresta_mat(G, b, a);
}

void imprimir_grafo_mat (GrafoM *G) {
    int u, v;
    printf ("Grafo (matriz adjacência):\n");
    printf ("   ");
    //print índice das colunas
    for (u = 0; u < G->V; u++) {
        printf ("%2d ", u);
    }
    printf ("\n\n");
    for (u = 0; u < G->V; u++) { //print índice das linhas
        printf ("%2d ", u);
        for (v = 0; v < G->V; v++) {
            printf ("%2d ", G->Mat[u][v]);
        }
        printf ("\n");
    }
    printf ("\n");
}

/*Função para destruir um grafo construído com lista de adjacências.*/
void liberar_grafo_adj (GrafoA *G) {
   int v;
   for (v = 0; v < G->V; v++) {
      if (G->Adj[v] != NULL) {
         free(G->Adj[v]);
      }
   }
   free(G->Adj);
   free(G);
}

/*Função para destruir um grafo construído com lista de adjacências.*/
void liberar_grafo_mat (GrafoM *G) {
   int v;
   for (v = 0; v < G->V; v++) {
      if (G->Mat[v] != NULL) {
         free(G->Mat[v]);
      }
   }
   free(G->Mat);
   free(G);
}


/* */
int main () {
//-------EXERCICIO 1---------
//    int Va = 6; /*Número de vertices*/

//    GrafoA* Ga = criar_grafo_adj (Va);

//    inserir_aresta_adj_bid(Ga, 4, 5);
//    inserir_aresta_adj_bid(Ga, 3, 4);
//    inserir_aresta_adj_bid(Ga, 2, 4);
//    inserir_aresta_adj_bid(Ga, 2, 3);
//    inserir_aresta_adj_bid(Ga, 1, 3);
//    inserir_aresta_adj_bid(Ga, 1, 2);
//    inserir_aresta_adj_bid(Ga, 0, 5);
//    inserir_aresta_adj_bid(Ga, 0, 2);
//    inserir_aresta_adj_bid(Ga, 0, 1);

//    imprimir_grafo_adj(Ga);
    
//    int Vm = 6; /*Número de vértices*/

//    GrafoM* Gm = criar_grafo_mat (Vm);

//    inserir_aresta_mat_bid(Gm, 4, 5);
//    inserir_aresta_mat_bid(Gm, 3, 4);
//    inserir_aresta_mat_bid(Gm, 2, 4);
//    inserir_aresta_mat_bid(Gm, 2, 3);
//    inserir_aresta_mat_bid(Gm, 1, 3);
//    inserir_aresta_mat_bid(Gm, 1, 2);
//    inserir_aresta_mat_bid(Gm, 0, 5);
//    inserir_aresta_mat_bid(Gm, 0, 2);
//    inserir_aresta_mat_bid(Gm, 0, 1);

//    imprimir_grafo_mat(Gm);

//    liberar_grafo_adj (Ga);
//    liberar_grafo_mat (Gm);







//-------EXERCICIO 2---------
//    int Va = 6; /*Número de vertices*/

//    GrafoA* Ga = criar_grafo_adj (Va);

//    inserir_aresta_adj(Ga, 0, 5);
//    inserir_aresta_adj(Ga, 0, 1);
//    inserir_aresta_adj(Ga, 1, 3);
//    inserir_aresta_adj(Ga, 1, 2);
//    inserir_aresta_adj(Ga, 2, 4);
//    inserir_aresta_adj(Ga, 2, 0);
//    inserir_aresta_adj(Ga, 3, 2);
//    inserir_aresta_adj(Ga, 4, 3);
//    inserir_aresta_adj(Ga, 5, 4);

//    imprimir_grafo_adj(Ga);

//    liberar_grafo_adj (Ga);


//    int Vm = 6; /*Número de vértices*/

//    GrafoM* Gm = criar_grafo_mat (Vm);

//    inserir_aresta_mat(Gm, 0, 5);
//    inserir_aresta_mat(Gm, 0, 1);
//    inserir_aresta_mat(Gm, 1, 3);
//    inserir_aresta_mat(Gm, 1, 2);
//    inserir_aresta_mat(Gm, 2, 4);
//    inserir_aresta_mat(Gm, 2, 0);
//    inserir_aresta_mat(Gm, 3, 2);
//    inserir_aresta_mat(Gm, 4, 3);
//    inserir_aresta_mat(Gm, 5, 4);

//    imprimir_grafo_mat(Gm);

//    liberar_grafo_mat (Gm);





   return 0;
}