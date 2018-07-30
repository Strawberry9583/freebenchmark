#pragma once
#ifndef PROPERTY_H
#define PROPERTY_H


#include"property_base.h"
#include"../definition.h"
#include<memory>
#include<set>

class property
{
public:
	property(/*std::shared_ptr<shift_base> shift = nullptr, std::shared_ptr<distance_base> dis = std::shared_ptr<distance_base>(new euclidean_distance),
		std::shared_ptr<decision_trans_base> decision_trans=nullptr,
		std::shared_ptr<obj_trans_base> obj_trans = nullptr, const std::set<property_type> & type = std::set<property_type>({ property_type::EUCLIDEAN_DISTANCE })) :
	m_shift(shift),m_dis(dis),m_decision_tran(decision_trans),m_obj_tran(obj_trans),m_property_type(type)*/){}
	void set_shift(std::shared_ptr<shift_base> & shift) { m_shift = shift; }
	~property() {}

private:
	std::set<property_type> m_property_type = { property_type::EUCLIDEAN_DISTANCE };
	std::shared_ptr<distance_base> m_dis = std::shared_ptr<distance_base>(new euclidean_distance);
	// X shift property;
	std::shared_ptr<shift_base> m_shift = nullptr;
	//the transforamation in decision spaces;
	std::shared_ptr<decision_trans_base> m_decision_tran = nullptr;
	//the transforamation in objective spaces;
	std::shared_ptr<obj_trans_base> m_obj_tran = nullptr;
};




#endif // !PROPERTY_H
