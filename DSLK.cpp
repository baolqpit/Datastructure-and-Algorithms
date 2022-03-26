#include <iostream>
using namespace std;

struct Node 
{
    int data;
    Node *next;
};
typedef struct Node* node;

node makeNode(int x)//Cấp phát động một node mới với dữ liệu là số nguyên x
{
    node tmp = new Node();
    tmp->data = x;
    tmp->next = NULL;
    return tmp;
}

//Kiểm tra rỗng
bool empty(node a)
{
    return a = NULL;
}

int Size(node a)
{
    int cnt = 0;
    while (a != NULL)
    {
        ++cnt;
        a = a->next;// gán địa chỉ của node tiếp theo cho node hiện tại
    };
    return cnt;
}

//thêm 1 phần tử vào đầu dslk
void insertFirst(node &a, int x)
{
    node tmp = makeNode(x);
    if (a == NULL)
        a = tmp;
    else 
    {
        tmp->next = a;
        a = tmp;
    }
}

void insertLast(node &a, int x)
{
    node tmp = makeNode(x);
    if (a == NULL)
        a = tmp;
    else
    {
        node p = a;
        while(p->next != NULL)
        {
            p = p->next;
        }
        p->next = tmp;
    }
}

//Thêm 1 phần tử vào giữa
void insertMiddle(node &a, int x, int pos)
{
    int n = Size(a);
    if (pos <= 0 || pos > n + 1)
        cout << "Error!";
    if (n == 1)
    {
        insertFirst(a,x);
        return;
    }
    else if (n == pos + 1)
    {
        insertLast(a,x);
        return;
    }
    node p = a;

    for (int i = 1; i < pos - 1; i++)
        p = p->next;

    node tmp = makeNode(x);
    tmp->next = p->next;
    p->next = tmp;
}

//Xóa phần tử ở đầu
void deleteFirst(node &a)
{
    if (a == NULL)
        return;
    a = a->next;
}

//Xóa phần tử ở cuối
void deleteLast(node &a)
{
    if (a == NULL)
        return;
    node truoc = NULL, sau = a;
    while (sau->next != NULL)
    {
        truoc = sau;
        sau  = sau->next;
    }
    if (truoc == NULL)
        a = NULL;
    else {
        truoc->next = NULL;
    }
}

void deleteMiddle(node &a, int pos)
{
    if (pos <= 0 || pos > Size(a))  return;
    node truoc = NULL;
    node sau = a;
    for (int i = 0; i < pos; i++){
        truoc = sau;
        sau = sau->next;
    }

    if (truoc == NULL){
        a = a->next;
    }
    else{
        truoc->next = sau->next;
    }
}

void Print(node a)
{
    while(a != NULL)
    {
        cout << a->data << " ";
        a = a->next;
    }
    cout << endl;
}

void sapxep(node &a)
{
    for (node p = a; p->next != NULL; p = p->next){
        node min = p;
        for (node q = p->next; q != NULL; q = q->next){
            if (q->data < min->data)
                min = q;
        }
        int tmp = min->data;
        min->data = p->data;
        p->data = tmp; 
    }
}
int main()
{
    node head = NULL;
    while(1)
    {
        cout << "------------------Menu------------------\n";
        cout << "0. Thoat khoi chuong trinh\n";
        cout << "1. Chen phan tu vao dau danh sach\n";
        cout << "2. Chen phan tu vao cuoi danh sach\n";
        cout << "3. Chen phan tu vao giua danh sach\n";
        cout << "4. Xoa phan tu o dau danh sach\n";
        cout << "5. Xoa phan tu o cuoi danh sach\n";
        cout << "6. Xoa phan tu o giua danh sach\n";
        cout << "7. Duyet danh sach lien ket\n";
        cout << "8.Sap xep cac phan tu trong dslk\n";
        cout << "----------------------------------------\n";

        cout << "Nhap lua chon: ";
        int lc; 
        cin >> lc;

        if (lc == 1)
        {
            int x;
            cout << "\nNhap vao bien x: ";
            cin >> x;
            insertFirst(head,x);
        }
        else if (lc == 2)
        {
            int x;
            cout << "\nNhap vao bien x: ";
            cin >> x;
            insertLast(head,x);
        }
        else if (lc == 3)
        {
            int x;
            cout << "\nNhap vao bien x: ";
            cin >> x;

            int pos;
            cout << "\nNhap vao vi tri can chen: ";
            cin >> pos;

            insertMiddle(head,x,pos);
        }
        else if (lc == 4)
            deleteFirst(head);
        else if (lc == 5)
            deleteLast(head);
        else if (lc == 6)
        {
            int pos;
            cout << "\nNhap vi tri can xoa: ";
            cin >> pos;
            deleteMiddle(head,pos);
        }
        else if (lc == 7){
            Print(head);
            cout << endl;
        }
        else if (lc == 8){
            sapxep(head);
        }
        else if (lc == 0){
            break;
        }
    }
    return 0;
}