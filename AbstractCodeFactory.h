#ifndef ABSTRACTCODEFACTORY_H
#define ABSTRACTCODEFACTORY_H

#include <string>

using Flags = unsigned int;

class AbstractCodeFactory {
public:
    virtual ~AbstractCodeFactory() = default;
    virtual std::string createClass(const std::string& className, const std::string& content) const = 0;

    // Создание метода с модификаторами
    virtual std::string createMethod(const std::string& returnType,
                                     const std::string& methodName,
                                     const std::string& params,
                                     Flags modifiers) const = 0;

    // Получение модификаторов доступа (public, private, protected и др.) (Установка типо поумолчанию если текущего нету в языке
    virtual std::string getAccessModifier(int flags) const = 0;

    // Получение специфичных модификаторов методов (async, static, final и т.д.)
    virtual std::string getMethodModifier(Flags modifier) const = 0;
};
#endif // ABSTRACTCODEFACTORY_H
