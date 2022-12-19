/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_iterator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 12:56:35 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/12/19 17:05:35 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_ITERATOR_HPP
#define BASE_ITERATOR_HPP

namespace ft
{
	template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
	struct base_iterator{
		typedef T			value_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
		typedef Category	iterator_category;
		typedef Distance	difference_type;
	};
} // namespace ft

#endif