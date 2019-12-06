// aliasd.c
// modify byp@jyqxz

// ���·��� global_alias ĳЩ JOB ��Ҫ������ȫ·��
mapping global_alias = ([
	"n"     : "go north",
	"e"     : "go east",
	"w"     : "go west",
	"s"     : "go south",
	"nu"    : "go northup",
	"eu"    : "go eastup",
	"wu"    : "go westup",
	"su"    : "go southup",
	"nd"    : "go northdown",
	"ed"    : "go eastdown",
	"wd"    : "go westdown",
	"sd"    : "go southdown",
	"ne"    : "go northeast",
	"se"    : "go southeast",
	"nw"    : "go northwest",
	"sw"    : "go southwest",
	"u"     : "go up",
	"d"     : "go down",
]);
// Ϊ�����������һЩ������ͬ�������ڴ˶���
mapping cmds_alias = ([
	"l"     : "look",
	"i"     : "inventory",
        "sc"    : "score",
        "xia"   : "unride",
        "qi"    : "ride",
        "dating": "check",
        "qiecuo": "fight",
        "cha"   : "skills",
        "bai"   : "apprentice",
        "bei"   : "prepare",
	"tt"    : "team talk",
        "jiali" : "enforce",
        "kaichu": "expell",
        "jiao"  : "teach",
        "shou"  : "recruit",
        "exercise"      : "dazuo",//��Щ�й����е��书�������ƴ����
"exit":"quit",
        "respirate"     : "tuna",
]);

string process_global_alias(string arg)
{
	string *word;

	if (arg[0]=='\'') return "say " + arg[1..strlen(arg)-1];

	word = explode(arg, " ");
	if( sizeof(word) && !undefinedp(global_alias[word[0]]) ) {
		word[0] = global_alias[word[0]];
		return implode(word, " ");
	}
	
	if( sizeof(word) && !undefinedp(cmds_alias[word[0]]) ) {
		word[0] = cmds_alias[word[0]];
		return implode(word, " ");
	}

	return arg;
}

