#ifndef CLASSUNIT_H
#define CLASSUNIT_H
#include "unit.h"

#include <vector>
#include "AbstractCodeFactory.h"

class ClassUnit : public Unit
{
public:
    using Flags = unsigned int;

    enum AccessModifier {
        PUBLIC,
        PROTECTED,
        PRIVATE,
        INTERNAL,
        PROTECTED_INTERNAL,
        PRIVATE_PROTECTED
    };

    static const std::vector<std::string> ACCESS_MODIFIERS;

    explicit ClassUnit(const std::string& name);
    void add(const std::shared_ptr<Unit>& unit, Flags flags) override;
    std::string compile(unsigned int level = 0, const AbstractCodeFactory* factory = nullptr) const override;

private:
    std::string m_name;
    using Fields = std::vector<std::shared_ptr<Unit>>;
    std::vector<Fields> m_fields;
};

#endif // CLASSUNIT_H
