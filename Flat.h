#pragma once
#include "Room.h"
#include <vector>

class Flat {
private:

	vector<Room> rms;

public:

	void new_room(string name) {
		rms.resize(rms.size() + 1);
		rms[rms.size()].set_info(1, name);
	}

	void del_room(int num) {
		rms.erase(rms.begin() + num - 1);
	}

	void show()
	{
		int No = 1;
		int a;
		for (auto i : rms)
		{
			cout << No << endl;
			cout << "    Название комнаты: " << i.get_name() << endl;
			if (i.get_avail()) {
				a = i.get_Wallp().get_size();
				cout << "    Название обоев: " << i.get_Wallp().get_name() << endl;
				cout << "    Количество рулонов: ";
				if ((i.square() / a) * a < a) {
					a =  i.square() / a + 1;
				}
				else a = i.square() / a;
				cout << a << "\n    Требуемая сумма: " << a * i.get_Wallp().get_price() << endl;
			}
			No++;
		}
	}

	void edit(int num, int numb, string info) {
		rms[numb].set_info(num, info);
	}
	void edit(int num, int numb, bool info) {
		rms[numb].set_info(num, info);
	}
	void edit(int num, int numb, int info) {
		rms[numb].set_info(num, info);
	}
};
