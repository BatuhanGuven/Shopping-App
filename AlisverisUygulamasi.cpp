
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <locale.h>
#include <iomanip>
#include <cstdlib>
#include <conio.h>
#ifdef _MSC_VER
#define getch() _getch()
#endif
using namespace std;
///////////////////HEADER.h///////////////////////////
class Zaman {
public:
	int saat;
	int dakika = -1;


	time_t now = time(0);

	tm* ltm = localtime(&now);
	Zaman();
	friend ostream& operator<<(ostream& os, const Zaman& dt);

};

class Clothes {
protected:
	int index;
	string size;
	string color;
	string category;
	double price;
public:

	Clothes(int = 0, string = "", string = "", string = "", double = 0);

	void setIndex(int);
	void setSize(string);
	void setColor(string);
	void setCategory(string);
	void setPrice(double);

	int getIndex();
	string getSize();
	string  getColor();
	string getCategory();
	double getPrice();
};

class Siparis :public Clothes {
public:

	int siparis_no = 0;
	double siparis_fiyat = 0;
	Zaman siparis_baslangic;
	Zaman siparis_ulasim;
	void setSiparis_no(int);
	void setSiparis_Fiyat(double);
	void setZaman(Zaman);
	void setSiparis_ulasim(Zaman);
	int getSiparisNo();

	void operator=(Clothes c) {
		this->setIndex(c.getIndex());
		this->setCategory(c.getCategory());
		this->setColor(c.getColor());
		this->setPrice(c.getPrice());
		this->setSize(c.getSize());
	}

};
class Dress :public Clothes {
public:
	Dress();
	Dress(int = 0, string = "", string = "", string = "", double = 0);
};
class Tshirt :public Clothes {
public:
	Tshirt();
	Tshirt(int = 0, string = "", string = "", string = "", double = 0);
};

class Pants :public Clothes {
public:
	Pants();
	Pants(int = 0, string = "", string = "", string = "", double = 0);
};
class Shirt :public Clothes {
public:
	Shirt();
	Shirt(int = 0, string = "", string = "", string = "", double = 0);
};
class Skirt :public Clothes {
public:
	Skirt();
	Skirt(int = 0, string = "", string = "", string = "", double = 0);
};
class Shoes :public Clothes {
public:
	Shoes();
	Shoes(int = 0, string = "", string = "", string = "", double = 0);
};

class Person {
public:
	Person();
	Person(string, string);
protected:
	string ad_soyad;
	string telno;
};

class User :public Person {
public:
	User();
	User(string, string, string, string, string, string, string, string);
	void setPassword(string);
	string getMail();
	string getNickName();
	void setIndirimKodu(string);
	string getIndirimKodu() { return indirim_kodu; }
	string getPassword() { return sifre; }
	vector<Clothes>vectorSepet;
	vector<Siparis>vectorSiparis;
	vector<vector<Siparis>>vectorSiparisler;
private:
	string kullanici_adi, eposta, adress_ilce, sifre, indirim_kodu, dtarihi;
};

class Manager :public Person {
public:
	Manager();
	Manager(string, string, string);
private:
	string sifre;

};

class Carrier : public Person {
public:
	Carrier();
	Carrier(string, string, Zaman, int);
private:
	Zaman dagitim_bitisler;
	int siparis_numarasi;
};

class Fatura {

private:
	int siparis_no;
	string kullanici_adi;
public:
	void setSiparisNo(int siparisNo) { this->siparis_no = siparisNo; }
	void setKullaniciAdi(string kullaniciAdi) { this->kullanici_adi = kullaniciAdi; }
	string getKullaniciAdi() { return kullanici_adi; }
	int getSiparis_no() { return siparis_no; }
	Fatura();
	Fatura(int, string);
};

/////////////////  SOURCE.CPP  ///////////////////////////////////////////////////////////////////////////////////////////////////////



Zaman::Zaman() {
	saat = ltm->tm_hour;
	dakika = ltm->tm_min;
}



Clothes::Clothes(int index, string size, string category, string color, double price) {
	this->index = index;
	this->size = size;
	this->category = category;
	this->color = color;
	this->price = price;
}
void Clothes::setIndex(int index) {
	this->index = index;

}
void Clothes::setSize(string size) {

	this->size = size;

}
void Clothes::setCategory(string category) {
	this->category = category;
}
void Clothes::setColor(string color) {

	this->color = color;
}
void Clothes::setPrice(double price) {
	this->price = price;

}
int Clothes::getIndex() {
	return this->index;
}
string Clothes::getSize() {
	return this->size;
}
string Clothes::getColor() {

	return this->color;
}
string Clothes::getCategory() {
	return this->category;

}
double Clothes::getPrice() {

	return this->price;
}


Dress::Dress(int index, string size, string color, string category, double price) :Clothes(index, size, category, color, price) {}
Tshirt::Tshirt(int index, string size, string color, string category, double price) :Clothes(index, size, category, color, price) {}
Pants::Pants(int index, string size, string color, string category, double price) :Clothes(index, size, category, color, price) {}
Shirt::Shirt(int index, string size, string color, string category, double price) :Clothes(index, size, category, color, price) {}
Skirt::Skirt(int index, string size, string color, string category, double price) :Clothes(index, size, category, color, price) {}
Shoes::Shoes(int index, string size, string color, string category, double price) :Clothes(index, size, category, color, price) {}



void Siparis::setSiparis_no(int siparis_no) {

	this->siparis_no = siparis_no;
}
void Siparis::setSiparis_Fiyat(double Siparis_Fiyat) {

	this->siparis_fiyat = siparis_fiyat;
}
void Siparis::setZaman(Zaman siparis_baslangic) {

	this->siparis_baslangic = siparis_baslangic;
}
void Siparis::setSiparis_ulasim(Zaman siparis_ulasim) {

	this->siparis_ulasim = siparis_ulasim;
}
int Siparis::getSiparisNo() { return siparis_no; }



Person::Person(string ad_soyad, string telno) {
	this->ad_soyad = ad_soyad;
	this->telno = telno;

}


User::User(string ad_soyad, string telno, string kullanici_adi, string eposta, string adress_ilce, string sifre, string dtarihi, string indirim_kodu) :Person(ad_soyad, telno) {
	this->kullanici_adi = kullanici_adi;
	this->eposta = eposta;
	this->adress_ilce = adress_ilce;
	this->sifre = sifre;
	this->dtarihi = dtarihi;
	this->indirim_kodu = indirim_kodu;
}
void User::setPassword(string password) {
	this->sifre = password;
}
string User::getMail() {
	return eposta;
}
string User::getNickName() {
	return kullanici_adi;
}
void User::setIndirimKodu(string indirim_kodu) {

	this->indirim_kodu = indirim_kodu;

}



Manager::Manager(string ad_soyad, string telno, string sifre) :Person(ad_soyad, telno) {
	this->sifre = sifre;

}

Carrier::Carrier(string ad_soyad, string telno, Zaman dagitim_bitisler, int siparis_numarasi) :Person(ad_soyad, telno) {

	this->dagitim_bitisler = dagitim_bitisler,
		this->siparis_numarasi = siparis_numarasi;
}

Fatura::Fatura(int siparis_no, string kullanici_adi) {
	this->siparis_no = siparis_no;
	this->kullanici_adi = kullanici_adi;

}




////////////////////	FUNCTİONS   ////////////////////////////////////////////////////////////////////////////////////////////////////////////////


vector<User>vectorUser;

string convertToString(char* a, int size)
{
	int i;
	string s = "";
	for (i = 0; i < size; i++) {
		s = s + a[i];
	}
	return s;
}

void printStrongNess(string& input)
{
	int n = input.length();


	bool hasLower = false, hasUpper = false;
	bool hasDigit = false, specialChar = false;
	string normalChars = "abcdefghijklmnopqrstu"
		"vwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890 ";

	for (int i = 0; i < n; i++) {
		if (islower(input[i]))
			hasLower = true;
		if (isupper(input[i]))
			hasUpper = true;
		if (isdigit(input[i]))
			hasDigit = true;

		size_t special = input.find_first_not_of(normalChars);
		if (special != string::npos)
			specialChar = true;
	}


	cout << "Parolanızın Gücü:";
	if (hasLower && hasUpper && hasDigit &&
		specialChar && (n >= 8))
		cout << "Güçlü" << endl;
	else if ((hasLower || hasUpper) &&
		specialChar && (n >= 6))
		cout << "Orta" << endl;
	else
		cout << "Zayıf" << endl;
}

double calculateBillAmount(vector<Siparis>orders, User& user) {
	double total = 0;
	for (int i = 0; i < orders.size(); i++) {
		total += orders.at(i).getPrice();
	}
	if (user.getIndirimKodu() == "indirim50") {
		cout << "indirim oranı : %50" << endl;
		total = total - (total / 2);
	}
	if (user.getIndirimKodu() == "indirim25") {
		cout << "indirim oranı : %25 indirim" << endl;
		total = total - (total / 4);
	}
	if (user.getIndirimKodu() == "indirim10") {
		cout << "indirim oranı : %10 indirim" << endl;
		total = total - (total / 10);
	}
	return total;
}

double calculateBasketAmount(vector<Clothes>basket, User user) {
	double total = 0;
	for (int i = 0; i < basket.size(); i++) {
		total += basket.at(i).getPrice();
	}

	return total;
}
void showBill(User user) {
	cout << "                              ***************" << "Fatura" << "***************" << endl;

	cout << endl;

	cout << "Numara" << setw(14) << "Kategori" << setw(18) << "Beden" << setw(15) << "Renk" << setw(15) << "Fiyat" << setw(25) << "Sipariş Numarası" << endl;
	for (int j = 0; j < user.vectorSiparis.size(); j++) {
		cout << j + 1 << setw(17) << user.vectorSiparis.at(j).getCategory() << setw(18) << user.vectorSiparis.at(j).getSize() << setw(17) << user.vectorSiparis.at(j).getColor() << setw(12) << user.vectorSiparis.at(j).getPrice() << setw(18) << user.vectorSiparis.at(j).siparis_no << endl;
	}

	cout << endl;

	cout << "Fatura Sahibi: " << user.getMail() << endl;
	cout << "Fatura Tarih Saat: " << user.vectorSiparis.at(0).siparis_baslangic << endl;
	cout << "Fatura Tutarı: " << calculateBillAmount(user.vectorSiparis, user) << "$" << endl;

}
void showBasket(User user) {
	cout << "                ***************" << "Sepet" << "***************" << endl;

	cout << endl << endl;

	cout << "Numara" << setw(14) << "Kategori" << setw(18) << "Beden" << setw(15) << "Renk" << setw(15) << "Fiyat" << endl;

	for (int i = 0; i < user.vectorSepet.size(); i++) {

		cout << i + 1 << setw(18) << user.vectorSepet.at(i).getCategory() << setw(18) << user.vectorSepet.at(i).getSize() << setw(17) << user.vectorSepet.at(i).getColor() << setw(12) << user.vectorSepet.at(i).getPrice() << endl;

	}
	cout << "Sepet Tutarı: " << calculateBasketAmount(user.vectorSepet, user) << "$" << endl;
	cout << endl << endl;
}
ostream& operator<<(ostream& os, const Zaman& dt)
{
	os << dt.saat << ':' << dt.dakika;
	return os;
}

Zaman getTime() {
	Zaman zaman;
	return zaman;
}


Zaman orderArrivalTime() {

	Zaman zaman;
	return zaman;

}

int main()
{
	setlocale(LC_ALL, "Turkish");

	fstream readfile("users.txt");

	ifstream dresses("dresses.txt");
	ifstream shoes("shoes.txt");
	ifstream skirts("skirts.txt");
	ifstream shirts("shirts.txt");
	ifstream pants("pants.txt");
	ifstream tshirts("tshirts.txt");

	fstream appdresses("dresses.txt", ios::app);
	fstream appshoes("shoes.txt", ios::app);
	fstream appskirts("skirts.txt", ios::app);
	fstream appshirts("shirts.txt", ios::app);
	fstream apppants("pants.txt", ios::app);
	fstream apptshirts("tshirts.txt", ios::app);

	fstream writefile;
	fstream myFile;
	ifstream readesikayet("Sikayet.txt");

	string mail, password, line, role, birthday, sikayet, size, color, name, indirim_kodu, telno, nickname, adres_ilce, yenikullanici;
	double price;
	Siparis siparisObj;
	Clothes clothe(0, "", "", "", 0);
	vector<Dress> vectorDresses;


	vector<Shoes> vectorShoes;
	vector<Skirt> vectorSkirts;
	vector<Shirt> vectorShirts;
	vector<Pants> vectorPants;
	vector<Tshirt> vectorTshirts;
	vector<Carrier> vectorIdleCarrier;
	vector<Carrier> vectorActiveCarrier;
	vector<vector<Siparis>>vectorManagerSiparisler;
	vector<Fatura> vectorFaturalar;
	Zaman zaman;

	int action = 0, loginInt = 0, chooese, carrierNumber = 0;
	bool auth = false;
	bool control = true;
	char pin[100];
	int k = 0;


	if (readfile.is_open())
	{
		while (getline(readfile, line))
		{
			string ad_soyad = line.substr(line.find("ad_soyad:") + 10, line.find("telno") - line.find("ad_soyad") - 2 - 9);
			string telno = line.substr(line.find("telno") + 7, line.find("kullanici_adi") - line.find("telno") - 2 - 6);
			string kullanici_adi = line.substr(line.find("kullanici_adi") + 15, line.find("eposta") - line.find("kullanici_adi") - 2 - 14);
			string eposta = line.substr(line.find("eposta") + 8, line.find("adres_ilce") - line.find("eposta") - 2 - 7);
			string adress_ilce = line.substr(line.find("adres_ilce") + 12, line.find("sifre") - line.find("adres_ilce") - 2 - 11);
			string sifre = line.substr(line.find("sifre") + 7, line.find("dtarihi") - line.find("sifre") - 2 - 6);
			string dtarihi = line.substr(line.find("dtarihi") + 9, line.find("role") - line.find("dtarihi") - 2 - 8);
			string role = line.substr(line.find("role") + 6, line.find("indirim_kodu") - line.find("role") - 2 - 5);
			string indirim_kodu = line.substr(line.find("indirim_kodu") + 14, line.length());



			User user(ad_soyad, telno, kullanici_adi, eposta, adress_ilce, sifre, dtarihi, indirim_kodu);

			if (role == "member") {
				vectorUser.push_back(user);
			}
		}
	}
Menu:

	cout << "1) Giriş: " << endl;
	cout << "2) Kaydol:" << endl;
	cin >> action;
	system("cls");

	switch (action)
	{

	case 1:

	MenuLogin:

		auth = false;
		cout << "1) Admin Giriş: " << endl;
		cout << "2) Kullanıcı Girişi:" << endl;
		cout << "3) Geri:" << endl;
		cin >> loginInt;
		system("cls");

		switch (loginInt)
		{
		case 1:

			// TODO: set method for this block code
			cout << "Kullanıcı Adınız? ";
			cin >> nickname;
			cout << "Şifreniz? ";
			cin >> password;
			system("cls");
			readfile.clear();
			readfile.seekg(0);
			if (readfile.is_open())
			{
				while (getline(readfile, line))
				{
					string ad_soyad = line.substr(line.find("ad_soyad:") + 10, line.find("telno") - line.find("ad_soyad") - 2 - 9);
					string telno = line.substr(line.find("telno") + 7, line.find("kullanici_adi") - line.find("telno") - 2 - 6);
					string kullanici_adi = line.substr(line.find("kullanici_adi") + 15, line.find("eposta") - line.find("kullanici_adi") - 2 - 14);
					string eposta = line.substr(line.find("eposta") + 8, line.find("adres_ilce") - line.find("eposta") - 2 - 7);
					string adress_ilce = line.substr(line.find("adres_ilce") + 12, line.find("sifre") - line.find("adres_ilce") - 2 - 11);
					string sifre = line.substr(line.find("sifre") + 7, line.find("dtarihi") - line.find("sifre") - 2 - 6);
					string dtarihi = line.substr(line.find("dtarihi") + 9, line.find("role") - line.find("dtarihi") - 2 - 8);
					string role = line.substr(line.find("role") + 6, line.find("indirim_kodu") - line.find("role") - 2 - 5);
					string indirim_kodu = line.substr(line.find("indirim_kodu") + 14, line.length());



					if (nickname == kullanici_adi && password == sifre && "manager" == role) {
					menumanager:
						auth = true;
						Manager manager(ad_soyad, telno, sifre);

						cout << "1) Yeni Ürün Girişi" << endl;
						cout << "2) Kurye Ekle" << endl;
						cout << "3) Şikayet ve Öneriler " << endl;
						cout << "4) İndirim Kodu Tanımla" << endl;
						cout << "5) Tüm Faturları Görüntüle" << endl;
						cout << "6) Geri" << endl;

						cin >> action;
						switch (action)
						{
						case 1:
						menucategories:
							system("cls");
							cout << "1)Elbise" << endl;
							cout << "2)Tshirt" << endl;
							cout << "3)Pantolon" << endl;
							cout << "4)Gömlek" << endl;
							cout << "5)Etek" << endl;
							cout << "6)Ayakkabı" << endl;
							cout << "7)Geri" << endl;
							cout << "Ürün girişi yapmak istediğiniz kategoriyi giriniz.." << endl;

							cin >> action;
							system("cls");
							switch (action) {
							case 1:
								cout << "Beden giriniz" << endl;
								cin >> size;
								cout << "Renk giriniz" << endl;
								cin >> color;
								cout << "Fiyat giriniz" << endl;
								cin >> price;

								system("cls");


								if (dresses.is_open()) {

									appdresses << "size: " << size << " price: " << price << " color: " << color << endl;


								}
								goto menucategories;
							case 2:
								cout << "Beden giriniz" << endl;
								cin >> size;
								cout << "Renk giriniz" << endl;
								cin >> color;
								cout << "Fiyat giriniz" << endl;
								cin >> price;

								system("cls");


								if (tshirts.is_open()) {

									apptshirts << "size: " << size << " price: " << price << " color: " << color << endl;


								}
								goto menucategories;
								break;
							case 3:
								cout << "Beden giriniz" << endl;
								cin >> size;
								cout << "Renk giriniz" << endl;
								cin >> color;
								cout << "Fiyat giriniz" << endl;
								cin >> price;

								system("cls");


								if (pants.is_open()) {

									apppants << "size: " << size << " price: " << price << " color: " << color << endl;


								}
								goto menucategories;
								break;
							case 4:
								cout << "Beden giriniz" << endl;
								cin >> size;
								cout << "Renk giriniz" << endl;
								cin >> color;
								cout << "Fiyat giriniz" << endl;
								cin >> price;

								system("cls");


								if (shirts.is_open()) {

									apptshirts << "size: " << size << " price: " << price << " color: " << color << endl;


								}
								goto menucategories;
								break;
							case 5:
								cout << "Beden giriniz" << endl;
								cin >> size;
								cout << "Renk giriniz" << endl;
								cin >> color;
								cout << "Fiyat giriniz" << endl;
								cin >> price;

								system("cls");


								if (skirts.is_open()) {

									appskirts << "size: " << size << " price: " << price << " color: " << color << endl;


								}
								goto menucategories;
								break;

							case 6:
								cout << "Beden giriniz" << endl;
								cin >> size;
								cout << "Renk giriniz" << endl;
								cin >> color;
								cout << "Fiyat giriniz" << endl;
								cin >> price;

								system("cls");


								if (shoes.is_open())
								{
									appshoes << "size: " << size << " price: " << price << " color: " << color << endl;
								}
								goto menucategories;
								break;
							case 7:
								goto menumanager;
								break;
							}


						case 2:
							system("cls");
							cout << "Eklemek istediğiniz Kurye Sayısını Giriniz" << endl;
							cin >> carrierNumber;
							system("cls");
							for (int i = 0; i < carrierNumber; i++)
							{
								cout << "Kuryenin İsmini Giriniz" << endl;
								cin >> name;
								cout << "Kuryenin TelNo Giriniz" << endl;
								cin >> telno;

								cout << "Kurye sepete eklendi..." << endl << endl;;
								system("cls");

								Carrier tempCarrier(name, telno, zaman, 0);
								vectorIdleCarrier.push_back(tempCarrier);

							}
							goto menumanager;

							break;
						case 3:
							system("cls");

							if (readesikayet.is_open())
							{

								while (getline(readesikayet, line))
								{
									cout << line << endl;
								}
							}
							cout << "1)Geri" << endl;
							cin >> action;
							system("cls");
							switch (action)
							{
							case 1:
								goto menumanager;
							default:
								break;
							}
							break;
						case 4:
							system("cls");
							cout << "İndirim kodu vermek istediğiniz kullanıcının kullanıcı adını giriniz" << endl;
							cin >> name;
							system("cls");
							cout << "indirim50 -> %50" << endl;
							cout << "indirim25 -> %25" << endl;
							cout << "indirim10 -> %10" << endl;

							cout << "İndirim kodunu giriniz" << endl;
							cin >> indirim_kodu;
							system("cls");

							for (int i = 0; i < vectorUser.size(); i++)
							{
								if (name == vectorUser.at(i).getNickName()) {


									vectorUser.at(i).setIndirimKodu(indirim_kodu);


									cout << "İndirim Kodu Başarıyla Tanımlandı" << endl;
								}
								else
									cout << "Kullanıcı Bulunamadı" << endl;
							}
							cout << "1) Geri" << endl;
							cin >> action;
							system("cls");
							switch (action)
							{
							case 1:
								goto menumanager;
							default:
								break;
							}

							//Kullanıcıya indirim kodu tanımlaması
							break;
						case 5:
							system("cls");
							if (vectorManagerSiparisler.size() != 0)
							{
								for (int i = 0; i < vectorManagerSiparisler.size(); i++)
								{

									cout << i + 1 << ")" << " " << "Siparis No: " << vectorManagerSiparisler.at(i).at(0).siparis_no << "  " << "Tutar: " << calculateBillAmount(vectorManagerSiparisler.at(i), vectorUser.at(0)) << endl;


								}
								cout << "Fatura Görüntüle: ";
								cin >> action;
								system("cls");


								cout << "                ***************" << "Fatura" << "***************" << endl;

								cout << endl;
								cout << "Kategori" << setw(15) << "Beden" << setw(15) << "Renk" << setw(14) << "Fiyat" << endl;
								for (int j = 0; j < vectorManagerSiparisler.at(action - 1).size(); j++) {
									cout << vectorManagerSiparisler.at(action - 1).at(j).getCategory() << setw(15) << vectorManagerSiparisler.at(action - 1).at(j).getSize() << setw(17) << vectorManagerSiparisler.at(action - 1).at(j).getColor() << setw(12) << vectorManagerSiparisler.at(action - 1).at(j).getPrice() << endl;
								}
								cout << endl;
								for (int j = 0; j < vectorManagerSiparisler.at(action - 1).size(); j++) {
									for (int i = 0; i < vectorFaturalar.size(); i++) {
										if (vectorFaturalar.at(i).getSiparis_no() == vectorManagerSiparisler.at(action - 1).at(i).siparis_no) {
											for (int k = 0; k < vectorUser.size(); k++) {
												if (vectorFaturalar.at(i).getKullaniciAdi() == vectorUser.at(k).getNickName()) {
													cout << "Fatura Sahibi: " << vectorUser.at(k).getMail() << endl;
													cout << "Fatura Saat: " << vectorUser.at(k).vectorSiparis.at(0).siparis_baslangic << endl;
													cout << "Fatura Tutarı: " << calculateBillAmount(vectorUser.at(k).vectorSiparis, vectorUser.at(0)) << "$" << endl;
													cout << "Siparis Ulaşma Süresi: " << "00:00" << endl;
													cout << endl;
												}
											}
										}
									}
								}
							}
							else
								cout << "Fatura Kaydı Bulunamadı" << endl;
							cout << "1) Geri" << endl;
							cin >> action;
							system("cls");
							switch (action)
							{
							case 1:
								goto menumanager;
							default:
								break;
							}
							system("cls");
							break;

						case 6:
							system("cls");
							goto 	MenuLogin;

						}
					}
				}
				readfile.close();
			}

			mail = "";
			password = "";
			break;

		case 2:

			auth = false;
		PasswordChange:
			cout << "Kullanıcı Adı ";
			cin >> nickname;

			cout << "Şifre ";
			cin >> password;
			system("cls");
			for (int userIndex = 0; userIndex < vectorUser.size(); userIndex++)
			{
				if (nickname == vectorUser.at(userIndex).getNickName() && password == vectorUser.at(userIndex).getPassword()) {


					system("cls");
				menux:
					cout << "1)Kıyafet kategorileri ve ürün seçimi" << endl;
					cout << "2)Sipariş takip" << endl;
					cout << "3)Şikayet/Öneriler" << endl;
					cout << "4)Şifre Değiştir" << endl;
					cout << "5)Geri dön" << endl;

					cin >> action;
					system("cls");
					switch (action)
					{

					case 1:
					categories:
						cout << "Categories" << endl;
						cout << "1)Elbise" << endl;
						cout << "2)Tshirt" << endl;
						cout << "3)Pantolon" << endl;
						cout << "4)Gömlek" << endl;
						cout << "5)Etek" << endl;
						cout << "6)Ayakkabı" << endl;
						cout << "7)Geri" << endl;
						cin >> action;

						system("CLS");

						switch (action)
						{
						case 1:

							control = false;
							if (dresses.is_open())
							{

								int index = 0;
								string tempSize;
								string tempColor;
								double  tempPrice;

								cout << "Numara" << "  " << "Renk " << endl;
								while (getline(dresses, line))
								{

									tempSize = line.substr(line.find("size:") + 6, line.find("price") - 7);
									tempColor = line.substr(line.find("color:") + 7, line.length());
									tempPrice = stoi(line.substr(line.find("price:") + 7, line.find("color") - 16));


									Dress tempDress(index, tempSize, tempColor, "Elbise ", tempPrice);

									vectorDresses.push_back(tempDress);


									index++;


								}
							startelbise:

								system("CLS");
								cout << "Numara" << setw(15) << "Beden" << setw(15) << "Renk" << setw(15) << "Fiyat" << endl << endl;



								for (int i = 0; i < vectorDresses.size(); i++) {

									cout << "  " << i + 1 << setw(16) << vectorDresses.at(i).getSize() << setw(17) << vectorDresses.at(i).getColor() << setw(12) << vectorDresses.at(i).getPrice() << endl;


								}


								cout << "Sepete eklemek istediginiz urunun numarasini giriniz" << endl;


								cin >> chooese;
								system("cls");

								vectorUser.at(userIndex).vectorSepet.push_back(vectorDresses.at(chooese - 1));

								system("cls");
								cout << "ürün sepete eklendi" << endl;
								cout << "1)Elbise ekle" << endl << "2)Kategori Menüsüne Dön" << endl << "3)Sepete Git" << endl;


								cin >> action;
								system("cls");
								switch (action)
								{
								case 1:
									goto startelbise;
								case 2:
									goto categories;

								case 3:
									cout << endl;
									showBasket(vectorUser.at(userIndex));

									cout << endl << endl;
									cout << "1)Alışverişe Devam Et" << endl;
									cout << "2)Sepeti Onayla " << endl;

									cin >> action;
									system("cls");
									switch (action)

									{

									case 1:
										goto categories;
									case 2:

										vectorUser.at(userIndex).vectorSiparis.clear();
										for (int i = 0; i < vectorUser.at(userIndex).vectorSepet.size(); i++) {
											siparisObj = vectorUser.at(userIndex).vectorSepet.at(i);
											siparisObj.setZaman(getTime());
											siparisObj.setSiparis_no(rand());
											vectorUser.at(userIndex).vectorSiparis.push_back(siparisObj);
										}
										vectorUser.at(userIndex).vectorSiparisler.push_back(vectorUser.at(userIndex).vectorSiparis);
										vectorManagerSiparisler.push_back(vectorUser.at(userIndex).vectorSiparis);
										system("cls");

										cout << endl;
										showBill(vectorUser.at(userIndex));
										vectorUser.at(userIndex).vectorSepet.clear();

										cout << endl;
										cout << "1)Alışverişe Devam Et" << endl;
										cout << "2)Çıkış Yap" << endl;
										cout << "3)Faturalarım" << endl;
										cout << "4)Menüye Dön" << endl;
										cin >> action;

										system("cls");
										switch (action)
										{
										case 1:
											goto categories;
											break;
										case 2:
											goto Menu;
											break;
										case 3:
											goto faturalar;
										case 4:
											goto menux;
										default:
											break;
										}

									default:
										break;
									}

								default:
									break;
								}

							}
							break;

						case 2:
							control = false;
							if (tshirts.is_open())
							{

								int index = 0;
								string tempSize;
								string tempColor;
								double  tempPrice;

								cout << "Numara" << "  " << "Renk " << endl;
								while (getline(tshirts, line))
								{

									tempSize = line.substr(line.find("size:") + 6, line.find("price") - 7);
									tempColor = line.substr(line.find("color:") + 7, line.length());
									tempPrice = stoi(line.substr(line.find("price:") + 7, line.find("color") - 16));


									Tshirt tempTshirt(index, tempSize, tempColor, "Tshirt ", tempPrice);

									vectorTshirts.push_back(tempTshirt);


									index++;


								}
							starttshirt:

								system("CLS");
								cout << "Numara" << setw(15) << "Beden" << setw(15) << "Renk" << setw(15) << "Fiyat" << endl << endl;



								for (int i = 0; i < vectorTshirts.size(); i++) {  // Tüm elbiseler konsolda gösterildi

									cout << "  " << i + 1 << setw(16) << vectorTshirts.at(i).getSize() << setw(17) << vectorTshirts.at(i).getColor() << setw(12) << vectorTshirts.at(i).getPrice() << endl;


								}


								cout << "Sepete eklemek istediginiz urunun numarasini giriniz" << endl;


								cin >> chooese;
								system("cls");

								vectorUser.at(userIndex).vectorSepet.push_back(vectorTshirts.at(chooese - 1));

								system("cls");
								cout << "ürün sepete eklendi" << endl;
								cout << "1)Tshirt ekle" << endl << "2)Kategori Menüsüne Dön" << endl << "3)Sepete Git" << endl;


								cin >> action;
								system("cls");
								switch (action)
								{
								case 1:
									goto starttshirt;
								case 2:
									goto categories;

								case 3:
									cout << endl;
									showBasket(vectorUser.at(userIndex));


									cout << endl << endl;
									cout << "1)Alışverişe Devam Et" << endl;
									cout << "2)Sepeti Onayla " << endl;

									cin >> action;
									system("cls");
									switch (action)

									{

									case 1:
										goto categories;
									case 2:

										vectorUser.at(userIndex).vectorSiparis.clear();
										for (int i = 0; i < vectorUser.at(userIndex).vectorSepet.size(); i++) {
											siparisObj = vectorUser.at(userIndex).vectorSepet.at(i);
											siparisObj.setZaman(getTime());

											siparisObj.setSiparis_no(rand());
											vectorUser.at(userIndex).vectorSiparis.push_back(siparisObj);
										}
										vectorManagerSiparisler.push_back(vectorUser.at(userIndex).vectorSiparis);
										vectorUser.at(userIndex).vectorSiparisler.push_back(vectorUser.at(userIndex).vectorSiparis);

										system("cls");

										cout << endl;
										showBill(vectorUser.at(userIndex));

										vectorUser.at(userIndex).vectorSepet.clear();
										///////////// fatura kesildikten sonra sepet boşaltıldı
										cout << endl;
										cout << "1)Alışverişe Devam Et" << endl;
										cout << "2)Çıkış Yap" << endl;
										cout << "3)Faturalarım" << endl;
										cout << "4)Menüye Dön" << endl;
										cin >> action;

										system("cls");
										switch (action)
										{
										case 1:
											goto categories;
											break;
										case 2:
											goto Menu;
											break;
										case 3:
											goto faturalar;
										case 4:
											goto menux;
										default:
											break;
										}

									default:
										break;
									}

								default:
									break;
								}

							}
							break;

						case 3:

							control = false;
							if (pants.is_open())
							{

								int index = 0;
								string tempSize;
								string tempColor;
								double  tempPrice;


								while (getline(pants, line))
								{

									tempSize = line.substr(line.find("size:") + 6, line.find("price") - 7);
									tempColor = line.substr(line.find("color:") + 7, line.length());
									tempPrice = stoi(line.substr(line.find("price:") + 7, line.find("color") - 16));


									Pants tempPants(index, tempSize, tempColor, "Pantolon ", tempPrice);

									vectorPants.push_back(tempPants);


									index++;


								}
							startpants:

								system("CLS");
								cout << "Numara" << setw(15) << "Beden" << setw(15) << "Renk" << setw(15) << "Fiyat" << endl << endl;



								for (int i = 0; i < vectorPants.size(); i++) {

									cout << "  " << i + 1 << setw(16) << vectorPants.at(i).getSize() << setw(17) << vectorPants.at(i).getColor() << setw(12) << vectorPants.at(i).getPrice() << endl;


								}


								cout << "Sepete eklemek istediginiz urunun numarasini giriniz" << endl;


								cin >> chooese;
								system("cls");

								vectorUser.at(userIndex).vectorSepet.push_back(vectorPants.at(chooese - 1));

								system("cls");
								cout << "ürün sepete eklendi" << endl;
								cout << "1)Pantolon ekle" << endl << "2)Kategori Menüsüne Dön" << endl << "3)Sepete Git" << endl;


								cin >> action;
								system("cls");
								switch (action)
								{
								case 1:
									goto startpants;
								case 2:
									goto categories;

								case 3:
									cout << endl;
									showBasket(vectorUser.at(userIndex));



									cout << endl << endl;
									cout << "1)Alışverişe Devam Et" << endl;
									cout << "2)Sepeti Onayla " << endl;

									cin >> action;
									system("cls");
									switch (action)

									{

									case 1:
										goto categories;
									case 2:

										vectorUser.at(userIndex).vectorSiparis.clear();
										for (int i = 0; i < vectorUser.at(userIndex).vectorSepet.size(); i++) {
											siparisObj = vectorUser.at(userIndex).vectorSepet.at(i);
											siparisObj.setZaman(getTime());
											siparisObj.setSiparis_no(rand());
											vectorUser.at(userIndex).vectorSiparis.push_back(siparisObj);
										}
										vectorManagerSiparisler.push_back(vectorUser.at(userIndex).vectorSiparis);
										vectorUser.at(userIndex).vectorSiparisler.push_back(vectorUser.at(userIndex).vectorSiparis);

										system("cls");

										cout << endl;
										showBill(vectorUser.at(userIndex));
										vectorUser.at(userIndex).vectorSepet.clear();
										///////////// fatura kesildikten sonra sepet boşaltıldı
										cout << endl;
										cout << "1)Alışverişe Devam Et" << endl;
										cout << "2)Çıkış Yap" << endl;
										cout << "3)Faturalarım" << endl;
										cout << "4)Menüye Dön" << endl;
										cin >> action;

										system("cls");
										switch (action)
										{
										case 1:
											goto categories;
											break;
										case 2:
											goto Menu;
											break;
										case 3:
											goto faturalar;
										case 4:
											goto menux;
										default:
											break;
										}

									default:
										break;
									}

								default:
									break;
								}

							}
							break;

						case 4:
							control = false;
							if (shirts.is_open())
							{

								int index = 0;
								string tempSize;
								string tempColor;
								double  tempPrice;

								cout << "Numara" << "  " << "Renk " << endl;
								while (getline(shirts, line))
								{

									tempSize = line.substr(line.find("size:") + 6, line.find("price") - 7);
									tempColor = line.substr(line.find("color:") + 7, line.length());
									tempPrice = stoi(line.substr(line.find("price:") + 7, line.find("color") - 16));


									Shirt tempShirts(index, tempSize, tempColor, "Gömlek ", tempPrice);

									vectorShirts.push_back(tempShirts);


									index++;


								}
							starshirts:

								system("CLS");
								cout << "Numara" << setw(15) << "Beden" << setw(15) << "Renk" << setw(15) << "Fiyat" << endl << endl;



								for (int i = 0; i < vectorShirts.size(); i++) {

									cout << "  " << i + 1 << setw(16) << vectorShirts.at(i).getSize() << setw(17) << vectorShirts.at(i).getColor() << setw(12) << vectorShirts.at(i).getPrice() << endl;


								}


								cout << "Sepete eklemek istediginiz urunun numarasini giriniz" << endl;


								cin >> chooese;
								system("cls");

								vectorUser.at(userIndex).vectorSepet.push_back(vectorShirts.at(chooese - 1));

								system("cls");
								cout << "ürün sepete eklendi" << endl;
								cout << "1)Gömlek ekle" << endl << "2)Kategori Menüsüne Dön" << endl << "3)Sepete Git" << endl;


								cin >> action;
								system("cls");
								switch (action)
								{
								case 1:
									goto starshirts;
								case 2:
									goto categories;

								case 3:
									cout << endl;
									showBasket(vectorUser.at(userIndex));


									cout << endl << endl;
									cout << "1)Alışverişe Devam Et" << endl;
									cout << "2)Sepeti Onayla " << endl;

									cin >> action;
									system("cls");
									switch (action)

									{

									case 1:
										goto categories;
									case 2:

										vectorUser.at(userIndex).vectorSiparis.clear();
										for (int i = 0; i < vectorUser.at(userIndex).vectorSepet.size(); i++) {
											siparisObj = vectorUser.at(userIndex).vectorSepet.at(i);
											siparisObj.setZaman(getTime());
											siparisObj.setSiparis_no(rand());
											vectorUser.at(userIndex).vectorSiparis.push_back(siparisObj);
										}
										vectorManagerSiparisler.push_back(vectorUser.at(userIndex).vectorSiparis);
										vectorUser.at(userIndex).vectorSiparisler.push_back(vectorUser.at(userIndex).vectorSiparis);

										system("cls");

										cout << endl;
										showBill(vectorUser.at(userIndex));
										vectorUser.at(userIndex).vectorSepet.clear();
										///////////// fatura kesildikten sonra sepet boşaltıldı
										cout << endl;
										cout << "1)Alışverişe Devam Et" << endl;
										cout << "2)Çıkış Yap" << endl;
										cout << "3)Faturalarım" << endl;
										cout << "4)Menüye Dön" << endl;
										cin >> action;

										system("cls");
										switch (action)
										{
										case 1:
											goto categories;
											break;
										case 2:
											goto Menu;
											break;
										case 3:
											goto faturalar;
										case 4:
											goto menux;
										default:
											break;
										}

									default:
										break;
									}

								default:
									break;
								}

							}
							break;

						case 5:
							control = false;
							if (skirts.is_open())
							{

								int index = 0;
								string tempSize;
								string tempColor;
								double  tempPrice;

								cout << "Numara" << "  " << "Renk " << endl;
								while (getline(skirts, line))
								{

									tempSize = line.substr(line.find("size:") + 6, line.find("price") - 7);
									tempColor = line.substr(line.find("color:") + 7, line.length());
									tempPrice = stoi(line.substr(line.find("price:") + 7, line.find("color") - 16));


									Skirt tempSkirt(index, tempSize, tempColor, "Etek ", tempPrice);

									vectorSkirts.push_back(tempSkirt);


									index++;


								}
							startskirts:

								system("CLS");
								cout << "Numara" << setw(15) << "Beden" << setw(15) << "Renk" << setw(15) << "Fiyat" << endl << endl;



								for (int i = 0; i < vectorSkirts.size(); i++) {

									cout << "  " << i + 1 << setw(16) << vectorSkirts.at(i).getSize() << setw(17) << vectorSkirts.at(i).getColor() << setw(12) << vectorSkirts.at(i).getPrice() << endl;


								}


								cout << "Sepete eklemek istediginiz urunun numarasini giriniz" << endl;


								cin >> chooese;
								system("cls");

								vectorUser.at(userIndex).vectorSepet.push_back(vectorSkirts.at(chooese - 1));

								system("cls");
								cout << "ürün sepete eklendi" << endl;
								cout << "1)Etek ekle" << endl << "2)Kategori Menüsüne Dön" << endl << "3)Sepete Git" << endl;


								cin >> action;
								system("cls");
								switch (action)
								{
								case 1:
									goto startskirts;
								case 2:
									goto categories;

								case 3:
									cout << endl;
									showBasket(vectorUser.at(userIndex));


									cout << endl << endl;
									cout << "1)Alışverişe Devam Et" << endl;
									cout << "2)Sepeti Onayla " << endl;

									cin >> action;
									system("cls");
									switch (action)

									{

									case 1:
										goto categories;
									case 2:

										vectorUser.at(userIndex).vectorSiparis.clear();
										for (int i = 0; i < vectorUser.at(userIndex).vectorSepet.size(); i++) {
											siparisObj = vectorUser.at(userIndex).vectorSepet.at(i);
											siparisObj.setZaman(getTime());
											siparisObj.setSiparis_no(rand());
											vectorUser.at(userIndex).vectorSiparis.push_back(siparisObj);
										}
										vectorManagerSiparisler.push_back(vectorUser.at(userIndex).vectorSiparis);
										vectorUser.at(userIndex).vectorSiparisler.push_back(vectorUser.at(userIndex).vectorSiparis);

										system("cls");

										cout << endl;
										showBill(vectorUser.at(userIndex));
										vectorUser.at(userIndex).vectorSepet.clear();
										///////////// fatura kesildikten sonra sepet boşaltıldı
										cout << endl;
										cout << "1)Alışverişe Devam Et" << endl;
										cout << "2)Çıkış Yap" << endl;
										cout << "3)Faturalarım" << endl;
										cout << "4)Menüye Dön" << endl;
										cin >> action;

										system("cls");
										switch (action)
										{
										case 1:
											goto categories;
											break;
										case 2:
											goto Menu;
											break;
										case 3:
											goto faturalar;
										case 4:
											goto menux;
										default:
											break;
										}

									default:
										break;
									}

								default:
									break;
								}

							}
							break;

						case 6:

							control = false;
							if (shoes.is_open())
							{

								int index = 0;
								string tempSize;
								string tempColor;
								double  tempPrice;

								cout << "Numara" << "  " << "Renk " << endl;
								while (getline(shoes, line))
								{

									tempSize = line.substr(line.find("size:") + 6, line.find("price") - 7);
									tempColor = line.substr(line.find("color:") + 7, line.length());
									tempPrice = stoi(line.substr(line.find("price:") + 7, line.find("color") - 16));



									Shoes tempShoes(index, tempSize, tempColor, "Ayakkabı", tempPrice);

									vectorShoes.push_back(tempShoes);

									index++;


								}
							startshoes:

								system("CLS");
								cout << "Numara" << setw(15) << "Beden" << setw(15) << "Renk" << setw(15) << "Fiyat" << endl << endl;



								for (int i = 0; i < vectorShoes.size(); i++) {

									cout << "  " << i + 1 << setw(16) << vectorShoes.at(i).getSize() << setw(17) << vectorShoes.at(i).getColor() << setw(12) << vectorShoes.at(i).getPrice() << endl;


								}


								cout << "Sepete eklemek istediginiz urunun numarasini giriniz" << endl;


								cin >> chooese;
								system("cls");

								vectorUser.at(userIndex).vectorSepet.push_back(vectorShoes.at(chooese - 1));

								system("cls");
								cout << "ürün sepete eklendi" << endl;
								cout << "1)Ayakkabı ekle" << endl << "2)Kategori Menüsüne Dön" << endl << "3)Sepete Git" << endl;


								cin >> action;
								system("cls");
								switch (action)
								{
								case 1:
									goto startshoes;
								case 2:
									goto categories;

								case 3:
									cout << endl;
									showBasket(vectorUser.at(userIndex));


									cout << endl << endl;
									cout << "1)Alışverişe Devam Et" << endl;
									cout << "2)Sepeti Onayla " << endl;

									cin >> action;
									system("cls");
									switch (action)

									{

									case 1:
										goto categories;
									case 2:

										vectorUser.at(userIndex).vectorSiparis.clear();
										for (int i = 0; i < vectorUser.at(userIndex).vectorSepet.size(); i++) {
											siparisObj = vectorUser.at(userIndex).vectorSepet.at(i);
											siparisObj.setZaman(getTime());
											siparisObj.setSiparis_no(rand());
											vectorUser.at(userIndex).vectorSiparis.push_back(siparisObj);
										}
										vectorManagerSiparisler.push_back(vectorUser.at(userIndex).vectorSiparis);
										vectorUser.at(userIndex).vectorSiparisler.push_back(vectorUser.at(userIndex).vectorSiparis);

										system("cls");

										cout << endl;
										showBill(vectorUser.at(userIndex));
										vectorUser.at(userIndex).vectorSepet.clear();

										cout << endl;
										cout << "1)Alışverişe Devam Et" << endl;
										cout << "2)Çıkış Yap" << endl;
										cout << "3)Faturalarım" << endl;
										cout << "4)Menüye Dön" << endl;
										cin >> action;

										system("cls");
										switch (action)
										{
										case 1:
											goto categories;
											break;
										case 2:
											goto Menu;
											break;
										case 3:
											goto faturalar;
										case 4:
											goto menux;
										default:
											break;
										}

									default:
										break;
									}

								default:
									break;
								}

							}
							break;


						default:
							break;


						case 7:
							goto menux;
							break;
						}




						break;
					case 2:

						cout << "Tüm Siparisler" << endl;

					faturalar:

						for (int i = 0; i < vectorUser.at(userIndex).vectorSiparisler.size(); i++)
						{
							cout << i + 1 << ")" << " " << "Siparis Tarihi: " << vectorUser.at(userIndex).vectorSiparis.at(0).siparis_baslangic << "  " << "Tutar: " << calculateBillAmount(vectorUser.at(userIndex).vectorSiparisler.at(i), vectorUser.at(userIndex)) << endl;

						}

						cout << "Fatura Görüntüle: ";
						cin >> action;
						system("cls");


						cout << "                ***************" << "Fatura" << "***************" << endl;

						cout << endl;
						cout << "Kategori" << setw(15) << "Beden" << setw(15) << "Renk" << setw(14) << "Fiyat" << endl;
						for (int j = 0; j < vectorUser.at(userIndex).vectorSiparisler.at(action - 1).size(); j++) {
							cout << vectorUser.at(userIndex).vectorSiparisler.at(action - 1).at(j).getCategory() << setw(15) << vectorUser.at(userIndex).vectorSiparisler.at(action - 1).at(j).getSize() << setw(17) << vectorUser.at(userIndex).vectorSiparisler.at(action - 1).at(j).getColor() << setw(12) << vectorUser.at(userIndex).vectorSiparisler.at(action - 1).at(j).getPrice() << endl;
						}
						cout << endl;

						cout << "Fatura Sahibi: " << vectorUser.at(userIndex).getMail() << endl;
						cout << "Fatura Saat: " << vectorUser.at(userIndex).vectorSiparis.at(0).siparis_baslangic << endl;
						cout << "Fatura Tutarı: " << calculateBillAmount(vectorUser.at(userIndex).vectorSiparis, vectorUser.at(userIndex)) << "$" << endl;
						cout << "Siparis Ulaşma Süresi: " << "00:00" << endl;							vectorUser.at(userIndex).vectorSepet.clear(); ///////////// fatura kesildikten sonra sepet boşaltıldı
						cout << endl;
						cout << "1)Alışverişe Devam Et" << endl;
						cout << "2)Çıkış" << endl;
						cout << "3)Başka Fatura Görüntüle" << endl;
						cin >> action;

						system("cls");
						switch (action)
						{
						case 1:
							goto categories;
							break;
						case 2:
							goto Menu;
							break;
						case 3:
							goto faturalar;
						default:
							break;
						}



						break;
					case 3:

						//Şikayet/Öneriler(Geri bildirimler)


						system("cls");


						getline(cin, sikayet);


						myFile.open("Sikayet.txt", std::ios_base::app);
						if (myFile.is_open()) {
							system("cls");
							cout << "Öneri ve sikayet giriniz" << endl;
							getline(cin, sikayet);
							myFile << vectorUser.at(userIndex).getMail() << ":   " << sikayet << endl;
							myFile.close();
						}
						system("cls");
						goto menux;

						break;
					case 4:
						cout << "Yeni Şifrenizi Giriniz: ";
						/*
						while (pin[k - 1] != '\r') {				///////////// PAROLA GİZLEME ///////////////
							pin[k] = getch();
							if (pin[k - 1] != '\r') {
								cout << "*";
							}
							k++;
						}
						pin[k - 1] = '\0';
						password = convertToString(pin, 100);
						*/


						cin >> password;
						system("cls");
						printStrongNess(password);

						vectorUser.at(userIndex).setPassword(password);
						if (readfile.is_open())
						{

						}
						system("cls");
						goto PasswordChange;

						break;
					case 5:
						system("cls");

						goto Menu;
						break;


					default:
						break;
					}



				}
			}

			break;
		case 3:

			goto Menu;
			break;

		default:
			break;
		}

		break;

	case 2:

		auth = false;
		cout << "Isim Soyisim? ";
		cin >> name;
		cout << "TelNo? ";
		cin >> telno;
		cout << "Kullanici adiniz? ";
		cin >> nickname;
		cout << "Epostanız? ";
		cin >> mail;
		cout << "Yasadiginiz ilce? ";
		cin >> adres_ilce;
	tekrardene:
		cout << "Sifreniz? ";

		/*
		while (pin[k - 1] != '\r') {                  ///////////// PAROLA GİZLEME ///////////////
			pin[k] = getch();
			if (pin[k - 1] != '\r') {
				cout << "*";
			}
			k++;
		}
		pin[k - 1] = '\0';
		password = convertToString(pin, 100);
		*/
		cin >> password;
		printStrongNess(password);                 ////////////// GÜÇLÜ PAROLA KONTROL /////////////
		cout << endl;
		cout << "Yeni şifre girmek iste misiniz?" << endl;
		cout << "1)Yeni şifre gir" << endl;
		cout << "2)Devam" << endl;
		cin >> action;
		switch (action)
		{
		case 1:
			goto tekrardene;
		default:
			break;
		}
		cout << "Dogum tarihiniz? ";
		cin >> birthday;

		system("cls");

		yenikullanici = "ad_soyad: " + name + " " + "telno: " + telno + " " + "kullanici_adi: " + nickname + " " + "eposta: " + mail + " " + "adres_ilce: " + adres_ilce + " " + "sifre: " + password + " " + "dtarihi: " + birthday + " " + "role: " + "member" + " " + "indirim_kodu: " + "***";
		writefile.open("users.txt", std::ios_base::app);
		{
			User user(name, telno, nickname, mail, adres_ilce, password, birthday, "***");
			vectorUser.push_back(user);
		}

		if (writefile.is_open())
		{
			writefile << yenikullanici << endl;
			writefile.close();
		}

		goto MenuLogin;
		break;

	default:
		break;
	}

	return 0;

}