#include "unit.h"

void Unit::add(const std::shared_ptr<Unit>&, Flags) {
    throw std::runtime_error("Not supported");
}

std::string Unit::generateShift(unsigned int level) const {
    static const auto DEFAULT_SHIFT = "    "; // Используем 4 пробела для удобочитаемости
    std::string result;
    for (unsigned int i = 0; i < level; ++i) {
        result += DEFAULT_SHIFT;
    }
    return result;
}
