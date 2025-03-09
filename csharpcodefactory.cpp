
#include <vector>
#include "csharpcodefactory.h"
#include "methodunit.h"

using Flags = unsigned int;

std::string CSharpCodeFactory::createClass(const std::string& className, const std::string& content) const {
    return "class " + className + " {\n" + content + "\n};\n";
}

std::string CSharpCodeFactory::createMethod(const std::string& returnType, const std::string& methodName, const std::string& params, Flags modifiers) const {
    std::string result = "    "; // Корректный отступ
    std::string methodModifier = getMethodModifier(modifiers);
    if (!methodModifier.empty()) {
        result += methodModifier + " ";
    }
    result += returnType + " " + methodName + "(" + params + ")";
    return result;
}

std::string CSharpCodeFactory::getAccessModifier(int flags) const {
    static const std::vector<std::string> ACCESS_MODIFIERS = { "public", "protected", "private", "internal", "protected internal", "private protected" };
    return (flags < ACCESS_MODIFIERS.size()) ? ACCESS_MODIFIERS[flags] : "private";
}

std::string CSharpCodeFactory::getMethodModifier(Flags modifier) const {
    if (modifier & MethodUnit::ASYNC) return "async";
    if (modifier & MethodUnit::STATIC) return "static";
    if (modifier & MethodUnit::OVERRIDE) return "override";
    if (modifier & MethodUnit::SEALED) return "sealed";
    return "";
}
