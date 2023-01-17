/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 02:17:59 by yel-mrab          #+#    #+#             */
/*   Updated: 2023/01/17 03:00:47 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
#define SET_HPP

#include <functional>
#include "redblacktree.hpp"

namespace	ft{
	
	template <class T, class Compare = std::less<T>, class Alloc = std::allocator<T> >
	class set{
		public:
			typedef T																value_type;
			typedef T																key_type;
			typedef Compare															value_compare;
			typedef Compare															key_compare;
			typedef Alloc															allocator_type;
			typedef typename allocator_type::reference								reference;
			typedef typename allocator_type::const_reference						const_reference;
			typedef typename allocator_type::pointer								pointer;
			typedef typename allocator_type::const_pointer							const_pointer;
			typedef	typename allocator_type::difference_type 						difference_type;
			typedef	typename allocator_type::size_type 								size_type;

		private:
			typedef ft::RedBlackTree<value_type, value_compare, allocator_type>		redblacktree;
			allocator_type															_alloc;
			key_compare																_key_comp;
			redblacktree															_tree;
			value_compare															_value_comp;

		public:
			typedef typename redblacktree::iterator									iterator;
			typedef typename redblacktree::const_iterator							const_iterator;
			typedef typename redblacktree::reverse_iterator							reverse_iterator;
			typedef typename redblacktree::const_reverse_iterator					const_reverse_iterator;

			explicit	set(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type()) : _alloc(alloc), _key_comp(comp), _tree(_key_comp), _value_comp(_key_comp) {}
			
			template <class InputIterator>
			set (InputIterator from, InputIterator until, const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type()) 
				: _alloc(alloc), _key_comp(comp), _tree(_key_comp), _value_comp(_key_comp)
			{
				insert(from, until);
			}

			set	(const set &s): _alloc(s._alloc), _key_comp(s._key_comp), _tree(_key_comp), _value_comp(s._value_comp){
				*this = s;
			}

			~set() {}
			
			set	&operator=(const set &s){
				this->_alloc = s._alloc;
				this->_key_comp = s._key_comp;
				this->_tree = s._tree;
				this->_value_comp = s._value_comp;
				return (*this);
			}

			ft::pair<iterator, bool>	insert(const value_type &value){
				ft::pair<iterator, bool>	pair;
				
				pair = _tree.insert(value);
				return (pair);
			}
			
			template <class InputIterator>
			void	insert(InputIterator from, InputIterator until){
				for (; from != until; from++){
					_tree.insert(*from);
				}
			}
			
			iterator	insert(iterator position, const value_type &value){
				(void) position;
				return (_tree.insert(value).first);
			}

			iterator	begin(){
				return (_tree.begin());
			}

			const_iterator	begin() const{
				return (_tree.begin());
			}

			iterator	end(){
				return (_tree.end());
			}

			const_iterator	end() const{
				return (_tree.end());
			}

			reverse_iterator	rbegin(){
				return (reverse_iterator(end()));
			}

			const_reverse_iterator	rbegin() const{
				return (const_reverse_iterator(end()));
			}

			reverse_iterator	rend(){
				return (reverse_iterator(begin()));
			}

			const_reverse_iterator	rend() const{
				return (const_reverse_iterator(begin()));
			}

			void	erase(iterator position){
				_tree.delete_node(*position);
			}
			
			size_type	erase(const value_type &value){
				size_type	size;
				
				size = _tree.delete_node(value);
				return (size);
			}

			void	erase(iterator from, iterator end){
				iterator	tmp;

				tmp = from++;
				while (from != end){
					erase(*tmp);
					tmp = from++;
				}
				erase(*tmp);
			}
			
			void	swap(set &s){
				set	tmp(s);
				
				s = *this;
				*this = tmp;
			}

			void	clear(){
				_tree.clear();
			}
			
			size_type	empty() const{
				return (_tree.empty());
			}

			size_type	size() const{
				return (_tree.size());
			}

			size_type	max_size() const{
				return (_alloc.max_size());
			}

			key_compare	key_comp() const{
				return (_key_comp);
			}

			value_compare	value_comp() const{
				return (_value_comp);
			}
			
			iterator	find(const value_type &value){
				typename redblacktree::pointer	node;
				iterator						iter;
				
				node = _tree.find(value);
				iter = iterator(node);
				return (iter);
			}

			const_iterator	find(const value_type &value) const{
				typename redblacktree::pointer	node;
				const_iterator						iter;
				
				node = _tree.find(value);
				iter = const_iterator(node);
				return (iter);
			}
			
			size_type	count(const value_type &value) const{
				return (find(value) != end());
			}

			iterator	lower_bound(const value_type &value){
				iterator	iter;

				iter = find(value);
				if (iter != end())
					return (iter);
				iter = begin();
				for (; iter != end(); iter++){
					if (_value_comp(value, *iter))
						return (iter);
				}
				return (iter);
			}
			
			const_iterator	lower_bound(const value_type &value) const{
				const_iterator	iter;

				iter = find(value);
				if (iter != end())
					return (iter);
				iter = begin();
				for (; iter != end(); iter++){
					if (_value_comp(value, *iter))
						return (iter);
				}
				return (iter);
			}

			iterator	upper_bound(const value_type &value){
				iterator	iter;

				iter = find(value);
				if (iter == end())
					return (lower_bound(value));
				return (++iter);
			}

 			const_iterator	upper_bound(const value_type &value) const{
				const_iterator	iter;

				iter = find(value);
				if (iter == end())
					return (lower_bound(value));
				return (++iter);
			}

			ft::pair<iterator, iterator>	equal_range(const value_type &value){
				ft::pair<iterator, iterator>	pair;

				pair.first = lower_bound(value);
				pair.second = upper_bound(value);
				return (pair);
			}

			ft::pair<const_iterator, const_iterator>	equal_range(const value_type &value) const{
				ft::pair<const_iterator, const_iterator>	pair;

				pair.first = lower_bound(value);
				pair.second = upper_bound(value);
				return (pair);
			}

			allocator_type	get_allocator() const{
				return (_alloc);
			}
	};
}

#endif