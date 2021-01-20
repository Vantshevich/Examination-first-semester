#pragma once
#include <string>
#include "CClient.h"
#include "CUseStatistics.h"

class CClientsFileReader
{
public:
	CClientsFileReader(std::string filename);
private:
	std::string m_sFileName;
public:
	bool Read(CClient** ppClients, CUseStatistics** ppStats, int& iClientSize, int& iStatsSize);
};

