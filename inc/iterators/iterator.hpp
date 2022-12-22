/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 13:02:57 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/12/22 13:33:41 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include "base_iterator.hpp"
#include "iterator_traits.hpp"
#include <cstddef>

namespace ft{
	
	template <class T>
	class iterator : base_iterator<std::random_access_iterator_tag, T>
	{
		private:
			T	*ptr;

		public:
			typedef T								value_type;
			typedef	ptrdiff_t						difference_type;
			typedef T*								pointer;
			typedef T&								reference;
			typedef std::random_access_iterator_tag	iterator_category;

			iterator() {};
			
			iterator(pointer p){
				ptr = p;
			}
			
			iterator(iterator const &iter){
				ptr = iter.ptr;
			}
			
			iterator &operator=(iterator const &copy){
				ptr = copy.ptr;
				return (*this);
			}

			bool	operator==(iterator const &iter) const{
				return (this->ptr == iter.ptr);
			}

			bool	operator!=(iterator const &iter) const{
				return (this->ptr != iter.ptr);
			}

			reference	operator*() const{
				return (*ptr);
			}

			pointer	operator->() const{
				return (ptr);
			}
			
			iterator	&operator++(){
				ptr++;
				return (*this);
			}

			iterator	operator++(int){
				iterator	iter(ptr);
				ptr++;
				return (iter);
			}
			
			iterator	&operator--(){
				ptr--;
				return (*this);
			}

			iterator	operator--(int){
				iterator	iter(ptr);
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
			
			iterator	operator+(difference_type n) const{
				iterator iter(ptr + n);
				return (iter);
			}
			
			iterator	operator-(difference_type n) const{
				iterator	iter(ptr - n);
				return (iter);
			}
			
			bool	operator<(iterator const &iter) const{
				return (iter.ptr < ptr);
			}

			bool	operator>(iterator const &iter) const{
				return (iter.ptr > ptr);
			}
			
			bool	operator<=(iterator const &iter) const{
				return (iter.ptr <= ptr);
			}

			bool	operator>=(iterator const &iter) const{
				return (iter.ptr >= ptr);
			}

			reference	operator[](difference_type n){
				return (ptr[n]);
			}

			reference	operator[](difference_type n) const{
				return (ptr[n]);
			}
	};
	
	template <class T>
	typename ft::iterator_traits<T>::difference_type difference(T from, T until){
		typename ft::iterator_traits<T>:: difference_type n = 0;

		for (; from != until; from++){
			n++;
		}
		return (n);
	}
	
}

#endif