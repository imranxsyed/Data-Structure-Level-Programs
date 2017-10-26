
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

    if (input[i]<= '9'|| input[i] == '-'){

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
int h;
h=1;
 temp  = (struct Node*)malloc( sizeof(struct Node));

        temp->data = x;
        temp ->left = NULL;
        temp->right= NULL;
        temp->height= 1;


    if (root ==NULL){
       root = temp;
       printf("inserted %d\n", h);
        return;
    }


    struct Node* ptr;
    struct Node* prev =NULL;
    ptr = root;

    while(ptr != NULL){


            if (ptr->data > x){

                prev = ptr;
                ptr = ptr->left;
h+=1;
            }


            else if (ptr->data == x){

                printf("duplicate\n");
              //  free(temp);
                return;
            }

            else{

                prev = ptr;
                ptr = ptr->right;
h+=1;

            }

            
    }


    if(prev->data > x){

        prev ->left = temp;
       // temp ->height = prev->height+1;
//h++;//

    }

    else{


        prev ->right= temp;
       // temp->height= prev->height+1;
//h++;//


    }


    printf("inserted %d\n", h);



    return;
}






void Search(int);
void Search(int x){
int h;
h=1;

if (root == NULL){


    printf("absent\n");
    return;

}


 struct Node* ptr;

ptr = root;



while (ptr !=NULL){


    if(ptr->data == x){


        printf("present %d\n", h);
        return;

    }


    else if (ptr ->data > x){


        
        ptr= ptr->left;
h++;

    }


    else{


       
        ptr = ptr ->right;
h++;
    }

 
} //nothing is found and all the values are viewd */


printf("absent\n");
return;



}



void Delete(int);
void Delete(int x){

if (root == NULL){

    printf("fail\n");
    return;
}

struct Node* prevTarget;
struct Node* target;
prevTarget = NULL;
target = root;


while (target != NULL){


        if (target->data==x){


            break;
        }

  else  if (target ->data > x){

        prevTarget = target;
        target = target ->left;
    }

    else{

        prevTarget = target;
        target = target ->right;

    }

}

if (target == NULL){ //object not found


    printf("fail\n");
    return;
}

if(target->left == NULL && target->right == NULL){//node with no children, found the target


    if (prevTarget==NULL){ // its the root and the only node

        root =NULL;

    }else{

        if ( prevTarget->left !=NULL && prevTarget->left->data == target->data){

            prevTarget->left=NULL;


        }else{

             prevTarget->right=NULL;

        }

    }

    printf("success\n");
    return;
}


if(target->left == NULL || target->right == NULL){ //target with only one child

 if (prevTarget==NULL){ //root is the target, and it only has one child

    if (target ->left !=NULL){

        root = target->left;

    }

    else{

        root = target->right;

    }

 }else{

    if (target->left !=NULL){


        if ( prevTarget->left!= NULL&&prevTarget->left->data ==target->data ){

            prevTarget->left = target->left;

        }else{

        prevTarget->right = target->left;

        }
    }else{



         if (prevTarget->left!= NULL && prevTarget->left->data ==target->data ){

            prevTarget->left = target->right;

        }else{

        prevTarget->right = target->right;

        }




    }

 }

 printf("success\n");
 return;

}

//root with both children

struct Node* ptr, *prev;
prev =NULL;

ptr = target->right;

while (ptr ->left != NULL){

    prev= ptr;
    ptr = ptr->left;
}

if (target->right->data == ptr->data){ // only one node to the right meaning the prev is NULL


    target->data = ptr->data;
    target ->right= ptr->right;

}
else{


    target->data = ptr->data;
    prev ->left = ptr->right;


}

printf("success\n");
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
    printf("error\n");
    return 0;
}  //error checking 



//FILE* file = fopen("ninth.txt", "r");// manual input
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


   if ((value != NULL && operation != NULL) && (strcmp("i",operation)==0 || strcmp("s",operation)==0|| strcmp("d",operation)==0)&& (Isdigit(value)==0)){ //checking all the restrictions

     int integer ;
    integer = atoi(value);

      if (strcmp(operation, "i")==0){

     insert(integer);

      }


      else if (strcmp("s",operation)==0){

    Search(integer);



      }


      else{

      Delete(integer);
      }
   }


   else{

    printf("error\n");
    
   }


} while(fgets(line,400, file));
fclose(file);




  return 0;
}


