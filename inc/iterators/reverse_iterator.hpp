/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 11:19:52 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/12/16 14:44:03 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft{
	template <class Category, class T, class Distance, class Pointer, class Reference>
	struct iterator{
		typedef T			value_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
		typedef Category	iterator_category;
		typedef Distance	difference_type;
	};

	template <class iterator>
	class reverse_iterator : public iterator < typename iterator_traits<iterator>::difference_type,
							typename iterator_traits<iterator>::value_type,
							typename iterator_traits<iterator>::pointer,
							typename iterator_traits<iterator>::reference,
							typename iterator_traits<iterator>::iterator_category>{
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

			iterator_type base() const{
				return (current);
			}
			
			reference operator*(){
				iterator_type	tmp(current);
				return (*(--tmp));
			}
	};
}

#endif