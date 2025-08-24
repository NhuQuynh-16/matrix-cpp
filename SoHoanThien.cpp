#include <stdio.h>
#include <conio.h>
#define MAXCOL 200

int ktSoHT(int n)
{
	int sum = 0;
	for (int i = 1; i <= n / 2; i++)
	{
		if (n%i == 0)
			sum += i;
	}
	if (sum == n && n!=0)
		return 1;
	return 0;
}

int demSoHTCuaTungDongK(int a[][MAXCOL], int m, int n, int k)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (ktSoHT(a[k][i]) == 1)
			count++;
	}
	return count;
}

void lietKeMangChuaDongCoNhieuSHTNhat(int a[][MAXCOL], int m, int n)
{ 
	int *MA=NULL;
	MA = new int[m];
	int dem=0;
	int count = demSoHTCuaTungDongK(a, m, n, 0);

	for (int i = 1; i < m; i++)
	{
		int count1 = demSoHTCuaTungDongK(a, m, n, i);
		if (count1 >count)
		{
			dem = 0;
			MA[dem] = i;
			count = count1;
		}
		else if ((count1 == count) && (count !=0))
		{
			MA[++dem] = i;
		}
	}
	if (count == 0)
	{
		printf("Khong co dong nao co so hoan thien!");
	}
	else
	{
		for (int i = 0; i <= dem; i++)
			printf("%d, ", MA[i]);
		printf("la dong co nhieu so hoan thien nhat");
	}
		
}

void loadMang2c_SoNguyen(int a[][MAXCOL], int &m, int &n, char *fNameIn)
{
	FILE *fi = fopen(fNameIn, "rt"); //read text
	if (fi == NULL)
	{
		printf("Loi mo file de doc du lieu");
		getch();
		return;
	}
	fscanf(fi, "%d\n", &m);
	fscanf(fi, "%d\n", &n);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{ 
			fscanf(fi, "%d", &a[i][j]);
		}
	}
	fclose(fi);
}
void xuatMang2c_SoNguyen(int a[][MAXCOL], int m ,int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}
}
void main()
{
	char FileName[] = "Ma tran SHT.txt";
	int A[100][MAXCOL]; int M, N;

	loadMang2c_SoNguyen(A, M, N, FileName);
	printf("NOI DUNG CUA MANG LOAD TU FILE TEXT\n");
	xuatMang2c_SoNguyen(A, M, N);
	lietKeMangChuaDongCoNhieuSHTNhat(A, M, N);
	getch();
	return;
}