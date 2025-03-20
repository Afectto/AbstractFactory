#include "printoperatorunit.h"

std::string PrintOperatorUnit::compile(unsigned int level, const AbstractCodeFactory* factory) const {
    return generateShift(level) + factory->createPrintStatement(m_text);
}
