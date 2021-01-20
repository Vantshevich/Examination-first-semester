#include <fstream>
#include <string>

#include "CClientsFileReader.h"

using namespace std;

#define MaxClients 1000

CClientsFileReader::CClientsFileReader(std::string filename) :
	m_sFileName(filename)
{
	_ASSERT(false);
}

bool CClientsFileReader::Read(CClient** ppClients, CUseStatistics** ppStats, int& iClientSize, int& iStatsSize)
{
	if (ppClients == nullptr || ppStats == nullptr || m_sFileName.empty())
	{
		return false;
	}
	ifstream stream(m_sFileName);
	if (!stream.is_open())
		return false;

	string Input_Str;
	  
	while (getline(stream, Input_Str)) {
		CClient* pClient = new CClient(Input_Str.c_str());
		CUseStatistics * pStats = new CUseStatistics(Input_Str);

	}
	stream.close();
	return true;
}
