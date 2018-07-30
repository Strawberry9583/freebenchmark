#include "free_onepeak.h"

void free_onepeak::create_tree()
{	
	m_tree = std::unique_ptr<KDTreeSpace::PartitioningKDTree<double>>
		(new KDTreeSpace::PartitioningKDTree<double>
		(m_peaks[0]->dim(), m_space_ratio, m_space_domain));
	m_tree->buildIndex();
	m_idx = m_tree->get_idx();
}

void free_onepeak::initialize()
{

}
