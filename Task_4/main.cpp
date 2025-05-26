#include "../Task_4/decicion/Prioritet.h"
#include <iostream>
#include <locale>

int main() {
    setlocale(LC_ALL, "Russian");

    Prioritet pq1 = { {5, 1}, {10, 3}, {25, 5}, {20, 4} };
    std::cout << "Начальная очередь: " << pq1.str() << std::endl;

    pq1.add(40, 2);
    pq1 << std::make_pair(60, 0);
    std::cout << "После добавления: " << pq1.str() << std::endl;

    int val;
    std::cout << "\nИзвлечение элементов:\n";
    while (pq1.removeHigh(val)) {
        std::cout << "Извлечено: " << val << std::endl;
    }

    std::cout << "\nОчередь пуста: " << std::boolalpha << pq1.is_empty() << std::endl;

    Prioritet pq2;
    pq2.add(200, 5);
    pq2.add(500, 10);
    pq2.add(600, 15);
    std::cout << "\nНовая очередь: " << pq2.str() << std::endl;

    if (pq2.checkHigh(val)) {
        std::cout << "Максимум: " << val << std::endl;
    }
    if (pq2.checkLow(val)) {
        std::cout << "Минимум: " << val << std::endl;
    }

    Prioritet pq3 = pq2;
    std::cout << "\nКопия: " << pq3.str() << std::endl;

    std::pair<int, int> elem;
    pq3 >> elem;
    std::cout << "Через оператор: (" << elem.first << ", " << elem.second << ")\n";

    return 0;
}