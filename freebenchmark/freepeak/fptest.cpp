#include"../utility/factory.h"
#include"../utility/typevar/typevar.h"
#include"../utility/kd-tree/kdtree_space.h"
#include"../freepeak/free_onepeak/free_static_onepeak.h"
#include<vector>
#include<memory>
#include"../utility/factory.h"
int main()
{
	free_onepeak onepeak1;
	onepeak1.register_par();

	OFEC::param_map v;
	std::vector<double> space_ratio = { 0.1,0.2,0.3,0.4 };
	std::vector<std::pair<double, double>> space_domain = { std::make_pair<double,double>(0,100),
		std::make_pair<double,double>(0,100) };
	free_static_onepeak static_peak;

	static_peak.tree()= std::unique_ptr<KDTreeSpace::PartitioningKDTree<double>>
		(new KDTreeSpace::PartitioningKDTree<double>
		(2, space_ratio, space_domain));
	static_peak.tree()->buildIndex();
	static_peak.tree()->regionShow();
	return 0;
}