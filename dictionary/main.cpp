#include <iostream>
#include"BuyukSozluk.h"
#include"Kayit.h"
#include<vector>
using namespace std;
//Copy Consturcterýn çalýþmasýný kontrol eden fonskýyon.
void ttt(Sozluk a)
{
	
}
int main()
{
	vector<string> aciklama = { "a1","a2","a3","a4","a5" };
	Kayit k1("kelime", aciklama);
	vector<string> aciklama2 = { "a1","a2","a3","a6","a7" };
	Kayit k2("kelime", aciklama2);
	vector<string> aciklama3 = { "a7","a8","a9" };
	Kayit k3("kelime", aciklama3);
	vector<string> aciklama4 = { "asds","sdfsa","asdfsdf","sdafsdf" };
	Kayit k4("kelime55552", aciklama4);
	vector<Kayit> kayitt;
	kayitt.push_back(k1);
	kayitt.push_back(k2);
	kayitt.push_back(k3);
	kayitt.push_back(k4);
	vector<string> aciklamaD = { "ac1","ac2","ac3","ac4" };
	Kayit d1("elma", aciklamaD);
	vector<string> aciklamaD2 = { "ac4","ac6","fjdashjf","ac8","ac7" };
	Kayit d2("elma", aciklamaD2);
	vector<string> aciklamaD3 = { "ac7","ac8","ac9" };
	Kayit d3("kelime", aciklamaD3);
	vector<string> aciklamaD4 = { "asds","sdfsa","asdfsdf","sdafsdf" };
	Kayit d4("armut", aciklamaD4);
	vector<Kayit> kayitt2;
	kayitt2.push_back(d1);
	kayitt2.push_back(d2);
	kayitt2.push_back(d3);
	kayitt2.push_back(d4);
	Sozluk a(k1); //Tek bir kayit alan sozluk
	Sozluk b; // Boþ Sozluk
	Sozluk c(kayitt), d(kayitt2); //Kayýt vectoru alan sozlukler
	cout << a << endl;
	cout << b << endl;
	b = a; // Assigment operatorunun test edilmesi
	cout << b << endl;
	ttt(a); //Copy Consturcterýn çalýþmasýný kontrol eden fonskýyonun cagýrýlmasý.
	cout << c << endl;
	string ttttt = "kelime55552";
	cout << c[ttttt] << endl; // Subscript operatounun calýþmasýnýn kontrol edilmesi

	// ==, !=, >, <, <=, >= operatorlerinin tamamýnýn kontrol edilmesi
	if (a == c)
		cout << "a ve c nin aciklama sayilari esittir" << endl;
	else
		cout << "a ve c nin aciklama sayilari esit degildir" << endl;
	if (a != c)
		cout << "a ve c nin aciklama sayilari esit degildir" << endl;
	else
		cout << "a ve c nin aciklama sayilari esittir" << endl;
	if (a > c)
		cout << "a nin aciklama sayisi b nin aciklama saysisindan buyuktur" << endl;
	else
		cout << "a nin aciklama sayisi b nin aciklama saysisindan buyuk degildir" << endl;
	if (a < c)
		cout << "a nin aciklama sayisi b nin aciklama saysisindan kucuktur" << endl;
	else
		cout << "a nin aciklama sayisi b nin aciklama saysisindan kucuk degildir" << endl;
	if (a >= c)
		cout << "a nin aciklama sayisi b nin aciklama saysisindan buyuk esittir" << endl;
	else
		cout << "a nin aciklama sayisi b nin aciklama saysisindan buyuk esit degildir" << endl;
	if (a <= c)
		cout << "a nin aciklama sayisi b nin aciklama saysisindan kucuk esittir" << endl;
	else
		cout << "a nin aciklama sayisi b nin aciklama saysisindan kucuk esit degildir" << endl;

	cout << d << endl;

	
	Sozluk okunan;
	ofstream output; // Dosyaya Yazma
	output.open("dosyayaYazma.txt");
	output << c;
	output.close();
	ifstream input; // Dosyadan okuma

	input.open("dosyadanOkuma.txt");
	input >> okunan;
	cout << okunan;
	input.close();

	c -= k4; // kayit alan -= operatorunun test edilmesi
	cout << c << endl;
	c -= k4; // kayit alan -= operatorunun test edilmesi
	cout << c << endl;
	c -= "kelime"; // string alan -= operatorunun test edilmesi
	cout << c << endl;

	vector<string> agacA1 = { "A1","A2","A3" };
	Kayit kk1("agac", agacA1);
	vector<string> agacA2 = { "A4","A5","A7" };
	Kayit kk2("agac", agacA2);
	vector<Kayit> toplamak;
	toplamak.push_back(kk1);
	toplamak.push_back(kk2);
	Sozluk SozlukAgac(toplamak);
	vector<string> pcA1 = { "pcA1","pcA2","pcA3" };
	Kayit pc1("pc", pcA1);
	vector<string> pcA2 = { "pcA8","pcA9","pcA3" };
	Kayit pc2("pc", pcA2);
	vector<Kayit> pckayit;
	pckayit.push_back(pc1);
	pckayit.push_back(pc2);
	Sozluk sozlukPc(pckayit);

	cout << "# # # # # #" << endl;
	cout << SozlukAgac + sozlukPc << endl;

	return 0;
}