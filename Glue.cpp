#include <iostream>
#include "Flat.h"
#include <windows.h>

using namespace std;

int yen() {
	int nos = 1;
	cout << R"(1 - Да
2 - Нет
)"; cin >> nos;
	while (nos != 1 and nos != 0) {
		cout << R"(Неверное значение. Попробуйте снова
1 - Да
2 - Нет
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
		switch (cond)
		{
		case 1:
			len++;
			cout << "Добавить название комнаты\n";
			nos = yen();
			if (nos == 1)
				cout << "Введите название\n"; cin >> inf;
			obj.edit(1, len, inf);

			cout << "Добавить длинну комнаты\n";
			nos = yen();
			if (nos == 1)
				cout << "Введите длинну\n"; cin >> inf;
			while (stoi(inf) <= 0) cout << "Неверная длинна. Попробуйте снова.\n"; cin >> inf;
			obj.edit(2, len, stoi(inf));

			cout << "Добавить ширину комнаты\n";
			nos = yen();
			if (nos == 1)
				cout << "Введите ширину\n"; cin >> inf;
			while (stoi(inf) <= 0) cout << "Неверная ширина. Попробуйте снова.\n"; cin >> inf;
			obj.edit(3, len, stoi(inf));

			cout << "Добавить высоту комнаты\n";
			nos = yen();
			if (nos == 1)
				cout << "Введите высоту\n"; cin >> inf;
			while (stoi(inf) <= 0) cout << "Неверная высота. Попробуйте снова.\n"; cin >> inf;
			obj.edit(4, len, stoi(inf));

			cout << "Будут ли обои на потолке\n";
			nos = yen();
			if (nos) obj.edit(5, len, true);
			else obj.edit(5, len, false);

			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
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