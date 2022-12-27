/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:35:30 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/12/27 17:13:54 by yel-mrab         ###   ########.fr       */
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
			
			~stack() {
			}

			bool	empty() const{
				return (c.empty());
			}

			size_type	size() const{
				return (c.size());
			}
			
			value_type	&top() {
				return (c.back());
			}
			
			const value_type	&top() const{
				return (c.back());
			}

			void	push(const value_type &val){
				c.push_back(val);
			}

			void	pop(){
				c.pop_back();
			}
	};
	
}

#endif