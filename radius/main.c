#include <stdio.h>
int Intro(int R){
    printf("반지름을 입력하시오 : ");
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
