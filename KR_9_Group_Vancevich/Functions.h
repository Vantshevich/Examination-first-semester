bool IsDigit(char a);

bool NoProbel(char a);

bool IsDouble(char a);

char* FindFirstWordIf(const char* str, int size, bool (check)(char), bool revers = 0, int begin = 0);

struct Time {
	int tm;
	int Position;
};

void sort(Time* array, int size);

std::string MinPlan(const char* Client, std::string* Plan, int n, double* SUM);