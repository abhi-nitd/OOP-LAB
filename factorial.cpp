#include<stdio.h>
#include<stdlib.h>

int calculate(int a, int prod[], int prod_size);

void factorial(int n) 
{
	int *product;
	product=NULL;
	product=malloc(1000);
	product[0] = 1; 
        int product_size = 1; 
	int i;  	
	
   
    for (i=2; i<=n; i++) 
        product_size = calculate(i, product, product_size); 
  
    printf ("Factorial of given number is \n"); 
    for (int i=product_size-1; i>=0; i--) 
        printf("%d",product[i]);
    printf("\n"); 
} 

int calculate(int x, int *product, int product_size) 
{ 
    int carry = 0;  
    
    for (int i=0; i<product_size; i++) 
    { 
        int prod = product[i] * x + carry; 
  
          
        product[i] = prod % 10;   
  
        
        carry  = prod/10;     
    } 
  
     while (carry) 
    { 
        product[product_size] = carry%10; 
        carry = carry/10; 
        product_size++; 
    } 
    return product_size; 
}

int main()
{
	int k;
	printf("Enter the number whose factorial is to be found ");
	scanf("%d",&k);
	factorial(k);
	return 0;
}