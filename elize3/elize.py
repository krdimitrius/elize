#!/usr/bin/env python3

"""
Elize classic
"""

copyright = "ELIZA/DOCTOR CREATED BY JOSEPH WEIZENBAUM"

elize_hi = "HI! I'M ELIZA. WHAT'S YOUR PROBLEM?"
elize_dontrepeat = "PLEASE DON'T REPEAT YOURSELF!"
elize_shut = "SHUT"
elize_shutup = "SHUT UP..."

keywords = [
"CAN YOU", "CAN I", "YOU ARE", "YOURE", "I DONT",
"I FEEL", "WHY DONT YOU", "WHY CANT I", "ARE YOU", "I CANT",
"I AM", "IM", "YOU", "I WANT", "WHAT",
"HOW", "WHO", "WHERE", "WHEN", "WHY",
"NAME", "CAUSE", "SORRY", "DREAM", "HELLO",
"HI", "MAYBE", "NO", "YOUR", "ALWAYS",
"THINK", "ALIKE", "YES", "FRIEND", "COMPUTER",
"NOKEYFOUND"
]

conjugation = {
    " ARE ": " AM ",
    " WERE ": " WAS ",
    " YOU ": " I ",
    " YOUR ": " MY ",
    " IVE ": " YOUVE ",
    " IM ": " YOURE "
}

replies = [
    "DON'T YOU BELIEVE THAT I CAN.",
    "PERHAPS YOU WOULD LIKE TO BE ABLE TO.",
    "YOU WANT ME TO BE ABLE TO#",
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
    "TELL ME MORE ABOUT SUCH FEELINGS#",
    "DO YOU OFTEN FEEL*",
    "DO YOU ENJOY FEELING*",
    "DO YOU REALLY BELIEVE I DON'T*",
    "PERHAPS IN G00D TIME I WILL#",
    "DO YOU WANT ME TO*",
    "DO YOU THINK YOU SHOULD BE ABLE TO*",
    "WHY CAN'T YOU*",
    "WHY ARE YOU INTERESTED IN WHETHER OR NOT I AM*",
    "WOULD YOU PREFER IF I WERE NOT*",
    "PERHAPS IN YOUR FANTASIES I AM#",
    "HOW DO YOU KNOW YOU CAN'T*",
    "HAVE YOU TRIED?",
    "PERHAPS YOU CAN NOW#",
    "DID YOU COME TO ME BECAUSE YOU ARE*",
    "HOW LONG HAVE YOU BEEN*",
    "DO YOU BELIEVE IT IS NORMAL TO BE*",
    "DO YOU ENJOY BEING*",
    "WE WERE DISCUSSING YOU, NOT ME.",
    "OH, I#",
    "YOU'RE NOT REALLY TALKING ABOUT ME. ARE YOU?",
    "WHAT WOULD IT MEAN TO YOU IF YOU GOT*",
    "WHY DO YOU WANT*",
    "SUPPOSE YOU SOON GOT#",
    "WHAT IF YOU NEVER GOT*",
    "I SOMETIMES ALSO WANT#",
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
    "THAT IS QUITE INTERESTING."
]

replies_idx = [
     0,3, 3,1, 5,3, 5,3, 9,3, # 0...4
    13,2,16,2,19,1,21,2,24,2, # 5...9
    27,3,27,3,31,2,34,4,39,8, # 10...14
    39,8,39,8,39,8,39,8,39,8, # 15...19
    48,1,50,3,54,3,58,3,62,0, # 20...24
    62,0,63,4,68,4,73,1,75,3, # 25...29
    79,2,82,6,89,2,92,5,98,6, # 30...34
    105,5, # 35
]

def main():

    print("\n" + copyright + "\n")
    print("\n" + elize_hi)

    str_in = " "    # input string
    str_last = " "  # last input string
    str_con = " "   # conjugated string

    s = [i for i in range(len(keywords))]
    r = [i for i in range(len(keywords))]
    n = [i for i in range(len(keywords))]

    for i in range(len(keywords)):
        s[i] = replies_idx[i * 2]
        j = replies_idx[i * 2 + 1]
        r[i] = s[i]
        n[i] = s[i] + j

    while 1:
        # input string
        str_tmp = input(">")
        str_tmp = str_tmp.upper()
        str_in = str_tmp.strip("\'")

        if elize_shut in str_in:
            print(elize_shutup)
            break

        if str_last == str_in:
            print(elize_dontrepeat);
            continue

        str_last = str_in

        # look for keyword
        for keyword_idx in range(len(keywords)):
            keyword_pos = str_in.find(keywords[keyword_idx])
            if keyword_pos >= 0:
                break
    
        # conjugate right part of the string
        if keyword_pos >= 0:
            str_tmp = str_in.partition(keywords[keyword_idx])
            str_con = str_tmp[2]
            for old_word, new_word in conjugation.items():
                str_con = str_con.replace(old_word, new_word)
        else:
            str_con = " "

        replies_str = replies[r[keyword_idx]];

        r[keyword_idx] = r[keyword_idx] + 1;
        if (r[keyword_idx] > n[keyword_idx]):
            r[keyword_idx] = s[keyword_idx]

        if replies_str[-1] == "*":
            replies_str = replies_str[:-1] + str_con + "?"
        elif replies_str[-1] == "#":
            replies_str = replies_str[:-1] + str_con + "."

        print(replies_str)

if __name__ == '__main__':
    main()
