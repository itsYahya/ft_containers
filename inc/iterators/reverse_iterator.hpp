/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 11:19:52 by yel-mrab          #+#    #+#             */
/*   Updated: 2023/01/16 02:31:47 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft{
	template <class iterator>
	class reverse_iterator{
		protected:
			iterator current;
		
		public:
			typedef iterator	iterator_type;
			typedef typename	iterator_traits<iterator>::difference_type difference_type;
			typedef typename	iterator_traits<iterator>::value_type value_type;
			typedef typename	iterator_traits<iterator>::pointer pointer;
			typedef typename	iterator_traits<iterator>::reference reference;
			typedef typename	iterator_traits<iterator>::iterator_category iterator_category;

			reverse_iterator() {};
			reverse_iterator(iterator_type it) {
				current = it;
			}

			template <class iter>
			reverse_iterator(const reverse_iterator<iter> &it){
				(*this) = it;
			}

			iterator_type base() const{
				return (current);
			}

			template <class iter>
			reverse_iterator<iter>	&operator=(const reverse_iterator<iter> &it){
				this->current = it.current;
				return (*this);
			}			

			reference operator*() const{
				iterator_type	tmp(current);
				return (*(--tmp));
			}
			
			iterator_type operator+(difference_type n) const{
				iterator_type iter(current - n);
				return (iter);
			}
			
			iterator_type	&operator++(){
				current--;
				return (*this);
			}
			
			iterator_type	operator++(int){
				iterator_type	tmp(current);
				current--;
				return (tmp);
			}
			
			iterator_type	&operator+=(difference_type n){
				current -= n;
				return (*this);
			}

			iterator_type	operator-(difference_type n) const{
				iterator_type iter(current + n);
				return (iter);
			}

			iterator_type	&operator--(){
				current++;
				return (this);
			}

			iterator_type	operator--(int){
				iterator_type tmp(current);
				current++;
				return (tmp);
			}

			iterator_type	&operator-=(difference_type n){
				current += n;
				return (*this);
			}
			
			pointer	operator->() const{
				return (&(operator*()));
			}
			
			reference	operator[](difference_type n) const{
				return (base()[-n -1]);
			}
	};

	template <class iter>
	reverse_iterator<iter> operator+(typename reverse_iterator<iter>::difference_type n, const reverse_iterator<iter> &it){
		reverse_iterator<iter> tmp(it - n);
		return (tmp);
	}

	template <class iter>
	typename reverse_iterator<iter>::difference_type operator-(const reverse_iterator<iter> &Lit, const reverse_iterator<iter> &Rit){
		return (Lit.base() - Rit.base());
	}
	
	template <class iter>
	bool	operator==(const reverse_iterator<iter> &Lit, const reverse_iterator<iter> &Rit){
		return (Lit.base() == Rit.base());
	}
	
	template <class iter>
	bool	operator!=(const reverse_iterator<iter> &Lit, const reverse_iterator<iter> &Rit){
		return (Lit.base() != Rit.base());
	}
	
	template <class iter>
	bool	operator<(const reverse_iterator<iter> &Lit, const reverse_iterator<iter> &Rit){
		return (Lit.base() < Rit.base());
	}
	
	template <class iter>
	bool	operator<=(const reverse_iterator<iter> &Lit, const reverse_iterator<iter> &Rit){
		return (Lit.base() <= Rit.base());
	}
	
	template <class iter>
	bool	operator>(const reverse_iterator<iter> &Lit, const reverse_iterator<iter> &Rit){
		return (Lit.base() > Rit.base());
	}
	
	template <class iter>
	bool	operator>=(const reverse_iterator<iter> &Lit, const reverse_iterator<iter> &Rit){
		return (Lit.base() >= Rit.base());
	}
}

#endif