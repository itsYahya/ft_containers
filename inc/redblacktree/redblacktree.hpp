/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redblacktree.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 19:43:52 by yel-mrab          #+#    #+#             */
/*   Updated: 2023/01/02 01:01:03 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDBLACKTREE_HPP
#define REDBLACKTREE_HPP

#define red 1
#define black 0

#define	LEFT 1
#define RIGHT 0

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
				return (this != nullptr && this->right == nullptr && this->left == nullptr);
			}
			bool	is_red() { return (this != nullptr && this->color == red); }
			bool	is_black() { return (this != nullptr && this->color == black); }
			bool	is_left() { return (this != nullptr && this == parent->left); }
			bool	is_right() { return (this != nullptr && this == parent->right); }
			pointer	get_grand_pa() { return (this->parent ? this->parent->parent : nullptr); }
			pointer	get_uncle() {
				pointer	grand_pa;

				grand_pa = get_grand_pa();
				if (grand_pa->right == this)
					return (grand_pa->left);
				return (grand_pa->right);
			}
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
					}
					else{
						tree = tree->right;
						side = RIGHT;
					}
				}
				return (parent);
			}
			
			void	_maintain_after_insertion(pointer node){
				pointer	parent, grand_pa, uncle;

				while (node->parent->is_red()){
					parent = node->parent;
					grand_pa = node->get_grand_pa();
					if (parent->is_left()){
						uncle = node->get_uncle();
						if (uncle->is_red()){
							uncle->color = black;
							parent->color = black;
							grand_pa->color = red;
						}
						node = grand_pa;
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
				if (parent != nullptr){
					if (tree->is_right())
						parent->right = child;
					else
						parent->left = child;
				}
				else
					_root = child;
				child->left = tree;
				tree->parent = child;
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
			
			void	set_end(){
				if (_root == _nil)
					return ;
				
				_root->parent = _end;
				_end->left = _root;
			}
			
			void	unset_end(){
				if (_root == _nil)
					return ;
				
				_root->parent = nullptr;
				_end->left = nullptr;
			}

			bool	empty() const {
				return (_size == 0);
			}

			bool	empty(){
				return (_size == 0);
			}
			
			void	insert(const value_type &value){
				pointer	node, parent;
				bool	side;
				
				node = _make_node(value);
				if (_root == _nil){
					_root = node;
				}
				else {
					parent = _get_parent_isertion(_root, node, side);
					node->parent = parent;
					if (side == RIGHT)
						parent->right = node;
					else
						parent->left = node;
					if (parent->is_red()){
						_maintain_after_insertion(node);
					}
				}
				_size++;
				_root->color = black;
			}
			
			void	print(){
				_print(_root, std::string());
			}

			void	rotation(){
				_left_rotation(_root->left);
			}
	};
}

#endif