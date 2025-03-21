#include <QCoreApplication>
#include <iostream>
#include "classunit.h"
#include "methodunit.h"
#include "printoperatorunit.h"
#include "AbstractCodeFactory.h"
#include "cppcodefactory.h"
#include "csharpcodefactory.h"
#include "javacodefactory.h"

std::string generateBrokenProgram(const AbstractCodeFactory* factory, const std::string& language) {
    if(factory == nullptr) return "Factory not provided";

    ClassUnit brokenClass("BrokenClass");

    // Пустое имя метода, неизвестный тип возвращаемого значения
    auto invalidMethod = std::make_shared<MethodUnit>("", "???", static_cast<Flags>(999));
    invalidMethod->add(std::make_shared<PrintOperatorUnit>("")); // Пустой вывод
    brokenClass.add(invalidMethod, ClassUnit::PUBLIC);

    // Метод с некорректным модификатором доступа
    auto anotherInvalid = std::make_shared<MethodUnit>("unknownMethod", "void", MethodUnit::STATIC);
    anotherInvalid->add(std::make_shared<PrintOperatorUnit>("Broken method test"));
    brokenClass.add(anotherInvalid, static_cast<ClassUnit::AccessModifier>(-1)); // Некорректный модификатор

    return brokenClass.compile(0, factory);
}

std::string generateProgram(const AbstractCodeFactory* factory, const std::string& language) {
    if(factory == nullptr) return "Factory not provided";

    ClassUnit myClass("Class");

    // Создание методов с разными модификаторами и доступом
    auto publicMethod = std::make_shared<MethodUnit>("publicMethod", "void", MethodUnit::STATIC);
    publicMethod->add(std::make_shared<PrintOperatorUnit>(R"(This is a public static method in )" + language + R"(!)"));
    myClass.add(publicMethod, ClassUnit::PUBLIC);

    auto protectedMethod = std::make_shared<MethodUnit>("protectedMethod", "int", MethodUnit::VIRTUAL | MethodUnit::CONST);
    protectedMethod->add(std::make_shared<PrintOperatorUnit>(R"(Protected virtual method returning 42)"));
    myClass.add(protectedMethod, ClassUnit::PROTECTED);

    auto privateMethod = std::make_shared<MethodUnit>("privateMethod", "string", MethodUnit::FINAL);
    privateMethod->add(std::make_shared<PrintOperatorUnit>(R"(Private final method called)"));
    myClass.add(privateMethod, ClassUnit::PRIVATE);

    auto internalMethod = std::make_shared<MethodUnit>("internalMethod", "bool", MethodUnit::ASYNC);
    internalMethod->add(std::make_shared<PrintOperatorUnit>(R"(Internal async method executed)"));
    myClass.add(internalMethod, ClassUnit::INTERNAL);

    return myClass.compile(0, factory);
}

int main() {
    CppCodeFactory cppFactory;
    CSharpCodeFactory csharpFactory;
    JavaCodeFactory javaFactory;

    std::cout << "C++ Code:\n" << generateProgram(&cppFactory, "C++") << std::endl;
    std::cout << "C# Code:\n" << generateProgram(&csharpFactory, "C#") << std::endl;
    std::cout << "Java Code:\n" << generateProgram(&javaFactory, "Java") << std::endl;
    // std::cout << "\n--- Testing Broken Input ---\n";
    // std::cout << "C++ Broken Code:\n" << generateBrokenProgram(&cppFactory, "C++") << std::endl;
    // std::cout << "C# Broken Code:\n" << generateBrokenProgram(&csharpFactory, "C#") << std::endl;
    // std::cout << "Java Broken Code:\n" << generateBrokenProgram(&javaFactory, "Java") << std::endl;

    return 0;
}
