#pragma once
#ifndef PROPERTY_BASE_H
#define PROPERTY_BASE_H
#include<vector>


class  distance_base
{
public:
	distance_base() {}
	~distance_base() {}


protected:
	virtual void cal_distance() {}

private:

};


class euclidean_distance: public distance_base
{
public:
	euclidean_distance() {}
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
		return dis;
	}
private:

};




class decision_trans_base
{
public:
	decision_trans_base(){}
	~decision_trans_base() {}
	virtual void decision_trans(){}
private:

};

class obj_trans_base
{
public:
	obj_trans_base() {}
	~obj_trans_base() {}
	virtual void obj_trans() {}
private:

};

class shift_base
{
public:
	shift_base() {}
	~shift_base() {}
protected:
	virtual std::vector<double>  shift(const std::vector<double> & x){}
private:

};

class shift_rand :public shift_base
{
public:

	std::vector<double> shift(const std::vector<double> & x){ }
};



class dynamic_change
{
public:
	dynamic_change();
	~dynamic_change();

private:

};





#endif // !PROPERTY_BASE_H
