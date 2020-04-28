/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hexa <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 03:49:46 by hexa              #+#    #+#             */
/*   Updated: 2020/04/29 01:13:26 by hexa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include "OfficeBlock.hpp"

static void
check(OfficeBlock& nightmare, std::string name, std::string target)
{
	try
	{
		nightmare.doBureaucracy(name, target);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}


int
main(void)
{
	Intern		slave;
	Bureaucrat	pierre(150);
	Bureaucrat	paul(140);
	Bureaucrat	jacques(50);
	Bureaucrat	ben(15);
	Bureaucrat	jerry(1);
	OfficeBlock	nightmare;

	check(nightmare, "", "");
	nightmare.setIntern(slave);
	check(nightmare, "", "");

	nightmare.setSigner(pierre);
	check(nightmare, "", "");
	nightmare.setExecutor(pierre);

	std::cout << std::endl << "---1" << std::endl;
	check(nightmare, "shrubbery creation", "Groot");

	std::cout << std::endl << "---2" << std::endl;
	nightmare.setSigner(paul);
	check(nightmare, "shrubbery creation", "Groot");

	std::cout << std::endl << "---3" << std::endl;
	nightmare.setSigner(ben);
	nightmare.setExecutor(jerry);
	check(nightmare, "shrubbery creation", "Groot");

	std::cout << std::endl << "---4" << std::endl;
	check(nightmare, "robotomy request", "Marvin");

	std::cout << std::endl << "---5" << std::endl;
	check(nightmare, "presidential pardon", "Snowden");

	std::cout << std::endl << "---6" << std::endl;
	check(nightmare, "idon'texists", "other");


	return (0);
}
