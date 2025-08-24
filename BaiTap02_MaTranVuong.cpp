/*Headerfile
Họ và tên: LÊ THỊ NHƯ QUỲNH
Lớp		 : Sang T3 - KTLT
*/
//========================================================
//Phần khai báo thư viện
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <cmath>
//========================================================
//Phần khai dữ liệu
typedef int Itemtype;
typedef Itemtype *ArrayPtr;
//========================================================
//Phần khai báo các nguyên mẫu hàm
void nhapSoNguyenDuong(int &n);
void InitArrayPtr(ArrayPtr *&a, int &n);
void DeleteArrayPtr(ArrayPtr *&a, int &n);
void nhapMaTran_SoNguyen(ArrayPtr *&a, int &n);
void taoMaTran_SoNguyen(ArrayPtr *&a, int &n);
void loadMaTran_SoNguyen(ArrayPtr *&a, int &n, char *fNameIn);
void xuatMaTran_SoNguyen(ArrayPtr *a, int n);

void swap(Itemtype &x, Itemtype &y);
void xuatPT_DCC(ArrayPtr *a, int n);//Xuất các phần tử trên đường chéo chính
void xuatPT_DuongCheoSSVoiDCC(ArrayPtr *a, int n);//Xuất các phần tử trên đường chéo song song với đường chéo chính
Itemtype timPTMax_TamGiacTrenDCC(ArrayPtr *a, int n);//Tìm phần tử max thuộc tam giác trên của đường chéo chính
void Copy_MaTran_To_Mang1C(ArrayPtr *a, int n, Itemtype *&b, int &sopt);
void Copy_Mang1C_To_MaTran(Itemtype *b, int sopt, ArrayPtr *&a, int &n);
void sapXepMaTranTangDan_ZicZac(ArrayPtr *&a, int n);//Sắp xếp ma trận tăng dần theo kiểu ziczac (tăng từ trái qua phải và từ trên xuống dưới)
void sapXepDCCTangDan_TrenXuongDuoi(ArrayPtr *&a, int n);//Sắp xếp đường chéo chính tăng dần từ trên xuống dưới
void sapXepDCPTangDan_TrenXuongDuoi(ArrayPtr *&a, int n);//Sắp xếp đường chéo phụ tăng dần từ trên xuống dưới
void sapXepMang1cTangDan_InterchangeSort(Itemtype *a, int n);
void sapXepMang1cGiamDan_InterchangeSort(Itemtype *a, int n);
void sapXepDongLeTang_DongChanGiam(ArrayPtr *&a, int n);//Sắp xếp ma trận sao cho các dòng có chỉ số lẻ thì tăng dần, các dòng có chỉ số chẵn thì giảm dần
void chuyenChanLe(Itemtype *&a, int n);//Chuyển số chẵn lên đầu mảng, chuyển số lẻ xuống cuối mảng
void sapXepPTChanDauMang_PTLeCuoiMang(ArrayPtr *&a, int n);//Sắp xếp ma trận sao cho các phần tử chẵn nằm ở các dòng đầu mảng, các phần tử lẻ nằm ở các dòng cuối mảng
int ktDoiXungQuaDCC(ArrayPtr *&a, int n);//Kiểm tra các phần tử trong ma trận có đối xứng qua đường chéo chính không

void showMenu();
void process();
//========================================================
//Phần khai chương trình chính
void main()
{
	process();
	return;
}
//-------------------------------------------------------
void showMenu()
{
	printf("\n*********************************************************************************");
	printf("\n*                    MENU                                                       *");
	printf("\n*********************************************************************************");
	printf("\n* 0.Thoat chuong trinh                                                          *");
	printf("\n* 1. Nhap ma tran vuong so nguyen (tu ban phim)                                 *");
	printf("\n* 2. Tao ma tran vuong so nguyen (ngau nhien)                                   *");
	printf("\n* 3. Load ma tran vuong so nguyen (tu file text)                                *");
	printf("\n* 4. Xem noi dung cua ma tran vuong                                             *");
	printf("\n* 5. Xuat cac phan tu tren duong cheo chinh                                     *");
	printf("\n* 6. Xuat cac phan tu tren duong cheo song song voi duong cheo chinh            *");
	printf("\n* 7. Tim phan tu max thuoc tam giac tren cua duong cheo chinh                   *");
	printf("\n* 8. Sap xep ma tran tang dan ZicZac (tang trai qua phai, tren xuong duoi)      *");
	printf("\n* 9. Sap xep duong cheo chinh tang dan tu tren xuong duoi                       *");
	printf("\n* 10. Sap xep duong cheo phu tang dan tu tren xuong duoi                        *");
	printf("\n* 11. Sap xep ma tran: dong co chi so le tang, dong co chi so chan giam         *");
	printf("\n* 12. Sap xep ma tran: cac phan tu chan nam dau mang, cac phan tu le cuoi mang  *");
	printf("\n* 13. Kiem tra cac phan tu trong ma tran co doi xung qua duong cheo chinh khong *");
	printf("\n*********************************************************************************");
}
//-------------------------------------------------------
void process()
{
	char FileName[] = "MaTran_SoNguyen.txt";
	ArrayPtr *A = NULL;
	int N, kq;
	int luaChon;
	do
	{
		showMenu();
		printf("\nBan hay lua chon mot chuc nang: ");
		nhapSoNguyenDuong(luaChon);

		switch (luaChon)
		{
		case 1:
			nhapMaTran_SoNguyen(A, N);
			printf("NOI DUNG MANG VUA NHAP TU BAN PHIM LA: \n");
			xuatMaTran_SoNguyen(A, N);
			break;
		case 2:
			taoMaTran_SoNguyen(A, N);
			printf("NOI DUNG MANG VUA TAO NGAU NHIEN LA: \n");
			xuatMaTran_SoNguyen(A, N);
			break;
		case 3:
			loadMaTran_SoNguyen(A, N, FileName);
			printf("NOI DUNG MANG VUA LOAD TU FILE TEXT LA: \n");
			xuatMaTran_SoNguyen(A, N);
			break;
		case 4:
			printf("NOI DUNG CUA MANG LA: \n");
			xuatMaTran_SoNguyen(A, N);
			break;
		case 5:
			xuatPT_DCC(A, N);
			break;
		case 6:
			xuatPT_DuongCheoSSVoiDCC(A, N);
			break;
		case 7:
			kq = timPTMax_TamGiacTrenDCC(A, N);
			printf("Phan tu max thuoc tam giac tren cua duong cheo chinh: %d", kq);
			break;
		case 8:
			printf("NOI DUNG MA TRAN SAU KHI SAP XEP ZICZAC TANG DAN TU TRAI QUA PHAI, TU TREN XUONG DUOI: \n");
			sapXepMaTranTangDan_ZicZac(A, N);
			xuatMaTran_SoNguyen(A, N);
			break;
		case 9:
			printf("NOI DUNG MA TRAN SAU KHI SAP XEP DUONG CHEO CHINH TANG DAN: \n");
			sapXepDCCTangDan_TrenXuongDuoi(A, N);
			xuatMaTran_SoNguyen(A, N);
			break;
		case 10:
			printf("NOI DUNG MA TRAN SAU KHI SAP XEP DUONG CHEO PHU TANG DAN: \n");
			sapXepDCPTangDan_TrenXuongDuoi(A, N);
			xuatMaTran_SoNguyen(A, N);
			break;
		case 11:
			printf("NOI DUNG MA TRAN SAU KHI SAP XEP DONG CO CHI SO LE TANG, DONG CO CHI SO CHAN GIAM: \n");
			sapXepDongLeTang_DongChanGiam(A, N);
			xuatMaTran_SoNguyen(A, N);
			break;
		case 12:
			printf("NOI DUNG MA TRAN SAU KHI SAP XEP CAC PHAN TU CHAN NAM DAU MANG, CAC PHAN TU LE NAM CUOI MANG: \n");
			sapXepPTChanDauMang_PTLeCuoiMang(A, N);
			xuatMaTran_SoNguyen(A, N);
			break;
		case 13: 
			kq = ktDoiXungQuaDCC(A, N);
			if (kq == 0)
				printf("Cac phan tu trong ma tran khong doi xung qua duong cheo chinh!");
			else
				printf("Cac phan tu trong ma tran doi xung qua duong cheo chinh");
			break;
		}

	} while (luaChon != 0);
	DeleteArrayPtr(A, N);
}
//========================================================
//Phần định nghĩa các hàm
void nhapSoNguyenDuong(int &n)
{
	do
	{
		scanf("%d", &n);
		if (n < 0)
		{
			printf("Sai roi! Nhap lai!");
		}
	} while (n < 0);
}
//-------------------------------------------------------
void InitArrayPtr(ArrayPtr *&a, int &n)
{
	a = new ArrayPtr[n*sizeof(Itemtype)];//Cấp phát 1 mảng m con trỏ mảng 1 chiều
	for (int i = 0; i < n; i++)
	{
		*(a + i) = new Itemtype[n*sizeof(Itemtype)]; //Cấp phát 1 dòng
	}
}
//-------------------------------------------------------
void DeleteArrayPtr(ArrayPtr *&a, int &n)
{
	for (int i = 0; i < n; i++)
	{
		delete *(a + i); //Thu hồi
	}
}
//-------------------------------------------------------
void nhapMaTran_SoNguyen(ArrayPtr *&a, int &n)
{
	printf("Ban hay cho biet so dong va cot cua ma tran vuong (n>=5): ");
	nhapSoNguyenDuong(n);
	InitArrayPtr(a, n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			Itemtype tmp;
			printf("a[%d][%d] = ", i, j);
			scanf("%d", &tmp);
			a[i][j] = tmp;
		}
	}
}
//-------------------------------------------------------
void taoMaTran_SoNguyen(ArrayPtr *&a, int &n)
{
	printf("Ban hay cho biet so dong va cot cua ma tran vuong (n>=5): ");
	nhapSoNguyenDuong(n);
	InitArrayPtr(a, n);

	srand((unsigned)time(NULL));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			Itemtype tmp;
			int x = -99, y = 99;
			tmp = rand() % (y - x + 1) + x;
			a[i][j] = tmp;
		}
	}
}
//-------------------------------------------------------
void loadMaTran_SoNguyen(ArrayPtr *&a, int &n, char *fNameIn)
{
	FILE *fi = fopen(fNameIn, "rt"); //read text
	if (fi == NULL)
	{
		printf("Loi mo file de doc du lieu");
		getch();
		return;
	}
	fscanf(fi, "%d\n", &n);
	InitArrayPtr(a, n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			Itemtype tmp;
			fscanf(fi, "%d", &tmp);
			a[i][j] = tmp;
		}
	}
	fclose(fi);
}
//-------------------------------------------------------
void xuatMaTran_SoNguyen(ArrayPtr *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%4d ", a[i][j]);
		}
		printf("\n\n");
	}
}
//-------------------------------------------------------
void swap(Itemtype &x, Itemtype &y)
{
	Itemtype tmp;
	tmp = x;
	x = y;
	y = tmp;
}
//-------------------------------------------------------
void xuatPT_DCC(ArrayPtr *a, int n)
{//Xuất các phần tử trên đường chéo chính
	printf("Cac phan tu den duong cheo chinh: ");
	for (int i = 0; i < n; i++)
		printf("%4d", a[i][i]);
}
//-------------------------------------------------------
void xuatPT_DuongCheoSSVoiDCC(ArrayPtr *a, int n)
{//Xuất các phần tử trên đường chéo song song với đường chéo chính
	printf("Cac phan tu thuoc duong cheo song song voi duong cheo chinh: ");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i != j)
				printf("%4d", a[i][j]);
		}
	}
}
//-------------------------------------------------------
Itemtype timPTMax_TamGiacTrenDCC(ArrayPtr *a, int n)
{//Tìm phần tử max thuộc tam giác trên của đường chéo chính
	Itemtype max = a[0][1];
	for (int i = 0; i < n; i++)
	{
		for (int j = i+1 ; j < n; j++)
		{
			if (a[i][j]>max)
			{
				max = a[i][j];
			}
		}
	}
	return max;
}
//-------------------------------------------------------
void Copy_MaTran_To_Mang1C(ArrayPtr *a, int n, Itemtype *&b, int &sopt)
{
	sopt = 0;
	b = new Itemtype[n*n];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			b[sopt++] = a[i][j];
		}
	}
}
//-------------------------------------------------------
void Copy_Mang1C_To_MaTran(Itemtype *b, int sopt, ArrayPtr *&a, int &n)
{
	sopt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[i][j] = b[sopt++];
		}
	}
}
//-------------------------------------------------------
void sapXepMaTranTangDan_ZicZac(ArrayPtr *&a, int n)
{//Sắp xếp ma trận tăng dần theo kiểu ziczac (tăng từ trái qua phải và từ trên xuống dưới)
	Itemtype *b = NULL;
	int sopt;
	Copy_MaTran_To_Mang1C(a, n, b, sopt);
	sapXepMang1cTangDan_InterchangeSort(b, sopt);
	Copy_Mang1C_To_MaTran(b, sopt, a, n);
}
//-------------------------------------------------------
void sapXepDCCTangDan_TrenXuongDuoi(ArrayPtr *&a, int n)
{//Sắp xếp đường chéo chính tăng dần từ trên xuống dưới
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i][i] > a[j][j])
				swap(a[i][i], a[j][j]);
		}
	}
}
//-------------------------------------------------------
void sapXepDCPTangDan_TrenXuongDuoi(ArrayPtr *&a, int n)
{//Sắp xếp đường chéo phụ tăng dần từ trên xuống dưới
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i][n - i - 1] > a[j][n - j - 1])
				swap(a[i][n - i - 1], a[j][n - j - 1]);
		}
	}
}
//-------------------------------------------------------
void sapXepMang1cTangDan_InterchangeSort(Itemtype *a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] > a[j])
				swap(a[i], a[j]);
		}
	}
}
//-------------------------------------------------------
void sapXepMang1cGiamDan_InterchangeSort(Itemtype *a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] < a[j])
				swap(a[i], a[j]);
		}
	}
}
//-------------------------------------------------------
void sapXepDongLeTang_DongChanGiam(ArrayPtr *&a, int n)
{//Sắp xếp ma trận sao cho các dòng có chỉ số lẻ thì tăng dần, các dòng có chỉ số chẵn thì giảm dần
	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0)
		{
			sapXepMang1cGiamDan_InterchangeSort(a[i], n);
		}
		else
		{
			sapXepMang1cTangDan_InterchangeSort(a[i], n);
		}
	}
}
//-------------------------------------------------------
void chuyenChanLe(Itemtype *&a, int n)
{//Chuyển số chẵn lên đầu mảng, chuyển số lẻ xuống cuối mảng
	int i = 0, j = n - 1;
	while (i <= j)
	{
		while (a[i] % 2 == 0)
			i++;
		while (a[j] % 2 != 0)
			j--;
		if (i < j)
			swap(a[i], a[j]);
		i++;
		j--;
	}
}
//-------------------------------------------------------
void sapXepPTChanDauMang_PTLeCuoiMang(ArrayPtr *&a, int n)
{//Sắp xếp ma trận sao cho các phần tử chẵn nằm ở các dòng đầu mảng, các phần tử lẻ nằm ở các dòng cuối mảng
	Itemtype *b = NULL;
	int sopt;
	Copy_MaTran_To_Mang1C(a, n, b, sopt);
	chuyenChanLe(b, sopt);
	Copy_Mang1C_To_MaTran(b, sopt, a, n);
}
//-------------------------------------------------------
int ktDoiXungQuaDCC(ArrayPtr *&a, int n)
{//Kiểm tra các phần tử trong ma trận có đối xứng qua đường chéo chính không
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] != a[j][i])
				return 0;
		}
	}
	return 1;
}


