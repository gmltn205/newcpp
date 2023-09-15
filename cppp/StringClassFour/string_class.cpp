#include <iostream>
#include <string.h>

class MyString
{
    char *string_content;
    int string_length;
    int memory_capacity;

public:
    int length() const;
    void print() const;
    void println() const;
    void reserve(int size);
    int capacity();
    ~MyString();
    MyString &insert(int loc, const MyString &str);
    MyString &insert(int loc, const char *str);
    MyString &insert(int loc, const char c);
    char at(int i) const;
    MyString &assign(const MyString &str);
    MyString &assign(const char *str);

    MyString(char c);
    MyString(char *str);
    MyString(const MyString &str);
};
char MyString::at(int i) const
{
    if (i >= string_length || i < 0)
    {
        return 0;
    }
    else
    {
        return string_content[i];
    }
}
MyString &MyString::insert(int loc, const char *str)
{
    MyString temp(str);
    return insert(loc, temp);
}
MyString &MyString::insert(int loc, const char c)
{
    MyString temp(c);
    return insert(loc, temp);
}
MyString &MyString::insert(int loc, const MyString &str)
{
    if (loc < 0 || loc > string_length)
    {
        return *this;
    }

    if (string_length + str.string_length > memory_capacity)
    {
        memory_capacity = string_length + str.string_length;
        char *prev_string_content = string_content;
        string_content = new char[memory_capacity];

        int i;
        for (i = 0; i < loc; i++)
        {
            string_content[i] = prev_string_content[i];
        }
        for (int j = loc; j < loc + str.string_length; i++)
        {
            string_content[j] = str.string_content[j];
        }
        for (; i < string_length; i++)
        {
            string_content[str.string_length + i] = prev_string_content[i];
        }
        delete[] prev_string_content;
        return *this;
    }
    delete[] string_content;
    for (int i = 0; i != loc; i++)
    {
    }
}
void MyString::reserve(int size)
{
    if (size > memory_capacity)
    {
        char *prev_string_content = string_content;
        string_content = new char[size];
        memory_capacity = size;

        for (int i = 0; i != string_length; i++)
        {
            string_content[i] = prev_string_content[i];
        }

        delete[] prev_string_content;
    }
}
int MyString::capacity()
{
    return memory_capacity;
}
MyString &MyString::assign(const MyString &str)
{
    string_length = str.string_length;

    if (memory_capacity < str.string_length)
    {
        delete[] string_content;
        string_content = new char[string_length];
        memory_capacity = str.string_length;
    }

    for (int i = 0; i != string_length; i++)
    {

        string_content[i] = str.string_content[i];
    }
    return *this;
}
MyString &MyString::assign(const char *str)
{
    string_length = strlen(str);
    if (memory_capacity < string_length)
    {
        delete[] string_content;

        string_content = new char[string_length];
        memory_capacity = string_length;
    }

    for (int i = 0; i != string_length; i++)
    {
        string_content[i] = str[i];
    }
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