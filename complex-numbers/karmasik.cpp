#include "karmasik.h"
#include<iostream>
#include<cstdlib>

using namespace std;
//Reel ve sanal katsayilari  alan constructer.
KarmasikSayi::KarmasikSayi(double reelDeger, double sanalDeger)
{
	sanal = sanalDeger;
	reel = reelDeger;

}
//Conversion constructor.
KarmasikSayi::KarmasikSayi(int reelDeger)
{
	reel = reelDeger;
	sanal = 0;
}
//Default Constructer.
KarmasikSayi::KarmasikSayi()
{
	reel = 0;
	sanal = 0;
}
//<< operatörünün asiri yüklenmesi. Bir Karmasik sayiyi a+bi seklinde yazdirmasi.
ostream& operator <<(ostream& outputStream, const KarmasikSayi& sayi)
{
	outputStream << sayi.reel;
	if (sayi.sanal < 0) 
	{
		outputStream << sayi.sanal;
		outputStream << "i";
	}
	else if (sayi.sanal == 1)
	{
		outputStream << "+";
		outputStream << "i";
	}
	else if (sayi.sanal > 1)
	{ 
		outputStream << "+"; 
		outputStream << sayi.sanal;
		outputStream << "i";
	}
	
	return outputStream;
}
//>> operatörünün asiri yüklenmesi. a + b seklinde klavyeden girilen karmasik sayiyi classa kaydetmesi.
istream& operator >>(istream& inputStream, KarmasikSayi& sayi)
{
	int reelDeger, sanalDeger;
	char isaret, iDegeri;
	inputStream >> reelDeger;
	inputStream >> isaret;
	inputStream >> sanalDeger;
	inputStream >> iDegeri;
	if (isaret == '-') //Eger sanal katsayini isareti eksi girildiyse sanal katsayiyi - ile carp ve ata.
		sayi.sanal = -sanalDeger;
	else
		sayi.sanal = sanalDeger;
	sayi.reel = reelDeger;

	return inputStream;
}
//Iki karmasik sayiyi toplamasi icin + operatörünün asiri yüklenmesi.
const KarmasikSayi operator +(const KarmasikSayi& sayi1, const KarmasikSayi& sayi2) {
	int reelToplam, sanalToplam;
	reelToplam = (int)(sayi2.reel + sayi1.reel);
	sanalToplam = (int)(sayi1.sanal + sayi2.sanal);
	return KarmasikSayi(reelToplam, sanalToplam);
	
}
//Bir karmasik sayi ve bir sayiyi toplamasi için + operatörnün asiri yüklenmesi.
const KarmasikSayi operator +(const KarmasikSayi& sayi1, const int& sayi2)
{
	int reelToplam;
	reelToplam = (int)(sayi1.reel + sayi2);
	return KarmasikSayi(reelToplam, (int)sayi1.sanal);
}
//Iki karmasik sayiyi çikarmasi için - operatörnün asiri yüklenmesi.
const KarmasikSayi operator -(const KarmasikSayi& sayi1, const KarmasikSayi& sayi2)
{
	int sanalFark, reelFark;
	reelFark = (int)(sayi1.reel - sayi2.reel);
	sanalFark = (int)(sayi1.sanal - sayi2.sanal);
	return KarmasikSayi(reelFark, sanalFark);
}
//Bir karmasik sayi ve bir sayiyi çikarmasi için - operatörnün asiri yüklenmesi.
const KarmasikSayi operator -(const KarmasikSayi& sayi1, const int& sayi2)
{
	int reelFark;
	reelFark = (int)(sayi1.reel - sayi2);
	return KarmasikSayi(reelFark, (int)sayi1.sanal);
}
//Bir karmasik sayiyi negatif yapmasi için - operatörnün asiri yüklenmesi.
const KarmasikSayi operator -(const KarmasikSayi& sayi)
{
	int reelNegatif, sanalNegatif;
	reelNegatif = (int)(0 - sayi.reel);
	sanalNegatif = (int)(0 - sayi.sanal);
	return KarmasikSayi(reelNegatif, sanalNegatif);
}
//Iki karmasik sayiyi çarpmasi için * operatörnün asiri yüklenmesi.
const KarmasikSayi operator *(const KarmasikSayi& sayi1, const KarmasikSayi& sayi2)
{
	int reelCarpim, sanalCarpim;
	reelCarpim = (int)((sayi1.reel*sayi2.reel) - (sayi1.sanal*sayi2.sanal));
	sanalCarpim = (int)((sayi1.reel*sayi2.sanal) + (sayi1.sanal*sayi2.reel));
	return KarmasikSayi(reelCarpim, sanalCarpim);
}
//Bir karmasik sayi ve bir sayiyi çarpmasi için * operatörnün asiri yüklenmesi.
const KarmasikSayi operator *(const KarmasikSayi& sayi1, const int& sayi2)
{
	int reelCarpim, sanalCarpim;
	reelCarpim = (int)(sayi1.reel*sayi2);
	sanalCarpim = (int)(sayi1.sanal*sayi2);
	return KarmasikSayi(reelCarpim, sanalCarpim);
}
//Iki karmasik sayiyi bölmesi için / operatörnün asiri yüklenmesi.
const KarmasikSayi operator /(const KarmasikSayi& sayi1, const KarmasikSayi& sayi2)
{
	double reelBolum, sanalBolum;
	if (sayi2 != 0) //Payda 0 degilse bölme islemini yap 
	{
		reelBolum = ((sayi1.reel*sayi2.reel) + (sayi2.sanal*sayi1.sanal)) / ((sayi2.reel*sayi2.reel) + (sayi2.sanal*sayi2.sanal));
		sanalBolum = ((sayi1.sanal*sayi2.reel) - (sayi1.reel*sayi2.sanal)) / ((sayi2.reel*sayi2.reel) + (sayi2.sanal*sayi2.sanal));
	}
	return KarmasikSayi(reelBolum, sanalBolum);
}
//Bir karmasik sayiyi bir sayiya bölmesi için / operatörnün asiri yüklenmesi.
const KarmasikSayi operator /(const KarmasikSayi& sayi1, const int& sayi2)
{
	double reelBolum, sanalBolum;
	if (sayi2 != 0) //Payda 0 degilse bölme islemini yap 
	{
		reelBolum = sayi1.reel / sayi2;
		sanalBolum = sayi1.sanal / sayi2;
	}
	return KarmasikSayi(reelBolum, sanalBolum);
}
//Iki karmasik sayi esit mi diye kontrol etmesi için == operatörünün asiri yüklenmesi.
bool operator ==(const KarmasikSayi& sayi1, const KarmasikSayi& sayi2)
{
	if ((sayi1.reel == sayi2.reel) && (sayi1.sanal == sayi2.sanal))
	{
		return true;
	}
	else return false;
}
//Iki karmasik sayi esit degil mi diye kontrol etmesi için != operatörünün asiri yüklenmesi.
bool operator !=(const KarmasikSayi& sayi1, const KarmasikSayi& sayi2)
{
	if ((sayi1.reel == sayi2.reel) && (sayi1.sanal == sayi2.sanal))
	{
		return false;
	}
	else return true;
}
//Bir karmasik sayi diger karmasik sayidan küçük mü  diye kontrol etmesi için < operatörünün asiri yüklenmesi.
//SADECE REEL KATSAYILARI KONTROL EDER
bool operator <(const KarmasikSayi& sayi1, const KarmasikSayi& sayi2)
{
	if (sayi1.reel < sayi2.reel)
		return true;
	else
		return false;

}
//Bir karmasik sayi diger karmasik sayidan büyük mü  diye kontrol etmesi için > operatörünün asiri yüklenmesi.
//SADECE REEL KATSAYILARI KONTROL EDER
bool operator >(const KarmasikSayi& sayi1, const KarmasikSayi& sayi2)
{
	if (sayi1.reel > sayi2.reel)
		return true;
	else
		return false;

}
//Bir karmasik sayi diger karmasik sayidan küçük esit mi  diye kontrol etmesi için <= operatörünün asiri yüklenmesi.
//SADECE REEL KATSAYILARI KONTROL EDER
bool operator <=(const KarmasikSayi& sayi1, const KarmasikSayi& sayi2) 
{
	if (sayi1.reel <= sayi2.reel)
		return true;
	else
		return false;
}
//Bir karmasik sayi diger karmasik sayidan büyük esit mi  diye kontrol etmesi için >= operatörünün asiri yüklenmesi.
//SADECE REEL KATSAYILARI KONTROL EDER
bool operator >=(const KarmasikSayi& sayi1, const KarmasikSayi& sayi2)
{
	if (sayi1.reel >= sayi2.reel)
		return true;
	else
		return false;
}
//Bir karmasik sayinin eslenigini almasi için ! operatörünün asiri yüklenmesi.
const KarmasikSayi operator !(const KarmasikSayi& sayi)
{
	int sanalKisim, reelKisim;
	reelKisim = (int)(sayi.reel);
	sanalKisim = (int)(-sayi.sanal);
	return KarmasikSayi(reelKisim, sanalKisim);
}
//Bir karmasik sayinin reel kismini 1 arttirmasi için ++ operatörünün asiri yüklenmesi.
const KarmasikSayi operator ++(KarmasikSayi& sayi)
{
	return KarmasikSayi((int)(sayi.reel + 1), (int)sayi.sanal);
}
//Bir karmasik sayinin reel kismini 1 azaltmasi için -- operatörünün asiri yüklenmesi.
const KarmasikSayi operator --(KarmasikSayi& sayi)
{
	return KarmasikSayi((int)(sayi.reel - 1), (int)sayi.sanal);
}
//Bir karmasik sayinin üssünü almasi için ^ opeatörünün asiri yüklenmesi.(Sol el tarafindaki parametre karmasik sayi, sag el tarafýndaki pozitif tam sayi)
const KarmasikSayi operator ^(const KarmasikSayi& sayi1, const int& sayi2)
{
	KarmasikSayi tutucu = sayi1;
	if (sayi2 == 0) 
	{
		return KarmasikSayi(1);
	}
	else if (sayi2 == 1)
	{
		return sayi1;
	}
	else if( sayi2 > 1)
	{
		for (int i = 1; i <= sayi2 - 1; i++)
		{
			tutucu = tutucu * sayi1;
		}
		return tutucu;
	}
	else
	{
		cout << "Program - ussu kabul etmemektedir." << endl;
		return NULL;
	}
}
//Bir karmasik sayiyi baska bir karmasik sayiya atmasi için = operatörünün asiri yüklenmesi.
KarmasikSayi&  KarmasikSayi::operator =(const KarmasikSayi& sayi)
{
	reel = sayi.reel;
	sanal = sayi.sanal;
	return *this;
}
//Birinci karmasik sayiyi baska bir karmasik sayi ile toplayip birinciye atamasi için += operatörünün asiri yüklenmesi.
KarmasikSayi operator +=(KarmasikSayi& sayi1, const KarmasikSayi& sayi2)
{
	sayi1 = sayi1 + sayi2;
	return sayi1;
}
//Birinci karmasik sayiyi baska bir sayi ile toplayip birinciye atamasi için += operatörünün asiri yüklenmesi.
KarmasikSayi operator +=(KarmasikSayi& sayi1, const int& sayi2)
{
	sayi1 = sayi1 + sayi2;
	return sayi1;
}
//Birinci karmasik sayiyi baska bir karmasik sayi ile cikarip birinciye atamasi için -= operatörünün asiri yüklenmesi.
KarmasikSayi operator -=(KarmasikSayi& sayi1, const KarmasikSayi& sayi2)
{
	sayi1 = sayi1 - sayi2;
	return sayi1;
}
//Birinci karmasik sayiyi baska bir sayi ile çikarip birinciye atamasi için -= operatörünün asiri yüklenmesi.
KarmasikSayi operator -=(KarmasikSayi& sayi1, const int& sayi2)
{
	sayi1 = sayi1 - sayi2;
	return sayi1;
}
//Birinci karmasik sayiyi baska bir karmasik sayi ile çarpip birinciye atamasi için *= operatörünün asiri yüklenmesi.
KarmasikSayi operator *=(KarmasikSayi& sayi1, const KarmasikSayi& sayi2)
{
	sayi1 = sayi1 * sayi2;
	return sayi1;
}
//Birinci karmasik sayiyi baska bir sayi ile çarpip birinciye atamasi için *= operatörünün asiri yüklenmesi.
KarmasikSayi operator *=(KarmasikSayi& sayi1, const int& sayi2)
{
	sayi1 = sayi1 * sayi2;
	return sayi1;
}
//Birinci karmasik sayiyi baska bir karmasik sayi ile bolup birinciye atamasi için /= operatörünün asiri yüklenmesi.
KarmasikSayi operator/=(KarmasikSayi & sayi1, const KarmasikSayi & sayi2)
{
	if (sayi2 != 0) //Payda 0 deðilse bölme iþlemini yap
	{
		sayi1 = sayi1 / sayi2;
		return sayi1;
	}
	else
		cout << "0'a bolme islemi yapilamaz" << endl;
	return -1;
}
//Birinci karmasik sayiyi baska bir sayi ile bölüp birinciye atamasi icin /= operatörünün asiri yüklenmesi.
KarmasikSayi operator/=(KarmasikSayi & sayi1, const int & sayi2)
{
	if (sayi2 != 0) //Payda 0 degilse bölme islemini yap
	{
		sayi1 = sayi1 / sayi2;
		return sayi1;
	}
	else
		cout << "0'a bolme islemi yapilamaz" << endl;
	return -1;
}

//Iki karmasik sayiyi karmasik düzlemdeki aralarindaki uzakligi bulan fonksiyon 
double uzaklýkFonk(KarmasikSayi & sayi1, const KarmasikSayi & sayi2)
{

	return sqrt(((sayi1.reel-sayi2.reel)*(sayi1.reel - sayi2.reel))+((sayi1.sanal-sayi2.sanal)*(sayi1.sanal - sayi2.sanal)));
}
//Girilen Karmasik sayilarin ortalamasini bulan fonksiyon
KarmasikSayi ortalama(const vector<KarmasikSayi> vektor)
{
	int vektorBoyutu = vektor.size();
	KarmasikSayi toplam(0,0);
	for (int i = 0; i < vektorBoyutu; i++)
	{
		toplam +=vektor[i];
	}
	toplam /= vektorBoyutu;
	return toplam;
}
//Butun Karmasik sayilari birbiri ile kontrol eden ve en uzak iki karmasik sayiyi bir vektöre yazip, aralarindaki uzakligi da bir degiskene yazan fonksiyon.
void enUzaklarýBulan(vector<KarmasikSayi>& KarSayi, vector<KarmasikSayi>& enUzak, int & vektorboyutu, double & uzaklýk)
{
	double uzaklýkdegeri  = -1;
	double uzaklýk1;
	for (int j = 0; j < vektorboyutu; j++)
	{
		for (int k = 0; k < vektorboyutu; k++)
		{
			uzaklýk1 = uzaklýkFonk(KarSayi[j], KarSayi[k]);
			if (uzaklýk1 > uzaklýkdegeri)
			{
				uzaklýkdegeri = uzaklýk1;
				enUzak[0] = KarSayi[j];
				enUzak[1] = KarSayi[k];
			}
			else
				uzaklýk = uzaklýk1;
		}
	}
	uzaklýk = uzaklýkdegeri;
}
