/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_tests.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:37:30 by yel-mrab          #+#    #+#             */
/*   Updated: 2023/01/25 23:42:54 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/vector/vector.hpp"
#include <vector>

void	test(const ft::vector<int> &vector)
{
	std::cout << "++++++++ const iterators test ++++++++++++" << std::endl;
	
	ft::vector<int>::const_iterator iter = vector.begin();
	//*iter = 44; // you can't actually do this cause this iterator is pointing on a const type of date
	for (; iter != vector.end(); iter++)
		std::cout << *iter << std::endl;
	std::cout << "+++++++++ reverse +++++++++++" << std::endl;
	ft::vector<int>::const_reverse_iterator riter = vector.rbegin();
	for (; riter != vector.rend(); riter++)
		std::cout << *riter << std::endl;
}

void	printv(const ft::vector<int> &vector){
	ft::vector<int>::const_iterator iter = vector.begin();
	for (; iter != vector.end(); iter++)
		std::cout << *iter << " ";
	std::cout << std::endl;
}

int main(){
	typedef ft::vector<int>::iterator iterator;
	typedef ft::vector<int>::reverse_iterator reverse_iterator;
	ft::vector<int> vector, v;
	
	vector.push_back(10);
	vector.push_back(20);
	vector.push_back(30);
	vector.push_back(40);
	vector.push_back(50);

	v.push_back(9091);
	v.push_back(9292);
	v.push_back(9493);
	v.push_back(9894);
	
	std::cout << "+++++++++++++++ iterators test ++++++++++" << std::endl;
	iterator iter = v.begin(), it = v.begin();
	for (; iter != v.end(); iter++)
		std::cout << *iter << std::endl;
		
	std::cout << "++++++++++ reverse +++++++++++++" << std::endl;
	reverse_iterator riter = v.rbegin();
	for (; riter != v.rend(); riter++)
		std::cout << *riter << std::endl;
	*it = 69; // here you can assign and change the data that this iterator is pointing on
	test(v);
	
	ft::vector<int> v1(v);
	printv(v1);
	v1.swap(vector);
	std::cout << "++++++++++ after swap +++++++++" << std::endl;
	printv(v1);
	
	iterator from = v1.begin(), until = v1.end() - 2;
	std::cout << until - from << std::endl;
	ft::vector<int> v2(from, until);
	std::cout << "the vector capacity is : " << v2.capacity() << std::endl;

	v1.resize(10, 1);
	std::cout << "after resising the vector " << std::endl;
	printv(v1);
	v1.resize(4);
	std::cout << "++++++0" << std::endl;
	printv(v1);
	std::cout << v1.capacity() << std::endl;
	std::cout << v1.size() << std::endl;
	// system("leaks container");
	size_t size = v1.max_size();
	try {
		v1.reserve(size+10);
		std::cout << "everything went as expected" << std::endl;
	}catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
    
    std::cout << "+++++++++++++" << std::endl;
    it = v.begin();
    ft::vector<int> v11 (2,400);
    v.insert (it + 2 , v11.begin() , v11.end());
    for (ft::vector<int>::iterator i = v.begin(); i < v.end() ; i++)
        std::cout << "\t" << *i ;
    std::cout << std::endl;
    int myarray [] = { 501,502,503 };
    v.insert (v.begin(), myarray, myarray+3);
    for (ft::vector<int>::iterator i = v.begin(); i < v.end() ; i++)
        std::cout << "\t" << *i ;
    std::cout << std::endl;
	return (0);	
}