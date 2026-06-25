#include "BitcoinExchange.hpp"

int main(int ac, char **ag)
{
	if (ac != 2)
		std::cerr << "Invalid usage\nbtc <input file>\n";
	else
	{
		try
		{
			BitcoinExchange be("data.csv");
			be.loadDb();
			be.exchange(ag[1]);
		}
		catch(std::runtime_error &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	return 0;
}
