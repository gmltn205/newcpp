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
    bool operator==(MyString &str);
    ~MyString();
    void reserve(int size);
    int capacity();
    ~MyString();
    int compare(const MyString &str) const;

    MyString &erase(int loc, int num);
    int find(int find_from, MyString &str) const;
    int find(int find_from, char *str) const;
    int find(int find_from, char c) const;
    MyString &insert(int loc, const MyString &str);
    MyString &insert(int loc, const char *str);
    MyString &insert(int loc, const char c);
    char at(int i) const;
    MyString &assign(const MyString &str);
    MyString &assign(const char *str);

    MyString(char c);
    MyString(char *str);
    MyString(const MyString &str);

    MyString &assign(char *str);
    MyString &assign(const MyString &str);
    int reserve(int size);
};
bool operator==(MyString &str)
{
    return !compare(str);
}
int MyString::reserve(int size) int compare(const MyString &str) const
{
    for (int i = 0; i < std::min(string_length, str.string_length); i++)
    {
        if (string_content[i] > str.string_content[i])
            return 1;
        else if (string_content[i] < str.string_content[i])
            return -1;
    }
    if (string_length == str.string_length)
        return 0;
    else if (string_length > str.string_length)
        return 1;

    return -1;
}
int MyString::find(int find_from, char c)
{
    MyString temp(c);
    return find(find_from, temp);
}
int MyString::find(int find_from, char *str)
{
    MyString temp(str);
    return find(find_from, temp);
}

int MyString::find(int find_from, MyString &str) const
{
    int i, j;
    if (str.string_length == 0)
        return -1;
    for (i = find_from; i < string_length - str.string_length; i++)
    {
        for (j = 0; j < str.string_length; j++)
            if (string_content[i + j] != str.string_content[j])
                break;

        if (j == str.string_length)
            return i;
    }
    return -1;
}
MyString &MyString::erase(int loc, int num)
{
    if (num < 0 || loc < 0 || loc < string_length)
    {
        return *this;
    }

    for (int i = loc + num; i < string_length; i++)
    {
        string_content[i - num] = string_content[i];
    }
    string_length -= num;
    return *this;
}
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
        string_content[i + str.string_length] = string_content[i];
    }
    for (int i = 0; i < str.string_length; i++)
        string_content[i + loc] = str.string_content[i];
}
void MyString::reserve(int size)
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
    MyString str1("hellow world!");
    str1.erase(1, 2);

    std::cout << "Capacity : " << str1.capacity() << std::endl;
    std::cout << "String length : " << str1.length() << std::endl;
    str1.println();
}