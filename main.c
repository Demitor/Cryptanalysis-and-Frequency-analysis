
/**************************************************************/
/* DVGC19 decryptation program                                */
/**************************************************************/
/* A. PAYNE & A. KÄCK - test version                          */
/**************************************************************/

/**************************************************************/
/* include files and  global data objects                     */
/**************************************************************/

#include <stdio.h>

/**************************************************************/
/* define constants & types                                   */
/**************************************************************/

#define ARRLEN 27
#define ABCLEN 26


/**************************************************************/
/* define variables                                           */
/**************************************************************/

double x[ARRLEN], p[ARRLEN];
char a[ARRLEN] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',' '};
char dec[ARRLEN] = {'b','k','u','n','f','x','w',' ','h','j','r','g','q','l','z','p','t','c','s','y','e','o','m','d','a','i','v'};
int total = 0;
char *mode = "r";
double f[ARRLEN] = {6.9, 0.4, 3.0, 3.2, 8.7, 2.3, 2.1, 2.7, 7.5, 0.1, 0.5, 4.6, 2.2, 7.0, 5.2, 1.7, 0.1, 4.6, 5.3, 6.1, 2.7, 1.5, 0.4, 0.2, 1.0, 0, 19.7};
int key = 0;

/****************************************************************************/
/* calculates the number of letters occurring in percent                    */
/****************************************************************************/

void percent()
{
	int i = 0;
	while(i <= ABCLEN)
	{
		p[i] = (x[i]/total)*100;
		i++;
	}
}

/****************************************************************************/
/* decrypts message                                                         */
/****************************************************************************/

int decrypt()
{
	while()
	
	/*
	Encryption:

	c = m + e mod(ABCLEN)
	

	Decryption:

	m = c + d mod(ABCLEN)

	c = ciphertext
	m = message
	e = Encryption key
	d = decryption key
	*/
} 

/* Prints the arrays */
void printarr()
{
	char abc = 'a';
	int i = 0;
	while(i < ABCLEN)
	{
	printf("%c : %g\t\t%c : %g\t\t%c : %g\n", abc, x[i], abc, f[i], abc, p[i]);
	i++;
	abc++;
	}
	abc = ' ';
	i = ABCLEN;
	printf("%c : %g\t\t%c : %g\t%c : %g\n", abc, x[i], abc, f[i], abc, p[i]);
}

/* Counts the number of every letter occurring */ 
int countChar(int y)
{
	printf("Current char: %c\n", y);
	FILE *fp;
	fp = fopen("cipher.in", mode);
	int c = 0;
	int count = 0;
	if (fp == NULL)
	{
		printf("%s\n", "File cannot be opened...");
	}
	
	while(!feof(fp))
	{
		c = fgetc(fp);
		printf("c = %c\n", c);
		//printf("y = %c\n", y);
		if (c == y)
		{
			count++;
			total++;
		}
	}
	fclose(fp);
	printf("Number of chars: %d\n", count);
	return count;
}

/* main - Calls every function */ 
int main(int argc, char const *argv[])
{
	char i = 'a';
	int j = 0;
	while(i <= 'z') 
	{
		printf("\nj : %d\n", j);
		x[j] = countChar(i);
		i++;
		j++;
	}
	//printf("%c\n", i);

	i = ' ';
	printf("%d\n", j);
	x[j] = countChar(i);
	percent();
	printarr();
	printf("%s%d\n", "Total characters: ", total);

	return 0;
}

/****************************************************************************/
/****************************************************************************/
/* public operations                                                        */
/****************************************************************************/
/****************************************************************************/

void printc()			{ printcrypted(); 	}
void printd();			{ printdecrypted(); }
void analysec();		{ analyse
void decryptt();

/****************************************************************************/
/* end of basic functions                                                   */
/****************************************************************************/