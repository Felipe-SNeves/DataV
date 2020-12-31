#include "t_arquivo.h"

int main(int argc, char ** argv)
{
	FILE * pf = NULL;

	switch(argc)
	{
		case 1: puts("Erro!"); exit(1);
		case 2: if((pf = fopen(*(argv+1), "rb"))==NULL)
			{
				puts("Não abri!");
				exit(1);
			}
	}

	visualizao_hexa(pf);

}
