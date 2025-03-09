#ifndef METHODUNIT_H
#define METHODUNIT_H
#include "unit.h"

#include <vector>
#include "AbstractCodeFactory.h"

class MethodUnit : public Unit {
public:
    using Flags = unsigned int;

    enum Modifier {
        STATIC = 1,
        CONST = 1 << 1,
        VIRTUAL = 1 << 2,
        ABSTRACT = 1 << 3,
        FINAL = 1 << 4,
        ASYNC = 1 << 5,
        OVERRIDE = 1 << 6,
        SEALED = 1 << 7,
        DEFAULT = 1 << 8,
        SYNCHRONIZED = 1 << 9,
        TRANSIENT = 1 << 10,
        VOLATILE = 1 << 11
    };

    MethodUnit(const std::string& name, const std::string& returnType, Flags modifiers);
    void add(const std::shared_ptr<Unit>& unit, Flags = 0) override;
    std::string compile(unsigned int level = 0, const AbstractCodeFactory* factory = nullptr) const override;

private:
    std::string m_name;
    std::string m_returnType;
    Flags m_modifiers;
    std::vector<std::shared_ptr<Unit>> m_body;
};

#endif // METHODUNIT_H
