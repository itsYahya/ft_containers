/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 12:23:40 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/12/20 16:27:07 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include "../iterators/iterator.hpp"
#include "../iterators/reverse_iterator.hpp"
#include <iostream>

namespace ft{
	template <class T, class Alloc = std::allocator<T> >
	class vector{
		private:
			T		*_arr;
			Alloc	_alloc;
			size_t	_size;
			size_t	_capacity;
			
			void	_realloc(){
				T		*arr;
				size_t	cap;

				cap = _capacity * 2;
				_capacity = cap;
				arr = _alloc.allocate(cap);
				for (size_t i = 0; i < _size; i++){
					_alloc.construct(arr + i, _arr[i]);
					_alloc.destroy(_arr + i);
				}				
				_alloc.deallocate(_arr, _size);
				_arr = arr;
			}

			void	_construct(const T &value){
				_alloc.construct(_arr + _size, value);
				_size++;
			}
			
		public:
			typedef T														value_type;
			typedef Alloc													allocator_type;
			typedef typename allocator_type::reference 						reference;
			typedef typename allocator_type::const_reference 				const_reference;
			typedef typename allocator_type::pointer 						pointer;
			typedef typename allocator_type::const_pointer 					const_pointer;
			typedef typename allocator_type::size_type 						size_type;
			typedef ft::iterator<value_type>								iterator;
			typedef const ft::iterator<value_type>							const_iterator;
			typedef ft::reverse_iterator<iterator>							reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>					const_reverse_iterator;
			typedef typename ft::iterator_traits<iterator>::difference_type	difference_type;
			
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
				
				for (size_type i = 0; i < n; i++){
					_alloc.construct(_arr + i, val);
				}
			}
			
			template <class Iterator>
			vector(Iterator from, Iterator until, const allocator_type &alloc = allocator_type()){
				difference_type	n;
				size_type		i;
				
				n = ft::difference<Iterator>(from, until);
				_size = n;
				_capacity = n;
				_alloc = alloc;
				_arr = _alloc.allocate(n);
				i = 0;
				for (; from != until; from++){
					_alloc.construct(_arr + i, *from);
					i++;
				}
			}
			
			vector(const vector &x){
				_size = x._size;
				_alloc = x._alloc;
				_capacity = x._capacity;
				_arr = _alloc.allocate(_capacity);

				for (size_type i; i < _size; i++){
					_alloc.construct(_arr + i, x._arr[i]);
				}
			}

			void	push_back(const value_type &value){
				if (_capacity == 0){
					_arr = _alloc.allocate(1);
					_construct(value);
					_capacity = 1;
				}
				else if (_size < _capacity){
					_construct(value);	
				}
				else {
					_realloc();
					_construct(value);
				}
			}
			
			iterator	begin(){
				iterator	iter(_arr);
				return (iter);
			}

			const_iterator	begin() const{
				const_iterator iter(_arr);
				return (iter);
			}
			
			iterator	end(){
				value_type	*ptr = NULL;
				if (_arr != NULL)
					ptr = _arr + _size;
				iterator	iter(ptr);
				return (iter);
			}

			const_iterator	end() const{
				value_type	*ptr = NULL;
				if (_arr != NULL)
					ptr = _arr + _size;
				const_iterator	iter(ptr);
				return (iter);
			}

			reverse_iterator	rbegin(){
				reverse_iterator	riter(end());
				return (riter);
			}

			const_reverse_iterator	rbegin() const{
				const_reverse_iterator	riter(end());
				return (riter);
			}
			
			reverse_iterator	rend(){
				reverse_iterator	riter(begin());
				return (riter);
			}

			const_reverse_iterator	rend() const{
				const_reverse_iterator	riter(begin());
				return (riter);
			}
			
			size_type	size() const{
				return (_size);
			}

			size_type	max_size() const{
				return (_alloc.max_size());
			}
			
			size_type	capacity() const{
				return (_capacity);
			}
			
			bool	empty() const{
				return (_size == 0);
			}
			
	};
}

#endif