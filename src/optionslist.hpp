#ifndef OPTIONSLIST_HPP
#define OPTIONSLIST_HPP

#include<string>
#include<vector>
#include<iostream>
#include "ui_option.hpp"

typedef std::vector<std::pair<std::string, std::string>> OPTIONS_LIST;

static inline int createListFromStrings(OPTIONS_LIST vec_ls)
{
	if (!vec_ls.empty()) {
		for (size_t i = 0; i < vec_ls.size(); ++i) {
			createOption(vec_ls[i].first, vec_ls[i].second);
		}
	} else {
		std::cout << "Failed to print list of options.";
		return 1;
	}
	return 0;
}

#endif // OPTIONSLIST_HPP
