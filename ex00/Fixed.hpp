/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 07:40:32 by kpuwar            #+#    #+#             */
/*   Updated: 2023/10/30 01:40:30 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

using std::cout;
using std::endl;

class Fixed
{
	private:
		int numberValue;
		static const int fractionalBits = 8;

	public:
		Fixed(void);
		~Fixed(void);

		Fixed(const Fixed& rhs);
		Fixed& operator=(const Fixed& rhs);

		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif
