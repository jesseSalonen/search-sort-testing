#include "functions.h"

#include <vector>

void test_search(int searches, List& the_list, int submenu)
/*

Pre:  None.
Post: The number of key comparisons and CPU time for a
      sequential searching function have been calculated.
Uses: Methods of the classes List, Random, and Timer,
      together with an output function print_out
*/
{
    int list_size = the_list.size();
    if (searches <= 0 || list_size < 0) {
        cout << " Exiting test: " << endl
            << " The number of searches must be positive." << endl
            << " The number of list entries must exceed 0." << endl;
        return;
    }
    int i, j, found_at;
    Key_type target;
    Key::comparisons = 0;
    Random number;
    Timer clock;

    if (submenu == -1) {
        for (i = 0; i < searches; i++) {
            target = 2 * number.random_integer(0, list_size - 1) + 1;
            if (sequential_search(the_list, target, found_at) == not_present)
                cout << "Error: Failed to find expected target " << target << endl;
        }
        print_out("Successful", clock.elapsed_time(), Key::comparisons, searches, submenu);

        Key::comparisons = 0;
        clock.reset();
        for (i = 0; i < searches; i++) {
            target = 2 * number.random_integer(0, list_size);
            if (sequential_search(the_list, target, found_at) == success)
                cout << "Error: Found unexpected target " << target
                << " at " << found_at << endl;
        }
        print_out("Unsuccessful", clock.elapsed_time(), Key::comparisons, searches, submenu);
    }

    else {
        
        vector<int> targets_even, targets_odd;
        for (i = 0; i < searches; i++) {
            targets_even.push_back(2 * number.random_integer(0, list_size));
        }
        for (i = 0; i < searches; i++) {
            targets_odd.push_back(2 * number.random_integer(0, list_size - 1) + 1);
        }
        for (j = 0; j <= submenu; j++) {
            if (j == 1) {
                cout << "sequential_search:" << endl;
                cout << "------------------" << endl;
            }
            else {
                cout << "recursive_binary_1:" << endl;
                cout << "------------------" << endl;
            }
            Key::comparisons = 0;
            clock.reset();
            for (i = 0; i < searches; i++) {
                target = targets_odd[i];
                if (j == 0) {
                    if (recursive_binary_1(the_list, target, 0, the_list.size() - 1, found_at) == not_present)
                        cout << "Error: Failed to find expected target " << target << endl;
                }
                else {
                    if (sequential_search(the_list, target, found_at) == not_present)
                        cout << "Error: Failed to find expected target " << target << endl;
                }
            }
            print_out("Successful", clock.elapsed_time(), Key::comparisons, searches, submenu);

            Key::comparisons = 0;
            clock.reset();
            for (i = 0; i < searches; i++) {
                target = targets_even[i];
                if (j == 0) {
                    if (recursive_binary_1(the_list, target, 0, the_list.size() - 1, found_at) == success)
                        cout << "Error: Found unexpected target " << target
                        << " at " << found_at << endl;
                }
                else {
                    if (sequential_search(the_list, target, found_at) == success)
                        cout << "Error: Found unexpected target " << target
                        << " at " << found_at << endl;
                }
            }
            print_out("Unsuccessful", clock.elapsed_time(), Key::comparisons, searches, submenu);
        }

    }

     
}

Error_code sequential_search(const List& the_list,
    const Key& target, int& position)
    /*
    Post: If an entry in the_list has key equal to target, then return
          success and the output parameter position locates such an entry
          within the list.
          Otherwise return not_present and position becomes invalid.
    */
{
    int s = the_list.size();
    for (position = 0; position < s; position++) {
        Record data;
        the_list.retrieve(position, data);
        if (data == target) return success;
    }
    return not_present;
}

void print_out(const string& result, const double& elapsed_time, const int& comparisons, const int& searches, int submenu)
{
    if (submenu == -1) {
        cout << "Status: " << result << endl;
        cout << "Total elapsed time: " << elapsed_time << endl;
        cout << "Total comparisons: " << comparisons << endl;
        cout << "Searches: " << searches << endl;
        cout << endl;
    }
    if (submenu == 0) {
        cout << "Status: " << result << endl;
        cout << "Elapsed per search: " << elapsed_time / (double)searches << endl;
        cout << "Comparisons per search: " << comparisons / (double)searches << endl;
        cout << "Searches: " << searches << endl;
        cout << endl;
    }
    if (submenu == 1) {
        cout << "Status: " << result << endl;
        cout << "Elapsed per search: " << elapsed_time / (double)searches << endl;
        cout << "Comparisons per search: " << comparisons / (double)searches << endl;
        cout << "Searches: " << searches << endl;
        cout << endl;
    }
}

Error_code recursive_binary_1(const List& the_list, const Key& target,
    int bottom, int top, int& position)
    /*
    Pre:  The indices bottom to top define the
          range in the list to search for the target.
    Post: If a Record in the range of locations
          from bottom to top in the_list has key equal
          to target, then position locates
          one such entry and a code of success is returned.
          Otherwise, the Error_code of not_present is returned
          and position becomes undefined.
    Uses: recursive_binary_1 and methods of the classes List and Record.
    */
{
    Record data;
    if (bottom < top) {              // List has more than one entry.
        int mid = (bottom + top) / 2;
        the_list.retrieve(mid, data);
        if (data < target)  // Reduce to top half of list.
            return recursive_binary_1(the_list, target, mid + 1, top, position);
        else                          // Reduce to bottom half of list.
            return recursive_binary_1(the_list, target, bottom, mid, position);
    }
    else if (top < bottom)
        return not_present;           // List is empty.
    else {                           // List has exactly one entry.
        position = bottom;
        the_list.retrieve(bottom, data);
        if (data == target) return success;
        else return not_present;
    }
}


