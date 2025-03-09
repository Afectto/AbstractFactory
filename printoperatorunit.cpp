#include "printoperatorunit.h"

std::string PrintOperatorUnit::compile(unsigned int level, const AbstractCodeFactory* factory) const {
    return generateShift(level) + "std::cout << \"" + m_text + "\";\n";
}
