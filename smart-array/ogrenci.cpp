#include"ogrenci.h"
Ogrenci::Ogrenci()
{
	ad = nullptr;
	adUzunlugu = 0;
	no = nullptr;
	noUzunlugu = 0;
}

Ogrenci::Ogrenci(string ad, string no)
{
	adUzunlugu = ad.size();
	noUzunlugu = no.size();
	this->ad = new char[adUzunlugu];
	if (this->ad == nullptr)
		exit(-1);
	this->no = new char[noUzunlugu];
	if (this->no == nullptr)
		exit(-1);
	for (unsigned i = 0; adUzunlugu; ++i)
		this->ad[i] = ad[i];
	for (unsigned i = 0; noUzunlugu; ++i)
		this->no[i] = no[i];
}

Ogrenci::~Ogrenci()
{
	if (ad != nullptr)
		delete[] ad;
	if (no != nullptr)
		delete[] no;
}

Ogrenci::Ogrenci(const Ogrenci & copy)
{
	adUzunlugu = copy.adUzunlugu;
	noUzunlugu = copy.noUzunlugu;
	ad = nullptr;
	no = nullptr;
	ad = new char[adUzunlugu];
	if (ad == nullptr)
		exit(-1);
	no = new char[noUzunlugu];
	if (no == nullptr)
		exit(-1);
	ad = copy.ad;
	no = copy.no;
}

Ogrenci & Ogrenci::operator=(const Ogrenci & assigmnt)
{
	if (this == &assigmnt)
		return *this;
	if (ad != nullptr)
		delete[] ad;
	if (no != nullptr)
		delete[] no;
	adUzunlugu = assigmnt.adUzunlugu;
	noUzunlugu = assigmnt.noUzunlugu;
	ad = new char[adUzunlugu];
	if (ad == nullptr)
		exit(-1);
	no = new char[noUzunlugu];
	if (no == nullptr)
		exit(-1);
	ad = assigmnt.ad;
	no = assigmnt.no;
	return *this;
}

ostream & operator<<(ostream & out, Ogrenci & ogrenciOut)
{
	out << "Adi: ";
	for (unsigned i = 0; i < ogrenciOut.adUzunlugu; ++i)
	{
		out << ogrenciOut.ad[i];
	}
	out << endl;
	for (unsigned i = 0; i < ogrenciOut.noUzunlugu; ++i)
	{
		out << ogrenciOut.no[i];
	}
	return out;
}
