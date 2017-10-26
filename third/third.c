
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

 struct Node{ //making a class


int data;

struct Node *next;
};


//front =NULL;

struct Node* hashTable[10000];



int Isdigit(char*);

int Isdigit(char input[]){

int i;
for ( i=0 ; i<strlen(input)-1; i++ ){

    if (input[i]<= '9' || input[i] =='-'){

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
    output = (char*)malloc((j-i)+1*sizeof(char));
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



void insert(int , int );
void insert(int input, int index){

struct Node* temp;
temp = (struct Node*) malloc(sizeof(struct Node));
temp->data = input;
temp->next= NULL;


// if the linked list is null
if (hashTable[index]== NULL){

    hashTable[index]= temp ;
    printf("inserted\n");
    return ;
}

struct Node* ptr ;
ptr = hashTable[index];

//going through the linked list till the end
while(ptr!= NULL){

    if (ptr->data == input){ //input already exists
		
		
		free(temp);
            printf("duplicate\n");
            return;


    }
ptr = ptr->next;
}//did not find any duplicate

temp->next = hashTable[index];
hashTable[index]= temp;
printf("inserted\n");
return;


}


void search(int , int);
void search(int input, int index){


if (hashTable[index]== NULL){ // if the linked list is empty


    printf("absent\n");
    return;
}


struct Node* ptr;
ptr = hashTable[index];

while(ptr!=NULL){//looking for target through the list


    if (ptr->data == input){

        printf("present\n");
        return;

    }
ptr = ptr->next;

} //the target is not found

printf("absent\n");
return;


}
















int main(int argc, char** argv)
{

FILE* file = fopen(argv[1],"r"); //getting the argument from the command line paramete

if (argc <2){

    printf("error\n");
    return 0;
}
else if (file ==NULL){
    printf("error\n");
    return 0;
}  //error checking */


//int i;

/*for (i=0; i<10000 ; i++){


    hashTable[i]= NULL;
}*/






//FILE* file = fopen("C:\\users\\imran\\Desktop\\file1.java", "r");// manual input
char line[400];
char* operation, *value;




fseek(file, 0, SEEK_END);
unsigned long len = (unsigned long)ftell(file);



if (len <= 0) {//check if the file is empty or


    return 0;
}

rewind(file);


fgets(line,400,file);

do{


    trim(line);
   operation = strtok(line, "	");
   value = strtok(NULL,"	");


   if ((value != NULL && operation != NULL) && (strcmp("i",operation)==0 || strcmp("s",operation)==0)&& (Isdigit(value)==0)){ //checking all the restrictions

     int integer,index ;
    integer = atoi(value);
   index= (integer)%(10000);


//checking if the modula outputs the negative number and if so, fixing it

	if (index< 0){
		index += 10000; 
	}




        if (strcmp(operation, "i")==0){

                insert(integer, index);


        }


        else if (strcmp("s",operation)==0){


                search(integer, index);

        }



   }


   else{

    printf("error\n");

   }


} while(fgets(line,400, file));
fclose(file);




  return 0;
}


