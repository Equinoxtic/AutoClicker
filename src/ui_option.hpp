#ifndef UI_OPTION_HPP
#define UI_OPTION_HPP

#include<string>
#include<cstdio>

static inline int createOption(std::string main_s = "", std::string desc_s = "")
{
	if (!(main_s.empty() && desc_s.empty())) {
		printf("* [%s]\t:   \"%s\"\n", main_s.c_str(), desc_s.c_str());
	} else {
		printf("Failed to create option.");
		return 1;
	}
	return 0;
}

#endif // UI_OPTION_HPP
