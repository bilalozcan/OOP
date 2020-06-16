/*BİLAL ÖZCAN
 *Karmasik sayilarla islemler yapabilmemiz için operatörlerin aşırı yüklenmesi
 */

#include<iostream>
#include<vector>
#include<cstdlib>
#include"karmasik.h"

using namespace std;

int main()
{
	KarmasikSayi  a(5, 2),b(2,3),c,d; // Bazı karmaşık sayı değşkenleri
	vector<KarmasikSayi> KarmasikVektor; //Kullanıcın girdiği karmaşık sayıları tutan vektör
	vector<KarmasikSayi> enUzak(2); // En Uzak 2 Karmaşık sayıyı tutan vektör 
	int karmasiksayiAdedi; // Kullanıcının kaç adet karmaşık sayı gireceğini tutan değişken
	double uzaklıkdegeri; // En uzak 2 karmaşık sayı arası uzaklık
	char cevap;

	cout << "\n\tKarmasik Sayi Programina Hosgeldiniz" << endl << endl;
	cout << "Programa veri girisi yapilacaksa asagidaki sekilde giriniz:" << endl << endl;
	cout << "a + b i (Her bir karakter arasinda bir bosluk olacak sekilde!)" << endl;
	cout << "Ornek olarak 5 + 2 i seklinde." << endl << endl;
	cout << "DIKKAT!  Eger i nin katsayisi 1 ise 1 olarak giriniz. Ornek: 8 + 1 i" << endl;
	cout << "Programla ilgili bazi orneklere bakalim:" << endl;
	cout << "a sayisi: "<< a << endl;
	cout << "b sayisi: " << b << endl;
	cout << "a+b: " << a+b << endl;
	cout << "a+5: " << a + 5 << endl;
	cout << "5+b: " << 5 + b << endl;
	cout << "a-b:" << a - b << endl; 
	cout << "a-3:" << a - 3 << endl;
	cout << "3-a:" << 3 - a << endl;
	cout << "-b:" << - b << endl;
	cout << "a*b:" << a * b << endl;
	cout << "a*3:" << a * 3 << endl;
	cout << "2*b:" << 2 * b << endl;
	cout << "a/b:" << a / b << endl;
	cout << "a/2:" << a / 2 << endl;
	cout << "2/b:" << 2 / b << endl;
	if (a == b) cout << "a esittir b" << endl;
	else cout << "a esit degildir b" << endl;
	if (a != b) cout << "a esit degildir b" << endl;
	else cout << "a esittir b" << endl;
	if (a < b) cout << "a < b" << endl;
	else cout << "a < degildir b" << endl;
	if (a <= b) cout << "a <= b" << endl;
	else cout << "a <= degildir b" << endl;
	if (a > b) cout << "a > b" << endl;
	else cout << "a > degildir b" << endl;
	if (a >= b) cout << "a >= b" << endl;
	else cout << "a >= degildir b" << endl;	
	cout << "!a: " << !a << endl;
	cout << "++a: " << ++a << endl;
	cout << "--b: " << --b << endl;
	cout << "a^3: " << (a^3) << endl;
	cout << "a+=b: " << (a += b) << endl;
	cout << "a+=2: " << (a += 2) << endl;
	cout << "a-=b: " << (a -= b) << endl;
	cout << "b-=b: " << (b -= b) << endl;
	cout << "b-=2: " << (b -= 2) << endl;
	cout << "a*=b: " << (a *= b) << endl;
	cout << "a*=8: " << (a *= 8) << endl;
	cout << "a/=b: " << (a /= b) << endl;
	cout << "a/=10: " << (a /= 10) << endl;

	cout << "Evet Program ile ilgili orneklerimiz bu kadardi." << endl;
	cout << "Simdide siz karmasik sayi girisi yapmak ister misiniz? E/H giriniz >";
	cin >> cevap;
	if ((cevap == 'e') || (cevap == 'E')) // Kullanıcı veri girişi yapmak istiyor mu kontrol eden if yapısı
	{
		cout << "Lutfen kac adet karmasik sayi gireceginizi yaziniz >";
		cin >> karmasiksayiAdedi;
		for (int i = 0; i < karmasiksayiAdedi; i++) // Karmasık Sayıların vektöre yazılmasını sağlayan döngü
		{
			KarmasikSayi b;
			cout << "Sayiyi giriniz: " << endl;
			cin >> b;
			KarmasikVektor.push_back(b);
		}
		for (int i = 0; i < karmasiksayiAdedi; i++)
		{
			cout << KarmasikVektor[i] << endl;
		}
		cout << "Girilen karmasik sayilarin ortalamasi: " << ortalama(KarmasikVektor) << endl;
		enUzaklarıBulan(KarmasikVektor, enUzak, karmasiksayiAdedi, uzaklıkdegeri);
		cout << enUzak[0] << " ve " << enUzak[1] << " karmasik sayilari en uzak iki karmasik sayidir.";
		cout << " Aralarindaki uzaklik: " << uzaklıkdegeri << " dir." << endl;
	
	}
	else if((cevap == 'h') || (cevap == 'H'))
		cout << "Programimizi kullandiginiz icin tesekkur ederiz.";
	else cout << "Hatali giris! PROGRAM SONLANDI!!";

	return 0;
}
