# 学生信息管理系统-Linux
Student Management System（SMS）

# 练习 1
写一个简单的学生管理系统-数组版，实现基本信息的“增删改查”功能，掌握指针数组的使用。

# 练习 2
写一个简单的学生管理系统-单向链表版，实现基本信息的“增删改查”功能，掌握链表的使用。

# 练习 3
在练习2的基础上，加上sqlite3数据库，可以本地保存数据不丢失

# sqlite3 数据库
#安装数据库 ubuntu+sqlite3

apt-get install sqlite3 libsqlite3-dev

#使用

ubuntu@VM-8-5-ubuntu:~$ sqlite3

SQLite version 3.22.0 2018-01-22 18:45:57

Enter ".help" for usage hints.

Connected to a transient in-memory database.

Use ".open FILENAME" to reopen on a persistent database.

sqlite>

sqlite> create table if not exists student (id integer, age integer, name text, tel text);

---------------

ubuntu@VM-8-5-ubuntu:~/Cstudy$ sqlite3 student.db

SQLite version 3.22.0 2018-01-22 18:45:57

Enter ".help" for usage hints.

sqlite>

sqlite> .table

student

sqlite> select * from student;

1|11|阿|11111111111

# 编译
gcc StudentManagementSystem_sqlite3.c -o SMS_sqlite3 -lsqlite3

#Makefile编译

TARGET:=./destdir/SMS_sqlite3

OBJS:=StudentManagementSystem_sqlite3.o

LIBS:=-lsqlite3

$(TARGET):$(OBJS)

    $(CC) $^ -o $@ $(LIBS)

clean:

    $(RM) $(TARGET) $(OBJS)

.PHONY:clean

------------------------------------------------------------------------------------------------
# Makefile
AR		库文件维护程序的名称，默认为ar

AS		汇编程序的名称，默认为as

CC		C编译器的名称，默认值为cc

CPP		C预编译器的名称，默认为$(CC)-E

CXX		c++编译器的名称，默认为g++

RM		文件删除程序的名称，默认值为rm -f

ARFLAGS		库文件维护程序的选项，无默认值

ASFLAGS		汇编程序的选项，无默认值

CFLAGS		C编译器的选项，无默认值

CPPFLAGS	C预编译器的选项，无默认值

CXX		C编译器的选项，无默认值

#同目录下文件编译

#例如编译 “StudentManagementSystem.c”

/************************第一版Makefile********************************/

StudentManagementSystem:StudentManagementSystem.c

    gcc StudentManagementSystem.c -o StudentManagementSystem

/************************第二版Makefile*******************************/

TARGET:=./destdir/StudentMS

#依赖文件

OBJS:=StudentManagementSystem.o

#编译

$(TARGET):$(OBJS)

    $(CC) $^ -o $@

#清理

clean:

    $(RM) $(TARGET) $(OBJS)

.PHONY:clean
