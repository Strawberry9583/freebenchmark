#pragma once
#ifndef SHAPE_BASE_H
#define SHAPE_BASE_H

#include"property\property_base.h"
#include<string>
#include<vector>



class shape_base
{

public:
	shape_base() {}
	virtual ~shape_base() = 0;
	virtual double evaluate(const std::vector<double> & x) {}
	virtual void resize(int dim){}
protected:
	//int m_idx;
	std::string m_name;
	//std::set<OFEC::problem_tag> m_problem_tag;

};


class s1:public shape_base
{
public:
	void set_distance(std::shared_ptr<distance_base> dis)
	{
		m_dis = dis;
	}

	double evaluate(const std::vector<double> & x) 
	{
		return m_height - m_dis->cal_distance(x,m_X);
	}

	void resize(int dim)
	{
		m_dim = dim;
		m_X.resize(dim);
	}
private:
	std::vector<double> m_X;
	double m_height=100;
	int m_dim;
	std::vector<std::pair<double,double> > m_boundary;
	std::shared_ptr<distance_base> m_dis;
};

//class single_obj_shape_base:public shape_base
//{
//
//public:
//	single_obj_shape_base()
//	{ m_problem_tag.insert(OFEC::problem_tag::GOP); };
//	~single_obj_shape_base() {}
//
//
//protected:
//	virtual void evaluate() {}
//
//};
//
//class dynamic_single_obj_shape_base: public shape_base
//{
//
//public:
//	dynamic_single_obj_shape_base()
//	{
//		m_problem_tag.insert(OFEC::problem_tag::GOP);
//		m_problem_tag.insert(OFEC::problem_tag::DOP);
//	}
//	~dynamic_single_obj_shape_base() {}
//protected:
//
//	virtual void evaluate() {}
//private:
//
//};
//
//
//
//
//
#endif // !SHAPE_BASE_H
