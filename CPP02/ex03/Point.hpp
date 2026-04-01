/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 13:16:07 by ofeverei          #+#    #+#             */
/*   Updated: 2026/03/04 16:08:49 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	private:
		Fixed const x;
		Fixed const y;

	public:
		Point();
		Point(const float& x, const float& y);
		Point(const int& x, const int& y);
		Point(const Point& other);
		~Point();
		Point& operator=(const Point& other);
		Fixed getX() const;
		Fixed getY() const;
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif
