#include <iostream>
#include <stdlib.h>
#include<stdio.h>
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
        std::cout<<"Queue is created\n";
        getch();

    }
    else if(size>0){
        std::cout<<"Do you want to overwrite on the previous queue ? [Y/N] :";
        std::cin>>d;

        if(d == 'Y'){
            front = -1;
            rear = -1;
            size = -1;
            std::cout<<"Queue is created\n";
              getch();
        }

        else if(d == 'N'){
            std::cout<<"Queue is not created\n";
              getch();
        }
    }

}

void EnterQueue(){
    int value,i,num;
    std::cout<<"Enter the number of elements you want to enter : ";
    std::cin>>num;

    if(size < MAXSIZE){
         for(i=front;i< num-1;i++){
                    if(size < 0){
                        std::cout<<"\nEnter the element :";
                        std::cin>>value;
                        front = rear = 0;
                        size = 1;
                        queue[front] = value;
                        }
                        else if(rear <= MAXSIZE - 1){
                        std::cout<<"\nEnter the element :";
                        std::cin>>value;
                        rear++;
                        queue[rear] = value;
                        size++;
                        }
            }
    }
    else
    {
        std::cout<<"Queue is full\n";
          getch();
    }
}

int DeleteQueue()
{
    if(size<0)
    {
        std::cout<<"Queue is empty\n";
          getch();
    }
    else
    {
        std::cout<<"Queue["<<front<<"] "<< queue[front];
        size--;
        front++;
          getch();
    }
}

void DisplayQueue()
{
    int i;
    if(size < 0){
        std::cout<<"Queue is empty\n";
         getch();
    }
    else{
        for(i = front;i <= rear;i++){
            std::cout<<"Queue["<<i<<"] "<<queue[i]<<"\n";
        }
          getch();
    }

}

SearchByValue(){
     int i,val,pos[100],c=-1;

    if(size < 0){
        std::cout<<"Queue is empty\n";
          getch();
    }
    else{
        std::cout<<"Enter the Element to search in Queue : ";
        std::cin>>val;

        }
        for(i = front;i <= rear;i++){

            if(val == queue[i]){
                std::cout<<"\033[1;32m";
                std::cout<<"Queue["<<i<<"] "<<queue[i]<<"\n";
                std::cout<<"\033[0m";
            }
            else{
                    std::cout<<"Queue["<<i<<"] "<<queue[i]<<"\n";
            }
        }
              getch();
        }

SearchByPosition(){
    int p,i;
    std::cout<<"Enter the postion of the element in queue :";
    std::cin>>p;

    if((queue[p] > rear) || (queue[p] <= -1)){
        std::cout<<"Position not exists\n";
          getch();
    }
    else{
        for(i=front;i<=rear;i++){
            if(p == i){
                std::cout<<"\033[1;32m";
                std::cout<<"Queue["<<p<<"] "<<queue[p]<<"\n";
                std::cout<<"\033[0m";
            }
        }
          getch();
    }
}
int main(){
      int ch;
    while(ch != 7){
            system("cls");
            std::cout<<"[1]Create a Queue\n[2] Enter a element in Queue.\n[3] Delete a element from Queue.\n[4] Display the Queue.\n[5] Search an element in Queue.\n[6] Search by Position in Queue.\n[7] Exit.\nEnter Your Choice [1-7] :";\
            std::cin>>ch;

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
                default:std::cout<<"Invalid Choice\n";
                            break;
                }
            }
            return 0;
}

