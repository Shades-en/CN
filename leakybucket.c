#include <stdio.h>

void main(){
    int incoming, outgoing, store = 0, n, bucket;

    printf("Enter the outgoing rate, size of bucket and no. of inputs\n");
    scanf("%d%d%d", &outgoing, &bucket, &n);
    while(n>0){
        printf("Enter the size of incoming packet");
        scanf("%d", &incoming);
        if(incoming<=(bucket - store)){
            store+=incoming;
            printf("bucket buffer size of %d out of %d\n",store, bucket);
        }  
        else{
            printf("Packets dropped %d\n", incoming - (bucket - store));
            store = bucket;
            printf("bucket buffer size of %d out of %d\n",store, bucket);
        } 
        store-=outgoing;
        printf("After outgoing bucket buffer size of %d out of %d\n",store, bucket);
        n--;
    }
}