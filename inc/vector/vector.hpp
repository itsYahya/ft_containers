/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 12:23:40 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/12/19 16:00:27 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VERCTO_HPP
#define VECTOR_HPP

#include <memory>
#include "iterator.hpp"
#include "reverse_iterator.hpp"

namespace ft{
	template <class T, class Alloc = std::allocator<T>>
	class vector{
		private:
			T		*_arr;
			Alloc	_alloc;
			size_t	_size;
			size_t	_capacity;
			
		public:
			typedef T														value_type;
			typedef Alloc													allocator_type;
			typedef typename allocator_type::reference 						reference;
			typedef typename allocator_type::const_reference 				const_reference;
			typedef typename allocator_type::pointer 						pointer;
			typedef typename allocator_type::const_pointer 					const_pointer;
			typedef typename allocator_type::size_type 						size_type;
			typedef iterator<value_type>									iterator;
			typedef const iterator<value_type>								const_iterator;
			typedef reverse_iterator<iterator>								reverse_iterator;
			typedef reverse_iterator<const_iterator>						const_reverse_iterator;
			typedef typename ft::iterator_traits<Iterator>::difference_type	difference_type;
			typedef typename allocator_type::size_type						size_type;
			
			vector(const allocator_type &alloc = allocator_type()) {
				_size = 0;
				_capacity = 0;
				_arr = nullptr;
				_alloc = alloc;
			}

			vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type()){
				_alloc = alloc;
				_arr = _alloc.alocate(n);
				_size = n;
				_capacity = n;
				
				for (int i = 0; i < n; i++){
					_alloc.construct(_arr + i, val);
				}
			}
			
	};
}

#endif