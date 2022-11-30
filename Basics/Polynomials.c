// Addition of polynomials using a single array
#include<stdio.h>
#include<stdlib.h>
#define COMPARE(x,y) ((x>y)?1:((x==y)?0:-1))
#define MAX_TERMS 100 
typedef struct {
 int coef;
 int expon;
 } polynomial;
polynomial terms[MAX_TERMS];
int avail = 0;
void attach(int coefficient, int exponent)
{
      if (avail >= MAX_TERMS) 
      {
        printf("Too many terms in the polynomial\n");
        exit(1);
      }
      else
      {
          terms[avail].coef = coefficient;
          terms[avail++].expon = exponent;
      }
}
void padd (int starta, int finisha, int startb, int finishb,
 int * startd)
{
    int coefficient;
    *startd = avail;
    while (starta <= finisha && startb <= finishb)
     {
         switch (COMPARE(terms[starta].expon,terms[startb].expon))
         {
                 case -1:
                         attach(terms[startb].coef, terms[startb].expon);
                         startb++;
                         break;
                 case 0: 
                        coefficient = terms[starta].coef+terms[startb].coef;
                        if (coefficient)
                            attach (coefficient, terms[starta].expon);
                        starta++; 
                        startb++;
                        break;
                case 1: 
                      attach(terms[starta].coef, terms[starta].expon);
                      starta++;
                      break;
          }
}
for( ; starta <= finisha; starta++)
     attach(terms[starta].coef, terms[starta].expon);
for( ; startb <= finishb; startb++)
       attach(terms[startb].coef, terms[startb].expon);
//*finishd =avail -1;
}

void main()
{
    int t1,t2,i,coeff,expon;

	printf("\nEnter the total number of terms in the 1st polynomial:");
	scanf("%d",&t1);
    printf("Enter the COEFFICIENT and EXPONENT\n");
	for(i=0;i<t1;i++)
	{
		printf("   Enter the Coefficient(%d): ",i+1);
		scanf("%d", &coeff);
		printf("   Enter the exponent(%d): ",i+1);
		scanf("%d", &expon);
		attach(coeff,expon);
		
	}
	
    printf("\nEnter the total number of terms in the 2nd polynomial:");
	scanf("%d",&t2);
    printf("Enter the COEFFICIENT and EXPONENT\n");
	for(i=0;i<t2;i++)
	{
		printf("   Enter the Coefficient(%d): ",i+1);
		scanf("%d",&coeff);
		printf("      Enter the exponent(%d): ",i+1);
		scanf("%d",&expon);   
		attach(coeff,expon);
	}
	
	
	printf("\n The addition of two polynomials is \n");
	
	padd(0,t1-1,t1,(t1+t2)-1,&avail);
	for(i=(t1+t2);i<avail;i++)
	{
	    printf("%d",terms[i].coef);
	    printf("(x^%d)",terms[i].expon);
	    if(i<avail-1)
	    {
	        printf("+");
	    }
	}
}	