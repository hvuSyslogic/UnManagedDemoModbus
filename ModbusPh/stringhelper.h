#include <string>
#include <sstream>
#include <vector>
#include <exception>
#include <algorithm>
using namespace std;
class StringHelper
{
public:
	static string toLower(string source)
	{
		::transform(source.begin(), source.end(), source.begin(), ::tolower);
		return source;
	}

	static  string toUpper(string source)
	{
		transform(source.begin(), source.end(), source.begin(), toupper);
		return source;
	}

	static  string trimStart(string source, const  string &trimChars = " \t\n\r\v\f")
	{
		return source.erase(0, source.find_first_not_of(trimChars));
	}

	static  string trimEnd(string source, const  string &trimChars = " \t\n\r\v\f")
	{
		return source.erase(source.find_last_not_of(trimChars) + 1);
	}

	static  string trim(string source, const  string &trimChars = " \t\n\r\v\f")
	{
		return trimStart(trimEnd(source, trimChars), trimChars);
	}

	static  string replace(string source, const  string &find, const  string &replace)
	{
		size_t pos = 0;
		while ((pos = source.find(find, pos)) != string::npos)
		{
			source.replace(pos, find.length(), replace);
			pos += replace.length();
		}
		return source;
	}

	static bool startsWith(const  string &source, const  string &value)
	{
		if (source.length() < value.length())
			return false;
		else
			return source.compare(0, value.length(), value) == 0;
	}

	static bool endsWith(const  string &source, const  string &value)
	{
		if (source.length() < value.length())
			return false;
		else
			return source.compare(source.length() - value.length(), value.length(), value) == 0;
	}

	static  vector< string> split(const  string &source, char delimiter)
	{
		vector< string> output;
		istringstream ss(source);
		string nextItem;

		while (getline(ss, nextItem, delimiter))
		{
			output.push_back(nextItem);
		}

		return output;
	}

	template<typename T>
	static  string toString(const T &subject)
	{
		ostringstream ss;
		ss << subject;
		return ss.str();
	}

	template<typename T>
	static T fromString(const  string &subject)
	{
		istringstream ss(subject);
		T target;
		ss >> target;
		return target;
	}

	static bool isEmptyOrWhiteSpace(const  string &source)
	{
		if (source.length() == 0)
			return true;
		else
		{
			for (unsigned int index = 0; index < source.length(); index++)
			{
				if (!isspace(source[index]))
					return false;
			}

			return true;
		}
	}

	template<typename T>
	static  string formatSimple(const  string &input, T arg0)
	{
		ostringstream ss;
		int lastCloseBrace = -1;
		int openBrace = -1;
		while ((openBrace = input.find('{', openBrace + 1)) > -1)
		{
			if (openBrace + 1 < input.length())
			{
				if (input[openBrace + 1] == '{')
				{
					openBrace++;
					continue;
				}

				int closeBrace = input.find('}', openBrace + 1);
				if (closeBrace > -1)
				{
					ss << input.substr(lastCloseBrace + 1, openBrace - lastCloseBrace - 1);
					lastCloseBrace = closeBrace;

					string index = trim(input.substr(openBrace + 1, closeBrace - openBrace - 1));
					if (index == "0")
						ss << arg0;
					else
						throw  exception("Only simple positional format specifiers are handled by the 'formatSimple' helper method.");
				}
			}
		}

		if (lastCloseBrace + 1 < input.length())
			ss << input.substr(lastCloseBrace + 1);

		return ss.str();
	}

	template<typename T1, typename T2>
	static  string formatSimple(const  string &input, T1 arg0, T2 arg1)
	{
		ostringstream ss;
		int lastCloseBrace = -1;
		int openBrace = -1;
		while ((openBrace = input.find('{', openBrace + 1)) > -1)
		{
			if (openBrace + 1 < input.length())
			{
				if (input[openBrace + 1] == '{')
				{
					openBrace++;
					continue;
				}

				int closeBrace = input.find('}', openBrace + 1);
				if (closeBrace > -1)
				{
					ss << input.substr(lastCloseBrace + 1, openBrace - lastCloseBrace - 1);
					lastCloseBrace = closeBrace;

					string index = trim(input.substr(openBrace + 1, closeBrace - openBrace - 1));
					if (index == "0")
						ss << arg0;
					else if (index == "1")
						ss << arg1;
					else
						throw  exception("Only simple positional format specifiers are handled by the 'formatSimple' helper method.");
				}
			}
		}

		if (lastCloseBrace + 1 < input.length())
			ss << input.substr(lastCloseBrace + 1);

		return ss.str();
	}

	template<typename T1, typename T2, typename T3>
	static  string formatSimple(const  string &input, T1 arg0, T2 arg1, T3 arg2)
	{
		ostringstream ss;
		unsigned int lastCloseBrace = -1;
		unsigned int openBrace = -1;
		while ((openBrace = input.find('{', openBrace + 1)) > -1)
		{
			if (openBrace + 1 < input.length())
			{
				if (input[openBrace + 1] == '{')
				{
					openBrace++;
					continue;
				}

				int closeBrace = input.find('}', openBrace + 1);
				if (closeBrace > -1)
				{
					ss << input.substr(lastCloseBrace + 1, openBrace - lastCloseBrace - 1);
					lastCloseBrace = closeBrace;

					string index = trim(input.substr(openBrace + 1, closeBrace - openBrace - 1));
					if (index == "0")
						ss << arg0;
					else if (index == "1")
						ss << arg1;
					else if (index == "2")
						ss << arg2;
					else
						throw  exception("Only simple positional format specifiers are handled by the 'formatSimple' helper method.");
				}
			}
		}

		if (lastCloseBrace + 1 < input.length())
			ss << input.substr(lastCloseBrace + 1);

		return ss.str();
	}
};
