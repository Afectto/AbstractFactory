#ifndef CPPCODEFACTORY_H
#define CPPCODEFACTORY_H

#include "AbstractCodeFactory.h"

class CppCodeFactory : public AbstractCodeFactory {
public:
    std::string createClass(const std::string& className, const std::string& content) const override;
    std::string createMethod(const std::string& returnType, const std::string& methodName, const std::string& params, Flags modifiers) const override;
    std::string getAccessModifier(int flags) const override;
    std::string getMethodModifier(Flags modifier) const override;
};

#endif // CPPCODEFACTORY_H
