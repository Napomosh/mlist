#include "mlist.h"
int main() {
	ns::mlist<int> l(3);
	l.push_back(4);
	l.push_back(3);

	ns::mlist<int> l1;
	l1 = l;
	l1.print_list();
	return 0;
}