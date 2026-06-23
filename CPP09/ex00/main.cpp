#include "BitcoinExchange.hpp"

int main(int ac, char **ag)
{
	if (ac != 2)
		std::cerr << "Invalid usage\nbtc <input file>\n";
	else
	{
		BitcoinExchange be("data.csv");
		be.Exchange();
	}
}
