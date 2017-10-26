
#include <stdio.h>
#include <stdlib.h>
#include<string.h>


 struct Node{ //making a class

int height;
int data;
struct Node *left;
struct Node *right;
};

struct Node* root = NULL;
//front =NULL;



int Isdigit(char*);

int Isdigit(char input[]){

int i;
for ( i=0 ; i<strlen(input)-1; i++ ){

    if (input[i]<= '9' || input[i]=='-'){

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






void insert(int);
void insert(int x){
struct Node* temp;
 temp  = (struct Node*)malloc( sizeof(struct Node));

        temp->data = x;
        temp ->left = NULL;
        temp->right= NULL;
        temp->height= 1;


    if (root ==NULL){
       root = temp;
       printf("inserted %d\n", root->height);
        return;
    }


    struct Node* ptr;
    struct Node* prev =NULL;
    ptr = root;

    while(ptr != NULL){


            if (ptr->data > x){

                prev = ptr;
                ptr = ptr->left;
            }


            else if (ptr->data == x){

                printf("duplicate\n");
                //free(temp);
                return;
            }

            else{

                prev = ptr;
                ptr = ptr->right;

            }

          /*  if (ptr == NULL){

                free(ptr);
            } */
    }


    if(prev->data > x){

        prev ->left = temp;
        temp ->height = prev->height+1;

    }

    else{


        prev ->right= temp;
        temp->height= prev->height+1;


    }


    printf("inserted %d\n", temp->height);



    return;
}






void Search(int);
void Search(int x){


if (root == NULL){


    printf("absent\n");
    return;

}


 struct Node* ptr;
//struct Node *prev= NULL;
ptr = root;



while (ptr !=NULL){


    if(ptr->data == x){


        printf("present %d\n", ptr->height);
        return;

    }


    else if (ptr ->data > x){


       // prev= ptr;
        ptr= ptr->left;

    }


    else{


      //  prev = ptr;
        ptr = ptr ->right;
    }

 if (ptr == NULL){

        //free(ptr);
    }
} //nothing is found and all the values are viewd */


printf("absent\n");
return;



}






int main(int argc, char** argv)
{

FILE* file = fopen(argv[1],"r"); //getting the argument from the command line parameters



if (argc <2){


    printf("error\n");
    return 0;

}


else if (file ==NULL){
    printf("error");
    return 0;


}  //error checking 



//FILE* file = fopen("eighth.txt", "r");// manual input
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
//int length;
//length = strlen(value);
//trim(value);

//printf("the value of number :%d\nthe length of the variable: %d\n the actual string is %s\n", Isdigit(value),length,value);

//printf("The integer value : %d \n the string value : %s\n the fuction returns: %d\n", integer, value, isdigit(integer));

   if ((value != NULL && operation != NULL) && (strcmp("i",operation)==0 || strcmp("s",operation)==0)&& (Isdigit(value)==0)){ //checking all the restrictions

     int integer ;
    integer = atoi(value);

      if (strcmp(operation, "i")==0){

     insert(integer);

      }

      else{

    Search(integer);
      }
   }


   else{

    printf("error\n");
    
   }


} while(fgets(line,400, file));
fclose(file);
//free(root);

 //free(file);
 //free(value);
// free(operation);



  return 0;
}


