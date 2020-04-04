#include "..\head\calculator.h"
#include "..\calculator\calculator.c"
#include "stdlib.h"
#include "stdio.h" 
int main() 
{
    void ScreenShow();
    int CalcCore();
	long result;
    ScreenShow(); 
    while(1){
    result = CalcCore();
    printf(" = %ld\n\n", result); 
	} 
    getch();
    getch();
    return 0;
}
 
void ScreenShow(){
	printf("欢迎使用四则运算计算器！\n");
	printf("***********************\n");
	printf("存在的缺陷：\n(1)仅支持第一个运算数为负数的情况，暂不支持例如2+-3的算术式。\n");
	printf("(2)不支持浮点运算。\n(3)暂不支持带有括号的算术式。\n") ;
	printf("***********************\n");
	printf("请输入算术式，按下Enter计算：\n");
} 
