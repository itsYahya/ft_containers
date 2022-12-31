/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redblacktree.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 19:43:52 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/12/31 18:56:51 by yel-mrab         ###   ########.fr       */
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
	};
}

#endif