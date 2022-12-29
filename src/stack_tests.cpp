/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tests.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:46:50 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/12/27 19:19:15 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.hpp"
#include <stack>

int main(){
	std::stack<int> s, s2;

	s.push(55);
	s.push(77);
	std::cout << "check whether the stack is empty : " << s.empty() << std::endl;
	std::cout << "the size of the stack is : " << s.size() << std::endl;
	std::cout << "the top  element in the stack is : " << s.top() << std::endl;
	s.pop();
	s2.push(55);
	s2.push(3939);
	s2.pop();
	std::cout << "the top element in the stack now is : " << s.top() << std::endl;
	std::cout << (s == s2) << std::endl;
}