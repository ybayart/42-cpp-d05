/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hexa <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 04:24:35 by hexa              #+#    #+#             */
/*   Updated: 2020/04/29 04:09:32 by hexa             ###   ########.fr       */
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
		std::string	m_target;

	public:
		Form(void);
		Form(std::string, std::string, int, int);
		Form(const Form&);

		Form& operator=	(const Form&);

		virtual ~Form(void);
	
		void			beSigned(Bureaucrat&);
		void			setTarget(std::string);

		virtual void	execute(const Bureaucrat&) const = 0;

		std::string		getName() const;
		bool			getSigned() const;
		int				getToSign() const;
		int				getToExec() const;
		std::string		getTarget() const;

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

		class NotSignedException : public std::exception
		{
		   public:
				NotSignedException(void);
				NotSignedException(const NotSignedException&);

				virtual ~NotSignedException(void) throw();

				NotSignedException& operator=	(const NotSignedException&);

				virtual const char	*what() const throw();
		};
};

std::ostream&
operator<< (std::ostream&, const Form&);

#endif
