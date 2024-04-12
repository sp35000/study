#include<stdio.h>
#include<stdlib.h>

typedef struct elemento	{
  char	valor;
  struct elemento	*proximo;
}	Elemento;

typedef struct lista	{
  Elemento	*inicio;
  int	tamanho;
}	Lista;

Lista* iniciar();
void add(Lista	*l,	char	caractere);
void add_pos(Lista	*l,	char	caractere,int posicao);
int	empty(Lista	*l);
void delete(Lista	*l,	int	posicao);
char get(Lista	*l,	int	posicao);
void set(Lista	*l,	char	caractere,	int	posicao);
void show(Lista *l);
int	size(Lista	*l);

int main() {
  Lista *l = iniciar();
  add_pos(l,'H',1);
  add(l,'G');
  add_pos(l,'F',1);
  add(l,'E');
  add(l,'D');
  add(l,'C');
  add(l,'B');
  add(l,'A');
  add_pos(l,'*',5);
  set(l,'#',5);
  get(l,1);
  get(l,2);
  get(l,3);
  get(l,4);
  get(l,5);
  get(l,6);
  get(l,7);
  get(l,8);
  delete(l,8);
  delete(l,7);
  delete(l,6);
  delete(l,5);
  delete(l,4);
  delete(l,3);
  delete(l,2);
  delete(l,1);
  delete(l,1);
}

Lista* iniciar() {
  Lista	*l	=	malloc(sizeof(Lista));
  l->inicio	=	NULL;
  l->tamanho	=	0;
  return l;
}

void add(Lista	*l,	char	caractere) {
  Elemento	*e	=	malloc(sizeof(Elemento));
  printf("Add: %c ",caractere);
  if (empty(l)) {
    Elemento *e = malloc(sizeof(Elemento));
    e->valor	=	caractere;
    e->proximo	=	NULL;
    l->inicio = e;
  } else {
    Elemento *e = malloc(sizeof(Elemento));
    e->valor	=	caractere;
    Elemento *antigo_inicio = l->inicio;
    l->inicio = e;
    e->proximo = antigo_inicio;
  }
  l->tamanho = l->tamanho + 1;
  show(l);
}

void add_pos(Lista	*l,	char	caractere,int posicao){
  printf("[%i]=%c ",posicao,caractere);
  if (empty(l)) {
    printf("Lista	vazia. Add posicional não permitido!\n");
		return;
  }
  if	(posicao	>	l->tamanho	||	posicao	<=	0)	{
		printf("Posição	inválida!\n");
		return;
	}
  if	(posicao	==	1)	{
		add(l,	caractere);
		return;
	}
  Elemento *e_atual=l->inicio; // e_atual
  printf("%p\n", &e_atual);
  Elemento *e_anterior;

  Elemento *e	=	malloc(sizeof(Elemento)); // e_atual, e
	e->valor	=	caractere;

  int	i;
  for	(i	=	1;	i	<	posicao	;	i++)	{
		e_anterior	=	e_atual;
		e_atual	=	e_atual->proximo; // e_anterior, e_atual --> e_atual, e_atual->proximo
    printf("%i %c,%c: ",i,e_anterior->valor,e_atual->valor);
    show(l);
	}
  e_anterior->proximo	=	e; // e_anterior,e,e_atual
  e->proximo	=	e_atual;
  l->tamanho	=	l->tamanho	+	1;
}

char	get(Lista	*l,	int	posicao) {
  if	(empty(l))	{	/*I*/
  		printf("Lista	vazia.\n");
  		return '\0';
  	}
  if	(posicao	>	l->tamanho	||	posicao	<=	0)	{
  		printf("Posição	inválida!\n");
  		return '\0';
  	}
  int	i	=	1;	/*III*/
  	Elemento	*e	=	l->inicio;
  while	(e->proximo	!=	NULL)	{
  		if	(i	==	posicao)	{
        printf("Get[%i]-->%c\n",posicao,e->valor);
  			return	e->valor;
  		}	else	{
  			e	=	e->proximo;
  			i++;
  		}
  	}
  return '\0';
}

void	set(Lista	*l,	char	caractere,	int	posicao) {
  printf("Set[%i]=%c ",posicao,caractere);
  if	(empty(l))	{	/*I*/
  		printf("Lista	vazia.	Set	não	permitido!\n");
  		return;
  	}
  if	(posicao	>	l->tamanho	||	posicao	<=	0)	{
  		printf("Posição	inválida!\n");
  		return;
  	}
  int	i	=	1;
  	Elemento	*e	=	l->inicio;
  while	(e->proximo	!=	NULL)	{
  		if	(i	==	posicao)	{
  			e->valor	=	caractere;
        return;
      }	else	{
        e	=	e->proximo;
        i++;
      }
    }
}

int	size(Lista	*l) {
			return	l->tamanho;
}

int	empty(Lista	*l) {
  return	l->tamanho	==	0;
}

void delete(Lista	*l,	int	posicao) {
  if	(empty(l))	{
    printf("Lista	vazia.	Delete	não	permitido!\n");
    return;
  }
  if	(posicao	>	l->tamanho	||	posicao	<=	0)	{
    printf("Posição	inválida!\n");
    return;
  }
  if	(posicao	==	1)	{
    Elemento	*e	=	l->inicio;
    char	caracter	=	e->valor;
    l->inicio	=	e->proximo;
    free(e);
    l->tamanho	=	l->tamanho	-	1;
    printf("Delete[%i]-->%c\n",posicao,caracter);
  }	else	{
    Elemento	*e_atual	=	l->inicio;
    Elemento	*e_anterior;
    int	i;
    for(i	=	1;	i	<	posicao	;	i++){
      e_anterior	=	e_atual;
      e_atual	=	e_atual->proximo;
      printf("%i %c,%c: ",i,e_anterior->valor,e_atual->valor);
  }
  char	caracter	=	e_atual->valor;
  e_anterior->proximo	=	e_atual->proximo;
  free(e_atual);
  l->tamanho	=	l->tamanho	-	1;
  printf("Delete[%i]-->%c\n",posicao,caracter);
  }
  show(l);
}

void show (Lista *l) {
  int tamanho = size(l);
  printf("List size: %i ",tamanho);
  if (tamanho !=0) {
    Elemento *tmp	=	malloc(sizeof(Elemento));
    tmp=l->inicio;
    int i=0;
    while (tmp->proximo != NULL) {
      printf("[%i]=%c,",i,tmp->valor);
      tmp=tmp->proximo;
      i++;
    }
    printf("[%i]=%c\n\n",i,tmp->valor);
  }
}
