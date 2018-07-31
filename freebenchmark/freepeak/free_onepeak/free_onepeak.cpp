#include "free_onepeak.h"

void free_onepeak::create_tree()
{	
	m_tree = std::unique_ptr<KDTreeSpace::PartitioningKDTree<double>>
		(new KDTreeSpace::PartitioningKDTree<double>
		(m_peaks[0]->dim(), m_space_ratio, m_space_domain));
	m_tree->buildIndex();
	m_idx = m_tree->get_idx();
}

void free_onepeak::register_par()
{

}


void free_onepeak::register_property()
{
	//register used distance;
	OFEC::REGISTER(distance_base, euclidean_distance, "euclidean_distance");
	OFEC::REGISTER(distance_base, manhattan_distance, "manhattan_distance");


	//register used decision transformation;
	OFEC::REGISTER(decision_trans_base, asymmetric_descision_trans, "asymmetric_descision_trans");



	//register used shift;
	OFEC::REGISTER(shift_base, shift_rand, "shift_rand");


	//register used obj transformation;
	OFEC::REGISTER(obj_trans_base, noise_trans, "noise_trans");


	//auto it = m_factory_distance.produce("euclidean_distance");
	//m_distance.push_back( std::shared_ptr<distance_base>(
	//	new it->second(m_param_map))
	//);
	//auto temp = new constructor();
	//auto temp = new m_factory_distance.get().find("euclidean_distance")();
	OFEC::param_map v;
	m_distance.push_back(std::shared_ptr<distance_base>
		(m_factory_distance.produce("euclidean_distance", v)));
	std::vector<double> v1 = { 1,1 }, v2 = { 0,0 };
	m_distance[0]->cal_distance(v1, v2);
	//temp.cal_distance(v1, v2);t
	//auto temp1 = dynamic_cast<distance_base *>(temp);
	//temp1->cal_distance(v1, v2);
}

void free_onepeak::initialize()
{

}
