#include "t_arquivo.h"

static int proximo(int);
static void apres(const char *, int);

void visualizao_hexa(FILE * pf)
{
        unsigned char buffer[1], caracteres[16];
        int i = 0;

        while(fread(buffer,1,1,pf)>0)
	{
                if(!(i%16))
		{
			if(i>0)
				apres(caracteres,0);
                        printf("\n0x%.8X:\t", i);
		}

		caracteres[proximo(i)] = *buffer;
		printf("%.2X", *buffer);
                	
		if(i%2)
                	putchar(' ');
                
		i++;
        }

	apres(caracteres,16-(i%16));

        putchar('\n');
}

static int proximo(int i)
{
	return i%16;
}

static void apres(const char * c, int offset)
{
	int i = 0, max = offset;

	while(offset--)
	{
		if(offset%2)
			printf("   ");
		else
			printf("  ");
	}

	printf("  ");

	while(i<16-max)
	{
		if(c[i] >= ' ' && c[i] <= '~')
			printf("%c", c[i]);
		else
			putchar('.');	
		i++;
	}
}
