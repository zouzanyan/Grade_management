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

//����ͷ�ڵ�
Node* creat_head()
{
    Node* head = (Node*)malloc(sizeof(Node));
    if (head == NULL)
    {
        printf("�����ڴ�ʧ��!");
        exit(0);
    }
    head->Next = NULL;
    return head;
}

//����������
void showlist(Node* head)
{
    Node* p = head->Next;
    printf("����\t\t�Ա�\t\tѧ��\t\t\t����\n");


    while (1)
    {
        if (p == NULL)
        {
            printf("\t\t\t�б�Ϊ��!\t\t\t\n");
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

//ͷ�巨
void insert_head(Node* head)
{
    Stu student;
    printf("������ѧ��������\n");
    scanf("%s", student.name);
    printf("������ѧ�����Ա�\n");
    scanf("%s", student.sex);
    printf("������ѧ����ѧ��\n");
    scanf("%s", student.num);
    printf("������ѧ���ĵ÷�\n");
    scanf("%d", &student.score);

    Node* node = (Node*)malloc(sizeof(Node));
    if (node == NULL)
    {
        printf("�����ڴ�ʧ��!");
        exit(0);
    }
    node->Next = NULL;
    node->student = student;
    node->Next = head->Next;
    head->Next = node;
    printf("������!\n");
}
//���Ҹ�����Ϣ
void search(Node* head)
{
    Node *p = head;
    printf("1.ͨ����������\n");
    printf("2.ͨ��ѧ�ż���\n");
    int a;
    scanf("%d", &a);
    if(a == 1)
    {
        char name[NAME_MAXSIZE];
        printf("������ѧ������\n");
        scanf("%s", name);
        while(1)
        {
            p = p->Next;
            if(p == NULL)
            {
                printf("δ�ҵ���������ѧ����Ϣ\n");
                break;
            }
            if(strcmp(name, p->student.name) == 0)
            {
                printf("��ѧ����Ϣ:\n");
                printf("%s\t\t%s\t\t%s\t\t\t%d\n", p->student.name, p->student.sex, p->student.num, p->student.score);
                break;
            }
        }
    }
    else if(a == 2)
    {
        char num[NUM_MAXSIZE];
        printf("������ѧ��ѧ��\n");
        scanf("%s", num);
        while(1)
        {
            p = p->Next;
            if(p == NULL)
            {
                printf("δ�ҵ���������ѧ����Ϣ\n");
                break;
            }
            if(strcmp(num, p->student.num) == 0)
            {
                printf("��ѧ����Ϣ:\n");
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

//ɾ��ѧ����Ϣ
void del(Node* head)
{
    Node* p = head;
    Node* q = p; //��ȡǰ�ýڵ�Ҫ�¶���һ��ָ��
    printf("1.ͨ������ɾ��\n");
    printf("2.ͨ��ѧ��ɾ��\n");
    int a;
    scanf("%d", &a);
    if (a == 1)
    {
        char sign = '0';
        printf("������ѧ��������\n");
        char name[NAME_MAXSIZE] = {0};
        scanf("%s", name);
        while (1)
        {

            q = p;
            p = p->Next;
            if (p == NULL)
            {
                printf("δ�ҵ���������ѧ����Ϣ\n");
                break;
            }
            if (strcmp(name, p->student.name) == 0)
            {
                printf("�Ѽ���������\n");
                printf("ȷ��ɾ����ѧ����Ϣ?y/n\n");
                printf("%s\t\t%s\t\t%s\t\t\t%d\n", p->student.name, p->student.sex, p->student.num, p->student.score);
                scanf("%s", &sign);
                if (sign == 'y')
                {
                    q->Next = p->Next;
                    printf("ɾ���ɹ�!\n");
                    break;
                }
                else
                {
                    printf("�ѳ��ز���\n");
                    break;
                }
            }

        }
    }


    else if (a == 2)
    {
        char a = '0';
        printf("������ѧ����ѧ��\n");
        char num[NUM_MAXSIZE] = {0};
        scanf("%s", num);
        while (1)
        {
            q = p;
            p = p->Next;
            if (p == NULL)
            {
                printf("δ�ҵ���ѧ�ŵ�ѧ����Ϣ\n");
                break;
            }
            if (strcmp(num, p->student.num) == 0)
            {
                printf("�Ѽ���������\n");
                printf("ȷ��ɾ����ѧ����Ϣ?y/n\n");
                printf("%s\t\t%s\t\t%s\t\t\t%d\n", p->student.name, p->student.sex, p->student.num, p->student.score);
                scanf("%s", &a);
                if (a == 'y')
                {
                    q->Next = p->Next;
                    printf("ɾ���ɹ�!\n");
                    break;
                }
                else
                {
                    printf("�ѳ��ز���\n");
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

//�޸���Ϣ
void revise(Node* head)
{
    Node* p = head;
    printf("1.ͨ�����������޸�\n");
    printf("2.ͨ��ѧ�ż����޸�\n");
    int a = 0;
    scanf("%d", &a);
    if(a == 1) //��������
    {
        printf("������ѧ��������\n");
        char name[NAME_MAXSIZE];
        scanf("%s", name);
        while(1)
        {
            p = p->Next;
            if(p == NULL)
            {
                printf("δ�ҵ���������ѧ����Ϣ\n");
                break;
            }
            if(strcmp(name, p->student.name) == 0)
            {
                printf("�Ѽ���������\n");
                printf("�������޸ĺ�ѧ��������\n");
                scanf("%s", p->student.name);
                printf("�������޸ĺ�ѧ�����Ա�\n");
                scanf("%s", p->student.sex);
                printf("�������޸ĺ�ѧ����ѧ��\n");
                scanf("%s", p->student.num);
                printf("�������޸ĺ�ѧ���ķ���\n");
                scanf("%d", &(p->student.score));
                printf("�޸����!\n");
                break;
            }
        }
    }
    else if(a == 2) //ѧ�ż���
    {
        printf("������ѧ����ѧ��\n");
        char num[NUM_MAXSIZE];
        scanf("%s", num);
        while(1)
        {
            p = p->Next;
            if(p == NULL)
            {
                printf("δ�ҵ���ѧ�ŵ�ѧ����Ϣ\n");
                break;
            }
            if(strcmp(num, p->student.num) == 0)
            {
                printf("�Ѽ���������\n");
                printf("�������޸ĺ�ѧ��������\n");
                scanf("%s", p->student.name);
                printf("�������޸ĺ�ѧ�����Ա�\n");
                scanf("%s", p->student.sex);
                printf("�������޸ĺ�ѧ����ѧ��\n");
                scanf("%s", p->student.num);
                printf("�������޸ĺ�ѧ���ķ���\n");
                scanf("%d", &(p->student.score));
                printf("�޸����!\n");
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
    printf(">>1.���ѧ����Ϣ\n");
    printf(">>2.����ѧ����Ϣ\n");
    printf(">>3.ɾ��ѧ����Ϣ\n");
    printf(">>4.��ʾ������Ϣ\n");
    printf(">>5.�޸�ѧ����Ϣ\n");
    printf("****************\n");
}

int main()
{

    Node* head = creat_head();
    int sign_ = 0;

    while (1)
    {
        menu();
        printf("���������Ĳ�����>>");
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
