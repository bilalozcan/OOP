/*Bilal OZCAN
 *18120205035
 *Uzun Yol Odevi 
 *Polimorfizm calismasi
 *Exception Handling Yapilmai
 *XML Parser kullanimi
 */
#pragma once
#include<list>
#include<iostream>
#include<vector>
using namespace std;
enum EhliyetTuru{ B, C, D, E };

class ExceptionHandlingTestClass {};
class Surucu
{
	friend ostream& operator <<(ostream& out, const Surucu& outSurucu);
public:
	Surucu();
	Surucu(const string ad, unsigned int yas, string ehliyet);
	~Surucu();
	Surucu(const Surucu& copySurucu);
	Surucu& operator =(Surucu& assigmntSurucu);
	char* getAd();
	void setAd(string& ad);
	unsigned int getYas();
	void setYas(unsigned int yas);
	EhliyetTuru getEhliyet();
	void setEhliyet(EhliyetTuru& ehliyet);

private:
	char* ad;
	unsigned int adUzunluk;
	unsigned int bitFieldYas : 5;
	unsigned int yas;
	EhliyetTuru ehliyet;
};
class Arac
{
	friend ostream& operator <<(ostream& out, Arac& outArac);
public:
	Arac();
	Arac(string plaka, list<Surucu>& suruculer);
	virtual ~Arac();
	Arac(Arac& copyArac);
	Arac& operator=(Arac& assigmntArac);
	char* getPlaka();
	void setPlaka(string plaka);
	unsigned int getPlakaUzunluk();
	list<Surucu>& getSuruculer();
	void setSuruculer(list<Surucu> suruculer);
	virtual void Print(ostream&out);
private:
	char* plaka;
	unsigned int plakaUzunluk;
	list<Surucu> suruculer;
};
class Yolcu 
{
	friend  ostream& operator <<(ostream& out, Yolcu& outYolcu);
public:
	Yolcu();
	Yolcu(string adii, string binisNoktasi, string inisNoktasi);
	~Yolcu();
	Yolcu(const Yolcu& copyYolcu);
	Yolcu& operator=(Yolcu& assigmntYolcu);
	char* getAd();
	void setAd(string& ad);
	char* getBinisNoktasi();
	void setBinisNoktasi(string& BinisNoktasi);
	string getInisNoktasi();
	void setInisNoktasi(string& InisNoktasi);
private:
	char* ad;
	unsigned int adUzunluk;
	char* binisNoktasi;
	unsigned int binisNoktasiUzunluk;
	string inisNoktasi;
};
class Yuk
{
	friend ostream& operator <<(ostream& out, Yuk& outYuk);
public:
	Yuk();
	Yuk(string icerik, double agirlik, double hacim, string alici, string binisNoktasi, string inisNoktasi);
	~Yuk();
	Yuk(const Yuk& copyYuk);
	Yuk& operator=(Yuk& assigmntYuk);
	char* getIcerik();
	void setIcerik(string& icerik);
	double getAgirlik();
	void setAgirlik(double& agirlik);
	double getHacim();
	void setHacim(double& hacim);
	string getAlici();
	void setAlici(string& alici);
	string getBinisNoktasi();
	void setBinisNoktasi(string& BinisNoktasi);
	string getInisNoktasi();
	void setInisNoktasi(string& InisNoktasi);
private:
	char* icerik;
	unsigned int icerikUzunluk;
	double agirlik;
	double hacim;
	string alici;
	string binisNoktasi;
	string inisNoktasi;
};
class Otobus : public Arac
{
	friend ostream& operator <<(ostream& out, Otobus& outOtobus);
public:
	Otobus();
	Otobus(string plaka, list<Surucu> suruculer, vector<Yolcu> yolcular);
	~Otobus();
	vector<Yolcu> getYolcular();
	void setYolcular(vector<Yolcu>& yolcular);
	void Print(ostream& out);
private:
	vector<Yolcu> yolcular;
};
class Kamyon : public Arac
{
	friend ostream& operator <<(ostream& out, Kamyon& outKamyon);
public:
	Kamyon();
	Kamyon(string plaka, list<Surucu>& suruculer, string ozluSoz, vector<Yuk>& yukler);
	~Kamyon();
	Kamyon(Kamyon& copyKamyon);
	Kamyon& operator=(Kamyon& assigmntKamyon);
	char* getOzluSoz();
	void setOzluSoz(string& ozluSoz);
	vector<Yuk>& getYukler();
	void setYukler(vector<Yuk>& yukler);
	void Print(ostream& out);
private:
	char* ozluSoz;
	unsigned int ozluSozUzunluk;
	vector<Yuk> yukler;
};