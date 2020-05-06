/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hexa <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 16:59:09 by hexa              #+#    #+#             */
/*   Updated: 2020/05/06 03:25:03 by hexa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include "ShrubberyCreationForm.hpp"

const int	ShrubberyCreationForm::m_sign = 145;
const int	ShrubberyCreationForm::m_exec = 137;

ShrubberyCreationForm::ShrubberyCreationForm(void) :
Form("Anonymous", "Shrubbery",
	ShrubberyCreationForm::m_sign, ShrubberyCreationForm::m_exec) {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
Form(target, "Shrubbery",
	ShrubberyCreationForm::m_sign, ShrubberyCreationForm::m_exec) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src) :
Form("Anonymous", "Shrubbery",
	ShrubberyCreationForm::m_sign, ShrubberyCreationForm::m_exec)
{
	*this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

ShrubberyCreationForm&
ShrubberyCreationForm::operator=	(const ShrubberyCreationForm& rhs)
{
    static_cast <void> (rhs);
    return (*this);
}

void
ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	std::ofstream  file;

	Form::execute(executor);
	file.open((getTarget() + "_shrubbery").c_str(), std::ofstream::out | std::ofstream::trunc);
	if (file.fail())
		std::cerr << "Error openning the outfile" << std::endl;
	file << "          1            " << std::endl;
	file << "         / \\          " << std::endl;
	file << "        /   \\         " << std::endl;
	file << "       /     \\        " << std::endl;
	file << "      2       3        " << std::endl;
	file << "     / \\     / \\     " << std::endl;
	file << "    4   5   6   7      " << std::endl;
	file << "   /   / \\     / \\   " << std::endl;
	file << "  8   9   1   2   3    " << std::endl;
	file << "     /                 " << std::endl;
	file << "    4                  " << std::endl;
	file.close();
	std::cout << "file `" << getTarget() + "_shrubbery` created" << std::endl;
}
