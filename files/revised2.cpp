//
// $Id: revised2.cpp,v 0.22 2021/11/27 03:33:33 kc4zvw Exp kc4zvw $
//

#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>
#include <locale>				// std::locale
#include <ostream>
#include <ctime>
#include <chrono>

using namespace std;

const char fmt[] = "Revised: %A, %B %d, %Y at %H:%M:%S %p (%Z)";
const tm* Today; 
struct tm timeinfo;

int main()
{
	// Current date/time based on current system
	time_t now = time(nullptr);

	// Convert now to string form
	char *dt = ctime(&now);
	timeinfo = *(localtime(&now));
	Today = &timeinfo;

	using chrono::system_clock;
	time_t tt = system_clock::to_time_t(system_clock::now());

	struct tm *ptm = localtime(&tt);

	//cout << put_time(Today, "Revised: %A, %B %d, %Y at %H:%M:%S %p (%Z)") << endl;
	//cout << "Now (local time): " << put_time(ptm, "%c") << endl;

	cout << put_time(Today, fmt) << endl;

	return 0;
}

/* End of File */
