#include <stdio.h>

//input: A(고정비용), B(per 가변비용), C(per 가격),  output: 손익분기점(break-even point)

int main(void){
    int A, B, C, output;
    scanf("%d %d %d", &A, &B, &C);

    if(C>B){
        output = A/(C-B);
        printf("%d\n", output+1);
    }
    else{
        printf("-1\n");
    }
    return 0;

}