#include <stdio.h>
#include <math.h>

int sender(int msg[20], int size){
    int sum = 0, checksum;
    printf("=====sender side==========");
    for(int i=0; i<size; i++)
        sum+=msg[i];
    checksum=~sum;
    return checksum;
}

int reciever(int msg[20], int size, int check){
    int sum = 0, checksum;
    printf("=====reciever side==========");
    for(int i=0; i<size; i++)
        sum+=msg[i];
    sum+=check;
    checksum=~sum;
    return checksum;
}

void main(){
    int msg[20], size, i, scheck, rcheck;
    printf("Enter the size of the message\n");
    scanf("%d", &size);

    printf("Enter the message\n");
    for(int i=0;i<size;i++){
        scanf("%d", &msg[i]);
    }

    scheck = sender(msg, size);
    printf("Sender sum = %d\n", scheck);
    rcheck = reciever(msg, size, scheck);
    printf("Reciever sum = %d\n", rcheck);

    if(rcheck == 0){
        printf("No error");
    }
    else{
        printf("Error");
    }
}


// ENTER SIZE OF THE STRING:2
// ENTER THE ELEMENTS OF THE ARRAY TO CALCULATE CHECKSUM:
// 1011
// 0111