#include "arvore.h"


Arvore* cria_arv_vazia (void) {
   return NULL;
}

Arvore* constroi_arv (char c, Arvore *e, Arvore *d) {
   Arvore *no = (Arvore*)malloc(sizeof(Arvore));
   no->info = c;
   no->esq = e;
   no->dir = d;
   return no;
}

int verifica_arv_vazia (Arvore *a) {
   return (a == NULL);
}

void arv_libera (Arvore* a) {
   if (!verifica_arv_vazia(a)) {
      arv_libera (a->esq);
      arv_libera (a->dir);
      free(a);
   }
}

//========= Exercício 2 - pré-ordem ====
void pre_ord(Arvore *a){
   if(a != NULL){
      printf("%c ", a->info);
      pre_ord(a->esq);
      pre_ord(a->dir);
   }
}

//========= Exercício 2 - in-ordem ====
void in_ord(Arvore *a){
   if(a != NULL){
      in_ord(a->esq);
      printf("%c ", a->info);
      in_ord(a->dir);
   }
    
}

//========= Exercício 2 - pós-ordem ====
void pos_ord(Arvore *a){
   if(a != NULL){
      pos_ord(a->esq);
      pos_ord(a->dir);
      printf("%c ", a->info);
   }

}

//========= Exercício 3 - pertence ====
int pertence_arv(Arvore *a, char c){
   if(a == NULL)
      return 0;
   return (a->info == c) || pertence_arv(a->esq, c) || pertence_arv(a->dir, c);
}

//========= Exercício 4 - conta nós ====
int conta_nos(Arvore *a){
   if(a == NULL)
      return 0;
   return 1 + conta_nos(a->esq) + conta_nos(a->dir);
}

//========= Exercício 5 - calcula altura ====
int calc_alt(Arvore *a){
   if(a == NULL)
      return -1;
   int alt_e = calc_alt(a->esq), alt_d = calc_alt(a->dir);
   
   return (alt_e >= alt_d ? alt_e : alt_d)
}

//========= Exercício 6 - conta folhas ====
int conta_nos_folha(Arvore *a){
   if(a == NULL)
      return 0;

   if(a->dir == NULL && a->esq == NULL)
      return 1;

   return conta_nos_folha(a->esq) + conta_nos_folha(a->dir);
}


int main (int argc, char *argv[]) {

   Arvore *a = constroi_arv ('a',
       constroi_arv('b',
       cria_arv_vazia(),
       constroi_arv('d', cria_arv_vazia(),cria_arv_vazia())
     ),
     constroi_arv('c',
       constroi_arv('e',cria_arv_vazia(),cria_arv_vazia()),
       constroi_arv('f',cria_arv_vazia(),cria_arv_vazia())
     )
   );
   //pre_ord(a);	
   //in_ord(a);
   //pos_ord(a);
   //printf("pertence: %d\n", pertence_arv(a, 'j')); 
   //printf("o numero de nos eh: %d\n", conta_nos(a));
   //printf("a altura da arvore eh: %d\n", calc_alt(a));
   //printf("o numero de folhas na arvore eh: %d\n", conta_nos_folha(a));

   arv_libera (a);

   return 0;
}
