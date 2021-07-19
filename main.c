#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

void printb(unsigned int v) {
  unsigned int mask = (int)1 << (sizeof(v) * CHAR_BIT - 1);
  do putchar(mask & v ? '1' : '0');
  while (mask >>= 1);
}

void putb(unsigned int v) {
  putchar('0'), putchar('b'), printb(v), putchar('\n');
}
int main()
{
	int len = 0;
	char a = 'a';
	char b = 'b';
	char s[] = "sentence";
	int i = -123456;
	int zero = 0;
	unsigned int x = 268435455;
	unsigned int u_i = 123;
	int	i_123 = 123;
	long long_i = 1 << 31;//32bitの一番左が1
	long test_i = 1111111111111111111;
	int i_16 = 0x1e240;//16進数
	int i_8 = 0173;//123(10)


	printf("---[%%c]のテスト---\n");
	printf("本家と自作を交互で表示\n");
	len = printf("[%%c] = [%c]\n",a);
	printf("len = [%d]\n",len);
	len = 0;
	len =ft_printf("[%%c] = [%c]\n\n",a);
	printf("len = [%d]\n",len);
	
	printf("[%%c] = [%c]\n",b);
	ft_printf("[%%c] = [%c]\n",b);
	printf("\n---[%%s]のテスト---\n");
	printf("[%%s] = [%s]\n",s);
	ft_printf("[%%s] = [%s]\n",s);
	printf("\n---[%%p]のテスト---\n");
	printf("[%%p] = [%p]\n",&a);
	ft_printf("[%%p] = [%p]\n\n",&a);
	printf("[%%p] = [%p]\n",&b);
	ft_printf("[%%p] = [%p]\n\n",&b);
	printf("\n---[%%d][%%i]のテスト---\n");
	printf("[%%d][%%i] = [%d][%i]\n",i,i);
	ft_printf("[%%d][%%i] = [%d][%i]\n",i,i);
	printf("引数がunsigned int型の時\n");
	
	printf("[%%d][%%i] = [%d][%i]\n",u_i,u_i);
	ft_printf("[%%d][%%i] = [%d][%i]\n",u_i,u_i);

	printf("引数がlong型の時で32bitの一番左が1の時の出力\n");
	printf("10進数では[2147483648]なるが、本家では-がつく\n");
	printf("これは、オーバーフローしているから、もしva_argの第二引数がunsigned intにしてしまうと、オーバーフローせずにプラスのまま出力してしまう。\n");
	printf("[%%d][%%i] = [%d][%i]\n",UINT_MAX,UINT_MAX);
	ft_printf("[%%d][%%i] = [%d][%i]\n",UINT_MAX,UINT_MAX);
	
	printf("\n---[%%u]のテスト---\n");
	printf("[%%u]は引数をunsigned intだから、UINT_MAXをそのまま出力できる\n");
	printf("[%%u] = [%u]\n",UINT_MAX);
	ft_printf("[%%u] = [%u]\n",UINT_MAX);

	printf("2進数がオーバーフローの理解に大事\n");
	printf("INT_MAXの２進数");
	putb(INT_MAX);
	printf("UINT_MAXの２進数");
	putb(UINT_MAX);
	printf("int型の変数[123]を２進数で出力\n");
	putb(i_123);
	printf("unsigned int型の変数[123]を２進数で出力\n");
	putb(u_i);
	putb(-1);
	printf("8進数を変換\n");
	printf("i_8は8進数で[%o]\n",i_8);
	printf("[%%u] = [%u]\n",i_8);
	ft_printf("[%%u] = [%u]\n",i_8);
	printf("16進数を変換\n");
	printf("i_16は16進数で[%x]\n",i_16);
	printf("[%%u] = [%u]\n",i_16);
	ft_printf("[%%u] = [%u]\n",i_16);

	printf("\n\n---[%%x]のテスト---\n");
	printf("10進数i=123を16進数で表示すると\n");
	printf("[%%x]は引数unsigned intで[%x]\n",i);
	ft_printf("[%%x]は引数unsigned intで[%x]\n",i);

	printf("[%%X]でアルファメットを大文字にする[%X]\n",i);
	ft_printf("[%%X]でアルファメットを大文字にする[%X]\n",i);

	printf("\n---[%%p]のテスト---\n");
	printf("ポインタ変数のアドレス値を16進数で表示\n");
	printf("[%%p] = [%p]\n",&a);
	ft_printf("[%%p] = [%p]\n",&a);

	printf("\n--[%%]のテスト---\n");
	printf("[%%]\n");
	ft_printf("[%%]\n");

	printf("---ft_printfの返り値をテスト---\n");
	len = printf("日本語はマルチバイト文字[%d],[%c],[%s],[%u],[%p]\n",i,a,s,i_16,&a);
	printf("%d\n",len);
	len = 0;
	len = ft_printf("日本語はマルチバイト文字[%d],[%c],[%s],[%u],[%p]\n",i,a,s,i_16,&a);
	printf("%d\n",len);
	// 以下で、２文字違う
	len =    printf("日本語はマルチバイト文字[%d][%c][%s][%u][%x][%X][%p][%%]",i,a,s,i_16,x,x,&a);//i=123456,a='a',s[]='sentence'
	printf("\n%d\n",len);
	len = ft_printf("日本語はマルチバイト文字[%d][%c][%s][%u][%x][%X][%p][%%]",i,a,s,i_16,x,x,&a);//x =1048575 i_16=0x1e240(123456) %dがないと38/%dがあると40になる。//[%d]だけで85になってる。消すと36で本家と同じ
	printf("\n%d\n",len);

	// ft_printf("%12d\n",zero);
	// printf("---------NULL対応-----\n");
	// printf("%p\n",NULL);
	// ft_printf("%p\n",NULL);
	// printf("%c\n",256);
	// ft_printf("%c\n",'\0');
	// printf("%s\n",NULL);
	// ft_printf("%s",NULL);

	// printf("---最大値の比較---\n");
	// printf("int-[%%d]=[%d] unsigned int-[%%d]= [%d] unsigned int-[%%u]=[%u]\n",INT_MAX,UINT_MAX,UINT_MAX);
	// ft_printf("int-[%%d]=[%d] unsigned int-[%%d]= [%d] unsigned int-[%%u]=[%u]\n",INT_MAX,UINT_MAX,UINT_MAX);

	// printf("int-[%%x]=[%x] unsigned int-[%%x]= [%x] unsigned int-[%%p]=[%p]\n",INT_MAX,UINT_MAX,UINT_MAX);
	// ft_printf("int-[%%x]=[%x] unsigned int-[%%x]= [%x] unsigned int-[%%p]=[%p]\n",INT_MAX,UINT_MAX,UINT_MAX);
	// // printf()/
	// printf("---char型とunsigned char型の違い---\n");
	// printf("[%%c]はint型をunsigned char型に変換して出力\n");
	// printf("この時の違いは-127~127 と 0~255の違い\n");
	// printf("100[%%c]=[%c],  130[%%c]=[%c] 255[%%c]=[%c]\n",100,130,254);
	// ft_printf("100[%%c]=[%c],  130[%%c]=[%c] 255[%%c]=[%c]\n",100,130,254);

	// printf("--duplicate conversion--\n");
	// printf("%d\n",i,i);
	// ft_printf("%d\n",i,i);

	printf("---INT_MIN---\n");
	printf("%d\n",INT_MIN);
	ft_printf("%d\n",INT_MIN);
	printf("%d\n",NULL);
	ft_printf("%d\n",NULL);

	// printf("--NULL(ポインタ)がchar型だとどうなるかを検証---\n");
	// len = printf("abc%s",NULL);
	// printf("\n--(null)の返り値[%d]\n",len);

	printf("---NULL対応---\n");
	printf("[%%d] = [%d]\n",NULL);
	ft_printf("[%%d] = [%d]\n\n",NULL);

	printf("[%%c] = [%c]\n",NULL);
	ft_printf("[%%c] = [%c]\n\n",NULL);

	len = printf("[%%s] = [%s]\n",NULL);
	printf("[%d]\n",len);
	len = ft_printf("[%%s] = [%s]\n",NULL);
	printf("[%d]\n",len);
	
	printf("[%%u] = [%u]\n",NULL);
	ft_printf("[%%u] = [%u]\n",NULL);

	printf("[%%x] = [%x]\n",NULL);
	ft_printf("[%%x] = [%x]\n\n",NULL);
	
	printf("---リーク確認---\n");
	// system("leaks a.out");
	return (0);
}
