#include <stdio.h>
#include <stdlib.h>
#define N 100
int index_first_zero(int *mas, int n){
    int first_zero=0;
    for (int i=n-1; i >= 0 ; i--){
        if (mas[i]==0){
            first_zero=i;
        }
    }
    return first_zero;
}
int index_last_zero(int *mas, int n){
    int last_zero;
    for(int i=0; i < n; i++){
        if (mas[i]==0){
            last_zero=i;
        }
    }
    return last_zero;
}
int sum_between(int *mas, int n){
    int sum=0;
    for(int i=0; i < n; i++){
        if(i > index_first_zero(mas, n) && i < index_last_zero(mas, n)){
            sum+=abs(mas[i]);
        }
    }
    return sum;
}
int sum_bef_and_aft(int *mas, int n){
    int sum12=0;
    int sum1=0;
    int sum2=0;
    for(int i=0; i < n; i++){
        if (i < index_first_zero(mas, n)){
            sum1+=abs(mas[i]);
        }
        if (i >= index_last_zero(mas, n)){
            sum2+=abs(mas[i]);
        }
    }
    sum12 = sum1 + sum2;
    return sum12;
}
int main(){
    int mass[N];
    int size = 0;
    int vvod;
    char s;
    scanf("%d\n", &vvod);
    do{
        scanf("%d%c", &mass[size], &s);
        size++;
    }while(s != '\n' && size < N);
    switch(vvod){
        case 0:
        {
            printf("%d\n", index_first_zero(mass, size));
            break;
        }
        case 1:
        {
            printf("%d\n", index_last_zero(mass, size));
            break;
        }
        case 2:
        {
            printf("%d\n", sum_between(mass, size));
            break;
        }
        case 3:
        {
            printf("%d\n", sum_bef_and_aft(mass, size));
            break;
        }
        default:
        {
            printf("Данные некорректны\n");
            break;
        }
    }
    return 0;
}
