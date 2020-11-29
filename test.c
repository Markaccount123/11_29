#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//1.什么是文件
//2.文件名 
//3.文件类型 
//4.文件缓冲区
//5.文件指针 
//6.文件的打开和关闭
//7.文件的顺序读写
//8.文件的随机读写 
//9.文件结束的判定
//磁盘上的文件是文件。
//但是在程序设计中，我们一般谈的文件有两种：程序文件、数据文件

//#include <stdio.h> 
//int main() 
//{    
//	int a = 10000;  
//	FILE* pf = fopen("test.txt", "wb");  
//	fwrite(&a, 4, 1, pf);//二进制的形式写到文件中  
//	fclose(pf);   
//	pf = NULL;    
//	return 0;
//} 



//struct _iobuf 
//{ 
//	char *_ptr; 
//	int   _cnt;       
//	char *_base;    
//	int   _flag;      
//	int   _file;      
//	int   _charbuf;    
//	int   _bufsiz;    
//	char *_tmpfname;
//}; 
//typedef struct _iobuf FILE;
//#include<string.h>
//#include<errno.h>
//int main()
//{
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//	}
//	//打开成功
//	//读文件
//	//关闭文件
//	fclose(pf);
//	return 0;
//}

//

//#include<string.h>
//#include<errno.h>
//int main()
//{
//	FILE* pfRead = fopen("test.txt", "r");
//	if (pfRead == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//	//读文件
//	printf("%c", fgetc(pfRead));
//	printf("%c", fgetc(pfRead));
//	printf("%c", fgetc(pfRead));
//	
//	//关闭文件
//	fclose(pfRead);
//	pfRead = NULL;
//	return 0;
//}

//键盘&屏幕都是外部设备
//键盘--标准输入设备
//屏幕--标准输出设备
//是一个程序默认打开的两个流设备
//stdin
//stdout
//stderr

//int mian()
//{
//	char ch = fgetc(stdin);
//	fputc(ch, stdout);
//	return 0;
//}

//int main()
//{
//	char buf[1024] = { 0 };
//	FILE* pf = fopen("test.txt", "r");  // 文件里面放了bit\n   hello
//	if (pf == NULL)
//	{
//		return 0;
//	}
//	//读文件
//	fgets(buf, 1024, pf);
//	printf("%s", buf);   // bit  因为fgets会把里面的\n也拿过来，所以这里即使没有加\n也会换行
//	fgets(buf, 1024, pf);
//	printf("%s", buf);  // hello  这里没有加\n 所以结尾不会换行
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//int main()
//{
//	char buf[1024] = { 0 };
//	FILE* pf = fopen("test.txt", "w");  
//	if (pf == NULL)
//	{
//		return 0;
//	}
//	//写文件
//	fputs("hello", pf);  //你会发现输出的结果是helloworld没有进行换行，因为fputs是没有自己加入换行的，需要手动添加
//	fputs("world", pf);
//	
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//int main()
//{
//	char buf[1024] = { 0 };
//	fgets(buf, 1024, stdin);
//	fputs(buf, stdout);
//	return 0;
//}
//
////等价于
//int main()
//{
//	char buf[1024] = { 0 };
//	gets(buf);
//	puts(buf);
//	return 0;
//}


//struct S
//{
//	int n;
//	float score;
//	char arr[10];
//};
//int main()
//{
//	struct S s = { 100, 3.14f, "bit" };
//	FILE* pf = fopen("test.txt", "w");
//	if (pf == NULL)
//	{
//		return 0;
//	}
//	//格式化的形式写文件
//	fprintf(pf, "%d %f %s", s.n, s.score, s.arr);
//
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//struct S
//{
//	int n;
//	float score;
//	char arr[10];
//};
//int main()
//{
//	struct S s = {0};
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		return 0;
//	}
//	//格式化的输入数据
//	fscanf(pf,"%d %f %s", &(s.n), &(s.score), &(s.arr));
//	printf( "%d %f %s", s.n, s.score, s.arr);
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//struct S
//{
//	int n;
//	float score;
//	char arr[10];
//};
//int main()
//{
//	struct S s = { 0 };
//	
//	fscanf(stdin, "%d %f %s", &(s.n), &(s.score), &(s.arr));
//	fprintf(stdout,"%d %f %s", s.n, s.score, s.arr);
//	
//	return 0;
//}


//struct S
//{
//	int n;
//	float score;
//	char arr[10];
//};
//int main()
//{
//	struct S s = { 100,3.14f,"abcdef" };
//	char buf[1024] = { 0 };
//
//	sprintf(buf, "%d %f %s", s.n, s.score, s.arr);
//	printf("%s\n", buf);
//
//	return 0;
//}


//struct S
//{
//	int n;
//	float score;
//	char arr[10];
//};
//int main()
//{
//	struct S s = { 100, 3.14f, "abcdef" };
//	struct S tmp = { 0 };
//	char buf[1024] = { 0 };
//
//	sprintf(buf, "%d %f %s", s.n, s.score, s.arr); // 已经把结构体中格式化的数据转换成为了一个字符串
//	sscanf(buf, "%d %f %s", &(tmp.n), &(tmp.score), tmp.arr);
//	printf("%d %f %s", tmp.n, tmp.score, tmp.arr);
//
//	return 0;
//}


//fread
//struct S
//{
//	char name[20];
//	int age;
//	double score;
//};
//int main()
//{
//	struct S s = { "张三", 20, 55.6 };
//	FILE* pf = fopen("test.txt", "wb");
//	if (pf == NULL)
//	{
//		return 0;
//	}
//	//二进制形式写文件
//	fwrite(&s, sizeof(struct S), 1, pf);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//struct S
//{
//	char name[20];
//	int age;
//	double score;
//};
//int main()
//{
//	struct S tmp = { 0 };
//	FILE* pf = fopen("test.txt", "rb");
//	if (pf == NULL)
//	{
//		return 0;
//	}
//	//二进制形式读文件
//	fread(&tmp,sizeof(struct S),1,pf);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}



 //fseek         pf          偏移量      起始位置
//int fseek(FILE* stream,long offset, int origin); 
//int main()
//{
//	FILE* pf = fopen("test.txt", "r"); // 文件里面放的是"abcdef"
//	if (pf == NULL)
//	{
//		return 0;
//	}
//	//1.定位文件指针
//	fseek(pf, -2, SEEK_END); // 打印'e'
//	int pos = ftell(pf); // 相对于起始位置的偏移量，对于ftell的返回值是一个 long int 
//	printf("%d\n", pos); // 结果是4
//	
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//int main()
//{
//	FILE* pf = fopen("test.txt", "r"); 
//	if (pf == NULL)
//	{
//		return 0;
//	}
//	int ch = fgetc(pf);
//	printf("%c\n", ch);
//	rewind(pf);  //可以让文件指针回到起始的位置
//	ch = fgetc(pf);
//	printf("%c\n", ch);
//	//所以结果打印的是两个一样的字符
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


int main()
{
	feof();//EOF -- end of file -- 文件结束标志
	return 0;
}

