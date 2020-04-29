/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hexa <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 16:59:09 by hexa              #+#    #+#             */
/*   Updated: 2020/04/28 17:51:07 by hexa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

const int	RobotomyRequestForm::m_sign = 72;
const int	RobotomyRequestForm::m_exec = 45;

RobotomyRequestForm::RobotomyRequestForm(void) :
Form("Anonymous", "Robotomy",
	RobotomyRequestForm::m_sign, RobotomyRequestForm::m_exec) {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
Form(target, "Robotomy",
	RobotomyRequestForm::m_sign, RobotomyRequestForm::m_exec) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src) :
Form("Anonymous", "Robotomy",
	RobotomyRequestForm::m_sign, RobotomyRequestForm::m_exec)
{
	*this = src;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

RobotomyRequestForm&
RobotomyRequestForm::operator=	(const RobotomyRequestForm& rhs)
{
    static_cast <void> (rhs);
    return (*this);
}

void
RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	Form::execute(executor);
	if (rand() & 1)
	{
		std::cout << "BZZZZZZZZZ..." << std::endl;
		std::cout << this->getTarget() << " has been robotomized!" << std::endl;
	}
	else
	{
		std::cout << "The " << this->getTarget() << " robotomization failed!" << std::endl;
	}
}
