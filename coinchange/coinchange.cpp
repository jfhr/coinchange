#include "stdafx.h"

int coinchange(const int sum, const int* firstcoin, const int* const lastcoin)
{
	if (firstcoin > lastcoin) return 0;
	if (sum < 0) return 0;
	if (sum == 0) return 1;

	int withCurrentCoin = coinchange(sum - *firstcoin, firstcoin, lastcoin);
	int withoutCurrentCoin = coinchange(sum, ++firstcoin, lastcoin);
	return withCurrentCoin + withoutCurrentCoin;
}
