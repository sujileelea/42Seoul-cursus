/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:11:55 by sujilee           #+#    #+#             */
/*   Updated: 2022/04/19 16:59:44 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream> // stream class header

void	replaceString(std::string &line, std::string s1, std::string s2)
{//line에서 s1을 s2로 바꿔준다.
	int	idx;

	while ((idx = line.find(s1)) != std::string::npos) // line에서 s1문자열을 찾아서 인덱스를 반환한다.
	{
		line.erase(idx, s1.length()); // 해당 인덱스부터 s1길이만큼 지워준다.
		line.insert(idx, s2); // 해당 인덱스부터 s2를 삽입한다.
	}
	line += "\n";
}

int	main(int argc, char** argv)
{
	if (argc != 4 || argv[2][0] == 0)
		std::cout << "input error!" << std::endl;
	else
	{
		std::string		orgName = argv[1];
		std::ifstream	orgFile(orgName); // data는 문자열을 배열로 만들어서 그 주소를 반환
		if (orgFile.is_open())
		{
			std::string		newName = orgName + ".replace";
			std::ofstream	newFile(newName); // 출력할 파일을 생성한다.
			if (newFile.is_open())
			{
				std::string	line;
				while (std::getline(orgFile, line)) // 입력 스트림을 받아 한줄씩 가져온다.
				{
					replaceString(line, argv[2], argv[3]);
					newFile << line;
				}
				newFile.close();
			}
			else
				std::cout << "open error!" << std::endl;
			orgFile.close();
		}
		else
			std::cout << "open error!" << std::endl;
	}
	return (0);
}