/*Bilal Özcan
 *18120205035
 *Mini sözlük classý oluþturma*/
#include "Kayit.h"
#include<iostream>
#include<vector>
#include<string>

//Bir kelime ve o kelimeye ait bir aciklama alan constructor.
Kayit::Kayit(const string & kelime, const string & aciklama)
{
	this->kelime = kelime;
	this->aciklama.push_back(aciklama);

}
//Bir kelime ve o kelimeye ait birden çok aciklama vectoru alan constructor.
Kayit::Kayit(const string & kelime, const vector<string>& aciklamalar)
{
	this->kelime = kelime;
	int vektorBoyutu = aciklamalar.size();
	for (int i = 0; i < vektorBoyutu; i++)
	{
		aciklama.push_back(aciklamalar[i]);
	}
}
// Kelime ve o kelimeye ait tum aciklamalari satir satir ekrana yazan << operatoruun asýrý yuklenmesi.
ostream & operator<<(ostream & outStream, const Kayit & kayit)
{
	int sizeV = kayit.aciklama.size();
	outStream << "Kelime: ";
	outStream << kayit.kelime << endl;
	outStream << "Aciklamalar: " << endl;
	for (int i = 1; i <= sizeV; i++)
	{
		outStream << i << ". ";
		outStream << kayit.aciklama[i - 1] << endl;
	}
	return outStream;

}
//Komut satýrýndan cin ile class a veri alan >> operatorunun asýrý yuklenmesi.
istream & operator>>(istream & inStream, Kayit & kayit)
{
	kayit.aciklama.clear();
	getline(inStream, kayit.kelime);
	string temp;
	
	while (1)
	{
		getline(inStream, temp);
		if (temp != "")
			kayit.aciklama.push_back(temp);
		else
			break;
	}

	return inStream;
}
//Ýki Kaydýn kelime deðerleri eþit ise aciklamalrýný birleþtiren + opratorunun asýrý yuklenmesi.
const Kayit & Kayit::operator+(const Kayit & digerKayit)
{
	int sizeThis = this->aciklama.size();
	int sizeDiger = digerKayit.aciklama.size();
	if (this->kelime == digerKayit.kelime)
	{
		for (int i = 0; i < sizeDiger; i++)
		{
			for (int j = 0; j < sizeThis; j++)
			{
				if (digerKayit.aciklama[i] == this->aciklama[j])
					break;
				else
				{
					if(j == (sizeThis-1))
						this->aciklama.push_back(digerKayit.aciklama[i]);
					continue;
				}
			}
		}
		return *this;
	}
	else return *this;
}
//O kayitta olmayan bir aciklamayi o kayida ekleyen + opratoru
const Kayit & Kayit::operator+(const string & aciklama)
{
	int sizeThis = this->aciklama.size();
	for (int i = 0; i < sizeThis; i++)
	{
		if (aciklama == this->aciklama[0])
			break;
		else
		{
			if (i == (sizeThis - 1))
				this->aciklama.push_back(aciklama);
			continue;
		}
	}
	return *this;
}
// o kayitta olan bir acýklamayý cýkaran - operatoru
const Kayit & Kayit::operator-(const string & aciklama)
{
	int sizeThis = this->aciklama.size();
	for (int i = 0; i < sizeThis; i++)
	{
		if (aciklama != this->aciklama[i]) 
			continue;
		
		else
		{
			this->aciklama.erase(this->aciklama.begin() + i);
			break;
		}
	}
	return *this;
}
//BÝr kaydýn boþ olup olmadýgýný kontrol eden ! operatoru.
bool Kayit::operator!()
{
	if ((this->kelime == "") || (this->aciklama.size() == 0) || (this->aciklama[0] == ""))
		return true;
	else
		return false;
}
//Ýki kaydýn kelimeleri aynýysa veya eþ anlamlýlar ise true döndüren == operatörü
bool Kayit::operator==(const Kayit & digerKayit)
{
	int value1 = 0;
	int value2 = 0;
	for (unsigned int i = 0; i < this->aciklama.size(); i++)
	{
		if (digerKayit.kelime == this->aciklama[i])
			value1++;

	}
	for (unsigned int i = 0; i < digerKayit.aciklama.size(); i++)
	{
		if (digerKayit.aciklama[i] == this->kelime)
			value2++;

	}
	if (this->kelime == digerKayit.kelime)
	{
		return true;
	}
	else if (value1 == 1)
		return true;
	else if (value2 == 1)
		return true;
	else
	return false;
}
//Kaydýn kelimesi ile verilen kelime aynýysa veya eþ anlamlýlar ise true döndüren == operatörü
bool Kayit::operator==(const string & digerKelime)
{
	int value1 = 0;
	for (unsigned int i = 0; i < this->aciklama.size(); i++)
	{
		if (digerKelime == this->aciklama[i])
			value1++;

	}
	
	if (this->kelime == digerKelime)
		return true;
	else if (value1 == 1)
		return true;
	else
		return false;
}


