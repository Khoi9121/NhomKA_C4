#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <cmath>
#include <stdlib.h>


// Các hàm đã có trong code mẫu
int power(int m, int n);
int UCLN(int a, int b);
int capSoCong(int a, int r, int n);
int capSoNhan(int a, int q, int n);
int day(int n);
int x(int n);
int Y(int n);

// Bài 2: Hàm tính m^n
int power(int m, int n) {
	int result = 1;
	for (int i = 0; i < n; i++) {
		result *= m;
	}
	return result;
}

// Bài 4: Hàm tính giá trị phần tử thứ n của cấp số cộng
int capSoCong(int a, int r, int n) {
	return a + (n - 1) * r;
}

// Bài 6: Hàm tính biểu thức U(n)
int U(int n) {
	if (n < 6)
		return n;
	return U(n - 5) + U(n - 4) + U(n - 3) + U(n - 2) + U(n - 1);
}

// Bài 8: Hàm tính f(n)
int f(int n) {
	if (n == 1) return 1;
	if (n % 2 == 0) return 2 * f(n / 2);
	return 2 * f(n / 2) + 3 * f(n / 2 + 1);
}

// Bài 10: Hàm tìm kiếm nhị phân
int binarySearch(int arr[], int left, int right, int x) {
	if (right >= left) {
		int mid = left + (right - left) / 2;
		if (arr[mid] == x) return mid;
		if (arr[mid] > x) return binarySearch(arr, left, mid - 1, x);
		return binarySearch(arr, mid + 1, right, x);
	}
	return -1;
}

// Bài 12: Hàm tìm số Fibonacci lớn nhất nhỏ hơn n
int maxFibonacciLessThanN(int n) {
	if (n <= 1) return 0;
	int a = 1, b = 1;
	while (b <= n) {
		int temp = b;
		b = a + b;
		a = temp;
	}
	return a;
}

// Bài 14: Hàm tính An
int An(int n) {
	if (n == 1) return 1;
	int sum = 0;
	for (int i = 1; i < n; i++) {
		sum += An(i);
	}
	return n * sum;
}

// Bài 16: Hàm tính Xn
int Xn(int n) {
	if (n == 1 || n == 2) return 1;
	return Xn(n - 1) + (n - 1) * Xn(n - 2);
}

// Bài 18: Hàm tính tổng S(n) = 1^2 + 2^2 + ... + n^2
int S18(int n) {
	return n * (n + 1) * (2 * n + 1) / 6;
}

// Bài 20: Hàm tính tổng S(n) = 1 + 1/3 + 1/5 + ... + 1/(2n+1)
double S20(int n) {
	double sum = 0;
	for (int i = 0; i <= n; i++) {
		sum += 1.0 / (2 * i + 1);
	}
	return sum;
}

// Bài 22: Hàm tính tổng S(n) = 1 - 1/2 + 1/3 - 1/4 + ... + (-1)^(n+1) * 1/n
double S22(int n) {
	double sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += pow(-1, i + 1) * 1.0 / i;
	}
	return sum;
}

// Bài 24: Hàm tính tổng S(n) = 1 - 1/2! + 1/3! - ... + (-1)^(n+1) * 1/n!
double S24(int n) {
	double sum = 0;
	double factorial = 1;
	for (int i = 1; i <= n; i++) {
		factorial *= i;
		sum += pow(-1, i + 1) * 1.0 / factorial;
	}
	return sum;
}

// Bài 26: Hàm tính tổng S(n) = 1 + x + x^2/2! + x^3/3! + ... + x^n/n!
double S26(double x, int n) {
	double sum = 1;
	double term = 1;
	for (int i = 1; i <= n; i++) {
		term *= x / i;
		sum += term;
	}
	return sum;
}

// Bài 28: Hàm tính pi sử dụng công thức Leibniz
double calculatePi(int n) {
	double pi = 0;
	for (int i = 0; i < n; i++) {
		pi += pow(-1, i) / (2 * i + 1);
	}
	return 4 * pi;
}

// Bài 30: Hàm tính ước chung lớn nhất của n số nguyên
int UCLN_n(int arr[], int n) {
	int result = arr[0];
	for (int i = 1; i < n; i++) {
		result = UCLN(result, arr[i]);
	}
	return result;
}

int UCLN(int a, int b) {
	if (b == 0) return a;
	return UCLN(b, a % b);
}

// Bài 32: Hàm kiểm tra số nguyên tố
bool isPrime(int n) {
	if (n <= 1) return false;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) return false;
	}
	return true;
}

// Bài 34: Hàm tìm số nguyên tố thứ n
int nthPrime(int n) {
	int count = 0;
	int num = 2;
	while (count < n) {
		if (isPrime(num)) {
			count++;
		}
		if (count == n) return num;
		num++;
	}
	return -1;  // Không tìm thấy
}


int main() {
	int choice, m, n, a, b, r, q;
	double x;
	do {
		printf("\nMenu:\n");
		printf("2. Tinh m^n\n");
		printf("4. Gia tri thu n cua cap so cong\n");
		printf("6. Tinh bieu thuc U(n)\n");
		printf("8. Tinh f(n)\n");
		printf("10. Tim kiem nhi phan\n");
		printf("12. Tim so Fibonacci lon nhat nho hon n\n");
		printf("14. Tinh An\n");
		printf("16. Tinh Xn\n");
		printf("18. Tinh tong S(n) = 1^2 + 2^2 + ... + n^2\n");
		printf("20. Tinh tong S(n) = 1 + 1/3 + 1/5 + ... + 1/(2n+1)\n");
		printf("22. Tinh tong S(n) = 1 - 1/2 + 1/3 - 1/4 + ... + (-1)^(n+1) * 1/n\n");
		printf("24. Tinh tong S(n) = 1 - 1/2! + 1/3! - ... + (-1)^(n+1) * 1/n!\n");
		printf("26. Tinh tong S(n) = 1 + x + x^2/2! + x^3/3! + ... + x^n/n!\n");
		printf("28. Tinh pi su dung cong thuc Leibniz\n");
		printf("30. Tim UCLN cua n so nguyen\n");
		printf("32. Kiem tra so nguyen to\n");
		printf("34. Tim so nguyen to thu n\n");
		printf("0. Thoat\n");
		printf("-----------------------------------------------------------\n");
		printf("Chon mot tuy chon: ");
		scanf_s("%d", &choice);

		switch (choice) {
		case 2:
			printf("Nhap m va n: ");
			scanf_s("%d %d", &m, &n);
			printf("%d^%d = %d\n", m, n, power(m, n));
			break;
		case 4:
			printf("Nhap a, r va n: ");
			scanf_s("%d %d %d", &a, &r, &n);
			printf("Gia tri thu %d cua cap so cong la %d\n", n, capSoCong(a, r, n));
			break;
		case 6:
			printf("Nhap n: ");
			scanf_s("%d", &n);
			printf("U(%d) = %d\n", n, U(n));
			break;
		case 8:
			printf("Nhap n: ");
			scanf_s("%d", &n);
			printf("f(%d) = %d\n", n, f(n));
			break;
		case 10:
		{
			int arr[100], size, x;
			printf("Nhap kich thuoc mang: ");
			scanf_s("%d", &size);
			printf("Nhap cac phan tu mang (da sap xep): ");
			for (int i = 0; i < size; i++) {
				scanf_s("%d", &arr[i]);
			}
			printf("Nhap gia tri can tim: ");
			scanf_s("%d", &x);
			int result = binarySearch(arr, 0, size - 1, x);
			if (result == -1)
				printf("Khong tim thay %d trong mang\n", x);
			else
				printf("%d duoc tim thay tai vi tri %d\n", x, result);
		}
		break;
		case 12:
			printf("Nhap n: ");
			scanf_s("%d", &n);
			printf("So Fibonacci lon nhat nho hon %d la %d\n", n, maxFibonacciLessThanN(n));
			break;
		case 14:
			printf("Nhap n: ");
			scanf_s("%d", &n);
			printf("A(%d) = %d\n", n, An(n));
			break;
		case 16:
			printf("Nhap n: ");
			scanf_s("%d", &n);
			printf("X(%d) = %d\n", n, Xn(n));
			break;
		case 18:
			printf("Nhap n: ");
			scanf_s("%d", &n);
			printf("S(%d) = %d\n", n, S18(n));
			break;
		case 20:
			printf("Nhap n: ");
			scanf_s("%d", &n);
			printf("S(%d) = %f\n", n, S20(n));
			break;
		case 22:
			printf("Nhap n: ");
			scanf_s("%d", &n);
			printf("S(%d) = %f\n", n, S22(n));
			break;
		case 24:
			printf("Nhap n: ");
			scanf_s("%d", &n);
			printf("S(%d) = %f\n", n, S24(n));
			break;
		case 26:
		{
			printf("Nhap x va n: ");
			scanf_s("%lf %d", &x, &n);
			printf("S(%d) = %f\n", n, S26(x, n));
			break;
		}
		case 28:
			printf("Nhap so lan lap de tinh pi: ");
			scanf_s("%d", &n);
			printf("Pi = %f\n", calculatePi(n));
			break;
		case 30:
		{
			int size;
			printf("Nhap so luong so nguyen: ");
			scanf_s("%d", &size);
			int* arr = (int*)malloc(size * sizeof(int));
			printf("Nhap %d so nguyen: ", size);
			for (int i = 0; i < size; i++) {
				scanf_s("%d", &arr[i]);
			}
			printf("UCLN cua %d so la: %d\n", size, UCLN_n(arr, size));
			free(arr);
		}
		break;
		case 32:
			printf("Nhap so can kiem tra: ");
			scanf_s("%d", &n);
			if (isPrime(n)) {
				printf("%d la so nguyen to\n", n);
			}
			else {
				printf("%d khong phai la so nguyen to\n", n);
			}
			break;
		case 34:
			printf("Nhap n: ");
			scanf_s("%d", &n);
			printf("So nguyen to thu %d la: %d\n", n, nthPrime(n));
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