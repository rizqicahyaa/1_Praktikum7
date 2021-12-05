#include <conio.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#define maks 5
using namespace std;
struct barang 
{
	int harga,jumlah;
	double harjum, total;
	char nama_b [35];
};

int main ()
{
	barang belanja[maks];
	int i,j=0;
	char lagi,nmr[20];
	do
	{
		cout<<"Pembelian barang ke="<<j+1<<endl;
		cout<<"======================"<<endl;
		cout<<"Nama barang	: ";
		cin.get(belanja[j].nama_b,30);
		cout<<"Harga Satuan	: ";
		cin>>belanja[j].harga;
		cout<<"Jumlah yang dibeli: ";
		cin>>belanja[j].jumlah;
		cout<<"\nAda barang lain lagi yang dibeli--maks 5--(Y/N)? ";
		cin>>lagi;
		cin.ignore();
		cout<<endl<<endl;
		j++;
		i=j;		
	}
	while((lagi=='y'||lagi=='Y')&&j<5);
	
	cout<<"Nama File Nota	: ";
	cin>>nmr;
	ofstream struk(nmr,ios::out);
	struk<<"\n";
	struk<<"			NOTA BELANJA					"<<endl;
	struk<<"		TOKO BUKU GRALEKTROMEDIA			"<<endl;
	struk<<"=================================================================="<<endl;
	struk<<"| no | nama barang |  harga satuan	|  jumlah  | total harga |"<<endl;
	struk<<"=================================================================="<<endl;
	for(j=0;j<i;j++)
	{
		belanja[j].harjum=belanja[j].harga*belanja[j].jumlah;
		struk<<"|"<<setw(3)<<j+1<<setw(2);
		struk<<"|"<<setw(11)<<belanja[j].nama_b<<setw(3);
		struk<<"|"<<setw(11)<<belanja[j].harga<<setw(10);
		struk<<"|"<<setw(6)<<belanja[j].jumlah<<setw(5);
		struk<<"|"<<setw(12)<<belanja[j].harjum<<setw(2)<<"|"<<endl;
		belanja[maks].total=belanja[0].harjum+belanja[1].harjum+belanja[2].harjum+belanja[3].harjum+belanja[4].harjum+belanja[5].harjum;
	}
	struk<<"=================================================================="<<endl;
	struk<<"total belanja (Rp)"<<setw(34)<<"|"<<setw(12);
	struk<<belanja[maks].total<<setw(2)<<"|"<<endl;
	struk<<"=================================================================="<<endl;
	getch();
}

