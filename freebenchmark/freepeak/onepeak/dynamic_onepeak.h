#pragma once
#ifndef DYNAMIC_ONEPEAK_H
#define DYNAMIC_ONEPEAK_H
#include<deque>
class dynamic_onepeak : public onepeak
{
public:
	dynamic_onepeak() {}
	~dynamic_onepeak() {}

private:

	double m_robustness;
	std::deque<double> m_pre_height;
	std::deque<std::vector<double>> m_pre_loc;
	double m_shift_severity, m_height_severity;

};



#endif // !DYNAMIC_ONEPEAK_H

#include"onepeak.h"

