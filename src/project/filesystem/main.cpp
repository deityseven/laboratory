#include <iostream>
#include <filesystem>

int main(int argc, char *argv[])
{
	//目录对象，仅记载目录
	std::filesystem::path path("/");

	std::filesystem::space_info info = std::filesystem::space(path);

	//字节
	std::cout << "\tavailable(GB) : " << info.available / 1024 / 1024 / 1024;
	std::cout << "\tcapacity(GB) : " << info.capacity / 1024 / 1024/ 1024;
	std::cout << "\tfree(GB) : " << info.free / 1024 / 1024/ 1024 << std::endl;

	//目录实体，实际可操作目录的对象
	std::filesystem::directory_entry de(path);

	std::cout << "./ = " << de.path() << std::endl;
	
	//迭代子目录
	for(auto item : std::filesystem::directory_iterator(de))
	{
		std::cout << item.path();
		if(item.exists())
		{
			std::cout << "\texists";
		}
		else
		{
			std::cout << "\tunexists";
		}

		if(item.is_directory())
		{
			std::cout << "\tdirectory";
		}

		if(item.is_block_file())
		{
			std::cout << "\tblock_file";
		}

		if(item.is_character_file())
		{
			std::cout << "\tcharacter_file";
		}

		if(item.is_fifo())
		{
			std::cout << "\tfifo";
		}

		if(item.is_other())
		{
			std::cout << "\tother";
		}

		if(item.is_regular_file())
		{
			std::cout << "\tregular_file";
			std::cout << "\tfile_size:" << std::filesystem::file_size(item);
		}

		if(item.is_socket())
		{
			std::cout << "\tsocket";
		}

		if(item.is_symlink())
		{
			std::cout << "\tsymlink";
		}

		std::cout << std::endl;
	}
	
	return 0;
}