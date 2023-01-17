#include <stdio.h>
#include <math.h>

int gcd(int a, int h){
    while (1)
    {
        int temp = a%h;
        if(temp == 0)
            return h;
        a = h;
        h = temp;
    }
}

int compute(int a, int m, int n)
{   
    int y=1;
    while(m>0){
        if(m%2==1){
            y = y*a%n;
        }
        a = a*a%n;
        m/=2;
    }
    return y;
}

void main(){
    int msg, p, q, phi_n, n, e=2, d=e;
    printf("Enter two prime numbers\n");
    scanf("%d%d", &p, &q);

    printf("Enter the message\n");
    scanf("%d", &msg);

    n = p*q;
    phi_n = (p-1)*(q-1);

    while (e<phi_n)
    {
        if(gcd(e, phi_n)==1)
            break;
        else
            e++;
    }

    while (1)
    {
        if(fmod(d*e, phi_n)==1)
            break;
        else
            d++;
    }

    long encrypted = compute(msg,e,n);
    long decrypted = compute(encrypted, d, n);

    printf("q : %d\n", q);
    printf("p : %d\n", p);
    printf("msg : %d\n", msg);
    printf("n : %d\n", n);
    printf("phi_n : %d\n", phi_n);
    printf("e : %d\n", e);
    printf("d : %d\n", d);
    printf("encrypted : %d\n", encrypted);
    printf("decrypted : %d\n", decrypted);
    
}


// 5 7 
// 30
