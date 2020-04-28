/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hexa <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 04:33:38 by hexa              #+#    #+#             */
/*   Updated: 2020/04/28 23:27:47 by hexa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void)
{
	this->m_name = "47.3";
	this->m_target = "Anonymous";
	this->m_signed = false;
	this->m_toSign = 50;
	this->m_toExec = 100;
}

Form::Form(std::string target, std::string name, int toSign, int toExec)
{
	if (toSign < 1 || toExec < 1)
		throw Form::GradeTooHighException();
	else if (toSign > 150 || toExec > 150)
		throw Form::GradeTooLowException();
	this->m_name = name;
	this->m_target = target;
	this->m_signed = false;
	this->m_toSign = toSign;
	this->m_toExec = toExec;
}

Form::Form(const Form& src)
{
    *this = src;
}

Form::~Form(void) {}

Form&
Form::operator=	(const Form& rhs)
{
	if (this != &rhs)
	{
		this->m_name = rhs.m_name;
		this->m_signed = rhs.m_signed;
		this->m_toSign = rhs.m_toSign;
		this->m_toExec = rhs.m_toExec;
	}
	return (*this);
}

std::ostream&
operator<< (std::ostream& o, const Form& rhs)
{
    o << rhs.getName() << " | signed? " << rhs.getSigned() << " | toSign: " << rhs.getToSign() << " | toExec: " << rhs.getToExec() << std::endl;
    return (o);
}


std::string
Form::getName() const
{
	return (this->m_name);
}

bool
Form::getSigned() const
{
	return (this->m_signed);
}

int
Form::getToSign() const
{
	return (this->m_toSign);
}

int
Form::getToExec() const
{
	return (this->m_toExec);
}

std::string
Form::getTarget() const
{
	return (this->m_target);
}

void
Form::beSigned(Bureaucrat& src)
{
	if (this->m_signed == false)
	{
		if (this->m_toSign < src.getGrade())
			throw Form::GradeTooLowException();
		this->m_signed = true;
	}
	
}

void
Form::execute(const Bureaucrat& executor) const
{
	if (m_signed == false) 
    {
        throw Form::NotSignedException();
    }
    else if (executor.getGrade() > m_toExec)
    {
        throw Form::GradeTooLowException();
    }
}


//========== EXCEPTION

//TooLow

Form::GradeTooLowException::GradeTooLowException(void) {}

Form::
GradeTooLowException::GradeTooLowException(const GradeTooLowException& src)
{
    *this = src;
}

Form::GradeTooLowException::~GradeTooLowException(void) throw() {}

Form::GradeTooLowException&
Form::GradeTooLowException::operator=	(const GradeTooLowException& rhs)
{
    static_cast <void> (rhs);
    return (*this);
}

const char*
Form::GradeTooLowException::what() const throw()
{
    return ("Grade is too low...");
}

//TooHight

Form::GradeTooHighException::GradeTooHighException(void) {}

Form::
GradeTooHighException::GradeTooHighException(const GradeTooHighException& src)
{
    *this = src;
}

Form::GradeTooHighException::~GradeTooHighException(void) throw() {}

Form::GradeTooHighException&
Form::GradeTooHighException::operator=	(const GradeTooHighException& rhs)
{
    static_cast <void> (rhs);
    return (*this);
}

const char*
Form::GradeTooHighException::what() const throw()
{
    return ("Grade is too high...");
}

//NotSigned

Form::NotSignedException::NotSignedException(void) {}

Form::
NotSignedException::NotSignedException(const NotSignedException& src)
{
    *this = src;
}

Form::NotSignedException::~NotSignedException(void) throw() {}

Form::NotSignedException&
Form::NotSignedException::operator=	(const NotSignedException& rhs)
{
    static_cast <void> (rhs);
    return (*this);
}

const char*
Form::NotSignedException::what() const throw()
{
    return ("Form isn't signed...");
}
