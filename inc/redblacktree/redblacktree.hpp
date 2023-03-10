/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redblacktree.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 19:43:52 by yel-mrab          #+#    #+#             */
/*   Updated: 2023/02/02 23:13:09 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDBLACKTREE_HPP
#define REDBLACKTREE_HPP

#define red 1
#define black 0

#define	LEFT 1
#define RIGHT 0

#include "bidirection_iterator.hpp"
#include "reverse_iterator.hpp"
#include "pair.hpp"
#include <iostream>

namespace ft{
	
	template <class T>
	class Node{
		public:
			typedef T				value_type;
			typedef Node<T>*		pointer;
			typedef const Node<T>*	const_pointer;

			value_type	data;
			bool		color;
			pointer		right;
			pointer		left;
			pointer		parent;

			Node(const value_type &data, pointer parent = NULL, bool color = red)
				: data(data), color(color), right(NULL), left(NULL), parent(parent) {}
			
			static pointer	minimum(pointer node){
				while (!node->left->is_nil())
					node = node->left;
				return (node);
			}

			static pointer	maximum(pointer node){
				while (!node->right->is_nil())
					node = node->right;
				return (node);
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
				while (!y->is_nil() && y->left == node){
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
				return (this->right == NULL && this->left == NULL);
			}
			bool	is_red() { return (this->color == red); }
			bool	is_black() { return (this->color == black); }
			bool	is_left() { return (this == parent->left); }
			bool	is_right() { return (this == parent->right); }
			pointer	get_grand_pa() { return (this->parent ? this->parent->parent : NULL); }
			pointer	get_uncle() {
				pointer	grand_pa;

				grand_pa = get_grand_pa();
				if (grand_pa == NULL) return (NULL);
				if (this->parent->is_right()) return (grand_pa->left);
				return (grand_pa->right);
			}
			pointer	get_sibling(){
				if (this->is_right())
					return (parent->left);
				return (parent->right);
			}
	};
	
	template <class T>
	std::ostream	&operator<<(std::ostream &stream, Node<T> &node){
		stream << node.data;
		return (stream);
	}
	
	template <class T, class Comp = std::less<T>, class Alloc = std::allocator<T> >
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
			typedef ft::bidirection_iterator<node_type, value_type>				iterator;
			typedef ft::bidirection_iterator<node_type, const value_type>		const_iterator;
			typedef ft::reverse_iterator<iterator>								reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>						const_reverse_iterator;
			
		
		private:
			pointer			_root;
			size_type		_size;
			pointer			_nil;
			pointer			_end;
			Comp			_comp;
			allocator_node	_alloc;

			pointer	_make_node(const value_type &value){
				pointer	node;
				
				node = _alloc.allocate(1);
				_alloc.construct(node, value);
				node->right = _nil;
				node->left = _nil;
				return (node);
			}

			void	_print(pointer node, std::string s, bool last = true){
				if (!node->is_nil()){
					std::cout << s;
					if (last){
						std::cout << "R----";
						s += "    ";
					}else{
						std::cout << "L----";
						s += "|    ";
					}
					std::string color = node->is_red() ? "red" : "black";
					std::cout << node->data << "(" << color << ")" << std::endl;
					_print(node->left, s, false);
					_print(node->right, s, true);
				}
			}

			pointer	_get_parent_isertion(pointer tree, pointer node, bool &side){
				pointer parent;

				parent = tree;
				while (!tree->is_nil()){
					parent = tree;
					if (_comp(node->data, tree->data)){
						tree = tree->left;
						side = LEFT;
					} else if (_comp(tree->data, node->data)){
						tree = tree->right;
						side = RIGHT;
					} else
						return (NULL);
				}
				return (parent);
			}
			
			pointer	_left_side_fix(pointer node, pointer parent, pointer grand_pa, pointer uncle){
				if (uncle->is_red()){
					uncle->color = black;
					parent->color = black;
					grand_pa->color = red;
					node = grand_pa;
				}else if (node->is_right()){
					node = node->parent;
					_left_rotation(node);
				}else {
					parent->color = black;
					grand_pa->color = red;
					_right_rotation(grand_pa);
				}
				return (node);
			}

			pointer _right_side_fix(pointer node, pointer parent, pointer grand_pa, pointer uncle){
				if (grand_pa->left->is_red()){
					parent->color = black;
					uncle->color = black;
					grand_pa->color = red;
					node = grand_pa;
				}else{
					if (node->is_left()){
						node = parent;
						_right_rotation(node);
					}
					grand_pa = node->get_grand_pa();
					node->parent->color = black;
					grand_pa->color = red;
					_left_rotation(grand_pa);
				}
				return (node);
			}
			
			void	_maintain_after_insertion(pointer node){
				pointer	parent, grand_pa, uncle;
				
				while (node->parent && node->parent->is_red()){
					parent = node->parent;
					grand_pa = node->get_grand_pa();
					uncle = node->get_uncle();
					if (parent->is_left()){
						node = _left_side_fix(node, parent, grand_pa, uncle);
					}else {
						node = _right_side_fix(node, parent, grand_pa, uncle);
					}
				}
			}
			
			void	_left_rotation(pointer tree){
				pointer child, parent;

				parent = tree->parent;
				child = tree->right;
				if (!child->left->is_nil()){
					tree->right = child->left;
					child->left->parent = tree;
				}
				else
					tree->right = _nil;
				if (parent != NULL){
					if (tree->is_right())
						parent->right = child;
					else
						parent->left = child;
				}
				else
					_root = child;
				child->left = tree;
				tree->parent = child;
				child->parent = parent;
			}
				
			void	_right_rotation(pointer tree){
				pointer	child, parent;

				parent = tree->parent;
				child = tree->left;
				if (!child->right->is_nil()){
					tree->left = child->right;
					child->right->parent = tree;
				}
				else
					tree->left = _nil;
				if (parent != NULL){
					if (tree->is_right())
						parent->right = child;
					else
						parent->left = child;
				}else
					_root = child;
				child->right = tree;
				tree->parent = child;
				child->parent = parent;
			}
			
			void	_transplant(pointer tree, pointer node){
				pointer parent = tree->parent;
				
				if (parent == NULL)
					_root = node;
				else if (tree->is_right())
					parent->right = node;
				else
					parent->left = node;
				node->parent = parent;
			}

			void	__transplant_v2(pointer tree, pointer node, pointer min, pointer node_d, bool side){
				_transplant(tree, node);
				if (side == LEFT){
					min->left = node_d->left;
					min->left->parent = min;
				}
				else{
					min->right = node_d->right;
					min->right->parent = min;
				}
			}
			
			void	_maintain_after_deletion(pointer node){
				pointer sib;
				
				while (node != _root && node->is_black()){
					if (node->is_left()){
						sib = node->parent->right;
						if (sib->is_red()){
							sib->color = black;
							node->parent->color = red;
							_left_rotation(node->parent);
							sib = node->parent->right;
						}
						if (sib->right->is_black() && sib->left->is_black()){
							sib->color = red;
							node = node->parent;
						}else {
							if (sib->right->is_black()){
								sib->left->color = black;
								sib->color = red;
								_right_rotation(sib);
								sib = node->parent->right;
							}
							sib->color = node->parent->color;
							node->parent->color = black;
							sib->right->color = black;
							_left_rotation(node->parent);
							node = _root;
						}
					}
					else{
						sib = node->parent->left;
						if (sib->is_red()){
							sib->color = black;
							node->parent->color = red;
							_right_rotation(node->parent);
							sib = node->parent->left;
						}
						if (sib->right->is_black() && sib->left->is_black()){
							sib->color = red;
							node = node->parent;
						}else {
							if (sib->left->is_black()){
								sib->right->color = black;
								sib->color = red;
								_left_rotation(sib);
								sib = node->parent->left;
							}
							sib->color = node->parent->color;
							node->parent->color = black;
							sib->left->color = black;
							_right_rotation(node->parent);
							node = _root;
						}
					}
				}
				node->color = black;
			}

			void	_set_end(){
				if (_root == _nil)
					return ;
				
				_root->parent = _end;
				_end->left = _root;
			}
			
			void	_unset_end(){
				if (_root == _nil)
					return ;
				
				_root->parent = NULL;
				_end->left = NULL;
			}

		public:
			RedBlackTree(const Comp &comp): _size(0), _comp(comp){
				_nil = _alloc.allocate(1);
				_alloc.construct(_nil, value_type());
				_end = _alloc.allocate(1);
				_alloc.construct(_end, value_type());
				_nil->color = black;
				_root = _nil;
			}
			
			~RedBlackTree(){
				clear();
				_alloc.destroy(_nil);
				_alloc.destroy(_end);
				_alloc.deallocate(_nil, 1);
				_alloc.deallocate(_end, 1);
			}
			
			bool	empty() const {
				return (_size == 0);
			}

			pointer	search(const value_type &value) const{
				pointer	tree;

				tree = _root;
				while (!tree->is_nil())
				{
					if (_comp(tree->data, value))
						tree = tree->right;
					else if (_comp(value, tree->data))
						tree = tree->left;
					else
						return (tree);
				}
				return (tree);
			}
			
			iterator	begin(){
				iterator iter(_size ? node_type::minimum(_root) : _end);
				return (iter);
			}
			
			const_iterator	begin() const{
				const_iterator iter(_size ? node_type::minimum(_root) : _end);
				return (iter);
			}
			
			iterator	end(){
				iterator	iter(_end);
				return (iter);
			}
			
			const_iterator	end() const{
				const_iterator	iter(_end);
				return (iter);
			}

			ft::pair<iterator, bool>	insert(const value_type &value){
				pointer						node, parent;
				ft::pair<iterator, bool> 	return_value;
				bool						side;
				
				_unset_end();
				node = _make_node(value);
				return_value.first = node;
				if (_root == _nil){
					_root = node;
					return_value.second = true;
				}
				else {
					parent = _get_parent_isertion(_root, node, side);
					return_value.second = (parent != NULL);
					if (parent == NULL)
						return (_set_end(), return_value);
					node->parent = parent;
					if (side == RIGHT)
						parent->right = node;
					else
						parent->left = node;
					_maintain_after_insertion(node);
				}
				_size++;
				_root->color = black;
				_set_end();
				return (return_value);
			}
			
			void	print(){
				_print(_root, std::string());
			}

			size_type	delete_node(const value_type &value){
				pointer node, child, min;
				bool	color;

				_unset_end();
				node = search(value);
				if (node->is_nil()) return (_set_end(), 0);
				color = node->color;
				if (node->left->is_nil() || node->right->is_nil()){
					if (node->left->is_nil()) child = node->right;
					else child = node->left;
					_transplant(node, child);
				} else {
					min = node_type::minimum(node->right);
					color = min->color;
					child = min->right;
					if (min->parent == node) min->right->parent = min;
					else __transplant_v2(min, min->right, min, node, RIGHT);
					__transplant_v2(node, min, min, node, LEFT);
					min->color = node->color;
				}
				_size--;
				_alloc.destroy(node);
				_alloc.deallocate(node, 1);
				if (color == black)
					_maintain_after_deletion(child);
				_set_end();
				return (1);
			}
			
			size_type	size() const {
				return (_size);
			}

			size_type	max_size() const {
				return (_alloc.max_size());
			}
			
			void	clear(){
				while (_root && !_root->is_nil())
					delete_node(_root->data);
			}
			
			RedBlackTree	&operator=(const RedBlackTree &tree){
				const_iterator iter, end;
				
				if (this == &tree)
					return (*this);
				clear();
				iter = tree.begin();
				end = tree.end();
				for (; iter != end; iter++)
					insert(*iter);
				return (*this);
			}

			pointer	find(const value_type &value) const{
				pointer	node;
				
				node = search(value);
				if (node->is_nil())
					return (_end);
				return (node);
			}
	};
}

#endif