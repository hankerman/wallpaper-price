#include "Flat.h"

double Flat::surfaceWallpaper(double width, double length)
{
	double res = width * length;
	
	return res;
}

double Flat::surfaceRoom(double width, double length, double height, bool gluing_the_ceiling)
{
	double res;

	if (gluing_the_ceiling) {
		res = 2 * (width * height) + 2 * (length * height) + (width * length);
	}
	else {
		res = 2 * (width * height) + 2 * (length * height);
	}

	return res;
}

void Flat::quantityWallpaper(double widthWallpaper, double lengthWallpaper, double widthRoom, double lengthRoom, double heightRoom, bool gluing_the_ceiling)
{
	int count_wallpaper = 1;
	double wallpapers, rooms = surfaceRoom(widthRoom, lengthRoom, heightRoom, gluing_the_ceiling);
	bool flag = true;

	do {

		wallpapers = surfaceWallpaper(widthWallpaper, lengthWallpaper) * count_wallpaper;
		if (wallpapers >= rooms) {
			quantity_wallpaper = count_wallpaper;
			flag = false;
		}
		else {
			count_wallpaper++;
		}

	} while (flag);
}

Flat::Flat()
{
	this->count_room = 1;
	list_room = new Room[count_room];
	list_wallpaper = new Wallpaper[count_room];
	this->quantity_wallpaper = 10;
}

Flat::Flat(int count_room)
{
	this->count_room = count_room;
	list_room = new Room[count_room];
	list_wallpaper = new Wallpaper[count_room];
	this->quantity_wallpaper = 10;
}

void Flat::fill()
{
	string temp;
	double tempp;
	
	for (int i = 0; i < count_room; i++) {
		temp = "";
		cout << "������� �������� �������:" << endl;
		if (temp == "") {
			cin >> temp;
		}
		list_room[i].setName(temp);
		cout << "������� ������� �������" << endl;
		cout << "������: ";
		cin >> tempp;
		list_room[i].setWidth(tempp);
		cout << "�����: ";
		cin >> tempp;
		list_room[i].setLength(tempp);
		cout << "������: ";
		cin >> tempp;
		list_room[i].setHeight(tempp);
		cout << "�� ������� ���� �����?" << endl;
		cout << "���� �� - yes, ���� ��� - no" << endl;		
		temp = "";
		cin >> temp;
		if (temp == "") {
			cin >> temp;
		}
		if (temp == "yes") {
			list_room[i].setGluingTheCeiling(true);
		}
		else {
			list_room[i].setGluingTheCeiling(false);
		}
		cout << endl << endl;
	}
}

void Flat::fillWallpapers()
{
	string temp;
	double tempp;
	int tem;

	for (int i = 0; i < count_room; i++) {
		cout << "������� �������� ����� ��� �������: " << list_room[i].getNaming() << endl;
		cin >> temp;
		list_wallpaper[i].setName(temp);
		cout << "������� ������� �����:" << endl;
		cout << "������: ";
		cin >> tempp;
		list_wallpaper[i].setWidth(tempp);
		cout << "�����: ";
		cin >> tempp;
		list_wallpaper[i].setLength(tempp);
		cout << "������� ���� ����� �� �����: ";
		cin >> tem;
		list_wallpaper[i].setPrice(tem);
		cout << endl << endl;
	}


}

void Flat::print()
{
	int count_price = 0;
	cout << "� �������� ���� �������:" << endl;
	for (int i = 0; i < count_room; i++) {
		cout << "������� " << i << " " << list_room[i].getNaming() << endl;
		cout << "�� ���������: " << endl;
		cout << "������ - " << list_room[i].getWidth() << "m" << ", ����� - " << list_room[i].getLenght() << "m" << ", ������ - " << list_room[i].getHeight() << "m" << endl;
		if (list_room[i].getGluingTheCeiling()) {
			cout << "���� �� ������� ������" << endl;
		}
		else {
			cout << "���� �� ������� �� ������" << endl;
		}
		cout << "���� � ���� �������: " << list_wallpaper[i].getNaming() << endl;
		cout << "���������: ������ - " << list_wallpaper[i].getWidth() << "m" << ", ������ - " << list_wallpaper[i].getLenght() << "m" << endl;
		cout << "����� �� ����� - " << list_wallpaper[i].getPrices() << " ������" << endl;
		quantityWallpaper(list_wallpaper[i].getWidth(), list_wallpaper[i].getLenght(), list_room[i].getWidth(), list_room[i].getLenght(), list_room[i].getHeight(), list_room[i].getGluingTheCeiling());
		cout << "��� �������� ���� ������� ����� - " << quantity_wallpaper + 1 << " ������� �����" << endl;
		cout << "���� �� ��� ���� �� ������� - " << (quantity_wallpaper + 1) * list_wallpaper[i].getPrices() << " ������" << endl;
		count_price = count_price + ((quantity_wallpaper + 1) * list_wallpaper[i].getPrices());
		cout << endl;
	}

	cout << "�����: " << count_price;
}
