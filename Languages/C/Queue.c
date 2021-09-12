#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAXSIZE 10

int queue[MAXSIZE];

int front = -1;
int rear = -1;
int size = -1;
int stop = 0;

CreateQueue(){
    char d;

    if(size < 0){
        printf("Queue is created\n");
        getch();

    }
    else if(size>0){

        printf("Do you want to overwrite on the previous queue ? [Y/N] :");
        scanf("\n%c", &d);

        if(d == 'Y'){
            front = -1;
            rear = -1;
            size = -1;
            printf("Queue is created\n");
              getch();
        }

        else if(d == 'N'){
            printf("Queue is not created\n");
              getch();
        }
    }

}

void EnterQueue(){
    int value,i,num;
    printf("Enter the number of elements you want to enter : ");
    scanf("%d",&num);

    if(size < MAXSIZE){
         for(i=0;i< num;i++){
                    if(size < 0){
                            printf("\nEnter the element :");
                            scanf("%d",&value);
                        front = rear = 0;
                        size = 1;
                        queue[front] = value;
                        }
                        else if(rear <= MAXSIZE - 1){
                                printf("\nEnter the element :");
                                scanf("%d",&value);
                        rear++;
                        queue[rear] = value;
                        size++;
                        }
            }
    }
    else
    {
        printf("Queue is full\n");
          getch();
    }
}

int DeleteQueue()
{
    if(size<0)
    {
        printf("Queue is empty\n");
          getch();
    }
    else
    {
        printf("Queue[%d] %d",front,queue[front]);
        size--;
        front++;
          getch();
    }
}

void DisplayQueue()
{
    int i;
    if(size < 0){
        printf("Queue is empty\n");
         getch();
    }
    else{
        for(i = front;i <= rear;i++){
            printf("Queue[%d] %d\n",i,queue[i]);
        }
          getch();
    }

}

SearchByValue(){
     int i,val,pos[100],c=-1;

    if(size < 0){
        printf("Queue is empty\n");
          getch();
    }
    else{
        printf("Enter the Element to search in Queue : ");
        scanf("%d",&val);

        }
        for(i = front;i <= rear;i++){

            if(val == queue[i]){

                printf("\033[1;32m");
                printf("Queue[%d] %d\n",i,queue[i]);
                printf("\033[0m");
            }
            else{
                printf("Queue[%d] %d\n",i,queue[i]);
            }
        }
              getch();
        }

SearchByPosition(){
    int p,i;

    printf("Enter the postion of the element in queue :");
    scanf("%d",&p);

    if((queue[p] > rear) || (queue[p] <= -1)){
        printf("Position not exists\n");
          getch();
    }
    else{
          printf("\033[1;32m");
          printf("Queue[%d] %d\n",p,queue[p]);
          printf("\033[0m");
          getch();
    }
}
int main(){
      int ch;
    while(ch != 7){
            system("cls");
        printf("[1]Create a Queue\n");
        printf("[2] Enter a element in Queue.\n[3] Delete a element from Queue.\n[4] Display the Queue.\n[5] Search an element in Queue.\n[6] Search by Position in Queue.\n[7] Exit.\nEnter Your Choice [1-7] :");
        scanf("%d",&ch);

            switch(ch){

                case 1: CreateQueue();
                            break;
                case 2: EnterQueue();
                            break;
                case 3: DeleteQueue();
                            break;
                case 4: DisplayQueue();
                            break;
                case 5:SearchByValue();
                            break;
                case 6:SearchByPosition();
                            break;
                case 7: exit(0);
                default: printf("Invalid Choice\n");
                            break;
                }
            }
            return 0;
}
