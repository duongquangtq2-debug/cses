#include <iostream>
#include <cmath>
#include <climits>


using namespace std;




int main(){
   

    //khai bao bien
    int toan;
    float diemtoan1;
    double tienluong;

    //khai bao kieu du lieu
    int a, b, c,d;


    // khoi tao
    bool check = false;
    char kytu = 'A';
    int cannang = 50;
    float diemvan ;
    float diemtoan ;
    float diemanh ;
    float diemtrungbinh ;

    cout << "nhap vao diem van: ";
    cin >> diemvan;

    cout << "nhap vao diem toan: ";
    cin >> diemtoan;

    cout << "nhap vao diem anh: ";
    cin >> diemanh;

    diemtrungbinh = (diemvan + diemtoan + diemanh)/3;


    //kiem tra dieu kien
    cout << typeid(diemvan).name() << endl;


    cout << "gia tri cua cannang: " <<diemtrungbinh <<endl;




}
