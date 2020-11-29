/**
 * @file tpvalg.c
 * @author Krysin Dmitriy <krdimitrius@gmail.comrysin@tecon.ru>
 * @date 2020
 * @brief ELIZE
 */

//------------------------------------------------------------------------------
// includes
//------------------------------------------------------------------------------
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>

#define STRING_SIZE 255

char copyright[] = "\n  ELIZA/DOCTOR"
"\n  CREATED BY JOSEPH WEIZENBAUM"
"\n  THIS VERSION BY JEFF SHRAGER"
"\n  EDITED AND MODIFIED FOR C MITS 8K BASIC 4.0 BY STEVE NORTH"
"\n  CREATIVE COMPUTING PO BOX 789-M MORRISTOWN NJ 07960"
"\n";

char elize_hi[] = "HI! I'M ELIZA. WHAT'S YOUR PROBLEM?";
char elize_dontrepeat[] = "PLEASE DON'T REPEAT YOURSELF!";
char elize_shut[] = "SHUT";
char elize_shutup[] = "SHUT UP...";

// ключевые слова
#define KEYWORDS_SIZE 16
#define KEYWORDS_NUM (sizeof(keywords)/KEYWORDS_SIZE)
char keywords[][16] = {
"CAN YOU", "CAN I", "YOU ARE", "YOURE", "I DONT",
"I FEEL", "WHY DONT YOU", "WHY CANT I", "ARE YOU", "I CANT",
"I AM", " IM ", "YOU", "I WANT", "WHAT",
"HOW", "WHO", "WHERE", "WHEN", "WHY",
"NAME", "CAUSE", "SORRY", "DREAM", "HELLO",
"HI", "MAYBE", "NO", "YOUR", "ALWAYS",
"THINK", "ALIKE", "YES", "FRIEND", "COMPUTER",
"NOKEYFOUND",
};

// строки для замены
#define CONJUGATION_SIZE 10
#define CONJUGATION_NUM (sizeof(conjugation)/CONJUGATION_SIZE)
char conjugation[][10] = {
	" ARE "," AM ",
	"WERE ","WAS ",
	" YOU "," I ",
	"YOUR ","MY ",
	" IVE "," YOUVE ",
	" IM "," YOURE ",
};

// реплики
#define REPLIES_SIZE 100
#define REPLIES_NUM (sizeof(replies)/REPLIES_SIZE)
char replies[][REPLIES_SIZE] = {
	"DON'T YOU BELIEVE THAT I CAN.",
	"PERHAPS YOU WOULD LIKE TO BE ABLE TO.",
	"YOU WANT ME TO BE ABLE TO*",
	"PERHAPS YOU DON'T WANT TO*",
	"DO YOU WANT TO BE ABLE TO*",
	"WHAT MAKES YOU THINK I AM*",
	"DOES IT PLEASE YOU TO BELIEVE I AM*",
	"PERHAPS YOU WOULD LIKE TO BE*",
	"DO YOU SOMETIMES WISH YOU WERE*",
	"DON'T YOU REALLY*",
	"WHY DON'T YOU*",
	"DO YOU WISH TO BE ABLE TO*",
	"DOES THAT TROUBLE YOU?",
	"TELL ME MORE ABOUT SUCH FEELINGS*",
	"DO YOU OFTEN FEEL*",
	"DO YOU ENJOY FEELING*",
	"DO YOU REALLY BELIEVE I DON'T*",
	"PERHAPS IN G00D TIME I WILL*",
	"DO YOU WANT ME TO*",
	"DO YOU THINK YOU SHOULD BE ABLE TO*",
	"WHY CAN'T YOU*",
	"WHY ARE YOU INTERESTED IN WHETHER OR NOT I AM*",
	"WOULD YOU PREFER IF I WERE NOT*",
	"PERHAPS IN YOUR FANTASIES I AM*",
	"HOW DO YOU KNOW YOU CAN'T*",
	"HAVE YOU TRIED?",
	"PERHAPS YOU CAN NOW*",
	"DID YOU COME TO ME BECAUSE YOU ARE*",
	"HOW LONG HAVE YOU BEEN*",
	"DO YOU BELIEVE IT IS NORMAL TO BE*",
	"DO YOU ENJOY BEING*",
	"WE WERE DISCUSSING YOU, NOT ME.",
	"OH, I*",
	"YOU'RE NOT REALLY TALKING ABOUT ME. ARE YOU?",
	"WHAT WOULD IT MEAN TO YOU IF YOU GOT*",
	"WHY DO YOU WANT*",
	"SUPPOSE YOU SOON GOT*",
	"WHAT IF YOU NEVER GOT*",
	"I SOMETIMES ALSO WANT*",
	"WHY DO YOU ASK?",
	"DOES THAT QUESTION INTEREST YOU?",
	"WHAT ANSWER WOULD PLEASE YOU THE MOST?",
	"WHAT DO YOU THINK?",
	"ARE SUCH QUESTIONS ON YOUR MIND OFTEN?",
	"WHAT IS IT THAT YOU REALLY WANT TO KNOW?",
	"HAVE YOU ASKED ANYONE ELSE?",
	"HAVE YOU ASKED SUCH QUESTIONS BEFORE?",
	"WHAT ELSE COMES TO MIND WHEN YOU ASK THAT?",
	"NAMES DON'T INTEREST ME.",
	"I DON'T CARE ABOUT NAMES, PLEASE GO ON.",
	"IS THAT THE REAL REASON?",
	"DON'T ANY OTHER REASONS COME TO MIND?",
	"DOES THAT REASON EXPLAIN ANYTHING ELSE?",
	"WHAT OTHER REASONS MIGHT THERE BE?",
	"PLEASE DON'T APOLOGIZE.",
	"APOLOGIES ARE NOT NECESSARY.",
	"WHAT FEELINGS DO YOU HAVE WHEN YOU APOLOGIZE.",
	"DON'T BE SO DEFENSIVE!",
	"WHAT DOES THAT DREAM SUGGEST TO YOU?",
	"DO YOU DREAM OFTEN?",
	"WHAT PERSONS APPEAR IN YOUR DREAMS?",
	"ARE YOU DISTURBED BY YOUR DREAMS?",
	"HOW DO YOU DO? PLEASE STATE YOUR PROBLEM.",
	"YOU DON'T SEEM QUITE CERTAIN.",
	"WHY THE UNCERTAIN TONE?",
	"CAN'T YOU BE MORE POSITIVE?",
	"YOU AREN'T SURE?",
	"DON'T YOU KNOW?",
	"ARE YOU SAYING NO JUST TO BE NEGATIVE?",
	"YOU ARE BEING A BIT NEGATIVE.",
	"WHY NOT?",
	"ARE YOU SURE?",
	"WHY NO?",
	"WHY ARE YOU CONCERNED ABOUT MY*",
	"WHAT ABOUT YOUR OWN*",
	"CAN'T YOU THINK OF A SPECIFIC EXAMPLE?",
	"WHEN?",
	"WHAT ARE YOU THINKING OF?",
	"REALLY. ALWAYS?",
	"DO YOU REALLY THINK SO?",
	"BUT YOU ARE NOT SURE YOU.",
	"DO YOU DOUBT YOU.",
	"IN WHAT WAY?",
	"WHAT RESEMBLANCE DO YOU SEE?",
	"WHAT DOES THE SIMILARITY SUGGEST TO YOU?",
	"WHAT OTHER CONNECTIONS DO YOU SEE?",
	"COULD THERE REALLY BE SOME CONNECTION?"
	"HOW?",
	"YOU SEEM QUITE POSITIVE.",
	"ARE YOU SURE?",
	"I SEE.",
	"I UNDERSTAND.",
	"WHY DO YOU BRING UP THE TOPIC OF FRIENDS?",
	"DO YOUR FRIENDS WORRY YOU?",
	"DO YOUR FRIENDS PICK ON YOU?",
	"ARE YOU SURE YOU HAVE ANY FRIENDS?",
	"DO YOU IMPOSE ON YOUR FRIENDS?",
	"PERHAPS YOUR LOVE FOR FRIENDS WORRIES YOU.",
	"DO COMPUTERS WORRY YOU?",
	"ARE YOU TALKING ABOUT ME IN PARTICULAR?",
	"ARE YOU FRIGHTENED BY MACHINES?",
	"WHY DO YOU MENTION COMPUTERS?",
	"WHAT DO YOU THINK MACHINES HAVE TO DO WITH YOUR PROBLEM?",
	"DON'T YOU THINK COMPUTERS CAN HELP PEOPLE?",
	"WHAT IS IT ABOUT MACHINES THAT WORRIES YOU?",
	"SAY, DO YOU HAVE ANY PSYCHOLOGICAL PROBLEMS?",
	"WHAT DOES THAT SUGGEST TO YOU?",
	"I SEE.",
	"I'M NOT SURE I UNDERSTAND YOU FULLY.",
	"COME COME ELUCIDATE YOUR THOUGHTS.",
	"CAN YOU ELABORATE ON THAT?",
	"THAT IS QUITE INTERESTING.",
};

// данные для поиска реплик
#define REPLIES_IDX_NUM (sizeof(replies_idx)/sizeof(int))
int replies_idx[] = {
	 0,3, 3,1, 5,3, 5,3, 9,3, // 0...4
	13,2,16,2,19,1,21,2,24,2, // 5...9
	27,3,27,3,31,2,34,4,39,8, // 10...14
	39,8,39,8,39,8,39,8,39,8, // 15...19
	48,1,50,3,54,3,58,3,62,0, // 20...24
	62,0,63,4,68,4,73,1,75,3, // 25...29
	79,2,82,6,89,2,92,5,98,6, // 30...34
	105,5, // 35
};

int main()
{
	int keyword_idx = 0; // индекс ключевого слова
	char * keyword_ptr; // указатель на ключевое во входной строке
	int s[KEYWORDS_NUM];
	int r[KEYWORDS_NUM];
	int n[KEYWORDS_NUM];
	char str_in[STRING_SIZE] = " "; // входная строка
	char str_p[STRING_SIZE] = " "; // прошлая входная строка
	char str_c[STRING_SIZE] = " ";
	char str_tmp[STRING_SIZE];

	printf("%s\n", copyright);

	for (int i = 0; i < KEYWORDS_NUM; i++) {
		s[i] = replies_idx[i * 2];
		int j = replies_idx[i * 2 + 1];	
		r[i] = s[i];
		n[i] = s[i] + j;
	}

	printf("%s\n", elize_hi);

	while(1) {
		// ввод строки
		{
			printf(">");

			str_tmp[0] = 0;
			gets(str_tmp);

			// устранение апострофа
			while(1) {
				char * p = strchr(str_tmp, '\'');
				if (p == NULL)
					break;
				*p = 0;
				p++;
				strncat(str_tmp, p, STRING_SIZE);
			}

			strncpy(str_in, " ", STRING_SIZE);
			strncat(str_in, str_tmp, STRING_SIZE);
			strncat(str_in, " ", STRING_SIZE);
		}
	
		if (strstr(str_in, elize_shut) != NULL) {
			printf("%s\n", elize_shutup);
			return 0;
		}

		if (strcmp(str_in, str_p) == 0) {
			printf("%s\n", elize_dontrepeat);
			continue;
		}
		
		// поиск ключевого слова во входной строке
		keyword_ptr = NULL;
		keyword_idx = KEYWORDS_NUM - 1;
		for (int i = 1; i < KEYWORDS_NUM; i++) {
			keyword_ptr = strstr(str_in, keywords[i]);
			if (keyword_ptr != NULL) {
				keyword_idx = i;
				break;
			}
		}

		/*
		 * Спрягаем правую часть строки
		 * используя список строк, подлежащих замене
		 */
		if (keyword_ptr != NULL) {
			// правая часть строки после ключевого слова
			strncpy(str_c , keyword_ptr + strlen(keywords[keyword_idx]), STRING_SIZE);

			for (int i = 0; i < CONJUGATION_SIZE/2; i++) {
				char * s_ptr = conjugation[i * 2]; // что искать 
				char * r_ptr = conjugation[i * 2 + 1]; // на что менять
				char * f_ptr = strstr(str_c, s_ptr); // указатель на найденное слово

				if (f_ptr == NULL)
					continue;

				// копирую правую часть				
				*f_ptr = 0;
				strncpy(str_tmp, str_c, STRING_SIZE);
				// подставляю замену
				strncat(str_tmp, r_ptr, STRING_SIZE);
				// подставляю левую часть
				strncpy(str_tmp, f_ptr + strlen(s_ptr), STRING_SIZE);
				// сохраняю
				strncat(str_c, str_tmp, STRING_SIZE);
			}

			// удаляю пробелы в начале строки
			for(int i = 1; i < strlen(str_c); i++) {
				if (str_c[i] != ' ') {
					strncpy(str_tmp, str_c + i, STRING_SIZE);
					// сохраняю
					strncpy(str_c, str_tmp, STRING_SIZE);
					break;
				}
			}
		}
		else 
			str_c[0] = 0;

		// используя номер ключевого слова, получаем ответ
		{
			char * replies_ptr = replies[r[keyword_idx]];

			r[keyword_idx]++;
			if (r[keyword_idx] > n[keyword_idx])
				r[keyword_idx] = s[keyword_idx];

			if (replies_ptr[strlen(replies_ptr) - 1] == '*') {
				strncpy(str_tmp, replies_ptr, STRING_SIZE);
				str_tmp[strlen(replies_ptr) - 1] = 0;
				printf("%s %s\n", str_tmp, str_c);
			}
			else
				printf("%s\n", replies_ptr);
			strncpy(str_p, str_in, STRING_SIZE);
		}
	}
	return 0;
}
