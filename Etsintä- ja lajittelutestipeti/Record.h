#pragma once
#include "Key.h"
typedef Key Record_type;
//  Definition of a Record class:
class Record {
public:
    Record();
    Record(Key_type x);
    Key_type key_value() const;
    void operator =(const Record& y);
    operator Record_type(); //  implicit conversion from Record to Key.
   //  Add any constructors and methods for Record objects.
private:
    Record_type value;
    //  Add data components.
};
