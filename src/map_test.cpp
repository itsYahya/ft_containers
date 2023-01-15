/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 22:47:44 by yel-mrab          #+#    #+#             */
/*   Updated: 2023/01/15 00:42:33 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <functional>
#include "../inc/pair/pair.hpp"
#include "../inc/redblacktree/redblacktree.hpp"
#include "random_iterator.hpp"
#include "map.hpp"


void	print(const ft::RedBlackTree<int> &tree){
	ft::RedBlackTree<int>::const_iterator iter = tree.begin();

	for (; iter != tree.end(); iter++){
		std::cout << "** : " << *iter << std::endl;
	}
}

#include <map>
#include <set>


void	test(const ft::map<int, int> &map){
	ft::map<int, int>::const_iterator iter ;

	iter = map.find(20);
	iter = map.lower_bound(-1);
	iter = map.begin();
	for (; iter != map.end(); iter++)
		std::cout << iter->first << " " << iter->second << std::endl;	
}

int main(){
	// ft::map<int, int>			m1, m2;
	// ft::map<int, int>::iterator iter;
	// ft::map<int, int> map;
	// typedef ft::map<int, int>::iterator	iterator;

	// m1.insert(ft::pair<int, int>(0, 00));
	// m1.insert(ft::pair<int, int>(1, 100));
	// m1.insert(ft::pair<int, int>(2, 100));
	// m1.insert(ft::pair<int, int>(3, 100));
	// m1.insert(ft::pair<int, int>(4, 100));
	
	// m2.insert(ft::pair<int, int>(10, 100));
	// m2.insert(ft::pair<int, int>(20, 100));
	// m2.insert(ft::pair<int, int>(30, 100));
	// m2.insert(ft::pair<int, int>(40, 100));
	// m2.insert(ft::pair<int, int>(50, 100));
	// m2.insert(ft::pair<int, int>(60, 100));
	
	// m1.swap(m2);
	// iter = m2.find(0);
	// test(m2);
	// std::cout << m2.count(0) << std::endl;

	// map.insert(ft::pair<int, int>(4, 30));
    // map.insert(ft::pair<int, int>(1, 40));
    // map.insert(ft::pair<int, int>(6, 60));
	// iterator iter = map.upper_bound(0);
	// std::cout << iter->first << std::endl;

	// ft::pair<iterator, iterator>	pair = map.equal_range(1);
	// std::cout << "lower bound : " << pair.first->first << ":" << pair.first->second << std::endl;
	// std::cout << "upper bound : " << pair.second->first << ":" << pair.second->second << std::endl;
	// test(map);

	ft::map<int, int> m2;
	std::map<int, int> map1;

	m2.insert(ft::pair<int, int>(10, 100));
	m2.insert(ft::pair<int, int>(20, 100));
	m2.insert(ft::pair<int, int>(30, 100));
	m2.insert(ft::pair<int, int>(40, 100));
	m2.insert(ft::pair<int, int>(50, 100));
	m2.insert(ft::pair<int, int>(60, 100));
	
	// std::cout << m2.max_size() << std::endl;
	// std::cout << map1.max_size() << std::endl;
	test(m2);
	
	// set.insert(1);
	// set.insert(4);
	// set.insert(5);
	// set.insert(0);
	// set.insert(9);
	// set.insert(3);
	
	// std::set<int>::iterator iter = set.begin();
	// for (; iter != set.end(); iter++)
		
	return (0);
}