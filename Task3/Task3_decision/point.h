#pragma once
#include <iostream>

/**
 * @class Point
 * @brief Класс, представляющий точку с координатами x и y в двумерном пространстве
 */

class Point {
private:
    double x;
    double y;
    double max_coord;

public:

    /**
 * @brief Конструктор точки
 * @param x Координата X (по умолчанию 0)
 * @param y Координата Y (по умолчанию 0)
 */

    Point(double x = 0, double y = 0);

    /**
     * @brief Получить координату X
     * @return Значение координаты X
     */

    double getX() const;

    /**
  * @brief Получить координату Y
  * @return Значение координаты Y
  */

    double getY() const;

    /**
 * @brief Установить новую координату X
 * @param newX Новое значение координаты X
 */

    void setX(double newX);

    /**
 * @brief Установить новую координату Y
 * @param newY Новое значение координаты Y
 */

    void setY(double newY);

    /**
  * @brief Установить максимальное значение координат
  * @param max Максимально допустимое значение координат
  */

    static void setMaxCoord(double max);

    /**
 * @brief Проверить валидность координат точки
 * @param max_coord Максимально допустимое значение координат
 */

    void validate(double max_coord) const;

    /**
        *@brief Оператор сравнения точек на равенство
        * @param lhs Первая точка для сравнения
        * @param rhs Вторая точка для сравнения
        * @return true если точки равны, false в противном случае
     */

    friend bool operator==(const Point& lhs, const Point& rhs);

    /**
 * @brief Оператор сравнения точек на неравенство
 * @param lhs Первая точка для сравнения
 * @param rhs Вторая точка для сравнения
 * @return true если точки не равны, false в противном случае
 */

    friend bool operator!=(const Point& lhs, const Point& rhs);

    /**
 * @brief Оператор вывода точки в поток
 * @param os Выходной поток
 * @param point Точка для вывода
 * @return Поток с записанной точкой в формате (x, y)
 */

    friend std::ostream& operator<<(std::ostream& os, const Point& point);
};
