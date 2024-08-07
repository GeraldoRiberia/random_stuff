#include <stdio.h>
#include <string.h>
  
union Employee {
   char name[32];
   int age;
   float salary;
};
  
int main(){
   union Employee employee;
   /* Using one member of a union at a time */
   strcpy(employee.name, "Jack");
   printf("Name = %s  Address = %p\n", employee.name,
       &employee.name);
    
   employee.age = 30;
   printf("Age = %d Address = %p\n", employee.age, 
       &employee.age);
    
   employee.salary = 1234.5;
   printf("Salary = %f Address = %p\n", employee.salary,
       &employee.salary);
    
   /* Printing all member variable of Union, Only last updated 
      member will hold it's value remaining will contain garbage */
   printf("\nName = %s\n", employee.name);
   printf("Age = %d\n", employee.age);
   printf("Salary = %f\n", employee.salary); 
    
   return 0;
}
