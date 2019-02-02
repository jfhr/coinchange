#pragma once

// Computes the number of sets of coins where their sum is equal to a certain number.
// @param sum: The sum that should be achieved
// @param firstcoin: pointer to the beginning of an int[] containing the values of all the coins,
//     which can be in any order
// @param lastcoint: pointer to the end of that array
int coinchange(const int sum, const int* firstcoin, const int* const lastcoin);
