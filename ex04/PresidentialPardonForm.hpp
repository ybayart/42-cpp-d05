/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hexa <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 16:41:33 by hexa              #+#    #+#             */
/*   Updated: 2020/04/28 17:40:42 by hexa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "Form.hpp"

class PresidentialPardonForm : public Form
{
	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(std::string);
		PresidentialPardonForm(const PresidentialPardonForm&);

		~PresidentialPardonForm(void);

		PresidentialPardonForm& operator=	(const PresidentialPardonForm&);

		virtual void            execute(const Bureaucrat&) const;

	private:
		static const int        m_sign;
		static const int        m_exec;
};

#endif
