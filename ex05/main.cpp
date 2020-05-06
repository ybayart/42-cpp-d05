/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hexa <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 03:49:46 by hexa              #+#    #+#             */
/*   Updated: 2020/05/06 03:33:33 by hexa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include "OfficeBlock.hpp"
#include "CentralBureaucracy.hpp"

std::string
random_string(size_t length)
{
	std::string		str(length, 0);
	std::string		randchar = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	for (size_t i = 0;i < length;i++)
		str[i] = randchar[rand() % 62];
	return str;
}

int
main(void)
{
	CentralBureaucracy	elysee;
	Bureaucrat			tmp;

	for (int i = 0;i < 60;i++)
	{
		tmp = Bureaucrat(rand() % 150 + 1);
		elysee.eat(tmp);
	}

	for (int i = 0;i < 1000;i++)
		elysee.queueUp(random_string(rand() % 20 + 10));

	elysee.doBureaucracy();
	return (0);
}
