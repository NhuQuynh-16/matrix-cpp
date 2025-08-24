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
struct TanSuat
{
	int n;//Giá trị 
	int m;//Tần suất xuất hiện của giá trị n
};
typedef int Itemtype;
typedef Itemtype *ArrayPtr;
//========================================================
//Phần khai báo các nguyên mẫu hàm
void nhapSoNguyenDuong(int &n);
void InitArrayPtr(ArrayPtr *&a, int &m, int &n);
void DeleteArrayPtr(ArrayPtr *&a, int &m, int &n);
void nhapMaTran_SoNguyen(ArrayPtr *&a, int &m, int &n);
void taoMaTran_SoNguyen(ArrayPtr *&a, int &m, int &n);
void loadMaTran_SoNguyen(ArrayPtr *&a, int &m, int &n, char *fNameIn);
void xuatMaTran_SoNguyen(ArrayPtr *a, int m, int n);

void swap(Itemtype &x, Itemtype &y);
void sapXepMaTran_TangDan(ArrayPtr *a, int m, int n);
Itemtype GTNN_Dongk(ArrayPtr *a, int m, int n, int k);
Itemtype GTLN_Dongk(ArrayPtr *a, int m, int n, int k);
Itemtype GTLN_Cotk(ArrayPtr *a, int m, int n, int k);
Itemtype GTNN_Cotk(ArrayPtr *a, int m, int n, int k);
void timDiemYenNgua(ArrayPtr *a, int m, int n);
void xuatTongGiaTriTungDong(ArrayPtr *a, int m, int n);//Tính và xuất tổng giá trị từng dòng
void xuatPhanTuDuongBien(ArrayPtr *a, int m, int n);//Xuất các phần tử thuộc các đường biên trên, dưới, trái, phải
int ktCucDai(ArrayPtr *a, int m, int n, int i, int j);
void xuatPTCucDai(ArrayPtr *a, int m, int n);//Xuất các phần tử cực đại
int ktCucTieu(ArrayPtr *a, int m, int n, int i, int j);
void xuatPTCucTieu(ArrayPtr *a, int m, int n);//Xuất các phần tử cực tiểu
int ktCotKChuaSoLe(ArrayPtr *a, int m, int n, int k);
void xuatCotChuaSoLe(ArrayPtr *a, int m, int n);//Xuất các cột chứa toàn số lẻ
Itemtype timPTMAxTrenBien(ArrayPtr *a, int m, int n);//Tìm phần tử lớn nhất trong các phần tử trên biên của ma trận
void sapXepMang1cTangDan_InterchangeSort(Itemtype *a, int n);
void sapXepMang1cGiamDan_InterchangeSort(Itemtype *a, int n);
void sapXep_DongLeTang_DongChanGiam(ArrayPtr *a, int m, int n);//Sắp xếp các dòng có chỉ số lẻ thì tăng dần, các dòng có chỉ số chẵn thì giảm dần
int ktrDongKCoGiaTriGiamDan(ArrayPtr *a, int m, int n, int k);
void lietKeDongCoGiaTriGiamDan(ArrayPtr *a, int m, int n);//Liệt kê các dòng chứa giá trị giảm dần
Itemtype timGiaTriXuatHienNhieuNhat(ArrayPtr *a, int m, int n);//Tìm giá trị xuất hiện nhiều nhất trong ma trận
void hoanVi2DongK_L(ArrayPtr *&a, int m, int n, int k, int l);//Hoán vị 2 dòng k và l trong ma trận
void hoanVi2CotI_J(ArrayPtr *&a, int m, int n, int i, int j);//Hoán vị 2 cột i và j trong ma trận
void lietKeCacCotCoTongNhoNhat(ArrayPtr *a, int m, int n);//Liệt kê các cột có tổng nhỏ nhất trong ma trận

int KiemTraDuongCheo(ArrayPtr *&a, int m, int n, int i, int j);
int KiemTraDongCot(ArrayPtr *&a, int m, int n, int i, int j);
int KiemTraHoangHau(ArrayPtr *&a, int m, int n, int i, int j);
void LietKe_All_HoangHau(ArrayPtr *a, int m, int n);//Liệt kê tất cả các phần tử Hoàng hậu trong ma trận

void Copy_MaTran_To_Mang1C(ArrayPtr *a, int m, int n, Itemtype *&b, int &sopt);
void Tao_MaTran_ZicZag(ArrayPtr *&a, int m, int n, Itemtype *b, int sopt);
void TangDong_TraiSangPhai(ArrayPtr *a, int &h1, int h2, int c1, int c2, Itemtype *b, int &count);
void TangDong_PhaiSangTrai(ArrayPtr *a, int h1, int &h2, int c1, int c2, Itemtype *b, int &count);
void TangCot_TrenXuongDuoi(ArrayPtr *a, int h1, int h2, int c1, int &c2, Itemtype *b, int &count);
void TangCot_DuoiLenTren(ArrayPtr *a, int h1, int h2, int &c1, int c2, Itemtype *b, int &count);
void Tao_MaTran_XoanOc(ArrayPtr *&a, int m, int n, Itemtype *b, int sopt);

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
	printf("\n**************************************************************");
	printf("\n*                           MENU                             *");
	printf("\n**************************************************************");
	printf("\n* 0.Thoat chuong trinh                                       *");
	printf("\n* 1. Nhap ma tran so nguyen (tu ban phim)                    *");
	printf("\n* 2. Tao ma tran so nguyen (ngau nhien)                      *");
	printf("\n* 3. Load ma tran so nguyen (tu file text)                   *");
	printf("\n* 4. Xem noi dung cua ma tran                                *");
	printf("\n* 5. Sap xep ma tran tang dan (Interchange Sort)             *");
	printf("\n* 6. Tim phan tu Yen Ngua                                    *");
	printf("\n* 7. Xuat tong gia tri tung dong                             *");
	printf("\n* 8. Xuat cac phan tu thuoc cac duong bien                   *");
	printf("\n* 9. Xuat cac phan tu cuc dai                                *");
	printf("\n* 10. Xuat cac phan tu cuc tieu                              *");
	printf("\n* 11. Xuat cac cot chua toan so le                           *");
	printf("\n* 12. Xuat phan tu lon nhat trong cac phan tu tren bien      *");
	printf("\n* 13. Sap xep dong co chi so le tang, chi so chan giam       *");
	printf("\n* 14. Liet ke cac dong chua gia tri giam dan                 *");
	printf("\n* 15. Tim gia tri xuat hien nhieu nhat trong ma tran         *");
	printf("\n* 16. Hoan vi 2 dong k va l trong ma tran                    *");
	printf("\n* 17. Hoan vi 2 cot i va j trong ma tran                     *");
	printf("\n* 18. Liet ke cac cot co tong nho nhat trong ma tran         *");
	printf("\n* 19. Liet ke cac phan tu hoang hau trong ma tran            *");
	printf("\n* 20. Tao ma tran ZicZag                                     *");
	printf("\n* 21. Tao ma tran xoan oc                                    *");
	printf("\n**************************************************************");
}
//-------------------------------------------------------
void process()
{
	char FileName[] = "MaTran_SoNguyen.txt";
	ArrayPtr *A = NULL, *B = NULL, *C = NULL;
	Itemtype *Ma = NULL;
	int M, N, kq, k, l, SoPT;
	int luaChon;
	do
	{
		showMenu();
		printf("\nBan hay lua chon mot chuc nang: ");
		nhapSoNguyenDuong(luaChon);

		switch (luaChon)
		{
		case 1:
			nhapMaTran_SoNguyen(A, M, N);
			printf("NOI DUNG MANG VUA NHAP TU BAN PHIM LA: \n");
			xuatMaTran_SoNguyen(A, M, N);
			break;
		case 2:
			taoMaTran_SoNguyen(A, M, N);
			printf("NOI DUNG MANG VUA TAO NGAU NHIEN LA: \n");
			xuatMaTran_SoNguyen(A, M, N);
			break;
		case 3:
			loadMaTran_SoNguyen(A, M, N, FileName);
			printf("NOI DUNG MANG VUA LOAD TU FILE TEXT LA: \n");
			xuatMaTran_SoNguyen(A, M, N);
			break;
		case 4:
			printf("NOI DUNG CUA MANG LA: \n");
			xuatMaTran_SoNguyen(A, M, N);
			break;
		case 5:
			sapXepMaTran_TangDan(A, M, N);
			printf("\nMA TRAN SAP XEP TANG DAN (TRAI SANG PHAI, TREN XUONG DUOI) LA: \n");
			xuatMaTran_SoNguyen(A, M, N);
			break;
		case 6:
			timDiemYenNgua(A, M, N);
			break;
		case 7:
			xuatTongGiaTriTungDong(A, M, N);
			break;
		case 8:
			xuatPhanTuDuongBien(A, M, N);
			break;
		case 9: 
			xuatPTCucDai(A, M, N);
			break;
		case 10:
			xuatPTCucTieu(A, M, N);
			break;
		case 11: 
			xuatCotChuaSoLe(A, M, N);
			break;
		case 12:
			kq = timPTMAxTrenBien(A, M, N);
			printf("Phan tu lon nhat trong cac phan tu tren bien cua ma tran: %d",kq);
			break;
		case 13:
			printf("Ma tran sau khi sap xep dong co chi so le tang, chi so chan giam: \n");
			sapXep_DongLeTang_DongChanGiam(A, M, N);
			xuatMaTran_SoNguyen(A, M, N);
			break;
		case 14: 
			lietKeDongCoGiaTriGiamDan(A, M, N);
			break;
		case 15:
			kq = timGiaTriXuatHienNhieuNhat(A, M, N);
			if (kq == -1)
				printf("Cac gia tri co so lan xuat hien bang nhau trong ma tran");
			else
				printf("Gia tri xuat hien nhieu nhat trong ma tran la: %d", kq);
			break;
		case 16:
			printf("Nhap 2 dong k va l ban muon hoan vi: ");
			scanf("%d%d", &k, &l);
			printf("Ma tran sau khi hoan vi 2 dong %d va %d: \n", k, l);
			hoanVi2DongK_L(A, M, N, k, l);
			xuatMaTran_SoNguyen(A, M, N);
			break;
		case 17:
			printf("Nhap 2 cot i va j ban muon hoan vi: ");
			scanf("%d%d", &k, &l);
			printf("Ma tran sau khi hoan vi 2 cot %d va %d: \n", k, l);
			hoanVi2CotI_J(A, M, N, k, l);
			xuatMaTran_SoNguyen(A, M, N);
			break;
		case 18:
			lietKeCacCotCoTongNhoNhat(A, M, N);
			break;
		case 19:
			LietKe_All_HoangHau(A, M, N);
			break;
		case 20:
			Copy_MaTran_To_Mang1C(A, M, N, Ma, SoPT);
			sapXepMang1cTangDan_InterchangeSort(Ma, SoPT);
			Tao_MaTran_ZicZag(B, M, N, Ma, SoPT);
			printf("\nMA TRAN ZICZAG (TANG DAN): \n");
			xuatMaTran_SoNguyen(B, M, N);
			break;
		case 21:
			Copy_MaTran_To_Mang1C(A, M, N, Ma, SoPT);
			sapXepMang1cTangDan_InterchangeSort(Ma, SoPT);
			Tao_MaTran_XoanOc(C, M, N, Ma, SoPT);
			printf("\nMA TRAN XOAN OC TANG DAN (THEO CHIEU KIM DONG HO) LA: \n");
			xuatMaTran_SoNguyen(C, M, N);
			break;
		}

	} while (luaChon != 0);
	DeleteArrayPtr(A, M, N);
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
void InitArrayPtr(ArrayPtr *&a, int &m, int &n)
{
	a = new ArrayPtr[m*sizeof(Itemtype)];//Cấp phát 1 mảng m con trỏ mảng 1 chiều
	for (int i = 0; i < m; i++)
	{
		*(a + i) = new Itemtype[n*sizeof(Itemtype)]; //Cấp phát 1 dòng
	}
}
//-------------------------------------------------------
void DeleteArrayPtr(ArrayPtr *&a, int &m, int &n)
{
	for (int i = 0; i < m; i++)
	{
		delete *(a + i); //Thu hồi
	}
}
//-------------------------------------------------------
void nhapMaTran_SoNguyen(ArrayPtr *&a, int &m, int &n)
{
	printf("Ban hay cho biet so dong cua ma tran: ");
	nhapSoNguyenDuong(m);
	printf("Ban hay cho biet so cot cua ma tran: ");
	nhapSoNguyenDuong(n);
	InitArrayPtr(a, m, n);
	for (int i = 0; i < m; i++)
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
void taoMaTran_SoNguyen(ArrayPtr *&a, int &m, int &n)
{
	printf("Ban hay cho biet so dong cua ma tran: ");
	nhapSoNguyenDuong(m);
	printf("Ban hay cho biet so cot cua ma tran: ");
	nhapSoNguyenDuong(n);
	InitArrayPtr(a, m, n);

	srand((unsigned)time(NULL));
	for (int i = 0; i < m; i++)
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
void loadMaTran_SoNguyen(ArrayPtr *&a, int &m, int &n, char *fNameIn)
{
	FILE *fi = fopen(fNameIn, "rt"); //read text
	if (fi == NULL)
	{
		printf("Loi mo file de doc du lieu");
		getch();
		return;
	}
	fscanf(fi, "%d%d\n", &n, &m);
	InitArrayPtr(a, m, n);
	for (int i = 0; i < m; i++)
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
void xuatMaTran_SoNguyen(ArrayPtr *a, int m, int n)
{
	for (int i = 0; i < m; i++)
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
void sapXepMaTran_TangDan(ArrayPtr *a, int m, int n)
{
	int sopt = m*n;
	for (int i = 0; i < sopt - 1; i++)
	{
		for (int j = i + 1; j < sopt; j++)
		{
			if (a[i / n][i%n]>a[j / n][j%n])
				swap(a[i / n][i%n], a[j / n][j%n]);
		}
	}
}
//-------------------------------------------------------
Itemtype GTNN_Dongk(ArrayPtr *a, int m, int n, int k)
{
	Itemtype min = a[k][0];
	for (int j = 0; j < n; j++)
	{
		if (min >a[k][j])
			min = a[k][j];
	}
	return min;
}
//-------------------------------------------------------
Itemtype GTLN_Dongk(ArrayPtr *a, int m, int n, int k)
{
	Itemtype max = a[k][0];
	for (int j = 0; j < n; j++)
	{
		if (max < a[k][j])
			max = a[k][j];
	}
	return max;
}
//-------------------------------------------------------
Itemtype GTLN_Cotk(ArrayPtr *a, int m, int n, int k)
{
	Itemtype max = a[0][k];
	for (int i = 0; i < m; i++)
	{
		if (max < a[i][k])
			max = a[i][k];
	}
	return max;
}
//-------------------------------------------------------
Itemtype GTNN_Cotk(ArrayPtr *a, int m, int n, int k)
{
	Itemtype min = a[0][k];
	for (int i = 0; i < m; i++)
	{
		if (min > a[i][k])
			min = a[i][k];
	}
	return min;
}
//-------------------------------------------------------
void timDiemYenNgua(ArrayPtr *a, int m, int n)
{
	int dem = 0;
	printf("CAC PHAN TU YEN NGUA TRONG MA TRAN LA: ");
	for (int i = 0; i < m; i++)
	{
		int minD = GTNN_Dongk(a, m, n, i);
		int maxD = GTLN_Dongk(a, m, n, i);
		for (int j = 0; j < n; j++)
		{
			int minC = GTNN_Cotk(a, m, n, i);
			int maxC = GTLN_Cotk(a, m, n, i);
			if ((a[i][j] == minD && a[i][j] == maxC) || (a[i][j] == maxD && a[i][j] == minC))
			{
				dem++;
				printf("%4d", a[i][j]);
			}
		}
	}
	if (dem == 0)
		printf("Khong co phan tu yen ngua!");
}
//-------------------------------------------------------
void xuatTongGiaTriTungDong(ArrayPtr *a, int m, int n)
{//Tính và xuất tổng giá trị từng dòng
	for (int i = 0; i < m; i++)
	{
		int sum = 0;
		for (int j = 0; j < n; j++)
			sum += a[i][j];
		printf("Tong gia tri dong %d: %d\n", i, sum);
	}
}
//-------------------------------------------------------
void xuatPhanTuDuongBien(ArrayPtr *a, int m, int n)
{//Xuất các phần tử thuộc các đường biên trên, dưới, trái, phải
	printf("Phan tu thuoc duong bien tren: ");
	for (int j = 0; j < n; j++) {
		printf("%4d", a[0][j]);
	}

	printf("\nPhan tu thuoc duong bien duoi: ");
	for (int j = 0; j < n; j++) {
		printf("%4d", a[m - 1][j]);
	}

	printf("\nPhan tu thuoc duong bien trai: ");
	for (int i = 0; i < m; i++) 
	{
		printf("%4d", a[i][0]);
	}

	printf("\nPhan tu thuoc duong bien phai: ");
	for (int i = 0; i < m; i++)
	{
		printf("%4d", a[i][n-1]);
	}
}
//-------------------------------------------------------
int ktCucDai(ArrayPtr *a, int m, int n, int i, int j)
{
	if (i>0 && a[i - 1][j] >= a[i][j]) return 0;//Xét trên
	if (i<m-1 && a[i + 1][j] >= a[i][j]) return 0;//Xét dưới
	if (j>0 && a[i][j-1] >= a[i][j]) return 0;//Xét trái
	if (j<n-1 && a[i][j+1] >= a[i][j]) return 0;//Xét phải

	if (i>0 && j>0 && a[i - 1][j-1] >= a[i][j]) return 0;//Xét chéo trái trên
	if (i>0 && j<n-1 && a[i - 1][j + 1] >= a[i][j]) return 0;//Xét chéo phải trên
	if (i<m-1 && j>0 && a[i + 1][j - 1] >= a[i][j]) return 0;//Xét chéo trái dưới
	if (i<m-1 && j<n-1 && a[i + 1][j + 1] >= a[i][j]) return 0;//Xét chéo phải dưới
	return 1;
}
void xuatPTCucDai(ArrayPtr *a, int m, int n)
{//Xuất các phần tử cực đại
	printf("CAC PHAN TU CUC DAI TRONG MA TRAN LA: ");
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (ktCucDai(a, m, n, i, j) == 1)
				printf("%4d", a[i][j]);
		}
	}
}
//-------------------------------------------------------
int ktCucTieu(ArrayPtr *a, int m, int n, int i, int j)
{
	if (i>0 && a[i - 1][j] <= a[i][j]) return 0;//Xét trên
	if (i<m - 1 && a[i + 1][j] <= a[i][j]) return 0;//Xét dưới
	if (j>0 && a[i][j - 1] <= a[i][j]) return 0;//Xét trái
	if (j<n - 1 && a[i][j + 1] <= a[i][j]) return 0;//Xét phải

	if (i>0 && j>0 && a[i - 1][j - 1] <= a[i][j]) return 0;//Xét chéo trái trên
	if (i>0 && j<n - 1 && a[i - 1][j + 1] <= a[i][j]) return 0;//Xét chéo phải trên
	if (i<m - 1 && j>0 && a[i + 1][j - 1] <= a[i][j]) return 0;//Xét chéo trái dưới
	if (i<m - 1 && j<n - 1 && a[i + 1][j + 1] <= a[i][j]) return 0;//Xét chéo phải dưới
	return 1;
}
void xuatPTCucTieu(ArrayPtr *a, int m, int n)
{//Xuất các phần tử cực tiểu
	printf("CAC PHAN TU CUC TIEU TRONG MA TRAN LA: ");
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (ktCucTieu(a, m, n, i, j) == 1)
				printf("%4d", a[i][j]);
		}
	}
}
//-------------------------------------------------------
int ktCotKChuaSoLe(ArrayPtr *a, int m, int n, int k)
{
	for (int i = 0; i < m; i++)
	if (a[i][k] % 2 == 0)
		return 0;
	return 1;
}
void xuatCotChuaSoLe(ArrayPtr *a, int m, int n)
{//Xuất các cột chứa toàn số lẻ
	int dem=0;
	printf("CAC COT CHUA TOAN SO LE LA: ");
	for (int j = 0; j < n; j++)
	{
		if (ktCotKChuaSoLe(a, m, n, j) == 1)
		{
			printf("%4d", j);
			dem++;
		}
	}
	if (dem == 0)
		printf("Khong co cot nao chua toan so le");
}
//-------------------------------------------------------
Itemtype timPTMAxTrenBien(ArrayPtr *a, int m, int n)
{//Tìm phần tử lớn nhất trong các phần tử trên biên của ma trận
	int max=a[0][0];
	for (int j = 0; j < n; j++) 
	{
		if (a[0][j]>max )
			max = a[0][j];
		if (a[m - 1][j] > max)
			max = a[m - 1][j];
	}
	for (int i = 0; i < m; i++)
	{
		if (a[i][0]>max)
			max = a[i][0];
		if (a[i][n-1] > max)
			max = a[i][n-1];
	}
	return max;
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
void sapXep_DongLeTang_DongChanGiam(ArrayPtr *a, int m, int n)
{//Sắp xếp các dòng có chỉ số lẻ thì tăng dần, các dòng có chỉ số chẵn thì giảm dần
	for (int i = 0; i < m; i++)
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
int ktrDongKCoGiaTriGiamDan(ArrayPtr *a, int m, int n, int k)
{
	for (int j = 0; j < n; j++)
	{
		if (a[k][j] < a[k][j + 1])
			return 0;
	}
	return 1;
}
//-------------------------------------------------------
void lietKeDongCoGiaTriGiamDan(ArrayPtr *a, int m, int n)
{//Liệt kê các dòng chứa giá trị giảm dần
	printf("CAC DONG CHUA GIA TRI GIAM DAN LA: ");
	int dem = 0;
	for (int i = 0; i < m; i++)
	{
		if (ktrDongKCoGiaTriGiamDan(a, m, n, i) == 1)
		{
			dem++;
			printf("%4d", i);
		}
	}
	if (dem == 0)
		printf("Khong co dong nao chua gia tri giam dan!");
}
//-------------------------------------------------------
Itemtype timGiaTriXuatHienNhieuNhat(ArrayPtr *a, int m, int n)
{//Tìm giá trị xuất hiện nhiều nhất trong ma trận
	TanSuat *MA = NULL;
	MA = new TanSuat[m*n];
	int dem = 0;
	MA[dem].n = a[0][0];//giá trị
	MA[dem].m = 1;//Tần suất
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < dem; k++)
			{
				if (a[i][j] != MA[k].n)
					MA[++dem].n = a[i][j];
				else
					MA[k].m++;
			}
		}
	}
	for (int i = 0; i < dem; i++)
	{
		for (int j = i + 1; j <= dem; j++)
		{
			if (MA[i].m < MA[j].m)
			{
				TanSuat tmp = MA[i];
				MA[i] = MA[j];
				MA[j] = tmp;
			}
		}
	}
	/*printf("Gia tri xuat hien nhieu nhat trong ma tran la: ");
	for (int i = 0; i <= dem; i++)
	{
		if (MA[i].n != MA[i + 1].n)
		{
			printf("%4d", MA[i].n);
			break;
		}
		else
			printf("%4d", MA[i].n);
	}*/
	if (MA[0].m == 1)
		return -1;
	else
		return MA[0].n;
}
//-------------------------------------------------------
void hoanVi2DongK_L(ArrayPtr *&a, int m, int n, int k, int l)
{//Hoán vị 2 dòng k và l trong ma trận
	for (int j = 0; j < n; j++)
	{
		swap(a[k][j], a[l][j]);
	}
}
//-------------------------------------------------------
void hoanVi2CotI_J(ArrayPtr *&a, int m, int n, int i, int j)
{//Hoán vị 2 cột i và j trong ma trận
	for (int k = 0; k < m; k++)
	{
		swap(a[k][i], a[k][j]);
	}
}
//-------------------------------------------------------
int tongGiaTriCotK(ArrayPtr *a, int m, int n, int k)
{
	int sum = 0;
	for (int i = 0; i < m; i++)
	{
		sum += a[i][k];
	}
	return sum;
}
//-------------------------------------------------------
void lietKeCacCotCoTongNhoNhat(ArrayPtr *a, int m, int n)
{
	int dem=0;
	int *MA=NULL;
	MA = new Itemtype[n];
	MA[dem] = 0;
	int min = tongGiaTriCotK(a, m, n, 0);
	for (int j = 1; j < n; j++)
	{
		int min1 = tongGiaTriCotK(a, m, n, j);
		if (min1 < min)
		{
			dem = 0;
			MA[dem] = j;
			min = min1;
		}
		else if (min1 == min)
		{
			MA[++dem] = j;
		}
	}
	printf("CAC COT CO TONG NHO NHAT TRONG MA TRAN LA: ");
	if (n == 1)
		printf("0");
	else {
		for (int i = 0; i <= dem; i++)
			printf("%4d", MA[i]);
	}
	delete(MA);
}
//-------------------------------------------------------
int KiemTraDuongCheo(ArrayPtr *&a, int m, int n, int i, int j)
{
	int k, h;
	for (k = i - 1, h = j + 1; k >= 0 && h<n; k--, h++)
	{
		if (a[k][h] > a[i][j])
			return 0;
	}
	for (k = i + 1, h = j - 1; k<m && h >= 0; k++, h--)
	{
		if (a[k][h] > a[i][j])
			return 0;
	}
	for (k = i - 1, h = j - 1; k >= 0 && h >= 0; k--, h--)
	{
		if (a[k][h] > a[i][j])
			return 0;
	}
	for (k = i + 1, h = j + 1; k < m && h<n; k++, h++)
	{
		if (a[k][h] > a[i][j])
			return 0;
	} return 1;
}
//-------------------------------------------------------
int KiemTraDongCot(ArrayPtr *&a, int m, int n, int i, int j)
{
	for (int k = 0; k < m; k++)
	{
		if (a[k][j] > a[i][j])
			return 0;
	}
	for (int k = 0; k < n; k++)
	{
		if (a[i][k] > a[i][j])
			return 0;
	}
	return 1;
}
//-------------------------------------------------------
int KiemTraHoangHau(ArrayPtr *&a, int m, int n, int i, int j)
{
	if (KiemTraDongCot(a, m, n, i, j) == 1)
	{
		if (KiemTraDuongCheo(a, m, n, i, j) == 1)
			return 1;
	}
	return 0;
}
//-------------------------------------------------------
void LietKe_All_HoangHau(ArrayPtr *a, int m, int n)
{//Liệt kê tất cả các phần tử Hoàng hậu trong ma trận
	printf("\nDANH SACH CAC PHAN TU HOANG HAU LA: ");
	int dem = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (KiemTraHoangHau(a, m, n, i, j) == 1)
			{
				printf("%5d", a[i][j]);
				dem++;
			}
		}
	}
	if (dem == 0) printf("Khong co phan tu Hoang hau nao!");
}
//------------------------------------------------------------------------------------
void Copy_MaTran_To_Mang1C(ArrayPtr *a, int m, int n, Itemtype *&b, int &sopt)
{
	sopt = 0;
	b = new Itemtype[m*n];
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			b[sopt++] = a[i][j];
		}
	}
}
//------------------------------------------------------------------------------------
void Tao_MaTran_ZicZag(ArrayPtr *&a, int m, int n, Itemtype *b, int sopt)
{
	InitArrayPtr(a, m, n);
	int count = 0;
	while (count < sopt)
	{
		// Duyệt ma trận theo hướng Ziczag chéo
		for (int d = 0; d < 2 * n - 1; d++)
		{
			int start = (d < n) ? 0 : d - n + 1;
			int end = (d < n) ? d : n - 1;
			if (d % 2 == 0)
			{
				for (int i = start; i <= end; i++)
				{
					a[i][d - i] = b[count++];
				}
			}
			else
			{
				for (int i = end; i >= start; i--)
				{
					a[i][d - i] = b[count++];
				}
			}
		}
	}
}
//------------------------------------------------------------------------------------
void TangDong_TraiSangPhai(ArrayPtr *a, int &h1, int h2, int c1, int c2, Itemtype *b, int
	&count)
{
	if (h1 > h2) return;
	//Xây dựng cạnh trên: hàng h1 từ cột c1 => cột c2
	for (int j = c1; j <= c2; j++)
	{
		a[h1][j] = b[count++];
	}
	h1++; //Tăng h1 để xây dựng cạnh bên phải
}
//------------------------------------------------------------------------------------
void TangDong_PhaiSangTrai(ArrayPtr *a, int h1, int &h2, int c1, int c2, Itemtype *b, int
	&count)
{
	if (h1 > h2) return;
	//Xây dựng cạnh dưới: hàng h2 từ cột c2 => cột c1
	for (int j = c2; j >= c1; j--)
	{
		a[h2][j] = b[count++];
	}
	h2--; //Giảm h2 để xây dựng cạnh bên phải
}
//------------------------------------------------------------------------------------
void TangCot_TrenXuongDuoi(ArrayPtr *a, int h1, int h2, int c1, int &c2, Itemtype *b, int
	&count)
{
	if (c1 > c2) return;
	//Xây dựng cạnh phải: cột c2 từ hàng h1 => hàng h2
	for (int i = h1; i <= h2; i++)
	{
		a[i][c2] = b[count++];
	}
	c2--; //Giảm c2 để xây dựng cạnh dưới
}
//------------------------------------------------------------------------------------
void TangCot_DuoiLenTren(ArrayPtr *a, int h1, int h2, int &c1, int c2, Itemtype *b, int
	&count)
{
	if (c1 > c2) return;
	//Xây dựng cạnh trái: cột c1 từ hàng h2 => hàng h1

	for (int i = h2; i >= h1; i--)
	{
		a[i][c1] = b[count++];
	}
	c1++; //Tăng c1 để xây dựng cạnh trái
}
//------------------------------------------------------------------------------------
void Tao_MaTran_XoanOc(ArrayPtr *&a, int m, int n, Itemtype *b, int sopt)
{
	InitArrayPtr(a, m, n);
	int h1 = 0, h2 = m - 1, c1 = 0, c2 = n - 1;
	int count = 0;
	while (h1 <= h2 && c1 <= c2)
	{
		TangDong_TraiSangPhai(a, h1, h2, c1, c2, b, count);
		TangCot_TrenXuongDuoi(a, h1, h2, c1, c2, b, count);
		TangDong_PhaiSangTrai(a, h1, h2, c1, c2, b, count);
		TangCot_DuoiLenTren(a, h1, h2, c1, c2, b, count);
	}
}
