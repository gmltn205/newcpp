#include <iostream>
#include <string.h>

class MyString
{
    char *string_content;
    int string_length;
    int memory_capacity;

public:
    int length() const;
    int capacity() const;
    void print() const;
    void println() const;

    ~MyString();

    MyString(char c);
    MyString(char *str);
    MyString(const MyString &str);

    MyString &assign(char *str);
    MyString &assign(const MyString &str);
    int reserve(int size);
};
int MyString::reserve(int size)
{
    if (size > memory_capacity)
    {
        char *prev_string_content = string_content;

        string_content = new char[size];
        memory_capacity = size;

        for (int i = 0; i != string_length; i++)
            string_content[i] = prev_string_content[i];
        delete[] prev_string_content;
    }
}
MyString::MyString(char c)
{
    string_content = new char[1];
    string_content[0] = c;
    string_length = 1;
    memory_capacity = 1;
}
MyString::MyString(char *str)
{
    string_length = strlen(str);
    memory_capacity = string_length;
    string_content = new char[string_length];
    for (int i = 0; i != string_length; i++)
        string_content[i] = str[i];
}

MyString::MyString(const MyString &str)
{
    string_length = str.string_length;
    memory_capacity = str.string_length;
    string_content = new char[string_length];
    for (int i = 0; i != string_length; i++)
    {
        string_content[i] = str.string_content[i];
    }
}
MyString &MyString::assign(const MyString &str)
{
    if (str.string_length > memory_capacity)
    {
        delete[] string_content;
        memory_capacity = str.string_length;
        string_content = new char[str.string_length];
    }
    for (int i = 0; i != str.string_length; i++)
    {
        string_content[i] = str.string_content[i];
    }
    string_length = str.string_length;
    return *this;
}
MyString &MyString::assign(char *str)
{
    int str_length = strlen(str);
    if (str_length > memory_capacity)
    {
        delete[] string_content;
        memory_capacity = str_length;
        string_content = new char[str_length];
    }
    for (int i = 0; i != str_length; i++)
    {
        string_content[i] = str[i];
    }
    string_length = str_length;
    return *this;
}

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
int MyString::capacity() const { return memory_capacity; }
int MyString::length() const
{
    return string_length;
}

MyString::~MyString()
{
    delete[] string_content;
}
int main()
{
    MyString str1("very very very long string");
    str1.reserve(30);

    std::cout << "Capacity : " << str1.capacity() << std::endl;
    std::cout << "String length : " << str1.length() << std::endl;
    str1.println();
}