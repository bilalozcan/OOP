/*Bilal OZCAN
 *18120205035
 *Uzun Yol Odevi 
 *Polimorfizm calismasi
 *Exception Handling Yapilmai
 *XML Parser kullanimi
 */
#include "odev8.h"
//Arac Default Constructer
Arac::Arac()
{
	plaka = nullptr;
	plakaUzunluk = 0;
}
//Arac Yapici Constructer
Arac::Arac(string plaka, list<Surucu>& suruculer)
{
	plakaUzunluk = plaka.size();
	this->plaka = new char[plakaUzunluk];
	if (this->plaka == nullptr)
		throw ExceptionHandlingTestClass();
	for (unsigned i = 0; i < plakaUzunluk; ++i)
		this->plaka[i] = plaka[i];
	for (list<Surucu>::iterator itr = suruculer.begin();
		itr != suruculer.end(); ++itr)
		this->suruculer.push_back(*itr);
}
//Arac Destructer
Arac::~Arac()
{
	if (plaka != nullptr)
		delete[] plaka;
}
//Arac Copy Constructer
Arac::Arac(Arac& copyArac)
{
	plakaUzunluk = copyArac.plakaUzunluk;
	for (list<Surucu>::iterator itr = copyArac.suruculer.begin();
		itr != copyArac.suruculer.end(); ++itr)
		this->suruculer.push_back(*itr);
	plaka = nullptr;
	plaka = new char[plakaUzunluk];
	if (this->plaka == nullptr)
		throw ExceptionHandlingTestClass();
	for (unsigned i = 0; i < plakaUzunluk; ++i)
		plaka[i] = copyArac.plaka[i];

}
//Arac Assigment Operator
Arac& Arac::operator=(Arac& assigmntArac)
{
	if (&assigmntArac == this)
		return *this;
	plaka = nullptr;
	plakaUzunluk = assigmntArac.plakaUzunluk;
	plaka = new char[plakaUzunluk];
	if (plaka == nullptr)
		throw ExceptionHandlingTestClass();
	for (unsigned i = 0; i < plakaUzunluk; ++i)
		plaka[i] = assigmntArac.plaka[i];
	suruculer.clear();
	for (list<Surucu>::iterator itr = assigmntArac.suruculer.begin();
		itr != assigmntArac.suruculer.end(); ++itr)
		suruculer.push_back(*itr);
	return *this;
}
//Aracin plakasini donderen getter
char* Arac::getPlaka()
{
	return plaka;
}
//Aracin plakasini set eden setter
void Arac::setPlaka(string plaka)
{
	plakaUzunluk = plaka.size();
	this->plaka = nullptr;
	this->plaka = new char[plakaUzunluk];
	if (this->plaka == nullptr)
		throw ExceptionHandlingTestClass();
	for (unsigned i = 0; i < plakaUzunluk; ++i)
		this->plaka[i] = plaka[i];
}
//Aracin plakasini uzunlugunu d�nderen getter
unsigned int Arac::getPlakaUzunluk()
{
	return plakaUzunluk;
}
//Aracin suruculerini tutan listi d�nderen getter
list<Surucu>& Arac::getSuruculer()
{
	return suruculer;
}
//Aracin suruculerine ekleme cikarma yapmamizi saglayan setter
void Arac::setSuruculer(list<Surucu> suruculerSet)
{
	suruculer.clear();
	for (list<Surucu>::iterator itr = suruculerSet.begin();
		itr != suruculerSet.end(); ++itr)
		suruculer.push_back(*itr);
}
//Aracin bilgilerini yazmamizi saglayan VIRTUAL (polimorfizmi gerceklestiren) print fonksiyonu
void Arac::Print(ostream& out)
{
	out << "ARACIN PLAKASI: ";
	for (unsigned int i = 0; i < plakaUzunluk; ++i)
		out << plaka[i];
	out << endl << "SURUCULER" << endl << endl;
	int sayi = 1;
	for (list<Surucu>::iterator itr = this->suruculer.begin();
		itr != suruculer.end(); ++itr)
		out << sayi++ << ". SURUCU" << endl << *itr;
}
//Aracin bilgilerini yazdiran << operatorunun overloadi
ostream& operator<<(ostream& out, Arac& outArac)
{
	outArac.Print(out);
	return out;
}
//Yolculari yazdiran << operator overloadi
ostream& operator<<(ostream& out, Yolcu& outYolcu)
{
	out << "YOLCU ADI: ";
	for (unsigned int i = 0; i < outYolcu.adUzunluk; ++i)
		out << outYolcu.ad[i];
	out << endl << "BINIS NOKTASI: "; 
	for (unsigned int i = 0; i < outYolcu.binisNoktasiUzunluk; ++i)
		out << outYolcu.binisNoktasi[i];
	out << endl << "INIS NOKTASI: " << outYolcu.inisNoktasi << endl << endl;
	return out;
}
//Yukleri yazdiran << operator overload
ostream& operator<<(ostream& out, Yuk& outYuk)
{
	out << "YUK ICERIGI: ";
	for (unsigned int i = 0; i < outYuk.icerikUzunluk; ++i)
		out << outYuk.icerik[i];
	out << endl << "YUK AGIRLIGI: " << outYuk.agirlik << endl;
	out << "YUK HACMI : " << outYuk.hacim << endl;
	out << "ALICI: " << outYuk.alici << endl;
	out << "BINIS NOKTASI: " << outYuk.binisNoktasi << endl;
	out << "INIS NOKTASI: " << outYuk.inisNoktasi << endl << endl;
	return out;
}
//Otobus bilgilerini yazdiran (suruculuer , yolcular, plaka vs.) << operator overload
ostream& operator<<(ostream& out, Otobus& outOtobus)
{
	outOtobus.Print(out);
	return out;
}

//Kamyon bilgilerini yazdiran (suruculuer , yolcular, plaka vs.) << operator overload
ostream& operator<<(ostream& out, Kamyon& outKamyon)
{
	outKamyon.Print(out);
	return out;
}
//Surucu bilgilerini yazdiran << operator overload
ostream& operator<<(ostream& out, const Surucu& outSurucu)
{
	out << "SURUCU ADI: ";
	for (unsigned int i = 0; i < outSurucu.adUzunluk; ++i)
		out << outSurucu.ad[i];
	out << endl << "SURUCU YASI: " << outSurucu.yas << endl;
	out << "SURUCU EHLIYET TURU: " << static_cast<char>('B' + outSurucu.ehliyet) << endl << endl;
	return out;
}
//Surucu Default Constructer
Surucu::Surucu()
{
	ad = nullptr;
	adUzunluk = 0; 
}
//Surucu Yapici Constructer
Surucu::Surucu(const string ad, unsigned int yas, string ehliyet)
{
	adUzunluk = ad.size();
	this->ad = new char[adUzunluk];
	if (this->ad == nullptr)
		throw ExceptionHandlingTestClass();
	for (unsigned i = 0; i < adUzunluk; ++i)
		this->ad[i] = ad[i];
	bitFieldYas = yas;
	this->yas = bitFieldYas + 32;
	if (ehliyet == "B")
		this->ehliyet = EhliyetTuru::B;
	else if (ehliyet == "C")
		this->ehliyet = EhliyetTuru::C;
	else if (ehliyet == "D")
		this->ehliyet = EhliyetTuru::D;
	else if (ehliyet == "E")
		this->ehliyet = EhliyetTuru::E;

}

//Surucu Destructer
Surucu::~Surucu()
{
	if (ad != nullptr)
		delete[] ad;
}

//Surucu Copy Constructer
Surucu::Surucu(const Surucu& copySurucu)
{
	adUzunluk = copySurucu.adUzunluk;
	yas = copySurucu.yas;
	ehliyet = copySurucu.ehliyet;
	ad = new char[adUzunluk];
	if (ad == nullptr)
		throw ExceptionHandlingTestClass();
	for (unsigned int i = 0; i < adUzunluk; ++i)
		ad[i] = copySurucu.ad[i];
}

//Surucu Assigment Operator
Surucu& Surucu::operator=(Surucu& assigmntSurucu)
{
	if (&assigmntSurucu == this)
		return *this;
	adUzunluk = assigmntSurucu.adUzunluk;
	yas = assigmntSurucu.yas;
	ehliyet = assigmntSurucu.ehliyet;
	ad = new char[adUzunluk];
	if (ad == nullptr)
		throw ExceptionHandlingTestClass();
	for (unsigned int i = 0; i < adUzunluk; ++i)
		ad[i] = assigmntSurucu.ad[i];
	return *this;
}
//Surucu adini donderen getter 
char* Surucu::getAd()
{
	return ad;
}
//Surucu adini degsitiren setter 
void Surucu::setAd(string& ad)
{
	this->ad = nullptr;
	adUzunluk = ad.size();
	this->ad = new char[adUzunluk];
	if (this->ad == nullptr)
		throw ExceptionHandlingTestClass();
	for (unsigned int i = 0; i < adUzunluk; ++i)
		this->ad[i] = ad[i];
}
//Surucu yasini donderen getter
unsigned int Surucu::getYas()
{
	return yas;
}
//Surucu yasini degistiren setter
void Surucu::setYas(unsigned int yas)
{
	this->yas = yas;
}
//Surucu ehliyet turunu donderen getter
EhliyetTuru Surucu::getEhliyet()
{
	return ehliyet;
}
//Surucu ehliyet turunu degistiren setter
void Surucu::setEhliyet(EhliyetTuru& ehliyet)
{
	this->ehliyet = ehliyet;
}

//Yolcu Default Constructer
Yolcu::Yolcu()
{
	ad = nullptr;
	binisNoktasi = nullptr;
	adUzunluk = 0;
	binisNoktasiUzunluk = 0;
	inisNoktasi = " ";
}

//Yolcu Yapici Constructer
Yolcu::Yolcu(string adii, string binisNoktasi, string inisNoktasi)
{
	adUzunluk = adii.size();
	binisNoktasiUzunluk = binisNoktasi.size();
	this->ad = new char[adUzunluk];
	this->binisNoktasi = new char[binisNoktasiUzunluk];
	if (this->ad == nullptr)
		throw ExceptionHandlingTestClass();
	if (this->binisNoktasi == nullptr)
		throw ExceptionHandlingTestClass();
	this->inisNoktasi = inisNoktasi;
	for (unsigned int i = 0; i < adUzunluk; ++i)
		this->ad[i] = adii[i];
	for (unsigned int i = 0; i < binisNoktasiUzunluk; ++i)
		this->binisNoktasi[i] = binisNoktasi[i];
}


//Yolcu Destructer
Yolcu::~Yolcu()
{
	if (ad != nullptr)
		delete[] ad;
	if (binisNoktasi != nullptr)
		delete[] binisNoktasi;
}

//Yolcu Copy Constructer
Yolcu::Yolcu(const Yolcu& copyYolcu)
{
	adUzunluk = copyYolcu.adUzunluk;
	binisNoktasiUzunluk = copyYolcu.binisNoktasiUzunluk;
	inisNoktasi = copyYolcu.inisNoktasi;
	this->ad = new char[adUzunluk];
	if (this->ad == nullptr)
		throw ExceptionHandlingTestClass();
	this->binisNoktasi = new char[binisNoktasiUzunluk];
	if (this->binisNoktasi == nullptr)
		throw ExceptionHandlingTestClass();
	this->inisNoktasi = inisNoktasi;
	for (unsigned int i = 0; i < adUzunluk; ++i)
		this->ad[i] = copyYolcu.ad[i];
	for (unsigned int i = 0; i < binisNoktasiUzunluk; ++i)
		this->binisNoktasi[i] = copyYolcu.binisNoktasi[i];
}



//Yolcu Assigment Operator
Yolcu& Yolcu::operator=(Yolcu& assigmntYolcu)
{
	if (&assigmntYolcu == this)
		return *this;
	adUzunluk = assigmntYolcu.adUzunluk;
	binisNoktasiUzunluk = assigmntYolcu.binisNoktasiUzunluk;
	inisNoktasi = assigmntYolcu.inisNoktasi;
	this->ad = new char[adUzunluk];
	this->binisNoktasi = new char[binisNoktasiUzunluk];
	if (this->ad == nullptr)
		throw ExceptionHandlingTestClass();
	if (this->binisNoktasi == nullptr)
		throw ExceptionHandlingTestClass();
	this->inisNoktasi = inisNoktasi;
	for (unsigned int i = 0; i < adUzunluk; ++i)
		this->ad[i] = assigmntYolcu.ad[i];
	for (unsigned int i = 0; i < binisNoktasiUzunluk; ++i)
		this->binisNoktasi[i] = assigmntYolcu.binisNoktasi[i];
	return *this;
}
//Yolcu adini donderen getter
char* Yolcu::getAd()
{
	return ad;
}
//Yolcu adini degistiren setter
void Yolcu::setAd(string& ad)
{
	this->adUzunluk = ad.size();
	this->ad = new char[adUzunluk];
	if (this->ad == nullptr)
		throw ExceptionHandlingTestClass();
	for (unsigned int i = 0; i < adUzunluk; ++i)
		this->ad[i] = ad[i];
}
//Yolcu binis noktasini donderen getter
char* Yolcu::getBinisNoktasi()
{
	return binisNoktasi;
}
//Yolcu binis noktasini degistiren setter
void Yolcu::setBinisNoktasi(string& binisNoktasi)
{
	binisNoktasiUzunluk = binisNoktasi.size();
	this->binisNoktasi = new char[binisNoktasiUzunluk];
	if (this->binisNoktasi == nullptr)
		throw ExceptionHandlingTestClass();
	for (unsigned int i = 0; i < binisNoktasiUzunluk; ++i)
		this->binisNoktasi[i] = binisNoktasi[i];
}

//Yolcu inis noktasini donderen getter
string Yolcu::getInisNoktasi()
{
	return inisNoktasi;
}

//Yolcu inis noktasini degistiren setter
void Yolcu::setInisNoktasi(string& InisNoktasi)
{
	this->inisNoktasi = InisNoktasi;
}

//Yuk Default Constructer
Yuk::Yuk()
{
	icerik = nullptr;
	icerikUzunluk = 0;
	agirlik = 0;
	hacim = 0;
	alici = " ";
	binisNoktasi = " ";
	inisNoktasi = " ";
}

//Yuk Yapici Constructer
Yuk::Yuk(string icerik, double agirlik, double hacim, string alici, string binisNoktasi, string inisNoktasi)
{
	icerikUzunluk = icerik.size();
	this->agirlik = agirlik;
	this->hacim = hacim;
	this->alici = alici;
	this->binisNoktasi = binisNoktasi;
	this->inisNoktasi = inisNoktasi;
	this->icerik = new char[icerikUzunluk];
	if (this->icerik == nullptr)
		throw ExceptionHandlingTestClass();
	for (unsigned int i = 0; i < icerikUzunluk; ++i)
		this->icerik[i] = icerik[i];
}

//Yuk Destructer
Yuk::~Yuk()
{
	if (icerik != nullptr)
		delete[] icerik; 
}

//Yuk Copy Constructer
Yuk::Yuk(const Yuk& copyYuk)
{
	icerikUzunluk = copyYuk.icerikUzunluk;
	this->agirlik = copyYuk.agirlik;
	this->hacim = copyYuk.hacim;
	this->alici = copyYuk.alici;
	this->binisNoktasi = copyYuk.binisNoktasi;
	this->inisNoktasi = copyYuk.inisNoktasi;
	icerik = new char[icerikUzunluk];
	if (this->icerik == nullptr)
		throw ExceptionHandlingTestClass();
	for (unsigned int i = 0; i < icerikUzunluk; ++i)
		this->icerik[i] = copyYuk.icerik[i];
}

//Yuk Assigment Operator
Yuk& Yuk::operator=(Yuk& assigmntYuk)
{
	if (&assigmntYuk == this)
		return* this;
	icerikUzunluk = assigmntYuk.icerikUzunluk;
	this->agirlik = assigmntYuk.agirlik;
	this->hacim = assigmntYuk.hacim;
	this->alici = assigmntYuk.alici;
	this->binisNoktasi = assigmntYuk.binisNoktasi;
	this->inisNoktasi = assigmntYuk.inisNoktasi;
	icerik = new char[icerikUzunluk];
	if (this->icerik == nullptr)
		throw ExceptionHandlingTestClass();
	for (unsigned int i = 0; i < icerikUzunluk; ++i)
		this->icerik[i] = assigmntYuk.icerik[i];
	return *this;
}
//Yuk icerigini donderen getter
char* Yuk::getIcerik()
{
	return icerik;
}
//Yuk icerigini degistiren setter
void Yuk::setIcerik(string& icerik)
{
	icerikUzunluk = icerik.size();
	this->icerik = nullptr;
	this->icerik = new char[icerikUzunluk];
	if (this->icerik == nullptr)
		throw ExceptionHandlingTestClass();
	for (unsigned int i = 0; i < icerikUzunluk; ++i)
		this->icerik[i] = icerik[i];
}

//Yuk agirligini donderen getter
double Yuk::getAgirlik()
{
	return agirlik;
}
//Yuk agirligini desistiren setter
void Yuk::setAgirlik(double& agirlik)
{
	this->agirlik = agirlik;
}

//Yuk hacmini donderen getter
double Yuk::getHacim()
{
	return hacim;
}

//Yuk hacmini degistiren setter
void Yuk::setHacim(double& hacim)
{
	this->hacim = hacim;
}
//Yuk alicisini donderen getter
string Yuk::getAlici()
{
	return alici;
}

//Yuk alicisini degistiren setter
void Yuk::setAlici(string& alici)
{
	this->alici = alici;
}

//Yukun binis noktasini donderen getter
string Yuk::getBinisNoktasi()
{
	return binisNoktasi;
}

//Yukun binis noktasini degistiren setter
void Yuk::setBinisNoktasi(string& BinisNoktasi)
{
	this->binisNoktasi = BinisNoktasi;
}

//Yukun inis noktasini donderen getter
string Yuk::getInisNoktasi()
{
	return inisNoktasi;
}

//Yukun inis noktasini degistiren setter
void Yuk::setInisNoktasi(string& InisNoktasi)
{
	this->inisNoktasi = InisNoktasi;
}

//Otobus Default Constructer
Otobus::Otobus() : Arac(){}

//Otobus Yapici Constructer
Otobus::Otobus(string plaka, list<Surucu> suruculer, vector<Yolcu> yolcular)
	:Arac(plaka, suruculer)
{
	this->yolcular = yolcular;
}

//Otobus Destructer
Otobus::~Otobus(){}

//Otobusun yolcularini tutan vectoru donderen getter
vector<Yolcu> Otobus::getYolcular()
{
	return yolcular;
}

//Otobusun yolcularini tutan vectoru degistirip ekleme cikarma yapilmasini saglayan setter
void Otobus::setYolcular(vector<Yolcu>& yolcular)
{
	this->yolcular = yolcular;
}

//Otobusun bilgilerini yazdiran polimorfizmi saglayan yazdirma fonksiyonu
void Otobus::Print(ostream& out)
{
	Arac::Print(out);
	out << "ARAC TURU: Otobus" << endl << endl;
	out << "YOLCULAR" << endl << endl;
	int sayi = 1; //Kacinci Yolcu oldugunu tutan degisken
	for (unsigned int i = 0; i < yolcular.size(); ++i)
		out << sayi++ << ".YOLCU:" << endl << yolcular[i];
}

//Kamyon Default Constructer
Kamyon::Kamyon()
{
	ozluSoz = nullptr;
	ozluSozUzunluk = 0;
}

//Kamyon Yapici Constructer
Kamyon::Kamyon(string plaka, list<Surucu>& suruculer,string ozluSoz, vector<Yuk>& yukler)
	:Arac(plaka, suruculer)
{
	ozluSozUzunluk = ozluSoz.size();
	this->ozluSoz = new char[ozluSozUzunluk];
	if (this->ozluSoz == nullptr)
		throw ExceptionHandlingTestClass();
	for (unsigned int i = 0; i < ozluSozUzunluk; ++i)
		this->ozluSoz[i] = ozluSoz[i];
	this->yukler = yukler;
}

//Kamyon Destructer
Kamyon::~Kamyon()
{
	delete[] ozluSoz;
}

//Kamyon Copy Constructer
Kamyon::Kamyon(Kamyon& copyKamyon)
{
	ozluSozUzunluk = copyKamyon.ozluSozUzunluk;
	this->ozluSoz = new char[ozluSozUzunluk];
	if (this->ozluSoz == nullptr)
		throw ExceptionHandlingTestClass();
	for (unsigned int i = 0; i < ozluSozUzunluk; ++i)
		this->ozluSoz[i] = copyKamyon.ozluSoz[i];
	this->yukler = copyKamyon.yukler;
}

//Kamyon Assigment Operator
Kamyon& Kamyon::operator=(Kamyon& assigmntKamyon)
{
	if (this == &assigmntKamyon)
		return *this;
	delete[] this->ozluSoz;
	ozluSozUzunluk = assigmntKamyon.ozluSozUzunluk;
	this->ozluSoz = new char[ozluSozUzunluk];
	if (this->ozluSoz == nullptr)
		throw ExceptionHandlingTestClass();
	for (unsigned int i = 0; i < ozluSozUzunluk; ++i)
		this->ozluSoz[i] = assigmntKamyon.ozluSoz[i];
	this->yukler = assigmntKamyon.yukler;
	return *this;
}

//Kamyonun ozlu sozunu donderen getter
char* Kamyon::getOzluSoz()
{
	return ozluSoz;
}

//Kamyonun ozlu sozunu degistiren setter
void Kamyon::setOzluSoz(string& ozluSoz)
{
	delete[] this->ozluSoz;
	ozluSozUzunluk = ozluSoz.size();
	this->ozluSoz = new char[ozluSozUzunluk];
	if (this->ozluSoz == nullptr)
		throw ExceptionHandlingTestClass();
	for (unsigned int i = 0; i < ozluSozUzunluk; ++i)
		this->ozluSoz[i] = ozluSoz[i];
}

//Kamyonun yuklerini tutan vectoru donderen getter
vector<Yuk>& Kamyon::getYukler()
{
	return yukler;
}

//Kamyonun yuklerini tutan vectoru degistirip ekleme cikarma yapilmasini saglayan setter
void Kamyon::setYukler(vector<Yuk>& yukler)
{
	this->yukler = yukler;
}

//Kamyonun bilgilerini yazdiran polimorfizmi saglayan yazdirma fonksiyonu
void Kamyon::Print(ostream& out)
{
	Arac::Print(out);
	out << "ARAC TURU: Kamyon" << endl;
	out << "OZLU SOZ: ";
	for (unsigned int i = 0; i < ozluSozUzunluk; ++i)
		out << ozluSoz[i];
	out << endl << endl << "YUKLER" << endl << endl;
	int sayi = 1; //Kacinci Yuk oldugunu tutan degisken
	for (unsigned int i = 0; i < yukler.size(); ++i)
		out << sayi++ << ".YUK:" << endl << yukler[i];
}