/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 07:40:32 by kpuwar            #+#    #+#             */
/*   Updated: 2023/10/28 22:49:58 by kpuwar           ###   ########.fr       */
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
		Fixed& operator=(const Fixed& rhs);
		int getRawBits(void) const;
		void setRawBits(const int raw);
		Fixed(const int integerNum);
		Fixed(const float floatNum);
		float toFloat(void) const;
		int toInt(void) const;
};

ostream& operator<<(ostream& coutDup, Fixed const &num);

#endif
