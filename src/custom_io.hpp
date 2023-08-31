#ifndef CUSTOM_IO_HPP
#define CUSTOM_IO_HPP

#include<string>
#include<sstream>
#include<cstdio>

static inline int printOut(std::string s = "", std::string end = "\n", std::string begin = "")
{
	std::ostringstream oss;
	if (!s.empty()) {
		oss << begin << s << end;
		printf("%s", oss.rdbuf()->str().c_str());
	} else {
		printf("String literal cannot be empty.");
		return 1;
	}
	return 0;
}

#endif // CUSTOM_IO_HPP
