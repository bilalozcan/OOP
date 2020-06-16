/*Bilal OZCAN
 *18120205035
 *Uzun Yol Odevi 
 *Polimorfizm calismasi
 *Exception Handling Yapilmai
 *XML Parser kullanimi
 */
#include<iostream>
#include"longWay.h"
#include"tinyxml2.cpp"
using namespace std;
using namespace tinyxml2;
//String olarak verilen agirlik ve hacmi (0-99 arasi) int ceviren yardimci fonksiyon
int cevirme(string no)
{
	int carpan = 10;
	int numara = 0;
	int temp;
	int sayilar[] = { 48, 49, 50, 51, 52, 53, 54, 55, 56, 57 };

	for (unsigned i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 10; ++j)
			if ((int)no[i] == sayilar[j])
				temp = j;
		numara += temp * carpan;
		carpan /= 10;
	}
	return numara;
}
//Xml dosyasindan Arac* tutan liste okuma yapan Fonksiyon
unsigned int dosyadanOku(const string& filename, list<Arac*>& araclar)
{
	unsigned int AracSayisi = 0;
	char* filenameChar = new char[filename.size()+1];
	if (filenameChar == nullptr)
		exit(-1);
	for (unsigned int i = 0; i < filename.size(); i++)
		filenameChar[i] = filename[i];
		filenameChar[filename.size()] = NULL;
	XMLDocument doc;
	doc.LoadFile(filenameChar);
	XMLElement* temp = doc.FirstChildElement("Araclar")->FirstChildElement("Arac");
	while (temp != NULL)
	{
		++AracSayisi;
		XMLElement* tempArac = temp->FirstChildElement("Turu");
		string AracTuru = tempArac->GetText();
		if (AracTuru == "Otobus")
		{
			string plakaO = tempArac->NextSiblingElement("Plaka")->GetText();
			XMLElement* tempSuruculer = tempArac->NextSiblingElement("Suruculer")->FirstChildElement("Surucu");
			list<Surucu> OtobusSuruculer;
			vector<Yolcu> OtobusYolcular;
			while (tempSuruculer != NULL)
			{
				XMLElement* tempSurucu = tempSuruculer->FirstChildElement("Adi");
				string SurucuAdi = tempSurucu->GetText();
				tempSurucu = tempSurucu->NextSiblingElement("Yasi");
				string SurucuYasi = tempSurucu->GetText();
				tempSurucu = tempSurucu->NextSiblingElement("EhliyetSinifi");
				string SurucuEhliyeti = tempSurucu->GetText();
				OtobusSuruculer.push_back(Surucu(SurucuAdi, cevirme(SurucuYasi), SurucuEhliyeti));
				tempSuruculer = tempSuruculer->NextSiblingElement("Surucu");
			}
			XMLElement* tempYolcular = tempArac->NextSiblingElement("Yolcular")->FirstChildElement("Yolcu");
			while (tempYolcular != NULL)
			{
				XMLElement* tempYolcu = tempYolcular->FirstChildElement("Adi");
				string YolcuAdi = tempYolcu->GetText();
				tempYolcu = tempYolcu->NextSiblingElement("BinisNoktasi");
				string YolcuBinisNoktasi = tempYolcu->GetText();
				tempYolcu = tempYolcu->NextSiblingElement("InisNoktasi");
				string YolcuInisNoktasi = tempYolcu->GetText();
				OtobusYolcular.push_back(Yolcu(YolcuAdi, YolcuBinisNoktasi, YolcuInisNoktasi));
				tempYolcular = tempYolcular->NextSiblingElement("Yolcu");
			}
			araclar.push_back(new Otobus(plakaO, OtobusSuruculer, OtobusYolcular));
		}
		if (AracTuru == "Kamyon")
		{
			string plakaK = tempArac->NextSiblingElement("Plaka")->GetText();
			string ozluSoz = tempArac->NextSiblingElement("OzluSoz")->GetText();
			XMLElement* tempSuruculer = tempArac->NextSiblingElement("Suruculer")->FirstChildElement("Surucu");
			list<Surucu> KamyonSuruculer;
			vector<Yuk> KamyonYukler;
			while (tempSuruculer != NULL)
			{
				XMLElement* tempSurucu = tempSuruculer->FirstChildElement("Adi");
				string SurucuAdi = tempSurucu->GetText();
				tempSurucu = tempSurucu->NextSiblingElement("Yasi");
				string SurucuYasi = tempSurucu->GetText();
				tempSurucu = tempSurucu->NextSiblingElement("EhliyetSinifi");
				string SurucuEhliyeti = tempSurucu->GetText();
				KamyonSuruculer.push_back(Surucu(SurucuAdi, cevirme(SurucuYasi), SurucuEhliyeti));
				tempSuruculer = tempSuruculer->NextSiblingElement("Surucu");
			}
			XMLElement* tempYukler = tempArac->NextSiblingElement("Yukler")->FirstChildElement("Yuk");
			while (tempYukler != NULL)
			{
				XMLElement* tempYuk = tempYukler->FirstChildElement("Icerik");
				string Icerik = tempYuk->GetText();
				tempYuk = tempYuk->NextSiblingElement("Agirlik");
				string Agirlik = tempYuk->GetText();
				tempYuk = tempYuk->NextSiblingElement("Hacim");
				string Hacim = tempYuk->GetText();
				tempYuk = tempYuk->NextSiblingElement("Alici");
				string Alici = tempYuk->GetText();
				tempYuk = tempYuk->NextSiblingElement("BinisNoktasi");
				string BinisNoktasi = tempYuk->GetText();
				tempYuk = tempYuk->NextSiblingElement("InisNoktasi");
				string InisNoktasi = tempYuk->GetText();
				KamyonYukler.push_back(Yuk(Icerik, cevirme(Agirlik),cevirme(Hacim), Alici, BinisNoktasi, InisNoktasi));
				tempYukler = tempYukler->NextSiblingElement("Yuk");
			}
			araclar.push_back(new Kamyon(plakaK, KamyonSuruculer, ozluSoz, KamyonYukler));
		}
		temp = temp->NextSiblingElement("Arac");
	}
	delete[] filenameChar;
	return AracSayisi;
}
int main()
{
	try
	{
		list<Arac*> araclar;
		int aracSayisi = dosyadanOku("bil122_hw08.xml", araclar);
		cout << "OKUNUN ARAC SAYISI: " << aracSayisi << endl;
		list <Arac* > ::iterator it;
		int i = 1; // //Kacinci arac oldugunu tutan degisken
		for (it = araclar.begin(); it != araclar.end(); ++it)
			cout << "- - - - - - - - - - - - " << i++
			<< ". ARAC - - - - - - - - - - - - - " << endl
			<< *(*it) << endl << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - "
			<< endl;

		//ARAC* UZERINDEN TUTULDUGU ICIN LIST UZERINDEN OTOBUS VE KAMYONUN FONKSIYONLARINA ERISILEMIYOR
		//ERISILENLER TEST EDILDI.
		list <Arac* > ::iterator itr;
		itr = araclar.begin();
		cout << "BIRINCI ARACIN PLAKASININ DEGISTIRILMESI " << endl;
		(*itr)->setPlaka("81DDD81");
		cout << *(*itr) << endl;
		++itr;


		cout << "IKINCI ARACIN SURUCULERININ SILINMESI" << endl;
		list<Surucu> bosSurucu;
		(*itr)->setSuruculer(bosSurucu);
		cout << *(*itr) << endl;
		++itr;
		cout << "UCUNCU ARACIN SURUCULERININ DEGISTIRILMESI" << endl;
		list<Surucu> digerSurucu;
		digerSurucu.push_back(Surucu("Adnan Sirma", 55, "C"));
		(*itr)->setSuruculer(digerSurucu);
		cout << *(*itr) << endl;

		for (it = araclar.begin(); it != araclar.end(); ++it)
			delete* it;
	}
	catch (ExceptionHandlingTestClass)
	{
		cout << "YER ALINAMADI" << endl;
	}
	return 0;
}
