#include <iostream>
#include <string>
#include "Stack.h"
#include "StackArray.h"

bool checkBalanceBrackets(const std::string& text, int maxDeep = 30);
bool testCheckBalanceBrackets();

int main()
{
    testCheckBalanceBrackets();
	return 0;
}

bool checkBalanceBrackets(const std::string& text, int maxDeep)
{
    StackArray<char> stack(maxDeep);
    try
    {
        for (int i = 0; i < text.length(); i++)
        {
            if (text[i] == '(' || text[i] == '[' || text[i] == '{')
            {
                stack.push(text[i]);
                continue;
            }
            if (text[i] == ')')
            {
                if (stack.pop() != '(')
                {
                    return false;
                }
                continue;
            }
            if (text[i] == '}')
            {
                if (stack.pop() != '{')
                {
                    return false;
                }
                continue;
            }
            if (text[i] == ']')
            {
                if (stack.pop() != '[')
                {
                    return false;
                }
            }
        }
    }
    catch (Stack<char>::StackException& error)
    {
        return false;
    }
    return stack.isEmpty();
}

bool testCheckBalanceBrackets()
{
    const char* text00 = " ";
    std::cout << text00 << ": " << (checkBalanceBrackets(text00) ? "Right" : "Error") << "\n";
    const char* text01 = "( )  ";
    std::cout << text01 << ": " << (checkBalanceBrackets(text01) ? "Right" : "Error") << "\n";
    const char* text02 = "( ( [] ) )  ";
    std::cout << text02 << ": " << (checkBalanceBrackets(text02) ? "Right" : "Error") << "\n";
    const char* text03 = "( ( [ { } [ ] ( [ ] ) ] ) ) ";
    std::cout << text03 << ": " << (checkBalanceBrackets(text03) ? "Right" : "Error") << "\n";
    const char* text04 = "( ( [ { } [ ] ( [ ] ) ] ) ) ) ";
    std::cout << text04 << ": " << (checkBalanceBrackets(text04) ? "Right" : "Error") << "\n";
    const char* text05 = "( ( [{ }[ ]([ ])] ) ";
    std::cout << text05 << ": " << (checkBalanceBrackets(text05) ? "Right" : "Error") << "\n";
    const char* text06 = "( ( [{ ][ ]([ ])]) ) ";
    std::cout << text06 << ": " << (checkBalanceBrackets(text06) ? "Right" : "Error") << "\n";

    return true;
}