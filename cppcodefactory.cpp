
#include <vector>
#include "cppcodefactory.h"
#include "methodunit.h"

std::string CppCodeFactory::createClass(const std::string& className, const std::string& content) const {
    std::string validName = className.empty() ? "UnnamedClass" : className;
    return "class " + validName + " {\n" + content + "\n};\n";
}

std::string CppCodeFactory::createMethod(const std::string& returnType, const std::string& methodName, const std::string& params, Flags modifiers) const {
    std::string name = methodName.empty() ? "unnamedMethod" : methodName;
    std::string type = returnType.empty() ? "void" : returnType;
    std::string result = "    ";
    std::string methodModifier = getMethodModifier(modifiers);
    if (!methodModifier.empty()) {
        result += methodModifier + " ";
    }
    result += returnType + " " + methodName + "(" + params + ")";
    if (modifiers & MethodUnit::CONST) result += " const";
    return result;
}

std::string CppCodeFactory::getAccessModifier(int flags) const {
    static const std::vector<std::string> ACCESS_MODIFIERS = { "public", "protected", "private" };
    return (flags < ACCESS_MODIFIERS.size()) ? ACCESS_MODIFIERS[flags] : "private";
}

std::string CppCodeFactory::getMethodModifier(Flags modifier) const {
    if (modifier & MethodUnit::STATIC) return "static";
    if (modifier & MethodUnit::VIRTUAL) return "virtual";
    if (modifier & MethodUnit::CONST) return "const";
    if (modifier & MethodUnit::OVERRIDE) return "override";
    return "";
}

std::string CppCodeFactory::createPrintStatement(const std::string &text) const {
    return "std::cout << \"" + text + "\";\n";
}
