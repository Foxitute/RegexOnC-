#include <iostream>
#include <string>
#include <regex>

void regex_match(std::string str)
{
// regex_match
//   ([a-z ]){0, 99999} \\w - for letters, \\s - space

	std::cmatch result;
	std::regex regular("([\\w-]+)"
					   "(@)"
					   "([\\w-]+)"
			   		   "(\.)"
					   "(\\w{2,5})"); // 2-5 symbols

// Convert to c-string
	if (std::regex_match(str.c_str(), result, regular))
	{
		for (int i = 0; i < result.size(); i++)
		{
			std::cout << result[i] << std::endl;
		}
	}
}


void regex_search1(std::string str)
{
	//regex_search

	std::cmatch result;
	std::regex regular(
					   "([\\w-]+:\\s)" // word, ':'sign with space
					   "([\\w-]+)" // can be letter, number and '-'sign
					   "(@)"	   // '@'sign
					   "([\\w-]+)" // can be letter, number and '-'sign
					   "\."		   // '.'sign
					   "(\\w{2,5})");//  can be letter (2-5 length)

	if (std::regex_search(str.c_str(), result, regular))
	{
		for (int i = 0; i < result.size(); i++)
		{
			std::cout << result[i] << std::endl;
		}
	}
}

void regex_search2(std::string str)
{
	std::cmatch result;
	std::regex regular( "(: )"
						"([.]*[^\.]+)" // any quantity of any symbols| before '.'sing
						"(\.)");

	if (std::regex_search(str.c_str(), result, regular))
	{
		for (int i = 0; i < result.size(); i++)
		{
			std::cout << result[i] << std::endl;
		}
	}
}

void regex_replace(std::string str)
{
	std::regex regular("(: )"
					   "([.]*[^\.]+)"
				   	   "(\.)");

	std::string result = regex_replace(str.c_str(), regular, " ---lulz--- ");
	std::cout << result << std::endl;
}



int main()
{
	std::cout << "REGEX_MATCH" << std::endl;
	std::string email = "grigorchukmaxon1@gmail.com";
	regex_match(email);

	std::cout << "\nREGEX_SEARCH\nFirst Example" << std::endl;
	std::string strWithEmail = "MyEmail: email@host.ua LOL11!!!";
	regex_search1(strWithEmail);
	
	std::cout << "\nREGEX_SEARCH\nSecond Example" << std::endl;
	std::string str2WithEmail = "MyEmail: email@host.ua LOL11!!!";
	regex_search2(str2WithEmail);

	std::cout << "\nREGEX_REPLACE" << std::endl;
	std::string str3WithEmail = "MyEmail: email@cuteNinja.org LOL11!!!";
	regex_replace(str3WithEmail);
}