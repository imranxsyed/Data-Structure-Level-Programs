#include <stdio.h>
#include <stdlib.h>
#include<string.h>

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
    output = (char*)malloc( ((j-i)+1) * sizeof(char));
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

int main (int argc, char** argv){

    //error checking

    if (argc <2){

      //  printf("Invalid input");
        return 0;
    }

    FILE* file = fopen(argv[1], "r"); 

if (file==NULL){

return 0;

}




//FILE* file = fopen("C:\\users\\imran\\desktop\\file1.java","r");

char line[400];

fgets(line, 400 , file);
trim(line);

int  rows;
int column;
int i,j,value;

rows = atoi(strtok(line, "	"));
column = atoi(strtok(NULL, "	"));

//printf("rows:%d\tcolumns:%d\n",rows,column); 

//int first[rows][column];
//int second [rows][column];

int **first, **second;

first = (int**)malloc((rows)* sizeof(int*));
second = (int**)malloc((rows)* sizeof(int*));

for (i = 0 ; i<rows ; i++){

	first[i] = (int *)malloc((column) * sizeof(int));
	second[i] = (int *)malloc((column) * sizeof(int));

}




for (i = 0 ; i< rows; i++){

    fgets(line, 400, file);
    trim(line);

    for (j=0 ; j<column; j++){
	if (j==0){
        value = atoi(strtok(line, "	"));
	}else{
value = atoi(strtok(NULL, "	"));

}	
        first[i][j]= value;
       // printf("%d ",value); //checking

}//printf("\n");
}
//printf("\n");

fgets(line,400,file);
trim(line);


while (line[0]=='\n'){
//printf("The line is Empty\n"); // taking out the empty spaces
fgets(line,400,file);
trim(line);
}


for (i=0 ; i<rows ; i++){

    if (i> 0 ){
        fgets(line,400,file);
    }
    for (j=0 ; j<column; j++){
value =first[i][j];

	if (j==0){
         value = atoi(strtok(line, "	"))+ value;

}	
else{
	
 value = atoi(strtok(NULL, "	"))+ value;

}
         second[i][j]= value;
         printf("%d	", value);
   
 } printf("\n");

if(i ==rows){
	free(second);
	free(first);
	
}
}
fclose(file);
//free(second);
//free(first);
return 0;
}
