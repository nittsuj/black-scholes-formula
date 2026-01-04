#include <iostream>
#include <cmath>

double normalCDF(double value);

int main() {
	double stockPrice, optionStrikePrice,
	       riskFreeInterestRate, timeRemaining,
	       volatility;
	
	std::cin >> stockPrice >> optionStrikePrice >>
		riskFreeInterestRate >> timeRemaining >> volatility;

	double d1 = (std::log(stockPrice/optionStrikePrice) +
			(riskFreeInterestRate+(volatility*volatility)/2.0) * timeRemaining) /
			(volatility*std::sqrt(timeRemaining)),
		d2 = d1 - (volatility*(std::sqrt(timeRemaining)));
	
	double N_d1 = normalCDF(d1), N_d2 = normalCDF(d2),

	       call = stockPrice * N_d1 - optionStrikePrice *
		       std::exp(-riskFreeInterestRate * timeRemaining) * N_d2,
	       put = optionStrikePrice * std::exp(-riskFreeInterestRate * timeRemaining) * (1-N_d2) -
		       stockPrice * (1-N_d1);

	std::cout << "Call Value" << call << std::endl;
	std::cout << "Put Value" << put << std::endl;
}

double normalCDF(double value) {
	return 0.5 * (std::erfc(-(value)/ (std::sqrt(2))));
} 
