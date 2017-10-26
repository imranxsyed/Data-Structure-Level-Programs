#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main(int argc, char** argv){



if (argc <2){


    printf("error\n");
return 0 ;
}




int i,length;

for (i=1 ; i<argc ; i++){


	length = strlen(argv[i]);
	printf("%c", argv[i][length-1]);

} 
printf("\n");




return 0 ;


}
