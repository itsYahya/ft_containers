/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 10:48:28 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/12/16 14:12:30 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
#define ITERATOR_TRAITS_HPP

#include <cstddef>

namespace ft{
	template <class iter>
	struct iterator_traits
	{
		typedef typename difference_type	iter::difference_type;
		typedef typename value_type			iter::value_type;
		typedef typename pointer			iter::pointer;
		typedef typename reference			iter::reference;
		typedef typename iterator_category	iter::iterator_category;
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