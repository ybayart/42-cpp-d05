/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CentralBureaucracy.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hexa <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 01:43:11 by hexa              #+#    #+#             */
/*   Updated: 2020/04/29 03:43:07 by hexa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CentralBureaucracy.hpp"

CentralBureaucracy::CentralBureaucracy(void)
{
	for (int i = 0;i < 20;i++)
		m_blocks[i] = OfficeBlock();
	m_queue = NULL;
	m_index = 0;
}

CentralBureaucracy::~CentralBureaucracy(void)
{
	this->m_destroy();
}

void
CentralBureaucracy::m_destroy(void)
{
    t_queue		*tmp;

    if (this->m_queue != NULL)
    {
        tmp = this->m_queue;
        this->m_queue = this->m_queue->next;
        delete tmp;
        return (this->m_destroy());
    }
}

void
CentralBureaucracy::eat(Bureaucrat& bur)
{
	int		index;

	index = this->m_index;
	if (index < 40)
	{
		if (index % 2 == 0)
			this->m_blocks[index / 2].setSigner(bur);
		else
			this->m_blocks[index / 2].setExecutor(bur);
		std::cout << "Eating " << bur.getName() << " (" << bur.getGrade() << ") "\
				<< "in office #" << index / 2 << " "\
				<< "as `" << (index % 2 == 0 ? "Signer" : "Executor") << "`"\
				<< std::endl;
		this->m_index++;
	}
	else
		std::cerr << "Rejected " << bur.getName()\
				<< " (" << bur.getGrade() << ")" << std::endl;
}

void
CentralBureaucracy::queueUp(std::string target)
{
    t_queue  *tmp;

	tmp = this->m_queue;
	if (this->m_queue != NULL)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new t_queue;
		tmp->next->target = target;
		tmp->next->next = NULL;
	}
	else
	{
		this->m_queue = new t_queue;
		this->m_queue->target = target;
		this->m_queue->next = NULL;
	}
	std::cout << "Push '" << target << "'" << std::endl;
}

void
CentralBureaucracy::doBureaucracy(void)
{
	t_queue*	tmp;
	std::string	name[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	Intern		slave;
	int			index;

	while (this->m_queue != NULL)
	{
		index = rand() % 20;
		this->m_blocks[index].setIntern(slave);
		m_try(this->m_blocks[index], name[rand() % 3], this->m_queue->target);
		tmp = this->m_queue;
		this->m_queue = this->m_queue->next;
		delete tmp;
		std::cout << std::endl;
	}
}

void
CentralBureaucracy::m_try(OfficeBlock& off, std::string name, std::string target)
{
	try
	{
		off.doBureaucracy(name, target);
	}
	catch (std::exception& e)
	{
		std::cerr << "ERROR: " << e.what() << std::endl;
	}
}
