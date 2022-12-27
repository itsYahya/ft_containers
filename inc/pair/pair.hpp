/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 13:43:59 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/12/27 14:09:11 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PAIR_HPP
#define PAIR_HPP

namespace ft{
	
	template <class T1, class T2>
	struct pair{
		typedef T1	first_type;
		typedef T2	second_type;
		first_type	first;
		second_type	second;
		
		pair(): first(first_type()), second(second_type()) {};
		
		template <class U, class V>
		pair(const pair<U, V> &p) : first(p.first), second(p.second) {};
		
		pair(const first_type &f, const second_type &s) : first(f), second(s) {};
	};
}

#endif