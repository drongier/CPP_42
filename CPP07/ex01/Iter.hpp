/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drongier <drongier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 16:47:53 by drongier          #+#    #+#             */
/*   Updated: 2025/10/27 16:47:54 by drongier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>

template<typename T>
void	iter(T *arr, const size_t len, void fun(T &element))
{
	for (size_t cur = 0; cur < len; cur++)
		fun(arr[cur]);
}

#endif
