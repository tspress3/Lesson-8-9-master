#include <Windows.h>
#include <iostream>
#include <time.h>
using namespace std;

int main()
{
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
	srand(time(NULL));

	// category
	string name_frukty[4]{ "Яблочный сок","Апельсиновый сок","Абрикосовый сок", "Грушевый сок" };
	string name_ovoshi[3]{ "Томатный сок", "Луковый сок", "Огуречный сок" };
	string name_tea[2]{ "Чесночный чай", "Петрушевый чай" };
	string name_nastoyki[1]{ "Боярышник" };

	// price
	double price_frukty[4]{ 120, 100, 110, 125 };
	double price_ovoshi[3]{ 90, 79, 85 };
	double price_tea[2]{ 99, 60 };
	double price_nastoyki[1]{ 890 };

	//skok banok vibral user
	int count_frukty[4]{ 0 };
	int count_ovoshi[3]{ 0 };
	int count_tea[2]{ 0 };
	int count_nastoyki[1]{ 0 };

	bool has_frukt_juice = false; // чек на сок, при покупке боярышника
	bool payment_success = false;
	int choice, item, n;

	
	// кол-во товаров на складе

	int stock_frukty[4]{ 15, 20 ,35 ,40 };
	int stock_ovoshi[3]{ 10, 5, 7 };
	int stock_tea[2]{ 3, 4 };
	int stock_nastoyki[1]{ 3 };


	/*
	TODO:
	 выбрать 1 товар , либо целую категорию, либо все и когда стартует программа, 
	есть склад и там кол-во товаров, пользователь может покупать товар пока они там есть, 
	если он оплатил , то эти товары со склада удаляются
	*/

	while (true) {

		cout << "\n === Магазин 'Соки Даниил' ===\n\n";
		cout << "Выберите категорию товаров: \n";
		cout << "1. Фруктовые\n";
		cout << "2. Овощные\n";
		cout << "3. Чаи\n";
		cout << "4. Настойки\n";
		cout << "5. Завершить покупку\n";
		cout << "Ваш выбор: ";
		cin >> choice;

		if (choice == 1) {
			while (true) {
				system("cls");
				cout << "--- Фруктовые Соки --- \n";
				for (int i = 0; i < 4; i++)
					cout << i + 1 << ". " << name_frukty[i] << " - " << price_frukty[i] << " руб./банка (в корзине: " << count_frukty[i] << ", Доступно на складе: " << stock_frukty[i] << ")\n";
				cout << "0. Вернуться к категориям \n";
				cout << "Выберите товар: ";
				cin >> item;

				if (item == 0){
					system("cls");
					break;
				}
				
				if (item < 1 || item > 4) {
					cout << "Нет такого товара! \n";
					continue;
				}

				int it = item - 1;

				// товара нету
				if (stock_frukty[it] <= 0) {
					cout << "\nИзвините, этот товар закончился на складе!\n";
					Sleep(2000);
					continue;
				}

				cout << "Сколько литровых банок: ";
				cin >> n;
				if (n < 0) {
					cout << "Неверное колличество!";
					continue;
				}

				if (count_frukty[it] + n > stock_frukty[it]) {
					cout << "\nНедостаточно товара на складе!\n";
					Sleep(3000);
					continue;
				}

				/*count_frukty[item - 1] += n;*/
				count_frukty[it] += n;

				if (n > 0 && count_nastoyki[0] > 0) { // аннулирование боярышника в корзине, так как есть фрукт сок
					count_nastoyki[0] = 0; 
					cout << "\nВы купили фруктовый сок - боярышник аннулирован\n";
					Sleep(3000);
				}

			}
		}
		// конец первого цикла

		else if (choice == 2) {
			while (true) {
				system("cls");
				cout << "--- Овощные Соки --- \n";
				for (int i = 0; i < 3; i++)
					cout << i + 1 << ". " << name_ovoshi[i] << " - " << price_ovoshi[i] << " руб./банка (в корзине: " << count_ovoshi[i] << ")\n";
				cout << "0. Вернуться к категориям \n";
				cout << "Выберите товар: ";
				cin >> item;

				if (item == 0) {
					system("cls");
					break;
				}

				if (item < 1 || item > 3) {
					cout << "Нет такого товара! \n";
					continue;
				}

				cout << "Сколько литровых банок: ";
				cin >> n;
				if (n < 0) {
					cout << "Неверное колличество!";
					continue;
				}
				count_ovoshi[item - 1] += n;
			}
		
		}
		// конец второго цикла

		else if (choice == 3) {
			while (true) {
				system("cls");
				cout << "--- Чаи --- \n";
				for (int i = 0; i < 2; i++)
					cout << i + 1 << ". " << name_tea[i] << " - " << price_tea[i] << " руб./банка (в корзине: " << count_tea[i] << ")\n";
				cout << "0. Вернуться к категориям \n";
				cout << "Выберите товар: ";
				cin >> item;

				if (item == 0) {
					system("cls");
					break;
				}

				if (item < 1 || item > 2) {
					cout << "Нет такого товара! \n";
					continue;
				}

				

				cout << "Сколько литровых банок: ";
				cin >> n;
				if (n < 0) {
					cout << "Неверное колличество!";
					continue;
				}
				count_tea[item - 1] += n;
			}
		}
		else if (choice == 4) {
			while (true) {
				system("cls");
				cout << "--- Настойки --- \n";
				for (int i = 0; i < 1; i++)
					cout << i + 1 << ". " << name_nastoyki[i] << " - " << price_nastoyki[i] << " руб./банка (в корзине: " << count_nastoyki[i] << ")\n";
				cout << "0. Вернуться к категориям \n";
				cout << "Выберите товар: ";
				cin >> item;

				if (item == 0) {
					system("cls");
					break;
				}

				
				for (int i = 0; i < 4; i++) {
					if (count_frukty[i] > 0) {
						has_frukt_juice = true;
						break;
					}
				}

				if (has_frukt_juice) {
					cout << "\nПокупка Боярышника аннулирована, в корзине есть фруктовый сок\n";
					Sleep(3000);
					continue;
				}


				//if (item < 1 || item > 2) {
				//	cout << "Нет такого товара! \n";
				//	continue;
				//}

				if (item != 1) {
					cout << "Нет такого товара! \n";
					continue;
				}



				cout << "Сколько литровых банок: ";
				cin >> n;
				if (n < 0) {
					cout << "Неверное колличество!";
					continue;
				}
				count_nastoyki[item - 1] += n;
			}
		}
		// конец третьего цикла
	
		else if (choice == 5) {
			break;
		}
		else
		{
			system("cls");
			cout << "Такого пункта нету! \n";
			cout << "Возвращаю вас назад...\n";
			Sleep(2000);
			system("cls");
		}
		// конец четвертого цикла
	
	
	}

	double sum = 0;
	int choice_payment;
	int pin_code;
	int gift_onion_juice = count_ovoshi[1] / 4; // сколько банок выбрал пользователь
	int discount_tea = count_tea[1];
	system("cls");
	cout << "\nВаш заказ: \n";
	

	for (int i = 0; i < 4; i++)
		if (count_frukty[i] > 0) {
			cout << name_frukty[i] << ": " << count_frukty[i] << "л * " << price_frukty[i] << " = " << count_frukty[i] * price_frukty[i] << " руб.\n";
			sum += count_frukty[i] * price_frukty[i];
		}

	for (int i = 0; i < 3; i++)
		if (count_ovoshi[i] > 0) {
			cout << name_ovoshi[i] << ": " << count_ovoshi[i] << "л * " << price_ovoshi[i] << " = " << count_ovoshi[i] * price_ovoshi[i] << " руб.\n";
			sum += count_ovoshi[i] * price_ovoshi[i];
		}

	for (int i = 0; i < 2; i++)
		if (count_tea[i] > 0) {
			cout << name_tea[i] << ": " << count_tea[i] << "л * " << price_tea[i] << " = " << count_tea[i] * price_tea[i] << " руб.\n";
			sum += count_tea[i] * price_tea[i];//
		}

	for (int i = 0; i < 1; i++)
		if (count_nastoyki[i] > 0) {
			cout << name_nastoyki[i] << ": " << count_nastoyki[i] << "л * " << price_nastoyki[i] << " = " << count_nastoyki[i] * price_nastoyki[i] << " руб.\n";
			sum += count_nastoyki[i] * price_nastoyki[i];//
		}

	if (sum == 0) {
		cout << "Корзина пуста\n";
		return 0;
	}


	
	
	// Проверки на скидки и тд

	// # 1
	if (discount_tea >= 3) {
		sum -= sum * 0.05;
		cout << "\nВы получили скидку 5% на петрушевый чай\n";
	}
	// #2 если сумма больше 5000 , то скидка 13% на весь чек
	if (sum > 2500) {
		sum -= sum * 0.13;
		cout << "\nВы получили скидку на весь чек 13% \n";
	}
	// #3 каждый четвертый литр лукового сока в подарок
	// если нету подарка ничего не выводим
	if (gift_onion_juice > 0) {
		double d = gift_onion_juice * price_ovoshi[1];
		sum -= d;
		cout << "\nВы получили акцию: каждый четвертый литр локового сока в подарок\n";
	}
	

	cout << "\nИтого к оплате: " << sum << " руб.\n";
	cout << "1. Оплатить картой \n" << "2. Оплатить наличными \n";
	cout << "Ваш выбор: ";
	cin >> choice_payment;

	
	if (choice_payment == 1 || choice_payment == 2) {
		payment_success = true;
		system("cls");
		cout << "Сумма вашей покупки была: " << sum << "\n";
		cout << "Спасибо за покупку. Приходите к нам еще! \n";
	}

	
	if (payment_success) {
		for (int i = 0; i < 4; i++) {
			stock_frukty[i] -= count_frukty[i]; // вычит товар на складе
		}
	}

	return 0;


}