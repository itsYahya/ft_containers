/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_iterator.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 13:02:57 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/12/17 23:06:50 by yel-mrab         ###   ########.fr       */
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
	};
}

#endif