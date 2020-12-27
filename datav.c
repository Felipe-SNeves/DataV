#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE * pf;

int main(int argc, char ** argv)
{
	FILE * pf = NULL;

	pf = fopen(*(argv+1), "rb");

	visualizao_hexa(tamanho());

}

long int tamanho()
{
	int aux;

	fseek(pf,0,SEEK_END);
	aux = ftell(pf);
	rewind(pf);

	return aux;
}

void visualizao_hexa(long int tam)
{
	unsigned char * buffer = (unsigned char *) malloc(tam);
	unsigned char * ptr = buffer;

	fread(buffer,tam,1,pf);

	while(*ptr)
		printf("%u", *ptr++);

	free(buffer);
}
