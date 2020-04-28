/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hexa <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 04:24:35 by hexa              #+#    #+#             */
/*   Updated: 2020/04/28 05:05:03 by hexa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class	Bureaucrat;

class Form
{
	private:
		std::string	m_name;
		bool		m_signed;
		int			m_toSign;
		int			m_toExec;

	public:
		Form(void);
		Form(std::string, int, int);
		Form(const Form&);

		Form& operator=	(const Form&);

		~Form(void);

		const std::string&	getName() const;
		const bool&			getSigned() const;
		const int&			getToSign() const;
		const int&			getToExec() const;
		void				beSigned(Bureaucrat&);

		class GradeTooLowException : public std::exception
		{
		   public:
				GradeTooLowException(void);
				GradeTooLowException(const GradeTooLowException&);

				virtual ~GradeTooLowException(void) throw();

				GradeTooLowException& operator=	(const GradeTooLowException&);

				virtual const char	*what() const throw();
		};

		class GradeTooHighException : public std::exception
		{
		   public:
				GradeTooHighException(void);
				GradeTooHighException(const GradeTooHighException&);

				virtual ~GradeTooHighException(void) throw();

				GradeTooHighException& operator=	(const GradeTooHighException&);

				virtual const char	*what() const throw();
		};
};

std::ostream&
operator<< (std::ostream&, const Form&);

#endif
