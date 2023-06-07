#pragma warning(disable:4996)

#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <math.h>

using namespace std;

class Time {
    int hours;
    int minutes;
    int seconds;
    void transfer() {
        seconds = (hours * 60 * 60) + (minutes * 60) + seconds;

        hours = (seconds / 60) / 60; 
        seconds -= ((hours * 60) * 60);

        minutes = seconds / 60;
        seconds -= (minutes * 60);
    }
public:
    Time(int h, int m, int s) : hours{ h }, minutes{ m }, seconds{ s } {
        transfer();
    }
    Time(int h, int m) :Time{ h,m,0 } {};
    Time(int h) : Time{ h,0,0 } {  };
    Time() : Time{ 0,0,0 } {  };
    
    Time& operator()(int x) {
        seconds += x;
        transfer();
        return *this;
    }
    Time& operator++() {
        seconds++;
        transfer();
        return *this;
    }
    Time operator++(int) {
        Time temp(*this);
        seconds++;
        transfer();
        return temp;
    }

    Time& operator+=(int x) {
        seconds += x;
        transfer();
        return *this;
    }

    Time& operator-=(int x) {
        seconds -= x;
        transfer();
        return *this;
    }

    friend bool operator==(const Time& t1, const Time& t2);
    friend ostream& operator<<(ostream& out, const Time& t1);
    friend istream& operator>>(istream& in, Time& t1);
    friend bool operator>(const Time& t1, const Time& t2);

    
};

ostream& operator<<(ostream& out,const Time& t1) {
    out << "Часы: " << t1.hours << "\nМинут: " << t1.minutes << "\nСекунд: " << t1.seconds << endl;
    return out;
}

istream& operator>>(istream& in, Time& t1) {
    in >> t1.hours >> t1.minutes >> t1.seconds;
    t1.transfer();
    return in;
}

bool operator==(const Time& t1,const Time& t2) {
    return t1.hours == t2.hours &&
        t1.minutes == t2.minutes &&
        t1.seconds == t2.seconds;
}
bool operator!=(const Time& t1, const Time& t2) {
    return !(t1 == t2);
}

bool operator>(const Time& t1, const Time& t2) {
    return (t1.hours * 60 * 60 + t1.minutes * 60 + t1.seconds) > (t2.hours * 60 * 60 + t2.minutes * 60 + t2.seconds);
}
bool operator<(const Time& t1, const Time& t2) {
    return !(t1 > t2) && (t1 == t2);
}

class Date {
    int day;
    int month;
    int year;

    void transfer() {

        day += year * 360;
        day += month * 30;

        year = day / 360;
        day -= year * 360;
        
        
        month = day / 30;
        day -= month * 30;
        /*
        нахождение високосного года через цикл, но косячит
        for (int i = 0; i < month; month--) {
            if (month == 1) {
                day += 31;
            }
            if (month == 2 && year % 4 ==0) {
                day += 29;
            }
            else if (month == 2 && year % 4 != 0) {
                day += 28;
            }
            if (month == 3 ){
                day += 31;
            }
            if (month == 4) {
                day += 30;
            }
            if (month == 5) {
                day += 31;
            }
            if (month == 6) {
                day += 30;
            }
            if (month == 7) {
                day += 31;
            }
            if (month == 8) {
                day += 31;
            }
            if (month == 9) {
                day += 30;
            }
            if (month == 10) {
                day += 31;
            }
            if (month == 11) {
                day += 30;
            }
            if (month == 12) {
                day += 31;
            }
        }

        for (int i = 0; i < year; year--) {
            if (year % 4 == 0) {
                day += 366;
            }
            else {
                day += 365;
            }
        }
        

        while(day > 365){
            if (year % 4 == 0) {
                day -= 366;
            }
            else {
                day -= 365;
            }
            year++;
        }

        month = 4;

        while (day > 31) {

            if (month == 1) {
                day -= 31;
                month++;
            }else if (month == 2 && year % 4 == 0) {
                day -= 29;
                month++;
            }else if (month == 2 && year % 4 != 0) {
                day -= 28;
                month++;
            }else if (month == 3) {
                day -= 31;
                month++;
            }else if (month == 4) {
                day -= 30;
                month++;
            }else if (month == 5) {
                day -= 31;
                month++;
            }else if (month == 6) {
                day -= 30;
                month++;
            }else if (month == 7) {
                day -= 31;
                month++;
            }else if (month == 8) {
                day -= 31;
                month++;
            }else if (month == 9) {
                day -= 30;
                month++;
            }else if (month == 10) {
                day -= 31;
                month++;
            }else if (month == 11) {
                day -= 30;
                month++;
            }else if (month == 12) {
                day -= 31;
                month++;
            }else {
                break;
            }
            
        }

        */
    }

public:
    Date(int d, int m, int y) : year{ y }, month{ m }, day{ d } {
        transfer();
    }
    Date(int y, int m) :Date{ y,m,1 } {};
    Date(int y) : Date{ y,1,1 } {  };
    Date() : Date{ 1,1,1 } {  };

    Date& operator()(int x) {
        day += x;
        transfer();
        return *this;
    }
    Date& operator++() {
        day++;
        transfer();
        return *this;
    }
    Date operator++(int) {// постфиксная
        Date temp(*this);
        day++;
        transfer();
        return temp;
    }

    Date& operator+=(int x) {
        day += x;
        transfer();
        return *this;
    }

    Date& operator-=(int x) {
        day -= x;
        transfer();
        return *this;
    }

    friend bool operator==(const Date& d1, const Date& d2);
    friend ostream& operator<<(ostream& out, const Date& d1);
    friend istream& operator>>(istream& in, Date& d1);
    friend bool operator>(const Date& d1, const Date& d2);

};

bool operator==(const Date& d1, const Date& d2) {
    return d1.day == d2.day &&
        d1.month == d2.month &&
        d1.year == d2.year;
}
bool operator!=(const Date& d1, const Date& d2) {
    return !(d1 == d2);
}

bool operator>(const Date& d1, const Date& d2) {
    return (d1.year * 360 + d1.month * 30 + d1.day) > (d2.year * 360 + d2.month * 30 + d2.day);
}
bool operator<(const Date& d1, const Date& d2) {
    return !(d1 > d2) && (d1 == d2);
}

ostream& operator<<(ostream& out, const Date& d1) {
    out << "День: " << d1.day << "\nМесяц: " << d1.month << "\nГод: " << d1.year << endl;
    return out;
}
istream& operator>>(istream& in, Date& d1) {
    in >> d1.year >> d1.month >> d1.day;
    d1.transfer();
    return in;
}

int main() {

    setlocale(0, "");
    srand(time(NULL));

    /*Time Zilean{ 5,10,50 };
    Zilean += 12;
    cout << Zilean;*/

    Date dpo{ 10,4,2000 };
    dpo += 40;
    cout << dpo;
}
