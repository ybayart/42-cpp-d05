/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OfficeBlock.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hexa <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 23:32:25 by hexa              #+#    #+#             */
/*   Updated: 2020/05/09 01:21:50 by hexa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OFFICEBLOCK_HPP
# define OFFICEBLOCK_HPP

# include "Bureaucrat.hpp"
# include "Intern.hpp"

class	OfficeBlock
{
	private:
		Intern*		m_intern;
		Bureaucrat*	m_signer;
		Bureaucrat*	m_executor;

		OfficeBlock(const OfficeBlock&);
		OfficeBlock& operator=	(const OfficeBlock&);

	public:
		OfficeBlock(void);
		OfficeBlock(Intern&, Bureaucrat&, Bureaucrat&);
		~OfficeBlock(void);

		void	setIntern(Intern&);
		void	setSigner(Bureaucrat&);
		void	setExecutor(Bureaucrat&);

		void	doBureaucracy(std::string, std::string);


		class MissingInternException : public std::exception
		{
		   public:
				MissingInternException(void);
				MissingInternException(int);
				MissingInternException(const MissingInternException&);

				virtual ~MissingInternException(void) throw();

				MissingInternException& operator=	(const MissingInternException&);

				virtual const char*		what() const throw();
		};

		class MissingSignerException : public std::exception
		{
		   public:
				MissingSignerException(void);
				MissingSignerException(int);
				MissingSignerException(const MissingSignerException&);

				virtual ~MissingSignerException(void) throw();

				MissingSignerException& operator=	(const MissingSignerException&);

				virtual const char*		what() const throw();
		};

		class MissingExecutorException : public std::exception
		{
		   public:
				MissingExecutorException(void);
				MissingExecutorException(int);
				MissingExecutorException(const MissingExecutorException&);

				virtual ~MissingExecutorException(void) throw();

				MissingExecutorException& operator=	(const MissingExecutorException&);

				virtual const char*		what() const throw();
		};
};

#endif
