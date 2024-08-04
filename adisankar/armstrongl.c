#include<stdio.h>
#include<math.h>
int arms(int i,int exp)
{
    int armno=0;
    while(i>0)
    {
        int digit = i%10;
        armno = armno + pow(digit,exp);
        i/=10;
    }
    return armno;
}
int digits(int i)
{
    int exp =0;
    for(int j =i; j>0;j/=10)
    {
        exp++;
    }
    return exp;
}

int main()
{
    int llm,ulm;
    printf("Enter the lower limit \n");
    scanf("%d",&llm);
    printf("Enter upper limit \n");
    scanf("%d",&ulm);
    printf("The armstrong numbers from %d to %d : ", llm, ulm);
    for(int i =llm; i<ulm; i++)
    {
        int exp = digits(i);
        int chk = arms(i,exp);
        if(chk == i)
        {
            printf("%d, ", i);
        }

    }
}

/*
Enter the lower limit 
100
Enter upper limit 
10000
The armstrong numbers from 100 to 10000 : 153, 370, 371, 407, 1634, 8208, 9474,
*/