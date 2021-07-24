#include "tester.hpp"

int		buffer_clean(std::ofstream &_Log, std::stringstream &_Os)
{
	_Log << _Os.str() << std::endl;
	_Os.str("");
	_Os.clear(std::stringstream::goodbit);
	return 0;
}

int		failed(std::ofstream &_Log, std::stringstream &_Os)
{
	return (buffer_clean(_Log, _Os));
}
