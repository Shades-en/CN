#include<stdio.h>
#include<stdlib.h>

int compute(int a, int m, int n){
    int y=1;
    while(m>0){
        if(m%2 == 1){
            y = y*a %n;
        }
        a = a*a%n;
        m/=2;
    }
    return y;
}

void main(){
    int p,g, a, b, A, B, key_A, key_B;

    printf("Enter the values of p and g\n");
    scanf("%d%d", &p, &g);

    a = rand();
    printf("private key of A is %d\n", a);
    A = compute(g, a, p);
    printf("key of A is %d\n", A);

    b = rand();
    printf("private key of B is %d\n", b);
    B = compute(g, b, p);
    printf("key of B is %d\n", B);

    key_A = compute(B, a, p);
    key_B = compute(A, b, p);
    printf("Secret key of A is %d\n", key_A);
    printf("Secret key of B is %d\n", key_B);

}

// 23 9