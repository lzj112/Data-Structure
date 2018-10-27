//线性表顺序存储的结构代码

#define MAXSIZE 20  //存储空间初始分配量
typedef int Elemtype;    //Elemtype 类型根据实际情况而定, 这里假设为 int

typedef struct 
{
    Elemtype data[MAXSIZE]; //数组存储数据元素, 最大值为 MAXSIZE
    int length; //线性表当前长度
}SqList;    


//线性表链式存储结构代码
typedef struct Node 
{
    Elemtype data;
    struct Node* next;
} Node;
typedef struct Node* LinkList;  //定义 LinkList

//静态链表
#define  MAXSIZE 1000
typedef struct 
{
    Elemtype data;
    int cure;   //游标 (Cursor), 为0时表示无指向
}Component, StaticLinkList[MAXSIZE];