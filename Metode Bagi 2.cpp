#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <math.h>

using namespace std;
void gotoxy(int x, int y){
 COORD coord;
 coord.X = x;
 coord.Y = y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

double f(double z)
{
 double panggil=(pow(z,3.0))+(2*pow(z,2.0))+(10*z)-(20);
 return panggil;
}
int main () {
menu: 
double a,b,c,e,error=1;
int n;
cout<<"------------------------------------------------------------------------------------------------------------------------------ \n";
cout<<"|                                                     METODE TERTUTUP                                                        | \n";
cout<<"|                                                     Metode Bagi Dua                                                        | \n";
cout<<"------------------------------------------------------------------------------------------------------------------------------ \n";
cout<<" Input Batas Bawah (a)   : ";cin>>a;
cout<<" Input Batas Atas (b)    : ";cin>>b;
cout<<" Input Kondisi Berhenti  : ";cin>>e;
cout<<" Iterasi Max             : ";cin>>n;

double Fa=f(a);
double  Fb=f(b);

if (Fa*Fb>0)
{
 gotoxy(2,9);cout<<"F(a)*F(b) :"<<f(a)*f(b);
 gotoxy(2,10);cout<<f(a);
 gotoxy(2,11);cout<<f(b); 
 gotoxy(2,12);cout<<"Kedua Batas persamaan Ini Tidak Memiliki Akar \n";
 system("pause");
 system("cls");
 goto menu;
 } 

else {
gotoxy(2,10);cout<<"----------------------------------------------------------------------------------------------------------------------------- \n";
gotoxy(2,11);cout<<"|Literasi|       a       |      c      |      b      |       f(a)      |      f(c)      |        f(b)      |      Error     | \n";
gotoxy(2,12);cout<<"----------------------------------------------------------------------------------------------------------------------------- \n";

for(int iterasi=1;iterasi<=n;iterasi++)
{ 
c=(a+b)/(2);
gotoxy(2,12+iterasi);cout<<"|";
gotoxy(6,12+iterasi);cout<<iterasi;
gotoxy(11,12+iterasi);cout<<"|";
gotoxy(13,12+iterasi);printf("%1.5f",a);
gotoxy(27,12+iterasi);cout<<"|";
gotoxy(29,12+iterasi);printf("%1.5f",c);
gotoxy(41,12+iterasi);cout<<"|";
gotoxy(43,12+iterasi);printf("%1.5f",b);
gotoxy(55,12+iterasi);cout<<"|";
gotoxy(57,12+iterasi);printf("%1.5f",Fa);
gotoxy(73,12+iterasi);cout<<"|";
gotoxy(75,12+iterasi);printf("%1.5f",f(c));
gotoxy(90,12+iterasi);cout<<"|";
gotoxy(92,12+iterasi);printf("%1.5f",Fb);
gotoxy(109,12+iterasi);cout<<"|";

if(f(a)*f(c)<0){
 b=c;
 Fb=f(c);
}

else{
 a=c;
 Fa=f(c);
}

error=fabs(b-a);
gotoxy(111,12+iterasi);printf("%1.10f",error);
gotoxy(126,12+iterasi);cout<<"|";

if (error < e){
gotoxy(1,13+iterasi);cout<<"------------------------------------------------------------------------------------------------------------------------------ \n";
iterasi=n+1;

}}}
return 0;
getch();
}


