#pragma once
#include "Room.h"
#include <vector>

class Flat {
private:

	vector<Room> rms;

public:

	void new_room() {
		rms.resize(rms.size() + 1);
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
				if (a == 0) {
					cout << "    Количество рулонов: ";
					if ((i.square() / a) * a < a) {
						a = i.square() / a + 1;
					}
					else a = i.square() / a;
					cout << a << "\n    Требуемая сумма: " << a * i.get_Wallp().get_price() << endl;
				}
				else cout << "    Количество рулонов: 0\n";
			}
			else cout << "    Обоев нет\n";
			No++;
		}
	}
	bool gg(int hg) {
		return rms[hg].get_avail();
	}
	void edit(int num, int numb, string info) {
		rms[numb-1].set_info(num, info);
	}
	void edit(int num, int numb, bool info) {
		rms[numb-1].set_info(num, info);
	}
	void edit(int num, int numb, int info) {
		rms[numb-1].set_info(num, info);
	}
};
