/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OfficeBlock.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hexa <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 23:42:30 by hexa              #+#    #+#             */
/*   Updated: 2020/04/29 04:17:39 by hexa             ###   ########.fr       */
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
		throw OfficeBlock::MissingMemberException(0);
	if (this->m_signer == NULL)
		throw OfficeBlock::MissingMemberException(1);
	if (this->m_executor == NULL)
		throw OfficeBlock::MissingMemberException(2);
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

const char*
OfficeBlock::MissingMemberException::m_messages[4] = {
	"Member `Intern` is missing...",
	"Member `Signer` is missing...",
	"Member `Executor` is missing...",
	"A required member is missing..."
};

//MissingMember

OfficeBlock::MissingMemberException::MissingMemberException(void)
{
	this->m_index = 3;
}

OfficeBlock::MissingMemberException::MissingMemberException(int index)
{
	if (index < 0 || index > 3)
		index = 3;
	this->m_index = index;
}

OfficeBlock::
MissingMemberException::MissingMemberException(const MissingMemberException& src)
{
    *this = src;
}

OfficeBlock::MissingMemberException::~MissingMemberException(void) throw() {}

OfficeBlock::MissingMemberException&
OfficeBlock::MissingMemberException::operator=	(const MissingMemberException& rhs)
{
    static_cast <void> (rhs);
    return (*this);
}

const char*
OfficeBlock::MissingMemberException::what() const throw()
{
	return (m_messages[this->m_index]);
}
