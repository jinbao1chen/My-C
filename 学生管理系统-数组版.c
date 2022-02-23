#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

struct Student
{
	int id;
	char name[32];
	int age;
	char tel[12];
};

typedef struct Student stu;

#define MAX 1024				//表示最多存放的学生数

stu *g_info[MAX] = {0};			//数组用于存放学生信息（结构体的地址）
int g_count = 0;				//表示当前学生人数


void welcome()
{
	system("clear");

	printf("-------------------------------------------------\n\n");
	printf("\t\t欢迎使用学生管理系统\n\n");
	printf("-------------------------------------------------\n\n");
	
	sleep(2);
}

void menum()
{
	system("clear");
	printf("-------------------------------------------------\n\n");
	printf("\t\t1、添加信息  2、显示信息\n\n");
	printf("\t\t3、修改信息  4、删除信息\n\n");
	printf("\t\t5、查找信息  6、退出系统\n\n");
	printf("-------------------------------------------------\n\n");
}

void add_info()
{
	printf("请输入学生信息：学号、姓名、年龄、电话\n");

	g_info[g_count] = (stu *)malloc(sizeof(stu) * 1);
	if(NULL == g_info[g_count])
	{
		printf("申请内存失败\n");
		exit(1);
	}

	int flag = 1;
	while(flag)
	{
		scanf("%d%s%d%s", &g_info[g_count]->id, g_info[g_count]->name,
							&g_info[g_count]->age, g_info[g_count]->tel);
		//printf("%d %s %d %s\n",g_info[g_count]->id, g_info[g_count]->name,
		//					g_info[g_count]->age, g_info[g_count]->tel);

		//判断电话号码长度
		if(strlen(g_info[g_count]->tel) != 11)
		{
			printf("输入的电话号码有误，请重新输入...\n");
			continue;
		}

		//判断电话号码是否重复
		int i;
		for(i=0; i<g_count; i++)
		{
			if(strcmp(g_info[i]->tel, g_info[g_count]->tel) == 0)
			{
				printf("电话号码重复，请重新输入...\n");
				flag = 1;
				break;
			}
		}

		if(i == g_count)
		{
			flag = 0;
		}
	}

	g_count++;
	printf("添加学生信息成功!\n");
	sleep(2);
}

void modify_info()
{
	printf("请输入要修改的学号:\n");
	int id;

Flag:
	scanf("%d", &id);
	
	int i;
	for(i=0; i<g_count; i++)
	{
		if(g_info[i]->id == id)
		{
			//找到要修改的学生，修改信息
			printf("当前学生信息如下：\n");
			printf("%d %s %d %s \n", g_info[i]->id, g_info[i]->name,
										g_info[i]->age, g_info[i]->tel);
			printf("请输入修改的信息:\n");
			
			int flag;
			while(flag)
			{
				scanf("%d%s%d%s", &g_info[i]->id, g_info[i]->name,
							&g_info[i]->age, g_info[i]->tel);
				//printf("%d %s %d %s\n",g_info[i]->id, g_info[i]->name,
				//					g_info[i]->age, g_info[i]->tel);

				//判断电话号码长度
				if(strlen(g_info[i]->tel) != 11)
				{
					printf("输入的电话号码有误，请重新输入...\n");
					continue;
				}

				//判断电话号码是否重复
				int j;
				for(j=0; j<g_count; j++)
				{
					if(j == i)
						continue;

					if(strcmp(g_info[i]->tel, g_info[j]->tel) == 0)
					{
						printf("电话号码重复，请重新输入...\n");
						flag = 1;
						break;
					}
				}
		
				if(j == g_count)
				{		
					flag = 0;
				}
			}

			printf("修改成功!\n");
			sleep(2);
			return;
		}
	}

	if(i == g_count)
	{
		printf("输入的学号不存在，请重新输入!\n");
		goto Flag;
	}
}

void delete_info()
{
	printf("请输入要删除的学号:\n");
	int id;
	scanf("%d", &id);

	int i,j;
	for(i=0; i<g_count; i++)
	{
		if(g_info[i]->id == id)
		{
			//删除信息
			free(g_info[i]);
			//后面的信息依次向前覆盖
			for(j=0; j<g_count-i-1; j++)
			{
				g_info[i+j] = g_info[i+1+j];
			}

			g_count--;

			printf("删除成功!\n");
			sleep(2);

			return;
		}
	}

	printf("学号不存在!\n");
	sleep(2);
}

void show_info()
{
	//冒泡排序，按照学号输出
	int i,j;
	stu *tmp;
	for(int i=0; i<g_count-1; i++)
	{
		for(j=0; j<g_count - i - 1; j++)
		{
			if(g_info[j]->id > g_info[j+1]->id)
			{
				tmp = g_info[j];
				g_info[j] = g_info[j+1];
				g_info[j+1] = tmp;
			}
		}
	}

	printf("%8s %7s %7s %8s\n", "学号", "姓名", "年龄", "电话");
	for(i=0; i<g_count; i++)
	{
		printf("%5d %5s %5d %5s\n", g_info[i]->id, g_info[i]->name, g_info[i]->age, g_info[i]->tel);
	}

	sleep(2);
}

void find_info()
{
Flag:
	printf("根据学号查找（1）还是根据姓名查找（2）\n");
	int choice, i;
	scanf("%d",&choice);
	if(1 == choice)
	{
		printf("请输入要查找的学号:\n");
		int id;
		scanf("%d", &id);
		for(i=0; i<g_count; i++)
		{
			if(id == g_info[i]->id)
			{
				printf("%5d %5s %5d %5s\n",g_info[i]->id, g_info[i]->name, 
											g_info[i]->age, g_info[i]->tel);
		
				printf("查找成功！\n");
        		sleep(2);
		        return;

			}
		}
		
		printf("学号不存在！\n");
		sleep(2);
	}
	else if(2 == choice)
	{
		printf("请输入要查找的姓名: \n");
		char name[32] = {0};
		scanf("%s",name);
		for(i=0; i<g_count; i++)
		{
			if(!strcmp(name, g_info[i]->name))
			{
			
				printf("%5d %5s %5d %5s\n",g_info[i]->id, g_info[i]->name, 
											g_info[i]->age, g_info[i]->tel);
		
				printf("查找成功！\n");
				sleep(2);
				return;
			}
		}

		printf("姓名不存在!\n");
		sleep(2);
	}
	else
	{
		printf("输入内容不合法，请重新输入!\n");
		sleep(2);
		goto Flag;
	}

}

int main()
{
	int choice;

	welcome();

	while (1)
	{
    	menum();

		scanf("%d", &choice);

		switch(choice)
		{
			case 1:
				add_info();
				break;
			case 2:
				show_info();
				break;
			case 3:
				modify_info();
				break;
			case 4:
				delete_info();
				break;
			case 5:
				find_info();
				break;
			case 6:
				exit(0);
		
			default:
				printf("输入有误，请重新输入！\n");
		}
	}

	return 0;
}
