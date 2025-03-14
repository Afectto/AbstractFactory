#ifndef PRINTOPERATORUNIT_H
#define PRINTOPERATORUNIT_H

#include "unit.h"

class PrintOperatorUnit : public Unit {
public:
    explicit PrintOperatorUnit(const std::string& text) : m_text(text) {}

    std::string compile(unsigned int level = 0, const AbstractCodeFactory* factory = nullptr) const override;

private:
    std::string m_text;
};

#endif // PRINTOPERATORUNIT_H
