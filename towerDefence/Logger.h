#pragma once 

#include <iostream>
#include <string>
#include <sstream>


namespace logger
{
	class printer;

	enum class LOGLEVEL{DEBUG, INFO, ERROR};

	printer info();
	printer error();
	printer debug();





	class printer
	{
	public:
		explicit printer(LOGLEVEL lvl);

		~printer();

		template <typename Val>
		printer& operator << (Val&& str);

	private:
		void print();

		std::string prefix;
		std::stringstream stream;

	};


	template <typename Val>
	printer& printer::operator << (Val&& str)
	{
		stream << std::forward<Val>(str);
		return *this;
	}

}


