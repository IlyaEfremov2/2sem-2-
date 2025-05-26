#include "Prioritet.h"
#include <sstream>

Prioritet::Prioritet() : first(nullptr), last(nullptr), length(0) {}

Prioritet::Prioritet(std::initializer_list<std::pair<int, int>> init) : Prioritet() {
    for (const auto& [v, p] : init) {
        add(v, p);
    }
}
//конструктор копирования//
Prioritet::Prioritet(const Prioritet& other) : Prioritet() {
    QueueItem* current = other.first;
    while (current) {
        add(current->val, current->prio);
        current = current->next;
    }
}
//конструктор перемещения//
Prioritet::Prioritet(Prioritet&& other) noexcept
    : first(other.first), last(other.last), length(other.length) {
    other.first = other.last = nullptr;
    other.length = 0;
}
//диструктор//
Prioritet::~Prioritet()
{
    clearAll();
}

void Prioritet::clearAll() {
    while (first) {
        QueueItem* tmp = first;
        first = first->next;
        delete tmp;
    }
    last = nullptr;
    length = 0;
}
//оператор присваивания копированием//
Prioritet& Prioritet::operator=(const Prioritet& other) {
    if (this != &other) {
        clearAll();
        QueueItem* current = other.first;
        while (current) {
            add(current->val, current->prio);
            current = current->next;
        }
    }
    return *this;
}
//оператор перемещения присваивания//
Prioritet& Prioritet::operator=(Prioritet&& other) noexcept {
    if (this != &other) {
        clearAll();
        first = other.first;
        last = other.last;
        length = other.length;
        other.first = other.last = nullptr;
        other.length = 0;
    }
    return *this;
}

Prioritet& Prioritet::operator<<(const std::pair<int, int>& elem) {
    add(elem.first, elem.second);
    return *this;
}

Prioritet& Prioritet::operator>>(std::pair<int, int>& elem) {
    if (!is_empty()) {
        elem.first = first->val;
        elem.second = first->prio;
        int tmp;
        removeHigh(tmp);
    }
    return *this;
}

void Prioritet::add(int value, int priority) {
    QueueItem* new_item = new QueueItem(value, priority);

    if (!first) {
        first = last = new_item;
    }
    else {
        QueueItem* current = first;
        while (current && current->prio >= priority) {
            current = current->next;
        }

        if (!current) {
            last->next = new_item;
            new_item->prev = last;
            last = new_item;
        }
        else if (current == first) {
            new_item->next = first;
            first->prev = new_item;
            first = new_item;
        }
        else {
            new_item->next = current;
            new_item->prev = current->prev;
            current->prev->next = new_item;
            current->prev = new_item;
        }
    }
    length++;
}

bool Prioritet::removeHigh(int& value) {
    if (!first) return false;

    value = first->val;
    QueueItem* tmp = first;
    first = first->next;

    if (first) {
        first->prev = nullptr;
    }
    else {
        last = nullptr;
    }

    delete tmp;
    length--;
    return true;
}

bool Prioritet::removeLow(int& value) {
    if (!last) return false;

    value = last->val;
    QueueItem* tmp = last;
    last = last->prev;

    if (last) {
        last->next = nullptr;
    }
    else {
        first = nullptr;
    }

    delete tmp;
    length--;
    return true;
}

bool Prioritet::checkHigh(int& value) const {
    if (!first) return false;
    value = first->val;
    return true;
}

bool Prioritet::checkLow(int& value) const {
    if (!last) return false;
    value = last->val;
    return true;
}

bool Prioritet::is_empty() const {
    return length == 0;
}

size_t Prioritet::size() const {
    return length;
}

std::string Prioritet::str() const {
    std::ostringstream oss;
    QueueItem* current = first;

    while (current) {
        oss << "[" << current->val << "(" << current->prio << ")]";
        if (current->next) {
            oss << "";
        }
        current = current->next;
    }

    return oss.str();
}

void Prioritet::purge() {
    clearAll();
}