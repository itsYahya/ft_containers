/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_test.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 03:23:03 by yel-mrab          #+#    #+#             */
/*   Updated: 2023/02/02 23:43:54 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <set>
#include "set.hpp"
#include <iostream>
#include "map.hpp"
#include <map>

int main(){
	std::set<int> set;
	ft::set<int> myset;
	typedef ft::set<int>::iterator iterator;
	typedef ft::set<int>::reverse_iterator reverse_iterator;
	
	// std::pair<iterator, bool> pair = myset.insert(10);
	// iterator iter = myset.insert(pair.first, 11);
	myset.insert(1);
	myset.insert(2);
	myset.insert(6);
	myset.insert(5);
	myset.insert(66);
	ft::set<int> s(myset.begin(), myset.end()), h(myset);
	iterator ii = myset.begin();
	ii++;ii++;
	myset.erase(myset.begin(), ++ii);
	iterator i = s.begin();
	for (; i != s.end(); i++)
		std::cout << *i << std::endl;
	std::cout << "++++++++++++++++"  << std::endl;
	iterator it = myset.upper_bound(66);
	// std::cout << (it == myset.end()) << std::endl;
	for (iterator iter = myset.begin(); iter != myset.end(); iter++)
		std::cout << *iter << std::endl;
	std::cout << "+++++++++++++++++" << std::endl;
	reverse_iterator riter = myset.rbegin();
	for (; riter != myset.rend(); riter++)
		std::cout << *riter << std::endl;
	std::cout << "++++++++++++++" << std::endl;
	std::cout << s.size() << std::endl;
	std::cout << myset.size() << std::endl;
	iterator iii = h.lower_bound(1);
	std::cout << "the lower bound of 1 is : " << *iii << std::endl;
	iii = h.upper_bound(1);
	std::cout << "the uper bound of 1 is : " << *iii << std::endl;
	std::cout << h.size() << std::endl;

	iii = h.find(55);
	std::cout << ((iii==h.end())?"the element couldn't be found":"the element was found") << std::endl;
	h.clear();
	iii = h.begin();
	for (; iii != h.end(); iii++)
		std::cout << *iii << std::endl;
	std::cout << h.size() << std::endl;
}