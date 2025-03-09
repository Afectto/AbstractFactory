#include "methodunit.h"

MethodUnit::MethodUnit(const std::string &name, const std::string &returnType, Flags flags) :
    m_name( name ), m_returnType( returnType ), m_modifiers( flags ) { }

void MethodUnit::add(const std::shared_ptr<Unit> &unit, Flags) {
    m_body.push_back( unit );
}

std::string MethodUnit::compile(unsigned int level, const AbstractCodeFactory* factory) const {
    std::string result = generateShift(level);

    std::string methodSignature = factory->createMethod(
        m_returnType,
        m_name,
        "",
        m_modifiers
        );

    result += methodSignature + " {\n";

    for (const auto& b : m_body) {
        result += b->compile(level + 2, factory);
    }

    result += generateShift(level +1 ) + "}\n";
    return result;
}
