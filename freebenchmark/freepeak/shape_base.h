#pragma once
#ifndef SHAPE_BASE_H
#define SHAPE_BASE_H
#include<string>
#include<vector>


class shape_base
{

public:
	shape_base() {}
	virtual ~shape_base() = 0;
	virtual double evaluate() {}

protected:
	//int m_idx;
	//std::string m_name;
	//std::set<OFEC::problem_tag> m_problem_tag;

};


class s1:public shape_base
{
public:
	double evaluate() { }

private:
	std::vector<std::vector<double>> m_X;
	double m_height;
	int m_dim;
	std::vector<std::vector<double>> m_boundary;

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
