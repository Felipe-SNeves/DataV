#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long int tamanho();
void visualizao_hexa(long int);
void visualizao_octal(long int);
void bin(unsigned n);
void visualizao_bin(long int);

FILE * pf;

int main(int argc, char ** argv)
{
	pf = NULL;

	switch(argc)
	{
		case 1: puts("Erro!"); exit(1);
		case 2: if((pf = fopen(*(argv+1), "rb"))==NULL)
			{
				puts("Não abri!");
				exit(1);
			}
	}

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
	int i = 0;

	fread(buffer,tam,1,pf);

	while(*ptr)
	{
		if(!(i%16))
			printf("\n0x%.8X\t", i);
		printf("%.2X", *ptr++);
		if(i%2)
			putchar(' ');
		i++;
	}
	putchar('\n');
	free(buffer);

}

void visualizao_octal(long int tam)
{
	unsigned char * buffer = (unsigned char *) malloc(tam);
	unsigned char * ptr = buffer;

	fread(buffer,tam,1,pf);

	while(*ptr)
		printf("%.3o ", *ptr++);

	putchar('\n');
	free(buffer);

}

void visualizao_bin(long int tam)
{
	unsigned char * buffer = (unsigned char *) malloc(tam);
	unsigned char * ptr = buffer;

	fread(buffer,tam,1,pf);

	while(*ptr)
	{
		bin(*ptr++);
		putchar(' ');
	}

	putchar('\n');
	free(buffer);

}

void bin(unsigned n)
{
    unsigned i;
    for(i = 1<< 7; i > 0; i = i / 2)
        (n & i) ? printf("1") : printf("0");
}
