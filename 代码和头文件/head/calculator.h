/**************************************************************
*	Multi-Include-Prevent Section
**************************************************************/
#ifndef CAL_CORE_H_INCLUDED
#define CAL_CORE_H_INCLUDED

/**************************************************************
*	Macro Define Section
**************************************************************/

#define OVERFLOW -1
#define MAX 100 

/**************************************************************
*	Struct Define Section
**************************************************************/

//�����������ջ 
struct SNode_Num
{
    int data[MAX];
    int top;
};
//����������ջ 
struct SNode_Symbol
{
    char symbol[MAX];
    int top;
};
typedef struct SNode_Num OperateNum;
typedef struct SNode_Symbol OperateSymbol;

/**************************************************************
*	Prototype Declare Section
**************************************************************/

int GetOperateNum(OperateNum *StackNum);//ȡ��

char GetOperateSymbol(OperateSymbol *StackSymbol);//ȡ�����

int IsOperateSymbolOrNum(char ch);//���������,����������������ж�Ϊ��

char Priority(char inputnum, char ch);//�ж���������ȼ�����ѧ�Ⱥ� 

void PushOperateNum(OperateNum *StackNum, int x);//����ջ

int PopOperateNum(OperateNum *StackNum);//����ջ 

void PushOperateSymbol(OperateSymbol *StackSymbol, char ch);//�������ջ

char PopOperateSymbol(OperateSymbol *StackSymbol);//�������ջ 

int Calculate(int num1, char ch, int num2);//����ִ���������� 

int CalcCore();//���롢���봦��ͼ������ 

 /**************************************************************
*	End-Multi-Include-Prevent Section
**************************************************************/
#endif
 
 
