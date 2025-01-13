/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drongier <drongier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:28:04 by drongier          #+#    #+#             */
/*   Updated: 2025/01/13 17:22:02 by drongier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

class Contact {
private:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;

public:
    void setFirstName(const std::string &firstName) { this->firstName = firstName; }
    void setLastName(const std::string &lastName) { this->lastName = lastName; }
    void setNickname(const std::string &nickname) { this->nickname = nickname; }
    void setPhoneNumber(const std::string &phoneNumber) { this->phoneNumber = phoneNumber; }
    void setDarkestSecret(const std::string &darkestSecret) { this->darkestSecret = darkestSecret; }

    void addContact();
};

#endif