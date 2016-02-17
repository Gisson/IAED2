#include "funcoes.h"

/*\\\\\\\\\\\\\\\\\\\\\\\\Ficheiro funcoes.c\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*/////////////Ficheiro que inclui as funcoes usadas pela funcao main/////////*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

/*	Funcao send:
		Efeitos: Envia a mensagem info do utilizador e para o utilizador
		     r, colocando-a na lista de espera do utilizador r(vetor).*/
struct queue send(int e,int r,char* info, struct queue vetor)
{
	link x = Newlink(info, e, r);
	
	return insertEnd(vetor , x);
}

/*	Funcao process:
		Efeitos: Mostra no standard output a primeira mensagem da lista
			 recebida(list) e de seguida elimina-a da lista .*/
struct queue process(struct queue list)
{
	if (list.begin== NULL)
		printf("NULL\n");
	else{
		showlink(list.begin);
		list = deletebegin(list);
	}	
	return list;
}

/*	Funcao list:
		Efeitos: Mostra no standard output todos os elementos da 
			lista(list) por ordem de chegada.*/
void list(struct queue list)
{
	link aux=list.begin;
	
	if (aux == NULL)
		printf("NULL\n");
	else	
		while(aux !=NULL){
			showlink(aux);
			aux=aux->next;
		}
}

/*	Funcao kill:
		Efeitos: Elimina todas as mensagens em espera,na fila list,para
			 o utilizador(user).*/
void kill(queue_ptr list, int user)
{
	while(list[user].begin != NULL)
	{
		list[user] = deletebegin(list[user]);
	}
}

/*	Funcao listsorted:
	    Efeitos: Ordena por ordem alfabetica as mensagens no vetor(vetor).*/
void listsorted(struct queue vetor)
{
	int i;
	link* lista=(link *) malloc(vetor.cont*sizeof(link));
	if(vetor.cont==0)
		printf("NULL\n");
	else
	{
		morflista(vetor,lista);
		qsort( lista ,vetor.cont, sizeof(struct node *), cmplink);
		for (i = 0; i < vetor.cont;i++)
			printf("%d %d %s", lista[i]->item->re, lista[i]->item->em,lista[i]->item->ms);
	free(lista);
	}
}

/*	Funcao quit:
		Efeitos: Sai do programa eliminando todas as mensagens em espera
			 para todos os utilizadores.*/
void quit(queue_ptr vetor,int max_user)
{
	int i;

	for(i=0;i<max_user;i++)
		kill( vetor, i);
	free(vetor);
}
