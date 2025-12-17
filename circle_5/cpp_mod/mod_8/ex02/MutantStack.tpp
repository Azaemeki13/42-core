/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauffret <cauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 13:04:28 by cauffret          #+#    #+#             */
/*   Updated: 2025/12/17 13:14:08 by cauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
    return(this->c.begin());
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
    return(this->c.end());
}