/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OfficeBlock.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hexa <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 23:32:25 by hexa              #+#    #+#             */
/*   Updated: 2020/04/29 00:52:44 by hexa             ###   ########.fr       */
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

	public:
		OfficeBlock(void);
		OfficeBlock(Intern&, Bureaucrat&, Bureaucrat&);
		~OfficeBlock(void);

		void	setIntern(Intern&);
		void	setSigner(Bureaucrat&);
		void	setExecutor(Bureaucrat&);

		void	doBureaucracy(std::string, std::string);

		class MissingMemberException : public std::exception
		{
		   public:
				MissingMemberException(void);
				MissingMemberException(int);
				MissingMemberException(const MissingMemberException&);

				virtual ~MissingMemberException(void) throw();

				MissingMemberException& operator=	(const MissingMemberException&);

				virtual const char*		what() const throw();

			private:
				int					m_index;
				static const char*	m_messages[4];
		};
};

#endif
