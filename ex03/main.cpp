/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hexa <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 03:49:46 by hexa              #+#    #+#             */
/*   Updated: 2020/04/28 23:25:50 by hexa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int
main(void)
{
	Intern	slave;

	std::cout << *slave.makeForm("shrubbery creation", "toto");
	std::cout << *slave.makeForm("robotomy request", "tata");
	std::cout << *slave.makeForm("presidential pardon", "titi");

	Form*	tmp = slave.makeForm("bad", "tata");
	std::cout << tmp << std::endl;

	return (0);
}
