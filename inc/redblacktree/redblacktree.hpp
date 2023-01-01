/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redblacktree.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 19:43:52 by yel-mrab          #+#    #+#             */
/*   Updated: 2023/01/01 03:56:09 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDBLACKTREE_HPP
#define REDBLACKTREE_HPP

#define red 1
#define black 0

namespace ft{
	
	template <class T>
	class Node{
		public:
			typedef T				value_type;
			typedef Node<T>*		pointer;
			typedef const pointer	const_pointer;

			value_type	data;
			bool		color;
			pointer		right;
			pointer		left;
			pointer		parent;

			Node(const value_type &data, pointer parent = nullptr, bool color = red)
				: data(data), color(color), right(nullptr), left(nullptr), parent(parent) {}
			
			static pointer	minimum(pointer node){
				while (!node->right->is_nil())
					node = node->right;
				return (node);
			}

			static pointer	maximum(pointer node){
				while (!node->left->is_nil())
					node = node->left;
				return (node)
			}

			static pointer	successor(pointer node){
				pointer	y;
				
				if (!node->right->is_nil())
					return (minimum(node->right));
				y = node->parent;
				while (!y->is_nil() && y->right == node){
					node = y;
					y = y->parent;
				}
				return (y);
			}
			
			static pointer	predecessor(pointer node){
				pointer	y;

				if (!node->left->is_nil())
					return (maximum(node->left));
				y = node->parent;
				while (!y->is_nil() && y->left = node){
					node = y;
					y = y->parent;
				}
				return (y);
			}

			template <class Comp>
			static pointer	find(const pointer root, value_type &value, Comp comp = Comp()){
				while (!root->is_nil()){
					if (comp(root->data, value))
						root = root->right;
					else if (comp(value, root->data))
						root = root->left;
					else
						return (root);
				}
				return (root);
			}
			

			bool	is_nil(){
				return (this != nullptr && this->right == nullptr && this->left == nullptr);
			}
			bool	is_red() { return (this->color == red); }
			bool	is_black() { return (this->color == black); }
	};

	template <class T, class Comp, class Alloc>
	class RedBlackTree{
		public:
			typedef T															value_type;
			typedef Node<T>														node_type;
			typedef Alloc														allocator_type;
			typedef typename allocator_type::template rebind<node_type>::other	allocator_node;
			typedef typename allocator_node::pointer							pointer;
			typedef typename allocator_node::const_pointer						const_pointer;
			typedef typename allocator_node::reference							reference;
			typedef typename allocator_node::const_reference					const_reference;
			typedef typename allocator_node::difference_type					difference_type;
			typedef typename allocator_node::size_type							size_type;
			typedef RedBlackTree<value_type, Comp, allocator_node>				rbtree;
		
		private:
			pointer			_root;
			size_type		_size;
			pointer			_nil;
			pointer			_end;
			Comp			_comp;
			allocator_node	_alloc;

		public:
			RedBlackTree(const Comp &comp): _size(0), _comp(comp()){
				_nil = _alloc.allocate(1);
				_alloc.construct(_nil, value_type());
				_end = _alloc.allocate(1);
				_alloc.construct(_end, value_type());
				_nil->color = black;
				_root = _nil;
			}
			
			
	};
}

#endif