#include "stdio.h"
#include "string.h"
#include <stdlib.h>
struct NGAY_THANG {
	int ngay,thang,nam;
};typedef struct NGAY_THANG ngay;

struct MON_HOC {
    char maMon[20];
    float diem;
};typedef struct MON_HOC mh;
struct SINH_VIEN {
	
	char mssv[12],hoten[25],diachi[100],gioitinh[10];
	int somon;
	ngay ngaysinh;
	MON_HOC *monhoc;
	
	
	
};typedef struct SINH_VIEN sv;

void nhapsinhvien(SINH_VIEN *sv)
{
	printf("moi nhap ho va ten: ");
	fflush(stdin);
	gets(sv->hoten);
	printf("moi nhap mssv: ");
	fflush(stdin);
	gets(sv->mssv);
	printf("moi nhap dia chi: ");
	fflush(stdin);
	gets(sv->diachi);
	printf("moi nhap ngay thang nam: ");
	scanf("%d  %d  %d",&sv->ngaysinh.ngay,&sv->ngaysinh.thang,&sv->ngaysinh.nam);
	printf("moi nhap so mon hoc: ");
	scanf("%d",&sv->somon);
  sv->monhoc = (MON_HOC*)malloc(sv->somon * sizeof(MON_HOC));
	for(int i=0;i<sv->somon;i++)
	{
		printf("moi nhap ma mon thu %d ",i+1);
		fflush(stdin);
		gets(sv->monhoc[i].maMon);
		printf("moi nhap diem mon thu %d ",i+1);
		scanf("%f",&sv->monhoc[i].diem);
	}

	
}

void xuatsinhvien(SINH_VIEN sv)
{
	printf("\n%s \t %s\t%s\t%d/%d/%d\t%d\t",sv.diachi,sv.hoten,sv.mssv,sv.ngaysinh.ngay,sv.ngaysinh.thang,sv.ngaysinh.nam,sv.somon);
	for(int i=0;i<sv.somon;i++)
	{
        printf(" %.10s %.2f diem", sv.monhoc[i].maMon, sv.monhoc[i].diem);
    }
}




int main()
{
	SINH_VIEN a;
	int n;

	
	printf("moi nhap n: ");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
	printf("\nmoi nhap thong tin sinh vien thu %d \n",i+1);
	nhapsinhvien(&a);
	xuatsinhvien(a);
	}
	
	return 0;
}
