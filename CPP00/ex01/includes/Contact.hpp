/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drongier <drongier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:28:04 by drongier          #+#    #+#             */
/*   Updated: 2025/02/11 13:32:33 by drongier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP
#include <iomanip>

class Contact 
{
	
private:
	size_t 		index;
    std::string firstName;
    std::string lastName;
    std::string nickName;
    std::string phoneNumber;
    std::string darkestSecret;

public:

    void setIndex(size_t index) { this->index = index; }
    size_t getIndex() const { return index; }

    void setFirstName(const std::string &firstName) { this->firstName = firstName; }
    std::string getFirstName() const { return firstName; }

    void setLastName(const std::string &lastName) { this->lastName = lastName; }
    std::string getLastName() const { return lastName; }

	void setNickName(const std::string &nickName) { this->nickName = nickName; }
	std::string getNickName() const { return nickName; }
	
    void setPhoneNumber(const std::string &phoneNumber) { this->phoneNumber = phoneNumber; }
	std::string getPhoneNumber() const { return phoneNumber; }
	
    void setDarkestSecret(const std::string &darkestSecret) { this->darkestSecret = darkestSecret; }
	std::string getDarkestSecret() const { return darkestSecret; }

    void addContact(size_t size);
	void displayContact() const;
};

#endif