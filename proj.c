#include "funcoes.h"

int main(int argc, char** argv)
{
	int n,e,r;
	char cmd[COMMAND+1], *info;	/*cmd e a variavel que guarda os 
					comandos(so pode ter 11 no maximo)*/
	queue_ptr user_vec;

	scanf("%d", &n);
	user_vec = (queue_ptr) calloc( n,sizeof(struct queue));
	scanf("%s", cmd);

	while(strcmp(cmd,"quit")!=0)
	{
		if(strcmp(cmd,"send")==0)
		{	
			info=(char*)(malloc(sizeof(char)*(MENSAGEM+1)));	
			scanf("%d", &e);
			scanf("%d", &r);
			getchar();
			fgets(info,MENSAGEM,stdin);
			user_vec[r] = send(e,r,info,user_vec[r]);
			free(info);
		}
		if(strcmp(cmd,"process")==0)
		{
			scanf("%d", &r);
			user_vec[r]=process(user_vec[r]);
		}
		
		
		if(strcmp(cmd,"list")==0)
		{
			scanf("%d", &r);
			list(user_vec[r]);
		}
		if(strcmp(cmd,"listsorted")==0)
		{
			scanf("%d", &r);
			listsorted( user_vec[r]);
		}
		if(strcmp(cmd,"kill")==0)
		{
			scanf("%d", &r);
			kill( user_vec, r);
		}
		scanf("%s", cmd);
	}
	quit(user_vec,n);
return 0;
}
