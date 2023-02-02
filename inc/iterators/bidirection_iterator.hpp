/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidirection_iterator.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 23:58:42 by yel-mrab          #+#    #+#             */
/*   Updated: 2023/02/02 23:11:25 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIDIRECTION_ITERATOR_HPP
#define BIDIRECTION_ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft{
	
	template <class T, class VT>
	class bidirection_iterator {
		public:
			typedef T														node_type;
			typedef VT														value_type;
			typedef typename iterator_traits<value_type*>::difference_type	difference_type;
			typedef typename iterator_traits<value_type*>::pointer			pointer;
			typedef typename iterator_traits<value_type*>::reference		reference;
			typedef std::bidirectional_iterator_tag							iterator_category;
			typedef bidirection_iterator<T, VT>								iterator_type;

		private:
			node_type*	ptr;
		
		public:
			bidirection_iterator() : ptr(NULL) {}
			
			bidirection_iterator(node_type* p) : ptr(p) {}

			bidirection_iterator(const iterator_type &iter) : ptr(iter.ptr) {}
			
			~bidirection_iterator() {};
			
			iterator_type	&operator=(const iterator_type &iter){
				this->ptr = iter.ptr;
				return (*this);
			}
			
			bool	operator==(const iterator_type &iter){
				return (iter.ptr == ptr);
			}
			
			bool	operator!=(const iterator_type &iter){
				return (iter.ptr != ptr);
			}
			
			reference	operator*(){
				return (ptr->data);
			}
			
			pointer		operator->() const{
				return (&ptr->data);
			}

			iterator_type	&operator++(){
				ptr = node_type::successor(this->ptr);
				return (*this);
			}
			
			iterator_type	operator++(int){
				iterator_type iter(*this);
				ptr = node_type::successor(this->ptr);
				return (iter);
			}
			
			iterator_type	&operator--(){
				ptr = node_type::predecessor(this->ptr);
				return (*this);
			}
			
			iterator_type	operator--(int){
				iterator_type iter(*this);
				ptr = node_type::predecessor(this->ptr);
				return (iter);
			}
	};
}

#endif