//C99ǰ,����Ĵ�С�ó�����������ʽ��ָ��. 
//const int a �ǳ�����,���ڱ���,ֻ��ֵȷ�� 
//C99ǰʹ�ñ��������鶨���С,������malloc.malloc����void,�������Byte 
//sizeof() ��ȡ��λ������ռ�ֽ�
//malloc�������free(),freeʧ�ܷ���0��NULL
//***free()����������ʱ��ԭʼ��ַ 
//����free(NULL),��˸�ָ���ʼ��0�Ǻ�ϰ�� 
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int number;
	int *a=0;
	printf("Input a number\n");
	scanf("%d",&number);
	// int a[number]; C99ǰ���� 
	a=(int*)malloc(number*sizeof(int));
	free(a);
	return 0;
}
