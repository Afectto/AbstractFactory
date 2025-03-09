#ifndef UNIT_H
#define UNIT_H

#include <iostream>
#include <bits/shared_ptr.h>
#include "AbstractCodeFactory.h"

class Unit {
public:
    using Flags = unsigned int;

    virtual ~Unit() = default;

    // Добавление виртуальных методов
    virtual void add(const std::shared_ptr<Unit>& unit, Flags flags);
    virtual std::string compile(unsigned int level = 0, const AbstractCodeFactory* factory = nullptr) const = 0;
    std::string generateShift(unsigned int level) const;
};
#endif // UNIT_H
