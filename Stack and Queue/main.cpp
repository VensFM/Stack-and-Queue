#include <iostream>
#include <string>
#include "Stack.h"
#include "StackArray.h"
#include "Queue.h"
#include "QueueArray.h"

bool testStackArray();
bool checkBalanceBrackets(const std::string& text, int maxDeep = 30);
bool testCheckBalanceBrackets();
bool testQueueArray();

int main()
{
    testStackArray();
    testCheckBalanceBrackets();
    testQueueArray();

	return 0;
}

bool testStackArray()
{
    system("cls");
    std::cout << "    1.Test StackArray:\n\nStandard error checking:\n";
    try
    {
        StackArray<int> test(0);
    }
    catch (Stack<int>::StackException& error)
    {
        std::cerr << error.getMessage();
    }
    try
    {
        StackArray<long> test(99999999999999999);
    }
    catch (Stack<long>::StackException& error)
    {
        std::cerr << error.getMessage();
    }
    try
    {
        StackArray<int> test(1);
        test.push(0);
        test.push(0);
    }
    catch (Stack<int>::StackException& error)
    {
        std::cerr << error.getMessage();
    }
    try
    {
        StackArray<int> test(1);
        test.pop();
    }
    catch (Stack<int>::StackException& error)
    {
        std::cerr << error.getMessage();
    }
    system("pause");
    system("cls");
    return true;
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
    system("cls");
    std::cout << "    2.Test CheckBalanceBrackets:\n\n";
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

    system("pause");
    system("cls");
    return true;
}

bool testQueueArray()
{
    system("cls");
    std::cout << "    3.Test QueueArray:\n\nStandard error checking:\n";
    try
    {
        QueueArray<int> test(0);
    }
    catch (Queue<int>::QueueException& error)
    {
        std::cerr << error.getMessage();
    }
    try
    {
        QueueArray<long> test(99999999999999999);
    }
    catch (Queue<long>::QueueException& error)
    {
        std::cerr << error.getMessage();
    }
    try
    {
        QueueArray<int> test(1);
        test.enQueue(0);
        test.enQueue(0);
    }
    catch (Queue<int>::QueueException& error)
    {
        std::cerr << error.getMessage();
    }
    try
    {
        QueueArray<int> test(1);
        test.deQueue();
    }
    catch (Queue<int>::QueueException& error)
    {
        std::cerr << error.getMessage();
    }
    system("pause");
    system("cls");
    return true;
}