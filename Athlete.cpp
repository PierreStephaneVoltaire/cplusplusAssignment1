
#include "Athlete.h"
#include "Person.h"
using namespace std;

/*!
 * \overload std::ostream &operator<<(std::ostream &out, Athlete &a)
 */

std::ostream &operator<<(std::ostream &out, Athlete &a) {
	out << "First Name: " << a.getFirstame() << "\n"
		<< "Last Name: " << a.getLastname() << "\n"
		<< "Nationality:" << a.getNationality() << "\n"
		<< "Distance: " << a.getDistance() << "\n";
	return out;
}
