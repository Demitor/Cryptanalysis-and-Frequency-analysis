
/**************************************************************/
/* DVGC19 decryption program                                */
/**************************************************************/
/* A. PAYNE & A. KÄCK - test version                          */
/**************************************************************/

/**************************************************************/
/* include files and  global data objects                     */
/**************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>

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
char dec[ARRLEN] = {'b','k','u','n','f','x','w',' ','h','t','r','g','q','l','z','p','j','c','s','y','e','o','m','d','a','i','v'};
char cry[ARRLEN] = {'r','f','q','b','c','g','a','y','k',' ','t','s','u','j','d','h','e','i','l','o','w','z','n','x','v','m','p'};
double f[ARRLEN] = {6.9, 0.4, 3.0, 3.2, 8.7, 2.3, 2.1, 2.7, 7.5, 0.1, 0.5, 4.6, 2.2, 7.0, 5.2, 1.7, 0.1, 4.6, 5.3, 6.1, 2.7, 1.5, 0.4, 0.2, 1.0, 0, 19.7};

int total = 0;
int key = 0;

char *read = "r", *write = "w";



/****************************************************************************/
/* checks if file can be opened                                             */
/****************************************************************************/

static void checkfile(FILE *file)
{
	if (file == NULL){ printf("%s\n", "File cannot be opened..."); }
}



/****************************************************************************/
/* lists all available text files                                           */
/****************************************************************************/

static void listfiles()
{
	DIR *dir;
  struct dirent *ent;
  
  if ((dir = opendir ("./")) != NULL) 
  {
  	printf("\nAvailable files to choose from:\n\n");
  	/* print all the files and directories within directory */
  	while ((ent = readdir (dir)) != NULL) 
  	{
  		if (strstr(ent->d_name, ".txt") != NULL || strstr(ent->d_name, ".in") != NULL) {
    		printf ("%s\n", ent->d_name);
			}
    	
  	}
  	closedir (dir);
	} 
	else 
	{
  	/* could not open directory */
  	perror ("");
	}
}



/****************************************************************************/
/* calculates the number of letters occurring in percent                    */
/****************************************************************************/

static void crypt()
{
	FILE *fp = fopen("engtext.txt", read);
	FILE *f = fopen("cryptengtext.txt", write);
	int c = 0;
	
	checkfile(fp);
	checkfile(f);
	
	while(!feof(fp))
	{
		
		int i = 0;
		c = fgetc(fp);
		
		while(c != a[i] && i < ARRLEN){ i++; }
		
		fprintf(f, "%c", cry[i]);
	}
	printf("\n");
	fclose(f);
	fclose(fp);
}



/****************************************************************************/
/* calculates the number of letters occurring in percent                    */
/****************************************************************************/

static void percent()
{
	int i = 0;
	while(i <= ABCLEN)
	{
		p[i] = (x[i]/total)*100;
		i++;
	}
}


/****************************************************************************/
/* print decrypted text                                                     */
/****************************************************************************/

static void printtext(char i)
{
	FILE *fp;
	fp = fopen(i, read);
	int c = 0;
	
	checkfile(fp);
	
	printf("\n");
	while(!feof(fp))
	{
		c = fgetc(fp);
		printf("%c", c);
	}
	printf("\n");
	fclose(fp);
}

/****************************************************************************/
/* decrypts text                                                            */
/****************************************************************************/

static void decrypt()
{
	FILE *f = fopen("file.txt", write);
	FILE *fp = fopen("cipher.in", read);
	int c = 0;
	
	printf("\n");
	
	
	while(!feof(fp))
	{
		int i = 0;
		c = fgetc(fp);
		
		while(c != dec[i]){ i++; }
		
		fprintf(f, "%c", a[i]);
		
	}
	
	printf("\n");
	fclose(fp);
	fclose(f);
	
	//printdecrypted();
} 



/****************************************************************************/
/* print crypted text                                                       */
/****************************************************************************/

// static void printcrypted()
// {
// 	FILE *fp;
// 	fp = fopen("cipher.in", read);
// 	int c = 0;
	
// 	if (fp == NULL)
// 	{
// 		printf("%s\n", "File cannot be opened...");
// 	}
	
// 	printf("\n");
// 	while(!feof(fp))
// 	{
// 		c = fgetc(fp);
// 		printf("%c", c);
// 	}
// 	printf("\n");
// 	fclose(fp);
// }



/****************************************************************************/
/* Prints the arrays                                                        */
/****************************************************************************/

static void printarr()
{
	char abc = 'a';
	int i = 0;
	
	printf("\nquantity\tready-made\tanalysed\n");
	
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



/****************************************************************************/
/* Counts the number of every letter occurring                              */
/****************************************************************************/

static int countChar(int y)
{
	FILE *fp;
	fp = fopen("cipher.in", read);
	int c = 0;
	int count = 0;
	if (fp == NULL)
	{
		printf("%s\n", "File cannot be opened...");
	}
	
	while(!feof(fp))
	{
		c = fgetc(fp);
		if (c == y)
		{
			count++;
			total++;
		}
	}
	fclose(fp);
	return count;
}



/****************************************************************************/
/* main - Calls every function                                              */
/****************************************************************************/

static void analyse()
{
	char i = 'a';
	int j = 0;
	while(i <= 'z') 
	{
		//printf("\nj : %d\n", j);
		x[j] = countChar(i);
		i++;
		j++;
	}
	//printf("%c\n", i);

	i = ' ';
	//printf("%d\n", j);
	x[j] = countChar(i);
	percent();
	printarr();
	printf("%s%d\n", "\nTotal characters: ", total);

}



/****************************************************************************/
/****************************************************************************/
/* public operations                                                        */
/****************************************************************************/
/****************************************************************************/

void printt(char i)			 	{ printtext(i)		 ;}
void listf()							{ listfiles()			 ;}
void analysec()		 				{ analyse()				 ;}
void decryptt()    				{ decrypt()				 ;}
void cryptt()			 				{ crypt()					 ;}

/****************************************************************************/
/* end of basic functions                                                   */
/****************************************************************************/