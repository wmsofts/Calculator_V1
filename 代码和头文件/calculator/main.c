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
	printf("��ӭʹ�����������������\n");
	printf("***********************\n");
	printf("���ڵ�ȱ�ݣ�\n(1)��֧�ֵ�һ��������Ϊ������������ݲ�֧������2+-3������ʽ��\n");
	printf("(2)��֧�ָ������㡣\n(3)�ݲ�֧�ִ������ŵ�����ʽ��\n") ;
	printf("***********************\n");
	printf("����������ʽ������Enter���㣺\n");
} 
