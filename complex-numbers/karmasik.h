#include<cstdlib>
#include<iostream>
#include<vector>
using namespace std;
class KarmasikSayi
{
private:
	double sanal, reel;

public:
	KarmasikSayi();
	KarmasikSayi(int reelDeger);
	KarmasikSayi(double reelDeger, double sanalDeger);
	friend ostream& operator <<(ostream& outputStream, const KarmasikSayi& sayi);
	friend istream& operator >>(istream& inputStream, KarmasikSayi& sayi);
	friend const KarmasikSayi operator +(const KarmasikSayi& sayi1, const KarmasikSayi& sayi2);
	friend const KarmasikSayi operator +(const KarmasikSayi& sayi1, const int& sayi2);
	friend const KarmasikSayi operator -(const KarmasikSayi& sayi1, const KarmasikSayi& sayi2);
	friend const KarmasikSayi operator -(const KarmasikSayi& sayi1, const int& sayi2);
	friend const KarmasikSayi operator -(const KarmasikSayi& sayi);
	friend const KarmasikSayi operator *(const KarmasikSayi& sayi1, const KarmasikSayi& sayi2);
	friend const KarmasikSayi operator *(const KarmasikSayi& sayi1, const int& sayi2);
	friend const KarmasikSayi operator /(const KarmasikSayi& sayi1, const KarmasikSayi& sayi2);
	friend const KarmasikSayi operator /(const KarmasikSayi& sayi1, const int& sayi2);
	friend bool operator ==(const KarmasikSayi& sayi1, const KarmasikSayi& sayi2);
	friend bool operator !=(const KarmasikSayi& sayi1, const KarmasikSayi& sayi2);
	friend bool operator <(const KarmasikSayi& sayi1, const KarmasikSayi& sayi2);
	friend bool operator >(const KarmasikSayi& sayi1, const KarmasikSayi& sayi2);
	friend bool operator <=(const KarmasikSayi& sayi1, const KarmasikSayi& sayi2);
	friend bool operator >=(const KarmasikSayi& sayi1, const KarmasikSayi& sayi2);
	friend const KarmasikSayi operator !(const KarmasikSayi& sayi);
	friend const KarmasikSayi operator ++(KarmasikSayi& sayi);
	friend const KarmasikSayi operator --(KarmasikSayi& sayi);
	friend const KarmasikSayi operator ^(const KarmasikSayi& sayi1, const int& sayi2);
	KarmasikSayi& operator =(const KarmasikSayi& sayi);
	friend KarmasikSayi operator +=(KarmasikSayi& sayi1, const KarmasikSayi& sayi2);
	friend KarmasikSayi operator +=(KarmasikSayi& sayi1, const int& sayi2);
	friend KarmasikSayi operator -=(KarmasikSayi& sayi1, const KarmasikSayi& sayi2);
	friend KarmasikSayi operator -=(KarmasikSayi& sayi1, const int& sayi2);
	friend KarmasikSayi operator *=(KarmasikSayi& sayi1, const KarmasikSayi& sayi2);
	friend KarmasikSayi operator *=(KarmasikSayi& sayi1, const int& sayi2);
	friend KarmasikSayi operator /=(KarmasikSayi& sayi1, const KarmasikSayi& sayi2);
	friend KarmasikSayi operator /=(KarmasikSayi& sayi1, const int& sayi2);
	friend double uzaklýkFonk(KarmasikSayi& sayi1, const KarmasikSayi& sayi2);
};
KarmasikSayi ortalama(vector<KarmasikSayi> vektor);
void enUzaklarýBulan(vector<KarmasikSayi>& KarSayi,vector<KarmasikSayi>& enUzak,  int& vektorboyutu, double& uzaklýk);
