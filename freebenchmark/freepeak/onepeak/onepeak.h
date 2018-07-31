#pragma once
#ifndef ONEPEAK_H
#define ONEPEAK_H

#include"../problem_base.h"
#include"../shape_base.h"
#include"../property/property.h"
#include"../definition.h"

#include<vector>
#include<memory>
#include<string>


class onepeak: public problem_base
{
public:
	onepeak() {}
	~onepeak() {}
	const int dim() const { return m_dim; }
protected:
	//int m_id;
	std::string m_name;
	int m_dim;
	// the total evals and the number of countable evlas 
	int m_total_evaluations;
	int m_current_evaluations;
	int m_countable_evaluations;
	int m_num_obj;
	double m_accuracy;
	compare m_compare_mode = compare::MIN_OPT;


	//double m_height = 100;

	double m_furest_dis;		// the longest distance from location to boarder points 
	double m_nearest_dis;	// the shortest distance from location to boundary points
	bool m_standardize = false;		// standardize objective value between height and zero

	double m_basin_ratio = 1;	//the ratio of the area of the basin of attraction to the area of the whole space
	
	double m_subspace_ratio;

	std::set<OFEC::property_type> m_property_type;
	std::shared_ptr<property> m_property;
	std::vector<std::shared_ptr<shape_base>> m_simple_function;
	std::vector<std::vector<double>> m_peak_optimal;

	
protected:

	void rename(const std::string & name);
	void resize_dim(int dim);
	void set_accuaracy(double accuracy);

	

	virtual std::vector<double> evaluate(const std::vector<double> & sol);

public:
	onepeak(){}
	~onepeak(){}
	void initialize();

};


#endif // !FREEPEAK_H
