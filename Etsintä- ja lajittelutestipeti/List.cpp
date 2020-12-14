#include "List.h"

List::List()
/*
Post: The List has been created and is initialized to be empty
*/
{
    count = 0;
}


int List::size() const
/*
Post: The function returns the number of entries in the List.
*/
{
    return count;
}


bool List::full() const
/*
Post: The function returns true or false according to whether
the List is full or not.
*/
{
    if (count == max_list) return true;
    else return false;
}


bool List::empty() const
/*
Post: The function returns true or false according to whether
the List is empty or not.
*/
{
    if (count == 0) return true;
    else return false;
}


void List::clear()
/*
Post: All List entries have been removed; the List is empty.
*/
{
    count = 0;
}



Error_code List::insert(int position, const List_entry& x)
/*
Post: If the List is not full and 0 <= position <= n,
      where n is the number of entries in the List, the function succeeds:
      Any entry formerly at position and all later entries have their
      position numbers increased by 1 and x is inserted at position of the List.
      Else: The function fails with a diagnostic error code.
*/
{
    if (full())
        return overflow;

    if (position < 0 || position > count)
        return utility_range_error;

    for (int i = count - 1; i >= position; i--)
        entry[i + 1] = entry[i];

    entry[position] = x;
    count++;
    return success;
}



void List::traverse(void (*visit)(List_entry&))
/*
Post: The action specified by function (*visit) has been performed on every
      entry of the List, beginning at position 0 and doing each in turn.
*/
{
    for (int i = 0; i < count; i++)
        (*visit)(entry[i]);
}


Error_code List::retrieve(int position, List_entry& x) const
/*
Post: If 0 ≤ position < n, where n is the number of entries
in the List, the function succeeds: The entry at position
is copied to x; all List entries remain unchanged.
Else: The function fails with a diagnostic error code.
*/
{
    if (empty())
        return underflow;

    if (position < 0 || position >= count)
        return utility_range_error;
    x = entry[position];
    return success;
}


Error_code List::replace(int position, const List_entry& x)
/*
Post: If 0 ≤ position < n, where n is the number of entries
in the List, the function succeeds: The entry at position
is replaced by x; all other entries remain unchanged.
Else: The function fails with a diagnostic error code.

*/
{
    if (empty())
        return underflow;

    if (position < 0 || position >= count)
        return utility_range_error;
    entry[position] = x;
    return success;
}


Error_code List::remove(int position, List_entry& x)
/*
Post: If 0 ≤ position < n, where n is the number of entries in
the List, the function succeeds: The entry at position is
removed from the List, and all later entries have their
position numbers decreased by 1. The parameter x
records a copy of the entry formerly at position.
Else: The function fails with a diagnostic error code.
*/
{
    if (empty())
        return underflow;

    if (position < 0 || position >= count)
        return utility_range_error;
    x = entry[position];
    for (int i = position; i < count - 1; i++)
        entry[i] = entry[i + 1];
    count--;
    return success;
}