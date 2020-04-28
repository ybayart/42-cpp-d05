/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hexa <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 03:49:46 by hexa              #+#    #+#             */
/*   Updated: 2020/04/28 18:46:56 by hexa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

static void
check(Bureaucrat bur, Form& form)
{
	try
	{
		std::cout << bur;
		std::cout << form;
		std::cout << "sign: ";
		form.beSigned(bur);
		std::cout << form;
		std::cout << "execute: ";
		form.execute(bur);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

static void
check2(Bureaucrat bur, Form& form)
{
	try
	{
		std::cout << bur;
		std::cout << form;
		std::cout << "execute: ";
		form.execute(bur);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

static void
check3(Bureaucrat bur, Form& form)
{
	try
	{
		std::cout << bur;
		std::cout << form;
		std::cout << "executeForm: ";
		bur.executeForm(form);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

int
main(void)
{
	ShrubberyCreationForm shrubbery("shrubbery");
	RobotomyRequestForm robotomy("robomoty");
	PresidentialPardonForm presidential("presidential");
	ShrubberyCreationForm shrubbery2("shrubbery2");
	RobotomyRequestForm robotomy2("robomoty2");
	PresidentialPardonForm presidential2("presidential2");
	Bureaucrat	bur1(150);
	Bureaucrat	bur2(140);
	Bureaucrat	bur3(50);
	Bureaucrat	bur4(15);
	Bureaucrat	bur5(1);

	std::cout << "----1" << std::endl;
	check(bur1, shrubbery);
	std::cout << "----2" << std::endl;
	check(bur2, shrubbery);
	std::cout << "----3" << std::endl;
	check(bur3, shrubbery);

	std::cout << std::endl << std::endl;

	std::cout << "----4" << std::endl;
	check(bur2, robotomy);
	std::cout << "----5" << std::endl;
	check(bur3, robotomy);
	std::cout << "----6" << std::endl;
	check(bur4, robotomy);

	std::cout << std::endl << std::endl;

	std::cout << "----7" << std::endl;
	check(bur3, presidential);
	std::cout << "----8" << std::endl;
	check(bur4, presidential);
	std::cout << "----9" << std::endl;
	check(bur5, presidential);


	std::cout << std::endl << std::endl << std::endl;


	std::cout << "~~~~1" << std::endl;
	check2(bur2, shrubbery2);
	std::cout << "~~~~2" << std::endl;
	check2(bur3, shrubbery2);

	std::cout << std::endl << std::endl;

	std::cout << "~~~~3" << std::endl;
	check2(bur3, robotomy2);
	std::cout << "~~~~4" << std::endl;
	check2(bur4, robotomy2);

	std::cout << std::endl << std::endl;

	std::cout << "~~~~5" << std::endl;
	check2(bur4, presidential2);
	std::cout << "~~~~6" << std::endl;
	check2(bur5, presidential2);


	std::cout << std::endl << std::endl << std::endl;


	std::cout << "====1" << std::endl;
	check3(bur1, shrubbery);
	std::cout << "====2" << std::endl;
	check3(bur2, shrubbery2);
	std::cout << "====3" << std::endl;
	check3(bur3, shrubbery);

	return (0);
}
