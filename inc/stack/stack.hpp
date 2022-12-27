/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:35:30 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/12/27 19:09:15 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP

#include "vector.hpp"

namespace ft{
	
	template <class T, class Container = ft::vector<T> >
	class stack
	{
		protected:
			Container	c;
			
		public:
			typedef	T									value_type;
			typedef Container							container_type;
			typedef typename container_type::size_type	size_type;
			
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
			template <class TP, class C>
			friend bool	operator==(const ft::stack<TP, C> &s1, const ft::stack<TP, C> &s2);
			template <class TP, class C>
			friend bool	operator!=(const ft::stack<TP, C> &s1, const ft::stack<TP, C> &s2);
			template <class TP, class C>
			friend bool	operator<(const ft::stack<TP, C> &s1, const ft::stack<TP, C> &s2);
			template <class TP, class C>
			friend bool	operator<=(const ft::stack<TP, C> &s1, const ft::stack<TP, C> &s2);
			template <class TP, class C>
			friend bool	operator>(const ft::stack<TP, C> &s1, const ft::stack<TP, C> &s2);
			template <class TP, class C>
			friend bool	operator>=(const ft::stack<TP, C> &s1, const ft::stack<TP, C> &s2);
	};
	
	template <class T, class Container>
	bool	operator==(const ft::stack<T, Container> &s1, const ft::stack<T, Container> &s2){
		return (s1.c == s2.c);
	}

	template <class T, class Container>
	bool	operator!=(const ft::stack<T, Container> &s1, const ft::stack<T, Container> &s2){
		return (s1.c != s2.c);
	}

	template <class T, class Container>
	bool	operator<(const ft::stack<T, Container> &s1, const ft::stack<T, Container> &s2){
		return (s1.c < s2.c);
	}

	template <class T, class Container>
	bool	operator<=(const ft::stack<T, Container> &s1, const ft::stack<T, Container> &s2){
		return (s1.c <= s2.c);
	}

	template <class T, class Container>
	bool	operator>(const ft::stack<T, Container> &s1, const ft::stack<T, Container> &s2){
		return (s1.c > s2.c);
	}

	template <class T, class Container>
	bool	operator>=(const ft::stack<T, Container> &s1, const ft::stack<T, Container> &s2){
		return (s1.c >= s2.c);
	}

}

#endif