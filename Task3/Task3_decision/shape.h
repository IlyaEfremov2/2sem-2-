#pragma once
#include "point.h"
#include <string>

/**
*@brief Абстрактный базовый класс для геометрических фигур.
*/

class Shape 
{
private:

    double max_coord;

public:

    /**
    *@brief Виртуальный деструктор.
    */

    virtual ~Shape() = default;

    /**
    * @brief Установка максимального значения координат для всех фигур
    * @param max Максимальное допустимое значение координат
    */

    static void setMaxCoord(double max);

    /**
    * @brief функция вычисления площади фигуры
    * @return Площадь фигуры
    */

    virtual double getArea() const = 0;

    /**
  * @brief  функция вычисления периметра фигуры
  * @return Периметр фигуры
  */

    virtual double getPerimeter() const = 0;

    /**
    *@brief  функция проверки принадлежности точки фигуре
    * @param point Точка для проверки
    * @return true если точка принадлежит фигуре, false в противном случае
    */

    virtual bool contains(const Point& point) const = 0;

    /**
   * @brief функция получения строкового представления фигуры
   * @return Строковое описание фигуры
   */

    virtual std::string toString() const = 0;

    /**
   * @brief Оператор вывода фигуры в поток
   * @param os Выходной поток
   * @param shape Фигура для вывода
   * @return Поток с записанным строковым представлением фигуры
   */

    friend std::ostream& operator<<(std::ostream& os, const Shape& shape);
};