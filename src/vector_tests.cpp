/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:37:30 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/12/26 19:58:15 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/vector/vector.hpp"
#include <vector>

int main(){
	ft::vector<int> vector, v;
	
	vector.push_back(991);
	vector.push_back(992);
	vector.push_back(993);
	vector.push_back(994);
	vector.push_back(995);

	v.push_back(909);
	v.push_back(929);
	v.push_back(949);
	v.push_back(989);
	
	// vector = v;
	// std::cout << v.size() << std::endl;
	// std::cout << vector.size() << std::endl;
	
	// ft::vector<int>::iterator iter = vector.begin();
	// for (int i = 1; iter != vector.end(); iter++, i++){
	// 	std::cout << "element number " << i << " : " << *iter << std::endl;
	// }

	// ft::vector<int>::iterator iter = vv.begin();
	// std::cout << vv.end() - iter << std::endl; 
	
	// vector.swap(v);
	// ft::vector<int>::iterator iter = v.begin();
	// for (; iter != v.end(); iter++){
	// 	std::cout << *iter << std::endl;
	// }
	// std::vector<int>::iterator iter = vector.erase(vector.begin(), vector.end() - 2);
	// iter = vector.begin();
	// for (; iter != vector.end(); iter++){
	// 	std::cout << *iter << std::endl;
	// }
	
	// // data function test
	// int	*ptr = vector.data();
	// *ptr = 88;
	// std::cout << *ptr << std::endl;
	
	// // back and fron functions test
	// std::cout << "back element : " << vector.back() << std::endl;
	// std::cout << "front element : " << vector.front() << std::endl;
	
	// // // at function test
	// try{
	// 	std::cout << vector.at(400) << std::endl;
	// }catch (std::exception &e){
	// 	std::cout << e.what() << std::endl;
	// }

	// // [] operator test
	// std::cout << vector[4] << std::endl;

	// // reserve function test
	// std::cout << vector.capacity() << std::endl;
	// vector.reserve(15);
	// std::cout << vector.capacity() << std::endl;
	
	// // resize function test
	// std::cout << "+++++++++ before resize ++++++++" << std::endl;
	// std::cout << "vector size : " << vector.size() << std::endl;
	// std::cout << "vector capacity : " << vector.capacity() << std::endl;
	// ft::vector<int>::iterator iter = vector.begin();
	// for (; iter != vector.end(); iter++){
	// 	std::cout << *iter << std::endl;
	// }
	// vector.resize(10);
	// std::cout << "+++++++++ after resize ++++++++" << std::endl;
	// std::cout << "vector size : " << vector.size() << std::endl;
	// std::cout << "vector capacity : " << vector.capacity() << std::endl;
	// iter = vector.begin();
	// for (; iter != vector.end(); iter++){
	// 	std::cout << *iter << std::endl;
	// }
	
	// // iterators test
	// std::cout << "+++++++++++ iterator ++++++++++" << std::endl;
	// ft::vector<int>::iterator iter = vector.begin();
	// for (; iter != vector.end(); iter++){
	// 	std::cout << *iter << std::endl;
	// }
	// std::cout << "+++++++++++ reverse iterator ++++++++++" << std::endl;
	// ft::vector<int>::reverse_iterator riter = vector.rbegin();
	// for (; riter != vector.rend(); riter++){
	// 	std::cout << *riter << std::endl;
	// }
	// std::cout << "+++++++++++ const iterator ++++++++++" << std::endl;
	// ft::vector<int> const cv(6, 55);
	// ft::vector<int>::const_iterator citer = cv.begin();
	// for (; citer != cv.end(); citer++){
	// 	std::cout << *citer << std::endl;
	// }
	
	// TODO		const_iterator test

	// // some functions test
	// std::cout << "+++++++++++++++++++++" << std::endl;
	// std::cout << vector.size() << std::endl;
	// std::cout << vector.capacity() << std::endl;
	// std::cout << vector.max_size() << std::endl;
	// std::cout << vector.empty() << std::endl;
	
	return (0);	
}