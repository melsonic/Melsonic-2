#include<stdio.h>
#include<string.h>

void dec(int a, int b){
    printf("\n binaryAdd = %d & binaryMul = %d\n", (a+b), (a*b));
}

int value(char r)
{
    if (r == 'I')
        return 1;
    if (r == 'V')
        return 5;
    if (r == 'X')
        return 10;
    if (r == 'L')
        return 50;
    if (r == 'C')
        return 100;
    if (r == 'D')
        return 500;
    if (r == 'M')
        return 1000;
}


int romToDec(char *a){
    int dec=0;
    for(int i=0; i<strlen(a); i++){
        int one = value(a[i]);
        if(i<(strlen(a)-1)){
            int two = value(a[i+1]);
            if(one>=two){
                dec += one;
            }else{
                dec += (two-one);
                i++;
            }
        }else{
            dec += one;
        }
    }
    return dec;
}

void decToRom(int a){
    while(a != 0){
         if (a >= 1000){
           printf("M");
           a -= 1000;
        }else if (a >= 900){
           printf("CM");
           a -= 900;
        }else if (a >= 500){           
           printf("D");
           a -= 500;
        }else if (a >= 400){
           printf("CD");
           a -= 400;
        }else if (a >= 100){
           printf("C");
           a -= 100;                       
        }else if (a >= 90){
           printf("XC");
           a -= 90;                                              
        }else if (a >= 50){
           printf("L");
           a -= 50;                                                                     
        }else if (a >= 40){
           printf("XL");           
           a -= 40;
        }else if (a >= 10){
           printf("X");
           a -= 10;           
        }else if (a >= 9){
           printf("IX");
           a -= 9;                         
        }else if (a >= 5){
           printf("V");
           a -= 5;                                     
        }else if (a >= 4){
           printf("IV");
           a -= 4;                                                            
        }else if (a >= 1){
           printf("I");
           a -= 1;                                                                                   
        }
    }
}

int binToDec(char *a){
    int l = strlen(a);
    int dec = 0;
    for(int i=(l-1); i>=0; i--){
        int two = 1;
        for(int j=1; j<=(l-i-1); j++){
            two *= 2;
        }
        dec += (a[i]-'0')*two;
    }
    return dec;
}

void decToBin(int a){
    char bin[20];
    for(int x=0; x<20; x++){
        bin[x] = '0';
    }
    int temp = a;
    int i=0;
    while(temp > 1){
        bin[i]=((temp%2)+'0');
        if(temp == 2){
            bin[i] = '0';
        }
        temp = temp/2;
        i++;
    }
    bin[i] = '1';
    int start = 0;
    for(int m=19; m>=0; m--){
        if(bin[m] == '0' && start == 0){
            continue;
        }
        if(bin[m] == '1'){
            start = 1;
        }
        printf("%c",bin[m]);
    }
}

int main()  {
    int option;
    printf("Enter 1--> Arabic, 2--> Roman, 3--> Binary\n");
    scanf("%d", &option);
    switch(option){
        case 1:
        {
                int hin1,hin2;
                scanf("%d %d", &hin1, &hin2);
                dec(hin1,hin2);
                break;
        }
        case 2:
        {
            char rom1[10], rom2[10];
            scanf("%s %s", rom1, rom2);
            int dec1 = romToDec(rom1);
            int dec2 = romToDec(rom2);
            int sum = dec1 + dec2;
            int mul = dec1*dec2;
            printf("sum = ");
                decToRom(sum);
                printf("\n");
                printf("mul = ");
                decToRom(mul);
                break;
        }
        case 3:
        {
                char bin1[10], bin2[10];
                scanf("%s %s", bin1, bin2);
                int dec1 = binToDec(bin1);
                int dec2 = binToDec(bin2);
                int sum = dec1 + dec2;
                int mul = dec1*dec2;
                printf("sum = ");
                decToBin(sum);
                printf("\n");
                printf("mul = ");
                decToBin(mul);
                break;
        }
    }
    
    return 0;
}