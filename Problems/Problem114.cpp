#include "Problem114.h"


/*
This problem was asked by Facebook.

Given a string and a set of delimiters, reverse the words in the string while maintaining the relative order of the delimiters. 
For example, given "hello/world:here", return "here/world:hello"

Follow-up: Does your solution work for the following cases: "hello/world:here/", "hello//world:here"
*/



void reverse(std::string& str, size_t begin, size_t end)
{
    if (str.length() <= end || begin >= end)
        return;

    while (begin < end)
    {
        std::swap(str[begin++], str[end--]);
    }
}

void reverse(std::string& str)
{
    std::cout << str.c_str() << std::endl;
    size_t sz = str.length();
    size_t msz = sz / 2;

    // Reverse whole string
    reverse(str, 0, sz - 1);

    // Reverse delimiters
    size_t bi = sz - 1;
    for (size_t i = 0; i < msz; i++)
    {
        bool leftFound = false;
        while (i < msz)
        {
            if (str[i] == '/' || str[i] == ':')
            {
                leftFound = true;
                break;
            }
            ++i;
        }

        bool rightFound = false;
        while (bi > msz)
        {
            if (str[bi] == '/' || str[bi] == ':')
            {
                rightFound = true;
                break;
            }
            --bi;
        }

        if (leftFound && rightFound)
            std::swap(str[i], str[bi++]);
        else
            break;
    }

    // Reverse words
    for (size_t i = 0; i < sz; i++)
    {
        if (str[i] == '/' || str[i] == ':')
            continue;

        size_t endOfWord = i + 1;
        // Find end of the word
        while (endOfWord < sz)
        {
            if (str[endOfWord] == '/' || str[endOfWord] == ':')
            {
                --endOfWord;
                break;
            }
            else if (endOfWord + 1 == sz)
            {
                break;
            }
            ++endOfWord;
        }
        reverse(str, i, endOfWord);
        i = endOfWord + 1;
    }
    std::cout << str.c_str() << std::endl;
}

void reverse2(std::string& str)
{
    std::cout << str.c_str() << std::endl;
    size_t sz = str.length();
    size_t msz = sz / 2;

    // Reverse whole string
    size_t begin = 0;
    size_t end = sz - 1;
    while (begin < end)
    {

        std::swap(str[begin++], str[end--]);
    }

    // Reverse delimiters
    size_t bi = sz - 1;
    for (size_t i = 0; i < msz; i++)
    {
        bool leftFound = false;
        while (i < msz)
        {
            if (str[i] == '/' || str[i] == ':')
            {
                leftFound = true;
                break;
            }
            ++i;
        }

        bool rightFound = false;
        while (bi > msz)
        {
            if (str[bi] == '/' || str[bi] == ':')
            {
                rightFound = true;
                break;
            }
            --bi;
        }

        if (leftFound && rightFound)
            std::swap(str[i], str[bi++]);
        else
            break;
    }

    // Reverse words
    for (size_t i = 0; i < sz; i++)
    {
        if (str[i] == '/' || str[i] == ':')
            continue;

        size_t endOfWord = i + 1;
        // Find end of the word
        while (endOfWord < sz)
        {
            if (str[endOfWord] == '/' || str[endOfWord] == ':')
            {
                --endOfWord;
                break;
            }
            else if (endOfWord + 1 == sz)
            {
                break;
            }
            ++endOfWord;
        }
        reverse(str, i, endOfWord);
        i = endOfWord + 1;
    }
    std::cout << str.c_str() << std::endl;
}

void Problem114::run()
{
    {
        std::string str1{ "hello/world:here" };
        std::string str2{ "here/world:hello" };
        reverse(str1);
        check(str1 == str2);
    }

    {
        std::string str1{ "hello/world:here/" };
        std::string str2{ "here/world:hello/" };
        reverse(str1);
        check(str1 == str2);
    }

    {
        std::string str1{ "hello//world:here" };
        std::string str2{ "here//world:hello" };
        reverse(str1);
        check(str1 == str2);
    }

    return;
}