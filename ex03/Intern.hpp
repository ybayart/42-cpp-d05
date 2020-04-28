/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hexa <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 22:29:25 by hexa              #+#    #+#             */
/*   Updated: 2020/04/28 22:58:32 by hexa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "Form.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class	Intern
{
	public:
		Intern(void);
		Intern(const Intern&);
		Intern& operator=	(const Intern&);

		~Intern(void);

		Form*	makeForm(std::string, std::string);

		typedef Form* (Intern::*InternFunc)(std::string);
		static std::string	m_funcNames[3];

	private:
		InternFunc	m_rep[3];

		Form*		m_makeShrubberyCreationForm(std::string);
		Form*		m_makeRobotomyRequestForm(std::string);
		Form*		m_makePresidentialPardonForm(std::string);
};

#endif
