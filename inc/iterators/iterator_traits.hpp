/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 10:48:28 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/12/19 16:58:00 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
#define ITERATOR_TRAITS_HPP

#include <cstddef>

namespace ft{
	template <class iter>
	struct iterator_traits
	{
		typedef typename 	iter::difference_type 	difference_type;
		typedef typename 	iter::value_type 		value_type;
		typedef typename 	iter::pointer 			pointer;
		typedef typename 	iter::reference 		reference;
		typedef typename 	iter::iterator_category iterator_category;
	};
	
	template <class T>
	struct iterator_traits<T *>
	{
		typedef ptrdiff_t						difference_type;
		typedef T								value_type;
		typedef T								*pointer;
		typedef T								&reference;
		typedef std::random_access_iterator_tag iterator_catefory;
	};

	template <class T>
	struct iterator_traits<const T *>
	{
		typedef ptrdiff_t						difference_type;
		typedef T								value_type;
		typedef const T							*pointer;
		typedef const T							&reference;
		typedef std::random_access_iterator_tag iterator_catefory;
	};
}


#endif