/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 12:23:40 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/12/25 23:33:16 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include "../iterators/iterator.hpp"
#include "../iterators/reverse_iterator.hpp"
#include "../equal/equal.hpp"
#include <iostream>

namespace ft{
	template <class T, class Alloc = std::allocator<T> >
	class vector{
		private:
			T		*_arr;
			Alloc	_alloc;
			size_t	_size;
			size_t	_capacity;
			
			void	_realloc(size_t cap){
				T		*arr;

				_capacity = cap;
				arr = _alloc.allocate(cap);
				for (size_t i = 0; i < _size; i++){
					_alloc.construct(arr + i, _arr[i]);
					_alloc.destroy(_arr + i);
				}				
				_alloc.deallocate(_arr, _capacity);
				_arr = arr;
			}

			void	_construct(const T &value){
				_alloc.construct(_arr + _size, value);
				_size++;
			}

			void	_clear(){
				for (size_t i = 0; i < _size; i++){
					_alloc.destroy(_arr + i);
				}
				_size = 0;
			}
			
			size_t	_copy_range(ft::iterator<T> from, ft::iterator<T> until, T *arr){
				size_t	i = 0;
				
				for (; from != until; from++){
					_alloc.construct(arr + i, *from);
					i++;
				}
				return (i);
			}
			
			void	_construct(T *arr, size_t n, const size_t &value){
				size_t	index = 0;

				for (; index < n; index++){
					_alloc.construct(arr + index, value);
				}
			}

			void	_construct(ft::iterator<T> from, ft::iterator<T> until, T* arr){
				for (size_t i = 0; from != until; i++, from++){
					_alloc.construct(arr + i, *from);
				}
			}

			size_t	_move_rage(ft::iterator<T> position, ft::iterator<T> from, ft::iterator<T> until){
				size_t i = 0;
				for (; from != until; from++){
					*position = *from;
					position++;
					i++;
				}
				return (i);
			}
			
		public:
			typedef T														value_type;
			typedef Alloc													allocator_type;
			typedef typename allocator_type::reference						reference;
			typedef typename allocator_type::const_reference 				const_reference;
			typedef typename allocator_type::pointer 						pointer;
			typedef typename allocator_type::const_pointer 					const_pointer;
			typedef typename allocator_type::size_type 						size_type;
			typedef ft::iterator<value_type>								iterator;
			typedef const ft::iterator<value_type>							const_iterator;
			typedef ft::reverse_iterator<iterator>							reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>					const_reverse_iterator;
			typedef typename ft::iterator_traits<iterator>::difference_type	difference_type;
			
			explicit vector(const allocator_type &alloc = allocator_type()) {
				_size = 0;
				_capacity = 0;
				_arr = nullptr;
				_alloc = alloc;
			}

			explicit vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type()){
				_alloc = alloc;
				_arr = _alloc.allocate(n);
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

			~vector(){
				_clear();
				_alloc.deallocate(_arr, _capacity);
			}

			vector	&operator=(const vector &v){
				_clear();
				if (_capacity < v.size())
					_realloc(v.size());
				_construct(v.begin(), v.end(), _arr);
				_size = v.size();
				return (*this);
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
					_realloc(_capacity * 2);
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
			
			void	resize(size_type n, value_type value = value_type()){
				if (n < _size){
					_size = n;
					for (; n < _size; n++){
						_alloc.destroy(_arr + n);
					}
				}
				else if (n < _capacity){
					for (; _size < n; _size++){
						_alloc.construct(_arr + _size, value);
					}
				}
				else{
					_realloc(std::max(_capacity * 2, n));
					for (; _size < n; _size++){
						_alloc.construct(_arr + _size, value);
					}
				}
			}

			void	reserve(size_type n){
				if (n > _capacity){
					_realloc(n);
				}
			}
			
			reference	operator[](size_type n){
				return (_arr[n]);
			}

			const_reference	operator[](size_type n) const{
				return (_arr[n]);
			}

			reference	at(size_type n){
				if (n >= _size)
					throw std::out_of_range("this index is out of range");
				return (_arr[n]);
			}

			const_reference at(size_type n) const{
				if (n >= _size)
					throw std::out_of_range("this index is out of range");
				return (_arr[n]);
			}

			reference	front(){
				return (_arr[0]);
			}

			const_reference	front() const{
				return (_arr[0]);
			}

			reference	back(){
				return (_arr[_size - 1]);
			}

			const_reference	back() const{
				return (_arr[_size - 1]);
			}

			pointer	data(){
				return (_arr);
			}

			const_pointer	data() const{
				return (_arr);
			}

			void	assign(size_type n, const value_type &value){
				_clear();
				if (n > _capacity)
					_realloc(n);
				_size = n;
				for (size_type i = 0; i < n; i++){
					_alloc.construct(_arr + i, value);
				}
			}

			template <class Iterator >
			void	assign(Iterator from, Iterator until){
				size_type n = ft::difference(from, until);
				_clear();
				if (n > _capacity)
					_realloc(n);
				_size = n;
				for (size_type i = 0; i < n; i++){
					_alloc.construct(_arr + i, *from);
					from++;
				}
			}

			void	pop_back(){
				if (_size > 0){
					_size--;
					_alloc.destroy(_arr + _size);
				}
			}
			
			iterator	insert(iterator position, const value_type &value){
				pointer		tmp;
				size_type	n = _capacity, index = 0, size;
				
				if (_size + 1 > _capacity)
					n = _capacity * 2;
				size = _size + 1;
				if (n == 0) n = 1;
				tmp = _alloc.allocate(n);
				if (_capacity)
					index = _copy_range(begin(), position, tmp);
				_alloc.construct(tmp + index, value);
				_copy_range(position, end(), tmp + index + 1);
				_clear();
				_alloc.deallocate(_arr, _capacity);
				_arr = tmp;
				_size = size;
				_capacity = n;
				return (iterator(_arr + index));
			}

			void	insert(iterator position, size_type n, const value_type &value){
				pointer	tmp;
				size_type	index = 0, size = 0, cap = 0;
				
				if ((n + _size) > _capacity)
					cap = std::max(n + _size, _capacity * 2);
				size = _size;
				tmp = _alloc.allocate(cap);
				if (_capacity)
					index = _copy_range(begin(), position, tmp);
				_construct(tmp + index, n, value);
				_copy_range(position, end(), tmp + index + n);
				_clear();
				_alloc.deallocate(tmp, _capacity);
				_arr = tmp;
				_size = size + n;
				_capacity = cap;
			}

			void	insert(iterator position, iterator from, iterator until){
				size_type	n = 0, size = 0, index = 0, cap = 0;
				pointer		tmp;

				n = ft::difference(from, until);
				if (_size + n > _capacity)
					cap = std::max(n + _size, _capacity * 2);
				size = _size;
				tmp = _alloc.allocate(cap);
				if (_capacity)
					index = _copy_range(begin(), position, tmp);
				_construct(from, until, tmp + index);
				_copy_range(position, end(), tmp + index + n);
				_clear();
				_alloc.deallocate(_arr, _capacity);
				_size = size + n;
				_arr = tmp;
				_capacity = cap;
			}

			iterator	erase(iterator position){
				_move_rage(position, position + 1, end());
				_size--;
				_alloc.destroy(_arr + _size);
				return (position);
			}

			iterator	erase(iterator from, iterator until){
				size_type	n = 0, i = 0, size = 0;
				
				n = ft::difference(begin(), from);
				i = _move_rage(from, until, end()) + n;
				size = i;
				for (; i < _size; i++){
					_alloc.destroy(_arr + i);
				}
				_size = size;
				return (until);
			}
			
			void	swap(vector &v){
				pointer			arr_swap;
				size_type		size_swap, cap_swap;
				allocator_type	alloc_swap;
				
				arr_swap = v._arr;
				size_swap = v._size;
				cap_swap = v._capacity;
				alloc_swap = v._alloc;
				v._arr = this->_arr;
				v._size = this->_size;
				v._capacity = this->_capacity;
				v._alloc = this->_alloc;
				this->_arr = arr_swap;
				this->_size = size_swap;
				this->_capacity = cap_swap;
				this->_alloc = alloc_swap;
			}

			void	clear(){
				_clear();
			}

			allocator_type	get_allocatore() const{
				return (_alloc);
			}
			
	};
	
	template <class ITERATOR>
	bool	_smaller_then(ITERATOR begin1, ITERATOR begin2, ITERATOR end1, ITERATOR end2){
		while (begin1 != end1 && begin2 != end2){
			if (*begin2 < *begin1) return (false);
			else if (*begin1 < *begin2) return (true);
			begin1++;
			begin2++;
		}
		return (begin2 != end2);
	}

	template <class ITERATOR>
	bool	_grater_than(ITERATOR begin1, ITERATOR begin2, ITERATOR end1, ITERATOR end2){
		while (begin1 != end1 && begin2 != end2)
		{
			if (*begin1 < *begin2) return (false);
			else if (*begin2 < *begin1) return (true);
			begin1++;
			begin2++;
		}
		return (begin2 == end2 && begin1 != end1);
	}
	
	template <class T, class Alloc>
	bool	operator==(const vector<T, Alloc> &Lv, const vector<T, Alloc> &Rv){
		if (Lv.size() != Rv.size() || Lv.capacity() != Rv.capacity()
				|| !ft::equal(Lv.begin(), Lv.end(), Rv.begin()))
			return (false);
		return (true);
	}
	
	template <class T, class Alloc>
	bool	operator!=(const vector<T, Alloc> &Lv, const vector<T, Alloc> &Rv){
		return !(Lv == Rv);
	}
	
	template <class T, class Alloc>
	bool	operator<(const vector<T, Alloc> &Lv, const vector<T, Alloc> &Rv){
		return (_smaller_then(Lv.begin(), Rv.begin(), Lv.end(), Rv.end()));
	}

	template <class T, class Alloc>
	bool	operator>(const vector<T, Alloc> &Lv, const vector<T, Alloc> &Rv){
		return (_grater_than(Lv.begin(), Rv.begin(), Lv.end(), Rv.end()));
	}
	
	template <class T, class Alloc>
	bool	operator<=(const vector<T, Alloc> &Lv, const vector<T, Alloc> &Rv){
		return (Lv == Rv || Lv < Rv);
	}
	
	template <class T, class Alloc>
	bool	operator>=(const vector<T, Alloc> &Lv, const vector<T, Alloc> &Rv){
		return (Lv == Rv || Lv > Rv);
	}
	
	template <class T, class Alloc>
	void	swap(vector<T, Alloc> &Lv, vector<T, Alloc> &Rv){
		vector<T, Alloc> tmp(Lv);
		Lv = Rv;
		Rv = tmp;
	}
}

#endif