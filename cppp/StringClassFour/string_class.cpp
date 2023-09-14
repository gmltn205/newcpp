#include <iostream>
#include <string.h>

class MyString
{
    char *string_content;
    int string_length;

public:
    int length() const;
    void print() const;
    void println() const;
    ~MyString();
    MyString(char c);
    MyString(char *str);
    MyString(const MyString &str);
};
void MyString::println() const
{
    int i;
    for (i = 0; i != string_length; i++)
    {
        std::cout << string_content[i];
    }
    std::cout << std::endl;
}
void MyString::print() const
{
    for (int i = 0; i != string_length; i++)
    {
        std::cout << string_content[i];
    }
}
int MyString::length() const
{
    return string_length;
}
MyString::MyString(char c)
{
    string_content = new char[1];
    string_content[0] = c;
    string_length = 1;
}
MyString::MyString(char *str)
{
    string_length = strlen(str);
    string_content = new char[string_length];
    for (int i = 0; i != string_length; i++)
        string_content[i] = str[i];
}
MyString::MyString(const MyString &str)
{
    string_length = str.string_length;
    string_content = new char[string_length];
    for (int i = 0; i != string_length; i++)
    {
        string_content[i] = str.string_content[i];
    }
}
MyString::~MyString()
{
    delete[] string_content;
}
int main()
{
    MyString str1("hellow world!");
    MyString str2(str1);

    str1.println();
    str2.println();
}