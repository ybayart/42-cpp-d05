/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hexa <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 03:49:46 by hexa              #+#    #+#             */
/*   Updated: 2020/04/28 04:16:11 by hexa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

static void
checkBureaucrat(int grade)
{
	try
	{
		Bureaucrat	slave(grade);
		std::cout << slave;
		slave.incGrade();
		slave.decGrade();
		slave.decGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return ;
}

int
main(void)
{
	checkBureaucrat(50);
	checkBureaucrat(-1);
	checkBureaucrat(151);
	checkBureaucrat(1);
	checkBureaucrat(150);
	return (0);
}
