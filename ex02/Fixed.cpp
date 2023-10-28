/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 07:40:24 by kpuwar            #+#    #+#             */
/*   Updated: 2023/10/29 01:51:11 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() {
	this->numberValue = 0;
}

Fixed::Fixed(const int integerNum) {
	this->numberValue = integerNum << this->fractionalBits;
}

Fixed::Fixed(const float floatNumber) {
	this->numberValue = std::roundf(floatNumber * (1 << this->fractionalBits));
}

Fixed::Fixed(const Fixed& rhs) {
	*this = rhs;
}

Fixed& Fixed::operator=(const Fixed& rhs) {
	if (this != &rhs)
		this->setRawBits(rhs.getRawBits());
	return *this;
}

Fixed::~Fixed() {
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

bool Fixed::operator>(const Fixed& rhs) const {
	return this->getRawBits() > rhs.getRawBits();
}

bool Fixed::operator<(const Fixed& rhs) const {
	return this->getRawBits() < rhs.getRawBits();
}

bool Fixed::operator>=(const Fixed& rhs) const {
	return this->getRawBits() >= rhs.getRawBits();
}

bool Fixed::operator<=(const Fixed& rhs) const {
	return this->getRawBits() <= rhs.getRawBits();
}

bool Fixed::operator==(const Fixed& rhs) const {
	return this->getRawBits() == rhs.getRawBits();
}

bool Fixed::operator!=(const Fixed& rhs) const {
	return this->getRawBits() != rhs.getRawBits();
}

Fixed Fixed::operator+(const Fixed& rhs) const {
	return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed Fixed::operator-(const Fixed& rhs) const {
	return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed Fixed::operator*(const Fixed& rhs) const {
	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(const Fixed& rhs) const {
	return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed& Fixed::operator++(void) {
	++this->numberValue;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed copy(*this);
	copy.numberValue = this->numberValue++;
	return copy;
}

Fixed& Fixed::operator--(void) {
	--this->numberValue;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed copy(*this);
	copy.numberValue = this->numberValue--;
	return copy;
}

Fixed& Fixed::min(Fixed &x, Fixed &y) {
	return x.getRawBits() < y.getRawBits() ? x : y;
}

const Fixed& Fixed::min(const Fixed &x, const Fixed &y) {
	return x.getRawBits() < y.getRawBits() ? x : y;
}

Fixed& Fixed::max(Fixed &x, Fixed &y) {
	return x.getRawBits() > y.getRawBits() ? x : y;
}

const Fixed& Fixed::max(const Fixed &x, const Fixed &y) {
	return x.getRawBits() > y.getRawBits() ? x : y;	
}
