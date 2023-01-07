/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidirection_iterator.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 23:58:42 by yel-mrab          #+#    #+#             */
/*   Updated: 2023/01/08 00:36:22 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIDIRECTION_ITERATOR_HPP
#define BIDIRECTION_ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft{
	
	template <class T>
	class bidirection_iterator {
		public:
			typedef T												value_type;
			typedef typename iterator_traits<T*>::difference_type	difference_type;
			typedef typename iterator_traits<T*>::pointer			pointer;
			typedef typename iterator_traits<T*>::reference			reference;
			typedef std::bidirectional_iterator_tag					iterator_category;
			typedef bidirection_iterator<T>							iterator_type;

		private:
			pointer	ptr;
		
		public:
			bidirection_iterator() {}
			
			bidirection_iterator(pointer p){
				ptr = p;
			}

			bidirection_iterator(const iterator_type &iter){
				ptr = iter.ptr;
			}
			
			iterator_type	&operator=(const iterator_type &iter){
				this->ptr = iter.ptr;
				return (*this);
			}
			
			bool	operator==(const iterator_type &iter){
				return (iter.ptr == ptr);
			}
			
			bool	operator!=(const iterator_type &iter){
				return (iter.ptr != ptr);
			}
	};
}

#endif