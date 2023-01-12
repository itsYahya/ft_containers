/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 02:34:01 by yel-mrab          #+#    #+#             */
/*   Updated: 2023/01/12 02:30:50 by yel-mrab         ###   ########.fr       */
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
			typedef Key																key_value;
			typedef T																mapped_value;
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
			
			map(const map &m) : _key_comp(m._key_comp), _alloc(m._alloc) ,_value_comp(_key_comp){
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
			
			size_type	erase(const key_value &key){
				size_type	size;
				
				size = _tree.delete_node(value_type(key, mapped_value()));
				return (size);
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