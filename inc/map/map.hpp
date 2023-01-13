/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 02:34:01 by yel-mrab          #+#    #+#             */
/*   Updated: 2023/01/14 00:08:59 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include <functional>
#include "pair.hpp"
#include "iterator_traits.hpp"
#include "bidirection_iterator.hpp"
#include "reverse_iterator.hpp"
#include "redblacktree.hpp"

namespace ft{
	
	template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> >  >
	class map{
		public:
			typedef ft::pair<const Key, T>											value_type;
			typedef Key																key_type;
			typedef T																mapped_type;
			typedef Compare															key_compare;
			class 																	value_compare;
			typedef Alloc															allocator_type;
			typedef typename allocator_type::reference								reference;
			typedef typename allocator_type::const_reference						const_reference;
			typedef typename allocator_type::pointer								pointer;
			typedef typename allocator_type::const_pointer							const_pointer;
			typedef	typename allocator_type::difference_type 						difference_type;
			typedef	typename allocator_type::size_type 								size_type;
		
		private:
			typedef	ft::RedBlackTree<value_type, value_compare, allocator_type>		redblacktree;
			key_compare																_key_comp;
			allocator_type															_alloc;
			value_compare															_value_comp;
			redblacktree															_tree;
			
		public:
			typedef typename redblacktree::iterator									iterator;
			typedef typename redblacktree::const_iterator							const_iterator;
			typedef typename redblacktree::reverse_iterator							reverse_iterator;
			typedef typename redblacktree::const_reverse_iterator					const_reverse_iterator;

			explicit	map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type())
						: _key_comp(comp), _alloc(alloc) ,_value_comp(_key_comp), _tree(_value_comp){}
			
			template <class InputIterator>
			map(InputIterator from, InputIterator until, const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type())
				: _key_comp(comp), _alloc(alloc), _value_comp(_key_comp), _tree(_value_comp){
				insert(from, until);
			}
			
			map(const map &m) : _key_comp(m._key_comp), _alloc(m._alloc) ,_value_comp(_key_comp), _tree(_value_comp){
				*this = m;
			}
			
			map	&operator=(const map &m){
				this->_tree = m._tree;
				return (*this);
			}

			~map() {}

			iterator	begin(){
				return (_tree.begin());
			}

			const_iterator	begin() const {
				return (_tree.begin());
			}

			iterator	end(){
				return (_tree.end());
			}

			const_iterator	end() const {
				return (_tree.end());
			}

			reverse_iterator	rbegin() {
				return (reverse_iterator(begin()));
			}

			const_reverse_iterator	rbegin() const{
				return (const_reverse_iterator(begin()));
			}

			reverse_iterator	rend() {
				return (reverse_iterator(end()));
			}

			const_reverse_iterator	rend() const{
				return (const_reverse_iterator(end()));
			}
			
			bool	empty() const{
				return (_tree.empty());
			}
			
			size_type	size() const{
				return (_tree.size());
			}

			size_type	max_size() const{
				return (_tree.max_size());
			}

			ft::pair<iterator, bool>	insert(const value_type &value){
				ft::pair<iterator, bool> pair;
				
				pair = _tree.insert(value);
				return (pair);
			}

			iterator	insert(iterator position, const value_type &value){
				ft::pair<iterator, bool> pair;
				
				(void) position;
				pair = _tree.insert(value);
				return (pair.first);
			}
			
			template <class InputIterator>
			void	insert(InputIterator from, InputIterator until){
				for (; from != until; from++)
					_tree.insert(*from);
			}

			void	erase(iterator position){
				_tree.delete_node(*position);
			}
			
			size_type	erase(const key_type &key){
				size_type	size;
				
				size = _tree.delete_node(value_type(key, mapped_type()));
				return (size);
			}

			void	erase(iterator from, iterator end){
				iterator	tmp;

				tmp = from++;
				while (from != end){
					erase(tmp);
					tmp = from++;
				}
				erase(tmp);
			}

			void	swap(map &m){
				map tmp(m);

				m = *this;
				*this = tmp;
			}
			
			void	clear(){
				_tree.clear();
			}
	
			key_compare	key_comp() const{
				return (_key_comp);
			}

			value_compare	value_comp() const{
				return (_value_comp);
			}

			allocator_type	get_allocator() const{
				return (_alloc);
			}
	
			mapped_type	&operator[](const key_type &key){
				typename redblacktree::pointer	node;
				iterator						iter;
				
				node = _tree.search(value_type(key, mapped_type()));
				if (node->is_nil()){
					iter = insert(value_type(key, mapped_type())).first;
					return ((*iter).second);
				}
				return (node->data.second);
			}

			mapped_type	&at(const key_type &key){
				typename redblacktree::pointer	node;
				
				node = _tree.search(value_type(key, mapped_type()));
				if (node->is_nil())
					throw std::out_of_range("this key is out of rang");
				return (node->data.second);
			}

			const mapped_type	&at(const key_type &key) const{
				typename redblacktree::pointer	node;
				
				node = _tree.search(value_type(key, mapped_type()));
				if (node->is_nil())
					throw std::out_of_range("this key is out of rang");
				return (node->data.second);
			}

			iterator	find(const key_type &key){
				typename redblacktree::pointer	node;
				iterator						iter;
				
				node = _tree.find(value_type(key, mapped_type()));
				iter = iterator(node);
				return (iter);
			}

			const_iterator	find(const key_type &key) const{
				typename redblacktree::pointer	node;
				const_iterator						iter;
				
				node = _tree.find(value_type(key, mapped_type()));
				iter = const_iterator(node);
				return (iter);
			}

			size_type	count(const key_type &key) const{
				return (find(key) != end());
			}

			iterator	lower_bound(const key_type &key){
				iterator	iter;

				iter = find(key);
				if (iter != end())
					return (iter);
				iter = begin();
				for (; iter != end(); iter++){
					if (_value_comp(value_type(key, mapped_type()), *iter))
						return (iter);
				}
				return (iter);
			}
			
			const_iterator	lower_bound(const key_type &key) const{
				const_iterator	iter;

				iter = find(key);
				if (iter != end())
					return (iter);
				iter = begin();
				for (; iter != end(); iter++){
					if (_value_comp(value_type(key, mapped_type()), *iter))
						return (iter);
				}
				return (iter);
			}
			
	};

	template <class Key, class T, class Compare, class Alloc>
	class	ft::map<Key, T, Compare, Alloc>::value_compare : public std::binary_function<value_type, value_type, bool>{
		friend class map;
		public:
			Compare	comp;
			value_compare(Compare &c) : comp(c) {}

		public:
			typedef bool		result_type;
			typedef value_type	first_argument_type;
			typedef value_type	second_argument_type;
			bool	operator()(const value_type &x, const value_type &y) const{
				return (comp(x.first, y.first));
			}
	};
}

#endif