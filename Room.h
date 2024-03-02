#pragma once
#include <iostream>
#include "WallpaperRoll.h"

using namespace std;

class Room {
private:
	string name{ "None" };
	int x{ 0 };
	int y{ 0 };
	int z{ 0 };
	bool roof{ false };
	bool avail{ false };
	WallpaperRoll obj;

public:

	string get_name() {
		return name;
	}
	int get_x() {
		return x;
	}
	int get_y() {
		return y;
	}
	int get_z() {
		return z;
	}
	bool get_roof() {
		return roof;
	}
	bool get_avail() {
		return avail;
	}

	WallpaperRoll get_Wallp(){
		if (avail) return obj;
	}

	void set_info(int num, int info) {
		switch (num)
		{
		case 2:
			x = info;
			break;
		case 3:
			y = info;
			break;
		case 4:
			z = info;
			break;
		case 8:
			obj.set_inf(info, 8);
			break;
		case 9:
			obj.set_inf(info, 9);
			break;
		}
	}
	void set_info(int num, bool info) {
		switch (num)
		{
		case 5:
			avail = info;
			break;
		case 6:
			roof = info;
			break;
		}
	}
	void set_info(int num, string info) {
		switch (num)
		{
		case 1:
			name = info;
			break;
		case 7:
			obj.set_inf(info);
			break;
		}
	}

	int square()
	{
		if (roof == true)
		{
			return (x * z * 2) + (y * z * 2) + (x * y);
		}
		else
		{
			return (x * z * 2) + (y * z * 2);
		}

	}
};

