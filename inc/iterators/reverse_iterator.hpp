/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 11:19:52 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/12/15 12:12:01 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft{
	template <class T, class Pointer, class Reference>
	struct iterator{
		typedef T			value_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
	};

	template <class iterator>
	class reverse_iterator : public iterator <typename iterator_traits<iterator>::value_type,
							typename iterator_traits<iterator>::pointer,
							typename iterator_traits<iterator>::reference>{
		protected:
			iterator current;
		public:
			typedef iterator	iterator_type;
			typedef typename	iterator_traits<iterator>::value_type value_type;
			typedef typename	iterator_traits<iterator>::pointer pointer;
			typedef typename	iterator_traits<iterator>::reference reference;
	};
}

#endif