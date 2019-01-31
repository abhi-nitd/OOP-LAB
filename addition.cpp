#include<stdio.h>
#include<stdlib.h>
int convert_char_to_int(char ch)
{
	int number1;
	number1=ch-'0';
	return number1;
}
char convert_int_to_char(int number)
{
	
	char ch;
	ch=number+'0';
	//printf("%c\n",ch);
	return ch;
}
int cal_length(char st[])
{
	int len;
	len=0;
	int i;
	i=0;

	while(st[i]!='\0')
	{
		len++;
		i++;
	}
	return len;
}
int main()
{
	int sum2;
	char *a;
	a=NULL;
	a = malloc(256);
	char *b;
	FILE *fptr;
	int k=2;
	b=NULL;
	b = malloc(256);
	char *c;
	c=NULL;
	c = malloc(256);
	int sum,mod,i,j,diff;
	sum=0;
	mod=0;
	printf("Enter the first number ");
	scanf("%s",a);

	int len1;
	len1=cal_length(a);
	//printf("%d\n",len1);
	printf("Enter the second number ");
	scanf("%s",b);
	//printf("%s\n",b);
	int len2;
	len2=cal_length(b);
	//printf("%d\n",len2);
	if(len1<len2)
	{	diff=len2-len1;
		//printf("%d\n",diff);
		for(i=0;i<=len1;i++)
		{	
			a[i+diff]=a[i];
		}
		for(i=0;i<diff;i++)
		{
			a[i]='0';
		}
		//printf("%s\n",a);
	}
	//printf("%s\n",a);
	if(len2<len1)
	{	diff=len1-len2;
		//printf("%d\n",diff);
		for(i=0;i<len2;i++)
		{	
			b[i+diff]=b[i];
		}
		for(i=0;i<diff;i++)
		{
			b[i]='0';
		}
		//printf("%s\n",b);
	}
	//printf("%s\n",b);
	len2=len1;
	for(i=len1-1;i>=0;i--)
	{	//printf("%c\n",a[i]);
		int t=convert_char_to_int(a[i]);
		//printf("%da\n",t);
		//printf("%c\n",b[i]);
		
		int s=convert_char_to_int(b[i]);
		//printf("%db\n",s);
		
		sum=t+s+sum;
		mod=sum%10;
		sum=sum/10;
		
		char k=convert_int_to_char(mod);
		c[i+1]=k;
		
	}
	if (sum!=0)
	{	
		char l=convert_int_to_char(sum);
		//printf("d %d\n",l);
		c[0]=l;
	}
	else
	{
		c[0]='0';

	}
	
	printf("The sum is %s", c);
	return 0;
}
