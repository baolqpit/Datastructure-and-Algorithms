#include <iostream>
using namespace std;

struct Date
{
    int day;
    int month;
    int year;
};

void InputDate(Date &x)//Nhập vào ngày tháng năm
{
    cin >> x.day >> x.month >> x.year;
}

bool CheckYear(Date x)//Kiểm tra xem năm nhập vào có phải là năm nhuận hay không
{
    if (x.year % 400 == 0)
        return true;
    if (x.year % 4 == 0 && x.year % 100 != 0)
        return true;
    else return false;
}

int ReturnMonth(Date x)// Kiểm tra tháng
{
    switch(x.month)
    {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12: 
        {
            return 31;
            break;
        }
        case 2: 
        {
            if (CheckYear(x))
                return 29;
            return 28;
        }
        case 4: case 6: case 9: case 11:
        {
            return 30;
            break;
        }
    }
}

bool CheckDate(Date x)//Kiểm tra ngày tháng năm hợp lệ
{
    if (x.year < 0)
        return false;
    if (x.day < 1 || x.day > ReturnMonth(x))
        return false;
    if (x.month < 1 || x.month > 12)
        return false;
    return true;
}

void NextDay(Date &x)
{
    x.day++;
    if (x.day > ReturnMonth(x))
    {
        x.day = 1;
        x.month++;
        if (x.month > 12)
        {
            x.month = 1;
            x.year++;
        }
    }

}

void OutputDate(Date x)
{
    if (CheckDate(x))
    {
        NextDay(x);
        cout << x.day << "/" << x.month << "/" << x.year;
    }
    else cout << "Error!";
}

int main()
{
    Date x;
    InputDate(x);
    OutputDate(x);
    return 0;
}