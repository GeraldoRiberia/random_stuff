#include <stdio.h>
#include<string.h>
 
struct employee{
    char    members_name[30];
    int     e_id;
    float   salary;
};
 
int main()
{
  int n;
  printf("Enter the number of employees : ");
  scanf("%d",&n);                               //variable for storing the number employees
  getchar();                                    //this is for catching the \n when you press enter from going into the next scanf
  struct employee emp[30];
  for(int j =0 ; j<n; j++)                      //loop to accept different employee details
  {
    printf("Enter employee name :");
    gets(emp[j].members_name);
    printf("Enter employee ID : ");
    scanf("%d", &emp[j].e_id);
    printf("Enter employee Salary : ");
    scanf("%f",&emp[j].salary);
    getchar();                                  //this is for catching the \n when you press enter from going into the next scanf

  }
  int i =0;
  while(i<n){                                   //loop to print all the details of the different employees
    printf("Name : %s \n",emp[i].members_name);
    printf("ID : %d \n",emp[i].e_id);
    printf("Salary %f \n",emp[i].salary);
    i++;
  }
  return 0;
}

