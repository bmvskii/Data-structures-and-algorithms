#define _CRT_SECURE_NO_WARNINGS

#include "test.hpp"
#include "priority_queue.hpp"
#include "vector.hpp"

void testFunctional()
{
	Payment p;

	assert(scanData("12/10/2015 $215 CompanyA CompanyB", p, std::cout) == 0);
	assert(scanData("/10/2015 $215 CompanyA CompanyB", p, std::cout) == -1);
	assert(scanData("12//2015 $215 CompanyA CompanyB", p, std::cout) == -1);
	assert(scanData("//2015 $215 CompanyA CompanyB", p, std::cout) == -1);
	assert(scanData("$215 asdsa CompanyA CompanyB", p, std::cout) == -1);
	assert(scanData("12/10/2015 $-1 CompanyA CompanyB", p, std::cout) == -1);
	assert(scanData("12/10/2015 $200 CompanyA", p, std::cout) == -1);
	assert(scanData("12/10/2015 $200", p, std::cout) == -1);
	assert(scanData("12/10/2015 $200 CompanyA Company B", p, std::cout) == -1);
}

void testPriorityQueueWorking()
{
	PriorityQueue * temp = PriorityQueueCreate(3);
	Payment p;

	for (int i = 0; i < 4; i++)
	{
		p.m_fstCompany = new char[strlen("Company1") + 1];
		p.m_sndCompany = new char[strlen("Company2") + 1];
		strcpy(p.m_fstCompany, "Company1");
		strcpy(p.m_sndCompany, "Company2"); 
		p.m_summary = i * i;
		p.m_time = { 1,1,1 };
		PriorityQueueInsert(*temp, p);
	}

	assert(PriorityQueueMin(*temp).m_summary == 1);

	PriorityQueueDestroy(temp);
}

int scanData(char * _buffer, Payment & _p, std::ostream & _s)
{
	char * buffer = new char[strlen(_buffer) + 1];
	strcpy(buffer, _buffer);
	if (sscanf(buffer, "%2d/%2d/%4d", &_p.m_time.tm_mday, &_p.m_time.tm_mon, &_p.m_time.tm_year) < 3)
	{
		_s << "Wrong date. Check it out and try again." << std::endl;
		return -1;
	}
		
	char * pCurrent = strtok(buffer, "$");
	pCurrent = strtok(NULL, " ");
	if (!atof(pCurrent) || atof(pCurrent) < 0) {
		_s << "Wrong summary.Check it out and try again." << std::endl;
		return -1;
	}
	_p.m_summary = atof(pCurrent);

	pCurrent = strtok(NULL, " ");
	if (pCurrent == nullptr)
	{
		_s << "Wrong first company name. Check it out and try again." << std::endl;
		return -1;
	}
	_p.m_fstCompany = new char[strlen(pCurrent) + 1];
	strcpy(_p.m_fstCompany, pCurrent);

	pCurrent = strtok(NULL, " ");
	if (pCurrent == nullptr)
	{
		_s << "Wrong second company name. Check it out and try again." << std::endl;
		return -1;
	}
	_p.m_sndCompany = new char[strlen(pCurrent) + 1];
	strcpy(_p.m_sndCompany, pCurrent);
	pCurrent = strtok(NULL, " ");
	if (pCurrent != nullptr)
	{
		_s << "Wrong format of company name. It shouldn't be divided by spaces. Check it out and try again." << std::endl;
		return -1;
	}

	return 0;
}