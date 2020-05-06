/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hexa <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 16:41:33 by hexa              #+#    #+#             */
/*   Updated: 2020/05/06 03:25:55 by hexa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <cstdlib>
# include "Form.hpp"

class RobotomyRequestForm : public Form
{
	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string);
		RobotomyRequestForm(const RobotomyRequestForm&);

		~RobotomyRequestForm(void);

		RobotomyRequestForm& operator=	(const RobotomyRequestForm&);

		virtual void            execute(const Bureaucrat&) const;

	private:
		static const int        m_sign;
		static const int        m_exec;
};

#endif
