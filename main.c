#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define NAME_MAXSIZE 20
#define SEX_MAXSIZE 5
#define NUM_MAXSIZE 20

typedef struct student
{
    char name[NAME_MAXSIZE];
    char sex[SEX_MAXSIZE];
    char num[NUM_MAXSIZE];
    int score;
}Stu;

typedef struct node
{
    Stu student;
    struct node* Next;
}Node;

//创建头节点
Node* creat_head()
{
    Node* head = (Node*)malloc(sizeof(Node));
    if (head == NULL)
    {
        printf("分配内存失败!");
        exit(0);
    }
    head->Next = NULL;
    return head;
}

//遍历单链表
void showlist(Node* head)
{
    Node* p = head->Next;
    printf("姓名\t\t性别\t\t学号\t\t\t分数\n");


    while (1)
    {
        if (p == NULL)
        {
            printf("\t\t\t列表为空!\t\t\t\n");
            break;
        }
        printf("%s\t\t%s\t\t%s\t\t\t%d\n", p->student.name, p->student.sex, p->student.num, p->student.score);
        p = p->Next;
        if (p == NULL)
        {
            free(p);
            break;
        }
    }

}

//头插法
void insert_head(Node* head)
{
    Stu student;
    printf("请输入学生的姓名\n");
    scanf("%s", student.name);
    printf("请输入学生的性别\n");
    scanf("%s", student.sex);
    printf("请输入学生的学号\n");
    scanf("%s", student.num);
    printf("请输入学生的得分\n");
    scanf("%d", &student.score);

    Node* node = (Node*)malloc(sizeof(Node));
    if (node == NULL)
    {
        printf("分配内存失败!");
        exit(0);
    }
    node->Next = NULL;
    node->student = student;
    node->Next = head->Next;
    head->Next = node;
    printf("添加完成!\n");
}
//查找个人信息
void search(Node* head)
{
    Node *p = head;
    printf("1.通过姓名检索\n");
    printf("2.通过学号检索\n");
    int a;
    scanf("%d", &a);
    if(a == 1)
    {
        char name[NAME_MAXSIZE];
        printf("请输入学生姓名\n");
        scanf("%s", name);
        while(1)
        {
            p = p->Next;
            if(p == NULL)
            {
                printf("未找到该姓名的学生信息\n");
                break;
            }
            if(strcmp(name, p->student.name) == 0)
            {
                printf("该学生信息:\n");
                printf("%s\t\t%s\t\t%s\t\t\t%d\n", p->student.name, p->student.sex, p->student.num, p->student.score);
                break;
            }
        }
    }
    else if(a == 2)
    {
        char num[NUM_MAXSIZE];
        printf("请输入学生学号\n");
        scanf("%s", num);
        while(1)
        {
            p = p->Next;
            if(p == NULL)
            {
                printf("未找到该姓名的学生信息\n");
                break;
            }
            if(strcmp(num, p->student.num) == 0)
            {
                printf("该学生信息:\n");
                printf("%s\t\t%s\t\t%s\t\t\t%d\n", p->student.name, p->student.sex, p->student.num, p->student.score);
                break;
            }
        }
    }
    else
    {
        printf("error");
    }
}

//删除学生信息
void del(Node* head)
{
    Node* p = head;
    Node* q = p; //获取前置节点要新定义一个指针
    printf("1.通过姓名删除\n");
    printf("2.通过学号删除\n");
    int a;
    scanf("%d", &a);
    if (a == 1)
    {
        char sign = '0';
        printf("请输入学生的姓名\n");
        char name[NAME_MAXSIZE] = {0};
        scanf("%s", name);
        while (1)
        {

            q = p;
            p = p->Next;
            if (p == NULL)
            {
                printf("未找到该姓名的学生信息\n");
                break;
            }
            if (strcmp(name, p->student.name) == 0)
            {
                printf("已检索到此人\n");
                printf("确定删除该学生信息?y/n\n");
                printf("%s\t\t%s\t\t%s\t\t\t%d\n", p->student.name, p->student.sex, p->student.num, p->student.score);
                scanf("%s", &sign);
                if (sign == 'y')
                {
                    q->Next = p->Next;
                    printf("删除成功!\n");
                    break;
                }
                else
                {
                    printf("已撤回操作\n");
                    break;
                }
            }

        }
    }


    else if (a == 2)
    {
        char a = '0';
        printf("请输入学生的学号\n");
        char num[NUM_MAXSIZE] = {0};
        scanf("%s", num);
        while (1)
        {
            q = p;
            p = p->Next;
            if (p == NULL)
            {
                printf("未找到该学号的学生信息\n");
                break;
            }
            if (strcmp(num, p->student.num) == 0)
            {
                printf("已检索到此人\n");
                printf("确定删除该学生信息?y/n\n");
                printf("%s\t\t%s\t\t%s\t\t\t%d\n", p->student.name, p->student.sex, p->student.num, p->student.score);
                scanf("%s", &a);
                if (a == 'y')
                {
                    q->Next = p->Next;
                    printf("删除成功!\n");
                    break;
                }
                else
                {
                    printf("已撤回操作\n");
                    break;
                }
            }
        }

    }
    else
    {
        printf("error!");
    }
}

//修改信息
void revise(Node* head)
{
    Node* p = head;
    printf("1.通过姓名检索修改\n");
    printf("2.通过学号检索修改\n");
    int a = 0;
    scanf("%d", &a);
    if(a == 1) //姓名检索
    {
        printf("请输入学生的姓名\n");
        char name[NAME_MAXSIZE];
        scanf("%s", name);
        while(1)
        {
            p = p->Next;
            if(p == NULL)
            {
                printf("未找到该姓名的学生信息\n");
                break;
            }
            if(strcmp(name, p->student.name) == 0)
            {
                printf("已检索到此人\n");
                printf("请输入修改后学生的姓名\n");
                scanf("%s", p->student.name);
                printf("请输入修改后学生的性别\n");
                scanf("%s", p->student.sex);
                printf("请输入修改后学生的学号\n");
                scanf("%s", p->student.num);
                printf("请输入修改后学生的分数\n");
                scanf("%d", &(p->student.score));
                printf("修改完成!\n");
                break;
            }
        }
    }
    else if(a == 2) //学号检索
    {
        printf("请输入学生的学号\n");
        char num[NUM_MAXSIZE];
        scanf("%s", num);
        while(1)
        {
            p = p->Next;
            if(p == NULL)
            {
                printf("未找到该学号的学生信息\n");
                break;
            }
            if(strcmp(num, p->student.num) == 0)
            {
                printf("已检索到此人\n");
                printf("请输入修改后学生的姓名\n");
                scanf("%s", p->student.name);
                printf("请输入修改后学生的性别\n");
                scanf("%s", p->student.sex);
                printf("请输入修改后学生的学号\n");
                scanf("%s", p->student.num);
                printf("请输入修改后学生的分数\n");
                scanf("%d", &(p->student.score));
                printf("修改完成!\n");
                break;
            }
        }
    }
    else
    {
        printf("error");
    }

}

void menu()
{
    printf(">>1.添加学生信息\n");
    printf(">>2.查找学生信息\n");
    printf(">>3.删除学生信息\n");
    printf(">>4.显示所有信息\n");
    printf(">>5.修改学生信息\n");
    printf("****************\n");
}

int main()
{

    Node* head = creat_head();
    int sign_ = 0;

    while (1)
    {
        menu();
        printf("请输入您的操作符>>");
        scanf("%d", &sign_);
        switch (sign_)
        {
        case 1: insert_head(head); system("pause"); break;
        case 2: search(head); system("pause"); break;
        case 3: del(head); system("pause"); break;
        case 4: showlist(head); system("pause"); break;
        case 5: revise(head); system("pause"); break;
        default: printf("error\n");system("pause"); break;
        }
        system("cls");
    }
    return 0;
}
