/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 02:17:59 by yel-mrab          #+#    #+#             */
/*   Updated: 2023/01/15 04:16:05 by yel-mrab         ###   ########.fr       */
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
			typedef Compare															value_comapre;
			typedef Compare															key_comapre;
			typedef Alloc															allocator_type;
			typedef typename allocator_type::reference								reference;
			typedef typename allocator_type::const_reference						const_reference;
			typedef typename allocator_type::pointer								pointer;
			typedef typename allocator_type::const_pointer							const_pointer;
			typedef	typename allocator_type::difference_type 						difference_type;
			typedef	typename allocator_type::size_type 								size_type;

		private:
			typedef ft::RedBlackTree<value_type, value_comapre, allocator_type>		redblacktree;
			allocator_type															_alloc;
			key_comapre																_key_comp;
			redblacktree															_tree;

		public:
			typedef typename redblacktree::iterator									iterator;
			typedef typename redblacktree::const_iterator							const_iterator;
			typedef typename redblacktree::reverse_iterator							reverse_iterator;
			typedef typename redblacktree::const_reverse_iterator					const_reverse_iterator;

			explicit	set(const key_comapre &comp = key_comapre(), const allocator_type &alloc = allocator_type()) : _alloc(alloc), _key_comp(comp), _tree(_key_comp) {}
			
			template <class InputIterator>
			set (InputIterator from, InputIterator until, const key_comapre &comp = key_comapre(), const allocator_type &alloc = allocator_type()) 
				: _alloc(alloc), _key_comp(comp), _tree(_key_comp)
			{
				isert(from, until);
			}

			set	(const set &s){
				*this = s;
			}

			set	&operator=(const set &s){
				this->_alloc = s._alloc;
				this->_key_comp = s._key_comp;
				this->_tree = s._tree;
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

			size_type	empty() const{
				return (_tree.empty());
			}

			size_type	size() const{
				return (_tree.size());
			}
	};
}

#endif