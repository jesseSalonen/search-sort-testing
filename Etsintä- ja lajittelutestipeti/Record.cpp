#include "Record.h"

Record::Record()
{
}

Record::Record(Key_type x)
{
	value.set_key(x);
}

Key_type Record::key_value() const
{
	return value.the_key();
}

void Record::operator=(const Record& y)
{
	Key_type x = y.value.the_key();
	value.set_key(x);
}


Record::operator Record_type()
{
	return value.the_key();
}
