#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void display_menu() {
    printf("MENU\n");
    printf("1. Nh?p s? ph?n t? c?n nh?p và giá tr? các ph?n t?\n");
    printf("2. In ra giá tr? các ph?n t? dang qu?n lý\n");
    printf("3. In ra giá tr? l?n nh?t c?a m?ng\n");
    printf("4. In ra các ph?n t? là s? nguyên t? trong m?ng\n");
    printf("5. Thêm m?t ph?n t? vào trong m?ng\n");
    printf("6. Xóa m?t ph?n t? trong m?ng\n");
    printf("7. S?p x?p m?ng theo th? t? tang d?n\n");
    printf("8. Tìm ki?m ph?n t? và in ra v? trí index c?a ph?n t? dó\n");
    printf("9. Thoát\n");
}

void nhap_mang(int arr[], int *n) {
    printf("Nh?p s? ph?n t?: ");
    scanf("%d", n);
    printf("Nh?p giá tr? các ph?n t?: ");
    for (int i = 0; i < *n; i++) {
        scanf("%d", &arr[i]);
    }
}

void in_mang(int arr[], int n) {
    printf("Các ph?n t? trong m?ng: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void gia_tri_lon_nhat(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    printf("Giá tr? l?n nh?t trong m?ng: %d\n", max);
}

int kiem_tra_nguyen_to(int n) {
    if (n < 2) return 0;
    for (int i = 2; i <= n/2; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

void in_nguyen_to(int arr[], int n) {
    printf("Các ph?n t? là s? nguyên t? trong m?ng: ");
    for (int i = 0; i < n; i++) {
        if (kiem_tra_nguyen_to(arr[i])) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}

void them_phan_tu(int arr[], int *n) {
    if (*n < MAX) {
        printf("Nh?p giá tr? ph?n t? c?n thêm: ");
        scanf("%d", &arr[*n]);
        (*n)++;
    } else {
        printf("M?ng dã d?y!\n");
    }
}

void xoa_phan_tu(int arr[], int *n) {
    int index;
    printf("Nh?p ch? s? ph?n t? c?n xóa: ");
    scanf("%d", &index);
    if (index >= 0 && index < *n) {
        for (int i = index; i < *n - 1; i++) {
            arr[i] = arr[i + 1];
        }
        (*n)--;
    } else {
        printf("Ch? s? không h?p l?!\n");
    }
}

void sap_xep_tang_dan(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("M?ng sau khi s?p x?p: ");
    in_mang(arr, n);
}

void tim_kiem(int arr[], int n) {
    int x, found = 0;
    printf("Nh?p giá tr? ph?n t? c?n tìm: ");
    scanf("%d", &x);
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            printf("Ph?n t? %d n?m ? v? trí index: %d\n", x, i);
            found = 1;
        }
    }
    if (!found) {
        printf("Không tìm th?y ph?n t? %d trong m?ng.\n", x);
    }
}

int main() {
    int arr[MAX], n = 0, choice;
    do {
        display_menu();
        printf("L?a ch?n c?a b?n: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                nhap_mang(arr, &n);
                break;
            case 2:
                in_mang(arr, n);
                break;
            case 3:
                gia_tri_lon_nhat(arr, n);
                break;
            case 4:
                in_nguyen_to(arr, n);
                break;
            case 5:
                them_phan_tu(arr, &n);
                break;
            case 6:
                xoa_phan_tu(arr, &n);
                break;
            case 7:
                sap_xep_tang_dan(arr, n);
                break;
            case 8:
                tim_kiem(arr, n);
                break;
            case 9:
                printf("Thoát chuong trình.\n");
                break;
            default:
                printf("L?a ch?n không h?p l?. Vui lòng ch?n l?i.\n");
                break;
        }
    } while (choice != 9);

    return 0;
}

