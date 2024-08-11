#include <stdio.h>
#include <cmath>

// Hàm tính m^n
int power(int m, int n) {
    int result = 1;
    for (int i = 0; i < n; i++) {
        result *= m;
    }
    return result;
}

// Hàm tính UCLN(a, b)
int UCLN(int a, int b) {
    if (b == 0)
        return a;
    return UCLN(b, a % b);
}

// Hàm tính giá trị thứ n của cấp số cộng
int capSoCong(int a, int r, int n) {
    return a + (n - 1) * r;
}

// Hàm tính giá trị thứ n của cấp số nhân
int capSoNhan(int a, int q, int n) {
    int result = a;
    for (int i = 1; i < n; i++) {
        result *= q;
    }
    return result;
}

// Hàm tính giá trị thứ n của dãy
int day(int n) {
    if (n < 6)
        return n;
    return day(n - 5) + day(n - 4) + day(n - 3) + day(n - 2) + day(n - 1);
}

// Bài 13: Tính số hạng thứ n của dãy
int x(int n) {
    if (n < 6)
        return n;
    return x(n - 5) + x(n - 4) + x(n - 3) + x(n - 2) + x(n - 1);
}

// Bài 15: Tính Y_n sử dụng đệ quy
int Y(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;
    if (n == 3) return 3;
    return Y(n - 1) + 2 * Y(n - 2) + 3 * Y(n - 3);
}

// Hàm tính S1(n)
int S1(int n) {
    return n * (n + 1) / 2;
}

// Hàm tính S3(n)
double S3(int n) {
    double sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += 1.0 / (i * (i + 1));
    }
    return sum;
}

// Hàm tính S5(n)
long long S5(int n) {
    long long sum = 0;
    long long fact = 1;
    for (int i = 1; i <= n; ++i) {
        fact *= i;
        sum += fact;
    }
    return sum;
}

// Hàm tính S7(n)
double S7(int n) {
    double sum = 0;
    for (int i = 0; i <= n; ++i) {
        sum += tgamma(n + 1) / pow(tgamma(i + 1), 3);
    }
    return sum;
}

// Hàm tính S9(n)
double S9(int n) {
    double sum = 0;
    for (int i = 0; i <= n; ++i) {
        double inner_sum = 0;
        for (int j = 0; j <= i; ++j) {
            double inner_inner_sum = 0;
            for (int k = 0; k <= j; ++k) {
                double inner_inner_inner_sum = 0;
                for (int m = 0; m <= k; ++m) {
                    double inner_inner_inner_inner_sum = 0;
                    for (int l = 0; l <= m; ++l) {
                        inner_inner_inner_inner_sum += pow((double)l / (l + m), l + m);
                    }
                    inner_inner_inner_sum += pow((double)m / (m + k), m + k) * inner_inner_inner_inner_sum;
                }
                inner_inner_sum += pow((double)k / (k + j), k + j) * inner_inner_sum;
            }
            inner_sum += pow((double)j / (j + i), j + i) * inner_sum;
        }
        sum += pow((double)i / (i + n), i + n) * inner_sum;
    }
    return sum;
}

// Hàm tính S11(n)
double S11(int n) {
    double sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += pow((double)i / (i + 1), 1.0 / 5);
    }
    return sum;
}

int main() {
    int choice, m, n, a, b, r, q;

    do {
        printf("\nMenu:\n");
        printf("1. Tinh m^n\n");
        printf("2. Tinh UCLN(a, b)\n");
        printf("3. Gia tri thu n cua cap so cong\n");
        printf("4. Gia tri thu n cua cap so nhan\n");
        printf("5. Gia tri thu n cua day\n");
        printf("6. Gia tri thu n cua day (Bai 13)\n");
        printf("7. Gia tri cua Y_n (Bai 15)\n");
        printf("8. Tinh S1(n)\n");
        printf("9. Tinh S3(n)\n");
        printf("10. Tinh S5(n)\n");
        printf("11. Tinh S7(n)\n");
        printf("12. Tinh S9(n)\n");
        printf("13. Tinh S11(n)\n");
        printf("0. Thoat\n");
        printf("Chon mot tuy chon: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            printf("Nhap m va n: ");
            scanf_s("%d %d", &m, &n);
            printf("%d^%d = %d\n", m, n, power(m, n));
            break;
        case 2:
            printf("Nhap a va b: ");
            scanf_s("%d %d", &a, &b);
            printf("UCLN(%d, %d) = %d\n", a, b, UCLN(a, b));
            break;
        case 3:
            printf("Nhap a, r va n: ");
            scanf_s("%d %d %d", &a, &r, &n);
            printf("Gia tri thu %d cua cap so cong la %d\n", n, capSoCong(a, r, n));
            break;
        case 4:
            printf("Nhap a, q va n: ");
            scanf_s("%d %d %d", &a, &q, &n);
            printf("Gia tri thu %d cua cap so nhan la %d\n", n, capSoNhan(a, q, n));
            break;
        case 5:
            printf("Nhap n: ");
            scanf_s("%d", &n);
            printf("Gia tri thu %d cua day la %d\n", n, day(n));
            break;
        case 6:
            printf("Nhap n: ");
            scanf_s("%d", &n);
            printf("Gia tri thu %d cua day (Bai 13) la %d\n", n, x(n));
            break;
        case 7:
            printf("Nhap n: ");
            scanf_s("%d", &n);
            printf("Gia tri cua Y(%d) la %d\n", n, Y(n));
            break;
        case 8:
            printf("Nhap n: ");
            scanf_s("%d", &n);
            printf("S1(%d) = %d\n", n, S1(n));
            break;
        case 9:
            printf("Nhap n: ");
            scanf_s("%d", &n);
            printf("S3(%d) = %lf\n", n, S3(n));
            break;
        case 10:
            printf("Nhap n: ");
            scanf_s("%d", &n);
            printf("S5(%d) = %lld\n", n, S5(n));
            break;
        case 11:
            printf("Nhap n: ");
            scanf_s("%d", &n);
            printf("S7(%d) = %lf\n", n, S7(n));
            break;
        case 12:
            printf("Nhap n: ");
            scanf_s("%d", &n);
            printf("S9(%d) = %lf\n", n, S9(n));
            break;
        case 13:
            printf("Nhap n: ");
            scanf_s("%d", &n);
            printf("S11(%d) = %lf\n", n, S11(n));
            break;
        case 0:
            printf("Thoat chuong trinh.\n");
            break;
        default:
            printf("Tuy chon khong hop le. Vui long chon lai.\n");
        }
    } while (choice != 0);

    return 0;
}
