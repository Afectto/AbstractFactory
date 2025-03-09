#include "classunit.h"
#include "AbstractCodeFactory.h"

const std::vector<std::string> ClassUnit::ACCESS_MODIFIERS = { "public", "protected", "private", "internal", "protected internal", "private protected" };

ClassUnit::ClassUnit(const std::string &name) : m_name(name) {
    m_fields.resize(ACCESS_MODIFIERS.size());
}

void ClassUnit::add(const std::shared_ptr<Unit> &unit, Flags flags) {
    int accessModifier = PRIVATE;
    if (flags < ACCESS_MODIFIERS.size()) {
        accessModifier = flags;
    }
    m_fields[accessModifier].push_back(unit);
}


std::string ClassUnit::compile(unsigned int level, const AbstractCodeFactory* factory) const {
    std::string content;

    for (size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i) {
        if (m_fields[i].empty()) {
            continue;
        }
        content += factory->getAccessModifier(i) + ":\n";
        for (const auto& f : m_fields[i]) {
            content += f->compile(level + 1, factory);
        }
    }

    return generateShift(level) + factory->createClass(m_name, content);
}
