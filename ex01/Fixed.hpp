/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 07:40:32 by kpuwar            #+#    #+#             */
/*   Updated: 2023/10/30 01:40:49 by kpuwar           ###   ########.fr       */
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
		Fixed(void);
		~Fixed(void);

		Fixed(const Fixed& rhs);
		Fixed(const int integerNum);
		Fixed(const float floatNum);

		Fixed& operator=(const Fixed& rhs);

		int getRawBits(void) const;
		void setRawBits(const int raw);

		float toFloat(void) const;
		int toInt(void) const;
};

ostream& operator<<(ostream& coutDup, Fixed const &num);

#endif
