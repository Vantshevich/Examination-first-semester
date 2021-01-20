#include <math.h>
#include <string>

bool IsDigit(char a) {
	return '0' <= a && '9' >= a;
}

bool IsDouble(char a) {
	return ('0' <= a && '9' >= a) || a == ',';
}

bool NoProbel(char a) {
	return a != ' ';
}

char* FindFirstWordIf(const char* str, int size, bool (check)(char), bool revers = 0, int begin = 0) {
	if (size == 1) {
		if (check(str[0])) {
			char* z = new char[2];
			z[0] = str[0];
			z[1] = '\0';
			return z;
		}
		else {
			return nullptr;
		}
	}
	int ending = -1, begining = -1;
	for (int i = begin * (int)pow(-1, revers) + revers * (size - 1); i < size && i > -1; i += 1 * (int)pow(-1, revers)) {
		if (begining == -1) {
			if (check(str[i])) begining = i;
		}
		else {
			if (!check(str[i])) {
				ending = i - 1 * (int)pow(-1, revers);
				char* new_str = new char[2 + abs(ending - begining)];
				for (int j = begining * (!revers) + ending * revers; j <= begining * revers + ending * (!revers); j++)
				{
					new_str[j - (begining * (!revers) + ending * revers)] = str[j];
				}
				new_str[1 + abs(ending - begining)] = '\0';
				return new_str;
			}
			if (i == size - 1 || i == 0) {
				ending = i;
				char* new_str = new char[2 + abs(ending - begining)];
				for (int j = begining * (!revers) + ending * revers; j <= begining * revers + ending * (!revers); j++)
				{
					new_str[j - (begining * (!revers) + ending * revers)] = str[j];
				}
				new_str[1 + abs(ending - begining)] = '\0';
				return new_str;
			}
		}
	}
	return nullptr;
}

struct Time {
	int tm;
	int Position;
};

void sort(Time* array, int size)
{
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (array[j].tm > array[j + 1].tm) {
				Time temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}

std::string MinPlan(const char *Client, std::string *Plan, int n, double* SUM) {
	int SMS, min;
	int flag = 0;
	*SUM = 0;
	min = atoi(FindFirstWordIf(Client, strlen(Client), IsDigit, true));
	SMS = atoi(FindFirstWordIf(Client, strlen(Client), IsDigit, true, strlen(FindFirstWordIf(Client, strlen(Client), IsDigit, true))));
	double sum = 0;
	for (int i = 0; i < n; i++) {
		double SMS_Cena, min_Cena, newSum = 0;
		std::string Current = FindFirstWordIf(Plan[i].c_str(), strlen(Plan[i].c_str()), IsDouble, true);
		min_Cena = atof(Current.c_str());
		Current = FindFirstWordIf(Plan[i].c_str(), strlen(Plan[i].c_str()), IsDouble, true, strlen(Current.c_str()));
		SMS_Cena = atof(Current.c_str());
		newSum += min * min_Cena + SMS * SMS_Cena;
		if (sum == 0) sum = newSum;
		if (newSum < sum) {
			sum = newSum;
			flag = i;
			*SUM = sum;
		}
	}

	std::string a = Plan[flag];
	return a;
}