// wuji2.c

inherit ITEM;

string* titles = ({
	"��צ����",
	"ӥצ����",
	"�黨ָ��",
	"һָ����",
	"�ȱ�����",
	"���޵���",
});

string* skills = ({
	"longzhua-gong",
	"yingzhua-gong",
	"nianhua-zhi",
	"yizhi-chan",
	"cibei-dao",
	"xiuluo-dao",
});

void create()
{
	int i = random(sizeof(titles));

	set_name(titles[i], ({ "shaolin-wuji", "wuji" }));
	set_weight(200);
	set("unit", "��");
	set("long", "����һ��" + titles[i] + "\n");
	set("value", 500);
	set("material", "paper");
	set("skill", ([
			"name":	skills[i],	// name of the skill
			"exp_required":	10000,	// minimum combat experience required
			"jing_cost": 15+random(30),// jing cost every time study this
			"difficulty":	25,	// the base int to learn this skill
			"max_skill":	99	// the maximum level you can learn
		      ]) );
}
