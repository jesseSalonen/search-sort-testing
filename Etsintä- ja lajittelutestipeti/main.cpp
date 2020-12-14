#include <iostream>
#include "functions.h"
#include "Sortable_list.h"
using namespace std;

int main() {

	char choice = '-';
	int searches;
	while (choice != 'q') {

		cout << "Submenus:" << endl
			<< "a.) sequential search" << endl
			<< "b.) binary search" << endl
			<< "c.) insertion sort" << endl
			<< "q.) exit" << endl;
		cout << "Choose a submenu(a, b, c, q):";
		cin >> choice;
		if (choice != 'q' && choice != 'c') {
			cout << "How many searches of the data? ";
			cin >> searches;
		}

		if (choice == 'a') {
			int data;
			int j = 1;
			List data_list;


			cout << "Give the data size: ";
			cin >> data;


			for (int i = 0; i < data; i++) {
				Record r(j);
				data_list.insert(i, r);
				j += 2;
			}

			test_search(searches, data_list, -1);
		}

		if (choice == 'b') {
			int data;
			int j = 1;
			List data_list;
			cout << "Compare to sequential search? (y/n):";
			cin >> choice;
			if (choice == 'y') {
				Random number;
				data = number.random_integer(1, max_list);
				cout << "The data size randomly generated:" << data << endl;

				for (int i = 0; i < data; i++) {
					Record r(j);
					data_list.insert(i, r);
					j += 2;
				}

				test_search(searches, data_list, 1);
			}
			else {
				cout << "Give the data size: ";
				cin >> data;

				for (int i = 0; i < data; i++) {
					Record r(j);
					data_list.insert(i, r);
					j += 2;
				}

				test_search(searches, data_list, 0);
			}
		}

		if (choice == 'c') {
			int data, slice;
			List_entry x;
			Sortable_list data_list;
			Random number;

			cout << "Give the data size: ";
			cin >> data;

			for (int i = 0; i < data; i++) {
				Record r(number.random_integer(0, data * 10));
				data_list.insert(i, r);
			}
			cout << "Give the size of the slice area('0' for entire data):";
			cin >> slice;

			if (slice == 0) slice = data;

			cout << "Before sorting:" << endl;
			for (int i = 0; i < slice; i++) {
				data_list.retrieve(i, x);
				cout << x.key_value() << endl;
			}

			data_list.insertion_sort();

			cout << "After sorting:" << endl;
			for (int i = 0; i < slice; i++) {
				data_list.retrieve(i, x);
				cout << x.key_value() << endl;
			}
		}

	}


	return 0;
}
