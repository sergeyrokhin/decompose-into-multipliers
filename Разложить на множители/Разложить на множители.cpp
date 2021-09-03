// Разложить на множители.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>


size_t getValue()
{
	while (true) // цикл продолжается до тех пор, пока пользователь не введет корректное значение
	{
		std::cout << "Enter a unsigned int value (0 for exit): ";
		size_t a;
		std::cin >> a;

		if (std::cin.fail()) // если предыдущее извлечение оказалось неудачным,
		{
			std::cin.clear(); // то возвращаем cin в 'обычный' режим работы
			std::cin.ignore(32767, '\n'); // и удаляем значения предыдущего ввода из входного буфера
			a = -1;
			std::cout << "the value is\'t correct, the value should be no more than: " << a << "\n";
		}
		else // если всё хорошо, то возвращаем a
			return a;
	}
}

size_t delitel(size_t k) //младший делитель числа
{
	size_t length = k / 2;
	for (size_t i = 2; i < length; i++) {
		if (k % i == 0) return i;
	}
	return 1;
}


int main()
{
	while (true)
	{
		size_t num, t; //- число и его делитель
		num = getValue();
		if (num == 0) return 0;
		std::cout << "devisors for number : \n" << num << std::endl;
		while (true) {
			t = delitel(num);
			if (t == 1)	break;
			num = num / t;
			std::cout << t << " ( " << num << " )" << std::endl;
		}
		std::cout << num << std::endl;
	}
}
