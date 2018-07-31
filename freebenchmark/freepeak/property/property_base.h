#pragma once
#ifndef PROPERTY_BASE_H
#define PROPERTY_BASE_H
#include"../../utility/typevar/typevar.h"
#include<vector>
#include<random>
#include<time>
#include<iostream>


class  distance_base
{
public:
	distance_base() {}
	~distance_base() {}

	virtual double cal_distance(const std::vector<double> & x1, const std::vector<double> & x2) 
	{
		//std::cout << "1" << std::endl;
		return 0;
	}

private:

};

class euclidean_distance: public distance_base
{
public:
	euclidean_distance() {}
	euclidean_distance(OFEC::param_map v) {}
	~euclidean_distance() {}

	double cal_distance(const std::vector<double> & x1, const std::vector<double> & x2) {
		double dis = 0;
		auto first1 = x1.begin(), first2 = x2.begin();
		while (first1 != x1.end()) {
			dis += (*first1 - *first2)*(*first1 - *first2);
			++first1;
			++first2;
		}
		dis = sqrt(dis);
		//std::cout << "succeed" << std::endl;
		return dis;
	}
private:

};

class manhattan_distance : public distance_base
{
public :
		manhattan_distance(){}
		manhattan_distance(OFEC::param_map v){}
		~manhattan_distance() {}

	double cal_distance(const std::vector<double> & x1, const std::vector<double> & x2) 
	{
		double dis = 0;
		auto first1 = x1.begin(), first2 = x2.begin();
		while (first1 != x1.end()) {
			dis += fabs(*first1++ - *first2++);
		}
		dis = sqrt(dis);
		//std::cout << "succeed" << std::endl;
		return dis;
	}
private:

};




class decision_trans_base
{
public:
	decision_trans_base(){}
	~decision_trans_base() {}
	virtual void decision_trans(std::vector<double> & rhs){}
private:

};

class asymmetric_descision_trans: public decision_trans_base
{
public:
	asymmetric_descision_trans(OFEC::param_map v){}
	~asymmetric_descision_trans(){}
	const double belta() const { return m_belta;}
	double & belta() { return m_belta; }
	void decision_trans(std::vector<double> &rhs)
	{
		size_t dim = rhs.size();
		if (dim==1) return;

		for (int i = 0; i < dim; ++i) 
		{
			if (rhs[i]>0) 
			{
				rhs[i] = pow(rhs[i], 1. + m_belta*(i / (dim - 1))*log(rhs[i] + 1));
			}
		}
	}
private:
	double m_belta = 0.2;
};


class obj_trans_base
{
public:
	obj_trans_base() {}
	~obj_trans_base() {}
	virtual void obj_trans(std::vector<double> & obj) {}
private:

};

class noise_trans : public obj_trans_base
{
public:
	noise_trans(OFEC::param_map v){}
	~noise_trans(){}
	void obj_trans(std::vector<double> & obj)
	{
		std::default_random_engine random(time(NULL));
		for (auto & i : obj)
		{
			std::uniform_real_distribution<double> dis(0., 1.0);
			i += dis(random);
		}
	}
};


class shift_base
{
public:
	shift_base() {}
	~shift_base() {}
protected:
	virtual std::vector<double>  shift(std::vector<double> & x, const std::vector<std::pair<double, double>> & domain){}
private:

};

class shift_rand :public shift_base
{
public:
	shift_rand(OFEC::param_map v) {}
	~shift_rand() {}

	std::vector<double> shift(std::vector<double> & x,const std::vector<std::pair<double,double>> & domain)
	{ 
		std::default_random_engine random(time(NULL));

		auto j = domain.begin();
		for (auto & i: x)
		{
			std::uniform_real_distribution<double> dis(j->first,j->second);
			i = dis(random);
			++j;
		}
	}
};



class dynamic_change
{
public:
	dynamic_change();
	~dynamic_change();

private:

};





#endif // !PROPERTY_BASE_H
