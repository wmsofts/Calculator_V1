#include "../head/calculator.h"
#include "stdlib.h"
#include "stdio.h" 
#define ERROR 0
#define SUCCESS 1

//ȡ��
int GetOperateNum(OperateNum *StackNum)
{
    return StackNum->data[StackNum->top];
}

//ȡ�����
char GetOperateSymbol(OperateSymbol *StackSymbol)
{
    return StackSymbol->symbol[StackSymbol->top];
}
 
//���������,����������������ж�Ϊ�� 
int IsOperateSymbolOrNum(char ch)
{
    if(ch == '+' || ch == '-' || ch == '*'|| ch == '/' || ch == '\n') return SUCCESS;
    else return ERROR;
}

//�ж���������ȼ�����ѧ�Ⱥ� 
char Priority(char inputnum, char ch)
{
    switch(inputnum)
    {  
	    //�Ӽ�
        case '+':
        case '-':
        {
            if(ch == '+' || ch == '-') return '>';
            else if(ch == '*' || ch == '/') return '<';
            else return '>';
        }
            break;
        //�˳�
        case '*':
        case '/':
        {
            if(ch == '+' || ch == '-') return '>';
            else if(ch == '*' || ch == '/') return '>';
            else return '>';
        }
            break;
 		//��ѧ�Ⱥ�           
        case '\n':
        {
            if(ch == '\n') return '=';
            else return '<';
        }
            break;
    }
}

//����ջ
void PushOperateNum(OperateNum *StackNum, int x)
{
    StackNum->top++;
    StackNum->data[StackNum->top] = x;
}

//����ջ 
int PopOperateNum(OperateNum *StackNum)
{
    int num;
    num = StackNum->data[StackNum->top];
    StackNum->top--;
    return num;
}

//�������ջ
void PushOperateSymbol(OperateSymbol *StackSymbol, char ch)
{
    StackSymbol->top++;
    StackSymbol->symbol[StackSymbol->top] = ch;
}

//�������ջ 
char PopOperateSymbol(OperateSymbol *StackSymbol)
{
    char ch;
    ch = StackSymbol->symbol[StackSymbol->top];
    StackSymbol->top--;
    return ch;
}

//����ִ���������� 
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

//���롢���봦��ͼ������ 
int CalcCore()
{
    //���������м���
    OperateNum data;
    OperateSymbol symbol;
    int num1, num2, result, num;
    char ch, sign;
	//��ʼ��˳��ջ
	data.top=-1;	//������ջ��ָ��
	symbol.top=-1;	//������ջ��ָ��
    //�ѻس�����Ĳ���������ջ��
    PushOperateSymbol(&symbol, '\n');
    ch = getchar();
    while(ch == ' '||(ch > 'a' && ch < 'z')||(ch > 'A' && ch < 'Z')) {
			printf("�������������벻Ҫ������ĸ��ո�"); 
 		    ch = getchar();
		}
    while((ch != '\n') || (GetOperateSymbol(&symbol) != '\n'))
    {
        if(!IsOperateSymbolOrNum(ch))
        {while(ch == ' '||(ch >= 'a' && ch <= 'z')||(ch >= 'A' && ch <= 'Z')) {
				printf("�������������벻Ҫ������ĸ��ո�\n"); 
     			ch = getchar();
			}   
            num = atoi(&ch);  //���ַ�ת��Ϊ����
            ch = getchar();   
             while(!IsOperateSymbolOrNum(ch))
            {while(ch == ' '||(ch > 'a' && ch < 'z')||(ch > 'A' && ch < 'Z')) {
					printf("�������������벻Ҫ������ĸ��ո�"); 
    				 ch = getchar();
				}
                num = num * 10 + atoi(&ch);
                ch = getchar();   //��û������س�ʱ��������ȡ����
 
            }
            PushOperateNum(&data, num);
        }
        else
        {
			//��һ�����Ǹ��������
			if(ch=='-'&&symbol.top==0&&data.top==-1)PushOperateNum(&data, 0);
            switch(Priority(GetOperateSymbol(&symbol), ch))
            {
                //�ж����ȼ�����м���
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
 
