/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OfficeBlock.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hexa <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 23:42:30 by hexa              #+#    #+#             */
/*   Updated: 2020/05/09 01:27:52 by hexa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OfficeBlock.hpp"

OfficeBlock::OfficeBlock(void)
{
	this->m_intern = NULL;
	this->m_signer = NULL;
	this->m_executor = NULL;
}

OfficeBlock::OfficeBlock(Intern& intern, Bureaucrat& signer, Bureaucrat& executor)
{
	this->m_intern = &intern;
	this->m_signer = &signer;
	this->m_executor = &executor;
}

OfficeBlock::~OfficeBlock(void) {}

void
OfficeBlock::setIntern(Intern& intern)
{
	this->m_intern = &intern;
}

void
OfficeBlock::setSigner(Bureaucrat& signer)
{
	this->m_signer = &signer;
}

void
OfficeBlock::setExecutor(Bureaucrat& executor)
{
	this->m_executor = &executor;
}

void
OfficeBlock::doBureaucracy(std::string name, std::string target)
{
	Form*	form;

	if (this->m_intern == NULL)
		throw OfficeBlock::MissingInternException();
	if (this->m_signer == NULL)
		throw OfficeBlock::MissingSignerException();
	if (this->m_executor == NULL)
		throw OfficeBlock::MissingExecutorException();
	if ((form = this->m_intern->makeForm(name, target)) == NULL)
		return ;
	try
	{
		std::cout << "sign: ";
		form->beSigned(*(this->m_signer));
		std::cout << *form;
		std::cout << "execute: ";
		form->execute(*(this->m_executor));
		std::cout << *form;
		delete form;
	}
	catch (std::exception& e)
	{
		delete form;
		throw;
	}
}



//========== EXCEPTION

//MissingIntern

OfficeBlock::MissingInternException::MissingInternException(void) {}

OfficeBlock::
MissingInternException::MissingInternException(const MissingInternException& src)
{
    *this = src;
}

OfficeBlock::MissingInternException::~MissingInternException(void) throw() {}

OfficeBlock::MissingInternException&
OfficeBlock::MissingInternException::operator=	(const MissingInternException& rhs)
{
    static_cast <void> (rhs);
    return (*this);
}

const char*
OfficeBlock::MissingInternException::what() const throw()
{
	return ("Member `Intern` is missing...");
}

//MissingSigner

OfficeBlock::MissingSignerException::MissingSignerException(void) {}

OfficeBlock::
MissingSignerException::MissingSignerException(const MissingSignerException& src)
{
    *this = src;
}

OfficeBlock::MissingSignerException::~MissingSignerException(void) throw() {}

OfficeBlock::MissingSignerException&
OfficeBlock::MissingSignerException::operator=	(const MissingSignerException& rhs)
{
    static_cast <void> (rhs);
    return (*this);
}

const char*
OfficeBlock::MissingSignerException::what() const throw()
{
	return ("Member `Signer` is missing...");
}

//MissingExecutor

OfficeBlock::MissingExecutorException::MissingExecutorException(void) {}

OfficeBlock::
MissingExecutorException::MissingExecutorException(const MissingExecutorException& src)
{
    *this = src;
}

OfficeBlock::MissingExecutorException::~MissingExecutorException(void) throw() {}

OfficeBlock::MissingExecutorException&
OfficeBlock::MissingExecutorException::operator=	(const MissingExecutorException& rhs)
{
    static_cast <void> (rhs);
    return (*this);
}

const char*
OfficeBlock::MissingExecutorException::what() const throw()
{
	return ("Member `Executor` is missing...");
}
