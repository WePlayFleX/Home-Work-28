#include <iostream>
#include <string.h>

using namespace std;

void sntType(char *str);
void chnText(char *str);
void cntLet(char *str);
void cntNumb(char *str);
void cntOcc(char *str, char *word);

int main()
{
	char *str = new char[1100]{ "meet my 1 family. there are five of us – my parents, my elder brother, my baby 2 sister and me! first, meet my mum and dad, Jane and Michael. my mum enjoys reading and my dad enjoys playing chess with my brother Ken? my mum is slim and rather tall. she has long red hair and big brown eyes. she has a very pleasant smile and a soft voice? my mother is very kind and understanding. we are real friends. she is a housewife. as she has three children, she is always busy around the house. she takes care of my baby sister Meg, who is only three months old. my sister is very small and funny. she sleeps, eats and sometimes cries. we all help our mother and let her have a rest in the evening. then she usually reads a book or just watches TV. my father is a doctor. he is tall and handsome. he has short dark hair and gray eyes. he is a very hardworking man. he is rather strict with us, but always fair. my elder brother Ken is thirteen, and he is very clever. he is good at Maths and always helps me with it, because I can hardly understand all these sums and problems." };
	puts(str);
	system("pause");

	cout << endl;
	cout << "Work1" << endl;
	sntType(str);
	system("pause");

	cout << endl;
	cout << "Work2" << endl;
	chnText(str);
	puts(str);
	system("pause");

	cout << endl;
	cout << "Work3" << endl;
	cntLet(str);
	system("pause");

	cout << endl;
	cout << "Work4" << endl;
	cntNumb(str);
	system("pause");

	cout << endl;
	cout << "Work5" << endl;
	char *src = new char[64];
	cout << "Enter a word to search: ";
	gets_s(src, 64);
	cntOcc(str, src);

	delete[] str;
	delete[] src;

	system("pause");
	return 0;
}
void sntType(char *str)
{
	char *cstr = str;
	int csent = 0, qsent = 0, exsent = 0;

	while (true)
	{
		cstr = strchr(cstr, '.');
		if (cstr == nullptr)
		{
			break;
		}

		csent++;
		cstr++;
	}

	cstr = str;

	while (true)
	{
		cstr = strchr(cstr, '!');
		if (cstr == nullptr)
		{
			break;
		}

		exsent++;
		cstr++;
	}

	cstr = str;

	while (true)
	{
		cstr = strchr(cstr, '?');
		if (cstr == nullptr)
		{
			break;
		}

		qsent++;
		cstr++;
	}

	cout << "Number of common sentences: " << csent << endl;
	cout << "Number of question sentences: " << qsent << endl;
	cout << "Number of exclamation sentences: " << exsent << endl;

	return;
}
void chnText(char *str)
{
	if (str[0] >= 97 && str[0] <= 122)
	{
		str[0] -= 32;
	}

	int l = strlen(str);

	for (size_t i = 0; i < l; i++)
	{
		if (str[i] == '.' || str[i] == '!' || str[i] == '?')
		{
			int k = i + 1;
			while (str[k] == ' ' || str[k] == '\n')
			{
				k++;
			}
			if (str[k] >= 97 && str[k] <= 122)
			{
				str[k] -= 32;
			}
		}
	}

	return;
}
void cntLet(char *str)
{
	char *cstr = str;
	int count = 0;
	char *let = new char[3]{ "Aa" };

	for (size_t i = 0; i < 26; i++)
	{
		while (true)
		{
			cstr = strpbrk(cstr, let);
			if (cstr == nullptr)
			{
				break;
			}
			count++;
			cstr++;
		}
		cout << "Number of " << let << " : " << count << endl;
		let[0] += 1;
		let[1] += 1;
		cstr = str;
		count = 0;
	}

	return;
}
void cntNumb(char *str)
{
	char *cstr = str;
	int count = 0;

	while (true)
	{
		cstr = strpbrk(cstr, "123456789");
		if (cstr == nullptr)
		{
			break;
		}
		cstr++;
		count++;
	}

	cout << "Number of digits: " << count << endl;

	return;
}
void cntOcc(char *str, char *word)
{
	int l = strlen(word), count = 0;
	char *cstr = str;

	while (true)
	{
		cstr = strstr(cstr, word);
		if (cstr == nullptr)
		{
			break;
		}
		cstr += l;
		count++;
	}

	cout << "Number of target word: " << count << endl;

	return;
}
