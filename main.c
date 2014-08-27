#include <stdio.h>

double x[27], p[27];
int total = 0;
char *mode = "r";
double f[27] = {6.9, 0.4, 3.0, 3.2, 8.7, 2.3, 2.1, 2.7, 7.5, 0.1, 0.5, 4.6, 2.2, 7.0, 5.2, 1.7, 0.1, 4.6, 5.3, 6.1, 2.7, 1.5, 0.4, 0.2, 1.0, 0, 19.7};
int key = 0;
/*
a = 0x61
b = 0x62
c = 0x63
d = 0x64
e = 0x65
f = 0x66
g = 0x67
h = 0x68
i = 0x69
j = 0x6A
k = 0x6B
l = 0x6C
m = 0x6D
n = 0x6E
o = 0x6F
p = 0x70
q = 0x71
r = 0x72
s = 0x73
t = 0x74
u = 0x75
v = 0x76
w = 0x77
x = 0x78
y = 0x79
z = 0x7A
  = 0x5E
*/
void percent()
{
	int i = 0;
	while(i <= 26)
	{
		p[i] = (x[i]/total)*100;
		i++;
	}
}

int decrypt()
{
	/*
	Encryption:

	c = m + e mod(26)
	

	Decryption:

	m = c + d mod(26)

	c = ciphertext
	m = message
	e = Encryption key
	d = decryption key
	*/
} 

void printarr()
{
	char abc = 'a';
	int i = 0;
	while(i < 26)
	{
	printf("%c : %g\t\t%c : %g\t\t%c : %g\n", abc, x[i], abc, f[i], abc, p[i]);
	i++;
	abc++;
	}
	abc = ' ';
	i = 26;
	printf("%c : %g\t\t%c : %g\t%c : %g\n", abc, x[i], abc, f[i], abc, p[i]);
}

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


