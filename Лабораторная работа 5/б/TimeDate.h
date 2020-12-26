#pragma once
#include "Time.h"
#include "Date.h"

class TimeDate :
    public Time, public Date
{
public:
    TimeDate(int h, int m, int s, int dd, int mm, int gg) : Time(h, m, s), Date(dd, mm, gg){}
    void print();
};

