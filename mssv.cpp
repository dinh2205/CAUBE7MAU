#include "stdio.h"
#include "stdlib.h"
#include "string.h"

// Struct definitions
struct MON_HOC {
    char mamon[20];
    float diem;
};

struct NGAY_THANG {
    int ngay, thang, nam;
};

struct SINH_VIEN {
    char hoten[50], mssv[15], diachi[100], gioitinh[4];
    int somon;
    MON_HOC *monhoc;
    NGAY_THANG ngaysinh;
};

typedef struct SINH_VIEN sv;

// Function declarations
void nhapsinhvien(SINH_VIEN *sv);
void xuatsinhvien(SINH_VIEN sv);
void timmasosv(SINH_VIEN *sv, int n, char *T);

int main() {
    int n;
    char T[15]; // To store MSSV as a string

    printf("Moi nhap so luong sinh vien: ");
    do {
        scanf("%d", &n);
    } while (n <= 0);  // Ensure n is positive

    // Dynamically allocate memory for 'n' students
    SINH_VIEN *sv = (SINH_VIEN *)malloc(n * sizeof(SINH_VIEN));

    // Input student data
    for (int i = 0; i < n; i++) {
        printf("Moi nhap thong tin sinh vien thu %d\n", i + 1);
        nhapsinhvien(&sv[i]); // Pass the correct student pointer
        xuatsinhvien(sv[i]);
        printf("\n");
    }

    // Tim kiem sinh vien theo MSSV
    printf("Moi nhap ma so sinh vien can tim: ");
    getchar();  // Clear any leftover newline character
    fgets(T, 15, stdin);
    T[strcspn(T, "\n")] = 0;  // Remove newline character from input
    timmasosv(sv, n, T);

    // Free allocated memory for monhoc array for each student
    for (int i = 0; i < n; i++) {
        free(sv[i].monhoc);
    }

    // Free memory for student array
    free(sv);

    return 0;
}

// Function to input student data
void nhapsinhvien(SINH_VIEN *sv) {
    printf("Moi nhap Ho va ten: ");
    getchar();  // Clear any leftover newline character
    fgets(sv->hoten, 50, stdin);
    sv->hoten[strcspn(sv->hoten, "\n")] = 0;  // Remove newline character
    
    printf("Moi nhap mssv: ");
    fgets(sv->mssv, 15, stdin);
    sv->mssv[strcspn(sv->mssv, "\n")] = 0;  // Remove newline character
    
    printf("Moi nhap gioi tinh: ");
    fgets(sv->gioitinh, 4, stdin);
    sv->gioitinh[strcspn(sv->gioitinh, "\n")] = 0;  // Remove newline character
    
    printf("Moi nhap dia chi: ");
    fgets(sv->diachi, 100, stdin);
    sv->diachi[strcspn(sv->diachi, "\n")] = 0;  // Remove newline character
    
    printf("Moi nhap ngay thang nam sinh: ");
    scanf("%d %d %d", &sv->ngaysinh.ngay, &sv->ngaysinh.thang, &sv->ngaysinh.nam);
    
    printf("Moi nhap so mon hoc: ");
    scanf("%d", &sv->somon);
    
    // Dynamically allocate memory for subjects
    sv->monhoc = (MON_HOC *)malloc(sv->somon * sizeof(MON_HOC));

    for (int i = 0; i < sv->somon; i++) {
        printf("Moi nhap ma mon thu %d: ", i + 1);
        getchar();  // Clear any leftover newline character
        fgets(sv->monhoc[i].mamon, 20, stdin);
        sv->monhoc[i].mamon[strcspn(sv->monhoc[i].mamon, "\n")] = 0;  // Remove newline character
        
        printf("Moi nhap diem mon thu %d: ", i + 1);
        scanf("%f", &sv->monhoc[i].diem);
    }
}

// Function to output student information
void xuatsinhvien(SINH_VIEN sv) {
    printf("Thong tin sinh vien:\n");
    printf("Ho va Ten: %s\n", sv.hoten);
    printf("MSSV: %s\n", sv.mssv);
    printf("Gioi Tinh: %s\n", sv.gioitinh);
    printf("Dia Chi: %s\n", sv.diachi);
    printf("Ngay Sinh: %d/%d/%d\n", sv.ngaysinh.ngay, sv.ngaysinh.thang, sv.ngaysinh.nam);
    printf("So Mon Hoc: %d\n", sv.somon);
    
    for (int i = 0; i < sv.somon; i++) {
        printf("Mon Hoc %d: %s - Diem: %.2f\n", i + 1, sv.monhoc[i].mamon, sv.monhoc[i].diem);
    }
}

// Function to find student by MSSV
void timmasosv(SINH_VIEN *sv, int n, char *T) {
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(sv[i].mssv, T) == 0) {
            xuatsinhvien(sv[i]);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Khong tim thay sinh vien voi MSSV: %s\n", T);
    }
}

