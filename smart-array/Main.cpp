/*18120205035
 *Bilal ÖZCAN
 *Ödev9 template class çalýþmasý 
 *Ýnt için , Double Ýçin, Char Ýçin ve Ogrenci class ý için ve bunlaýrn dizi vector 
 *veya tek hali için butun fonksiyonlar asagýda denenmektedir*/
#include<iostream>
#include<vector>
#include"smartArray.h"
#include"smartArray.cpp"
using namespace std;

int main()
{
	try {
		cout << "# # # # # # # # # # # # # # # # int icin # # # # # # # # # # # # # # # #" << endl;
		int intDizi[] = { 51,52,53,54 };
		vector<int> intVector;
		for (int i = 2; i < 11; ++i)
			intVector.push_back(i);
		int x = 4;
		vector<Pair<int>> intPairVector;
		AkilliDizi<int> intAkilliDiziDefault;
		AkilliDizi<int> intAkilliDiziTek(51);
		AkilliDizi<int> intAkilliDiziDizi(intDizi, 4);
		AkilliDizi<int> intAkilliDiziVector(intVector);
		cout << "int default " << intAkilliDiziDefault << endl;
		cout << "int tek " << intAkilliDiziTek << endl;
		cout << "int dizi " << intAkilliDiziDizi << endl;
		cout << "int vector " << intAkilliDiziVector << endl;
		cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
		intAkilliDiziDizi.sirala();
		intAkilliDiziVector.sirala();
		cout << "Sirali int dizi " << intAkilliDiziDizi << endl;
		cout << "Sirali int vector " << intAkilliDiziVector << endl;
		cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
		intAkilliDiziDefault = intAkilliDiziVector;
		cout << "Atama operatoru kontrol (Defaulta vector atandi) " << intAkilliDiziDefault << endl;
		cout << "+ operatoru kontrol: int tek + 4 : " << intAkilliDiziTek + x << endl;
		cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
		cout << "int vector varMi(5): " << intAkilliDiziVector.varMi(5) << endl;
		cout << "int dizi kacTane(58): " << intAkilliDiziDizi.kacTane(58) << endl;
		cout << "int dizi nin 2 indexli elemani: " << intAkilliDiziDizi[2] << endl;
		cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
		cout << "int Vector un histogrami: " << endl;
		intAkilliDiziVector.histogram(intPairVector);
		for (unsigned int i = 0; i < intPairVector.size(); ++i)
		{
			cout << intPairVector[i].eleman << " dan/den " << intPairVector[i].adet << " tane var" << endl;
		}
		cout << "# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #" << endl;
		cout << "# # # # # # # # # # # # # # # # char icin # # # # # # # # # # # # # # # #" << endl;
		char charDizi[] = { "ABCDBBGHjiomnssfFdk" };
		vector<char> charVector;
		for (int i = 65; i < 94; ++i)
			charVector.push_back(char(i));
		charVector.push_back('A');
		charVector.push_back('B');
		charVector.push_back('Z');
		charVector.push_back('a');
		charVector.push_back('A');
		AkilliDizi<char> charAkilliDiziDefault;
		AkilliDizi<char> charAkilliDiziTek('G');
		AkilliDizi<char> charAkilliDiziDizi(charDizi, 19);
		AkilliDizi<char> charAkilliDiziVector(charVector);
		vector<Pair<char>> charPairDizi;
		vector<Pair<char>> charPairVector;
		cout << "Akilli Dizi Char Default: " << charAkilliDiziDefault << endl;
		cout << "Akilli Dizi Char Tek: " << charAkilliDiziTek << endl;
		cout << "Akilli Dizi Char Dizi: " << charAkilliDiziDizi << endl;
		cout << "Akilli Dizi Char Vector: " << charAkilliDiziVector << endl;
		cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
		charAkilliDiziDizi.sirala();
		charAkilliDiziVector.sirala();
		cout << "Sirali Akilli Dizi Char Dizi: " << charAkilliDiziDizi << endl;
		cout << "Sirali Akilli Dizi Char Vector: " << charAkilliDiziVector << endl;
		cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
		charAkilliDiziDefault = charAkilliDiziVector;
		cout << "Akilli Dizi Char Default'a Akilli Dizi Char Vector atandi: " << endl;
		cout << charAkilliDiziDefault << endl;
		cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
		cout << "charAkilliDiziVector + X + P : = " << charAkilliDiziVector + 'X' + 'P' << endl;
		cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
		cout << "charAkilliDiziVector de A varMi? " << charAkilliDiziVector.varMi('A') << endl;
		cout << "charAkilliDiziDizi de B kac tane? " << charAkilliDiziDizi.kacTane('B') << endl;
		cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
		cout << "charAkilliDiziDizi nin 8 indexli elemani: " << charAkilliDiziDizi[8] << endl;
		cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
		charAkilliDiziDizi.histogram(charPairDizi);
		cout << "charAkilliDiziDizi nin histogrami: " << endl;
		for (unsigned int i = 0; i < charPairDizi.size(); ++i)
		{
			cout << charPairDizi[i].eleman << " dan/den " << charPairDizi[i].adet << " tane var" << endl;
		}
		cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
		charAkilliDiziVector.histogram(charPairVector);
		cout << "charAkilliDiziVector un histogrami: " << endl;
		for (unsigned int i = 0; i < charPairVector.size(); ++i)
		{
			cout << charPairVector[i].eleman << " dan/den " << charPairVector[i].adet << " tane var" << endl;
		}
		cout << "# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #" << endl << endl;
		cout << "# # # # # # # # # # # # # # # # double icin # # # # # # # # # # # # # # # #" << endl;
		double doubleDizi[] = { 0.45, 1.89, 1.78, 7.56, 5.87, 14.65, 1.89 };
		vector<double> doubleVector;
		for (int i = 0; i < 15; ++i)
			doubleVector.push_back(double(i * 3 + (double)i / 8));
		AkilliDizi<double> doubleAkilliDiziDefault;
		AkilliDizi<double> doubleAkilliDiziTek(0.07);
		AkilliDizi<double> doubleAkilliDiziDizi(doubleDizi, 7);
		AkilliDizi<double> doubleAkilliDiziVector(doubleVector);
		vector<Pair<double>> doublePairDizi;
		vector<Pair<double>> doublePairVector;
		cout << "Akilli Dizi Double Default: " << doubleAkilliDiziDefault << endl;
		cout << "Akilli Dizi Double Tek: " << doubleAkilliDiziTek << endl;
		cout << "Akilli Dizi Double Dizi: " << doubleAkilliDiziDizi << endl;
		cout << "Akilli Dizi Double Vector: " << doubleAkilliDiziVector << endl;
		cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
		doubleAkilliDiziDizi.sirala();
		doubleAkilliDiziVector.sirala();
		cout << "Sirali Akilli Dizi Double Dizi: " << doubleAkilliDiziDizi << endl;
		cout << "Sirali Akilli Dizi Double Vector: " << doubleAkilliDiziVector << endl;
		cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
		doubleAkilliDiziDefault = doubleAkilliDiziVector;
		cout << "Akilli Dizi Double Default'a Akilli Dizi Double Vector atandi: " << endl;
		cout << doubleAkilliDiziDefault << endl;
		cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
		cout << "doubleAkilliDiziVector + 0.08 + 0.21 : = " << doubleAkilliDiziVector + 0.08 + 0.21 << endl;
		cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
		cout << "doubleAkilliDiziVector de 0.21 varMi? " << doubleAkilliDiziVector.varMi(0.21) << endl;
		cout << "doubleAkilliDiziDizi de 1.89 kac tane? " << doubleAkilliDiziDizi.kacTane(1.89) << endl;
		cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
		cout << "doubleAkilliDiziDizi nin 4 indexli elemani: " << doubleAkilliDiziDizi[4] << endl;
		cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
		doubleAkilliDiziDizi.histogram(doublePairDizi);
		cout << "doubleAkilliDiziDizi nin histogrami: " << endl;
		for (unsigned int i = 0; i < doublePairDizi.size(); ++i)
		{
			cout << doublePairDizi[i].eleman << " dan/den " << doublePairDizi[i].adet << " tane var" << endl;
		}
		cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
		doubleAkilliDiziVector.histogram(doublePairVector);
		cout << "doubleAkilliDiziVector un histogrami: " << endl;
		for (unsigned int i = 0; i < doublePairVector.size(); ++i)
		{
			cout << doublePairVector[i].eleman << " dan/den " << doublePairVector[i].adet << " tane var" << endl;
		}
		cout << "# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #" << endl << endl;

		cout << "# # # # # # # # # # # # # # # # double icin # # # # # # # # # # # # # # # #" << endl;

		Ogrenci ogrenciDizi[] = { Ogrenci("mehmet", "18120205036"),Ogrenci("bilal", "18120205035"),
		Ogrenci("mustafa", "18120205030"), Ogrenci("fatih", "18120205041") };
		vector<Ogrenci> ogrenciVector;
		ogrenciVector.push_back(Ogrenci("Ayse", "18120205014"));
		ogrenciVector.push_back(Ogrenci("Zeynep", "18120205058"));
		ogrenciVector.push_back(Ogrenci("Ali", "18120205074"));
		ogrenciVector.push_back(Ogrenci("Kasim", "18120205002"));
		ogrenciVector.push_back(Ogrenci("Huseyin", "18120205007"));
		ogrenciVector.push_back(Ogrenci("Ayse", "18120205014"));
		AkilliDizi<Ogrenci> ogrenciAkilliDiziDefault;
		AkilliDizi<Ogrenci> ogrenciAkilliDiziTek(Ogrenci("Ahmet", "18120205009"));
		AkilliDizi<Ogrenci> ogrenciAkilliDiziDizi(ogrenciDizi, 4);
		AkilliDizi<Ogrenci> ogrenciAkilliDiziVector(ogrenciVector);
		vector<Pair<Ogrenci>> ogrenciPairDizi;
		vector<Pair<Ogrenci>> ogrenciPairVector;
		cout << "Akilli Dizi Ogrenci Default: " << endl << ogrenciAkilliDiziDefault << endl;
		cout << "Akilli Dizi Ogrenci Tek: " << endl << ogrenciAkilliDiziTek << endl;
		cout << "Akilli Dizi Ogrenci Dizi: " << endl << ogrenciAkilliDiziDizi << endl;
		cout << "Akilli Dizi Ogrenci Vector: " << endl << ogrenciAkilliDiziVector << endl;
		cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
		ogrenciAkilliDiziDizi.sirala();
		ogrenciAkilliDiziVector.sirala();
		cout << "Sirali Akilli Dizi Ogrenci Dizi: " << endl << ogrenciAkilliDiziDizi << endl;
		cout << "Sirali Akilli Dizi Ogrenci Vector: " << endl << ogrenciAkilliDiziVector << endl;
		cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
		ogrenciAkilliDiziDefault = ogrenciAkilliDiziVector;
		cout << "Akilli Dizi Ogrenci Default'a Akilli Dizi Ogrenci Vector atandi: " << endl;
		cout << ogrenciAkilliDiziDefault << endl << endl;
		cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
		cout << "ogrenciAkilliDiziVector + Veli, 18120205025: = " << ogrenciAkilliDiziVector +
			Ogrenci("Veli", "18120205025") << endl;
		cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
		cout << "ogrenciAkilliDiziVector de 18120205025 varMi? "
			<< ogrenciAkilliDiziVector.varMi(Ogrenci("Veli", "18120205025")) << endl;
		cout << "ogrenciAkilliDiziDizi de 18120205035 kac tane? "
			<< ogrenciAkilliDiziDizi.kacTane(Ogrenci("bilal", "18120205035")) << endl;
		cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
		cout << "ogrenciAkilliDiziDizi nin 2 indexli elemani: " << ogrenciAkilliDiziDizi[2] << endl;
		cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
		ogrenciAkilliDiziDizi.histogram(ogrenciPairDizi);
		cout << "doubleAkilliDiziDizi nin histogrami: " << endl;
		for (unsigned int i = 0; i < ogrenciPairDizi.size(); ++i)
		{
			cout << ogrenciPairDizi[i].eleman << " dan/den " << ogrenciPairDizi[i].adet << " tane var" << endl;
		}
		cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
		ogrenciAkilliDiziVector.histogram(ogrenciPairVector);
		cout << "doubleAkilliDiziVector un histogrami: " << endl;
		for (unsigned int i = 0; i < ogrenciPairVector.size(); ++i)
		{
			cout << ogrenciPairVector[i].eleman << " dan/den " << ogrenciPairVector[i].adet << " tane var" << endl;
		}
		cout << "# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #" << endl << endl;
	}
	catch (ExpHandNoMemory)
	{
		cout << "YER ALINAMADI" << endl;
	}
	catch (ExpHandOverMemory)
	{
		cout << "HAFIZA ASILDI" << endl;
	}

	return 0;
}
