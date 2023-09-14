#include <iostream>

class Date
{
    int year_;
    int month_;
    int day_;

public:
    w int list[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    void SetDate(int year, int month, int day)
    {
        year_ = year;

        if (month <= 12 && month >= 1)
        {
            month_ = month;
        }
        else
        {
            printf("오류\n");
        }
        if (list[month - 1] >= day && 1 <= day)
        {
            day_ = day;
        }
        else
        {
            printf("오류\n");
        }
    }
    void AddMonth(int inc)
    {
        if (month_ + inc > 12)
            month_ = (month_ + inc) % 12;
        else
            month_ = month_ + inc;
    }
    void AddDay(int inc)
    {
        if (inc + day_ > list[month_ - 1])
        {
            while (day_ < list[month_ - 1])
            {
                day_ = day_ + inc - list[month_ - 1];
                AddMonth(1);
                if (day_ > list[month_ - 1])
                {
                    inc
                }
            }
        }

        else
            day_ = day_ + inc;
    }
};

int main()
{
}