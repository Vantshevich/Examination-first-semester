#pragma once
#include <string>
class CPlan
{
public:
	CPlan(std::string from);
public:
	std::string name;
	float smsPrice;
	float minPrice;
};