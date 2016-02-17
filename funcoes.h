#ifndef FUNCOES_H
#define FUNCOES_H

#define COMMAND 11
#define MENSAGEM 500

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*////////////////////////////////ESTRUTURAS////////////////////////////////////
Ficheiro que contem todas as estruturas utilizadas pelo programa
				(incluido por todos os ficheiros)*/

/*Estutura de mensagems que tem o emissor(em) recetor(re) e a 
				mensagem (char pointer ms)*/
typedef struct mensagem{
	int em;
	int re;
	char *ms;
} *Item_ptr;

/*Estrutura de node que contem um item e um ponteiro para o proximo node*/
typedef struct node{
	Item_ptr item;
	struct node *next;
}*link;

/*Estrutura queue que contem o inicio da lista(begin), o fim da lista(end) e um
		 contador que guarda o numero de elementos na lista(cont)*/
typedef struct queue{
	link begin;
	link end;
	int cont;
} *queue_ptr;

/*Declaracao das funcoes usadas pela main*/
struct queue send(int e,int r,char* info, struct queue vetor);
struct queue process(struct queue vetor);
void list(struct queue vetor);
void listsorted(struct queue vetor);
void kill( queue_ptr vetor, int user);
void quit(queue_ptr vetor,int max_utilizadores);

/*Declaracao de funcoes auxiliares*/
link Newlink(char* info, int e, int r);
void showlink(link x);
void deletelink(link x);
int cmplink (const void *a, const void* b);
struct queue deletebegin(struct queue fila);
struct queue insertEnd(struct queue fila, link text);
void morflista(struct queue fila,link *links);

#endif

