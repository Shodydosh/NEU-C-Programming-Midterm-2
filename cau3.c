#include<stdio.h>
#include<math.h>
#include<string.h>

int toNum(char x){
    return x - '0';
}

int reCal(int n){
    if(n < 10) return n;
    return 1+n%10;
}

int firstCheck(char a[20]){
    if(strlen(a) >= 16 || strlen(a) <= 13) return 0;
    if(a[0] != '4' && a[0] != '6' && a[0] != '5') return 0;
    if(a[0] == '3' && a[1] != '7') return 0;
    return 1;
}

int finalCheck(char a[20]){
    int evenSum = 0;
    int oddSum = 0;
    int n = strlen(a);
    if(n % 2 == 0){
        for(int i=0; i<strlen(a); i++){
            if(i%2==0) evenSum += reCal(a[i]*2);
            else oddSum += a[i];
        }
    }
    else{
        for(int i=0; i<strlen(a); i++){
            if(i%2==1) evenSum += reCal(a[i]*2);
            else oddSum += a[i];
        }
    }

    int totalSum = evenSum + oddSum;

    if(totalSum % 10 == 0) return 1;
    return 0;
}


int main(){
    char a[20];
    printf("Nhap so the tin dung: ");
    gets(a);

    if(firstCheck(a) == 0 || finalCheck(a) == 0){
        printf("So the tin dung khong hop le");
    }
    else printf("So the tin dung hop le");
    return 0;
}
