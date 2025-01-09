/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drongier <drongier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:28:04 by drongier          #+#    #+#             */
/*   Updated: 2025/01/09 16:35:15 by drongier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

class Contact
{
private:
	size_t		_index;
	std::string _first_name;
	std::string _last_name;
	std::string _nickname
	std::string _phone_number;
	std::string _darkest_secret;

public:
	void	addContact(size_t index);
	voit 	setIndex(size_t index);
};

#endif