#ifndef wikipedia_functions_h
#define wikipedia_functions_h

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <curl.h> //your directory may be different
#include <list>
using namespace std;

namespace wikipedia_functions
{
	std::string content; //will hold the url's contents
	size_t writeCallback(char* buf, size_t size, size_t nmemb, void* up);
	void scrape(string topic);
	string remove_tags(string html_source);
}

#endif
