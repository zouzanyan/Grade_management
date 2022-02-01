#pragma warning(disable:6031)
#pragma warning(disable:4996)

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define NAME_MAXSIZE 20
#define SEX_MAXSIZE 5
#define NUM_MAXSIZE 20

int nodenum = 0; //节点数(学生个数)

typedef struct student
{
    char name[NAME_MAXSIZE];
    char sex[SEX_MAXSIZE];
    char num[NUM_MAXSIZE];
    float ch_score;
    float en_score;
    float job_score;
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
    printf("共有学生数: %d\n\n", nodenum);
    printf("姓名\t\t性别\t\t学号\t\t\t中文分数\t外语分数\t专业分数\n");


    while (1)
    {
        if (p == NULL)
        {
            printf("\t\t\t列表为空!\t\t\t\n");
            break;
        }
        printf("%s\t\t%s\t\t%s\t\t\t%.1f\t\t%.1f\t\t%.1f\n", p->student.name, p->student.sex, p->student.num, p->student.ch_score, p->student.en_score, p->student.job_score);
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
    printf("请输入学生的中文得分\n");
    scanf("%f", &student.ch_score);
    printf("请输入学生的外语得分\n");
    scanf("%f", &student.en_score);
    printf("请输入学生的专业得分\n");
    scanf("%f", &student.job_score);

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
    nodenum++;
}

//查找个人信息
void search(Node* head)
{
    Node* p = head;
    printf("1.通过姓名检索\n");
    printf("2.通过学号检索\n");
    int a;
    scanf("%d", &a);
    if (a == 1)
    {
        char name[NAME_MAXSIZE] = {0};
        printf("请输入学生姓名\n");
        scanf("%s", name);
        while (1)
        {
            p = p->Next;
            if (p == NULL)
            {
                printf("未找到该姓名的学生信息\n");
                break;
            }
            if (strcmp(name, p->student.name) == 0)
            {
                printf("该学生信息:\n");
                printf("姓名\t\t性别\t\t学号\t\t\t中文分数\t外语分数\t专业分数\n");
                printf("%s\t\t%s\t\t%s\t\t\t%.1f\t\t%.1f\t\t%.1f\n", p->student.name, p->student.sex, p->student.num, p->student.ch_score, p->student.en_score, p->student.job_score);
                break;
            }
        }
    }
    else if (a == 2)
    {
        char num[NUM_MAXSIZE] = {0};
        printf("请输入学生学号\n");
        scanf("%s", num);
        while (1)
        {
            p = p->Next;
            if (p == NULL)
            {
                printf("未找到该姓名的学生信息\n");
                break;
            }
            if (strcmp(num, p->student.num) == 0)
            {
                printf("该学生信息:\n");
                printf("%s\t\t%s\t\t%s\t\t\t%.1f\t\t%.1f\t\t%.1f\n", p->student.name, p->student.sex, p->student.num, p->student.ch_score, p->student.en_score, p->student.job_score);
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
        char name[NAME_MAXSIZE] = { 0 };
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
                printf("%s\t\t%s\t\t%s\t\t\t%.1f\t\t%.1f\t\t%.1f\n", p->student.name, p->student.sex, p->student.num, p->student.ch_score, p->student.en_score, p->student.job_score);
                scanf("%s", &sign);
                if (sign == 'y')
                {
                    q->Next = p->Next;
                    printf("删除成功!\n");
                    nodenum--;
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
        char num[NUM_MAXSIZE] = { 0 };
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
                printf("%s\t\t%s\t\t%s\t\t\t%.1f\t\t%.1f\t\t%.1f\n", p->student.name, p->student.sex, p->student.num, p->student.ch_score, p->student.en_score, p->student.job_score);
                scanf("%s", &a);
                if (a == 'y')
                {
                    q->Next = p->Next;
                    printf("删除成功!\n");
                    nodenum--;
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
    if (a == 1) //姓名检索
    {
        printf("请输入学生的姓名\n");
        char name[NAME_MAXSIZE];
        scanf("%s", name);
        while (1)
        {
            p = p->Next;
            if (p == NULL)
            {
                printf("未找到该姓名的学生信息\n");
                break;
            }
            if (strcmp(name, p->student.name) == 0)
            {
                printf("已检索到此人\n");
                printf("请输入修改后学生的姓名\n");
                scanf("%s", p->student.name);
                printf("请输入修改后学生的性别\n");
                scanf("%s", p->student.sex);
                printf("请输入修改后学生的学号\n");
                scanf("%s", p->student.num);
                printf("请输入修改后学生的中文得分\n");
                scanf("%f", &(p->student.ch_score));
                printf("请输入修改后学生的外语得分\n");
                scanf("%f", &(p->student.en_score));
                printf("请输入修改后学生的专业得分\n");
                scanf("%f", &(p->student.job_score));
                printf("修改完成!\n");
                break;
            }
        }
    }
    else if (a == 2) //学号检索
    {
        printf("请输入学生的学号\n");
        char num[NUM_MAXSIZE];
        scanf("%s", num);
        while (1)
        {
            p = p->Next;
            if (p == NULL)
            {
                printf("未找到该学号的学生信息\n");
                break;
            }
            if (strcmp(num, p->student.num) == 0)
            {
                printf("已检索到此人\n");
                printf("请输入修改后学生的姓名\n");
                scanf("%s", p->student.name);
                printf("请输入修改后学生的性别\n");
                scanf("%s", p->student.sex);
                printf("请输入修改后学生的学号\n");
                scanf("%s", p->student.num);
                printf("请输入修改后学生的中文得分\n");
                scanf("%f", &(p->student.ch_score));
                printf("请输入修改后学生的外语得分\n");
                scanf("%f", &(p->student.en_score));
                printf("请输入修改后学生的专业得分\n");
                scanf("%f", &(p->student.job_score));
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

void analyse(Node* head)
{
    float ch_hign = 0; //最高分
    float en_hign = 0;
    float job_hign = 0;
    float ch_low = 0; // 最低分
    float en_low = 0;
    float job_low = 0;
    double ch_average = 0; //平均分
    double en_average = 0;
    double job_average = 0;
    Node* p = head->Next;
    Node* q = p;

    if (p == NULL)
    {
        printf("列表为空\n");
    }
    else if (p->Next == NULL)
    {
        ch_hign = p->student.ch_score;
        ch_low = p->student.ch_score;
        en_hign = p->student.en_score;
        en_low = p->student.en_score;
        job_hign = p->student.job_score;
        job_low = p->student.job_score;
        ch_average = p->student.ch_score / nodenum;
        en_average = p->student.en_score / nodenum;
        job_average = p->student.job_score / nodenum;
    }
    else
    {
        ch_hign = p->student.ch_score;
        ch_low = p->student.ch_score;
        en_hign = p->student.en_score;
        en_low = p->student.en_score;
        job_hign = p->student.job_score;
        job_low = p->student.job_score;
        for (int i = nodenum - 1; i > 0; i--)
        {
            q = p;
            p = p->Next;
            ch_average += p->student.ch_score / nodenum;
            en_average += p->student.en_score / nodenum;
            job_average += p->student.job_score / nodenum;
            if (ch_hign < p->student.ch_score)
                ch_hign = p->student.ch_score;
            if (ch_low > p->student.ch_score)
                ch_low = p->student.ch_score;
            if (en_hign < p->student.en_score)
                en_hign = p->student.en_score;
            if (en_low > p->student.en_score)
                en_low = p->student.en_score;
            if (job_hign < p->student.job_score)
                job_hign = p->student.job_score;
            if (job_low > p->student.job_score)
                job_low = p->student.job_score;
        }
        ch_average += head->Next->student.ch_score / nodenum;
        en_average += head->Next->student.en_score / nodenum;
        job_average += head->Next->student.job_score / nodenum;
        printf("中文最高分为 %.1f\n", ch_hign);
        printf("中文最低分为 %.1f\n", ch_low);
        printf("中文平均分为 %.2lf\n\n", ch_average);
        printf("外语最高分为 %.1f\n", en_hign);
        printf("外语最低分为 %.1f\n", en_low);
        printf("外语平均分为 %.2lf\n\n", en_average);
        printf("专业最高分为 %.1f\n", job_hign);
        printf("专业最低分为 %.1f\n", job_low);
        printf("专业平均分为 %.2lf\n", job_average);
    }
}


void sort(Node* head) //排序
{
    Node* p = head->Next;
    Node* q = p;
    printf("1.通过中文成绩排序\n");
    printf("2.通过外语成绩排序\n");
    printf("3.通过专业成绩排序\n");

    Stu t;
    int sign;
    scanf("%d", &sign);
    if (sign == 1)
    {
        if (p == NULL)
        {
            printf("列表为空\n");
            return;
        }
        for (int i = nodenum - 1; i > 0; i--)//冒泡排序
        {
            for (int j = 0; j < i; j++)
            {
                q = p;
                p = p->Next;
                if (p->student.ch_score > q->student.ch_score)
                {
                    t = p->student;
                    p->student = q->student;
                    q->student = t;
                }
            }
            p = head->Next; //每得到一个最大的数要把指针初始化
            q = p;
        }
        printf("排列完成!\n");
    }
    if (sign == 2)
    {
        if (p == NULL)
        {
            printf("列表为空\n");
            return;
        }
        for (int i = nodenum - 1; i > 0; i--) //冒泡排序
        {

            for (int j = 0; j < i; j++)
            {
                q = p;
                p = p->Next;
                if (p->student.en_score > q->student.en_score)
                {
                    t = p->student;
                    p->student = q->student;
                    q->student = t;
                }
            }
            p = head->Next;
            q = p;
        }
        printf("排列完成!\n");
    }
    if (sign == 3)
    {
        if (p == NULL)
        {
            printf("列表为空\n");
            return;
        }
        for (int i = nodenum - 1; i > 0; i--) //冒泡排序
        {

            for (int j = 0; j < i; j++)
            {
                q = p;
                p = p->Next;
                if (p->student.job_score > q->student.job_score)
                {
                    t = p->student;
                    p->student = q->student;
                    q->student = t;
                }
            }
            p = head->Next;
            q = p;
        }
        printf("排列完成!\n");
    }
}

void menu()
{
    printf("---------- 学生成绩管理系统 -------\n");
    printf("*                                 *\n");
    printf("*********  1.添加学生信息  *********\n");
    printf("*********  2.查找学生信息  *********\n");
    printf("*********  3.删除学生信息  *********\n");
    printf("*********  4.显示所有信息  *********\n");
    printf("*********  5.修改学生信息  *********\n");
    printf("*********  6.排列学生信息  *********\n");
    printf("*********  7.分析学生数据  *********\n");
    printf("*                                 *\n");
    printf("-----------------------------------\n");
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
        case 6: sort(head); system("pause"); break;
        case 7: analyse(head); system("pause"); break;
        default: printf("error\n"); system("pause"); break;
        }
        system("cls");
    }
    return 0;
}

//有时间再精简一下代码,代码目前比较杂乱冗余
//qq1406823510  欢迎交流
