/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hexa <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 22:32:35 by hexa              #+#    #+#             */
/*   Updated: 2020/04/28 23:24:09 by hexa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

std::string
Intern::m_funcNames[3] = {
	"shrubbery creation",
	"robotomy request",
	"presidential pardon"
};


Intern::Intern(void)
{
	this->m_rep[0] = &Intern::m_makeShrubberyCreationForm;
	this->m_rep[1] = &Intern::m_makeRobotomyRequestForm;
	this->m_rep[2] = &Intern::m_makePresidentialPardonForm;
}

Intern::Intern(const Intern& src)
{
	*this = src;
}

Intern&
Intern::operator=	(const Intern& rhs)
{
	static_cast <void> (rhs);
	return (*this);
}

Intern::~Intern(void) {}

Form*
Intern::makeForm(std::string name, std::string target)
{
	Form*	tmp;

	for(int i = 0;i < 3;i++)
		if (this->m_funcNames[i] == name)
		{
			tmp = (this->*(m_rep[i]))(target);
			std::cout << "Intern creates " << tmp->getName() << " (toSign: " << tmp->getToSign() << ", toExec: " << tmp->getToExec() << ") targeted on " << tmp->getTarget() << std::endl;
			return (tmp);
		}
	std::cerr << "Form `" << name << "` not found :(" << std::endl;
	return (NULL);
}

Form*
Intern::m_makeShrubberyCreationForm(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

Form*
Intern::m_makeRobotomyRequestForm(std::string target)
{
	return (new RobotomyRequestForm(target));
}

Form*
Intern::m_makePresidentialPardonForm(std::string target)
{
	return (new PresidentialPardonForm(target));
}
