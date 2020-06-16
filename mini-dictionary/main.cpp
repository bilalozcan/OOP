/*Bilal Özcan
 *18120205035
 *Mini sözlük classý oluþturma*/
#include<iostream>
#include"Kayit.h"
using namespace std;

int main()
{
	Kayit a("asdfg", "b");
	vector<string> aciklamaB = { "b","Bitis", "E","Vize" };
	Kayit b("asdfg", aciklamaB);
	Kayit c = a + b;
	cout << c << endl;
	cout << a << endl;
	cout << b << endl;

	//Kayit a("Vize", "Ara sinav"); //Bir Kelime ve o kelimeye ait bir açýklama alan obje oluþturma
	//vector<string> aciklamaB = { "Bir isin sonu","Donem sonu sinavi","Bitis", "Elemeli yarismalarda sonucu belirten karsilasma","Vize" };
	//Kayit b("Final", aciklamaB); //Bir Kelime ve o kelimeye ait açýklamalar alan obje oluþturma
	//cout << "a objesi verileri:" << endl;
	//cout << a << endl;
	//cout << "b objesi verileri:" << endl;
	//cout << b << endl;
	//Kayit c; //Cin ile veri alacaðýmýz obje.
	//cout << "Lutfen once kelimeyi girip Enter'a basiniz.\nDaha sonra aciklamalari satir satir girip herbir aciklamadan sonra tekrar ";
	//cout << "Enter'a basiniz. \nAciklamalar bittiginde bos satirda tekrar enter'a basiniz: " << endl;
	//cout << "Lutfen kelimeyi ve aciklamalarini giriniz" << endl;
	//cin >> c;
	//cout << c << endl;
	//if (a == b) //== operatorunun kontrol edilmesi
	//	cout << "a ile b ayni kelimedir veya es anlamlidir." << endl;
	//if (a == "Vize") //== operatorunun kontrol edilmesi
	//	cout << "a ile vize kelimesi ayni kelimedir veya es anlamlidirlar." << endl;
	//Kayit d;
	//if (!d) //! operatorunun kontrol edilmesi
	//	cout << "d objesi bostur" << endl;
	//vector<string> test1Aciklama = { "aciklama1","aciklama2","aciklama3","aciklama51","aciklama35","aciklama36","aciklama4" };
	//vector<string> test2Aciklama = { "aciklama37","aciklama38","aciklama51","aciklama52","aciklama5","aciklama6","aciklama1" };
	//Kayit test1("kelime",test1Aciklama), test2("kelime",test2Aciklama);
	//cout << "test1:\n" << test1 << endl;
	//cout << "test2:\n" << test2 << endl;
	//string x = "aciklamaEklenen";
	//string y = "aciklama37";
	//test1 + x; // + operatorunun kontrol edilmesi
	//cout << "test1 objesine aciklamaEklenen diye aciklama eklendi.test1: \n" << test1 << endl;
	//test2 - y; // - operatorunun kontrol edilmesi
	//cout << "test2 objesinden aciklama37 cikartildi. test2: \n" << test2 << endl;
	//cout << "test1+test2" << test1+test2 << endl; // + operatorunun kontrol edilmesi
	return 0;
}