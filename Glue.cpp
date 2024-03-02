#include <iostream>
#include "Flat.h"
#include <windows.h>

using namespace std;

int yen() {
	int nos = 1;
	cout << R"(1 - Нет
2 - Да
)"; cin >> nos;
	while (nos != 1 and nos != 2) {
		cout << R"(Неверное значение. Попробуйте снова
1 - Нет
2 - Да
)"; cin >> nos;
	}
	return nos - 1;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Flat obj;
	int cond = 1;
	int nos = 0;
	int len = 0;
	int son;
	string inf;
	cout << "Программа для расчёта тебуемых обоев\n";
	while (cond != 0) {
		cout << R"(Выберите действие:
0 - Выход
1 - Добавить комнату
2 - Удалить комнату
3 - Изменить параметры
4 - Показать результат
)"; cin >> cond;
		system("cls");
		if (len < 1 and (cond == 2 or cond == 3)) {
			cout << "Недостаточно комнат для операции\n";
			system("pause");
			system("cls");
			continue;
		}
		switch (cond)
		{
		case 1:
			obj.new_room();
			len++;
			cout << "Добавить название комнаты\n";
			nos = yen();
			if (nos == 1) {
				cout << "Введите название\n"; cin >> inf;
				obj.edit(1, len, inf);
			}

			cout << "Добавить длинну комнаты\n";
			nos = yen();
			if (nos == 1) {
				cout << "Введите длинну\n"; cin >> inf;
				while (stoi(inf) < 1) {
					cout << "Неверная длинна. Попробуйте снова.\n"; cin >> inf;
				}
				obj.edit(2, len, stoi(inf));
			}
			cout << "Добавить ширину комнаты\n";
			nos = yen();
			if (nos == 1) {
				cout << "Введите ширину\n"; cin >> inf;
				while (stoi(inf) <= 0) {
					cout << "Неверная ширина. Попробуйте снова.\n"; cin >> inf;
				}
				obj.edit(3, len, stoi(inf));
			}
			cout << "Добавить высоту комнаты\n";
			nos = yen();
			if (nos == 1) {
				cout << "Введите высоту\n"; cin >> inf;
				while (stoi(inf) <= 0) {
					cout << "Неверная высота. Попробуйте снова.\n"; cin >> inf;
				}
				obj.edit(4, len, stoi(inf));
			}
			cout << "Будут ли обои в комнате\n";
			nos = yen();
			if (nos)
			{
				if (nos) obj.edit(6, len, true);
				cout << "Введите название обоев\n"; cin >> inf;
				obj.edit(7, len, inf);

				cout << "Введите размер обоев\n"; cin >> inf;
				while (stoi(inf) <= 0) {
					cout << "Неверный размер. Попробуйте снова.\n"; cin >> inf;
				}
				obj.edit(8, len, stoi(inf));

				cout << "Введите цену обоев\n"; cin >> inf;
				while (stoi(inf) <= 0) {
					cout << "Неверная цена. Попробуйте снова.\n"; cin >> inf;
				}
				obj.edit(9, len, stoi(inf));
			}
			else obj.edit(6, len, false);

			cout << "Будут ли обои на потолке\n";
			nos = yen();
			if (nos) obj.edit(5, len, true);
			else obj.edit(5, len, false);

			break;
		case 2:
			cout << "Выберите номер комнаты для удаления\n"; cin >> nos;
			while (nos < 1 or nos > len) {
				cout << "Неверный номер. Попробуйте снова\n"; cin >> nos;
			}
			obj.del_room(nos);
			len--;
			break;
		case 3:
			nos = 0;
			cout << "Введите номер комнаты для изменения\n"; cin >> nos;
			while (nos < 1 or nos > len) {
				cout << "Неверный номер. Попробуйте снова\n"; cin >> nos;
			}
			if (obj.gg(nos - 1)) {
				cout << R"( "Выберите параметр для изменения:
1 - Название комнаты
2 - Длинна комнаты
3 - Ширина комнаты
4 - Высота комнаты
5 - Наличие в ней обоев
6 - Наличие обоев на потолке
7 - Название обоев
8 - Размер обоев
9 - Цена обоев
)"; cin >> son;
				while (son < 1 or son > 9) {
					cout << "Неверный параметр. Попробуйте снова\n"; cin >> nos;
				}
			}
			else {
				cout << R"( "Выберите параметр для изменения:
1 - Название комнаты
2 - Длинна комнаты
3 - Ширина комнаты
4 - Высота комнаты
5 - Наличие в ней обоев
)"; cin >> son;
				while (son < 1 or son > 5) {
					cout << "Неверный параметр. Попробуйте снова\n"; cin >> nos;
				}
			}
			if (son != 5
				and son != 6) {
				cout << "Введите изменённую информацию\n"; cin >> inf;
			}
			if (son == 1
				or son == 7) {
				obj.edit(son, nos, inf);
			}
			else 
				if (son == 5
				or son == 6) {
					cout << "Будут ли обои\n";
					inf = yen();
					if (inf == "") obj.edit(son, nos, false);
					else obj.edit(son, nos, true);
				}
				else {
					while (stoi(inf) < 1) {
						cout << "Неверная информация. Попробуйте снова\n"; cin >> inf;
					}
					obj.edit(son, nos, stoi(inf));
				}
			break;
		case 4:
			obj.show();
			break;
		case 0:
			break;
		default:
			cout << "Неверная команда\n";
			break;
		}
		system("pause");
		system("cls");
	}
}