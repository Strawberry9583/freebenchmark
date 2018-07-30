#pragma once
#ifndef FREE_ONEPEAK_H
#define FREE_ONEPEAK_H

#include"../onepeak/onepeak.h"
#include"../../utility/kd-tree/kdtree_space.h"
#include<map>

class free_onepeak
{
public:
	free_onepeak() {}
	~free_onepeak(){}

protected:
	std::unique_ptr<KDTreeSpace::PartitioningKDTree<double>> m_tree;
	//division ratio to create the tree;
	std::vector<double> m_space_ratio;
	//space domain in every dimension;
	 //std::vector<std::pair<double, double>> m_space_domain;
	 //map the subspaces indeces to problem;
	 std::vector<size_t> m_idx;
	 // all problem in subspaces;
	std::vector<std::shared_ptr<onepeak> >  m_peaks;

	//all properties(not including dynamic properties) will be used;
	std::vector<std::shared_ptr<distance_base>> m_distance;
	std::vector<std::shared_ptr<decision_trans_base>> m_decision_trans;
	std::vector<std::shared_ptr<obj_trans_base>> m_obj_trans;
	std::vector<std::shared_ptr<shift_base>> m_shift;

	std::vector<std::vector<double>>  m_global_optimal;

	int m_num_peak = 0;
	int m_num_space;

	std::vector<std::vector<std::vector<double>>> m_division_point;
	std::map<int, std::shared_ptr<onepeak>> m_space2problem;



	int m_peaks_per_space = 1;

	std::vector<std::vector<double> > m_peak;
	division_model m_division_model;

protected:

	void register_par() {}
	void register_property() {}
	void register_shapefunction() {}

	//virtual void create_problem() = 0;

	int map_x2space() {}
	int map_x_from_space(){}
	


	void initialize();
	//virtual void create_peaks() = 0;
	//virtual void createPeaks_() = 0;
	double disNearestPeak();

public:
	void create_tree();
	std::unique_ptr<KDTreeSpace::PartitioningKDTree<double>> & tree() { return m_tree; }
	const std::unique_ptr<KDTreeSpace::PartitioningKDTree<double>> &  tree() const { return m_tree; }

	std::vector<double> & space_ratio() { return m_space_ratio; }
};



#endif // !FREE_ONEPEAK_H
