/*18120205035
 *Bilal �ZCAN
 *�dev9 template class �al��mas� */
#include"odev9.h"

/* bos bir akilli dizi olusturur*/
template<class T>
AkilliDizi<T>::AkilliDizi()
{
	veri = nullptr;
	elemanSayisi = 0;
	kapasite = 0;
}

/* tek elamanl� ve eleman degeri i olan bir akilli dizi olusturur*/
template<class T>
AkilliDizi<T>::AkilliDizi(T i)
{
	elemanSayisi = 1;
	kapasite = 1;
	veri = new T[1];
	if (veri == nullptr)
		throw ExpHandNoMemory();
	veri[0] = i;
	
}

/* elemanSayisi elamanli bir akilli dizi olusturur ve TDizi elamanlarini akilli diziye atar.*/
template<class T>
AkilliDizi<T>::AkilliDizi(const T* TDizi, unsigned int elemanSayisi)
{
	this->elemanSayisi = elemanSayisi;
	veri = new T[elemanSayisi];
	if (veri == nullptr)
		throw ExpHandNoMemory();
	for (unsigned i = 0; i < elemanSayisi; i++)
		veri[i] = TDizi[i];
}

/*vektoru akilli diziye donusturur.*/
template<class T>
AkilliDizi<T>::AkilliDizi(const vector<T>& TVector)
{
	elemanSayisi = TVector.size();
	veri = new T[elemanSayisi];
	if (veri == nullptr)
		throw ExpHandNoMemory();
	for (unsigned i = 0; i < elemanSayisi; i++)
		veri[i] = TVector[i];
}

//Destructer
template<class T>
AkilliDizi<T>::~AkilliDizi()
{
	if (veri != nullptr)
		delete [] veri;
}

//Copy Constructer
template<class T>
AkilliDizi<T>::AkilliDizi(const AkilliDizi<T>& copyT)
{
	elemanSayisi = copyT.elemanSayisi;
	kapasite = copyT.kapasite;
	veri = nullptr;
	if (elemanSayisi != 0)
	{
		veri = new T[elemanSayisi];
		if (veri == nullptr)
			throw ExpHandNoMemory();
		for (unsigned i = 0; i < elemanSayisi; i++)
			veri[i] = copy.veri[i];
	}
}

//assigmnet opart�r�n�n a��r� y�klenmesi
template<class T>
AkilliDizi<T>& AkilliDizi<T>::operator=(const AkilliDizi<T>& assigmentT)
{
	if (this == &assigmentT)
		return *this;
	if (veri != nullptr)
		delete[] veri;
	elemanSayisi = assigmentT.elemanSayisi;
	kapasite = assigmentT.kapasite;
	veri = new T[elemanSayisi];
	if (veri == nullptr)
		throw ExpHandNoMemory();
	for (unsigned i = 0; i < elemanSayisi; i++)
		veri[i] = assigmentT.veri[i];
	return *this;
}

/*Verilen indeks degerindeki eleman� d�nd�r�r. index elemanSayisindan buyukse hata mesaji yazdirir*/
template<class T>
T& AkilliDizi<T>::operator[](const unsigned int index)
{
	if (index > elemanSayisi)
	{
		throw ExpHandOverMemory();
	}
	return veri[index];
}

/*Verilen indeks degerindeki eleman� d�nd�r�r. index elemanSayisindan buyukse hata mesaji yazdirir*/
template<class T>
T AkilliDizi<T>::operator[](const unsigned int index) const
{
	if (index > elemanSayisi)
	{
		throw ExpHandOverMemory();
	}
	return veri[index];
}

/* AkilliDizi'ye bir T degeri ekleyebilenn + operat�r�*/
template<class T>
AkilliDizi<T>& AkilliDizi<T>::operator+(T i)
{
	elemanSayisi += 1;
	kapasite = kapasite+kapasite/2;
	T *temp  = veri;
	veri = nullptr;
	veri = new T[elemanSayisi];
	if (veri == nullptr)
		throw ExpHandNoMemory();
	for (unsigned i = 0; i < elemanSayisi - 1; i++)
		veri[i] = temp[i];
	veri[elemanSayisi - 1] = i;
	return *this;
}

/* diziyi buyukten kucuge siralar.*/
template<class T>
void AkilliDizi<T>::sirala() const
{
	T temp;
	for (unsigned int i = 0; i < elemanSayisi; ++i)
	{
		for (unsigned int j = i+1; j < elemanSayisi; ++j)
		{
			if (veri[j] > veri[i])
			{
				temp = veri[i];
				veri[i] = veri[j];
				veri[j] = temp;
			}

			
		}
	}
}

/* veri icinde gecen her bir elemanin kac kez oldugunu bulur 
ve bunu vektor<Pair> olarak donderir */
template<class T>
void AkilliDizi<T>::histogram(vector<Pair<T>>& hist) const
{
	this->sirala();
	unsigned int i = 0;
	while (i < elemanSayisi)
	{
		unsigned int adedi = kacTane(veri[i]);
		Pair<T> temp;
		temp.eleman = veri[i];
		temp.adet = adedi;
		hist.push_back(temp);
		i += adedi;
	}
}

/* veri icinde i degerinden kac tane oldu�unu sayar*/
template<class T>
unsigned AkilliDizi<T>::kacTane(T a) const
{
	unsigned temp = 0;
	for (unsigned i = 0; i < elemanSayisi; i++)
	{
		if (veri[i] == a)
			temp++;
	}
	return temp;
}

/* veri icinde i degeri mevcutsa dogru degilse yanlis donderir.*/
template<class T>
bool AkilliDizi<T>::varMi(T a) const
{
	for (unsigned i = 0; i < elemanSayisi; i++)
	{
		if (veri[i] == a)
			return true;
		else
			continue;
	}
	return false;
}

// Dizinin tum elemanlarini ekrana yazd�ran << operatoru
template<class T>
ostream& operator << (ostream& out,const AkilliDizi<T>& dizi)
{
	for(unsigned i = 0; i < dizi.elemanSayisi; i++)
		out << dizi.veri[i] << " ";
	return out;
}
