#include <iostream>
#include <cstring>

struct ClubResults
{
	const char * m_clubName;
	int m_nWins, m_nDraws, m_nLooses;
	int m_goalsFor, m_goalsAgainst;
};

int getPTS(ClubResults _club)
{
	return _club.m_nWins * 3 + _club.m_nDraws;
}

int getGDIFF(ClubResults _club)
{
	return _club.m_goalsFor - _club.m_goalsAgainst;
}

void selectionSort(ClubResults * _pData, const int _N)
{
	for (int i = 0; i < _N - 1; i++)
	{
		int lowIndex = i;
		for (int j = i + 1; j < _N; j++)
			if (getPTS(_pData[j]) > getPTS(_pData[lowIndex]) ||
			   (getPTS(_pData[j]) == getPTS(_pData[lowIndex]) &&
				getGDIFF(_pData[j]) > getGDIFF(_pData[lowIndex])))
				lowIndex = j;

		std::swap(_pData[lowIndex], _pData[i]);
	}
}


int main()
{
	ClubResults clubs[5] = {
		{"Goverla",1,7,9,11,25},
		{"Dnipro",11,4,2,32,11},
		{"Shakhtar Donetsk",12,2,3,43,10},
		{"Dynamo Kiev",14,3,0,42,17},
		{"Metalist Kharkiv",6,6,4,26,24}
	};

	selectionSort(clubs, 5);

	std::cout << "CLUB W D L GF GA GDIFF PTS" << std::endl;
	std::cout << "__________________________" << std::endl << std::endl;
	for (int i = 0; i < 5; i++)
		std::cout << clubs[i].m_clubName << " " << clubs[i].m_nWins << " "
		<< clubs[i].m_nDraws << " " << clubs[i].m_nLooses << " "
		<< clubs[i].m_goalsFor << " " << clubs[i].m_goalsAgainst << " "
		<< getGDIFF(clubs[i]) << " " << getPTS(clubs[i]) << std::endl;

	return 0;
}