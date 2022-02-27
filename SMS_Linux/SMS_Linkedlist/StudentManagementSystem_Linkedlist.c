#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

struct Student
{
	int id;
	int age;
	char name[32];
	char tel[12];
	struct Student *next;
};

typedef struct Student Student;

void InitLink(Student **s)
{
	(*s) = (Student *)malloc(sizeof(Student) * 1);
	if(NULL == *s)
	{
		printf("申请头节点失败！\n");
		return;
	}

	(*s)->next = NULL;
}

void welcome()
{
	system("clear");
	printf("------------------------------------------------------------------\n");
	printf("\t\t欢迎进入学生管理系统\n");
	printf("------------------------------------------------------------------\n");
	
	sleep(2);
}

void menum()
{
	system("clear");

	printf("------------------------------------------------------------------\n");
	printf("\t\t1、添加学生信息		2、显示学生信息\n");
	printf("\t\t3、查找学生信息		4、修改学生信息\n");
	printf("\t\t5、删除学生信息		6、退出系统\n");
	printf("------------------------------------------------------------------\n");
}

int LocateElem(Student *head, Student s)
{
	if(NULL == head)
		return -1;

	int p = 1;
	Student *n = head->next;	//指向链表第一个元素

	//遍历链表
	while(n)
	{
		if(n->id > s.id)
		{
			return p;
		}

		n = n->next;
		p++;
	}

	return p;
}

void InsertLink(Student *head, int num, Student s)
{
	if(NULL == head)
		return;

	Student *n = head;
	int k = 1;

	while(k<num && n)
	{
		n = n->next;
		k++;
	}

	if(NULL == n || k > num)
	{
		printf("插入位置有误!\n");
		return;
	}

	Student *m = (Student *)malloc(sizeof(Student) * 1);
	if(NULL == m)
	{
		printf("申请节点失败\n");
		return;
	}

	m->id = s.id;
	m->age = s.age;
	strcpy(m->name, s.name);
	strcpy(m->tel, s.tel);

	m->next = n->next;
	n->next = m;
}

void add_info(Student *head)
{
	if(NULL == head)
	{
		printf("error, head is NULL \n");
		return;
	}

	printf("请输入学号、年龄、姓名、电话...\n");

	Student s;
	int flag = 1;
	while(flag)
	{
		scanf("%d%d%s%s", &s.id, &s.age, s.name, s.tel);

		//判断电话号码长度
		if(strlen(s.tel) != 11)
		{
			printf("电话号码长度输入有误，请重新输入全部信息\n");
			continue;
		}

		//判断电话号码是否重复
		flag = 0;
		//遍历链表，判断电话是否重复
		Student *p = head->next;
		while(p)  
		{
			if(!strcmp(s.tel, p->tel))
			{
				printf("输入的电话号码重复，请重新输入\n");
				flag = 1;
				break;
			}
			p = p->next;
		}
	}

	//确定要插入的位置，按学号顺序插入
	int num = LocateElem(head, s);

	InsertLink(head, num, s);
	
	printf("插入数据成功\n");
	sleep(2);
}

void show_info(Student *head)
{
	if(NULL == head)
		return;

	printf("%5s %5s %5s %5s\n", "学号", "年龄", "姓名", "电话");
	Student *p = head->next;
	while(p)
	{
		printf("%d %d %s %s \n", p->id, p->age, p->name, p->tel);
		p = p->next;
	}

	sleep(2);
}

void find_info(Student *head)
{
	if(NULL == head)
		return;

	printf("请输入查找条件（1）按学号查找（2）按姓名查找\n");
	int choice;
	scanf("%d", &choice);
	
	if(1 == choice)
	{
		printf("请输入学号\n");
		int id;
		scanf("%d", &id);

		Student *p = head->next;
		while(p)
		{
			if(p->id == id)
			{
				printf("%d %d %s %s\n", p->id, p->age, p->name, p->tel);
				sleep(2);
				return;
			}
			p = p->next;
		}

		printf("学号不存在!\n");
		sleep(2);
	}
	else if(2 == choice)
	{
		printf("请输入姓名\n");
		char name[32] = {0};
		scanf("%s", name);

		Student *p = head->next;

		while(p)
		{
			if(!strcmp(p->name, name))
			{
				printf("%d %d %s %s\n", p->id, p->age, p->name, p->tel);
				sleep(2);
				return;
			}
			p = p->next;
		}

		printf("姓名不存在!\n");
		sleep(2);
	}
	else
	{
		printf("输入的查找条件有误!\n");
		sleep(2);
	}
}

void delete_info(Student *head, int id)
{
	if(NULL == head)
		return;

	Student *pFront = head->next, *pBehind = head;

	while(pFront)
	{
		if(pFront->id == id)
		{
			pBehind->next = pFront->next;
			free(pFront);

			printf("删除信息成功!\n");
			sleep(2);
			return;
		}
		pFront = pFront->next;
		pBehind = pBehind->next;
	}

	printf("学生不存在\n");
	sleep(2);
}

void modify_info(Student *head)
{
	if(NULL == head)
		return;

	printf("请输入要修改学生的学号\n");
	int id;
	scanf("%d", &id);

	Student *p = head->next;
	while(p)
	{
		if(p->id == id)
		{
			//先删除信息
			delete_info(head, id);

			//再添加信息
			add_info(head);
		
			printf("信息修改成功!\n");
			sleep(2);
			return;
		}
		p = p->next;
	}

	printf("学生信息不存在\n");
	sleep(2);
}

int main()
{
	//定义链表头指针
	Student *head = NULL;

	InitLink(&head);

	welcome();

	while(1)
	{
		int chioce;

		//菜单
		menum();

Flag:
		scanf("%d", &chioce);

		switch(chioce)
		{
			case 1:
				add_info(head);
				break;
			case 2:
				show_info(head);
				break;
			case 3:
				find_info(head);
				break;
			case 4:
				modify_info(head);
				break;
			case 5:
				printf("请输入要删除的学号\n");
				int id;
				scanf("%d", &id);
				delete_info(head, id);
				break;
			case 6:
				exit(1);
				break;
			default:
				printf("输入的信息不合法!请重新输入\n");
				goto Flag;
		}
	}

	return 0;
}

