/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair_tests.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:03:26 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/12/27 16:03:15 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pair.hpp"
#include <iostream>

int main(){
	ft::pair<int, int> pair(808, 55), pair1(88, 555), pp;
	std::pair<int, int> p(808, 55), p1(88, 555);
	
	pp = ft::make_pair(55.0f, 'A');
	// std::cout << pair1.first << std::endl;
	// std::cout << pair1.second << std::endl;

	std::cout << pp.first << " " << pp.second << std::endl;
	std::cout << "from ft space  :: " << (pair <= pair1) << std::endl;
	std::cout << "from std space :: " << (p <= p1)  << std::endl;
}