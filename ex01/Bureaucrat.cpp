/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hexa <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 03:35:39 by hexa              #+#    #+#             */
/*   Updated: 2020/04/28 05:03:50 by hexa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void)
{
	this->m_name = "Marvin";
	this->m_grade = 5;
}

Bureaucrat::Bureaucrat(int grade)
{
	this->m_name = "Marvin";
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->m_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& src)
{
    *this = src;
}

Bureaucrat::~Bureaucrat(void) {}

Bureaucrat&
Bureaucrat::operator=	(const Bureaucrat& rhs)
{
	if (this != &rhs)
	{
		this->m_name = rhs.m_name;
		this->m_grade = rhs.m_grade;
	}
	return (*this);
}

const std::string&
Bureaucrat::getName() const
{
	return (this->m_name);
}

const int&
Bureaucrat::getGrade() const
{
	return (this->m_grade);
}

void
Bureaucrat::incGrade()
{
	if (this->m_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->m_grade--;
}

void
Bureaucrat::decGrade()
{
	if (this->m_grade == 150)
		throw Bureaucrat::GradeTooHighException();
	else
		this->m_grade++;
}

void
Bureaucrat::signForm(Form &src)
{
	try
	{
		src.beSigned(*this);
		std::cout << this->getName() << " signs " << src.getName() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << this->getName() << " can't sign " << src.getName() << " because " << e.what() << std::endl;
	}
}

std::ostream&
operator<< (std::ostream& o, const Bureaucrat& rhs)
{
    o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << std::endl;
    return (o);
}

Bureaucrat::GradeTooLowException::GradeTooLowException(void) {}

Bureaucrat::
GradeTooLowException::GradeTooLowException(const GradeTooLowException& src)
{
    *this = src;
}

Bureaucrat::GradeTooLowException::~GradeTooLowException(void) throw() {}

Bureaucrat::GradeTooLowException&
Bureaucrat::GradeTooLowException::operator=	(const GradeTooLowException& rhs)
{
    static_cast <void> (rhs);
    return (*this);
}

const char*
Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade is too low...");
}

Bureaucrat::GradeTooHighException::GradeTooHighException(void) {}

Bureaucrat::
GradeTooHighException::GradeTooHighException(const GradeTooHighException& src)
{
    *this = src;
}

Bureaucrat::GradeTooHighException::~GradeTooHighException(void) throw() {}

Bureaucrat::GradeTooHighException&
Bureaucrat::GradeTooHighException::operator=	(const GradeTooHighException& rhs)
{
    static_cast <void> (rhs);
    return (*this);
}

const char*
Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade is too high...");
}
