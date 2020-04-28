/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hexa <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 03:49:46 by hexa              #+#    #+#             */
/*   Updated: 2020/04/28 05:17:51 by hexa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

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
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

static void
checkForm1(std::string name, int toSign)
{
	try
	{
		Form	horror(name, toSign, 100);
		std::cout << horror;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

static void
checkForm2(Bureaucrat bur, Form form)
{
	try
	{
		form.beSigned(bur);
		std::cout << form;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
}

static void
checkBureaucrat2(Bureaucrat bur, Form form)
{
	try
	{
		bur.signForm(form);
		std::cout << form;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
}

int
main(void)
{
	std::cout << "------------------------ checkBureaucrat" << std::endl;
	checkBureaucrat(50);
	checkBureaucrat(-1);
	checkBureaucrat(151);
	checkBureaucrat(1);
	checkBureaucrat(150);

	std::cout << "------------------------ checkForm1" << std::endl;
	checkForm1("47.3", 50);
	checkForm1("47.3", 125);
	checkForm1("47.3", -1);
	checkForm1("47.3", 151);

	std::cout << "------------------------ checkForm2" << std::endl;
	Bureaucrat	bur(75);
	Form		form1("47.3", 100, 100);
	Form		form2("47.3", 50, 100);

	checkForm2(bur, form1);
	checkForm2(bur, form2);

	std::cout << "------------------------ checkBureaucrat2" << std::endl;
	Form		form3("47.3", 100, 100);
	Form		form4("47.3", 50, 100);

	checkBureaucrat2(bur, form3);
	checkBureaucrat2(bur, form4);

	return (0);
}
