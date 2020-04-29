/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hexa <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 03:30:54 by hexa              #+#    #+#             */
/*   Updated: 2020/04/28 18:00:33 by hexa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <stdexcept>
# include "Form.hpp"

class	Form;

class	Bureaucrat
{
	private:
		std::string	m_name;
		int			m_grade;

	public:
		Bureaucrat(void);
		Bureaucrat(int);
		Bureaucrat(const Bureaucrat&);

		Bureaucrat& operator=	(const Bureaucrat&);

		~Bureaucrat(void);

		const std::string&	getName() const;
		const int&			getGrade() const;
		void				incGrade();
		void				decGrade();
		void				signForm(Form&);
		void				executeForm(const Form&);

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
operator<< (std::ostream&, const Bureaucrat&);

#endif
