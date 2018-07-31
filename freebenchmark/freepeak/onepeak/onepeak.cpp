#include "onepeak.h"

void onepeak::rename(const std::string & name)
{
	m_name = name;
}

void onepeak::resize_dim(int dim)
{
	m_dim = dim;
	for (auto & i : m_simple_function)
	{
		i->resize(dim);
	}
	for (auto & i : m_peak_optimal)
	{
		i.resize(dim);
	}
}

std::vector<double> onepeak::evaluate(const std::vector<double>& sol)
{
	std::vector<double> obj;
	for (auto & i : m_simple_function)
	{
		obj.push_back(i->evaluate(sol));
	}
	++m_current_evaluations; 
	return obj;
}
