# My-C
Student Management System（Array practice）

# 练习 1
写一个简单的学生管理系统-数组版，实现基本信息的“增删改查”功能，掌握指针数组的使用。

# 练习 2
写一个简单的学生管理系统-单向链表版，实现基本信息的“增删改查”功能，掌握链表的使用。

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
