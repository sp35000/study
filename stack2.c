#include<stdio.h>
#include<stdlib.h>

typedef struct elemento	{
  char	valor;
  struct elemento	*proximo;
}	Elemento;

typedef struct pilha	{
	Elemento	*topo;
  int	tamanho;
}	Pilha;

Pilha*	iniciar();
void push(Pilha	*p,	char	caractere);
int	empty(Pilha	*p);
char pop(Pilha	*p);
void show(Pilha *p);

int main() {
  Pilha *p = iniciar();
  push (p,'A');
  show (p);
  push (p,'B');
  show (p);
  push (p,'C');
  show (p);
  push (p,'D');
  show (p);

  pop (p);
  show (p);
  pop (p);
  show (p);
  pop (p);
  show (p);
  pop (p);
}

Pilha*	iniciar() {
  Pilha	*p	=	malloc(sizeof(Pilha));
  p->topo	=	NULL;
  p->tamanho	=	0;
  return	p;
}

void	push(Pilha	*p,	char	caractere) {
  Elemento	*e	=	malloc(sizeof(Elemento));
  e->valor	=	caractere;
  e->proximo	=	p->topo;
  p->topo	=	e;
  p->tamanho	=	p->tamanho	+	1;
}

char pop(Pilha	*p) {
	Elemento	*e;
  char	c;
if	(!empty(p))	{
		e	=	p->topo;
		c	=	e->valor;
		p->topo	=	p->topo->proximo;
		p->tamanho	=	p->tamanho	-	1;
		free(e);
		e	=	NULL;
		return	c;
	}	else	{
		printf("Pilha	vazia.\n\n");
		return '\0';
	}
}

int	size(Pilha	*p) {
			return	p->tamanho;
}

int	empty(Pilha	*p) {
  return	p->tamanho	==	0;
}

void show (Pilha *p) {
  Elemento *tmp	=	malloc(sizeof(Elemento));
  tmp=p->topo;
  printf("Stack size: %i\n",size(p));
  while (tmp->proximo != NULL) {
    printf("%c ---> %p\n",tmp->valor,tmp->proximo);
    tmp=tmp->proximo;
  }
  printf("%c ---> %p\n\n",tmp->valor,tmp->proximo);
}
