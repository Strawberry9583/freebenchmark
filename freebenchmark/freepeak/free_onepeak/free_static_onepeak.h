#pragma once
#ifndef FREE_STATIC_ONEPEAK
#define FREE_STATIC_ONEPEAK

#include"../onepeak/static_onepeak.h"
#include"free_onepeak.h"

class free_static_onepeak: public free_onepeak
{

protected:
	int m_num_opt;
	double m_max_height = 100;
	std::vector<int> m_max_peak;

};
#endif // ! FREE_STATIC_ONEPEAK
