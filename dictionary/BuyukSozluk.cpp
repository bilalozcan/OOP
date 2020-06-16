#include"BuyukSozluk.h"
#include"Kayit.h"
#include<iostream>

using namespace std;
// bos bir sozluk oluturur.
Sozluk::Sozluk()
{
	kayitlar = nullptr;
	toplamKayitSayisi = 0;
}
// tek bir kayittan olusan bir sozluk olusturur.
Sozluk::Sozluk(const Kayit & kayit)
{
	kayitlar = new Kayit [1];
	if (kayitlar == nullptr)
		exit(-1);
	kayitlar[0] = kayit;
	toplamKayitSayisi = 1;
}
// Bir kayit vektoru alir ve sozluk olusturur. Sozlukte her kayit sadece bir kez olabilir.
// Eger vektor icinde ayni kayit sozcugu varsa bunlarýn aciklamalarýný birlestirir.
Sozluk::Sozluk(const vector<Kayit>& kayitlar)
{
	vector<Kayit> temp = kayitlar; //Verilen kaydý geçici olarak tutan vector.

	for (unsigned i = 0; i < temp.size(); i++)
	{
		for (unsigned j = temp.size()-1 ; j > i;j--)
		{
			if (temp[i].getKelime() == temp[j].getKelime())
			{
				temp[i] + temp[j];
				temp.erase(temp.begin() + j);
			}
		}
	}
	this->kayitlar = nullptr;
	this->kayitlar = new Kayit[temp.size()];
	if (this->kayitlar == nullptr)
		exit(-1);
	toplamKayitSayisi = temp.size();
	for (unsigned i = 0; i < toplamKayitSayisi; i++)
	{
		this->kayitlar[i] = temp[i];
	}

}
//Copy Consturcter
Sozluk::Sozluk(const Sozluk & copy)
{
	//cout << "COPY CONSTRUCTORS" << endl;
	toplamKayitSayisi = copy.toplamKayitSayisi;
	kayitlar = nullptr;
	if (toplamKayitSayisi != 0)
	{
		kayitlar = new Kayit[toplamKayitSayisi];
		if (kayitlar == nullptr)
			exit(-1);

		for (unsigned i = 0; i < toplamKayitSayisi; i++)
		{
			kayitlar[i] = copy.kayitlar[i];
		}
	}
}
//Destructer
Sozluk::~Sozluk()
{
	//cout << "DESTRUCTORS" << endl;
	if (kayitlar != nullptr)
		delete[] kayitlar;
}
//Assigment operatörünün aþýrý yuklenmesi
const Sozluk & Sozluk::operator=(const Sozluk & other)
{
	//cout << "ASSIGMENT OPERATORU" << endl;
	if (this == &other)
		return *this;
	if (kayitlar != nullptr)
		delete[] kayitlar;
	toplamKayitSayisi = other.toplamKayitSayisi;
	kayitlar = new Kayit[toplamKayitSayisi];
	if (kayitlar == nullptr)
		exit(-1);
	for (unsigned i = 0; i < toplamKayitSayisi; i++)
	{
		kayitlar[i] = other.kayitlar[i];
	}
	return *this;
	
}
//Verilen bir kelime degerine sahip Kaydi donderen subscript operatorunu asiri yukleyiniz
Kayit & Sozluk::operator[](const string & kelime)
{

	for(unsigned  i = 0; i < toplamKayitSayisi ;i++)
	{
		if (kayitlar[i].getKelime() == kelime)
			return kayitlar[i];
	}
	Kayit a;
	return a;
}
//Sozlukdeki aciklama sayisini bulup döndüren fonksiyon
int Sozluk::getAciklamSayisi ()const
{
	int temp = 0;
	for (unsigned i = 0; i < toplamKayitSayisi; i++)
	{
		temp += kayitlar[i].getAciklamaSayisi();
	}
	return temp;
}
// Iki sozlugu buyukluk acisindan karislatiran operatorleri asiri yukleyin
// Karsilasirmalar toplam sozlukteki toplam aciklama sayisina gore yapilir
// ==, !=, >, <, <=, >= operatorlerinin tamamýnýn asiri yuklenmesi
bool Sozluk::operator ==(const Sozluk digerSozluk)
{
	if (this->getAciklamSayisi() == digerSozluk.getAciklamSayisi())
		return true;
	return false;
}

bool Sozluk::operator!=(const Sozluk digerSozluk)
{
	if (this->getAciklamSayisi() != digerSozluk.getAciklamSayisi())
		return true;
	return false;
}

bool Sozluk::operator>(const Sozluk digerSozluk)
{
	if (this->getAciklamSayisi() > digerSozluk.getAciklamSayisi())
		return true;
	return false;
}

bool Sozluk::operator<(const Sozluk digerSozluk)
{
	if (getAciklamSayisi() < digerSozluk.getAciklamSayisi())
		return true;
	return false;
}

bool Sozluk::operator<=(const Sozluk digerSozluk)
{
	if (this->getAciklamSayisi() <= digerSozluk.getAciklamSayisi())
		return true;
	return false;
}

bool Sozluk::operator>=(const Sozluk digerSozluk)
{
	if (this->getAciklamSayisi() >= digerSozluk.getAciklamSayisi())
		return true;
	return false;
}
// Iki sozlugu birlestiren iki operandli + operatorunu asiri yukleyiniz. Birlesim
// sonunda ayni kayittan iki tane olmaz, aciklamalar bir kelime altina toplanir
// bir kayit altinda birebir ayni aciklama iki veya daha cok kez bulunamaz
Sozluk & Sozluk::operator+(const Sozluk & digerSozluk)
{
	vector<Kayit>temp;
	vector<Kayit>tempb;
	for (int i = 0; i < this->toplamKayitSayisi; i++) {
		temp.push_back(this->kayitlar[i]);
	}
	for (int i = 0; i < digerSozluk.toplamKayitSayisi; i++) {
		tempb.push_back(digerSozluk.kayitlar[i]);
	}
	for (int i = 0; i < this->toplamKayitSayisi; i++) {
		for (int j = 0; j < digerSozluk.toplamKayitSayisi; j++) {
			if ((temp[i].getKelime() == tempb[j].getKelime())) {
				temp[i] + tempb[j];
			}
		}
	}
	toplamKayitSayisi = temp.size();
	this->kayitlar = new Kayit[toplamKayitSayisi];
	if (this->kayitlar == nullptr) exit(-1);
	for (unsigned i = 0; i < toplamKayitSayisi; i++) {
		this->kayitlar[i] = temp[i];
	}
	return *this;
}
// Iki sozlugu birlestiren += operatorunu asiri yukleyiniz. Birlesim sonunda ayni kayittan
//iki tane olmaz, aciklamalar bir kelime altina toplanir
// bir kayit altinda birebir ayni aciklama iki veya daha cok kez bulunamaz
Sozluk & Sozluk::operator+=(const Sozluk & digerSozluk)
{
	*this = *this + digerSozluk;
	return *this;
}
// Sozluk icindeki kelimede yer alan aciklamalari siler. Eger hic aciklama
//kalmamissa tum kelimeyi siler
Sozluk & Sozluk::operator-=(const Kayit & kayit)
{
	unsigned temp;
	for (unsigned i = 0; i < this->toplamKayitSayisi; i++)
	{
		if (this->kayitlar[i].getKelime() == kayit.getKelime())
			temp = i;
	}
	if(this->kayitlar[temp].getAciklamaSayisi()==0)
	{
		vector<Kayit> gecici;
		for (unsigned i = 0; i < toplamKayitSayisi; i++)
		{
			if (i != temp)
				gecici.push_back(kayitlar[i]);
		}
		Sozluk a(gecici);
		*this = a;
		return *this;

	}
	else
	{
		this->kayitlar[temp].aciklamalariSilme();
		return *this;
	}
}
// Sozluk icindeki kelimede yer alan TUM aciklamalari siler.
Sozluk & Sozluk::operator-=(const string & kelime)
{
	for (unsigned i = 0; i < this->toplamKayitSayisi; i++)
	{
		if (this->kayitlar[i].getKelime() == kelime)
			this->kayitlar[i].aciklamalariSilme();
	}
	return *this;
}
// Sozlukteki kayitli kelime sayisini ve toplam aciklama sayisini ekrana yazdirir.
ostream & operator<<(ostream & o, const Sozluk & s)
{
	o << "Kayitli Kelime Sayisi: " << s.toplamKayitSayisi << endl;
	o << "Toplam aciklama Sayisi: " << s.getAciklamSayisi() << endl;
	return o;
}
//Sozlukdeký kelimeleri ve aciklamalarýný dosya yazmak için << ooperatorunun aþýrý yuklenmesi
ofstream& operator<<(ofstream& out, const Sozluk& s)
{
	for (int i = 0; i < s.toplamKayitSayisi; i++)
	{
		out << s.kayitlar[i].getKelime() << ":"<<std::endl;
		for (int j = 0; j < s.kayitlar[i].getAciklamaSayisi(); j++)
		{
			out << s.kayitlar[i].getAciklama()[j] << std::endl;
		}
		out << "- - - - - - - - - - - - - - - - - - - - -" << endl;
	}
	return out;
}
//Býr dosyadan kelýme ve acýklamalarýný okumak ýcýn >> operatorunun asýrý yuklenmesý
ifstream& operator>>(ifstream& in, Sozluk& s)
{
	string kelimeTutan, aciklamaTutan, bos;
	vector<string> aciklamalar;
	vector<Kayit> kayitlar;
	while (!in.eof())
	{
		getline(in, kelimeTutan, ':');
		getline(in, bos, '\n');
		getline(in, aciklamaTutan, '\n');
		while (aciklamaTutan != "- - - - - - - - - - - - - - - - - - - - -")
		{
			aciklamalar.push_back(aciklamaTutan);
			getline(in, aciklamaTutan, '\n');
		}
		Kayit k1(kelimeTutan, aciklamalar);
		kayitlar.push_back(k1);
		aciklamalar.clear();
	}
	Sozluk sozluk1(kayitlar);
	s = sozluk1;
	return in;
}
