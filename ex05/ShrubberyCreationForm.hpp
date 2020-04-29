/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hexa <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 16:41:33 by hexa              #+#    #+#             */
/*   Updated: 2020/04/28 16:58:55 by hexa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "Form.hpp"

class ShrubberyCreationForm : public Form
{
	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string);
		ShrubberyCreationForm(const ShrubberyCreationForm&);

		~ShrubberyCreationForm(void);

		ShrubberyCreationForm& operator=	(const ShrubberyCreationForm&);

		virtual void            execute(const Bureaucrat&) const;

	private:
		static const int        m_sign;
		static const int        m_exec;
};

#endif
