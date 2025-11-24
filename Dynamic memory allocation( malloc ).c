//C99前,数组的大小用常量或常量表达式来指定. 
//const int a 是常变量,属于变量,只是值确定 
//C99前使用变量给数组定义大小,必须用malloc.malloc返回void,申请的是Byte
//sizeof() 获取单位类型所占字节
//malloc后必须用free(),free失败返回0或NULL
//***free()必须是申请时的原始地址 
//允许free(NULL),因此给指针初始化0是好习惯 
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int number;
	int *a=0;
	printf("Input a number\n");
	scanf("%d",&number);
	// int a[number]; C99前不行 
	a=(int*)malloc(number*sizeof(int));
	free(a);
	return 0;
}
