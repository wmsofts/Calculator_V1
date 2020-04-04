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

//存放运算数的栈 
struct SNode_Num
{
    int data[MAX];
    int top;
};
//存放运算符的栈 
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

int GetOperateNum(OperateNum *StackNum);//取数

char GetOperateSymbol(OperateSymbol *StackSymbol);//取运算符

int IsOperateSymbolOrNum(char ch);//判误运算符,不是四则运算符则判断为误

char Priority(char inputnum, char ch);//判断运算符优先级和数学等号 

void PushOperateNum(OperateNum *StackNum, int x);//数进栈

int PopOperateNum(OperateNum *StackNum);//数出栈 

void PushOperateSymbol(OperateSymbol *StackSymbol, char ch);//运算符进栈

char PopOperateSymbol(OperateSymbol *StackSymbol);//运算符出栈 

int Calculate(int num1, char ch, int num2);//两数执行四则运算 

int CalcCore();//输入、输入处理和计算核心 

 /**************************************************************
*	End-Multi-Include-Prevent Section
**************************************************************/
#endif
 
 
