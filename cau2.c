#include<stdio.h>
#include<math.h>
#include<string.h>

char a[100000] = "Dseb63";
char b[100000] = "";

void generate(int i){
    if(i == strlen(a)) return;
    else{
        b[i] = a[i];
        generate(i+1);
    }
}

int main(){
    generate(0);
    printf("day a la: %s\n", a);
    printf("day b la: %s", b);
    return 0;
}
