#include<stdio.h>
#include<math.h>

typedef struct {
    int phanNguyen, tuSo, mauSo;
} honSo;

typedef struct {
    int tuSo, mauSo;
} phanSo;

honSo a;
honSo b;

int ucln(int a, int b){
    while(a != b){
        if(a > b) a -= b;
        else b -= a;
    }
    return a;
}

void nhapHonSo(int a, int b, int c){
    printf("Phan nguyen cua hon so: %d\n", a);
    printf("Phan phan so cua hon so: %d/%d\n", b, c);
}

void input(){
    char c;
    printf("\nHon so dau tien: ");
    scanf("%d %c %d %c %d", &a.phanNguyen, &c, &a.tuSo, &c, &a.mauSo);
    printf("\nHon so thu hai: ");
    scanf("%d %c %d %c %d", &b.phanNguyen, &c, &b.tuSo, &c, &b.mauSo);

    // printf("%d %d %d", a.phanNguyen, a.tuSo, a.mauSo);
    // printf(" %d %d %d", b.phanNguyen, b.tuSo, b.mauSo);
}

void in(phanSo x){
    if(x.mauSo == 1) printf("%d", x.tuSo);
    else printf("%d/%d", x.tuSo, x.mauSo);
}

phanSo toPhanSo(honSo x){
    phanSo tmp;
    tmp.tuSo = x.phanNguyen*x.mauSo + x.tuSo;
    tmp.mauSo = x.mauSo;
    return tmp;
}

phanSo rutGon(phanSo x){
    phanSo res;
    int uoc = ucln(x.mauSo, x.tuSo);
    res.tuSo = x.tuSo / uoc;
    res.mauSo = x.mauSo / uoc;
    return res;
}

phanSo Plus(phanSo a, phanSo b){
    phanSo res;
    res.tuSo = a.tuSo * b.mauSo + b.tuSo * a.mauSo;
    res.mauSo = a.mauSo * b.mauSo;
    return res;
}

phanSo Minus(phanSo a, phanSo b){
    phanSo res;
    res.tuSo = a.tuSo * b.mauSo - b.tuSo * a.mauSo;
    res.mauSo = a.mauSo * b.mauSo;
    return res;
}

phanSo Multiply(phanSo a, phanSo b){
    phanSo res;
    res.tuSo = a.tuSo * b.tuSo;
    res.mauSo = a.mauSo * b.mauSo;
    return res;
}

int main(){
    phanSo p1, p2;

    nhapHonSo(3, 1, 5);

    input();

    p1 = rutGon(toPhanSo(a));
    p2 = rutGon(toPhanSo(b));

    printf("\n");
    printf("***************************");
    printf("Dang phan so cua hon so 1: ");
    in(p1);
    printf("\n");
    printf("Dang phan so cua hon so 2: ");
    in(p2);
    printf("\n");

    phanSo p3, p4, p5;
    
    p3 = rutGon(Plus(p1, p2));
    p4 = rutGon(Minus(p1, p2));
    p5 = rutGon(Multiply(p1, p2));

    printf("Tong hai hon so la: ");
    in(p3);
    printf("\n");

    printf("Tich hai hon so la: ");
    in(p5);
    printf("\n");

    printf("Hieu hai hon so la: ");
    in(p4);
    printf("\n");

    return 0;
}
