#include "Logger.h"


namespace logger
{

	printer info() { return printer(LOGLEVEL::INFO); }
	printer error() { return printer(LOGLEVEL::ERROR); }
	printer debug() { return printer(LOGLEVEL::DEBUG); }


	printer::printer(LOGLEVEL lvl)
	{
		switch (lvl)
		{
		case LOGLEVEL::INFO:
			prefix = "INFO: ";
			break;
		case LOGLEVEL::ERROR:
			prefix = "ERROR: ";
			break;
		case LOGLEVEL::DEBUG:
			prefix = "DEBUG: ";
			break;

		}
		
	}

	printer::~printer()
	{
		print();
	}

	void printer::print()
	{
		std::cout << stream.str() << std::endl;
	
	}

}

