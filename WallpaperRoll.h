#pragma once
#include <string>

using namespace std;


class WallpaperRoll {
private:
	string name{ "None" };
	int size{ 0 };
	int price{ 0 };
public:

	string get_name(){
		return name;
	}
	int get_size() {
		return size;
	}
	int get_price() {
		return price;
	}

	void set_inf(string inf) {
		name = inf;
	}

	void set_inf(int inf, int num) {
		switch (num)
			{
		case 7:
			size = inf;
			break;
		case 8:
			price = inf;
			break;
		}
	}
};