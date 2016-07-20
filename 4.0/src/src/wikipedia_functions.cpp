#include "wikipedia_functions.h"


size_t wikipedia_functions::writeCallback(char* buf, size_t size, size_t nmemb, void* up)
{ //callback must have this declaration
  //buf is a pointer to the data that curl has for us
  //size*nmemb is the size of the buffer

	for (size_t c = 0; c<size*nmemb; c++)
		wikipedia_functions::content.push_back(buf[c]);
	return size*nmemb; //tell curl how many bytes we handled
}
void wikipedia_functions::scrape(string topic)
{
	wikipedia_functions::content.clear(); //clears content before using
	CURL* curl; //our curl object

	curl_global_init(CURL_GLOBAL_ALL); //pretty obvious
	curl = curl_easy_init();

	curl_easy_setopt(curl, CURLOPT_URL, "https://en.wikipedia.org/wiki/" + topic);
	curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1);
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &wikipedia_functions::writeCallback);
	curl_easy_perform(curl);
	curl_easy_cleanup(curl);
	curl_global_cleanup();
}

string wikipedia_functions::remove_tags(string html_source)
{
	string buffer; //contains the information with tags filtered out
	bool push = true;
	for (size_t i = 0; i < html_source.length(); i++)
	{
		if (html_source[i] == '<')
			push = false;
		else if (push == false && html_source[i] == '>')
		{
			push = true;
			continue;
		}
		if (push)
			buffer.push_back(html_source[i]);
	}
	return buffer;
}