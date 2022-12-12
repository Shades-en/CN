#include<stdio.h>
#include<string.h>

int i,j,k, data_len, key_len, flag=0;
char data[30], key[30], cs[30];

void xor(){
    for(j = 0;j<key_len;j++)
        cs[j] = (cs[j] == key[j])? '0': '1';
    
}

void crc(){
    for(i=0;i<key_len;i++)
        cs[i] = data[i];
    do{
        if(cs[0]=='1')
            xor();
        
        for(j = 0;j<key_len-1;j++)
            cs[j] = cs[j+1];
        
        cs[j] = data[i++];
    }while(i<=data_len+key_len-1);
    
}

void main(){
    printf("Enter the data\n");
    scanf("%s", &data);
    printf("Enter the key\n");
    scanf("%s", &key);

    data_len = strlen(data);
    key_len = strlen(key);

    for(int i=data_len; i<data_len+key_len-1; i++)
        data[i] = '0';

    printf("Modified dataword is %s \n", data);
    crc();
    printf("checksum is %s\n", cs);

    for(int i=data_len; i<data_len+key_len-1; i++)
        data[i] = cs[i - data_len];

    printf("Sent dataword is %s \n", data);
    crc();
    printf("checksum is %s\n", cs);

    for(int i=0;i<strlen(cs);i++)
	{
		if(cs[i]=='1')
		       flag=1;
	}
    if(flag==1)
    printf("error detected");
    else 
    printf("no error");
}

//data -100100
//Key - 1101

//data sent is 100100001.
