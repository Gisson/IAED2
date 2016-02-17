#include "funcoes.h"

/*\\\\\\\\\\\\\\\\\\\\\\\\Ficheiro aux.c\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/* Ficheiro que inclui as funcoes auxiliares as funcoes do programa principal*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/



/*	Funcao Newlink:
		Efeitos: Cria um novo node(item e ponteiro para proximo node).*/
link Newlink(char* info, int e, int r)
{
	int c = strlen(info);

	link novo = (link) malloc(sizeof(struct node));
	novo->item=(Item_ptr) malloc(sizeof(struct mensagem));
	novo->item->ms=(char*) malloc(c+1);
	novo-> item ->em = e;
	novo-> item ->re = r;
	strcpy(novo-> item ->ms,info);
	novo -> next = NULL;
	return novo;
}

/*	Funcao showlink:
		Efeitos: Mostra no standard output todos os valores na estrutura
			 link recebida.*/
void showlink (link x)
{
	printf("%d ", x->item->re);
	printf("%d ", x->item->em);
	printf("%s", x->item->ms);
}

/*	Funcao deletelink:
		Efeitos: Destroi todos os valores no link recebido.*/
void deletelink (link x)
{
	free(x->item->ms);
	free(x->item);
	free(x);
} 

/*	Funcao cmplink:
		Efeitos: Compara 2 links, mas compara so a mensagem e em caso de
			 igualdade compara tambem os emissores.*/
int cmplink (const void *a, const void* b){
	int c = strcmp((*(*(struct node **)a)->item).ms, (*(*(struct node **)b)->item).ms );
	if ( c!= 0)
		return c;
	else
		return ((*(*(struct node **)a)->item).em - (*(*(struct node **)b)->item).em);
}

/*	Funcao insertEnd:
		Efeitos: insere um link como ultimo elemento da 
			 struct queue(fila) recebida.*/
struct queue insertEnd(struct queue fila, link text)
{

	if(fila.begin==NULL){
		fila.begin=text;
		fila.end=text;
	}
	else{
		fila.end->next=text;
		fila.end=text;
	}
	fila.cont++;	
	return fila;		
}

/*	Funcao deletebegin:
		Efeitos: Elimina o primeiro link da fila recebida(fila).*/
struct queue deletebegin(struct queue fila)
{
	
	link aux = fila.begin;
	
	fila.begin = fila.begin->next;
	deletelink (aux);
	fila.cont--;
	return fila;

}

/*	Funcao morflista:
		Efeitos: Transforma uma struct queue(fila) num vetor.*/
void morflista(struct queue fila,link *links){

	int i;
	link begin_aux;
		
	begin_aux=fila.begin;
	for(i=0 ; i < fila.cont;i++)
	{
		links[i]=fila.begin;
		fila.begin=fila.begin->next;
	}
	fila.begin=begin_aux;
}
