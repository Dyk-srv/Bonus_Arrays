#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
	setlocale(LC_ALL, "Russian");
	const int size = 10;
	srand(time(NULL));
	// 1. ������� �������������� �� ��������
	std::cout << "\t\t1. ������� �������������� �� ��������\n\n";
	int A[size][size];
	
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			A[i][j] = rand() % (101);
			std::cout << A[i][j] << '\t';
		}
		std::cout << '\n';
	}
	std::cout << '\n';
	int col_sum = 0;
	for (int j = 0; j < size; j++){
		for (int i = 0; i < size; i++)
			col_sum += A[i][j];
		std::cout << "������� �������������� ��������� " << j + 1 << "-�� �������: "; 
		std::cout << double(col_sum) / size << '\n';
		col_sum = 0;
	}

	// 2. ���������� ������� � ��������� �������
	std::cout << "\n\t\t2. ���������� ������� � ��������� �������\n\n";
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			A[i][j] = (i + j) % 2 ? 1 : 0;
			std::cout << A[i][j] << '\t';
		}
		std::cout << '\n';
	}

	// 3. ������ �� 2-� ��������
	/*std::cout << "\n\t\t3. ������ �� 2-� ��������\n\n";
	int B[size][2];
	for (int i = 0; i < size; i++) {
		std::cout << "������� ������� B[0][" << i << "] -> ";
		std::cin >> B[i][0];
		B[i][1] = (i + 1) * B[i][0];
	}
	std::cout << "\n����������� ������:\n\n";
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < 2; j++)
			std::cout << B[i][j] << '\t';
		std::cout << '\n';
	}*/


	// 4. ����� ������� �� �������
	std::cout << "\n\t\t4. ����� ������� �� �������\n\n";
	const int arrSize = 5;
	int arr[arrSize][arrSize];
	int k = 0, i = 0, j = 0, max;
	int i_start = 0, i_stop = 0, j_start = 0, j_stop = 0;		// ����� ��������
	max = arrSize * arrSize - 1;	// ������������ ������� �������
	
	while (k <= max) {		// �� ��� ���, ���� k <= max, ��������� ������						
		arr[i][j] = k;
		if (i == i_start && j < arrSize - j_stop - 1)	// ���� �� �� ������� ������� �������� � �� �������� ������ �������, 
			j++;										// �� ��������� ������
			else 
				if (j == arrSize - j_stop - 1 && i < arrSize - i_stop - 1)	// ���� �� �� ������ ������� �������� � �� �������� ������ �������,  
					i++;													// �� ��������� ����
				else 
					if (i == arrSize - i_stop - 1 && j > j_start)	// ���� �� �� ������ ������� �������� � �� �������� ����� �������,
						j--;										// �� ��������� �����
					else											
						i--;		// ����� ��������� �����

		if (i == i_start + 1 && j == j_start) {	// ���� �������� ����� �� ������ ���� ���������, 
			i_start++;							// �� ����������� ������� �� ����� ������� ��������
			i_stop++;
			j_start++;
			j_stop++;
		}
		k++;
	}

	// �������������� ������
	/*int c = 0;				 // ������� ���������� ("�������") ������
	do							 // �� ��� ���, ���� k <= max, ��������� ������
	{                                      
		for (int j = c; j < arrSize - c; j++)		// 1  2  3  4  5   <---- ������ ������
		{											// *  *  *  *  *
			if (k > max)							// *  *  *  *  *
				break;								// *  *  *  *  *
			arr[c][j] = k++;						// *  *  *  *  *
		}                                   
											
		for (int i = c + 1; i < arrSize - c; i++)	// 1  2  3  4  5
		{                                           // *  *  *  *  6       
			if (k > max)                            // *  *  *  *  7       
				break;                              // *  *  *  *  8      
			arr[i][arrSize - c - 1] = k++;          // *  *  *  *  9             
		}                                           //			   ^	
													//			   '-------- ������ ������	
		
		for (int j = arrSize - c - 2; j >= c; j--)  // 1  2  3  4  5
		{                                           // *  *  *  *  6       
			if (k > max)                            // *  *  *  *  7         
				break;                              // *  *  *  *  8 
			arr[arrSize - c - 1][j] = k++;          // 13 12 11 10 9  <---- ������ ������         
													 
		}                                            
													
		for (int i = arrSize - c - 2; i > c; i--)   // 1   2  3  4  5                  
		{                                           // 16  *  *  *  6                                
			if (k > max)                            // 15  *  *  *  7                                          
				break;                              // 14  *  *  *  8                               
			arr[i][c] = k++;                        // 13 12 11 10  9    
		}                                           //  ^                                            
													//  '------------------ ��������� ������                                           
		c++;                                        
	}                                                       
	while (k <= max);                               // �� ��������� ������ ��������� ���������� "�����"*/
													
	
	for (int i = 0; i < arrSize; i++) {             // ����� �������
		for (int j = 0; j < arrSize; j++)            
			std::cout << arr[i][j] << '\t';          
		std::cout << '\n';                                                    
	}
	

	// 5. ������������ ������� � �������� �������
	std::cout << "\n\t\t5. ������������ ������� � �������� �������\n\n";
	std::cout << "\t��������� ������:\n\n";
	for (int i = 0; i < arrSize; i++) {
		for (int j = 0; j < arrSize; j++) {
			arr[i][j] = rand() % (100);
			std::cout << arr[i][j] << '\t';
		}
		std::cout << '\n';
	}
	
	std::cout << "\n\t�������� ���������:\n";

	std::cout << "\na\n\n";
	for (int i = 0; i < arrSize; i++) {
		for (int j = 0; j < arrSize; j++)
			if (i <= j)
				std::cout << "* ";
			else
				std::cout << "  ";
		std::cout << '\n';
	}
	
	std::cout << "\nb\n\n";
	for (int i = 0; i < arrSize; i++) {
		for (int j = 0; j < arrSize; j++)
			if (i >= j)
				std::cout << "* ";
			else
				std::cout << "  ";
		std::cout << '\n';
	}
	
	std::cout << "\nc\n\n";
	for (int i = 0; i < arrSize; i++) {
		for (int j = 0; j < arrSize; j++)
			if (i <= j && i + j <= arrSize - 1)
				std::cout << "* ";
			else
				std::cout << "  ";
		std::cout << '\n';
	}

	std::cout << "\nd\n\n";
	for (int i = 0; i < arrSize; i++) {
		for (int j = 0; j < arrSize; j++)
			if (i >= j && i + j >= arrSize - 1)
				std::cout << "* ";
			else
				std::cout << "  ";
		std::cout << '\n';
	}

	std::cout << "\ne\n\n";
	for (int i = 0; i < arrSize; i++) {
		for (int j = 0; j < arrSize; j++)
			if ((i >= j && i + j >= arrSize - 1) || (i <= j && i + j <= arrSize - 1))
				std::cout << "* ";
			else
				std::cout << "  ";
		std::cout << '\n';
	}

	std::cout << "\nf\n\n";
	for (int i = 0; i < arrSize; i++) {
		for (int j = 0; j < arrSize; j++)
			if ((i >= j && i + j <= arrSize - 1) || (i <= j && i + j >= arrSize - 1))
				std::cout << "* ";
			else
				std::cout << "  ";
		std::cout << '\n';
	}

	std::cout << "\ng\n\n";
	for (int i = 0; i < arrSize; i++) {
		for (int j = 0; j < arrSize; j++)
			if (i >= j && i + j <= arrSize - 1)
				std::cout << "* ";
			else
				std::cout << "  ";
		std::cout << '\n';
	}

	std::cout << "\nh\n\n";
	for (int i = 0; i < arrSize; i++) {
		for (int j = 0; j < arrSize; j++)
			if (i <= j && i + j >= arrSize - 1)
				std::cout << "* ";
			else
				std::cout << "  ";
		std::cout << '\n';
	}
	
	std::cout << "\ni\n\n";
	for (int i = 0; i < arrSize; i++) {
		for (int j = 0; j < arrSize; j++)
			if (i + j <= arrSize - 1)
				std::cout << "* ";
			else
				std::cout << "  ";
		std::cout << '\n';
	}

	std::cout << "\nj\n\n";
	for (int i = 0; i < arrSize; i++) {
		for (int j = 0; j < arrSize; j++)
			if (i + j >= arrSize - 1)
				std::cout << "* ";
			else
				std::cout << "  ";
		std::cout << '\n';
	}

	char pattern;
	int counter = 0;
	std::cout << "\n�������� ������� ������ ������������� �������� -> ";
	std::cin >> pattern;
	std::cout << '\n';
	switch (pattern) {
	case 'a': case 'A':
		for (int i = 0; i < arrSize; i++) {
			for (int j = 0; j < arrSize; j++)
				if (i <= j) {
					counter++;
					if (counter == 1)
						max = arr[i][j];
					max = arr[i][j] > max ? arr[i][j] : max;
					std::cout << arr[i][j] << '\t';
				}
				else 
					std::cout << "  " << '\t';;
			std::cout << '\n';
		}
		break;
	case 'b': case 'B':
		for (int i = 0; i < arrSize; i++) {
			for (int j = 0; j < arrSize; j++)
				if (i >= j) {
					counter++;
					if (counter == 1)
						max = arr[i][j];
					max = arr[i][j] > max ? arr[i][j] : max;
					std::cout << arr[i][j] << '\t';
				}
				else
					std::cout << "  " << '\t';;
			std::cout << '\n';
		}
		break;
	case 'c': case 'C':
		for (int i = 0; i < arrSize; i++) {
			for (int j = 0; j < arrSize; j++)
				if (i <= j && i + j <= arrSize - 1) {
					counter++;
					if (counter == 1)
						max = arr[i][j];
					max = arr[i][j] > max ? arr[i][j] : max;
					std::cout << arr[i][j] << '\t';
				}
				else
					std::cout << "  " << '\t';;
			std::cout << '\n';
		}
		break;
	case 'd': case 'D':
		for (int i = 0; i < arrSize; i++) {
			for (int j = 0; j < arrSize; j++)
				if (i >= j && i + j >= arrSize - 1) {
					counter++;
					if (counter == 1)
						max = arr[i][j];
					max = arr[i][j] > max ? arr[i][j] : max;
					std::cout << arr[i][j] << '\t';
				}
				else
					std::cout << "  " << '\t';;
			std::cout << '\n';
		}
		break;
	case 'e': case 'E':
		for (int i = 0; i < arrSize; i++) {
			for (int j = 0; j < arrSize; j++)
				if ((i >= j && i + j >= arrSize - 1) || (i <= j && i + j <= arrSize - 1)) {
					counter++;
					if (counter == 1)
						max = arr[i][j];
					max = arr[i][j] > max ? arr[i][j] : max;
					std::cout << arr[i][j] << '\t';
				}
				else
					std::cout << "  " << '\t';;
			std::cout << '\n';
		}
		break;
	case 'f': case 'F':
		for (int i = 0; i < arrSize; i++) {
			for (int j = 0; j < arrSize; j++)
				if ((i >= j && i + j <= arrSize - 1) || (i <= j && i + j >= arrSize - 1)) {
					counter++;
					if (counter == 1)
						max = arr[i][j];
					max = arr[i][j] > max ? arr[i][j] : max;
					std::cout << arr[i][j] << '\t';
				}
				else
					std::cout << "  " << '\t';;
			std::cout << '\n';
		}
		break;
	case 'g': case 'G':
		for (int i = 0; i < arrSize; i++) {
			for (int j = 0; j < arrSize; j++)
				if (i >= j && i + j <= arrSize - 1) {
					counter++;
					if (counter == 1)
						max = arr[i][j];
					max = arr[i][j] > max ? arr[i][j] : max;
					std::cout << arr[i][j] << '\t';
				}
				else
					std::cout << "  " << '\t';;
			std::cout << '\n';
		}
		break;
	case 'h': case 'H':
		for (int i = 0; i < arrSize; i++) {
			for (int j = 0; j < arrSize; j++)
				if (i <= j && i + j >= arrSize - 1) {
					counter++;
					if (counter == 1)
						max = arr[i][j];
					max = arr[i][j] > max ? arr[i][j] : max;
					std::cout << arr[i][j] << '\t';
				}
				else
					std::cout << "  " << '\t';;
			std::cout << '\n';
		}
		break;
	case 'i': case 'I':
		for (int i = 0; i < arrSize; i++) {
			for (int j = 0; j < arrSize; j++)
				if (i + j <= arrSize - 1) {
					counter++;
					if (counter == 1)
						max = arr[i][j];
					max = arr[i][j] > max ? arr[i][j] : max;
					std::cout << arr[i][j] << '\t';
				}
				else
					std::cout << "  " << '\t';;
			std::cout << '\n';
		}
		break;
	case 'j': case 'J':
		for (int i = 0; i < arrSize; i++) {
			for (int j = 0; j < arrSize; j++) 
				if (i + j >= arrSize - 1) {
					counter++;
					if (counter == 1)
						max = arr[i][j];
					max = arr[i][j] > max ? arr[i][j] : max;
					std::cout << arr[i][j] << '\t';
				}
				else
					std::cout << "  " << '\t';;
			std::cout << '\n';
		}
		break;
	default:
		std::cout << "������ �����!\n";			
	}

	std::cout << "\n������������ ������� � ��������� ������� = " << max << "\n\n";

	return 0;
}