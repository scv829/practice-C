#include <stdio.h>
int Intro(int R){
    printf("�������� �Է��Ͻÿ� : ");
    scanf("%d", &R);
    return R;
}
int Check(int R){
    if(R < 0) R = -R;
    return R;
}
float Area(int R){
    float f_a;
    f_a = 3.14 * (float)(R * R);
    printf("Area is %0.3f",f_a);
}
int main(void){
    int r = Intro(r);
    r = Check(r);
    Area(r);
    return 0;
}
