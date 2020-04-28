/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hexa <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 16:59:09 by hexa              #+#    #+#             */
/*   Updated: 2020/04/28 17:48:52 by hexa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

const int	PresidentialPardonForm::m_sign = 25;
const int	PresidentialPardonForm::m_exec = 5;

PresidentialPardonForm::PresidentialPardonForm(void) :
Form("Anonymous", "Presidential",
	PresidentialPardonForm::m_sign, PresidentialPardonForm::m_exec) {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
Form(target, "Presidential",
	PresidentialPardonForm::m_sign, PresidentialPardonForm::m_exec) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src) :
Form("Anonymous", "Presidential",
	PresidentialPardonForm::m_sign, PresidentialPardonForm::m_exec)
{
	*this = src;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

PresidentialPardonForm&
PresidentialPardonForm::operator=	(const PresidentialPardonForm& rhs)
{
    static_cast <void> (rhs);
    return (*this);
}

void
PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	Form::execute(executor);
	std::cout << this->getTarget() << " has been pardoned by Zaphood Beeblebrox" << std::endl;
}
