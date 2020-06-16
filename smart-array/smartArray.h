/*18120205035
 *Bilal ÖZCAN
 *Ödev9 template class çalýþmasý */
#pragma once
#include <vector>
#include <iostream>
#include<string>
using namespace std;
template<typename T>
struct Pair 
{
	T eleman; 
	unsigned adet;
}; // histogramda her bir elemandan kacar adet oldugunu gosterebilecek veri tipi */

//Ýndex operatöründe eleman sayýsýndan fazla bir index istendiðinde exception handling yapacak class
class ExpHandNoMemory{};
//Dinamik Hafýza kullanýrken yer alýnamadýðýnda exception handling yapacak class
class ExpHandOverMemory{};
template<class T>
class AkilliDizi 
{
	template<class T>
	friend ostream& operator << (ostream& out,const AkilliDizi<T>& dizi);
public:
	//bos bir akilli dizi olusturur
	AkilliDizi();
	//tek elamanlý ve eleman degeri i olan bir akilli dizi olusturur
	AkilliDizi(T i);
	//elemanSayisi elamanli bir akilli dizi olusturur ve intDizi elamanlarini akilli diziye atar
	AkilliDizi(const T* TDizi, unsigned int elemanSayisi);
	//vektoru akilli diziye donusturur
	AkilliDizi(const vector<T>& TVector);

	//Dinamik bellek yonetimi icin gerekli olan fonksiyonlari
	~AkilliDizi();
	AkilliDizi(const AkilliDizi<T>& copyT);
	AkilliDizi<T>& operator =(const AkilliDizi<T>& assigmentT);
	
	//[] operatorunun asiri yuklenmesi
	T& operator[](const unsigned int index);
	T operator[](const unsigned int index)const;
	
	//AkilliDizi'ye bir int degeri ekleyebilen + operatorunun asiri yuklenmesi
	AkilliDizi<T>& operator +(T i);

	//diziyi buyukten kucuge siralar
	void sirala()const;

	//veri icinde gecen her bir elemanin kac kez oldugunu bulur ve bunu vektor<Pair> olarak donderir
	void histogram(vector<Pair<T>>& hist) const;

	//veri icinde i degerinden kac tane olduðunu sayar
	unsigned kacTane(T a) const;

	//veri icinde i degeri mevcutsa dogru degilse yanlis donderir TEMPLATE OLACAK*/
	bool varMi(T a) const;


private:
	T* veri;
	unsigned int kapasite;
	unsigned int elemanSayisi;
};
class Ogrenci
{
	//Ogrencýn adýný ve numarasýný yazdýran << operatörü
	friend ostream& operator <<(ostream& out, Ogrenci& ogrenciOut)
	{
		out << "Adi: ";
		for (unsigned i = 0; i < ogrenciOut.adUzunlugu; ++i)
		{
			out << ogrenciOut.ad[i];
		}
		out << "  " << "No: ";
		for (unsigned i = 0; i < ogrenciOut.noUzunlugu; ++i)
		{
			out << ogrenciOut.no[i];
		}
		out << endl;
		return out;
	}

public:
	//Default Constructer
	Ogrenci()
	{
		ad = nullptr;
		no = nullptr;
		adUzunlugu = 0;
		noUzunlugu = 0;
	}
	//BÜYÜK ÜÇLÜ
	//Conversion Consturcter
	Ogrenci(string ad, string no)
	{
		adUzunlugu = ad.size();
		noUzunlugu = no.size();
		this->ad = new char[adUzunlugu];
		if (this->ad == nullptr)
			throw ExpHandNoMemory();
		this->no = new char[noUzunlugu];
		if (this->no == nullptr)
			throw ExpHandNoMemory();
		for (unsigned i = 0; i < adUzunlugu; ++i)
			this->ad[i] = ad[i];
		for (unsigned i = 0; i < noUzunlugu; ++i)
			this->no[i] = no[i];
	}
	//Destructer
	~Ogrenci()
	{
		if (ad != nullptr)
			delete[] ad;

		if (no != nullptr)
			delete[] no;
	}
	//Copy Constructer
	Ogrenci(const Ogrenci& copyOgrenci)
	{
		adUzunlugu = copyOgrenci.adUzunlugu;
		noUzunlugu = copyOgrenci.noUzunlugu;
		ad = nullptr;
		no = nullptr;
		ad = new char[adUzunlugu];
		if (this->ad == nullptr)
			throw ExpHandNoMemory();
		no = new char[noUzunlugu];
		if (this->no == nullptr)
			throw ExpHandNoMemory();
		for (unsigned i = 0; i < adUzunlugu; ++i)
			ad[i] = copyOgrenci.ad[i];
		for (unsigned i = 0; i < noUzunlugu; ++i)
			no[i] = copyOgrenci.no[i];
	}
	//Assigment Operatörü
	Ogrenci& operator=(const Ogrenci& assigmentOgrenci)
	{
		if (this == &assigmentOgrenci)
			return *this;
		if (ad != nullptr)
			delete[] ad;
		if (no != nullptr)
			delete[] no;
		adUzunlugu = assigmentOgrenci.adUzunlugu;
		noUzunlugu = assigmentOgrenci.noUzunlugu;
		ad = new char[adUzunlugu];
		if (this->ad == nullptr)
			throw ExpHandNoMemory();
		no = new char[noUzunlugu];
		if (this->no == nullptr)
			throw ExpHandNoMemory();
		for (unsigned i = 0; i < adUzunlugu; ++i)
			ad[i] = assigmentOgrenci.ad[i];
		for (unsigned i = 0; i < noUzunlugu; ++i)
			no[i] = assigmentOgrenci.no[i];
		return *this;
	}
	//char* tutulan öðrenci nosunu double a çevirme
	double cevirme() const
	{
		double carpan = noUzunlugu*10;
		double numara = 0;
		double temp;
		int sayilar[] = { 48, 49, 50, 51, 52, 53, 54, 55, 56, 57};
		
		for (unsigned i = 0; i < noUzunlugu; ++i)
		{
			for (int j = 0; j < 10; ++j)
				if ((int)no[i] == sayilar[j])
					temp = j;
			numara += temp * carpan;
			carpan /= 10;
		}
		return numara;
	}
	//Öðrenci nosuna göre karþýlaþtýrma yapan < oparatörü
	bool operator <(const Ogrenci& ogr)
	{
		if (this->cevirme() < ogr.cevirme())
			return true;
		return false;
	}
	//Öðrenci nosuna göre karþýlaþtýrma yapan > oparatörü
	bool operator >(const Ogrenci& ogr)
	{
		if (this->cevirme() > ogr.cevirme())
			return true;
		return false;
	}
	//Öðrenci nosuna göre karþýlaþtýrma yapan == oparatörü
	bool operator ==(const Ogrenci& ogr)
	{
		if (this->cevirme() == ogr.cevirme())
			return true;
		return false;
	}
private:
	char *ad;
	unsigned adUzunlugu;
	char *no;
	unsigned noUzunlugu;
};