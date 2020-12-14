#pragma once
typedef int Key_type;
//  Definition of a Key class:
class Key {
	Key_type key;
public:
	static int comparisons;
	Key(Key_type x = 0);
	int the_key() const;
	void set_key(Key_type x);
};

bool operator ==(const Key& x, const Key& y);
bool operator >(const Key& x, const Key& y);
bool operator <(const Key& x, const Key& y);
bool operator >=(const Key& x, const Key& y);
bool operator <=(const Key& x, const Key& y);
bool operator !=(const Key& x, const Key& y);
