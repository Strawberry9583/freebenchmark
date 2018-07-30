/******************************************************************************
* Project:Open Frameworks for Evolutionary Computation (OFEC)
*******************************************************************************
* Author: Changhe Li
* Email: changhe.lw@gmail.com
* Language: C++
*-------------------------------------------------------------------------------
*  This file is part of OFEC. This library is free software;
*  you can redistribute it and/or modify it under the terms of the
*  GNU General Public License as published by the Free Software
*  Foundation; either version 2, or (at your option) any later version.
*
*  see https://github.com/Changhe160/OFEC for more information
*
*-------------------------------------------------------------------------------
* class factory is for the registration of all problems and algorithms  
*
*********************************************************************************/

#ifndef OFEC_FACTORY_H
#define OFEC_FACTORY_H

#include <map>
#include <functional>
#include "definition.h"
#include "typevar/typevar.h"
namespace OFEC {

	template<typename Base>
	struct factory
	{
		template<typename T>
		struct register_
		{
			register_(const std::string& key)
			{
				map_.emplace(
					key, 
					[](param_map& par) { 
						return new T(par); 
					}
				);
			}
		};

		static Base* produce(const std::string& key, param_map& par)
		{
			auto it = map_.find(key);
			if (it == map_.end())
				THROW("the key is not exist!");

			return it->second(par);
		}

		static const std::map<std::string, std::function<Base*(param_map&)>>& get()
		{		
			return map_;
		}
		factory() =default;
	private:
		factory& operator=(const factory&) = delete;
		factory& operator=(factory&&) = delete;
		factory(const factory&) = delete;
		factory(factory&&) = delete;
		static std::map<std::string,std::function<Base*(param_map&)>>  map_;
	};

	template<typename Base>
	std::map<std::string, std::function<Base*(param_map&)>> factory<Base>::map_;

	#define REGISTER(Base, Derived, key) factory<Base>::register_<Derived> reg_##Derived(key);

}

#endif
