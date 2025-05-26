#pragma once

#include <initializer_list>
#include <utility>
#include <string>

/**
* @class Prioritet
* @brief Класс, реализующий приоритетную очередь с двусвязным списком.
*/

class Prioritet {
private:
    struct QueueItem {
        int val;
        int prio;
        QueueItem* next;
        QueueItem* prev;

        QueueItem(int v, int p) : val(v), prio(p), next(nullptr), prev(nullptr) {}
    };

    QueueItem* first;
    QueueItem* last;
    size_t length;

    void clearAll();

public:
 /**
 * @brief Конструктор по умолчанию.
 */

    Prioritet();

  /**
 * @brief Конструктор инициализации списком.
 * @param init Список пар.
 */

    Prioritet(std::initializer_list<std::pair<int, int>> init);

 /**
 * @brief Конструктор копирования.
 * @param other Другой объект Prioritet.
 */

    Prioritet(const Prioritet& other);

 /**
 * @brief Конструктор перемещения.
 * @param other Перемещаемый объект Prioritet.
 */

    Prioritet(Prioritet&& other) noexcept;

 /**
 * @brief Деструктор.
 */

    ~Prioritet();

    /**
 * @brief Оператор копирующего присваивания.
 * @param other Другой объект Prioritet.
 * @return Ссылка на текущий объект.
 */

    Prioritet& operator=(const Prioritet& other);

    /**
 * @brief Оператор перемещающего присваивания.
 * @param other Перемещаемый объект Prioritet.
 * @return Ссылка на текущий объект.
 */

    Prioritet& operator=(Prioritet&& other) noexcept;

    /**
 * @brief Оператор добавления элемента.
 * @param elem Пара (значение, приоритет).
 * @return Ссылка на текущий объект.
 */

    Prioritet& operator<<(const std::pair<int, int>& elem);

    /**
 * @brief Оператор удаления элемента с наивысшим приоритетом.
 * @param elem Сюда сохраняется удалённый элемент.
 * @return Ссылка на текущий объект.
 */

    Prioritet& operator>>(std::pair<int, int>& elem);

 /**
 * @brief Добавить элемент в очередь.
 * @param value Значение.
 * @param priority Приоритет.
 */

    void add(int value, int priority);

 /**
  * @brief Удалить элемент с наивысшим приоритетом.
  * @param value Сюда сохраняется значение удалённого элемента.
  * @return true, если удаление прошло успешно.
  */
    bool removeHigh(int& value);

    /**
     * @brief Удалить элемент с наименьшим приоритетом.
     * @param value Сюда сохраняется значение удалённого элемента.
     * @return true, если удаление прошло успешно.
     */

    bool removeLow(int& value);

    /**
     * @brief Проверить значение элемента с наивысшим приоритетом без удаления.
     * @param value Сюда сохраняется значение.
     * @return true, если такой элемент существует.
     */

    bool checkHigh(int& value) const;

    /**
     * @brief Проверить значение элемента с наименьшим приоритетом без удаления.
     * @param value Сюда сохраняется значение.
     * @return true, если такой элемент существует.
     */
    bool checkLow(int& value) const;
    /**
         * @brief Проверить, пуста ли очередь.
         * @return true, если очередь пуста.
         */

    bool is_empty() const;

    /**
     * @brief Получить размер очереди.
     * @return Количество элементов в очереди.
     */

    size_t size() const;

    /**
     * @brief Получить строковое представление очереди.
     * @return Строка с элементами очереди.
     */

    std::string str() const;

    /**
     * @brief Очистить очередь.
     */

    void purge();
};
