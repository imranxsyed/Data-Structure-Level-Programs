#include <stdio.h>
#include <stdlib.h>
#include<string.h>





int Isdigit(char*);

int Isdigit(char input[]){

int i;
for ( i=0 ; i<strlen(input)-1; i++ ){

    if (input[i] >= '0' && input[i]<= '9'){

    }else{
    return -1;
    }
}
return 0;
}








char* trim (char*);
char* trim (char* input){

    if (input == NULL || strlen(input)<1){

        return input =NULL;
    }
    int i;
    i=0;

    while (i <strlen(input) &&input[i]==' '){
        i++;
    }
    if (i == strlen(input)){

        return input= NULL;
    }


    int j;
    j = strlen(input) -1;

    while (input[j]== ' '){

        j--;
    }

    char * output;
    output = (char*)malloc(((j-i)+1)*sizeof(char));
    int index;
    index = 0;


    for (i = i; i <=j ; i++){

    output[index] = input[i];
    index++;
    }

   // input = output;
  // printf("%s", output);

    return output;

}







int main(int argc , char** argv){

int rows,column,rows2,column2,value,i,j;
FILE* file;//free it
char line[400]; //free int end
file = fopen(argv[1],"r");

if (argc <2 || file == NULL){

return 0;

}



fgets(line,400,file);
trim(line);



rows = atoi(strtok(line, "	"));
column = atoi(strtok(NULL, "	"));
//int first[rows][column];//free in the end

//allocating memory
int **first;

first = (int**)malloc((rows)* sizeof(int*));


for (i = 0 ; i<rows ; i++){

	first[i] = (int *)malloc((column) * sizeof(int));
	
}
//first allocated




//first the driver;


for ( i =0; i< rows; i++){


    fgets(line,400,file);


    for (j=0 ; j<column; j++){


		if (j==0){ // the first tokenizer from the line

			 value = atoi(strtok(line,"	"));
			

		}else{ // the rest tokenizer from the file

			 value = atoi(strtok(NULL,"	"));

		}



       
        first[i][j]= value;
      //  printf("%d ", value);


    }
 //  printf("\n");
}
//printf("\n");



fgets(line,400,file);
  trim(line);
  while (line[0] == '\n'){


       //   printf("empty line %s", line);
          fgets(line,400,file);
            trim(line);
  }


    rows2 = atoi(strtok(line, "	"));
    column2 = atoi(strtok(NULL, "	"));
    

//allocating memory for second matrix

int  **second;


second = (int**)malloc((rows2)* sizeof(int*));

for (i = 0 ; i<rows2 ; i++){

	
	second[i] = (int *)malloc((column2) * sizeof(int));

} 
//second allocated 



    for ( i =0; i< rows2; i++){

 fgets(line,400,file);


    for (j=0 ; j<column2; j++){

		

		if(j==0){
			
			 value = atoi(strtok(line,"	"));
		

		}else{

			value = atoi(strtok(NULL,"	"));
		}

        
        second[i][j]= value;
     // printf("%d ", value);


    }
   // printf("\n");
}
//printf("\n");
//int c[rows][column2];

//allocting c matrix
int **c;

c = (int**)malloc((rows)* sizeof(int*));


for (i = 0 ; i<rows ; i++){

	c[i] = (int *)malloc((column2) * sizeof(int));
	

}
//allocated c 


//printf("column %d  rows %d\n",column,rows);
//setting c's values to equal to zero
int k;

for (i = 0; i<rows; i++){



    for (j=0 ; j< column2; j++){

        c[i][j] = 0;
    }
}
//all values are set to equal to zero





for(i=0; i<column2; i++){


			for( j=0 ; j<column; j++){



				for(k=0; k<rows ; k++){



               // printf("%d--> ", c[k][i]);
               c[k][i]= first[k][j] * second[j][i] + c[k][i];

				}

			}

			if (i==column2){
			free(first);
			free(second);

			}

		}




	for (i =0 ; i<rows; i++){

            for (j=0 ; j< column2; j++){

                printf("%d	", c[i][j]);
            }
		
		if (i==rows){
		free(c);	

		}
	
            printf("\n");
		}
fclose(file);


//free(first);
//free(second);
//free(c);

return 0;
}



