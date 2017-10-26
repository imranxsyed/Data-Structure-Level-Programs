#include <stdio.h>
#include <stdlib.h>
#include<string.h>

 
int main(int argc , char** argv)
{
if (argc <2){
    printf("error");
return 0 ;
} 
int input;

input = atoi(argv[1]);
int i ;

for (i=2 ; i<= input/2 ; i++){

if ((input%i)==0){

printf("no\n");
return 0;

}

}

printf("yes\n");


    return 0;
}
