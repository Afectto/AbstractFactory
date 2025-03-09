
#include "javacodefactory.h"
#include <vector>
#include "methodunit.h"

using Flags = unsigned int;

std::string JavaCodeFactory::createClass(const std::string& className, const std::string& content) const {
    return "class " + className + " {\n" + content + "\n};\n";
}

std::string JavaCodeFactory::createMethod(const std::string& returnType, const std::string& methodName, const std::string& params, Flags modifiers) const {
    std::string result = "    "; // Корректный отступ
    std::string methodModifier = getMethodModifier(modifiers);
    if (!methodModifier.empty()) {
        result += methodModifier + " ";
    }
    result += returnType + " " + methodName + "(" + params + ")";
    if (modifiers & MethodUnit::ABSTRACT) {
        result += ";\n";
    }
    return result;
}

std::string JavaCodeFactory::getAccessModifier(int flags) const {
    static const std::vector<std::string> ACCESS_MODIFIERS = { "public", "protected", "private", "default" };
    return (flags < ACCESS_MODIFIERS.size()) ? ACCESS_MODIFIERS[flags] : "private";
}

std::string JavaCodeFactory::getMethodModifier(Flags modifier) const {
    if (modifier & MethodUnit::ABSTRACT) return "abstract";
    if (modifier & MethodUnit::STATIC) return "static";
    if (modifier & MethodUnit::FINAL) return "final";
    if (modifier & MethodUnit::SYNCHRONIZED) return "synchronized";
    return "";
}
