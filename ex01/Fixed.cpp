/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 07:40:24 by kpuwar            #+#    #+#             */
/*   Updated: 2023/10/30 01:40:41 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) {
	cout << "Default constructor called" << endl;
	this->numberValue = 0;
}

Fixed::Fixed(const int integerNum) {
	cout << "Int constructor called" << endl;
	this->numberValue = integerNum << this->fractionalBits;
}

Fixed::Fixed(const float floatNumber) {
	cout << "Float constructor called" << endl;
	this->numberValue = std::roundf(floatNumber * (1 << this->fractionalBits));
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

Fixed::~Fixed(void) {
	cout << "Destructor called" << endl;
}

int Fixed::getRawBits(void) const {
	return this->numberValue;
}

void Fixed::setRawBits(const int raw) {
	this->numberValue = raw;
}

float Fixed::toFloat(void) const {
	return ((float) (this->numberValue)) / (1 << fractionalBits);
}

int Fixed::toInt(void) const {
	return (this->numberValue >> fractionalBits);
}

ostream& operator<<(ostream& coutDup, Fixed const &num) {
    coutDup << num.toFloat();
    return coutDup;
}