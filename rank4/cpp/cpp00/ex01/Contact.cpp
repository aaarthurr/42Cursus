/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 22:43:31 by arthur            #+#    #+#             */
/*   Updated: 2024/06/13 14:14:50 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"


Contact::Contact(/* args */)
{
}

Contact::~Contact()
{
}

std::string Contact::_getInput(std::string str) const {
    std::string input = "";
    bool        valid = false;
    do
    {
        std::cout << str << std::flush;
        std::getline(std::cin, input);
        if (std::cin.good() && !input.empty())
            valid = true;
        else {
            std::cin.clear();
            std::cout << "Invalid input; please try again." << std::endl;
        }
    } while (!valid);
    return (input);
}

void    Contact::init(void) {
    std::cin.ignore();
    this->_firstName = this->_getInput("Please enter you first name:      ");
    this->_lastName = this->_getInput("Please enter your last name:      ");
    this->_nickname = this->_getInput("Please enter your nickname:       ");
    this->_phoneNumber = this->_getInput("Please enter your phone number:   ");
    this->_darkestSecret = this->_getInput("Please enter your darkest secret: ");
    std::cout << std::endl;
}


std::string Contact::_printLen(std::string str) const {
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

void    Contact::setIndex(int i) {
    this->_index = i;
}

void    Contact::view(int index) const {
    if (this->_firstName.empty() || this->_lastName.empty() || this->_nickname.empty())
        return ;
    std::cout << "|" << std::setw(10) << index << std::flush;
    std::cout << "|" << std::setw(10) << this->_printLen(this->_firstName) << std::flush;
    std::cout << "|" << std::setw(10) << this->_printLen(this->_lastName) << std::flush;
    std::cout << "|" << std::setw(10) << this->_printLen(this->_nickname) << std::flush;
    std::cout << "|" << std::endl;
}

void    Contact::display(int index) const {
    if (this->_firstName.empty() || this->_lastName.empty() || this->_nickname.empty() || this->_phoneNumber.empty())
        return ;
    std::cout << std::endl;
    std::cout << "---->> CONTACT #" << index << " <<----" << std::endl;
    std::cout << "First Name:\t" << this->_firstName << std::endl;
    std::cout << "Last Name: \t" << this->_lastName << std::endl;
    std::cout << "Nickname:  \t" << this->_nickname << std::endl;
    std::cout << "Number:    \t" << this->_phoneNumber << std::endl;
    std::cout << "Darkest secret:\t" << this->_darkestSecret << std::endl;
    std::cout << std::endl;
}
