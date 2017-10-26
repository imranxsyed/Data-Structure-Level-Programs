#include <stdio.h>
#include <stdlib.h>
#include<string.h>


 struct Node{ //making a class

int data;
struct Node *next;
};

struct Node* front = NULL;
//front =NULL;




int isWord(char*);
int isWord(char input[]){






    if (input == NULL || strcmp("",input)==0){


        return -1;
    }

    char* letters;
    char* LETTERS;
		
  letters = (char*) malloc(26 * sizeof(char));
  LETTERS = (char*) malloc(26 * sizeof(char));
letters ="abcdefghjiklmnopqrstuvwxyz";
LETTERS= "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int i,j,f;

    for (i=0 ; i<strlen(input); i++){
        f=0;
        for (j=0 ; j<strlen(letters); j++){

            if (input[i]==letters[j]|| input[i]== LETTERS[j] || input[i]==' '){

                f=1;
                break;
            }
        }

        if (f!=1){
            return 1;
        }
    }

    return 0;


}







int checkdigit(char*);

int checkdigit(char input[]){

int i;
for ( i=0 ; input[i]<strlen(input)-1; i++ ){

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
    output = (char*)malloc(((j-i)+1) * sizeof(char));
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









void insert(int);
void insert(int x){
struct Node* temp;
 temp  = (struct Node*)malloc(sizeof(struct Node));
        temp->data = x;
        temp ->next = NULL;


    if (front ==NULL){
       front = temp;
        return;
    }
    struct Node* ptr;
    struct Node* prev =NULL;
    ptr = front;

    while(ptr -> next !=NULL && ptr->data < x){

        prev = ptr;
        ptr = ptr ->next;
    }

    if (ptr->data == x){ // duplicate variable

        return ;
    }


    if (prev == NULL){

            if (ptr->data <x){
                ptr->next = temp;
            }else{
             temp->next =ptr ;
                front = temp;
            }



    }else if(ptr->next ==NULL){
        if (ptr->data <x){
             ptr->next = temp;
        }else{
         temp->next = prev->next;
    prev->next = temp;
        }

    }else{
     temp->next = prev->next;
    prev->next = temp;
    }
}


void print();
void print(){

    if (front ==NULL){
        printf("\n");
        return ;
    }
    struct Node* ptr;
    ptr = front;

    while(ptr->next !=NULL){

        printf("%d	",ptr->data);
        ptr = ptr->next;
    }
    printf("%d\n", ptr ->data);
    return ;
}




void Delete (int);
void Delete(int x){
    if (front ==NULL){
        return;
    }
    struct Node* ptr;
    struct Node* prev = NULL;
    ptr = front;

    while(ptr->next != NULL && ptr->data != x){
        prev = ptr;
        ptr = ptr->next;
    }
    if (prev == NULL){

        front= ptr->next;
       free(ptr);
    }
   else if (ptr->data == x){

        prev ->next = ptr->next;
        free(ptr);
    }
    return;
}

int main(int argc, char** argv)
{
FILE* file;
file = fopen(argv[1],"r"); //getting the argument from the command line parameters
 //file = fopen("file1.java", "r");

 if (argc <2){

    printf("error\n");//
    return 0;
}
else if (file ==NULL){
    printf("error");//
    return 0;
}  //error checking


char line[20];

 //char* operation = strtok(line, " ");
   // char *value = strtok(NULL," ");



fseek(file, 0, SEEK_END);
    unsigned long len = (unsigned long)ftell(file);

if (len<=0){
printf("\n");
return 0;
}
rewind(file);

fgets(line,20,file);

do{


    trim(line);
 char* operation = strtok(line,"	");
   char *value = strtok(NULL,"	");
//printf("%d\n%s", checkdigit(value), value);

   if ((value != NULL && operation != NULL) && (strcmp("i",operation)==0 || strcmp("d",operation)==0)&& (checkdigit(value)==0)){ //checking all the restrictions

     int integer ;
    integer = atoi(value);

      if (strcmp(operation, "i")==0){

        insert(integer);

      }

      else{

      Delete(integer);
      }
   }


   else{

    printf("error \n");
    return 0;
   }


} while(fgets(line,20, file));
fclose(file);
//free(value);
//free(operation);


 print();


  return 0;
}


