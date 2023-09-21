all: 
	+$(MAKE) -C Memory_management_and_Pointer main
	+$(MAKE) -C Data_Structure_and_Algorithms/Data_structures_v2 main
	+$(MAKE) -C Data_Structure_and_Algorithms/Data_structures main
	+$(MAKE) -C Data_Structure_and_Algorithms/Searching_and_sorting_algorithms main
	+$(MAKE) -C File_handling/File_manipulation_and_encryption main	
	+$(MAKE) -C File_handling/File_size_calculator main	
	+$(MAKE) -C Static_Link_and_Dynamic_Link_Libraries/Shared_libraries main	
	+$(MAKE) -C Static_Link_and_Dynamic_Link_Libraries/Static_libraries main	
	+$(MAKE) -C MINI_PROJECT_Cryptography main	

clean:
	+$(MAKE) -C Memory_management_and_Pointer clean
	+$(MAKE) -C Data_Structure_and_Algorithms/Data_structures_v2 clean
	+$(MAKE) -C Data_Structure_and_Algorithms/Data_structures clean
	+$(MAKE) -C Data_Structure_and_Algorithms/Searching_and_sorting_algorithms clean
	+$(MAKE) -C File_handling/File_manipulation_and_encryption clean	
	+$(MAKE) -C File_handling/File_size_calculator clean	
	+$(MAKE) -C Static_Link_and_Dynamic_Link_Libraries/Shared_libraries clean	
	+$(MAKE) -C Static_Link_and_Dynamic_Link_Libraries/Static_libraries clean	
	+$(MAKE) -C MINI_PROJECT_Cryptography clean	