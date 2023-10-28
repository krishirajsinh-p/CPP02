/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 07:40:24 by kpuwar            #+#    #+#             */
/*   Updated: 2023/10/28 21:59:15 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() {
	cout << "Default constructor called" << endl;
	this->numberValue = 0;
}

Fixed::Fixed(const Fixed& rhs) {
	cout << "Copy constructor called" << endl;
	*this = rhs;
}

Fixed& Fixed::operator=(const Fixed& rhs) {
	cout << "Copy assignment operator called" << endl;
	if (this != &rhs)
		this->setRawBits(rhs.getRawBits());
	return *this;
}

Fixed::~Fixed() {
	cout << "Destructor called" << endl;
}

int Fixed::getRawBits(void) const {
	cout << "getRawBits member function called" << endl;
	return this->numberValue;
}

void Fixed::setRawBits(int const raw) {
	this->numberValue = raw;
}
