/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 13:02:57 by yel-mrab          #+#    #+#             */
/*   Updated: 2023/01/08 17:11:43 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include "base_iterator.hpp"
#include "iterator_traits.hpp"
#include <cstddef>

namespace ft{
	
	template <class T>
	class random_iterator
	{
		private:
			T	*ptr;

		public:
			typedef T												value_type;
			typedef	typename iterator_traits<T*>::difference_type	difference_type;
			typedef typename iterator_traits<T*>::pointer			pointer;
			typedef typename iterator_traits<T*>::reference			reference;
			typedef std::random_access_iterator_tag					iterator_category;

			random_iterator() {};
			
			random_iterator(pointer p){
				ptr = p;
			}
			
			random_iterator(random_iterator const &iter){
				ptr = iter.ptr;
			}
			
			random_iterator &operator=(random_iterator const &copy){
				ptr = copy.ptr;
				return (*this);
			}

			bool	operator==(random_iterator const &iter) const{
				return (this->ptr == iter.ptr);
			}

			bool	operator!=(random_iterator const &iter) const{
				return (this->ptr != iter.ptr);
			}

			reference	operator*() const{
				return (*ptr);
			}

			pointer	operator->() const{
				return (ptr);
			}
			
			random_iterator	&operator++(){
				ptr++;
				return (*this);
			}

			random_iterator	operator++(int){
				random_iterator	iter(ptr);
				ptr++;
				return (iter);
			}
			
			random_iterator	&operator--(){
				ptr--;
				return (*this);
			}

			random_iterator	operator--(int){
				random_iterator	iter(ptr);
				ptr--;
				return (iter);
			}
			
			random_iterator	&operator+=(difference_type n){
				ptr += n;
				return (*this);
			}
			
			random_iterator	&operator-=(difference_type n){
				ptr -= n;
				return (*this);
			}
			
			random_iterator	operator+(difference_type n) const{
				random_iterator iter(ptr + n);
				return (iter);
			}
			
			random_iterator	operator-(difference_type n) const{
				random_iterator	iter(ptr - n);
				return (iter);
			}
			
			bool	operator<(random_iterator const &iter) const{
				return (iter.ptr < ptr);
			}

			bool	operator>(random_iterator const &iter) const{
				return (iter.ptr > ptr);
			}
			
			bool	operator<=(random_iterator const &iter) const{
				return (iter.ptr <= ptr);
			}

			bool	operator>=(random_iterator const &iter) const{
				return (iter.ptr >= ptr);
			}

			reference	operator[](difference_type n){
				return (ptr[n]);
			}

			reference	operator[](difference_type n) const{
				return (ptr[n]);
			}

			pointer	base() const{
				return (ptr);
			}
	};
	
	template <class T>
	random_iterator<T> operator+(typename random_iterator<T>::difference_type n, const random_iterator<T> &it){
		random_iterator<T> tmp(it - n);
		return (tmp);
	}

	template <class T>
	typename random_iterator<T>::difference_type operator-(const random_iterator<T> &Lit, const random_iterator<T> &Rit){
		return (Lit.base() - Rit.base());
	}
	
	template <class T>
	bool	operator==(const random_iterator<T> &Lit, const random_iterator<T> &Rit){
		return (Lit.base() == Rit.base());
	}
	
	template <class T>
	bool	operator!=(const random_iterator<T> &Lit, const random_iterator<T> &Rit){
		return (Lit.base() != Rit.base());
	}
	
	template <class T>
	bool	operator<(const random_iterator<T> &Lit, const random_iterator<T> &Rit){
		return (Lit.base() < Rit.base());
	}
	
	template <class T>
	bool	operator<=(const random_iterator<T> &Lit, const random_iterator<T> &Rit){
		return (Lit.base() <= Rit.base());
	}
	
	template <class T>
	bool	operator>(const random_iterator<T> &Lit, const random_iterator<T> &Rit){
		return (Lit.base() > Rit.base());
	}
	
	template <class T>
	bool	operator>=(const random_iterator<T> &Lit, const random_iterator<T> &Rit){
		return (Lit.base() >= Rit.base());
	}

	template <class T>
	typename ft::iterator_traits<T>::difference_type distance(T from, T until, std::random_access_iterator_tag){
		return (until - from);
	}

	template <class T>
	typename ft::iterator_traits<T>::difference_type distance(T from, T until, std::input_iterator_tag){
		typename ft::iterator_traits<T>:: difference_type n = 0;
		
		for (; from != until; from++){
			n++;
		}
		return (n);
	}
	
	template <class T>
	typename ft::iterator_traits<T>::difference_type difference(T from, T until){
		return (distance(from, until, typename ft::iterator_traits<T>::iterator_category()));
	}

}

#endif