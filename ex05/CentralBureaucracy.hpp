/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CentralBureaucracy.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hexa <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 01:35:26 by hexa              #+#    #+#             */
/*   Updated: 2020/05/06 03:28:04 by hexa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CENTRALBUREAUCRACY_HPP
# define CENTRALBUREAUCRACY_HPP

# include <cstdlib>
# include "OfficeBlock.hpp"
# include "Bureaucrat.hpp"
# include "Intern.hpp"

class	CentralBureaucracy
{
	private:
		typedef struct	s_queue {
			std::string		target;
			struct s_queue*	next;
		}				t_queue;

		OfficeBlock		m_blocks[20];
		int				m_index;
		t_queue			*m_queue;

		void			m_destroy(void);
		void			m_try(OfficeBlock&, std::string, std::string);
	
	public:
		CentralBureaucracy(void);
		~CentralBureaucracy(void);

		void	eat(Bureaucrat&);
		void	queueUp(std::string);
		void	doBureaucracy(void);
};

#endif
