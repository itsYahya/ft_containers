/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_iterator.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 13:02:57 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/12/18 13:49:34 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef F_ITERATOR_HPP
#define F_ITERATOR_HPP

#include "iterator.hpp"
#include <cstddef>

namespace ft{
	
	template <class T>
	class f_iterator : iterator<std::random_access_iterator_tag, T>
	{
		private:
			T	*ptr;

		public:
			typedef T								value_type;
			typedef	ptrdiff_t						difference_type;
			typedef T*								pointer;
			typedef T&								reference;
			typedef std::random_access_iterator_tag	iterator_category;

			f_iterator() {};
			
			f_iterator(pointer p){
				ptr = p;
			}
			
			f_iterator(f_iterator &iter){
				ptr = iter.ptr;
			}
			
			f_iterator &operator=(f_iterator const &copy){
				ptr = copy.ptr;
				return (*this);
			}

			bool	operator==(f_iterator const &iter) const{
				return (this->ptr == iter.ptr);
			}

			bool	operator!=(f_iterator const &iter) const{
				return (this->ptr != iter.ptr);
			}

			reference	operator*() const{
				return (*ptr);
			}

			pointer	operator->() const{
				return (ptr);
			}
			
			f_iterator	&operator++(){
				ptr++;
				return (*this);
			}

			f_iterator	operator++(int){
				f_iterator	iter(ptr);
				ptr++;
				return (iter);
			}
			
			f_iterator	&operator--(){
				ptr--;
				return (*this);
			}

			f_iterator	operator--(int){
				f_iterator	iter(ptr);
				ptr--;
				return (iter);
			}
			
			iterator	&operator+=(difference_type n){
				ptr += n;
				return (*this);
			}
			
			iterator	&operator-=(difference_type n){
				ptr -= n;
				return (*this);
			}
			
			f_iterator	operator+(difference_type n) const{
				f_iterator iter(ptr + n);
				return (iter);
			}
			
			f_iterator	operator-(difference_type n) const{
				f_iterator	iter(ptr - n);
				return (iter);
			}
			
			bool	operator<(f_iterator const &iter) const{
				return (iter.ptr < ptr);
			}

			bool	operator>(f_iterator const &iter) const{
				return (iter.ptr > ptr);
			}
			
			bool	operator<=(f_iterator const &iter) const{
				return (iter.ptr <= ptr);
			}

			bool	operator>=(f_iterator const &iter) const{
				return (iter.ptr >= ptr);
			}
			
	};
}

#endif