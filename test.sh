#!/bin/bash
./money_maker -test USA 0.01 > test.txt
echo "USA 0.01"
if grep "one cent" test.txt; then
echo "\033[32mOK\033[0m"
else
echo "\033[31mNOT OK\033[0m"
fi
./money_maker -test USA 2147483647 > test.txt
echo "USA 2147483647"
if grep "two billion one hundred forty-seven million four hundred eighty-three thousand six hundred forty-seven" test.txt; then
echo "\033[32mOK\033[0m"
else
echo "\033[31mNOT OK\033[0m"
fi
./money_maker -test USA 1234567.89 > test.txt
echo "USA 1234567.89"
if grep "one million two hundred thirty-four thousand five hundred sixty-seven dollars and eighty-nine cents" test.txt; then
echo "\033[32mOK\033[0m"
else
echo "\033[31mNOT OK\033[0m"
fi
./money_maker -test USA 1.00 > test.txt
echo "USA 1.00"
if grep "one dollar" test.txt; then
echo "\033[32mOK\033[0m"
else
echo "\033[31mNOT OK\033[0m"
fi
./money_maker -test USA 1000000 > test.txt
echo "USA 1000000"
if grep "one million dollars" test.txt; then
echo "\033[32mOK\033[0m"
else
echo "\033[31mNOT OK\033[0m"
fi
./money_maker -test USA 543636.85 > test.txt
echo "USA 543636.85"
if grep "five hundred forty-three thousand six hundred thirty-six dollars and eighty-five cents" test.txt; then
echo "\033[32mOK\033[0m"
else
echo "\033[31mNOT OK\033[0m"
fi
./money_maker -test USA 1000000001 > test.txt
echo "USA 1000000001"
if grep "one billion one dollar" test.txt; then
echo "\033[32mOK\033[0m"
else
echo "\033[31mNOT OK\033[0m"
fi
./money_maker -test UKR 0,01 > test.txt
echo "UKR 0,01"
if grep "одна копiйка" test.txt; then
echo "\033[32mOK\033[0m"
else
echo "\033[31mNOT OK\033[0m"
fi
./money_maker -test UKR 2147483647 > test.txt
echo "UKR 2147483647"
if grep "два мільярди сто сорок сім мільйонiв чотириста вісімдесят три тисячi шістсот сорок сім гривень" test.txt; then
echo "\033[32mOK\033[0m"
else
echo "\033[31mNOT OK\033[0m"
fi
./money_maker -test UKR 1234567,89 > test.txt
echo "UKR 1234567,89"
if grep "один мільйон двісті тридцять чотири тисячi п'ятсот шістдесят сім гривень вісімдесят дев'ять копiйок" test.txt; then
echo "\033[32mOK\033[0m"
else
echo "\033[31mNOT OK\033[0m"
fi
./money_maker -test UKR 1,00 > test.txt
echo "UKR 1.00"
if grep "одна гривня" test.txt; then
echo "\033[32mOK\033[0m"
else
echo "\033[31mNOT OK\033[0m"
fi
./money_maker -test UKR 543636,85 > test.txt
echo "UKR 543636.85"
if grep "п'ятсот сорок три тисячi шістсот тридцять шість гривень вісімдесят п'ять копiйок" test.txt; then
echo "\033[32mOK\033[0m"
else
echo "\033[31mNOT OK\033[0m"
fi
./money_maker -test UKR 2100000 > test.txt
echo "UKR 2100000"
if grep "два мільйони сто тисяч гривень" test.txt; then
echo "\033[32mOK\033[0m"
else
echo "\033[31mNOT OK\033[0m"
fi
