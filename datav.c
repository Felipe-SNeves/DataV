#include "t_arquivo.h"

int main(int argc, char ** argv)
{
	FILE * pf = NULL;
	int i = 1;

	if(argc==1){
		puts("Sintaxe: datav arquivo_1, [arquivo_2], ... [arquivo_n]");
		exit(EXIT_FAILURE);
	}

	while(i<argc){
		
		if((pf=fopen(*(argv+i),"rb"))!=NULL){
			data_dump(pf,*(argv+i));
			fclose(pf);	
		}
		else
			printf("Nao foi possível abrir o arquivo %s\n\n", *(argv+i));

		i++;
	}

	exit(EXIT_SUCCESS);
}