#include<stdio.h>
#include<stdlib.h>

typedef struct elemento	{
  char	valor;
  struct elemento	*proximo;
}	Elemento;

typedef struct fila	{
  Elemento	*cabeca;
  Elemento	*fim;
  int	tamanho;
}	Fila;

Fila*	iniciar();
void enqueue(Fila	*f,	char	caractere);
char dequeue(Fila	*f);
int	size(Fila	*f);
char	head(Fila	*f);
int	empty(Fila	*f);
void show(Fila *f);

int main() {
  Fila *f = iniciar();
  enqueue(f,'A');
  show(f);
  enqueue(f,'B');
  show(f);
  enqueue(f,'C');
  show(f);
  dequeue(f);
  show(f);
  dequeue(f);
  show(f);
  dequeue(f);
  show(f);
  dequeue(f);
  show(f);
  dequeue(f);
  show(f);
}

Fila*	iniciar() {
  Fila	*f	=	malloc(sizeof(Fila));
  f->cabeca	=	NULL;
  f->fim	=	NULL;
  f->tamanho	=	0;
  return	f;
}

void enqueue(Fila	*f,	char	caractere) {
  Elemento	*e	=	malloc(sizeof(Elemento));
  printf("Enqueue: %c\n",caractere);
  e->valor	=	caractere;
  e->proximo	=	NULL;
  if	(f->fim	!=	NULL)	{
		f->fim->proximo	=	e;
	}	else	{
		f->cabeca	=	e;
	}
  f->fim	=	e;
	f->tamanho	=	f->tamanho	+	1;
}

char dequeue(Fila	*f) {
	Elemento	*e;
  char	caracter;
  if	(!empty(f))	{
      printf("Dequeue\n");
  		e	=	f->cabeca;
  		caracter	=	e->valor;
  		f->cabeca	=	e->proximo;
  		if	(empty(f))	{
  			f->fim	=	NULL;
  		}
  		f->tamanho	=	f->tamanho	-	1;
  		free(e);
  		return	caracter;
  }	else	{
  		printf("Fila vazia. ");
  		return '\0';
  }
}

int	size(Fila	*f) {
			return	f->tamanho;
}

char	head(Fila	*f) {
			return	f->cabeca->valor;
}

int	empty(Fila	*f) {
  return	f->tamanho	==	0;
}

void show (Fila *f) {
  Elemento *tmp	=	malloc(sizeof(Elemento));
  tmp=f->cabeca;
  int tamanho = size(f);
  printf("Queue size: %i\n",tamanho);
  if (tamanho !=0) {
    while (tmp->proximo != NULL) {
      printf("%c ---> %p\n",tmp->valor,tmp->proximo);
      tmp=tmp->proximo;
    }
    printf("%c ---> %p\n\n",tmp->valor,tmp->proximo);
  }
}
