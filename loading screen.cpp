#include <iostream>
#include <windows.h>//untuk gotoxy
#include <conio.h>
using namespace std;

//prosedur animasi - delay
void delay()
{
    int delay =1;
    while (delay<10000000)//bisa 10000000 atau 100000000(lebih lama) aku nyoba 0 lebih dikit ga bakal kek animasi
    {
        delay++;
    }
}

//gotoxy
void gotoxy(int x, int y)
{
    HANDLE hConsoleOutput;//untuk handle layar
    COORD dwCursorPosition;//COORD adalah struct yang punya 2 variabel yaitu x dan y dengan tipe data SHORT

    dwCursorPosition.X = x;//x dan y untuk menentukan posisi koordinat cursor
    dwCursorPosition.Y = y;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleCursorPosition(hConsoleOutput,dwCursorPosition);
}


void l_pp()//luas persegi panjang
{
    int p,l,luas;
    gotoxy(42,8);
    cout <<"LUAS PERSEGI PANJANG";
    gotoxy(42,9);
    cout <<"Masukkan panjang = ";cin>>p;
    gotoxy(42,10);
    cout <<"Masukkan lebar   = ";cin>>l;
    luas=p*l;
    gotoxy(42,12);
    cout <<"------------------------";
    gotoxy(42,13);
    cout <<"Luas persegi panjang = "<<luas;

}

void k_pp()//keliling persegi panjang
{
    int p,l,kel;
    gotoxy(42,8);
    cout <<"KELILING PERSEGI PANJANG";
    gotoxy(42,9);
    cout <<"Masukkan panjang = ";cin>>p;
    gotoxy(42,10);
    cout <<"Masukkan lebar   = ";cin>>l;
    kel=2*(p+l);
    gotoxy(42,12);
    cout <<"----------------------------";
    gotoxy(42,13);
    cout <<"Keliling persegi panjang = "<<kel;

}

void l_p()//luas persegi
{
    int s,luas;
    gotoxy(42,8);
    cout <<"LUAS PERSEGI ";
    gotoxy(42,9);
    cout <<"Masukkan sisi = ";cin>>s;

    luas=s*s;
    gotoxy(42,11);
    cout <<"----------------";
    gotoxy(42,12);
    cout <<"Luas persegi = "<<luas;

}

void k_p()//keliling persegi
{
    int s,kel;
    gotoxy(42,8);
    cout <<"KELILING PERSEGI ";
    gotoxy(42,9);
    cout <<"Masukkan sisi = ";cin>>s;

    kel=4*s;
    gotoxy(42,11);
    cout <<"--------------------";
    gotoxy(42,12);
    cout <<"Keliling persegi = "<<kel;

}
int main()
{
    int i,j,pil;
    char ulang;

    for (i=30; i<=50; i++)//i=30 krn aku mau mulai - di x = 30
    {
        gotoxy(i,12);//pake i, krn kalau tetep 30, cuma muncul satu - (krn akan selalu di koordinat 30)
        cout <<"-";
        gotoxy(i,14);
        cout <<"-";
        delay();// agar - muncul satu satu (jadi gerak kek animasi)
    }

    for(i=0; i<=100; i++)
    {
        gotoxy(30,13); //gausah pake i di x, karena biar star di koordinat 30, untuk y=13 krn  biar ditengah garis atas & bawah (12&14)
        cout << "L O A D I N G "<<i<<"%";
        delay();
    }


    atas://untuk ulang (line 197)
    system("cls");

    //bingkai atas
    for(i=1; i<=100; i++)
    {
        gotoxy(i,1);
        cout<<"#";
        gotoxy(i,4);
        cout<<"#";
        gotoxy(i,20);
        cout<<"#";
        gotoxy(i,24);
        cout<<"#";
    }

    //bingkai samping
    for(i=1; i<=24; i++)
    {
        gotoxy(1,i);//y yg berubah krn y buat yg vertikal
        cout<<"#";
        gotoxy(100,i);
        cout<<"#";
    }

    //bingkai tengah
    for(i=4; i<=20; i++)
    {
        gotoxy(40,i);
        cout<<"#";
    }

    //teks
    gotoxy(35,2);
    cout<<"KUMPULAN RUMUS - MATEMATIKA";
    gotoxy(35,22);
    cout<<"Talitha Aurora - 2023";


    //teks kiri
    gotoxy(3,6);
    cout <<"1. LUAS PERSEGI PANJANG";
    gotoxy(3,7);
    cout <<"2. KELILING PERSEGI PANJANG";
    gotoxy(3,8);
    cout <<"3. LUAS PERSEGI";
    gotoxy(3,9);
    cout <<"4. KELILING PERSEGI";

    //teks kanan
    gotoxy(42,6);
    cout << "Masukkan pilihan Anda [1..4] : ";cin>>pil;

    if(pil == 1)
    {
        l_pp();
    }
    else if(pil == 2)
    {
        k_pp();
    }
    else if(pil == 3)
    {
        l_p();
    }else if(pil == 4)
    {
        k_p();
    }else
    {
        gotoxy(42,14);
        cout<<"MAAF ANDA SALAH PILIH KODE";
    }

    //program ulang
    gotoxy(42,16);
    cout<<"Apakah Anda mau mengulang [y/n] : ";cin>>ulang;

    if(ulang == 'y')
    {
       goto atas; //atas adalah sebuah nama label, aturan buat nama label kek variabel
    }else
    {
        system("cls");
        cout <<"PROGRAM SELESAI";
    }


    getch();
    return 0;
}


