#include <iostream>
#include <algorithm>
using namespace std;

void NhapMang(int *a, int n)
{
    for (int  i = 0 ; i < n ; i++)
        cin >> a[i];
    sort(a,a+n);// Hàm sắp xếp theo thứ tự tăng dần.
}

int TimKiemNhiPhan(int *a, int &n, int x)
{
    int left = 0;
    int right = n-1;
    int mid;
    do 
    {
        mid = ( left + right ) / 2 ; // vị trí mid = vị trí đầu + vị trí cuối của các phần tử trong mảng / 2
        if (a[mid] == x) 
            return mid; // nếu a ở vị trí mid = x thì kết luận ngay mid là vị trí của x
        else if (a[mid] < x) 
            left  = mid +1;// nếu a ở vị trí mid < x tức là x đang nằm dịch về phía cuối mảng vì vậy ta cho left dịch sang bển phải mid 1 đơn vị, right vẫn giữ nguyên là n-1 sau đó xét tiếp vòng lặp
        else right = mid-1;// nếu a ở vị trí mid > x tức là x đang nằm dịch về phía đầu mảng vì vậy ta cho right dịch sang bển trái mid 1 đơn vị, left vẫn giữ nguyên là 0 sau đó xét tiếp vòng lặp
    }while(left <= right);
    return -1;
}

int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    NhapMang(a,n);

    int x; 
    cout << "Nhap vao gia tri x can tim: ";
    cin >> x;
    cout << "Vi tri cua " << x << " sau khi tim kiem nhi phan la: " << TimKiemNhiPhan(a,n,x);// tìm kiếm phần tử x bằng thuật toán tìm kiếm nhị phân
    return 0;
}