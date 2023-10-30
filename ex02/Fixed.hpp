/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 07:40:32 by kpuwar            #+#    #+#             */
/*   Updated: 2023/10/30 00:52:40 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

using std::cout;
using std::endl;
using std::ostream;

class Fixed
{
	private:
		int numberValue;
		static const int fractionalBits = 8;

	public:
		Fixed();
		~Fixed();

		Fixed(const Fixed& rhs);
		Fixed(const int integerNum);
		Fixed(const float floatNum);

		Fixed& operator=(const Fixed& rhs);

		int getRawBits(void) const;
		void setRawBits(const int raw);

		float toFloat(void) const;
		int toInt(void) const;

		bool operator>(const Fixed& rhs) const;
		bool operator<(const Fixed& rhs) const;
		bool operator>=(const Fixed& rhs) const;
		bool operator<=(const Fixed& rhs) const;
		bool operator==(const Fixed& rhs) const;
		bool operator!=(const Fixed& rhs) const;

		Fixed operator+(const Fixed& rhs) const;
		Fixed operator-(const Fixed& rhs) const;
		Fixed operator*(const Fixed& rhs) const;
		Fixed operator/(const Fixed& rhs) const;

		Fixed& operator++(void);
		Fixed operator++(int);
		Fixed& operator--(void);
		Fixed operator--(int);

		static Fixed& min(Fixed &x, Fixed &y);
		static const Fixed& min(const Fixed &x, const Fixed &y);
		static Fixed& max(Fixed &x, Fixed &y);
		static const Fixed& max(const Fixed &x, const Fixed &y);
};

ostream& operator<<(ostream& coutDup, Fixed const &num);

#endif
