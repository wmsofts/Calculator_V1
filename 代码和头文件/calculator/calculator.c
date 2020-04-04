#include "../head/calculator.h"
#include "stdlib.h"
#include "stdio.h" 
#define ERROR 0
#define SUCCESS 1

//取数
int GetOperateNum(OperateNum *StackNum)
{
    return StackNum->data[StackNum->top];
}

//取运算符
char GetOperateSymbol(OperateSymbol *StackSymbol)
{
    return StackSymbol->symbol[StackSymbol->top];
}
 
//判误运算符,不是四则运算符则判断为误 
int IsOperateSymbolOrNum(char ch)
{
    if(ch == '+' || ch == '-' || ch == '*'|| ch == '/' || ch == '\n') return SUCCESS;
    else return ERROR;
}

//判断运算符优先级和数学等号 
char Priority(char inputnum, char ch)
{
    switch(inputnum)
    {  
	    //加减
        case '+':
        case '-':
        {
            if(ch == '+' || ch == '-') return '>';
            else if(ch == '*' || ch == '/') return '<';
            else return '>';
        }
            break;
        //乘除
        case '*':
        case '/':
        {
            if(ch == '+' || ch == '-') return '>';
            else if(ch == '*' || ch == '/') return '>';
            else return '>';
        }
            break;
 		//数学等号           
        case '\n':
        {
            if(ch == '\n') return '=';
            else return '<';
        }
            break;
    }
}

//数进栈
void PushOperateNum(OperateNum *StackNum, int x)
{
    StackNum->top++;
    StackNum->data[StackNum->top] = x;
}

//数出栈 
int PopOperateNum(OperateNum *StackNum)
{
    int num;
    num = StackNum->data[StackNum->top];
    StackNum->top--;
    return num;
}

//运算符进栈
void PushOperateSymbol(OperateSymbol *StackSymbol, char ch)
{
    StackSymbol->top++;
    StackSymbol->symbol[StackSymbol->top] = ch;
}

//运算符出栈 
char PopOperateSymbol(OperateSymbol *StackSymbol)
{
    char ch;
    ch = StackSymbol->symbol[StackSymbol->top];
    StackSymbol->top--;
    return ch;
}

//两数执行四则运算 
int Calculate(int num1, char ch, int num2)
{
    int result;
    switch(ch)
    {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            result = num1 / num2;
    }
    return result;
}

//输入、输入处理和计算核心 
int CalcCore()
{
    //主函数进行计算
    OperateNum data;
    OperateSymbol symbol;
    int num1, num2, result, num;
    char ch, sign;
	//初始化顺序栈
	data.top=-1;	//操作数栈顶指针
	symbol.top=-1;	//操作符栈顶指针
    //把回车计算的操作符放在栈中
    PushOperateSymbol(&symbol, '\n');
    ch = getchar();
    while(ch == ' '||(ch > 'a' && ch < 'z')||(ch > 'A' && ch < 'Z')) {
			printf("错误：输入有误！请不要输入字母或空格。"); 
 		    ch = getchar();
		}
    while((ch != '\n') || (GetOperateSymbol(&symbol) != '\n'))
    {
        if(!IsOperateSymbolOrNum(ch))
        {while(ch == ' '||(ch >= 'a' && ch <= 'z')||(ch >= 'A' && ch <= 'Z')) {
				printf("错误：输入有误！请不要输入字母或空格。\n"); 
     			ch = getchar();
			}   
            num = atoi(&ch);  //将字符转换为整数
            ch = getchar();   
             while(!IsOperateSymbolOrNum(ch))
            {while(ch == ' '||(ch > 'a' && ch < 'z')||(ch > 'A' && ch < 'Z')) {
					printf("错误：输入有误！请不要输入字母或空格。"); 
    				 ch = getchar();
				}
                num = num * 10 + atoi(&ch);
                ch = getchar();   //当没有输入回车时，继续获取输入
 
            }
            PushOperateNum(&data, num);
        }
        else
        {
			//第一个数是负数的情况
			if(ch=='-'&&symbol.top==0&&data.top==-1)PushOperateNum(&data, 0);
            switch(Priority(GetOperateSymbol(&symbol), ch))
            {
                //判断优先级后进行计算
                case '<':
                    PushOperateSymbol(&symbol, ch);
                    ch = getchar();
                    break;
                case '=':
                    sign = PopOperateSymbol(&symbol);
                    ch = getchar();  
                    break;
                case '>':
                    sign = PopOperateSymbol(&symbol);
                    num2 = PopOperateNum(&data);
                    num1 = PopOperateNum(&data);
                    result = Calculate(num1, sign, num2);
                    PushOperateNum(&data, result);
                    break;
 
            }
        }
    }
    result = GetOperateNum(&data);
    return result;
}
 
