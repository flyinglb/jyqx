// wuji13.c

inherit ITEM;

string* titles = ({
	"Τ�ӹ���",
	"�������",
	"�޳��ȷ�",
	"�ն��ȷ�",
	"��ħ����",
	"��Ħ����",
});

string* skills = ({
	"weituo-gun",
	"zui-gun",
	"wuchang-zhang",
	"pudu-zhang",
	"fumo-jian",
	"damo-jian",
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
