/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:35:30 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/12/27 17:09:27 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP

#include "vector.hpp"

namespace ft{
	
	template <class T, class Container = ft::vector<T> >
	class stack
	{
		private:
			Container	c;
			
		public:
			typedef	T			value_type;
			typedef Container	container_type;
			typedef size_t		size_type;
			
			explicit stack(const container_type &c = container_type()){
				this->c = c;
			}
			
			
	};
	
}

#endif