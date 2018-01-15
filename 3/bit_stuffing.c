#include<stdio.h>
#include<string.h>

char * encode(char s[])
{
	char en[100];
	
	en[0] = s[0];
	en[1] = s[1];
	en[2] = s[2];
	en[3] = s[3];
	en[4] = s[4];
	
	int k = 5;
	
	for(int i = 5; i < strlen(s); i++, k++)
	{
		if(en[k-1] == '0' && en[k-2] == '0' && en[k-3] == '0' && en[k-4] == '0' && en[k-5] == '0')
		{
			en[k] = '1';
			i--;
		}
		else
		{
			en[k] = s[i];
		}
	}
	
	char * p = en;
	
	return p;
}

char * decode(char s[])
{
	char dn[100];

	printf("%d\n",strlen(s));
	

	dn[0] = s[0];
	dn[1] = s[1];
	dn[2] = s[2];
	dn[3] = s[3];
	dn[4] = s[4];
		
	int k = 5;
	
	for(int i = 5; i < strlen(s);i++)
	{
		if(s[i-1] == '0' && s[i-2] == '0' && s[i-3] == '0' && s[i-4] == '0' && s[i-5] == '0')
		{
				
		}
		else
		{
			dn[k] = s[i];
			k++;
		}
	}
	
	printf("%d", k);
	
	char my[200];
	
	for(int j = 0; j < k; j++)
	{
		my[j] = dn[j];
	}
	
	char * p = my;
	
	return p;
}

int main()
{
	char input_string[100];
	
	scanf("%s", input_string);
	
	printf("input string : %s \n", input_string);
	
	char encoded_string[100];
	strcpy(encoded_string,encode(input_string));	
	printf("encoded string : %s \n", encoded_string);
	
	char decoded_string[100];
	strcpy(decoded_string,decode(encoded_string));	
	printf("decoded string : %s \n", decoded_string);
	
	return 0;
}
