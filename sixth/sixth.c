#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main(int argc, char** argv){



if (argc <2){


    printf("error\n");
return 0 ;
}




int i;

for (i=1 ; i<argc ; i++){


	printf("%c", argv[i][0]);

} 
printf("\n");




return 0 ;


}
